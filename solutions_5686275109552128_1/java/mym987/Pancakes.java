import java.io.*;
import java.util.*;

public class Pancakes {
	public static void main(String args[]) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("B-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());

		int numCase = Integer.parseInt(st.nextToken());
		for (int i = 0; i < numCase; i++) {
			st = new StringTokenizer(f.readLine());
			int n = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(f.readLine());
			int[] mat = new int[n];
			int max = 0;
			for(int j=0;j<n;j++){
				mat[j] = Integer.parseInt(st.nextToken());
				max = mat[j]>max?mat[j]:max;
			}
			//System.out.println(max);
			int minTime = max;
			for(int j=max;j>0;j--){
				int cnt = j;
				for(int k=0;k<n;k++){
					if(mat[k]%j==0)cnt+=mat[k]/j-1;
					else cnt+=mat[k]/j;
				}
				minTime = cnt<minTime?cnt:minTime;
			}
			
			out.format("Case #%d: %d\n", i+1, minTime);
		}
		out.close();
		System.exit(0);
	}
}