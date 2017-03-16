import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
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
		for (int i = 0; i < N; i++) {
			maxI.put(i, -1);
		}
		for (int j = 0; j < M; j++) {
			maxJ.put(j, -1);
		}
//		toMowI = new int[101][101];
//		toMowJ = new int[101][101];
	}
	
	public int N;
	public int M;
	public int[][] target;
	public boolean[][] mowed;
	public TreeSet<Integer> values = new TreeSet<Integer>();
	public Map<Integer, Integer> maxI = new HashMap<Integer, Integer>();
	public Map<Integer, Integer> maxJ = new HashMap<Integer, Integer>();
	
	public void set(int i, int j, int v) {
		target[i][j] = v;
		maxI.put(i, Math.max(maxI.get(i), v));
		maxJ.put(j, Math.max(maxJ.get(j), v));
		values.add(v);
	}
	
	public boolean isValid(int v) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (target[i][j] == v && !mowed[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	
	public boolean isPossible() {
//		System.out.println("compute");
		for (int e : values) {
//			System.out.println("e:" + e);
			for (int i = 0; i < N; i++) {
//				System.out.println("i:" + i);
//				System.out.println("0:" + target[i][0]);
//				System.out.println("M-1:" + target[i][M-1]);
//				System.out.println("maxI: " + maxI.get(i));
				if ((e >= target[i][0] || e >= target[i][M-1]) && e >= maxI.get(i)) {
//					System.out.println("meow");
					for (int j = 0; j < M; j++) {
						if (target[i][j] == e){
							mowed[i][j] = true;
						}
					}
				}
			}

//			System.out.println(this);
			
			for (int j = 0; j < M; j++) {
				if ((e >= target[0][j] || e >= target[N-1][j]) && e >= maxJ.get(j)) {
					for (int i = 0; i < N; i++) {
						if (target[i][j] == e){
							mowed[i][j] = true;
						}
					}
				}
			}
			
//			System.out.println(this);
			
			if (!isValid(e)) {
				return false;
			}
		}
		return true;
	}
	
	public String toString() {
		String rs = "";
//		for (int i = 0; i < N; i++) {
//			rs += Arrays.toString(mowed[i]) + "\n";
//		}
		return rs;
	}
	
	public static void main(String args[]) throws IOException{
		Scanner scin = new Scanner(new File("in2.txt"));
		FileWriter fw = new FileWriter(new File("out2.txt"));

		int T = scin.nextInt();
		
		for (int cs = 1; cs < T + 1; cs++) {
			int N = scin.nextInt();
			int M = scin.nextInt();
//			System.out.println("cs" + cs);

			Lawnmower lm = new Lawnmower(N, M);
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					lm.set(i, j, scin.nextInt());
				}
			}
			
			boolean possible = lm.isPossible();
//			System.out.println(lm);
//			
//			System.out.println(possible);
			
			fw.write("Case #"+cs+": " + (possible ? "YES" : "NO") + "\n");
		}
		
		fw.close();
	}
}
