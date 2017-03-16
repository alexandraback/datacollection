import java.io.*;
import java.util.*;

public class b {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tn = sc.nextInt();
		for(int tc = 1; tc <= tn; tc++){
			int e = sc.nextInt();
			int r = sc.nextInt();
			int n = sc.nextInt();
			int[] v = new int[n];
			for(int i = 0; i < n; i++){
				v[i] = sc.nextInt();;
			}
			//System.out.printf("run %d: %d\n",tc,e);
			long ans = getAns(e,r,n,v);
			System.out.printf("Case #%d: %d\n",tc,ans);
		}
	}

	private static long getAns(int e, int r, int n, int[] v) {
		long[] valAtE = new long[e+1];
		
		for(int i = 0; i < n; i++){ //item ==i
			//System.out.println(Arrays.toString(valAtE));
			
			long[] nextVal = new long[e+1];
			for(int j = 0; j <= e; j++){ //starting energy level ==j
				for(int k = 0; k <= j; k++){ //spend k energy ==k
					nextVal[j-k] = Math.max(valAtE[j] + v[i] * k, nextVal[j-k]);
				}
			}
			//System.out.println("\t\t" + Arrays.toString(nextVal));
			
			for(int j = 0; j < e - r + 1; j++) //energy level ==j
				valAtE[j + r] = nextVal[j];
			for(int j = 0; j < Math.min(r, e+1); j++) //energy level ==j
				valAtE[j] = nextVal[0];
		}
		//System.out.println(Arrays.toString(valAtE));
		
		long max = 0;
		for(int i = 0; i < valAtE.length; i++)
			max = Math.max(valAtE[i],max);
		return max;
	}

}
