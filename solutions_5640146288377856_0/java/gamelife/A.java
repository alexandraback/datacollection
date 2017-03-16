
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;



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
//			reader = new FileReader("input");
			reader = new FileReader("A-small-attempt0.in");
//			reader = new FileReader("B-large-practice.in");
			
			writer = new PrintWriter("small-out.txt", "UTF-8");
//			writer = new PrintWriter("large-out.txt", "UTF-8");
		}catch(Exception e){
			
		}

        Scanner input = new Scanner(reader);

        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
        	R = input.nextInt();
        	C = input.nextInt();
        	W = input.nextInt();
        	
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
	

	int R,C,W;
	String solve(){

		return String.valueOf(F(C)) ;
	}
	
	int F(int n){
		if(n == W){
			return W;
		}
		
		return 1+ F(Math.max(W, n-W)) ;
		
	}
}






