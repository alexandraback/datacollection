import java.util.*;
import java.io.*;

public class A{
	
	public static void main(String[] args) throws IOException{
		Scanner inp = new Scanner(new File("A-small-attempt7.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small7.out"));
		
		
		
		
		
		int numCases = inp.nextInt();
		
		for (int cas = 0; cas < numCases; cas++){
			pw.print("Case #" + (cas+1) + ":");
			
			/* case input */
			int N = inp.nextInt();
			int[] s = new int[N];
			int[] scopy = new int[N];
			long sum = 0;
			for (int i = 0; i < N; i++){
				s[i] = inp.nextInt();
				scopy[i] = s[i];
				sum += s[i];
			}
			
			// det Y
			//int[] scopy = s.clone();
			Arrays.sort(scopy);
			int competitors = N;
			double diff = 0;
			int count = 0;
			for (int i = 1; i < N; i++){
				diff += i*(scopy[i]- scopy[i-1]);
				if (diff > sum){
					competitors = i;
					break;
				}
			}
			
			int compBound = 0;
			if (competitors == N){
				compBound = scopy[N-1]+1;
			}
			else{
				
				compBound = scopy[competitors];
			}
			
			double[] m = new double[N];
			
			int ncomp = 0;
			int scomp = 0;
			
			
			for (int i = 0; i < N; i++){
				if (s[i] < compBound){
					ncomp++;
					scomp += s[i];
				}
			}
			for (int i = 0; i < N; i++){
				if (s[i] < compBound){
					m[i] = (double)100*((double)scomp/((double)sum*(double)ncomp) + ((double)1/(double)ncomp) - (double)s[i]/(double)sum); 
				}
				else{
					m[i] = 0;
				}
			}
			
			
			for (int i = 0; i < N; i++){
				pw.format(" %.6f", m[i]);
			}
			pw.println();
		}
		pw.close();
	}
}
