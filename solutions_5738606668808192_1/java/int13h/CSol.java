import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
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
		solveC("C-large.in", "C-large.out");		
		//solveC("C-small-attempt0.in", "C-small-attempt0.out");
		
		Date d2 = new Date();
		//System.out.println("time: " + (d2.getTime() - d1.getTime()));

	}



	

	

	
	private static void solveC(String in, String out) {
		try {
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			Scanner sc = new Scanner(new File(in));

			long t = sc.nextLong();
			sc.nextLine();
			
			
			

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
				
				
				String bs = Long.toBinaryString(e);
				String result =  bs + " ";
				boolean good = true;
				for (int i = 2; i <= 10; i++) {
					BigInteger inBaseLong = new BigInteger(bs, i);
					
					//BigInteger factor = null;
					//BigInteger factor = findFactor(inBaseLong);
					BigInteger factor = findFactorFast(inBaseLong);
					
					//result += inBaseLong + " " + factor;
					result += factor;
					
					if (factor == BigInteger.valueOf(-1)) {
						good = false;
						break;
					}
					if (i != 10) {
						result += " ";
					}
				}
				result += "\n";
				
				//System.out.println(result);
				
				if (good) {
					cnt++;
					//System.out.println(cnt + " " + result);
					bw.write(result);
				}
				
				
				if (cnt == j) {
					break;
				}
			}
		}
		
		//System.out.println("matches: " + cnt);
		
		
				
		
		
		return null;
	}

	private static BigInteger findFactor(BigInteger r) {
		
		BigInteger b2 = BigInteger.valueOf(2L);
		BigInteger b0 = BigInteger.valueOf(0L);
		
		if (r.mod(b2) == b0) {
			return b2;
		}
		BigInteger max = r.divide(b2);
		BigInteger i = BigInteger.valueOf(3);
		while (true) {
			if (r.mod(i) == b0) {
				return i;
			}
			i = i.add(b2);
			if (i.compareTo(max) > 0) {
				break;
			}
		}
		return BigInteger.valueOf(-1L);
	}
	
	private static BigInteger findFactorFast(BigInteger r) {
		
		BigInteger b2 = BigInteger.valueOf(2L);
		BigInteger b0 = BigInteger.valueOf(0L);
		
		if (r.mod(b2) == b0) {
			return b2;
		}
		
		BigInteger max = r.divide(b2);
		max = max.min(BigInteger.valueOf(100L));
		BigInteger i = BigInteger.valueOf(3);
		while (true) {
			if (r.mod(i) == b0) {
				return i;
			}
			i = i.add(b2);
			if (i.compareTo(max) > 0) {
				break;
			}
		}
		return BigInteger.valueOf(-1L);
	}




	private static boolean isAllGood(long a) {
		boolean allGood = true;

		String bs = Long.toBinaryString(a);
		for (int i = 10; i >= 2; i--) {
			
			//String inBase = Long.toString(a, i);
			BigInteger inBaseLong = new BigInteger(bs, i);
			
			//long inBaseLong = Long.parseLong(bs, i);
			boolean isPrime = isPrimeFast(inBaseLong);
			
			//System.out.println(bs + " base: " + i + " " +  inBaseLong + " " + isPrime);
			if (isPrime) {
				allGood = false;
				//break;
			}
		}
		return allGood;
	}

	private static boolean isPrimeFast(BigInteger inBaseLong) {
		
		if (inBaseLong.isProbablePrime(6)) {
			return true;
		} else {
			return false;
		}
	}















}
