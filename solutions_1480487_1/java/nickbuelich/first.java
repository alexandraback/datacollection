import java.io.*;
import java.util.*;


public class first {
	public static void main(String[] args) throws Exception {
		FastScanner sc = new FastScanner(new File("A.in"));
		PrintWriter out = new PrintWriter(new File("A.out"));
		int I = sc.nextInt();
		for(int i=1;i<=I;i++){
			int N = sc.nextInt();
			out.print("Case #"+i+":");
			System.out.print("Case #"+i+":");
			double[] start = new double[N];
			double total = 0;
			for(int a=0;a<N;a++){
				start[a]+=sc.nextDouble();
				total+=start[a];
			}
			for(int a=0;a<N;a++){
				ArrayList<Double> AL = new ArrayList<Double>();
				for(int b=0;b<N;b++)if(a!=b)AL.add(start[b]);
				double res = function(start[a],AL,total);
				out.printf(" %.10f",res);
				System.out.printf(" %.10f",res);
				
			}
			out.println();
			System.out.println();
			
			
			

		}
		
		out.close();
	}
	
	
	private static double function(double person, ArrayList<Double> AL, double total) {
		//want p1 = average of prest with outliers excluded
		double low = 0;
		double high = 100.0;
		double mid = 0;
		while(low+1e-14<high){
			mid= (low+high)/2;
			double pscore = person + total*(mid/100);
			double others = calculate(AL, total, 1-(mid/100));
			if(pscore<others){
				low = mid;
			}
			else {
				high = mid;
			}
		}
		return mid;
	}


	private static double calculate(ArrayList<Double> AL, double total, double percent) {
		//Arraylist of people getting p percent of the score, balenced
		double ttl = total*percent;
		for(double d : AL)ttl+=d;
		ttl/=AL.size();
		ArrayList<Double> two = new ArrayList<Double>();
		for(double d : AL){
			if(d<ttl)two.add(d);
		}
		
		if(two.size()!=AL.size())return calculate(two,total,percent);
		
		else return ttl;
		
	}


	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		
		public FastScanner(File file) throws Exception{
			br = new BufferedReader(new FileReader(file));
			st = new StringTokenizer(br.readLine().trim());
		}
		public int numTokens() throws Exception {
			if(!st.hasMoreTokens()){
				st = new StringTokenizer(br.readLine().trim());
				return numTokens();
			}
			return st.countTokens();
		}
		public String next() throws Exception {
			if(!st.hasMoreTokens()){
				st = new StringTokenizer(br.readLine().trim());
				return next();
			}
			return st.nextToken();
		}
		public double nextDouble() throws Exception{
			return Double.parseDouble(next());
		}
		public float nextFloat() throws Exception{
			return Float.parseFloat(next());
		}
		public long nextLong() throws Exception{
			return Long.parseLong(next());
		}
		public int nextInt() throws Exception{
			return Integer.parseInt(next());
		}
		public String nextLine() throws Exception{
			return br.readLine().trim();
		}
	}

}
