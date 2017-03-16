import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class A {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new A();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			int [] s = new int[n];int x=0;
			for (int i = 0; i < s.length; i++) x+=(s[i]=nextInt());
			double [] res = new double[n];
			for (int i = 0; i < res.length; i++) {
				if(can(s,i,0.0,x))res[i]=0.0;
				else{
					double start=0.0;
					double end = 1.0;
					int itr = 0;
					while(itr++<50){
						double mid = (start+end)/2;
						if(can(s, i, mid, x))end=mid;
						else start=mid;
					}
					res[i]=end;
				}
			}
			
			write("Case #"+counter+":");
			for (int i = 0; i < res.length; i++) {
//				write(" "+res[i]);
				out.printf(" %.6f", res[i]*100);
			}
			writeln("");
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static boolean can(int[] s, int i, double d,int x) {
		// TODO Auto-generated method stub
		double check =0.00000000001 + s[i] + d*x;
		double left = 1.0-d;
		for (int j = 0; j < s.length; j++) {
			if(j==i)continue;
			double v = (check-s[j])/x;
			if(v<0.000000001)continue;
			left-=v;
			if(left<-0.000000001)return true;
		}
		return false;
	}

	public A() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(System.out);
//		-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter("A.txt");
		//-------------------------------------------------------------------------
		//Initalize Stringtokenizer input
		input = new StringTokenizer(in.readLine());
	}

	private static int nextInt() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Integer.parseInt(input.nextToken());
	}
	private static long nextLong() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Long.parseLong(input.nextToken());
	}
	private static double nextDouble() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Double.parseDouble(input.nextToken());
	}
	private static String nextString() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return input.nextToken();
	}
	private static void write(String output){
		out.write(output);
		out.flush();
	}
	private static void writeln(String output){
		out.write(output+"\n");
		out.flush();
	}
	private static void end() throws IOException{
		in.close();
		out.close();
		System.exit(0);
	}
	
}
