import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class DancingWiththeGooglers {

	public static void main ( String [] arg ) throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader(new File("input")));
		PrintWriter output = new PrintWriter(new File("output"));
		int cases = Integer.valueOf( reader.readLine() ); 
		for ( int i=1; i<=cases; i++ ){
			StringTokenizer tkn = new StringTokenizer( reader.readLine() ); 
			int N = Integer.valueOf( tkn.nextToken() ); 
			int S = Integer.valueOf( tkn.nextToken() ); 
			int p = Integer.valueOf( tkn.nextToken() ); 
			int sol=0; 
			for ( int j=0; j<N; j++){
				int points = Integer.valueOf( tkn.nextToken() ); 
				if ( ok(points,p,3) ){
					sol++;
				} else {
					if ( S>0 && ok(points,p,4) ){
						sol++;
						S--;
					}
				}
			}
			output.println("Case #"+i+": " + sol ); 
		}
		output.close(); 
	}
	
	public static boolean ok( int suma, int p, int sum_delta ){
		for ( int i=0; i<=10; i++ ){
			for ( int j=0; j<=10; j++ ){
				for ( int k=0; k<=10; k++ ){
					if ( i+j+k == suma ){
						int unu =  Math.abs(i-j);
						int doi =  Math.abs(i-k);
						int trei = Math.abs(j-k);
						if ( unu+doi+trei<=sum_delta ){
							if ( Math.max( Math.max(i, j), k )>=p){
								return true; 
							}
						}
					}
				}
			}
		}
		return false; 
	}
	
}
