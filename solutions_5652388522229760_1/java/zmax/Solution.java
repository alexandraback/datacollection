package countingSheep;

import java.util.*;

public class Solution {

	public static long fallAsleep(int N){
		if(N==0){
			return -1;
		}
		
		HashSet<Integer> set = new HashSet<Integer>();
		for(int i=0;i<10;i++){
			set.add(i);
		}
		
		long times = 1;
		long result = 0;
		while(!set.isEmpty()){
			result = N*times;
			long num = result;
			int digit;
			while(num>0){
				digit = (int)(num%10);
				if(set.contains(digit)){
					set.remove(digit);
				}
				num = num/10;
			}
			times++;			
		}
		
		return result;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			int N = scan.nextInt();
			long lastNum = Solution.fallAsleep(N);
			if(lastNum<0){
				System.out.printf("Case #%d: INSOMNIA\n", i);
			}
			else{
				System.out.printf("Case #%d: %d\n", i, lastNum);
			}
		}
		scan.close();

	}

}
