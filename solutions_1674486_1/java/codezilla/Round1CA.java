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

public class Round1CA {
	
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
			int[][] cArr = new int[N+1][];
			
			for(int i = 1; i <= N; i ++){
				int m = scanner.nextInt();
				cArr[i] = new int[m + 1];
				
				for(int j = 1; j <= m; j ++){
					cArr[i][j] = scanner.nextInt(); 
				}
			}
			
			boolean[] workspace = new boolean[N+1];
			boolean yes = false;
			
			for(int i = 1; i < N; i ++){
				Arrays.fill(workspace, false);
				
				workspace[i] = true;
				yes = search(workspace, cArr, i);
				
				if(yes){
					break;
				}
			}

			out.format("Case #%d: %s", t, yes ? "Yes" : "No");

			out.println();

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
