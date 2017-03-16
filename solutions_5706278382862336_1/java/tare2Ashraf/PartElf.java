import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PartElf {

	public static long gcd(long a, long b) {
		long r = a % b;
		while (r != 0) {
			a = b;
			b = r;
			r = a % b;
		}
		return b;
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t=1;
		long n = Long.parseLong(br.readLine());

		while (n-- > 0) {
			String[] s = br.readLine().split("/");

			long a = Long.parseLong(s[0]);
			long b = Long.parseLong(s[1]);

			long g=gcd(a,b);
			if(g!=1){
				a/=g;
				b/=g;
			}
			
			if(b%2!=0){
				System.out.println("Case #"+(t++)+": impossible");
				continue;
			}
			int c=0;
			while(b%2==0){
				b/=2;
				c++;
				
				if(a>b)
					break;
			}
			if(b>1){
				while(b%2==0)
					b/=2;
			}
			if(b!=1)
				System.out.println("Case #"+(t++)+": impossible");
			else
				System.out.println("Case #"+(t++)+": "+c);
		}
	}
}
