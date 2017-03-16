import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Fractiles
{
	static long f(int pos, int K, int C)
	{
		if (C == 1) return pos;
		return K*(f(pos,K,C-1)-1)+pos;
	}
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; ++t)
		{
			StringTokenizer tok = new StringTokenizer(in.readLine());
			int K = Integer.parseInt(tok.nextToken());
			int C = Integer.parseInt(tok.nextToken());
			int S = Integer.parseInt(tok.nextToken());
			System.out.printf("Case #%d:", t+1);
			long val = 1;
			for (int s = 0; s < S; ++s)
			{
				System.out.printf(" %d",f(s+1,K,C));
			}
			System.out.println();
		}
	}
}
