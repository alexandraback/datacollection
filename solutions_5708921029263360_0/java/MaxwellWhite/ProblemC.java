import java.io.*;
import java.util.*;

public class ProblemC {
	
	public static void main(String[] agrs) throws FileNotFoundException {
		String FILENAME = "shortC";
		
		File FILE = new File(FILENAME);
		
		Scanner fileReader = new Scanner(FILE);
		
		int T =  fileReader.nextInt();
		
		for (int test = 0; test < T; test ++) {
			int J = fileReader.nextInt();
			int P = fileReader.nextInt();
			int S = fileReader.nextInt();
			int K = fileReader.nextInt();
			
			int[] JPS = {J,P,S};
			
			int maxClothing = 0;
			int max = JPS[0];
			
			for (int i = 1; i < 3; i ++) {
				if (JPS[i] > max){
					max = JPS[i];
					maxClothing = i;
				}
				
			}
			
			int[] z =  new int[3];
			
			int mem = 0;
			
			ArrayList<Integer> y2 = new ArrayList<Integer>();
			for (int i = 0; i < 3; i ++) {
				if (i != maxClothing) {
					y2.add(JPS[i]);
					z[mem] = i;
				}
			}
			
			y2.add(JPS[maxClothing]);
			z[2] = maxClothing;
			
			int[] y = new int[3];
			
			for (int i = 0; i < 3; i ++) {
				y[i] = y2.get(i);
			}
			
			
			int total;
			
			if (max <= K) {
				total = J * P * S;
				int[][] x = new int[total][3];
				int current = 0;
				for (int i = 0; i < J; i ++) {
					for (int j = 0; j < P; j ++) {
						for (int k = 0; k < S; k ++) {
							x[current][0] = i;
							x[current][1] = j;
							x[current][2] = k;
							current ++;
						}
					}
				}
				print(x, total, test);
				
			} else {
				int offset = 0;
				total = y[0] * y[1] * K;
				int[][] x = new int[total][3];
				int current = 0;
				for (int i = 0; i < y[0]; i ++) {
					for (int j = 0; j < y[1]; j ++) {
						for (int k = 0; k < K; k ++) {
							x[current][0] = i;
							x[current][1] = j;
							x[current][2] = (k + offset) % K;
							current ++;
						}
						offset ++;
					}
				}
				int[][] out =  new int[total][3];
				for (int i = 0; i < total; i ++) {
					out[i][z[0]] = x[i][0];
					out[i][z[1]] = x[i][1];
					out[i][z[2]] = x[i][2];
				}
				print(out, total, test);
			}
			
			
		}
		fileReader.close();
	}
	
	public static void print(int[][] matrix, int total, int test) {
		System.out.println("Case #" + (test+1) + ": " + total);
		for (int i = 0; i < total; i ++) {
			for (int j = 0; j < 3; j ++) {
				int a = matrix[i][j] + 1;
				System.out.print(a + " ");
			}
			System.out.println("");
		}
	}
}