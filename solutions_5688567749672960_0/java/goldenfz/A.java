package R1B_2015;

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
		PrintWriter out = new PrintWriter("A-small-attempt1.out");
		int t=in.readInt();
		long n;
		for(int i=1;i<=t;i++){
			n=in.readLong();
			print(out,bfs(n),i);
		}
		out.flush();
		out.close();

	}
	private static long solve(long n,int count){
		if(n==1)
			return count;
		if(n%10==0)
			return solve(n-1,count+1);
		return solve(Math.min(reverse(n),n-1),count+1);
	}
	private static long solve1(long n,int count){
		if(n==1)
			return 1;
		if(n%10==0)
			return solve(n-1,count+1)+1;
		return Math.min(solve(reverse(n),count+1)+1,solve(n-1,count+1)+1);
	}
	private static long bfs(long n){
		if(n==1)
			return 1;
		LinkedList<Long>list=new LinkedList<Long>();
		HashSet<Long>visited=new HashSet<Long>();
		long cur,rv,size;
		long level=1;
		list.add((long) 1);
		while(!list.isEmpty()){
			size=list.size();
			while(size>0){
				cur=list.pollFirst();
				rv=reverse(cur);
				cur++;
				if(rv==n||cur==n)
					return level+1;
				if(!visited.contains(cur)){
					list.add(cur);
					visited.add(cur);
				}
				if(!visited.contains(rv)){
					list.add(rv);
					visited.add(rv);
				}
				size--;
			}
			size=list.size();
			level++;
		}
		return level;
		
	}
	private static long reverse(long n){
		long t=0;
		while(n>0){
			t=t*10+n%10;
			n/=10;
		}
		return t;
	}
	private static void print(PrintWriter out,Object t,int cases){
		out.println("Case #"+cases+": "+t);
	}

	private static class Stdin {
		BufferedReader br;

		StringTokenizer st = new StringTokenizer("");

		private Stdin() throws FileNotFoundException {
			br = new BufferedReader(new FileReader("A-small-attempt1.in"));

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
