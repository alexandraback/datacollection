import java.math.BigInteger;
import java.util.Scanner;

public class p3 {
	private static BigInteger findLCD(BigInteger N){
		//for(BigInteger i = BigInteger.valueOf(2); i.multiply(i).compareTo(N) < 0; i = i.add(BigInteger.valueOf(1))){
		for(BigInteger i = BigInteger.valueOf(2); i.compareTo(BigInteger.valueOf(50)) < 0; i = i.add(BigInteger.valueOf(1))){
			if(N.mod(i).compareTo(BigInteger.ZERO) == 0) return i;
		}
		return BigInteger.ZERO;
	}
	private static BigInteger interpret(BigInteger N2, int base){
		BigInteger currPow = BigInteger.valueOf(1);
		BigInteger retval = BigInteger.valueOf(0);
		
		while(N2.compareTo(BigInteger.ZERO) > 0){
			BigInteger divmod[] = N2.divideAndRemainder(BigInteger.valueOf(2));
			if(divmod[1].compareTo(BigInteger.ONE) == 0) retval = retval.add(currPow);
			currPow = currPow.multiply(BigInteger.valueOf(base));
			N2 = divmod[0];
		}
		return retval;
	}
	private static void getJamcoins(int length, int quantity){
		BigInteger coin = BigInteger.valueOf(2).pow(length - 1).add(BigInteger.ONE);
		BigInteger divisors[] = new BigInteger[9];
		while(quantity > 0){
			
			boolean isPrime = false;
			for(int b = 2; b <= 10 && !isPrime; b++){
				divisors[b - 2] = findLCD(interpret(coin, b));
				if(divisors[b - 2] == BigInteger.ZERO) isPrime = true;
			}
			
			if(!isPrime){
				System.out.print(interpret(coin, 10).toString());
				for(int b = 0; b < 9; b++) 
					System.out.print(" " + divisors[b].toString());
				System.out.println("");
				quantity--;
			}
			
			coin = coin.add(BigInteger.valueOf(2));
		}
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		for(int c = 1; c <= testCases; c++){
			int N = sc.nextInt();
			int J = sc.nextInt();
			System.out.println("Case #" + Integer.valueOf(c).toString() + ":");
			getJamcoins(N, J);
		}
		sc.close();
	}
	
	
}
