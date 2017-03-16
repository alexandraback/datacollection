package G2016A1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class C {
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("out.txt");
		int t=in.readInt();
		int n;
		int []bff;
		for(int i=1;i<=t;i++){
			//long t1=System.currentTimeMillis();
			n=in.readInt();
			bff=new int[n];
			for(int j=0;j<n;j++){
				bff[j]=in.readInt()-1;
			}
			print(out,solve(bff,n),i);
			//System.out.println(i+" "+(System.currentTimeMillis()-t1)/1000);
		}
		out.flush();
		out.close();

	}
private static int solve(int[]bff,int n){
	int max=(1<<n)-1;
	int maxValue=0;
	ArrayList<Integer>list;
	for(int i=0;i<=max;i++){
		list=new ArrayList<Integer>();
		for(int j=0;j<n;j++){
			if(((i>>j)&1)==1){
				list.add(j);
			}
		}
		if(list.size()<2)continue;
		int []cur=new int[list.size()];
		for(int j=0;j<list.size();j++)cur[j]=list.get(j);
		LinkedList<int[]>all=new LinkedList<int[]>();
		permutation(cur,0,all);
		for(int[]each:all){
			if(isValid(bff,each,cur.length)){
				maxValue=maxValue<cur.length?cur.length:maxValue;
				break;
			}
		}
	}
	return maxValue;
}

private static boolean isValid(int[]bff,int []order,int n){
	if(!(bff[order[0]]==order[n-1]||bff[order[0]]==order[1])){
		return false;
	}
	for(int i=1;i<n;i++){
		if(bff[order[i]]==order[i-1]||bff[order[i]]==order[(i+1)%n])continue;
		else return false;
	}
	return true;
}

private static void permutation(int []a,int k,LinkedList<int[]>ans){  // including same element
	if(k==a.length-1){		
		ans.add(a.clone());
		return;
	}else{
		for(int i=k;i<a.length;i++){
			swap(a,k,i); // get next		
			permutation(a,k+1,ans); // do next parts
			swap(a,k,i); //  keep pre
		}
		
	}
	
}

private static void swap(int []a,int k,int j){
	int tem=a[k];
	a[k]=a[j];
	a[j]=tem;
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
