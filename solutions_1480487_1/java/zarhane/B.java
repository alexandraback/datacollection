

import java.io.*;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader(new File("A-large.in")));
		PrintWriter out = new PrintWriter(new File("B.out"));
		StringBuilder resultat =new StringBuilder("");
		
		int T = sc.nextInt();

		for (int t = 0; t < T; t++) {
			
			String r="";
			
			int N = sc.nextInt();
			int[] s = new int[N];
			int S = 0;
			
			for (int i = 0; i < N; i++) {
				s[i] =sc.nextInt();
				S += s[i];
			}
			
			
			int SG = 0;
			int NG = 0;
			for (int i = 0; i < N; i++) {	
				if(s[i]>=2*S/N)
					SG += s[i];
				else
					NG++;
			}
			
			
			//System.out.println(t);
			double R  =(2*S-SG);
			R = R/NG;
			
			//System.out.println("R=" + R);
			
			for (int i = 0; i < N; i++) {
				double d = R-s[i];
				r += " " + Math.max(0,(100*d/S));
				//System.out.println(r);
			}
			
			if(t!=0)
				resultat.append("\n");
			resultat.append("Case #"+(t+1)+":"+r);

		}
		
		
		
		out.print(resultat);
		out.close();
	}
}
