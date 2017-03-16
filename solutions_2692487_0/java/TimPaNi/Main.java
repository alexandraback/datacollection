import java.io.*;
import java.util.*;


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader fin = new BufferedReader(new FileReader("a_in.in"));
		BufferedWriter fout = new BufferedWriter(new FileWriter("a_out.out"));

		int T = Integer.parseInt(fin.readLine().trim());

		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(fin.readLine());

			long A = Long.parseLong(st.nextToken());
			int N = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(fin.readLine());
			long mote[] = new long[N];
			for(int i = 0; i < N; i++)
				mote[i] = Long.parseLong(st.nextToken());

			Arrays.sort(mote);
/*
			long count = 0;
			for(int i = 0; i < N; i++){
				if( A == 1 ){
					count = N-i;
					break;
				}

				if( A > mote[i] ){	//정상경우
					A += mote[i];
				}				
				else{
					long tA = A;
					int tc = 0;
					while( tA <= mote[i] ){
						tA += tA-1;
						tc++;
					}

					if( tc > N - i ){
						count += N - i;
						break;
					}
					else{
						A = tA;
						count += tc;
					}
				}

			}
*/
			fout.write("Case #" + t + ": " + cal(A, 0, 0, N, mote) + "\n");
		}


		// fout.write("Case #" + t + ": " + ansCount + "\n");
		fin.close();
		fout.close();
	}
	
	public static long cal(long A, long count, int i, int N, long mote[]){
		if( A == 1 )
			return N-i;
		
		if( i >= N )
			return count;
		
		long ans = Long.MAX_VALUE;
		if( A > mote[i] )
			ans = cal(A+mote[i], count, i+1, N, mote);
		else{
			long tA = A;
			int tc = 0;
			while( tA <= mote[i] ){
				tA += tA-1;
				tc++;
			}
			
			tA += mote[i];
															
			ans = Math.min(cal(tA, count+tc, i+1, N, mote), count + N-i);
		}
			
		
		
		return ans;
	}

}