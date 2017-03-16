import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


/**
 * 
 * @author JuanFelipe
 *
 */
public class C_FairAndSquare {

	public static void main(String[] args) throws Exception {
		File _ = new File("C-large.in");
		Scanner in = new Scanner( _.exists()?(new FileInputStream(_)):System.in );
		PrintWriter pr=new PrintWriter( new File("solution.out") );
		//PrintWriter pr=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int res;
		long A, B;
		ArrayList<Long>valid = new ArrayList<Long>();
		
		for( long i=1; i<=10000000; i++ ){
			if( isPalindrome(i) && isPalindrome(i*i) ){
				valid.add(i*i);
			}
		}
		
		for(int k=0, T = in.nextInt(); k < T; k++){
			res = 0;
			A = in.nextLong( );
			B = in.nextLong( );
			
			for( Long val : valid){
				if( A<=val && B>=val ){
					res++;
				}
			}
			
			pr.println("Case #"+(k+1)+": "+res);
		}
		
		pr.close();
		//in.close();
	}

	private static boolean isPalindrome(long i) {
		String sr = i+"";
		StringBuffer s = new StringBuffer( sr );
		//System.out.println( sr + " " + s.reverse() + " " + s.reverse().toString().equals(sr) );
		return s.reverse().toString().equals(sr);
	}

}
