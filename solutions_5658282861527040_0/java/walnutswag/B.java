package round1b;

import java.io.*;
import java.util.*;

import metrics.Timer;

public class B {

	public static void main(String[] args) throws IOException {

		String path = "B";

		BufferedReader in = new BufferedReader(new FileReader(Main.DIR + path + ".in"));
		PrintWriter out = new PrintWriter(Main.DIR + path + ".out");
		int inputs = Integer.parseInt(in.readLine());

		for (int idx = 0; idx < inputs; idx++) {
			System.out.print("Case #"+(idx+1)+": ");
			out.print("Case #"+(idx+1)+": ");
			
			String[] split = in.readLine().split(" ");
			int A = Integer.parseInt(split[0]);
			int B = Integer.parseInt(split[1]);
			int K = Integer.parseInt(split[2]);
			
			String Astr = Integer.toString(A, 2);
			String Bstr = Integer.toString(B, 2);
			String Kstr = Integer.toString(K, 2);
			Astr = new StringBuilder(Astr).reverse().toString();
			Bstr = new StringBuilder(Bstr).reverse().toString();
			Kstr = new StringBuilder(Kstr).reverse().toString();
			
		
			
			long prod = 1;
			
//			for (int i = 0; i < Kstr.length(); i++) {
//				char kChar = Kstr.charAt(i);
//				char aChar = Astr.charAt(i);
//				char bChar = Bstr.charAt(i);
//				
//				if (kChar == '0') {
//					
//				}
//				else {
//					
//				}
//			}
			
			long count = 0;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < B; j++) {
					if ((i&j) < K)
						count++;
				}
			}
			
			System.out.println(count);
			out.println(count);
			
		}
		in.close();
		out.close();

	}

}
