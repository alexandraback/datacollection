import java.util.*;
import java.io.*;


public class Main {
	
  public static void main(String[] args) {
	  try {
		System.setIn(new FileInputStream("g:/C-large.in"));
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
  
  public static long isPrime(char[] number, int base) {
	  long i = 2;
	  long m;
	  while (i < 100) {
		  m = bigDiv(number, i, base);
		  if (m == 0) return i;
		  i++;
	  }
	  return -1;
  }
  
  public static long[] isJamcoins(char[] j) {
	  if (j[0] != '1' || j[j.length - 1] != '1') return null;
	  long[] divisors = new long[11];
	  int i = 2;
	  while (i <= 10) {
		  divisors[i] = isPrime(j, i);
		  if (divisors[i] == -1) return null;
		  i++;
	  }
	  return divisors;
  }
  
  public static long getInterpretation(char[] a, int base, int length) {
	  int i = length - 1;
	  long e = 1;
	  long interpretation = 0;
	  while (i >= 0) {
		  interpretation = interpretation + (a[i] - '0') * e;
		  i--;
		  e = e * base;
	  }
	  return interpretation;
  }
  
  public static long bigDiv(char[] number, long div, int base) {
	  if (number.length <= 8) return getInterpretation(number, base, number.length) % div;
	  long m = getInterpretation(number, base, 8) % div;
	  char[] mChar = new char[number.length - 8];
	  int i = mChar.length - 1;
	  while (i >= 0) {
		  mChar[i] = number[i + 8];
		  i--;
	  }
	  return bigDiv(addAtStart(mChar, base(m, base)), div, base);
  }
  
  public static char[] addAtStart(char[] number, char[] toAdd) {
	  String string = new String(toAdd) + new String(number);
	  byte[] bytes = string.getBytes();
	  char[] s = new char[bytes.length];
	  int i = bytes.length- 1;
	  while (i >= 0) {
		  s[i] = (char)bytes[i];
		  i--;
	  }
	  return s;
  }
  
  public static char[] base(long number, int base) {
	  int length = 1;
	  long m = number;
	  while (m >= base) {
		  m = m / base;
		  length++;
	  }
	  char[] s = new char[length];
	  length--;
	  m = number;
	  while (length >= 0) {
		  s[length] = (char)(m % base + '0');
		  m = m / base;
		  length--;
	  }
	  return s;
  }

}