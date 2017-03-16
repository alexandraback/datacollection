package codejam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Round1CB {
	
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
			
			double D = scanner.nextDouble();
			int N = scanner.nextInt();
			int A = scanner.nextInt();
			
			double[] times = new double[N];
			double[] positions = new double[N];
			
			for(int i = 0; i < N; i ++){
				times[i] = scanner.nextDouble();
				positions[i] = scanner.nextDouble();
			}
			
			double[] gravities = new double[A];
			
			for(int i = 0; i < A; i ++){
				gravities[i] = scanner.nextDouble();
			}
			
			double[] result = new double[A];
			
			for(int i = 0; i < A; i ++){
				
				double a = gravities[i];
				double startP = 0;
				double startT = 0;
				double startSpeed = 0;
				
				boolean last = false;
				
				for(int j = 0; j < N - 1 && !last; j ++){
					
					double deltaT = times[j + 1] - times[j];
					
					if(positions[j + 1] >= D){
						//deltaT *= (D - positions[j]) / (positions[j + 1] - positions[j]);
						deltaT = (D - positions[j]) * (times[j + 1] - times[j]) / (positions[j + 1] - positions[j]);
						times[j + 1] =  times[j] + deltaT;
						positions[j + 1] = D;
						last = true;
					}
					
					double maxMove = startSpeed * deltaT + 0.5 * a * deltaT * deltaT;
					
					// cannot overpass
					if(maxMove <= positions[j + 1]){
						startP += maxMove;
						startSpeed += a * deltaT;
					} else {
						startP = positions[j + 1];
						
						if(deltaT < 1e-6){
							startSpeed = 0;
						} else {
							double speed1 = (positions[j + 1] - positions[j]) / deltaT;
							double speed2 = Math.sqrt(2 * a * (positions[j + 1] - positions[j]));
							startSpeed = Math.max(speed1, speed2);
						}
					}
					startT = times[j + 1];
				}
				
				if(D - startP > 1e-6){
					
					double ss = D - startP;
					double tt = Math.sqrt(4 * startSpeed * startSpeed + 8 * a * ss);
					tt = (tt - 2 * startSpeed) / (2 * a);
					
					startT += tt;
					
//					double hi = 1e5;
//					double lo = 0;
//					
//					while(hi - lo > 1e-5){
//						double mi = (hi + lo) / 2;
//						double s = startSpeed * mi + 0.5 * a * mi * mi;
//						
//						if(s + startP > D){
//							hi = mi;
//						} else {
//							lo = mi;
//						}
//					}
//					
//					startT += lo;
				}
				
				result[i] = startT;
				
			}

			out.format("Case #%d:\n", t);
			
			for(int i = 0; i < A; i ++){
				out.println("" + result[i]);
			}


		}

		scanner.close();
		out.close();
	}




	private static boolean search(boolean[] workspace, int[][] cArr, int i) {
		

		for(int j = 1; j < cArr[i].length; j ++){
			if(workspace[ cArr[i][j] ]){
				return true;
			}
			
			workspace[cArr[i][j]] = true;
			
			boolean b = search(workspace, cArr, cArr[i][j]);
			
			if(b){
				return true;
			}
		}
		
		
		return false;
	}




	static <E> String joinList(List<E> list, String sep){
		
		if(list == null || list.isEmpty()){
			return "";
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append(list.get(0));
		
		Iterator<E> it = list.iterator();
		it.next();
		
		while(it.hasNext()){
			sb.append(sep).append(it.next());
		}
		
		return sb.toString();
	}
	
	static String joinArray(int[] arr, String sep){
		
		if(arr == null || arr.length == 0){
			return "";
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append(arr[0]);
		
		for(int i = 1; i < arr.length; i ++){
			sb.append(sep).append(arr[i]);
		}
		
		return sb.toString();
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

		public void println() {
			pw.println();
			System.out.println();
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
