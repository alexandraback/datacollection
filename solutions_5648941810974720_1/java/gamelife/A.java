
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;



public class A {

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
		new A().run();
    }
	
	private void run() {
		PrintWriter writer =  null ;
		FileReader reader = null;
		try{
//			reader = new FileReader("input.txt");
//			reader = new FileReader("A-small-attempt0.in");
			reader = new FileReader("A-large.in");
			
//			writer = new PrintWriter("small-out.txt", "UTF-8");
			writer = new PrintWriter("large-out.txt", "UTF-8");
		}catch(Exception e){
			System.out.println(" Exception " + e) ;  
			return;
		}

        Scanner input = new Scanner(reader);

        int numCases = input.nextInt();
        input.nextLine() ;
        for (int n = 0; n < numCases; n++)
        {
        	str = input.nextLine();
        	String result = solve();
        	System.out.println("Case #"+ (n+1) + ": " + result) ;  
        	writer.println("Case #"+ (n+1) + ": " + result) ;  

	
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
	
	String str ;
	

	static final double MAX = 1e15;
	String solve(){
		int[] ch = new int[27];
		int[] num  = new int[10];
		
		for(int i = 0 ; i < 26 ; i++){
			ch[i] =  0 ;
		}
		
		for(int i = 0 ; i < str.length() ; i++){
			char c = str.charAt(i)  ;
			ch[str.charAt(i) - 'A'] ++ ;
		}
		for(int i = 0 ; i < 26 ; i++){
			System.out.print(" " + ch[i]) ;  
		}
		System.out.println();
		
		//  0 
		if(ch['Z'-'A'] != 0) {
			num[0] = ch['Z'-'A'] ;
			ch['Z'-'A'] -= num[0] ;
			ch['E'-'A'] -= num[0] ;
			ch['R'-'A'] -= num[0] ;
			ch['O'-'A'] -= num[0] ;
		}
	
		//  2 
		if(ch['W'-'A'] != 0) {
			num[2] = ch['W'-'A'] ;
			ch['T'-'A'] -= num[2] ;
			ch['W'-'A'] -= num[2] ;
			ch['O'-'A'] -= num[2] ;
		}
		
		//  4
		if(ch['U'-'A'] != 0) {
			num[4] = ch['U'-'A'] ;
			ch['F'-'A'] -= num[4] ;
			ch['O'-'A'] -= num[4] ;
			ch['U'-'A'] -= num[4] ;
			ch['R'-'A'] -= num[4] ;
		}
		
		//  6 
		if(ch['X'-'A'] != 0) {
			num[6] = ch['X'-'A'] ;
			ch['S'-'A'] -= num[6] ;
			ch['I'-'A'] -= num[6] ;
			ch['X'-'A'] -= num[6] ;
		}
		
		//  8
		if(ch['G'-'A'] != 0) {
			num[8] = ch['G'-'A'] ;
			ch['E'-'A'] -= num[8] ;
			ch['I'-'A'] -= num[8] ;
			ch['G'-'A'] -= num[8] ;
			ch['H'-'A'] -= num[8] ;
			ch['T'-'A'] -= num[8] ;
		}
		
		//  3 
		if(ch['H'-'A'] != 0) {
			num[3] = ch['H'-'A'] ;
			ch['T'-'A'] -= num[3] ;
			ch['H'-'A'] -= num[3] ;
			ch['R'-'A'] -= num[3] ;
			ch['E'-'A'] -= num[3] ;
			ch['E'-'A'] -= num[3] ;
		}
		//  5 
		if(ch['F'-'A'] != 0) {
			num[5] = ch['F'-'A'] ;
			ch['F'-'A'] -= num[5] ;
			ch['I'-'A'] -= num[5] ;
			ch['V'-'A'] -= num[5] ;
			ch['E'-'A'] -= num[5] ;
		}
		//  7 
		if(ch['S'-'A'] != 0) {
			num[7] = ch['S'-'A'] ;
			ch['S'-'A'] -= num[7] ;
			ch['E'-'A'] -= num[7] ;
			ch['V'-'A'] -= num[7] ;
			ch['E'-'A'] -= num[7] ;
			ch['N'-'A'] -= num[7] ;
		}
		//  9 
		if(ch['I'-'A'] != 0) {
			num[9] = ch['I'-'A'] ;
			ch['N'-'A'] -= num[9] ;
			ch['I'-'A'] -= num[9] ;
			ch['N'-'A'] -= num[9] ;
			ch['E'-'A'] -= num[9] ;
		}
		//  1 
		if(ch['O'-'A'] != 0) {
			num[1] = ch['O'-'A'] ;
			ch['O'-'A'] -= num[1] ;
			ch['N'-'A'] -= num[1] ;
			ch['E'-'A'] -= num[1] ;
		}
		
		
		for(int i = 0 ; i < 26 ; i++){
			System.out.print(" " + ch[i]) ;  
		}
		System.out.println();
		
		
		String result = "" ; 
		for(int i = 0 ; i < 10 ; i++){
			for(int j = 0 ; j < num[i] ; j++){
				result += i ;
			}
		}
		

		return result ;
	}
	
	int digit(char c){
		return c-'A' ;
	}
	
}






