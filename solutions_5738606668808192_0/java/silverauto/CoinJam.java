package main;

import java.util.ArrayList;

public class CoinJam extends CodeJamBase {

	@Override
	public String doResolve(int count, String line, int lineNum) {
		String[] strs = line.split(this.SPACE_CHAR);
		int n = Integer.parseInt(strs[0]);
		int j = Integer.parseInt(strs[1]);
		jamcoins = new long[j];
		divisors = new ArrayList<ArrayList<Long>>();
		digits = new long[n-2];
		backtrack(n, j, 0);
		this.outputSolution(1, "");
		for(int i=0;i<j;i++) {			
			System.out.println(this.getSolutionLine(i));
		}
		return null;
	}
	
//	int[][] divisors;
	ArrayList<ArrayList<Long>> divisors;
	long[] digits;
	long[] jamcoins;
	int foundCount=0;
	
	void backtrack(int n, int j, int index) {
		if(foundCount == j) {
			return;
		}
		if(index == digits.length) {
			boolean isJamcoin = true;
			ArrayList<Long> divisorSol = new ArrayList<Long>();
			long value = 0;
//			for(int i=0;i<digits.length;i++) {
//				System.out.print(digits[i]+" ");
//			}
//			System.out.println("");
			for(int base=2;base<=10;base++) {
				value = 0;
				int size = digits.length;
				for(int i=0;i<size;i++) {
					if(digits[i] == 1) {
					    value += getValueAt(base, i + 1);
					}
				}
				value = value + 1 + getValueAt(base, n-1);
				
				long divisor = checkPrime(value);
//				System.out.println(base + " : " + value + " > " + divisor);
				divisorSol.add(divisor);
				if(divisor == -1) {
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
		ArrayList<Long> divisorSol = divisors.get(index);
		for(Long divisor : divisorSol) {
			sol += " " + divisor;
		}
		return sol;
	}
	
	public long getValueAt(int base, int pos) {
		return (long) Math.pow(base, pos);
	}
	
	private long checkPrime(long coin) {
		long maxCheckValue = ((long)Math.sqrt(coin)) + 1;
		long divisor = -1;
		for(long i=2;i<=maxCheckValue;i++) {
			if(coin % i == 0) {
				divisor = i;
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
