import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
 
public class Main {
	
	public static String[] currentLine;
	public static int n;
	
//	public static boolean valid(String[] seq) {
//		boolean v = true;
//		
//		if (seq[seq.length-1].charAt(seq[seq.length-1].length()-1) != seq[0].charAt(0)) {
//			for (int j = 1; j < seq.length-1; j++) {
//				if (seq[seq.length-1].charAt(seq[seq.length-1].length()-1) == seq[j].charAt(0)) {
//					v = false;
//					break;
//				}
//				if (seq[0].charAt(0) == seq[j].charAt(seq[j].length()-1)) {
//					v = false;
//					break;
//				}
//			}
//		}
//		else {
//			v = false;
//		}
//		
//		if (!v) {
//			for (int i = 1; i < seq.length; i++) {
//				if (seq[i-1].charAt(seq[i-1].length()-1) != seq[i].charAt(0)) {
//					
//					boolean w = true;
//					for (int j = 0; j < seq.length; j++) {
//						if (i-1 != j && i != j) {
//							if (seq[i-1].charAt(seq[i-1].length()-1) == seq[j].charAt(0)) {
//								w = false;
//								break;
//							}
//							if (seq[i].charAt(0) == seq[j].charAt(seq[j].length()-1)) {
//								w = false;
//								break;
//							}
//						}
//					}
//					
//					if (!w) {
//						v = false;
//						break;
//					}
//				}
//			}
//		}
//		
//		for (int i = 0; i < seq.length; i++) {
//			System.out.print(seq[i] + " ");
//		}
//		System.out.println(v);
//		
//		return v;
//	}
	
	public static boolean valid(String[] seq) {
		boolean v = true;
		
		String concat = "";
		for (int i = 0; i < seq.length; i++) {
			concat += seq[i]; 
		}
		
		Set<Character> used = new HashSet<>();
		char current = concat.charAt(0);
		used.add(current);
		for (int i = 1; i < concat.length(); i++) {
			if (concat.charAt(i) != current) {
				if (used.contains(concat.charAt(i))) {
					v = false;
					break;
				}
				current = concat.charAt(i);
				used.add(current);
			}
		}
		
		return v;
	}
	
	public static int dfs(int step, String[] curr, boolean[] used) {
		if (step == n) {
			if (valid(curr))
				return 1;
			else
				return 0;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				used[i] = true;
				curr[step] = currentLine[i];
				sum += dfs(step+1, curr, used);
				used[i] = false;
			}
		}
		return sum;
	}
	
	public static void main(String[] args) {
 
		BufferedReader br = null;
 
		try {
 
			br = new BufferedReader(new FileReader("B-small-attempt0.in"));
			
			int t = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < t; i++) {
				n = Integer.parseInt(br.readLine());
				currentLine = br.readLine().split(" ");
				
				boolean[] used = new boolean[n];
				Arrays.fill(used, false);
				String[] curr = new String[n];
				Arrays.fill(curr, "");
				
				int sum = dfs(0, curr, used);
				
				System.out.println("Case #" + (i+1) + ": " + sum);
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}