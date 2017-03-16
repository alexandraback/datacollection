import java.io.* ;
import java.text.DecimalFormat;
import java.util.*;

import static java.lang.Math.* ;
import static java.util.Arrays.* ;

public class A {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		in = new Scanner(new InputStreamReader(new FileInputStream("a_in.txt")));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream("a_out.txt")));
		
		int n = in.nextInt() ; in.nextLine() ;
		int t = 1 ;
		while( n-- > 0)
			new A().solveProblem(t++);
		
		out.close();
	}

	static Scanner in = new Scanner(new InputStreamReader(System.in));
	static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
	

	//static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	
	public void solveProblem(int nr) {	
		out.print("Case #" + nr + ": " ) ;

		HashMap<String,String> map = new HashMap<String, String>() ;
		map.put("a", "y") ;
		map.put("b", "h") ;
		map.put("c", "e") ;
		map.put("d", "s") ;
		map.put("e", "o") ;
		map.put("f", "c") ;
		map.put("g", "v") ;
		map.put("h", "x") ;
		map.put("i", "d") ;
		map.put("j", "u") ;
		map.put("k", "i") ;
		map.put("l", "g") ;
		map.put("m", "l") ;
		map.put("n", "b") ;
		map.put("o", "k") ;
		map.put("p", "r") ;
		map.put("q", "z") ;
		map.put("r", "t") ;
		map.put("s", "n") ;
		map.put("t", "w") ;
		map.put("u", "j") ;
		map.put("v", "p") ;
		map.put("w", "f") ;
		map.put("x", "m") ;
		map.put("y", "a") ;
		map.put("z", "q") ;
		
		char[] s = in.nextLine().toCharArray() ;
		for( char c : s ){
			if( c == ' ')
				out.print(c) ;
			else
				out.print(map.get(""+c)) ;
		}
		out.println();
		System.err.println("Case #" + nr + " solved") ;
	}
	

}