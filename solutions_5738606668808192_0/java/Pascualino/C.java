package com.google.gcj.pascualino;

import java.math.BigInteger;
import java.util.Scanner;

public class C {
	private static int N, J;
	private static int solutionCounts = 0;
	private static BigInteger[][] powBases;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		@SuppressWarnings("unused")
		int T = sc.nextInt();
		// Always a single case
		System.out.println("Case #1:");
		N = sc.nextInt();
		J = sc.nextInt();

		long time = System.currentTimeMillis();
		BigInteger[] bases = new BigInteger[11];
		for(int i=2;i<=10;i++){
			bases[i] = new BigInteger("1");
		}
		powBases = new BigInteger[11][N+1];
		for(int j=0;j<=10;j++){
			for(int i=0;i<=N;i++){
				powBases[j][i] = new BigInteger(Integer.toString(j)).pow(i);
			}
		}
		rec("1", bases);
		
		sc.close();
		System.err.println("Time taken: " + (System.currentTimeMillis() - time));
	}
	
	public static void rec(String coin, BigInteger[] bases){
		if(coin.length() == N-1){
			if(solutionCounts < J){
				for(int i=2;i<=10;i++){
					bases[i] = bases[i].add(powBases[i][coin.length()]);
				}
				checkJamCoin("1"+coin, bases);
				for(int i=2;i<=10;i++){
					bases[i] = bases[i].subtract(powBases[i][coin.length()]);
				}
			}
			return;
		}
		if(solutionCounts < J) rec("0"+coin, bases);
		if(solutionCounts < J){
			for(int i=2;i<=10;i++){
				bases[i] = bases[i].add(powBases[i][coin.length()]);
			}
			rec("1"+coin, bases);
			for(int i=2;i<=10;i++){
				bases[i] = bases[i].subtract(powBases[i][coin.length()]);
			}
		}
	}
	
	public static void checkJamCoin(String coin, BigInteger[] bases){
		BigInteger[] divisors = new BigInteger[11];
		for(int n=2;n<=10;n++){
			BigInteger num = bases[n];
			BigInteger divisor = getDivisor(num);
			if(divisor.equals(BigInteger.ONE)){
				return;
			}
			divisors[n] = divisor;
		}
		
		System.out.print(coin);
		for(int i=2;i<=10;i++){
			System.out.print(" " + divisors[i]);
		}
		System.out.println();
		solutionCounts++;
	}

	private static BigInteger getDivisor(BigInteger num) {
		for(BigInteger div = new BigInteger("2"); div.compareTo(new BigInteger("100")) == -1 /*div.bitLength() <= num.bitLength()/2*/; div = div.add(BigInteger.ONE)){
			if(num.mod(div).equals(BigInteger.ZERO)){
				return div;
			}
		}
		return BigInteger.ONE;
	}
}
