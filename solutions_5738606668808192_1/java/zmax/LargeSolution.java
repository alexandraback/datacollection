package coinJam;

import java.math.BigInteger;
import java.util.*;

public class LargeSolution {

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
			List<BigInteger> divisors = new ArrayList<BigInteger>();
			boolean isJamCoin = true;
			for(int base=2;base<=10;base++){
				BigInteger divisor = getDivisor(num, base);
				if(divisor.compareTo(BigInteger.ONE) > 0){
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
	
	public static BigInteger getDivisor(long num, int base){
		//num is in base 2
		//need to convert to base
		
		BigInteger result = BigInteger.ZERO;
		
		if(base == 2){
			//System.out.println(num);
			result = BigInteger.valueOf(num);
			return findDivisor(result);
		}
		
		BigInteger multiple = BigInteger.ONE;
		while(num > 0){
			if((num%2)==1){
				result = result.add(multiple);
			} 
			multiple = multiple.multiply(BigInteger.valueOf(base));
			num = num/2;
		}
		//System.out.println(result);
		return findDivisor(result);
		
	}
	
	private static BigInteger findDivisor(BigInteger num){
		BigInteger divisor = BigInteger.ONE;
		BigInteger limit = BigInteger.valueOf(300000);
		
		BigInteger temp = BigInteger.valueOf(2);
		while(temp.compareTo(limit) <= 0 && temp.multiply(temp).compareTo(num)<=0){
			if(num.remainder(temp).compareTo(BigInteger.ZERO) == 0){
				divisor = temp;
				break;
			}
			temp = temp.add(BigInteger.ONE);
		}
		
		return divisor;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		long num1 = 3456;
		long num2 = 2340;
		BigInteger b1 = BigInteger.valueOf(num1);
		BigInteger b2 = BigInteger.valueOf(num2);
		System.out.printf("%d", b1);
		System.out.println(b1);		
		System.out.println(b2);
		System.out.println(b1.add(b2));
		System.out.println(b1.subtract(b2));
		System.out.println(b1.multiply(b2));
		System.out.println(b1.divide(b2));
		System.out.println(b1.remainder(b2));
		System.out.println(b1.mod(b2));
		*/
		//System.out.println(Integer.MAX_VALUE);
		
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			int N = scan.nextInt();
			int J = scan.nextInt();
			System.out.printf("Case #%d:\n", i);
			LargeSolution.getCoinJam(N, J);

		}

		scan.close();
		
	}

}
