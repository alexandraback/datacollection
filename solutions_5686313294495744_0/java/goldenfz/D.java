package G2016A2;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;


public class D {
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("out.txt");
		int t=in.readInt();
		int n,max;
		String[][]topics;
		for(int i=1;i<=t;i++){
			n=in.readInt();
			topics=new String[n][];
			for(int j=0;j<n;j++){
				topics[j]=in.readNext().split(" ");
			}
			max=0;
			for(int k=(1<<n)-1;k>=1;k--){
				max=Math.max(solve(k,topics),max);
			}
			print(out,max,i);
		}
		out.flush();
		out.close();

	}

private static int solve(int k,String[][]topics){
	boolean []fake=new boolean[topics.length];
	int count=0;
	for(int i=fake.length-1;i>=0;i--){
		if(k%2==1){
			fake[i]=true;
			count++;
		}
		k/=2;
	}
	HashSet<String>[]map=new HashSet[20];
	for(int i=0;i<map.length;i++)map[i]=new HashSet<String>();
	for(int i=0;i<fake.length;i++){
		if(!fake[i]){
			for(int j=0;j<topics[i].length;j++){
				map[j].add(topics[i][j]);
			}
		}
	}
	for(int i=0;i<fake.length;i++){
		if(fake[i]){
			for(int j=0;j<topics[i].length;j++){
				if(!map[j].contains(topics[i][j])){
					return 0;
				}
			}
		}
	}
	return count;
	
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

			return br.readLine();
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
