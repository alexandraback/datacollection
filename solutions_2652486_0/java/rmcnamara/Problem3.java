import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;


public class Problem3 {

	public static void main(String[] args )
	{
		String inputPath = "C:\\Users\\Ryan\\EclipseProjects\\Google_Code_Jam_2013-Round1A\\tc\\C-small-1-attempt0.in";
		String outputPath = inputPath + "_results";
		
		try {
			System.setOut(new PrintStream( new File(outputPath)));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Scanner in = null;
		try {
			in = new Scanner(new File(inputPath));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		int T = in.nextInt();
		
		int R = in.nextInt(); // number of rounds
		int N = in.nextInt(); // number of cards
		int M = in.nextInt(); // value of card is between 2 and m
		int K = in.nextInt(); // the number of hands randomly picked
		
		System.out.println("Case #1:");
		
		for ( int i = 1; i <= R; i++ )
		{
			ArrayList<Integer> prods = new ArrayList<Integer>();
			for ( int k = 0; k < K; k++ )
			{
				prods.add(in.nextInt());
			}
			
			int x = 0;
			int y = 0;
			int z = 0;
	
	
out:		for (  x = 2; x <= M; x++ )
			{
				for (  y = 2; y <= M; y++ )
				{
					for (  z = 2; z <= M; z++ )
					{
						HashSet<Integer> possible = new HashSet<Integer>();
						
						for ( int sub = 0; sub < 8; sub++ )
						{	
							int mul = 1;
							int numUsed = 0;
							
							if ( ( sub & ( 1 << 0 )  ) != 0 )
							{
								mul *= x;
								numUsed++;
							}
							if ( ( sub & ( 1 << 1 )  ) != 0 )
							{
								mul *= y;
								numUsed++;
							}
							if ( ( sub & ( 1 << 2 )  ) != 0 )
							{
								mul *= z;
								numUsed++;
							}
							if ( numUsed <= K )
								possible.add(mul);
						}
						
						int k = 0;
						for (  k = 0; k< K;k ++ )
						{
							if ( !possible.contains(prods.get(k)))
							{
								break;
							}
						}
						
						if ( k == K)
						{
							break out;
						}
						
						
					}
				}
			}
			
			
			
			
			System.out.println("" + x + "" + y + "" + z);
			
			
			
		}
		
		
	}
}
