package codejam_2015_1c;

import java.util.*;
import java.io.*;

public class C {

	private static void solve(int c_lim, List<Integer> arr, int v_max) {
		// TODO Auto-generated method stub
		int counter = 0;
		for(int candidate = 1; candidate <= v_max; candidate++) {
			boolean test = canForm(arr, candidate);
			//System.out.println(test + " " + candidate + " " + Arrays.toString(arr.toArray()));
			if( !canForm(arr, candidate) ) {
				counter++;
				arr.add(candidate);
				//System.out.println("added " + candidate);
			}
		}
		System.out.println(counter);
		
	}
	
	private static boolean canForm(List<Integer> arr, int candidate) {
		// TODO Auto-generated method stub
 		int max = (int) Math.pow(2, arr.size()); 
		max--;
		int bin = 1;
		while(bin <= max) {
			
			
			
			String binStr = Integer.toBinaryString(bin);
			//System.out.println("bin/max: " + binStr + " " + max + " " + arr.toString());
			
			
			int ptr = arr.size() - 1;
			int sum = 0;
			for(int offSet = 0; offSet < binStr.length(); offSet++) {
				if(binStr.charAt(binStr.length() - 1 -offSet) == '1') {
					sum += arr.get(ptr - offSet);
				}
			}
			//System.out.println(sum);
			if(sum == candidate) return true;
			bin++;
		}
		return false;
	}

	public static void solve() throws IOException {
		String homeFolder = "//Users//user//Documents//workspace//Runnables//src//" 
							+ C.class.getName().replaceFirst("\\..*", "")+ "//";
		String inFile = homeFolder + "C-small-attempt0.in"; //"C-small-attempt.in";
		String outFile = homeFolder + "C small output";

		Scanner in = new Scanner(new FileReader(inFile));
		FileWriter out = new FileWriter(outFile);
		int totalRounds = in.nextInt();
		for (int round = 1; round <= totalRounds; round++) {
			// FORMATTING HERE
			int c_lim = in.nextInt();
			int d = in.nextInt();
			int v_max = in.nextInt();
			List<Integer> list = new LinkedList<Integer>();
			
			for(int i = 0; i < d; i++) list.add(in.nextInt());
			
			System.out.format("Case #%d: ", round);
			solve(c_lim, list, v_max);
		}
		in.close();
		out.close();
	}
	


	public static void main(String[] args) throws IOException {
		solve();
		//System.out.println(canForm(Arrays.asList(1,2), 1));
	}
}