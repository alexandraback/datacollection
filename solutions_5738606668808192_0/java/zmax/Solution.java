package coinJam;

import java.util.*;

public class Solution {

	public static void getCoinJam(int N, int J){
		//generate J jamcoin with length N
		
		int numCoinJam = 0;
		
		long minValue = 1+ (long)Math.pow(2, N-1);
		long maxValue = 0;
		long multiple = 1;
		for(int i=0;i<N;i++){
			maxValue += multiple;
			multiple *= 2;
		}
		//System.out.println(minValue);
		//System.out.println(maxValue);
		for(long num = minValue; num<=maxValue;num += 2){
			List<Long> divisors = new ArrayList<Long>();
			boolean isJamCoin = true;
			for(int base=2;base<=10;base++){
				long divisor = getDivisor(num, base);
				if(divisor > 1){
					divisors.add(divisor);
				}
				else{
					isJamCoin = false;
					break;
				}
			}
			if(isJamCoin){
				System.out.print(Long.toBinaryString(num));
				for(int i=0;i<9;i++){
					System.out.printf(" %d", divisors.get(i));
				}
				System.out.println();
				numCoinJam++;
				if(numCoinJam>=J){
					break;
				}
			}
		}
		
	}
	
	public static long getDivisor(long num, int base){
		//num is in base 2
		//need to convert to base
		
		if(base == 2){
			//System.out.println(num);
			return findDivisor(num);
		}
		
		long result = 0;
		long multiple = 1;
		while(num > 0){
			if((num%2)==1){
				result += multiple;
			} 
			multiple *= base;
			num = num/2;
		}
		//System.out.println(result);
		return findDivisor(result);
	}
	
	private static long findDivisor(long num){
		long divisor = 1;
		long max = (long)Math.sqrt(num);
		for(long i=2;i<=max;i++){
			if((num%i)==0){
				divisor = i;
				break;
			}
		}
		
		return divisor;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			int N = scan.nextInt();
			int J = scan.nextInt();
			System.out.printf("Case #%d:\n", i);
			Solution.getCoinJam(N, J);
			
		}
		
		scan.close();
		
		
	}

}
