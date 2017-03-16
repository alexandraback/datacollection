package world2015.qualification_round;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.TreeMap;

public class OminousOmino {

	public static void main(String args[]) throws IOException {
		OminousOmino oo = new OminousOmino();
		String inputPath = "file/world2015/qualification_round/D-small-attempt0.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			String[] tokens = line.split(" ");
			int X = Integer.parseInt(tokens[0]);
			int R = Integer.parseInt(tokens[1]);
			int C = Integer.parseInt(tokens[2]);
			String res = oo.solve(X, R, C);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
	
	private static final int[][] NEIGHBORS = {
		{-1, 0}, {0, -1}, {1, 0}, {0, 1}
	};
	
	private int[][][] possible = new int[7][21][21];
	private int[] numBasicOminos = new int[7];
	
	public OminousOmino() {
		init();
	}
	
	private void init() {
		for (int x=3; x<=6; x++) {
			TreeMap<Long, Omino> basicOminos = createBasicOminos(x);
			TreeMap<Long, Omino> ominos = createAllOminos(basicOminos);
			numBasicOminos[x] = basicOminos.size();
			for (int r=1; r<=20; r++)
				for (int c=r; c<=20; c++) {
					if ((r*c)%x!=0)
						continue;
					possible[x][r][c] = arrange(x, basicOminos.size(), ominos, r, c);
				}
		}
	}
	
	private TreeMap<Long, Omino> createBasicOminos(int x) {
		TreeMap<Long, Omino> ominos = new TreeMap<>();
		int[][] locs = new int[x][2];
		locs[0][0] = 0; locs[0][1] = 0;
		createBasicOminos(ominos, locs, x, 1);
		return ominos;
	}
	
	private void createBasicOminos(TreeMap<Long, Omino> ominos, int[][] locs, int x, int idx) {
		if (idx==x) {
			int[][] clocs = new int[locs.length][2];
			for (int i=0; i<locs.length; i++) {
				clocs[i][0] = locs[i][0];
				clocs[i][1] = locs[i][1];
			}
			Omino.arrange(clocs);
			Omino.normalize(clocs);
			boolean exists = false;
			LOOP : for (int reverse=0; reverse<2; reverse++)
				for (int rotate=0; rotate<4; rotate++) {
					int[][] nlocs = clocs;
					if (reverse==1)
						nlocs = Omino.reverse(nlocs);
					nlocs = Omino.rotate(nlocs, rotate);
					long key = Omino.getKey(nlocs);
					if (ominos.containsKey(key)) {
						exists = true;
						break LOOP;
					}
				}
			if (!exists)
				ominos.put(Omino.getKey(clocs), new Omino(clocs, ominos.size()));
		} else {
			for (int i=0; i<idx; i++) {
				for (int j=0; j<NEIGHBORS.length; j++) {
					int r = locs[i][0] + NEIGHBORS[j][0];
					int c = locs[i][1] + NEIGHBORS[j][1];
					boolean duplicate = false;
					for (int k=0; k<idx; k++)
						if (r==locs[k][0] && c==locs[k][1]) {
							duplicate = true;
							break;
						}
					if (!duplicate) {
						locs[idx][0] = r; locs[idx][1] = c;
						createBasicOminos(ominos, locs, x, idx+1);
					}
				}
			}
		}
	}
	
	private TreeMap<Long, Omino> createAllOminos(TreeMap<Long, Omino> basicOminos) {
		TreeMap<Long, Omino> ominos = new TreeMap<>();
		for (long key : basicOminos.keySet()) {
			Omino omino = basicOminos.get(key);
			ominos.put(key, omino);
			for (int reverse=0; reverse<2; reverse++)
				for (int rotate=0; rotate<4; rotate++) {
					int[][] nlocs = omino.locs;
					if (reverse==1)
						nlocs = Omino.reverse(nlocs);
					nlocs = Omino.rotate(nlocs, rotate);
					long nkey = Omino.getKey(nlocs);
					if (!ominos.containsKey(nkey))
						ominos.put(nkey, new Omino(nlocs, omino.no));
				}
		}
		return ominos;
	}
	
	private int arrange(int x, int numBasics, TreeMap<Long, Omino> ominos, int r, int c) {
		int numUsed = 0;
		for (int i=0; i<numBasics; i++)
			if (arrange(x, ominos, i, r, c))
				numUsed++;
		return numUsed;
	}
	
	private boolean arrange(int x, TreeMap<Long, Omino> ominos, int no, int r, int c) {
		for (Omino omino : ominos.values())
			if (omino.no==no) {
				for (int rr=0; rr<r; rr++)
					for (int cc=0; cc<c; cc++) {
						boolean[][] filled = new boolean[r][c];
						if (canPut(filled, rr, cc, omino.locs)) {
							fill(filled, rr, cc, omino.locs, true);
							if (arrange(x, filled))
								return true;
						}
					}
			}
		return false;
	}
	
	private boolean arrange(int x, boolean[][] filled) {
		for (int r=0; r<filled.length; r++)
			for (int c=0; c<filled[r].length; c++)
				if (count(filled, r, c)%x!=0)
					return false;
		return true;
	}
	
	private int count(boolean[][] filled, int r, int c) {
		if (filled[r][c])
			return 0;
		filled[r][c] = true;
		int cnt = 1;
		for (int i=0; i<NEIGHBORS.length; i++) {
			int rr = r + NEIGHBORS[i][0];
			int cc = c + NEIGHBORS[i][1];
			if (canPut(filled, rr, cc))
				cnt += count(filled, rr, cc);
		}
		return cnt;
	}
	
	private boolean canPut(boolean[][] filled, int r, int c, int[][] locs) {
		int dr = r - locs[0][0], dc = c - locs[0][1];
		for (int i=0; i<locs.length; i++)
			if (!canPut(filled, locs[i][0]+dr, locs[i][1]+dc))
				return false;
		return true;
	}
	
	private boolean canPut(boolean[][] filled, int r, int c) {
		if (r<0 || filled.length<=r || c<0 || filled[r].length<=c)
			return false;
		return !filled[r][c];
	}
	
	private void fill(boolean[][] filled, int r, int c, int[][] locs, boolean flag) {
		int dr = r - locs[0][0], dc = c - locs[0][1];
		for (int i=0; i<locs.length; i++)
			filled[locs[i][0]+dr][locs[i][1]+dc] = flag;
	}
	
	private boolean possible(int X, int R, int C) {
		if (R>C) {
			int tmp = R; R = C; C = tmp;
		}
		return possible[X][R][C]==numBasicOminos[X];
	}
	
	public String solve(int X, int R, int C) {
		if (X>=7 || (R*C)%X!=0 || (X+1)/2>Math.min(R, C))
			return "RICHARD";
		if (X==1 || X==2)
			return "GABRIEL";
		if (possible(X, R, C))
			return "GABRIEL";
		else
			return "RICHARD";
	}
}

class Omino {

	static long getKey(int[][] locs) {
		int n = locs.length;
		long key = 0;
		for (int i=0; i<n; i++) {
			key *= n; key += locs[i][0];
			key *= n; key += locs[i][1];
		}
		return key;
	}
	
	static void normalize(int[][] locs) {
		int minr = locs[0][0], minc = locs[0][1];
		for (int i=0; i<locs.length; i++) {
			minr = Math.min(minr, locs[i][0]);
			minc = Math.min(minc, locs[i][1]);
		}
		for (int i=0; i<locs.length; i++) {
			locs[i][0] -= minr;
			locs[i][1] -= minc;
		}
	}
	
	static void arrange(int[][] locs) {
		for (int i=0; i<locs.length; i++)
			for (int j=i+1; j<locs.length; j++)
				if (locs[j][0]<locs[i][0] || locs[j][0]==locs[i][0] && locs[j][1]<locs[i][1]) {
					int[] tmp = locs[i];
					locs[i] = locs[j];
					locs[j] = tmp;
				}
	}
	
	static int[][] reverse(int[][] locs) {
		int[][] nlocs = new int[locs.length][2];
		for (int i=0; i<locs.length; i++) {
			nlocs[i][0] = locs[i][0];
			nlocs[i][1] = -locs[i][1];
		}
		arrange(nlocs);
		normalize(nlocs);
		return nlocs;
	}
	
	static int[][] rotate(int[][] locs, int numRotates) {
		int[][] nlocs = new int[locs.length][2];
		for (int i=0; i<locs.length; i++) {
			nlocs[i][0] = locs[i][0];
			nlocs[i][1] = locs[i][1];
		}
		for (int i=0; i<numRotates; i++) {
			for (int j=0; j<nlocs.length; j++) {
				int tmp = nlocs[j][0];
				nlocs[j][0] = nlocs[j][1];
				nlocs[j][1] = -tmp;
			}
		}
		arrange(nlocs);
		normalize(nlocs);
		return nlocs;
	}
	
	int[][] locs;
	int no;
	
	Omino(int[][] locs, int no) {
		this.locs = locs;
		this.no = no;
	}
	
	long rotate(int numRotates) {
		int[][] locs = new int[this.locs.length][2];
		for (int i=0; i<this.locs.length; i++) {
			locs[i][0] = this.locs[i][0];
			locs[i][1] = this.locs[i][1];
		}
		for (int i=0; i<numRotates; i++) {
			for (int j=0; j<locs.length; j++) {
				int tmp = locs[j][0];
				locs[j][0] = locs[j][1];
				locs[j][1] = -tmp;
			}
			arrange(locs);
		}
		normalize(locs);
		return getKey(locs);
	}
}
