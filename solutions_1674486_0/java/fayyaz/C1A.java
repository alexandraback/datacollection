import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;



public class C1A {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new C1A();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			boolean [][] graph = new boolean[n][n];
			int a [] = new int[n];
			for (int i = 0; i < graph.length; i++) {
				a[i] = nextInt();
				for (int j = 0; j < a[i]; j++) {
					graph[i][nextInt()-1]=true;
				}
			}
			
			boolean can = false;
			
			for (int k = 0; k < a.length; k++) {
				if(a[k]==0){
					Queue<Integer> w = new LinkedList<Integer>();
					boolean [] vis = new boolean[n];
					w.add(k);
					vis[k]=true;
					while(!w.isEmpty()){
						int node = w.poll();
						for (int i = 0; i < graph.length; i++) {
							if(graph[i][node]){
								if(vis[i]){
									can=true;
									break;
								}else{
									w.add(i);
									vis[i]=true;
								}
							}
						}
						if(can)break;
					}
				}
			}
			if(can)
			writeln("Case #"+counter+": Yes");
			else writeln("Case #"+counter+": No");
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	public C1A() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("C1A.in"));
		out = new PrintWriter("C1A.txt");
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
