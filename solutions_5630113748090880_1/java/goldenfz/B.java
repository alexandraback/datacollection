package G2016A1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.StringTokenizer;


public class B {
		static int min;
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("out.txt");
		int t=in.readInt();
		int n,v;
		HashMap<Integer,Integer>count;
		ArrayList<Integer>list;
		for(int i=1;i<=t;i++){
			n=in.readInt();
			count=new HashMap<Integer,Integer>();
			list=new ArrayList<Integer>();
			for(int j=1;j<=2*n-1;j++){
				for(int k=0;k<n;k++){
					v=in.readInt();
					if(count.containsKey(v)){
						count.put(v, count.get(v)+1);
					}else{
						count.put(v, 1);
					}
				}
			}
			for(int key:count.keySet()){
				if(count.get(key)%2==1){
					list.add(key);
				}
			}
			Collections.sort(list);
			out.print("Case #"+i+":");
			for(int k:list){
				out.print(" "+k);
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
