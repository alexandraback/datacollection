package main;

import java.math.BigInteger;
import java.util.ArrayList;

public class CoinJam extends CodeJamBase {

	@Override
	public String doResolve(int count, String line, int lineNum) {
		String[] strs = line.split(this.SPACE_CHAR);
		int n = Integer.parseInt(strs[0]);
		int j = Integer.parseInt(strs[1]);
		jamcoins = new BigInteger[j];
		divisors = new ArrayList<ArrayList<BigInteger>>();
		digits = new int[n-2];
		backtrack(n, j, 0);
		this.outputSolution(1, "");
		for(int i=0;i<j;i++) {			
			System.out.println(this.getSolutionLine(i));
		}
		return null;
	}
	
//	int[][] divisors;
	ArrayList<ArrayList<BigInteger>> divisors;
	int[] digits;
	BigInteger[] jamcoins;
	int foundCount=0;
	
	void backtrack(int n, int j, int index) {
		if(foundCount == j) {
			return;
		}
		if(index == digits.length) {
			boolean isJamcoin = true;
			ArrayList<BigInteger> divisorSol = new ArrayList<BigInteger>();
			BigInteger value = BigInteger.ZERO;
//			for(int i=0;i<digits.length;i++) {
//				System.out.print(digits[i]+" ");
//			}
//			System.out.println("");
			BigInteger valueAt;
			for(int base=2;base<=10;base++) {
				value = BigInteger.ZERO;
				int size = digits.length;
				for(int i=0;i<size;i++) {
					if(digits[i] == 1) {
						valueAt = getValueAt(base, i + 1);
						if(value == BigInteger.ZERO) {
							value = valueAt;
						} else {
							value = value.add(valueAt);
						}
					}
				}
				value = value.add(BigInteger.ONE);
				valueAt = getValueAt(base, n-1);
				value = value.add(valueAt);
				
				BigInteger divisor = checkPrime(value, base);
//				System.out.println(foundCount + " @@ " + base + " : " + value + " > " + divisor);
				divisorSol.add(divisor);
				if(divisor.equals(BigInteger.ZERO)) {
					isJamcoin = false;
					break;
				}
			}

			if(isJamcoin) {
				jamcoins[foundCount++] = value;
				divisors.add(divisorSol);
			}
			return;
		}
		
		digits[index] = 1;
		backtrack(n, j, index+1);
		
		digits[index] = 0;
		backtrack(n, j, index+1);					
	}
	
	String getSolutionLine(int index) {
		String sol = "" + jamcoins[index];
		ArrayList<BigInteger> divisorSol = divisors.get(index);
		for(BigInteger divisor : divisorSol) {
			sol += " " + divisor.toString();
		}
		return sol;
	}
	
	public BigInteger getValueAt(int base, int pos) {
		return new BigInteger(""+base).pow(pos);
	}
	
	BigInteger[] check = {BigInteger.valueOf(2), BigInteger.valueOf(3), BigInteger.valueOf(5), BigInteger.valueOf(7)};
	private BigInteger checkPrime(BigInteger coin, int base) {
		BigInteger divisor = BigInteger.ZERO;

		for(BigInteger bi : check) {
			BigInteger remainder = coin.remainder(bi);	
			if(remainder.equals(BigInteger.ZERO)) {
				divisor = bi;
				break;
			}
		}
		return divisor;
	}

	public static void main(String[] args) {
		CoinJam test = new CoinJam();
		test.start();
	}

}
