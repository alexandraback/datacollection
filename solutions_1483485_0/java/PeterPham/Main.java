import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "A-small-practice";

	public BufferedReader in;

	public PrintWriter out;

	static char[][] map = new char[2][26];
	
	void translationsMAP() throws IOException {
		boolean sorted = false;
		String origin     = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
		String translated = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
		char[] array = new char[origin.length()];
		char[] array1 = new char[origin.length()];
		
		for(int i = 0; i<origin.length()-1; i++)
		{
			array[i]= origin.charAt(i);
		}
		for(int i = 0; i<origin.length()-1; i++)
		{
			array1[i]= translated.charAt(i);
			
		}
		
		while(!sorted)
		{
			sorted = true;
			for(int i = 0; i<origin.length()-1; i++)
			{
				
				if((int) array[i] > (int) array[i+1])
				{
					char c = array[i];
					array[i] = array[i+1];
					array[i+1] = c;
					
					c = array1[i];
					array1[i] = array1[i+1];
					array1[i+1] = c;
					sorted = false;
					
					
				}
			}
		}
		
		int i= 0;
		int count = 0;
		while(i <26)
		{
			map[0][i] = (char)(i+97);
			while(true)
			{
				if (array[count] == map[0][i])
				{
					map[1][i] = array1[count];
					break;
				}else if(map[0][i] == 'z')
				{
					map[1][i] = 'q';
					count--;
					break;
 				}else if(map[0][i] == 'q')
 				{
 					
 					int sum = 0;
 					for (int j=0;j<26;j++)
 					{
 						sum += (97+j);
 					}
 		
 					
 					for (int j = 0; j<array1.length;j++)
 					{
 						if(j==0 || array1[j-1] != array1[j])
 						{
 							sum -= (int)array1[j];
  						}
 						
 					}
 					map[1][i] = (char) (sum-113);
 					count--;
 					break;
 					
 				}
				count++;
			}
			
			
			i++;
			
		}
		
		
	}
	
	void open() throws IOException {
		in = new BufferedReader( new FileReader( new File( FNAME + ".in" ) ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	void run() throws IOException {
		
		translationsMAP();
		String str = in.readLine();
		int num = new Integer( str );
		for(int i = 0; i<num ; i++){
			str = in.readLine();
			String result = "";
			for(int j = 0; j< str.length(); j++)
			{
				if(str.charAt(j) == ' ')
				{
					result+= " ";
				}else{
					
					result+= map[1][(int)str.charAt(j) -97];
				}
			}
			out.println( "Case #" + (i+1) + ": " + result );
		}
		
		
	}

	public static void main( String[] args ) throws IOException {
		new Thread() {

			public void run() {
				try {
					Main solution = new Main();
					solution.open();
					solution.run();
					solution.close();
				} catch ( Exception e ) {
					throw new RuntimeException( e );
				}
			}
		}.start();
	}
}