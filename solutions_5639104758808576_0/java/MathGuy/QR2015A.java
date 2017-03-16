import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class QR2015A
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; ++t)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			int Smax = Integer.parseInt(st.nextToken());
			String s = st.nextToken();
			int clap = s.charAt(0)-'0', added = 0;
			for (int i = 1; i < s.length(); ++i)
			{
				if (i > clap) 
				{
					int need = i - clap;
					added += need;
					clap += need;
				}
				clap += s.charAt(i) - '0';
			}
			System.out.printf("Case #%d: %d\n",t+1,added);
		}
	}
}
