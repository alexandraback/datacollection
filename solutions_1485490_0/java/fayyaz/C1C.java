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



public class C1C {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new C1C();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			n = nextInt();
			m = nextInt();
			sn = new long[n];
			tn = new long[n];
			sm = new long[m];
			tm = new long[m];
			for (int i = 0; i < sn.length; i++) {
				sn[i]=nextLong();tn[i]=nextLong();
			}
			for (int i = 0; i < tm.length; i++) {
				sm[i]=nextLong();tm[i]=nextLong();
			}
			
			
			writeln("Case #"+counter+": "+BT(0, -1, 0, -1));
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	static int n;
	static int m;
	static long [] sn ;
	static long [] tn ;
	static long [] sm ;
	static long [] tm ;
	
	public static long BT(int in ,long ln , int im , long lm){
		if(in==n)return 0;
		if(im==m)return 0;
		if(lm==-1)lm=sm[im];
		if(ln==-1)ln=sn[in];
		if(ln==0)return BT(in+1, -1, im, lm);
		if(lm==0)return BT(in, ln, im+1, -1);
		if(tn[in]==tm[im]){
			if(ln<lm){
				return ln+BT(in+1, -1, im, lm-ln);
			}else{
				return lm+BT(in, ln-lm, im+1, -1);
			}
		}
		return Math.max(BT(in+1, -1, im, lm), BT(in, ln, im+1, -1));
	}
	
	public C1C() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("C1C.in"));
		out = new PrintWriter("C1C.txt");
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
