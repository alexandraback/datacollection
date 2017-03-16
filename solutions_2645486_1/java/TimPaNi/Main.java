import java.io.*;
import java.util.*;


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader fin = new BufferedReader(new FileReader("a_in.in"));
		BufferedWriter fout = new BufferedWriter(new FileWriter("a_out.out"));

		long T = Long.parseLong(fin.readLine().trim());

		for (long t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(fin.readLine());
			long E = Long.parseLong(st.nextToken());
			long R = Long.parseLong(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			if(t == T)
				System.out.println();
			long V[] = new long[N];
			st = new StringTokenizer(fin.readLine());
			for(int i = 0; i < N; i++)
				V[i] = Long.parseLong(st.nextToken());

			long a[] = new long[N];
			for(int i = 0; i < N; i++){
				long count = 1;
				for(int j = i+1; j < N; j++){
					if( V[i] < V[j] ){
						a[i] = count;
						break;
					}
					count++;
				}
			}

			long current = E;
			long ans = 0;
			for(int i = 0; i < N; i++){
				//System.out.prlongln(current + " "+V[i]+" "+a[i]);
				if( a[i] == 0 ){
					ans += current * V[i];
					current = R;
				}
				else{
					long temp = (current + (a[i] * R)) - E;
					if( temp > E )
						temp = E;
					
					if( temp > 0 )
						ans += temp * V[i];
					else
						temp = 0;
					current = current-temp+R;
				}
			}




			fout.write("Case #" + t + ": " + ans + "\n");
		}


		// fout.write("Case #" + t + ": " + ansCount + "\n");
		fin.close();
		fout.close();
	}

}