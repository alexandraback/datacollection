/*
PROG: Prob1AC
LANG: JAVA
ID: sridhar4
*/

import java.io.*;
import java.util.*;

public class Prob1AC{

	public static void main(String [] args) throws IOException {
		//long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(new FileReader("Prob1AC.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Prob1AC.out")));
		f.readLine();
		f.readLine();
		int R = 100;
		int N = 3;
		int M = 5;
		int K = 7;
		String finans = "Case #1:\n";
		for(int q = 0; q < R; q++){
			String ans = "";
			int[] products = new int[K];
			String[] s = (f.readLine()).split(" ");
			for(int i = 0; i < K; i++){
				products[i] = Integer.parseInt(s[i]);
			}
			for(int a = M; a >= 2; a--){
				for(int b = M; b >= 2; b--){
					for(int c = M; c >= 2; c--){
							Set<Integer> set = new HashSet<Integer>();
							for(int bin = 0; bin < 8; bin++){
								int x = bin;
								int prod = Math.max(a*(x % 2),1);
								x /= 2;
								prod *= Math.max(b*(x % 2),1);
								x /= 2;
								prod *= Math.max(c*(x % 2),1);
								set.add(prod);
							}
							boolean flag = true;
							for(int i = 0; i < K; i++){
								if(!set.contains(products[i])){
									flag = false;
									break;
								}
							}
							if(flag)
								ans = a + "" + b + "" + c;
					}
				}
			}
			finans += ans + "\n";
		}
		out.print(finans);
		//long end = System.currentTimeMillis();
		//System.out.println(end - start);
		out.close();
	}
	

}