import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CodeJamPartElf {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long two = 1 << (20);
		two *= two;
		int t = Integer.parseInt(br.readLine());
		for(int i = 1; i <= t; i++){
			StringTokenizer st = new StringTokenizer(br.readLine(), "/");
			long num = Long.parseLong(st.nextToken());
			long denom = Long.parseLong(st.nextToken());
			long g = GCD(num,denom);
			num /= g;
			denom /= g;
			if(!pow2(denom)){
				System.out.printf("Case #%d: impossible\n",i);
				continue;
			}
			double p = ((double)num)/denom;
			double cmp = 0.5;
			int ctr = 1;
			while(p < cmp && ctr <= 40){
				ctr++;
				cmp /= 2;
			}
			if(ctr > 40) System.out.printf("Case #%d: impossible\n",i);
			else System.out.printf("Case #%d: %d\n",i,ctr);
		}

	}
	
	public static long GCD(long a, long b){
		if(a % b == 0) return b;
		return GCD(b, a % b);
	}
	
	public static boolean pow2(long a){
		while(a > 1){
			if(a % 2 != 0) return false;
			a /= 2;
		}
		return true;
	}
}
