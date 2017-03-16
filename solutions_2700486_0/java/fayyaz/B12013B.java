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



public class B12013B {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new B12013B();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			int x = nextInt();
			int y = nextInt();
			
			int manhatten = Math.abs(x)+Math.abs(y);
			double p = 0.0;
			if(manhatten==0){
				p=1.0;
			}else if(manhatten==2){
				if(n<=1){//cant do this level
					p=0.0;
				}else if(n>=6){//full level
					p=1.0;
				}else{
					int place = x+2;
					can = 0;
					cant = 0;
					mid = 2;
					prop(0, 4, place, n-1);
					p = 1.0*can/(can+cant);
				}
			}else if(manhatten==4){
				if(n<=6){//cant do this level
					p=0.0;
				}else if(n>=15){//full level
					p=1.0;
				}else{
					int place = x+4;
					can = 0;
					cant = 0;
					mid = 4;
					prop(0, 8, place, n-6);
					p = 1.0*can/(can+cant);
				}
			}else if(manhatten==6){
				if(n<=15){//cant do this level
					p=0.0;
				}else{
					int place = x+6;
					can = 0;
					cant = 0;
					mid = 6;
					prop(0, 12, place, n-15);
					p = 1.0*can/(can+cant);
				}
			}else{
				p=0.0;
			}
			
			writeln("Case #"+counter+": "+(p+1e-7));
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	static int can;
	static int cant;
	static int mid;
	public static void prop(int left,int right,int place,int d){
		if(d==0){//no more
			if(place<left || place > right)can++;
			else cant++;
			return;
		}
		if(left==right)
			prop(left+1,right-1,place,d-1);
		else if(left==mid)
			prop(left, right-1, place, d-1);
		else if(right==mid)
			prop(left+1, right, place, d-1);
		else{
			prop(left+1, right, place, d-1);
			prop(left, right-1, place, d-1);
		}
		
	}
	
	
	public B12013B() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("b12013b.in");
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
