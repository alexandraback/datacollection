package gcj2014r1c;


import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class SolutionB {
	
	public static String IN_FILE = "practice.in";
	public static String OUT_FILE = "practice.out";

	public static String WORKSPACE = "C:/Users/main/Desktop/";
	
	class Case {
		
		
		int N; 
		String[] cars;
		String[] sigs;
		public void parse(Scanner sc) throws IOException {
			N = sc.nextInt();
			cars = new String[N];
			sigs = new String[N];
			
			for (int i=0; i<N; i++) {
				cars[i] = sc.next();
				char[] charArr = cars[i].toCharArray();
				char prev = charArr[0];
				String sig = prev + "";
				for (int j =0; j<charArr.length; j++) {
					char curr = charArr[j];
					if (curr!= prev)
						sig += curr;
					prev = curr;
				}
				sigs[i] = sig;
			}

		}
		
		long result = 0;
		
		String gjs ="";
		HashSet<Integer> used = new HashSet<Integer>();
		public void solve() {
			for (int i=0; i<N; i++) {
				String sig = sigs[i];
				for (int j=0; j<sig.length(); j++) {
					char charj = sig.charAt(j);
					if (sig.substring(0, j).indexOf(charj) >= 0) {
						result = 0;
						return;
					}
				}
			}
			
			solve(0);
		}
		private void solve(int considered) {
			if (considered == N) {
				result ++;
				return;
			}
			char currEnd = ' ';
			if (considered > 0) { 
				currEnd = gjs.charAt(gjs.length()-1);
			}
			outerfor:
			for (int i=0; i<N; i++) {
				if (used.contains(i))
					continue;
				String next = sigs[i];
				
				if (gjs.indexOf(next.charAt(0)) == -1) {

					for (int j = 0; j<next.length(); j++) {
						if (gjs.indexOf(next.charAt(j))>=0) {
							continue outerfor;
						}
					}
					used.add(i);
					int oldLen = gjs.length();
					for (int j = 0; j<next.length(); j++) {
						gjs += next.charAt(j);
					}
					solve (considered + 1);
					gjs = gjs.substring(0, oldLen);
					used.remove(i);

				}
				else if (next.charAt(0) == currEnd){
				 
					for (int j = 1; j<next.length(); j++) {
						if (gjs.indexOf(next.charAt(j))>=0) {
							continue outerfor;
						}
					}	
					used.add(i);
					int oldLen = gjs.length();
					for (int j = 1; j<next.length(); j++) {
						gjs += next.charAt(j);
					}
					solve (considered + 1);
					gjs = gjs.substring(0, oldLen);

					used.remove(i);

				}
			}
		}
		


		public String getResult() {
			return result + "";
		}

	}

	private void run() {
		try {
			
			Scanner sc = new Scanner(new FileReader(new File(WORKSPACE + IN_FILE)));
			
			File outFile = new File(WORKSPACE + OUT_FILE);
			if (!outFile.exists())
				outFile.createNewFile();
			BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));

			int caseN = sc.nextInt();
					
			for (int i = 0; i < caseN; i++) {
				Case caseI = new Case();
				caseI.parse(sc);
				System.out.println("Solving case: " + (i+1));
				caseI.solve();
				writer.write("Case #" + (i+1) +": " + caseI.getResult() +"\r\n");
			}
			System.out.println("Done.");
			
			sc.close();
			writer.close();

		} catch (IOException e) {
			e.printStackTrace();
		} 
	}

	public static void main(String[] args) {
		SolutionB sol = new SolutionB();
		sol.run();
	}
}
