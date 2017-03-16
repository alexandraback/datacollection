import java.util.*;
import java.io.*;


public class Main {
	
  public static void main(String[] args) {
	  try {
		System.setIn(new FileInputStream("g:/C-small-attempt2.in"));
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	}
	  
	  Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	  int line = in.nextInt();
	  int i = 1;
	  int n, j, m;
	  char[] jams;
	  long[] divisors;
	  String mString;
	  while (i <= line) {
		  System.out.println("Case #" + i + ":");
		  n = in.nextInt();
		  j = in.nextInt();
		  jams = new char[n];
		  jams[0] = '1';
		  jams[n - 1] = '1';
		  n = n - 2;
		  while (n > 0) {
			  jams[n] = '0';
			  n--;
		  }
		  while (j > 0) {
			  divisors = isJamcoins(jams);
			  if (divisors != null) {
				  mString = new String(jams);
				  m = 2;
				  while (m <= 10) {
					  mString = mString + " " + divisors[m];
					  m++;
				  }
				  System.out.println(mString);
				  j--;
			  }
			  if (!next(jams)) break;
		  }
		  i++;
	  }
	  in.close();
  }
  
  public static boolean next(char[] j) {
	  int i = j.length - 2;
	  while (i > 0) {
		  if (j[i] == '0') {
			  j[i] = '1';
			  i++;
			  while (i < j.length - 1) {
				  j[i] = '0';
				  i++;
			  }
			  return true;
		  }
		  i--;
	  }
	  return false;
  }
  
  public static long isPrime(long a) {
	  if (a == 2 || a == 3) return 1;
	  if (a % 2== 0) return 2;
	  long i = 3;
	  long max = a / 2;
	  while (i <= max) {
		  if (a % i== 0) return i;
		  i = i + 2;
		  if (i > 10000) return -1;
	  }
	  return 1;
  }
  
  public static long[] isJamcoins(char[] j) {
	  if (j[0] != '1' || j[j.length - 1] != '1') return null;
	  long[] divisors = new long[11];
	  int i = 2;
	  while (i <= 10) {
		  divisors[i] = getInterpretation(j, i);
		  i++;
	  }
	  i = 2;
	  while (i <= 10) {
		  divisors[i] = isPrime(divisors[i]);
		  if (divisors[i] == 1 || divisors[i] == -1) return null;
		  i++;
	  }
	  return divisors;
  }
  public static long getInterpretation(char[] a, int base) {
	  int i = a.length - 1;
	  long e = 1;
	  long interpretation = 0;
	  while (i >= 0) {
		  interpretation = interpretation + (a[i] - '0') * e;
		  i--;
		  e = e * base;
	  }
	  return interpretation;
  }

}