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
			in = new BufferedReader(new FileReader("input.txt"));
			PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
			int T = nextInt();
			for(int q = 0; q < T; q++){
				String scoreA = next();
				String scoreB = next();
				
				String ansA = "";
				String ansB = "";
				
				boolean doneFront = false;
				int larger = -1;
				boolean sameS = false;
				for(int x = 0; x < scoreA.length(); x++){
					if (scoreA.charAt(x) == '?' && scoreB.charAt(x) == '?' && !doneFront){
						ansA += "0";
						ansB += "0";
						continue;
					}
					
					if (!doneFront){
						if (scoreA.charAt(x) < scoreB.charAt(x)){
							larger = 0;
						}
						else if (scoreA.charAt(x) == scoreB.charAt(x)){
							sameS = true;
							ansA += scoreA.charAt(x);
							ansB += scoreA.charAt(x);
							doneFront = true;
							continue;
							
						}
						else{
							larger = 1;
						}
						doneFront = true;
					}
					
					if (doneFront && larger == -1){
						if (scoreA.charAt(x) < scoreB.charAt(x)){
							larger = 0;
						}
						else if (scoreA.charAt(x) > scoreB.charAt(x)){
							larger = 1;
						}
					}
					
					if (scoreA.charAt(x) == '?' && scoreB.charAt(x) == '?' && sameS == false && larger != -1){
						if (larger == 0){ //first one is larger
							ansA += "9";
							ansB += "0";
						}	
						else{
							scoreA += "0";
							ansB += "9";
						}
						continue;
					}
					
					//&sameS == true
					if (scoreA.charAt(x) == '?' && scoreB.charAt(x) == '?' && (sameS == true || larger == -1)){
						if (larger == 0){ //first one is larger
							ansA += "0";
							ansB += "0";
						}	
						else{
							ansA += "0";
							ansB += "0";
						}
						continue;
					}
					
					
					
					if (scoreA.charAt(x) == '?' && sameS){
						ansA += scoreB.charAt(x);
						ansB += scoreB.charAt(x);
						continue;
					}
					
					if (scoreB.charAt(x) == '?' && sameS){
						ansA += scoreA.charAt(x);
						ansB += scoreA.charAt(x);
						continue;
					}
					
					if (!sameS && scoreA.charAt(x) != '?' && scoreB.charAt(x) != '?'){
						ansA += scoreA.charAt(x);
						ansB += scoreB.charAt(x);
						continue;
					}
					
					System.out.println("NONE");
					
				}
				out.println("Case #" + (q+1) + ": " + ansA + " " + ansB);
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