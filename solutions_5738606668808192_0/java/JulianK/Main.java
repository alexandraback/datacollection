package ProblemC;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	static ArrayList<Integer> primes = new ArrayList<>(Arrays.asList(2,3,5));

	public static void main(String[] args) {
	    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    in.nextLine();
	    int N = in.nextInt();
	    int J = in.nextInt();
	    
   	 ArrayList<String> answers = new ArrayList<>();
   	 ArrayList<int[]> divisors = new ArrayList<>();
   	 int found = 0;
   	 int mid = 0;
   	 
   	 find: while (found < J && mid < Math.pow(2, N-2)) {
   		 String currentStr = String.format("1%" + (N-2) + "s1", Integer.toBinaryString(mid)).replace(' ', '0');
//   		 System.out.println(currentStr);
   		 int[] currentDivisors = new int[9];
   		 for(int base=2; base<=10; base++) {
//   			 System.out.println("base: " + base);
	   		 long value = Long.parseLong(currentStr, base);
//	   		 System.out.println("value: " + value);
	   		 int factor = factorOf(value);
//	   		 System.out.println("factor: " + factor);
				 if (factor <= 1) {
					 mid++;
					 continue find;
				 }
				 currentDivisors[base-2] = factor;
   		 }
   		 answers.add(currentStr);
   		 divisors.add(currentDivisors);
//   		 System.out.println(Arrays.toString(currentDivisors));
   		 found++;
   		 mid++;
   	 }
   	 System.out.println("Case #1:");
   	 for (int i=0;i<J;i++) {
   		 System.out.println(String.format("%s %s", answers.get(i), Arrays.toString(divisors.get(i)).replace(", "," ").replaceAll("[\\[\\]]", "")));
   	 }
	    in.close();
	}
	
	public static int factorOf(long n) {
		for (int prime : primes) {
			if (n%prime == 0) return prime;
		}
		int nextPrime = primes.get(primes.size() - 1);
		search: while (nextPrime < 30) {//Math.sqrt(n)) {
			nextPrime++;
			for (int prime: primes) {
				if (nextPrime%prime == 0) {
					continue search;
				}
			}
			primes.add(nextPrime);
			if (n%nextPrime == 0) return nextPrime;
		}
		return 0;
	}
	
}
