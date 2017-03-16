import java.io.*;
import java.util.*;


public class RecycledNumbers {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;
		int t = 0;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
			t = sc.nextInt();
		} catch(Exception e) {
			System.out.println(e);
		}
		
		for( int i = 0; i < t; i++ ) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			boolean[] memo = new boolean[b+1];
			
			int digit = 1;
			while( digit * 10 <= a ) {
				digit *= 10;
			}
			
			long ret = 0;
			for( int j = a; j <= b; j++ ) {
				if( memo[j] ) continue;
				
				if( digit * 10 <= j ) {
					digit *= 10;
				}
				
				int tmp = j, dr = 1;
				do {
					int aa = tmp % 10;
					tmp = ( tmp / 10 ) + digit * aa;
					if( tmp > j && tmp <= b ) {memo[tmp] = true;
						ret += dr;
						dr++;					
					}
				} while( tmp != j );
			}
			
//			System.out.println("Case #" + (i+1) + ": " + ret);
			fout.println("Case #" + (i+1) + ": " + ret);
		}

		fout.close();
		sc.close();
	}

}
