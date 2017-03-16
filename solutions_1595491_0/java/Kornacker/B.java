import java.io.* ;
import java.text.DecimalFormat;
import java.util.*;
import static java.lang.Math.* ;
import static java.util.Arrays.* ;

public class B {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		in = new Scanner(new InputStreamReader(new FileInputStream("b_in.txt")));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream("b_out.txt")));
		
		int n = in.nextInt() ; in.nextLine() ;
		int t = 1 ;
		while( n-- > 0)
			new B().solveProblem(t++);
		
		out.close();
	}

	static Scanner in = new Scanner(new InputStreamReader(System.in));
	static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
	

	//static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	
	public void solveProblem(int nr) {	
		out.print("Case #" + nr + ": " ) ;

		int N = in.nextInt() ;
		int S = in.nextInt() ;
		int p = in.nextInt() ;
		
		int[] v = new int[N] ;
		for( int i = 0 ; i < N ; i++ )
			v[i] = in.nextInt() ;
		
		int[] min_ns = new int[31] ;
		int[] min_s = new int[31] ;
		fill( min_s, -1 );
		
		for( int i = 0 ; i <= 10 ; i++ )
			for( int j = i ; j <= i + 2 && j <= 10 ; j++ )
				for( int k = j ; k <= i + 2  && k <= 10 ; k++ ){
					min_s[i+j+k]  = max(min_s[i+j+k],k ) ;
				}
		for( int i = 0 ; i <= 10 ; i++ )
			for( int j = i ; j <= i + 1 && j <= 10 ; j++ )
				for( int k = j ; k <= i + 1  && k <= 10 ; k++ ){
					min_ns[i+j+k]  = max(min_ns[i+j+k],k ) ;
				}
		int t1 = 0 ;
		int t2 = 0 ;
		
		for( int a : v ){
			
			if( min_ns[a] >= p )
				t1++ ;
			else if( min_s[a]  >= p )
				t2++ ;
			
		}
		
		out.println(t1+min(t2,S)) ;
		System.err.println("Case #" + nr + " solved") ;
	}
	

}