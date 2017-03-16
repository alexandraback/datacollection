package Q2015;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {
	static int min=1000;
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("B-small-attempt1.out");
		int T=in.readInt();
		int d,minCost,curCost;
		int p[];
		int max=0;
		for(int i=1;i<=T;i++){
			d=in.readInt();
			p=new int[d];
			max=0;
			for(int j=0;j<d;j++){
				p[j]=in.readInt();
				max=max<p[j]?p[j]:max;
			}
			minCost=max;
			for(int k=2;k<max;k++){
				curCost=k;
				for(int si:p){
					if(si>k){
						curCost+=(si/k+(si%k==0?-1:0));
					}
				}
				minCost=minCost<curCost?minCost:curCost;
			}			
			print(out,minCost,i);
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
			br = new BufferedReader(new FileReader("B-small-attempt1.in"));

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
