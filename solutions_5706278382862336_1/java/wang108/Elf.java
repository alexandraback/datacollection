import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Elf {

	public static void main( String[] args ) throws IOException{
		(new Elf()).elf();
	}
	
	long gcd( long a, long b ){
		if ( a%b == 0 )
			return b;
		else return gcd(b, a%b);
	}
	
	public void elf() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			String str = sc.next();
			int slash = str.indexOf('/');
			long p = Long.parseLong(str.substring(0,slash));
			long q = Long.parseLong(str.substring(slash+1));
			if ( p == 0 ){
				bw.write("Case #" + z + ": ");
				bw.write("impossible\n");
				continue;
			}
			long g = gcd(q, p);
			p /= g;
			q /= g;
			int ans = 0;
			long tq = q;
			boolean flag = true;
			while ( tq > 1 ){
				if ( tq%2 != 0 ){
					flag = false;
					break;
				}
				tq /= 2;
			}
			ans = 1;
			while ( p*2 < q ){
				q /= 2;
				ans++;
			}
			bw.write("Case #" + z + ": ");
			if ( !flag )
				bw.write("impossible");
			else bw.write(""+ans);
			bw.write("\n");
		}
		bw.close();
		sc.close();
	}
}
