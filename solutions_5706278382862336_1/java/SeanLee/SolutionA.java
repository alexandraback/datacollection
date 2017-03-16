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

public class SolutionA {
	
	public static String IN_FILE = "practice.in";
	public static String OUT_FILE = "practice.out";

	public static String WORKSPACE = "C:/Users/main/Desktop/";
	
	class Case {
		long P;
		long Q;
		
		int result;
		
		public void parse(Scanner sc) throws IOException {
			String pair = sc.next();
			String[] cells = pair.split("/");
			
			P = Long.parseLong(cells[0]);
			Q = Long.parseLong(cells[1]);

		}
		
		public long GCD(long a, long b) {
			   if (b==0) return a;
			   return GCD(b,a%b);
			}
		
		public void solve() {
			
			long gcd = GCD(P, Q);
			P = P / gcd;
			Q = Q / gcd;
			
			if ((Q & (Q-1)) != 0) {
				result = -1;
				return;
			}
			
			int Qn = 0;
			long qq = Q;
			while (true) {
				if (qq == 1)
					break;
				qq = qq >> 1;
				Qn ++;
			}
			
			int Pn = 0;
			long pp = P;
			while (true) {
				if (pp == 1)
					break;
				pp = pp >> 1;
				Pn ++;
			}
			
			result = Qn- Pn;
			
		}
		public String getResult() {
			if (result == -1)
				return "impossible";
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
		SolutionA sol = new SolutionA();
		sol.run();
	}
}
