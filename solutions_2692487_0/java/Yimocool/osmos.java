import java.io.*;
import java.util.*;
import java.text.*;

class osmos{
	public static void main (String [] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("osmos.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("osmos.out")));
		int numCases = Integer.parseInt(f.readLine());
		
		for(int time=1; time<=numCases; time++){
			StringTokenizer st=new StringTokenizer(f.readLine());
			int A =Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			st=new StringTokenizer(f.readLine());
			int[] M=new int[N];
			for(int i=0; i<N; i++)
				M[i]=Integer.parseInt(st.nextToken());
			Arrays.sort(M);
			int minMoves=N;
			if (A==1){
				out.println("Case #"+time+": "+N);
				continue;
			}
			for(int i=0; i<N; i++){
				int curA=A;
				int moves=i;
				int at=0;
				while(at<N-i){
					while (curA<=M[at]){
						curA+=curA-1;
						moves++;
					}
					curA+=M[at];
					at++;
				}
				minMoves=Math.min(moves, minMoves);
			}
			out.println("Case #"+time+": "+minMoves);
		}
                   
		out.close();                                  
		System.exit(0);                               
	}
}