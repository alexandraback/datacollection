import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class CodeJamB 
{
	static boolean debug = false;
	
	public static void main(String[] args) throws FileNotFoundException
	{
		if(!debug)
		{
			System.setIn(new FileInputStream("B-large.in"));
			System.setOut(new PrintStream("B-large.out"));
		}
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		for(int caso = 1; caso <= t; caso++)
		{
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] vals = new int[n][m];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					vals[i][j] = sc.nextInt();
			int[] maxFila = new int[n];
			int[] maxColumna = new int[m];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
				{
					maxFila[i] = Math.max(maxFila[i], vals[i][j]);
					maxColumna[j] = Math.max(maxColumna[j], vals[i][j]);
				}
			boolean paila = false;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
				{
					int val = vals[i][j];
					if(val != maxFila[i] && val != maxColumna[j])
						paila = true;
				}
			System.out.println("Case #" + caso + ": " + (paila ? "NO" : "YES"));
		}

		sc.close();
		if(debug)
		{
			System.out.flush();
			System.out.close();
		}
	}

}
