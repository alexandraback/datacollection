import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;

public class CoinJam
{
	static int getFactor(BigInteger v)
	{
		int b = v.min(BigInteger.valueOf(100001)).intValue()-1;
		for (int d = 2; d <= b; ++d)
		{
			if (v.mod(BigInteger.valueOf(d)).equals(BigInteger.ZERO)) return d;
		}
		return -1;
	}
	public static void main(String[] args) throws Exception
	{
		Random ran = new Random(1);
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; ++t)
		{
			StringTokenizer tok = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(tok.nextToken());
			int J = Integer.parseInt(tok.nextToken());
			HashMap<String,ArrayList<Integer>> map = new HashMap<>();
			while (map.size() < J)
			{
				int r = ran.nextInt(1<<(N-2));
				long v = (1L<<(N-1)) + (r<<1) + 1;
				String s = Long.toBinaryString(v);
				ArrayList<Integer> list = new ArrayList<>();
				boolean bad = false;
				for (int b = 2; b <= 10 && !bad; ++b)
				{
					int div = getFactor(new BigInteger(s,b));
					if (div > 1) list.add(div);
					else bad = true;
				}
				if (!bad) map.put(s, list);
			}
			System.out.println("Case #1:");
			for (String s : map.keySet())
			{
				System.out.print(s);
				ArrayList<Integer> list = map.get(s);
				for (int i = 0; i < list.size(); ++i) System.out.printf(" %d",list.get(i));
				System.out.println();
			}
		}
	}
}
