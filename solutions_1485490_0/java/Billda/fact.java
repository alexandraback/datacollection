import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class fact {
	static long [] toysCnt;
	static int [] toyType ;
	static long []  boxesCnt ;
	static int [] boxType;
	static long max;
	
	private static void solve(int i, int j, long sum)
	{
		if(sum > max) max = sum;
		if(i == toysCnt.length || j == boxesCnt.length) return;
		if(boxType [j] == toyType[i])
		{
			long res = Math.min(toysCnt[i],boxesCnt[j]);
			
				toysCnt[i] -= res;
				boxesCnt[j] -= res;
				solve(i, j+1, sum+res);
				solve(i+1, j, sum+res);
				solve(i+1, j+1,  sum+res);
				toysCnt[i] += res;
				boxesCnt[j] += res;
		}
		else
		{
			solve(i+1, j, sum);
			solve(i, j+1, sum);
			solve(i+1, j+1, sum);
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("input"));
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		
		for(int x = 1; x <= t;x++)
		{
			max = 0;
			int n = s.nextInt();
			int m = s.nextInt();
			toysCnt = new long[n];
			toyType = new int[n];
			boxesCnt = new long[m];
			boxType = new int[m];
			for(int i = 0; i < n; i++)
			{
				toysCnt[i] = s.nextLong();
				toyType[i] = s.nextInt();
			}
			for(int i = 0; i < m; i++)
			{
				boxesCnt[i] = s.nextLong();
				boxType[i] = s.nextInt();
			}
			solve(0,0, 0);
			System.out.println("Case #" + x + ": " + max);
		}
	}
}
