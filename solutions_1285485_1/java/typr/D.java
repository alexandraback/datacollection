package qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;


public class D {
	
	static class Ray{
		// directions
		public static byte U = 0; // up
		public static byte L = 1; // left
		public static byte C = 2; // left-up (corner)
		// for printing
		private static char[] SYMB = new char[]{'u', 'l', 'c'};
		
		// replace l -> u, u -> l, to build symmetric ray
		private static byte[] REPL = new byte[]{L, U, C};
		
		private final int mDdeep;
		private final int mDlength;
		private byte[] mDirs;
		private int dL = +1;
		private int dU = +1;
		private int mC = 0;
		
		public Ray(int ddeep, int dlength, byte[] dirs){
			mDdeep = ddeep;
			mDlength = dlength;
			mDirs = dirs;
		}
		
		public Ray(Ray ray){
			mDdeep = ray.mDdeep;
			mDlength = ray.mDlength;
			mDirs = ray.mDirs;
			dL = ray.dL;
			dU = ray.dU;
			mC = ray.mC;
		}
		public void revertU(){
			dU *= -1;
		}
		
		public void revertL(){
			dL *= -1;
		}
		
		public Ray(int ddeep, int dlength, int l, int u){
			mDdeep = ddeep;
			mDlength = dlength;
			
			List<Byte> res = new ArrayList<Byte>();
			int la = l * 2;
			//int ua = u * 2;
			int cu = 0;
			for (int t = 1; t < la; t += 2){
				if (t * u % l == 0 && t * u / l % 2 == 1) {
					// corner move
					res.add(Ray.C);
					cu++;
				} else {
					if (t*u / l > 2*cu){
						res.add(Ray.U);
						cu++;
					}
					res.add(Ray.L);
				}
			}
			mDirs = new byte[res.size()];
			for (int i = 0; i < res.size(); i++){
				mDirs[i] = res.get(i);
			}
		}
		
		//produce symmetric ray
		public Ray symm(){
			byte[] dirs = new byte[mDirs.length];
			for(int i = 0; i < mDirs.length; i++){
				dirs[i] = REPL[mDirs[i]];
			}
			return new Ray(mDdeep, mDlength, dirs);
		}
		
		public String toString(){
			StringBuilder res =  new StringBuilder();
			for (int i = 0; i < mDirs.length; i++){
				res.append(SYMB[mDirs[i]]);
			}
			return res.toString();
		}
		
		public boolean trace(int x, int y, char[][] field){
			int n = 0;
			while (true){
				// still parsing
				if (mC < mDirs.length){
					byte dir = mDirs[mC];
					int nx = dir == U ? x : x + dL;
					int ny = dir == L ? y : y + dU;
					if (field[ny][nx] == '#'){
						//mirror processing
						if (dir == L){
							revertL();
						} else if (dir == U){
							revertU();
						} else {
							// corner processing
							char lc = field[y][nx];
							char uc = field[ny][x];
							if (lc == '#' && uc == '#'){
								revertU();
								revertL();
							} else if (lc == '#'){
								y = ny;
								revertL();
							} else if (uc == '#'){
								x = nx;
								revertU();
							} else {
								// destroy ray
								return false;
							}
						}
					} else {
						x = nx; 
						y = ny;
					}
					mC++;
				} else {
					// we are reach ray's end
					// check if we hit X
					n++;
					if (field[y][x] == 'X' && n*n*mDlength <= mDdeep) return true;
						
					if (n*n*mDlength < mDdeep){
						// can continue ray
						mC = 0;
					} else {
						// can not reach X
						return false;
					}
				}
			}
		}
	}
	public static String printField(char[][] data){
		StringBuilder s = new StringBuilder();
		for (int i = 0; i < data.length; i++){
			for (int j = 0; j < data[i].length; j++){
				s.append(data[i][j]);
			}
			s.append("\n");
		}
		return s.toString();
	}
	public static List<Ray> createAll(int deep){
		List<Ray> rays = new ArrayList<Ray>();
		int ddeep = deep * deep;
		boolean [][] points = new boolean[deep + 1][deep];
		for (int l = 1; l <= deep; l++){
			for (int u = 0; u < l; u++){
				// check point not covered already
				if (points[l][u]) continue;
				// check length
				int dlength = l*l + u*u;
				if (dlength > ddeep) continue;

				//cover points by this ray
				int t = 1;
				while (l*t < deep + 1 && u*t < deep){
					points[l*t][u*t] = true;
					t++;
				}
				// build ray and it's symmetric ray
				Ray ray = new Ray(ddeep, dlength, l, u);
				rays.add(ray);
				rays.add(ray.symm());
			}
		}
		rays.add(new Ray(ddeep, 2, new byte[]{Ray.C}));
		int t = rays.size();
		for (int i = 0; i < t; i++){
			Ray r = rays.get(i);
			if (r.mDirs.length > 1 || r.mDirs[0] == Ray.C){
				Ray ar = new Ray(r);
				ar.revertL();
				ar.revertU();
				rays.add(ar);
			}
			if (r.mDirs.length > 1 || r.mDirs[0] != Ray.U){
				Ray ar = new Ray(r);
				ar.revertL();
				rays.add(ar);
			}
			if (r.mDirs.length > 1 || r.mDirs[0] != Ray.L){
				Ray ar = new Ray(r);
				ar.revertU();
				rays.add(ar);
			}
		}
		return rays;
	}
	
	public static void main(String[] args) throws Exception {
		/*List<Ray> rays = createAll(7);
		for (Ray r : rays){
			System.out.println(r);
		}*/
		String in_file = "q/d/l_in.txt";
		String out_file = in_file.replace("_in.txt", "_out.txt");
		BufferedReader in = new BufferedReader(new FileReader(in_file));
		BufferedWriter out = new BufferedWriter(new FileWriter(out_file));
		
		int n = Integer.parseInt(in.readLine());
		for (int i = 1; i <= n; i++){
			String[] s = in.readLine().split(" ");
			int h = Integer.parseInt(s[0]);
			int w = Integer.parseInt(s[1]);
			int d = Integer.parseInt(s[2]);
			int x = -1, y = -1;
			char[][] field = new char[h][w];
			for (int j = 0; j < h; j++){
				String fline = in.readLine();
				for (int k = 0; k < w; k++){
					field[j][k] = fline.charAt(k);
					if (field[j][k] == 'X'){
						x = k;
						y = j;
					}
				}
			}
			List<Ray> rays = createAll(d);
			int count = 0;
			for (Ray r : rays){
				// trace ray
				if (r.trace(x, y, field)) {
					//System.out.println(r);
					count++;
				}
			}
			out.write("Case #" + i + ": " + count + "\n");
		}
		
		in.close();
		out.close();
		
	}

}
