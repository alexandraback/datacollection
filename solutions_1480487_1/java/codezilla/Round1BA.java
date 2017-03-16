package codejam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Round1BA {
	
	static class Item {
		int cost1;
		int cost2;
		int level;
		int status;
		
		Item(int l, int c1, int c2){
			level = l;
			cost1 = c1;
			cost2 = c2;
		}
	}

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new BufferedReader(new FileReader(
				"A-large-practice.in.txt")));
		Output out = new Output("A.out");

		int T = scanner.nextInt();

		for (int t = 1; t <= T; t++) {
			
			int N = scanner.nextInt();
			int[] sArr = new int[N];
			
			int ind1 = -1;
			int ind2 = -1;
			double sum = 0;
			for(int i = 0; i < N; i ++){
				sArr[i] = scanner.nextInt();
				
				if(ind1 == -1 || sArr[i] < sArr[ind1]){
					ind1 = i;
				}
				
				sum += sArr[i];
			}
			
			for(int i = 0; i < N; i ++){
				
				if(i != ind1 && (ind2 == -1 || sArr[i] < sArr[ind2])){
					ind2 = i;
				}
			}

			double[] result = new double[N];
			
			double d = sum * 2 / N;
			
			double collect = 0.0;
			int count = N;
			
			for(int i = 0; i < N; i ++){
				
				result[i] = (d - sArr[i]) * 100 / sum;

				if(result[i] < 0){
					collect += result[i];
					count --;
				}
			}
			
			for(int i = 0; i < N; i ++){
				
				if(result[i] > 0){
					result[i] += (collect/count);
				} else {
					result[i] = 0;
				}
			}

			out.format("Case #%d: %f", t, result[0]);
			
			for(int i = 1; i < N; i ++){
				out.format(" %f", result[i]);
			}
			
			out.println("");

		}

		scanner.close();
		out.close();
	}


	static class Output {

		PrintWriter pw;

		public Output(String filename) throws IOException {
			pw = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
		}

		public void print(String s) {
			pw.print(s);
			System.out.print(s);
		}

		public void println(String s) {
			pw.println(s);
			System.out.println(s);
		}

		public void format(String format, Object... args) {
			pw.format(format, args);
			System.out.format(format, args);
		}

		public void close() {
			pw.close();
		}
	}

}
