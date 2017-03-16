package G2016A2;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class B {
		static int min;
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("out.txt");
		int t=in.readInt();
		char[]c,j;
		int limit = 0;
		for(int i=1;i<=t;i++){
			c=in.readNext().toCharArray();
			j=in.readNext().toCharArray();
			if(c.length==1)limit=9;
			if(c.length==2)limit=99;
			if(c.length==3)limit=999;
			int diff=10000,c0=0,j0=0;
			for(int c1=0;c1<=limit;c1++){
				if(!valid(c,c1))continue;
				for(int j1=0;j1<=limit;j1++){
					if(valid(j,j1)){
						if(Math.abs(c1-j1)<diff){
							diff=Math.abs(c1-j1);
							c0=c1;
							j0=j1;
						}else{
							if(Math.abs(c1-j1)==diff){
								if(c1<=c0&&j1<=j0){
									c0=c1;
									j1=j0;
								}
							}
						}
					}
				}
			}
			out.println("Case #"+i+": "+toString(c.length,c0)+" "+toString(c.length,j0));
			
		}
		
		out.flush();
		out.close();

	}
	private static String toString(int length,int num){
		StringBuilder sb=new StringBuilder();
		int temp=num;
		while(temp>0){
			length--;
			temp/=10;
		}
		for(int i=0;i<length;i++){
			sb.append(0);
		}
		if(num>0)
			sb.append(num);
		return sb.toString();
		
	} 
	private static boolean valid(char[]c,int num){
		for(int i=c.length-1;i>=0;i--){
			if(c[i]!='?'&&num%10!=(c[i]-'0'))return false;
			num/=10;
		}
		return true;
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
