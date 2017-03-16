import java.util.*;
public class b {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int n = input.nextInt(), m = input.nextInt();
		int[] maxr = new int[n], maxc = new int[m];
		int[][] data = new int[n][m];
		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++)
			{
				data[i][j] = input.nextInt();
				maxr[i] = Math.max(maxr[i], data[i][j]);
				maxc[j] = Math.max(maxc[j], data[i][j]);
			}
		boolean good = true;
		for(int i =0; i<n; i++)
			for(int j = 0; j<m; j++)
				good &= data[i][j] == Math.min(maxr[i], maxc[j]);
		System.out.println("Case #"+(t+1)+": " + (good ? "YES" :"NO"));
	}
}
}
