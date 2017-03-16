package Q2015;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class A {
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("A-large.out");
		int T=in.readInt();
		int S,cur,need,audience;
		char si[];
		for(int i=1;i<=T;i++){
			S=in.readInt();
			si=in.readNext().toCharArray();
			need=0;
			cur=0;
			for(int j=0;j<si.length;j++){
				audience=si[j]-'0';
				if(audience==0)
					continue;
				if(cur>=j){
					cur+=audience;
				}else{
					need+=j-cur;
					cur=j+audience;
				}
			}
			print(out,need,i);
		}
		out.flush();
		out.close();

	}
	
	private static void print(PrintWriter out,Object t,int cases){
		out.println("Case #"+cases+": "+t);
	}

	private static class Stdin {
		BufferedReader br;

		StringTokenizer st = new StringTokenizer("");

		private Stdin() throws FileNotFoundException {
			br = new BufferedReader(new FileReader("A-large.in"));

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
