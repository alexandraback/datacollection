import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;


public class MainC {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/alexander/Downloads/C-small-attempt1.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PrintStream writer = new PrintStream("a.txt");
		//PrintStream writer = System.out;
		int N = Integer.parseInt(reader.readLine());
		for (int i =0; i<N; i++)
		{
			reader.readLine();
			ArrayList<Long> a = new ArrayList<Long>();
			ArrayList<Long> A = new ArrayList<Long>();
			ArrayList<Long> b = new ArrayList<Long>();
			ArrayList<Long> B = new ArrayList<Long>();
			
			String[] boxes = reader.readLine().split(" ");
			for (int j =0; j<boxes.length; j+=2)
			{
				a.add(Long.parseLong(boxes[j]));
				A.add(Long.parseLong(boxes[j+1]));
			}
			
			String[] toys = reader.readLine().split(" ");
			for (int j =0; j<toys.length; j+=2)
			{
				b.add(Long.parseLong(toys[j]));
				B.add(Long.parseLong(toys[j+1]));
			}
			
			int ai = 0;
			int bi = 0;
			long res = 0;
			long profit;
			while (ai<a.size() && bi<b.size())
			{
				if (A.get(ai) == B.get(bi))
				{
					profit = Math.min(a.get(ai), b.get(bi));
					a.set(ai, a.get(ai) - profit);
					b.set(bi, b.get(bi) - profit);
					if (a.get(ai) == 0)
						ai++;
					if (b.get(bi) == 0)
						bi++;
					res+=profit;
				}
				else
				{
					long dropa = 0;
					long profita = 0;
					int tai = ai;
					while (tai < a.size() && A.get(tai)!=B.get(bi))
					{
						dropa += a.get(tai);
						tai++;
					}
					if (tai <a.size())
						profita = Math.min(a.get(tai), b.get(bi));
					
					
					long dropb = 0;
					long profitb = 0;
					int tbi = bi;
					while (tbi < b.size() && B.get(tbi)!=A.get(ai))
					{
						dropb += b.get(tbi);
						tbi++;
					}
					if (tbi<b.size())
						profitb = Math.min(b.get(tbi), a.get(ai));
					
					if (profita -dropa > profitb-dropb)
						ai = tai;
					else
						bi = tbi;
				}
			}
			writer.println("Case #"+(i+1)+": "+res);
		}
		writer.flush();
		writer.close();
	}

}
