import java.io.*;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.StringTokenizer;

//remember to change task name; change public class name!
public class prB {

	static void solve() throws Exception{
		int t=nextInt();
		for(int k=1;k<t+1;k++)
		{
			double C=nextDouble();
			double F=nextDouble();
			double X=nextDouble();
			double rate=2;
			out.println("Case #"+k+": "+recur(rate,C,F,X));
		}
	}
	static double recur(double rate, double C, double F, double X){
		if(X/rate<=(C/rate+(X)/(rate+F)))return X/rate;
		else return C/rate+recur(rate+F,C,F,X);
	}

	public static void main(String[] args) throws Exception {
		String filename="B-small-attempt0";// change name here!
		in = new BufferedReader(new FileReader(filename+".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(filename+".out")));

		//	setTime();
		solve();
		in.close();
		//printTime();
		//	printMemory();
		out.close();
		System.exit(0);
	}
	static double time;
	static void setTime(){
		time=System.currentTimeMillis();
	}
	static void printTime(){
		System.err.println("Time consumed (sec): "+(System.currentTimeMillis()-time)/1024);
	}
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok = new StringTokenizer("");
	//	static long systemTime;
	static void printMemory() {
		System.err.println("Memory consumed: "
				+ (Runtime.getRuntime().totalMemory() - Runtime.getRuntime()
				.freeMemory()) / 1000 + " kb");
	}
	static void println(Object o){
		out.println(o);
		//	System.err.println(o);
	}
	static void print(Object o){
		out.print(o);
		//	System.err.print(o);
	}

	static String nextLine() throws Exception{
		return in.readLine();
	}
	static String next() {//if !hasNext returns null
		while (!tok.hasMoreTokens()) {
			String w = null;
			try {
				w = in.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (w == null)
				return null;
			tok = new StringTokenizer(w);
		}
		return tok.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static long nextLong() {
		return Long.parseLong(next());
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() {
		return new BigInteger(next());
	}
}