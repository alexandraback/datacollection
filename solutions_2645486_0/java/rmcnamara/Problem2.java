import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class Problem2 {

	public static void main(String[] args )
	{
		String inputPath = "C:\\Users\\Ryan\\EclipseProjects\\Google_Code_Jam_2013-Round1A\\tc\\B-small-attempt0.in";
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
		
		for ( int i = 1; i <= T; i++ )
		{
			mem = new HashMap<Integer[], Integer>();
			
			int E = in.nextInt();
			int R = in.nextInt();
			
			int N = in.nextInt();
			
			ArrayList<Integer> V = new ArrayList<Integer>();
					
			for ( int  j = 0; j < N; j++ )
			{
				V.add(in.nextInt());			
			}
			
			
			int val = getGain(E, 0, V, R, E);
			
			
			System.out.println("Case #" + i + ": " + val);
				
		}		
		
	}
	
	public static HashMap<Integer[], Integer> mem;
	
	public static int getGain( int e, int n, ArrayList<Integer> V, int r, int E)
	{
		if ( n >= V.size() )
		{
			return 0;
		}
		
		
		
		Integer[] key = new Integer[2];
		key[0] = e;
		key[1] = n;
		
		if ( mem.containsKey(key) )
		{
			return mem.get(key);
		}
		
		int best = Integer.MIN_VALUE;
		
		for ( int spend = 0; spend <= e; spend++ )
		{			
			int thisOne = getGain(Math.min(e - spend + r, E), n+1, V, r, E ) + V.get(n)*spend;
			
			best = Math.max(thisOne, best);
			
		}
		
		mem.put(key, best);
		return best;
		
		
	}

}

