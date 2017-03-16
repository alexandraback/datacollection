import java.util.*;
import java.io.*;


public class Main {
  public static void main(String[] args) {
	  try {
		System.setIn(new FileInputStream("g:/A-small-attempt0.in"));
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	}
	  
	  Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	  int line = in.nextInt();
	  int i = 1;
	  int f;
	  while (i <= line) {
		  f = getF(in.nextInt());
		  if (f == -1) System.out.println("Case #" + i + ": INSOMNIA");
		  else System.out.println("Case #" + i + ": " + f);
		  i++;
	  }
	  in.close();
  }
  
  public static int getF(int number) {
	  if (number == 0) return -1;
	  boolean[] read = new boolean[]{false,false,false,false,false,false,false,false,false,false};
	  int length;
	  int mNumber = number;
	  int d;
	  int i = 1;
	  while (i < 100000) {
		  mNumber = number * i;
		  length = getLength(mNumber) - 1;
		  while (length >= 0) {
			  d = mNumber / mul(length);
			  read[d] = true;
			  mNumber = mNumber - d * mul(length);
			  length--;
		  }
		  if (done(read)) return number * i;
		  i++;
	  }
	  return -1;
  }
  
  public static boolean done(boolean[] a) {
	  int i = 0;
	  while (i < 10) {
		  if (!a[i]) return false;
		  i++;
	  }
	  return true;
  }
  
  public static int getLength(int a) {
	  int s = 0;
	  while (a > 0) {
		  a = a / 10;
		  s++;
	  }
	  return s;
  }
  
  public static int mul(int a) {
	  int s = 1;
	  while (a > 0) {
		  s = s * 10;
		  a--;
	  }
	  return s;
  }
  
}