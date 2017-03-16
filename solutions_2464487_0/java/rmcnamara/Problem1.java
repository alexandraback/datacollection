import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Problem1 {

	public static void main(String[] args )
	{
		String inputPath = "C:\\Users\\Ryan\\EclipseProjects\\Google_Code_Jam_2013-Round1A\\tc\\A-small-attempt0.in";
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
		
		long T = in.nextInt();
		
		for ( long i = 0; i < T; i++ )
		{
			long r = in.nextLong();
			long t = in.nextLong();
			long ring;
			
			for ( ring = 0; ; ring++  ){
				long inner = r+( ring) * 2 ;
				long outer = r+( ring ) * 2 + 1;
				long needed = ( outer * outer - inner * inner ); 
				
				if ( needed <= t )
				{
					t -= needed;
				}
				else
				{
					break;
				}
				
					
			}
			System.out.println("Case #" + ( i + 1 ) + ": " + ring);
			
			
			
		}
		
		
	}

}

