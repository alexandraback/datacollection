import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;


public class main {
	
	 static public void publishResult(int s, int N){
		 System.out.print("Case #"+N+": "+s);
		 System.out.println(); 
	 }
	 
	 static public boolean checkQ(long Q){
		 for(int i=0; i<41; i++){
			 if(Q== Math.pow(2, i))
				 return true;
			 }
		 return false;
		 }
	 
	 public static long pgcd(long u, long v) {
		    if (u * v == 0) {
		      return (Math.abs(u) + Math.abs(v));
		    }
		    
		    if (u > 0) {
		      u = -u;
		    } // make u negative
		    if (v > 0) {
		      v = -v;
		    } // make v negative
		      // B1. [Find power of 2]
		    int k = 0;
		    while ((u & 1) == 0 && (v & 1) == 0 && k < 31) { // while u and v are
		                              // both even...
		      u /= 2;
		      v /= 2;
		      k++; // cast out twos.
		    }
		    // B2. Initialize: u and v have been divided by 2^k and at least
		    // one is odd.
		    long t = ((u & 1) == 1) ? v : -(u / 2)/* B3 */;
		    // t negative: u was odd, v may be even (t replaces v)
		    // t positive: u was even, v is odd (t replaces u)
		    do {
		      /* assert u<0 && v<0; */
		      // B4/B3: cast out twos from t.
		      while ((t & 1) == 0) { // while t is even..
		        t /= 2; // cast out twos
		      }
		      // B5 [reset max(u,v)]
		      if (t > 0) {
		        u = -t;
		      } else {
		        v = t;
		      }
		      // B6/B3. at this point both u and v should be odd.
		      t = (v - u) / 2;
		      // |u| larger: t positive (replace u)
		      // |v| larger: t negative (replace v)
		    } while (t != 0);
		    return -u * (1 << k); // gcd is u*2^k
		  }
	
	public static void main(String[] args) throws FileNotFoundException {
		//Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner( new File("/home/loic/workspace/CodeJam1/src/input.txt"));
		//Scanner res = new Scanner( new File("/home/workspace/CodeJam1/bin/Result.txt"));
		int T = sc.nextInt(); long P;
		long Q, R;
		int result; String s;
		for(int z = 0; z<T; z++){
			s=sc.next();
			result=s.indexOf('/');
			P=Long.parseLong(s.subSequence(0, result).toString());
			Q=Long.parseLong(s.subSequence(result+1, s.length()).toString());
			R = pgcd(P,Q);
			P=P/R;
			Q=Q/R;
			if(!checkQ(Q)){
				System.out.print("Case #"+(z+1)+": "+"impossible");
				 System.out.println(); 
			}
			else{
				result=1;
				while(2*P<Q){
					P*=2;
					result++;
				}
			publishResult(result, z+1);
			}
		}
	}
}
