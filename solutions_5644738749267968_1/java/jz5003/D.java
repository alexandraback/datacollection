import java.util.*;
import java.io.*;
public class D {
	static int tc, n;
	static double naomi[],ken[];
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter(new File("D.out"));
		tc = i(in.nextLine());
		for(int i = 1; i <= tc; i++)
		{
			out.printf("Case #%d: ",i);
			n = i(in.nextLine());
			naomi = new double[n]; ken = new double[n];
			StringTokenizer st = new StringTokenizer(in.nextLine());
			for(int j = 0; j < n; j++)
				naomi[j]=d(st.nextToken());
			st = new StringTokenizer(in.nextLine());
			for(int j = 0; j < n; j++)
				ken[j]=d(st.nextToken());
			Arrays.sort(naomi); Arrays.sort(ken);
			//System.out.println(Arrays.toString(naomi));
			//System.out.println(Arrays.toString(ken));
			int war = n, dwar = 0 , bi = 0, bj = 0, ci = 0, cj = 0;
			//System.out.println();///
			for(; bi < n; bi++) //naomi playing player 1
			{
				while(bj < n && ken[bj]<naomi[bi]) {bj++;} //find what ken must play next
				if(bj>=n) break;//ken needs to play his minimum now
				else
				{
					war--; //naomi lost
				}
				bj++;	//destroy
			}
			for(; cj < n; cj++) //naomi playing player 2
			{
				while(ci < n && naomi[ci]<ken[cj]) {ci++;} //find where naomi must play next
				if(ci>=n) break;//naomi needs to play her minimum now
				else 
				{
					dwar++; //naomi won
				}
				ci++;
			}
			out.println(dwar+" "+war);
		}
		out.close();
		System.exit(0);
	}
	static int i(String s)
	{
		return Integer.parseInt(s);
	}
	static double  d(String s)
	{
		return Double.parseDouble(s);
	}
}
