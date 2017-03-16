import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;


public class Lawnmower {
	public Lawnmower(int N, int M) {
		this.N = N;
		this.M = M;
//		System.out.println(N);
//		System.out.println(M);
		target = new int[N][M];
		mowed = new boolean[N][M];
	}
	
	public int N;
	public int M;
	public int[][] target;
	public boolean[][] mowed;
	public TreeSet<Integer> edges = new TreeSet<Integer>();
	public TreeSet<Integer> values = new TreeSet<Integer>();
	
	public void set(int i, int j, int v) {
		target[i][j] = v;
		if (i == 0 || i == N-1 || j == 0 || j == M-1) {
			edges.add(v);
		}
		values.add(v);
	}
	
	public boolean isPossible() {
		for (int e : values) {
			System.out.println(e);
			for (int i = 0; i < N; i++) {
				if (e >= target[i][0]) {
					List<Integer> toMarkJ = new ArrayList<Integer>();
					for (int j = 0; j < M; j++) {
						if (target[i][j] == e) {
							toMarkJ.add(j);
						} if (target[i][j] > e) {
							toMarkJ.clear();
							break;
						}
					}
					for (int j : toMarkJ) {
						mowed[i][j]  = true;
					}
				}
			}
			for (int i = 0; i < N; i++) {
				if (e >= target[i][M-1]) {
					List<Integer> toMarkJ = new ArrayList<Integer>();
					for (int j = M-1; j >= 0; j--) {
						if (target[i][j] == e) {
							toMarkJ.add(j);
						} if (target[i][j] > e) {
							toMarkJ.clear();
							break;
						}
					}
					for (int j : toMarkJ) {
						mowed[i][j]  = true;
					}
				}
			}
			for (int j = 0; j < M; j++) {
				if (e >= target[0][j]) {
					List<Integer> toMarkI = new ArrayList<Integer>();
					for (int i = 0; i < N; i++) {
						if (target[i][j] == e) {
							toMarkI.add(i);
						} if (target[i][j] > e) {
							toMarkI.clear();
							break;
						}
					}
					for (int i : toMarkI) {
						mowed[i][j]  = true;
					}
				}
			}
			for (int j = 0; j < M; j++) {
				if (e >= target[N-1][j]) {
					List<Integer> toMarkI = new ArrayList<Integer>();
					for (int i = N-1; i >= 0; i--) {
						if (target[i][j] == e) {
							toMarkI.add(i);
						} if (target[i][j] > e) {
							toMarkI.clear();
							break;
						}
					}
					for (int i : toMarkI) {
						mowed[i][j]  = true;
					}
				}
			}
			System.out.println(this);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (target[i][j] == e && !mowed[i][j]) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	public String toString() {
		String rs = "";
		for (int i = 0; i < N; i++) {
			rs += Arrays.toString(mowed[i]) + "\n";
		}
		return rs;
	}
	
	public static void main(String args[]) throws IOException{
		Scanner scin = new Scanner(new File("in2.txt"));
		FileWriter fw = new FileWriter(new File("out2.txt"));

		int T = scin.nextInt();
		
		for (int cs = 1; cs < T + 1; cs++) {
			int N = scin.nextInt();
			int M = scin.nextInt();
			System.out.println("cs" + cs);

			Lawnmower lm = new Lawnmower(N, M);
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					lm.set(i, j, scin.nextInt());
				}
			}
			
			boolean possible = lm.isPossible();
			System.out.println(lm);
			
			System.out.println(possible);
			
			fw.write("Case #"+cs+": " + (possible ? "YES" : "NO") + "\n");
		}
		
		fw.close();
	}
}
