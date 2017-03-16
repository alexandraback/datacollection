import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.Date;
import java.util.Locale;
import java.util.Scanner;


public class CSol {


	public static void main(String[] args) {
		
		
		
		
		
		Date d1 = new Date();
		//solveC("c.in", "c.out");
		//solveA("c-large.in", "C-large.out");		
		solveC("C-small-attempt0.in", "C-small-attempt0.out");
		
		Date d2 = new Date();
		//System.out.println("time: " + (d2.getTime() - d1.getTime()));

	}


	private static boolean numbers [] = new boolean [1000000];
	private static void createPrimes() {
		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = true;
		}
		
		int sk = 2;
		numbers[0] = false;
		numbers[1] = false;
		while (true) {
			if (numbers[sk]) {
				for (int i = sk*2; i < numbers.length; i+=sk) {
					numbers[i] = false;
				}
			}
			
			if (sk == 2)
				sk = 3;
			else {
				sk+=2;
			}
			if (sk >= numbers.length) {
				break;
			}
		}
	}
	
	private static boolean isPrimeFast(long r) {
		if (r < numbers.length ) {
			return numbers[(int)r];
		} else {
			return isPrime(r);
		}
	}
	
	private static boolean isPrime(long r) {
		if (r == 1) {
			return false;
		} else if (r == 2) {
			return true;
		} else {
			if (r % 2 == 0) {
				return false;
			}
			for (long i = 3; i <= Math.sqrt(r); i+=2) {
				if (r % i == 0) {
					return false;
				}
				
			}
			return true;
		}
	}

	
	private static void solveC(String in, String out) {
		try {
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			Scanner sc = new Scanner(new File(in));

			long t = sc.nextLong();
			sc.nextLine();
			
			
			
			createPrimes();
			

			for (long i2 = 0; i2 < t; i2++) {
				
				int n = sc.nextInt();
				int j = sc.nextInt();
				
				//System.out.println(n + " result: " + rez);
				bw.write("Case #" + (i2+1) + ":" +"\n");
				solve(n, j, bw);
				
				
			}				
				
			
			bw.flush();
			bw.close();
			fw.close();
			sc.close();
		} catch (FileNotFoundException e) {
			
		} catch (IOException e) {
			
		} finally {
			
		}
	}


	private static String solve(int n, int j, BufferedWriter bw) throws IOException {
		//System.out.println(n + " " + j);
		

		
		long min = (2L << (n-2)) + 1;
		long max = (2L << (n-1)) - 1;
		//System.out.println(min + " " + Long.toBinaryString(min));
		//System.out.println(max + " " + Long.toBinaryString(max) + " " +Long.toBinaryString(max).length());
		//System.out.println("range: " + (max-min+1));
		
		//long a = min;
		//long a = Long.parseLong("1001", 2);
		
		int cnt = 0;
		for (long e = min; e <= max; e=e+2) {
			
			boolean allGood = isAllGood(e);
			
			
			
			
			if (allGood) {
				cnt++;
				
				String bs = Long.toBinaryString(e);
				String result =  bs + " ";
				for (int i = 2; i <= 10; i++) {
					long inBaseLong = Long.parseLong(bs, i);
					long factor = findFactor(inBaseLong);
					//result += inBaseLong + " " + factor;
					result += factor;
					if (i != 10) {
						result += " ";
					}
				}
				result += "\n";
				//System.out.println(result);
				bw.write(result);
				
				
				if (cnt == j) {
					break;
				}
			}
		}
		
		//System.out.println("matches: " + cnt);
		
		
				
		
		
		return null;
	}

	private static long findFactor(long r) {
		if (r % 2 == 0) {
			return 2;
		}
		for (long i = 3; i <= Math.sqrt(r); i+=2) {
			if (r % i == 0) {
				return i;
			}
		}
		return -1;
	}

	private static boolean isAllGood(long a) {
		boolean allGood = true;

		String bs = Long.toBinaryString(a);
		for (int i = 10; i >= 2; i--) {
			
			//String inBase = Long.toString(a, i);
			long inBaseLong = Long.parseLong(bs, i);
			boolean isPrime = isPrimeFast(inBaseLong);
			
			//System.out.println(bs + " base: " + i + " " +  inBaseLong + " " + isPrime);
			if (isPrime) {
				allGood = false;
				//break;
			}
		}
		return allGood;
	}















}
