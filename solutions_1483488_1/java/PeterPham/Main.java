import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "A-small-practice";

	public BufferedReader in;

	public PrintWriter out;

	
	
	void open() throws IOException {
		in = new BufferedReader( new FileReader( new File( FNAME + ".in" ) ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	void run() throws IOException {
		
		
		String str = in.readLine();
		String[] input;
		int min,max,firstdigit, count;
		String newNum, converted;
		int num = new Integer( str );
		int[] array;
		for(int i = 0; i<num ; i++){
			
			input = in.readLine().split(" ");
			min = new Integer(input[0]);
			max = new Integer(input[1]);
			count=0;
			
			for(int j=min;j<=max; j++)
			{
				newNum=""+j;
				array = new int[input[0].length()-1];
				for(int k=1;k<newNum.length();k++)
				{
					boolean notsame = true;
					converted = newNum.substring(k) + newNum.substring(0,k);
					for(int h =0;h<k-1;h++)
					{
						if(new Integer(converted) == array[h] )
						{
							notsame = false;
						}
					}
					array[k-1] = new Integer(converted);
					if(new Integer(converted)>new Integer(newNum) && new Integer(converted)<=max && notsame)
					{
						count++;
					}
				}
			}
			
			out.println( "Case #" + (i+1) + ": "+ count );
			
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