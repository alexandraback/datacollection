import java.util.*;

public class NewLotteryGame{
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=0; t<T; t++){
		
			int A = sc.nextInt();
			int B = sc.nextInt();
			int K = sc.nextInt();
			
			int num = 0;
			int count = 0;
			
			for(int i=0; i<A; i++){
				
				for(int j=0; j<B; j++){
					
					num = i & j;
					if(num < K) count++;
					
				}
				
			}
			
			System.out.println("Case #"+(t+1)+": "+count);
		
		}
		
	}
	
}