import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;


/**
 * 
 * @author JuanFelipe
 *
 */
public class C_FairAndSquare {

	public static void main(String[] args) throws Exception {
		File _ = new File("C-small.in");
		Scanner in = new Scanner( _.exists()?(new FileInputStream(_)):System.in );
		//PrintWriter pr=new PrintWriter( new File("solution.out") );
		PrintWriter pr=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int res, A, B;
		int valid[] = {1, 4, 9, 121, 484};
		/*int fas[] = new int[1100];
		fas[ 0 ] = 0;
		for( int i=1; i<=32; i++ ){
			if( isPalindrome(i) && isPalindrome(i*i) ){
				fas[ i*i ] +=1;
				System.out.println(i*i);
			}
			
			fas[i] += fas[ i-1 ];
			
		}
		
		for( int i = 33 ; i<=1000; i++){
			fas[i] += fas[ i-1 ];
		}*/
		
		for(int k=0, T = in.nextInt(); k < T; k++){
			res = 0;
			A = in.nextInt( );
			B = in.nextInt( );
			
			for(int i=0; i<5; i++){
				if( A<=valid[i] && B>=valid[i] ){
					res++;
				}
			}
			
			pr.println("Case #"+(k+1)+": "+res);
		}
		
		pr.close();
		in.close();
	}

	private static boolean isPalindrome(int i) {
		String sr = i+"";
		StringBuffer s = new StringBuffer( sr );
		//System.out.println( sr + " " + s.reverse() + " " + s.reverse().toString().equals(sr) );
		return s.reverse().toString().equals(sr);
	}

}
