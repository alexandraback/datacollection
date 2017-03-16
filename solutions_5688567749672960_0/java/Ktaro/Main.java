import java.io.InputStreamReader;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		try(Scanner scan = new Scanner(new InputStreamReader(System.in))){
			int T = scan.nextInt();
			
			for(int i = 1; i<=T; i++){
				long N = scan.nextLong();
				solve(i, N);
			}
			
		}
	}
	
	private static void solve(int testNum, final long N){
		long ans = 1;
		long num = 1;
				
		while(true){
			if(num == N){
				System.out.println("Case #" + testNum + ": " + ans);
				return;
			}
			ans++;
			
			long tmp = num;
			tmp++;
			long rev = reverse(tmp);
			long revnum = reverse(num);
			if((num % 10 == 9 || rev >= N) && revnum <= N && revnum > num){
				num = revnum;
			}else{
				num = tmp;
			}
		}
	}
	
	private static long reverse(long l){
		StringBuilder sb = new StringBuilder(Long.toString(l));
		long rev = Long.valueOf(sb.reverse().toString());
		return rev; 
	}
	
}
