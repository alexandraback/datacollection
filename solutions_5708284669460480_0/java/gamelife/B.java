
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;



public class B {

	private static int gcd(int a, int b) {
	    BigInteger b1 = BigInteger.valueOf(a);
	    BigInteger b2 = BigInteger.valueOf(b);
	    BigInteger gcd = b1.gcd(b2);
	    return gcd.intValue();
	}
	private static int getBit(int num, int i){
		return (num>>i) & 1 ;
	}


	public static void main(String[] args) {
		new B().run();
    }
	
	private void run() {
		PrintWriter writer =  null ;
		FileReader reader = null;
		try{
//			reader = new FileReader("input");
			reader = new FileReader("B-small-attempt0.in");
//			reader = new FileReader("B-large-practice.in");
			
			writer = new PrintWriter("small-out.txt", "UTF-8");
//			writer = new PrintWriter("large-out.txt", "UTF-8");
		}catch(Exception e){
			
		}

        Scanner input = new Scanner(reader);

        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
        	K = input.nextInt();
        	L = input.nextInt();
        	S = input.nextInt();
        	
        	input.nextLine();
        	Key = input.nextLine().toCharArray();
        	Len = input.nextLine().toCharArray();
//        	System.out.printf("%d %d %d\n" , K , L ,S) ;  
//        	System.out.println(  Key) ;
//        	System.out.println(  Len) ;
        	
        	double result = solve();
//        	System.out.println("Case #"+ (n+1) + ": " + result) ;  
        	System.out.printf("Case #%d: %.7f\n" , (n+1) , result) ;  
//        	writer.println("Case #"+ (n+1) + ": " + result) ;  
        	writer.printf("Case #%d: %.7f\n" , (n+1) , result) ;  

	
        }
        if(writer !=null){
        	writer.close();
        }
        if(reader !=null){
        	try{
        		reader.close();
        	}catch(Exception e){
        		System.out.println(e.toString()) ;
        	}
        }
        if(input !=null){
        	input.close();
        }
	}
	
	int K,L,S;
	char[] Key;
	char[] Len;
	
	int pow(int a, int b){
		if(b==1)
			return a ;
		
		return a*pow(a,b-1);
		
	}

	double solve(){
		int max = 0;
		int contains = 0 ;
		int all = pow(K, S) ;
		String[] strs = new String[all] ;
		
//		System.out.println( "all " + all) ;
		for(int i = 0 ; i<all ;i++){
			int now = i ;
			char[] str = new char[S] ;
			for(int j = 0 ; j < S;j++){
				str[S-j-1] = Key[now%K] ;
				now = now / K ;
			}
			
//			System.out.println( str) ;
			int contain = 0;
			String sstr = new String(str);
//			for(int l = 0 ; l <S ; l++){
//				 
//				 System.out.println( "sub " + sstr.substring(l) ) ;
//				if( sstr.substring(l).contains(new String(Len) ) ){
//					contain++;
//					l = sstr.substring(l).indexOf(new String(Len) ) + 1 ;
//				}
//			}
			int l = 0 ;
//			System.out.println( "index " + sstr.indexOf(new String(Len) , l )) ;
			while( l< S && sstr.indexOf(new String(Len) , l ) > -1){
//				System.out.println( "sub " + sstr.substring(l) ) ;
				contain++;
				l = sstr.indexOf(new String(Len) , l ) + 1 ;
			}
			max = Math.max(max, contain);
			contains += contain;
			
//			System.out.println( "max " + max + " contain " + contain) ;
		}
//		System.out.println( "max " + max + " contains " + contains) ;
		double give = (double)contains/all ;
		double ans = (double)max - give;

		return ans  ;
	}
}






