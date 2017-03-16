package cj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class CJ2013_1b_1 {

	public final static String LOC = "./src/cj/"; // the package name, cj, is where you should put input files

	public static void main(String[] args) {
		try (	BufferedReader bf = new BufferedReader(new FileReader(LOC + args[0] + ".in"));
				BufferedWriter bw = new BufferedWriter(new FileWriter(LOC + args[0] + ".out"));) {
			
			int numberOfCases = Integer.valueOf(bf.readLine());

			for (int caseNum=1; caseNum <= numberOfCases; caseNum++) {
				String result = solve(bf);
				
				bw.write("Case #" + (caseNum) + ": "  + result + "\n");
				
				System.out.println("Case #" + (caseNum) + ": " + result); // for your convenience

			}
		} catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		}
	}
	
	private static String solve(BufferedReader bf) throws NumberFormatException, IOException {
		String[] first = bf.readLine().split(" ");
		
		long ms = Long.valueOf(first[0]);
		
		int maxOps = Integer.valueOf(first[1]);
		
		String[] mString = bf.readLine().split(" ");
		
		int motes[] = new int[maxOps];
		
		for (int i=0; i< motes.length;i++)
			motes[i] = Integer.valueOf(mString[i]);

		Arrays.sort(motes);
		
		int actions = 0;
		
		if (ms == 1) return String.valueOf(maxOps);
		
		for (int i=0; i<motes.length;i++) {
			if (ms > motes[i]) {
				ms += motes[i];
			} else {
				long newMs = ms;
				int newActions = 0;
				
				while (motes[i] >= newMs) {
					newMs = (newMs * 2) - 1;
					newActions ++;
				}
				
				if (newActions > motes.length - i) {
					actions += (motes.length-i);
					break;
				} else {
					ms = newMs;
					actions += newActions;
					ms += motes[i];
				}
			}
		}
		
		return String.valueOf(Math.min(actions, maxOps));
	}
}
