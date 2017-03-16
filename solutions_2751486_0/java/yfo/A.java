package round1C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {
	static File inFile = new File("inA.txt");
	static File outFile = new File("outA.txt");

	static BufferedReader in;
	static BufferedWriter out;
	static Scanner sc;

	static int T = 0;	
	
	public static void solve() throws IOException{

		T = sc.nextInt();
		for (int t=0;t<T;t++) {						
			long res = 0;
			String name = sc.next();
			int n = sc.nextInt();
			int L = name.length();	
			long[]dp = new long[L];
			int maxSub = 0;
			for (int i=0;i<L;i++) {
				char c = name.charAt(i);
				if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
					maxSub = 0;
					if (i+1<n) {
						dp[i] = 0;
						continue;
					}
					
					if (i>0) dp[i]=dp[i-1];
					else dp[i]=0;
				} else {
					maxSub++;
					if (i+1<n) {
						dp[i] = 0;
						continue;
					}
					if (maxSub>=n) {
						dp[i]=(i+1)-n+1;
					}
					else dp[i]=dp[i-1];
					
				}
				//i>=n
				
			}
			
			for (int i=0;i<L;i++) res+=dp[i];
					
			//out.write("Case #"+(t+1)+": "+res+"\n");\
			out.write("Case #"+(t+1)+": "+res+"\n");
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		try {
			in = new BufferedReader(new FileReader(inFile));
			out = new BufferedWriter(new FileWriter(outFile));
			sc = new Scanner(in);
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			in.close();
			out.close();		
		}		

	}
}

