package G2016A1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class A {
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("out.txt");
		int t=in.readInt();
		for(int i=1;i<=t;i++){
			char []s=in.readNext().toCharArray();
			String []dp=new String[s.length];
			dp[0]=s[0]+"";
			for(int j=1;j<s.length;j++){
				
				if(dp[j-1].charAt(0)>s[j]){
					dp[j]=dp[j-1]+s[j];
				}else{
					dp[j]=s[j]+dp[j-1];
				}
			}
			print(out,dp[s.length-1],i);
		}
		out.flush();
		out.close();

	}
    private static String max(String a,String b){
    	return a.compareTo(b)>=0?a:b;
    }
    private static String min(String a,String b){
    	return a.compareTo(b)>=0?b:a;
    }
	private static void print(PrintWriter out,Object t,int cases){
		out.println("Case #"+cases+": "+t);
	}

	private static class Stdin {
		BufferedReader br;

		StringTokenizer st = new StringTokenizer("");

		private Stdin() throws FileNotFoundException {
			br = new BufferedReader(new FileReader("in.txt"));

		}

		private String readNext() throws IOException {

			while (!st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		private int readInt() throws IOException, NumberFormatException {

			return Integer.parseInt(readNext());

		}

		private long readLong() throws IOException, NumberFormatException {

			return Long.parseLong(readNext());

		}
		private double readDouble() throws IOException, NumberFormatException {

			return Double.parseDouble(readNext());

		}
	}
}
