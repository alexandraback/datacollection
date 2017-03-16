import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Round1B14B {

	public static void main(String[] args) throws Exception {
		BufferedReader inRaw = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		int nCases = Integer.parseInt(inRaw.readLine());
		for(int z = 0; z < nCases; z++)
		{
			StringTokenizer in = new StringTokenizer(inRaw.readLine());
			int A = Integer.parseInt(in.nextToken()), B = Integer.parseInt(in.nextToken()), K = Integer.parseInt(in.nextToken());
			int count = 0;
			for(int i = 0; i < A; i++)
			{
				for(int j = 0; j < B; j++)
				{
					if((i & j) < K) count++;
				}
			}
			out.println("Case #" + (z + 1) + ": " + count);
		}
		inRaw.close();
		out.close();
	}
}
