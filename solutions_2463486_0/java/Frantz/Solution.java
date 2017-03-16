import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {
	long[][] cases ;
	int T ;

	public Solution() {
		Scanner sc = null;
		try {
			sc = new Scanner(new FileReader("C-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		T = Integer.parseInt(sc.nextLine()) ;
		cases = new long[T][2] ;
		String[] line ;
		for(int i = 0 ; i < T ; i ++) {
			line = sc.nextLine().split(" ") ;
			cases[i][0] = Integer.parseInt(line[0]) ;
			cases[i][1] = Integer.parseInt(line[1]) ;
		}		
		sc.close() ;
	}
	
	public static void main(String[] args) throws IOException {
		Solution s = new Solution() ;
		PrintWriter out = new PrintWriter(new FileWriter("result.txt")) ;
		for(int i = 0 ; i < s.T ; i ++) {
			out.println("Case #"+(i+1)+": "+s.getResult(i)) ;
		}
		out.flush();
		out.close() ;
	}
	
	private int getResult(int i) {
		int count = 0 ;
		long start = (long) Math.ceil(Math.sqrt(cases[i][0])) ;
		long end = (long) Math.floor(Math.sqrt(cases[i][1])) ;
		for(long j = start ; j <= end ; j ++) {
			if(isPal(j) && isPal((long) Math.pow(j, 2))) {
				count ++ ;
			}
		}
		return count;		
	}
	
	private boolean isPal(long l) {
		return isPal(Long.toString(l),0) ;
	}
	
	private boolean isPal(String s, int start){
		if(start >= (s.length()/2 + 1)) {
			return true ;
		}
		if(s.charAt(start) == s.charAt(s.length() - 1 - start)) {
			return(isPal(s,start +1)) ;
		}
		return false ;
	}
}
