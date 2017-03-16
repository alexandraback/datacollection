package G2016A2;

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
		char []str;
		int []count;
		int []counting;
		for(int i=1;i<=t;i++){
			str=in.readNext().toCharArray();
			count=new int[26];
			counting=new int[10];
			for(char c:str){
				count[c-'A']++;
			}
			counting[6]=count['X'-'A'];
			counting[8]=count['G'-'A'];
			counting[0]=count['Z'-'A'];
			counting[4]=count['U'-'A'];
			counting[2]=count['W'-'A'];
			counting[7]=count['S'-'A']-counting[6];
			counting[5]=count['V'-'A']-counting[7];
			counting[3]=count['H'-'A']-counting[8];
			counting[1]=count['O'-'A']-counting[0]-counting[2]-counting[4];
			counting[9]=count['I'-'A']-counting[5]-counting[6]-counting[8];
			out.print("Case #"+i+": ");
			for(int j=0;j<10;j++){
				for(int k=0;k<counting[j];k++){
					out.print(j);
				}
			}
			out.println();
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
