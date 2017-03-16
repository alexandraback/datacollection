import java.util.*;

public class B{
	public static void main(String args[]){	
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++){
			long A = sc.nextLong();
			long B = sc.nextLong();
			long K = sc.nextLong();

			long ans = 0;
			for(long i = 0; i < A; i++)
				for(long j = 0; j < B; j++)
				 	if((i&j) < K)
				 		ans++;

			System.out.printf("Case #%d: %d\n",ca,ans);
		}
	}
}