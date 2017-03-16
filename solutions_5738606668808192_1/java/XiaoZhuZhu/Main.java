import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class Main {
	public static void run(int N, int J){
		System.out.println("Case #1:");
		long x = (1L << (N-1) ) | 1;
		BigInteger [][]g = new BigInteger[11][N];
		for(int i=2; i<=10; i++){
			g[i][0] = BigInteger.ONE;
			for(int j=1; j<N; j++){
				g[i][j] = g[i][j-1].multiply( BigInteger.valueOf(i) );
			}
		}
		
		while( J > 0 ){
			assert( x < (1L<<N) );
			BigInteger a[] = new BigInteger[11];
			for(int i=0; i<=10; i++) a[i] = BigInteger.valueOf(0);
			long t = x;
			for(int i=0; i<N; i++){
				int m = (int)(t % 2);
				t /= 2;
				for(int k=2; k<=10; k++){
					if ( 1==m ){
						a[k] = a[k].add( g[k][i] );
					}
				}
			}
//			System.out.print( x + " " + t + " " );
//			for(int i=2; i<=10; i++) System.out.print( a[i] + " " );
//			System.out.println("");
			
			int fac[] = new int[11];
			int cnt=0;
			for(int base=2; base<=10; base++){
				fac[base] = -1;
				for(int i=3; i<10000; i++){
					if( a[base].mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO) ){
						fac[base]=i;
						cnt++;
						break;
					}
				}
				if( -1 == fac[base] ) break;
			}
			if( 9 == cnt ){
				System.out.print(a[10]);
				for(int i=2; i<=10; i++) System.out.print(" "+fac[i]);
				System.out.println();
				J--;
			}
			
			x += 2;		
		}
		
	}
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		System.setOut(new PrintStream(new File("C-small.out")));
		run(16, 50);
		System.setOut(new PrintStream(new File("C-large.out")));
		run(32, 500);
	}

}
