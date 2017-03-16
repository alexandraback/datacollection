import java.io.*;

public class Main{
	
	
	private static long solve(int e, int r, int [] v){
		int n = v.length;
		
		int [] nextLargerIndex = new int[n];
		for (int i = 0; i < n; i++){
			int cur = v[i];
			int j = i+1;
			while ((j < n) && (v[j] <= cur))
				j++;
			nextLargerIndex[i] = (j == n) ? -1 : j;
		}
		
		long gain = 0;
		long curE = e;
		for (int i = 0; i < n; i++){
			if (nextLargerIndex[i] == -1){
				gain += curE*v[i];
				curE = 0;
			}
			else{
				long after = Math.max(0, e - r*(nextLargerIndex[i] - i));
				long spend = Math.max(curE-after, 0);
				gain += spend*v[i];
				curE -= spend;
			}
			
			curE = Math.min(e, curE + r);
		}
		
		return gain;
	}
	
	
	
	public static void main(String [] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tests = Integer.parseInt(in.readLine());
		
		for (int i = 0; i < tests; i++){
			String [] line = in.readLine().split(" ");
			int e = Integer.parseInt(line[0]);
			int r = Integer.parseInt(line[1]);
			int n = Integer.parseInt(line[2]);
			
			int [] v = new int[n];
			String values = in.readLine();
			int startIndex = 0;
			for (int j = 0; j < n; j++){
				int nextIndex = values.indexOf(' ', startIndex);
				if (nextIndex == -1)
					nextIndex = values.length();
				v[j] = Integer.parseInt(values.substring(startIndex, nextIndex));
				startIndex = nextIndex+1;
			}
			
			System.out.println("Case #" + (i+1) + ": " + solve(e, r, v));
		}
	}

}