import java.io.*;
import java.util.*;

class KingTmp implements Comparable<KingTmp> {
	int a;
	int b;
	
	public int compareTo( KingTmp other ) {
		if( this.b == other.b ) {
			return other.a - this.a;
		}
		return this.b - other.b;
	}
}

public class KingdomRush {

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
			int n = sc.nextInt();

			KingTmp[] ab = new KingTmp[n];
			for( int j = 0; j < n; j++ ) {
				ab[j] = new KingTmp();
				ab[j].a = sc.nextInt();
				ab[j].b = sc.nextInt();
			}
			
			Arrays.sort( ab );
			boolean[] check = new boolean[ab.length];
			
			int ret = 0, s = 0;
			FORJ: for( int j = 0; j < ab.length; j++ ) {
				boolean flag = true;
				while( s < ab[j].b && flag ) {
					flag = false;
					for( int k = ab.length - 1; k >= j && s < ab[j].b ; k-- ) {
						if( s >= ab[k].a && check[k] == false ) {
							check[k] = true;
							s += 1;
							ret++;
							flag = true;
						}
					}
				}
				if( s >= ab[j].b ) {
					if( check[j] ) s += 1;
					else s += 2;
				}
				else {
					ret = -1;
					break FORJ;
				}
				ret++;
			}
			
						
			//System.out.println("Case #" + (i+1) + ": " + ( ( ret >= 0 )? ret: "Too Bad" ));
			fout.println("Case #" + (i+1) + ": " + ( ( ret >= 0 )? ret: "Too Bad" ));
		}

		fout.close();
		sc.close();
	}

}
