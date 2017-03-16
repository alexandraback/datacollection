/* Programming Competition - Template (Horatiu Lazu) */

import java.io.*;
import java.util.*;
import java.lang.*;
import java.awt.*;
import java.awt.geom.*;
import java.math.*;
import java.text.*;


class Main{
	BufferedReader in;
	StringTokenizer st;
	
	public static void main (String [] args){
		new Main();
	}

	public Main(){
		try{
			in = new BufferedReader(new FileReader("problemA-large.in"));
			PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
			int T = nextInt();
			for(int q = 0; q < T; q++){
				String s = next();
				//now sort ?
				String n = "";
				for(int x = 0; x < s.length(); x++){
					if (x == 0){
						n = s.charAt(0) + "";	
					}
					else{
						if (n.charAt(0) <= s.charAt(x)){
							n = s.charAt(x) + n;
						}
						else{
							n = n + s.charAt(x);
						}
					}
				}
				out.println("Case #" + (q+1) + ": " + n);
			}
			out.close();
			
		}
		catch(IOException e){
			System.out.println("IO: General");
		}
	}
	
	String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
	   	 	st = new StringTokenizer(in.readLine().trim());
		return st.nextToken();
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	String nextLine() throws IOException {
		return in.readLine().trim();
	}
}