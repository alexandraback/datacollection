package codejam.roundOne;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class DiamondInheritance {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("input.in"));
		Writer out = new FileWriter("output.txt");
		
		long time; //no see
		time = System.currentTimeMillis();
		
		// ignore test cases
		in.nextLine();
		
		int count = 1;
		while (in.hasNext()) {
			int N = in.nextInt();
			
			List<List<Integer>> classes = new ArrayList<List<Integer>>();
			
			for (int i=0; i<N; i++) {
				ArrayList<Integer> nums = new ArrayList<Integer>();
				
				int X = in.nextInt();
				for (int x=0; x<X; x++) {
					nums.add(in.nextInt());
				}
				classes.add(nums);
			}
			
			out.write("Case #" + count++ + ": " + (calc(classes)? "Yes\r\n" : "No\r\n"));
		}
		
		out.flush();
		out.close();
		in.close();
		System.out.println("Done in " + (System.currentTimeMillis() - time) / 1000f + " seconds!");
	}
	
	public static boolean calc(List<List<Integer>> classes) {
		for (List<Integer> c: classes) {
			int found[] = new int[51];
			
			for (int x: c) {
				int[] f = buildMap(classes, x);
				
				for (int a=0; a<f.length; a++) {
					found[a] += f[a];
				}
				
				found[x]++;
			}
		
			for (int i: found) {
				if (i > 1) return true;
			}
		}
		
		return false;
	}
	
	public static int[] buildMap(List<List<Integer>> classes, int pos) {
		int found[] = new int[51];
		
		if (classes.get(pos-1).size() == 0) {
			return found;
		}
		for (int i: classes.get(pos-1)) {
			int[] f = buildMap(classes, i);
			
			for (int x=0; x<f.length; x++) {
				found[x] += f[x];
			}
			
			found[i]++;
		}
		return found;
	}
}
