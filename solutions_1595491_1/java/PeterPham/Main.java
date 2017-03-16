import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "A-small-practice";

	public BufferedReader in;

	public PrintWriter out;

	static char[][] map = new char[2][26];
	
	
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
		int n,s,p, noSmin, Smin,count;
		int num = new Integer( str );
		for(int i = 0; i<num ; i++){
			
			input = in.readLine().split(" ");
			
			n= new Integer(input[0]);
			s= new Integer(input[1]);
			p= new Integer(input[2]);
			
			count = 0;
			if(p>=2){
				Smin= p+2*(p-1);
				noSmin= p+2*(p-2);
				
			}else if(p==1){
				Smin=p+2*(p-1);
				noSmin=p+2*(p-1);
			}else{
				Smin=0;
				noSmin=0;
			}
			
			
			for(int j = 3; j<3+n;j++)
			{
				int no = new Integer(input[j]);
				if (no >= noSmin)
				{
					
					if (no >= Smin)
					{
						count++;
					}
					
					if(no < Smin && s>0)
					{
						
						count++;
						s--;
					}
				}
				
			}
			
			out.println( "Case #" + (i+1) + ": " + count );
			
			
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