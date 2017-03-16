import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Main {
	static int primes[] = {2,3,5,7,11,13,17,19,23,29,31} ;
	static int n , jj ;
	static BigInteger [][]power  = new BigInteger[11][33];
	static BigInteger convert(BigInteger mask , int base){
	    BigInteger ans = BigInteger.ZERO ;
	    for(int i = 0 ; i < n ; i++){
	        if(mask.and(power[2][i]).compareTo(BigInteger.ZERO) !=0){
	            ans = ans.add(power[base][i]) ;
	        }
	    }
	    return ans ;
	}

	public static void main(String[]args) throws FileNotFoundException{
		File file = new File("C-large.in") ;
		Scanner in = new Scanner(file) ;
		PrintWriter writer = new PrintWriter("large.out") ;
	    int t ;
	    t = in.nextInt() ;
	    //t = 1 ;
	    for(int i = 2 ; i <= 10 ; i++){
	        power[i][0] = BigInteger.ONE ;
	        for(int j = 1 ; j <= 32 ; j++){
	            power[i][j] = power[i][j-1].multiply(BigInteger.valueOf(i)) ;
	        }
	    }
	    for(int I = 1 ; I <= t ; I++){
	        writer.println("Case #" + I + ":") ;
	        n = in.nextInt() ;
	        jj = in.nextInt() ;
	        //n = 32 ;
	        //jj = 500 ;
	        for(BigInteger i = power[2][n-1] ; jj > 0 && i.compareTo(power[2][n].subtract(BigInteger.ONE)) < 0 ; i = i.add(BigInteger.ONE)){
	            if((i.and(power[2][0])).compareTo(BigInteger.ZERO) == 0 || (i.and(power[2][n-1])).compareTo(BigInteger.ZERO) == 0)continue ;
	            ArrayList<Integer>v = new ArrayList() ;
	            boolean flag = true ;
	            for(int j = 2 ; j <= 10 && flag ; j++){
	                BigInteger x = convert(i,j) ;
	                boolean f = true ;
	                for(int k = 0 ; k < 11 && f ; k++){
	                    if(x.mod(BigInteger.valueOf(primes[k])).compareTo(BigInteger.ZERO) == 0){
	                        v.add(primes[k]) ;
	                        f = false ;
	                        break ;
	                    }
	                }
	                if(f)flag = false ;
	            }
	            if(flag){
	                ArrayList<Character>s = new ArrayList<Character>() ;
	                for(int j = 0 ; j < n ; j++){
	                    if((i.and(power[2][j])).compareTo(BigInteger.ZERO) == 0)s.add('0') ;
	                    else s.add('1');
	                }
	                Collections.reverse(s);
	                for(int j = 0 ; j < s.size() ; j++)writer.print(s.get(j)) ;
	                for(int j = 0 ; j < v.size() ; j++){
	                	writer.print(" " + v.get(j)) ;
	                }
	                writer.println() ;
	                jj--;
	            }
	        }
	    }
	    writer.close(); 
	    return ;
	}
}
