import java.io.* ;
import java.text.DecimalFormat;
import java.util.*;
import static java.lang.Math.* ;
import static java.util.Arrays.* ;

public class C {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		in = new Scanner(new InputStreamReader(new FileInputStream("c_in.txt")));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream("c_out.txt")));
		
		int n = in.nextInt() ; in.nextLine() ;
		int t = 1 ;
		while( n-- > 0)
			new C().solveProblem(t++);
		
		out.close();
	}

	static Scanner in = new Scanner(new InputStreamReader(System.in));
	static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
	

	//static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	
	public void solveProblem(int nr) {	
		out.print("Case #" + nr + ": " ) ;

		int A = in.nextInt() ;
		int B = in.nextInt() ;
		
		int l = ( A + "").length() ;
		
		int som = 0 ;
		for( int i = A ; i <= B ; i++ ){
			
			HashSet<Integer> set = new HashSet<Integer>() ;
			for( int j = 1 ; j < l ; j++ ){
				int n = i ;
				n /= (int) pow(10,j) ;
				n += (i % pow(10,j) )*(int) pow(10,l-j) ; 
				//System.out.println(n + " " + i);
				if( n > i && n <= B )
					set.add(n) ;
			}
			
			som += set.size();
		}
		
		out.println(som) ;
		
		System.err.println("Case #" + nr + " solved") ;
	}
	

}