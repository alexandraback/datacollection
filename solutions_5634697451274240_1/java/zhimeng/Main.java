import java.util.*;
import java.io.*;


public class Main {
	
  public static void main(String[] args) {
	  try {
		System.setIn(new FileInputStream("g:/B-large.in"));
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	}
	  
	  Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	  int line = in.nextInt();
	  in.nextLine();
	  int i = 1;
	  int step;
	  byte[] string;
	  int finalPosition;
	  while (i <= line) {
		  string = in.nextLine().getBytes();
		  step = 0;
		  if (string[0] == '+') finalPosition = getFinalHappyP(string);
		  else finalPosition = getFinalBlankP(string);
		  while (finalPosition != -1) {
			  step++;
			  flip(string, finalPosition + 1);
			  if (string[0] == '+') finalPosition = getFinalHappyP(string);
			  else finalPosition = getFinalBlankP(string);
		  }
		  System.out.println("Case #" + i + ": " + step);
		  i++;
	  }
	  in.close();
  }
  
  public static void flip(byte[] string, int count) {
	  int top = 0;
	  int bottom = count - 1;
	  byte m;
	  while (top <= bottom) {
		  if (top == bottom) {
			  if (string[top] == '+') string[top] = '-';
			  else string[top] = '+';
		  }
		  else {
			  m = string[top];
			  if (string[bottom] == '+') string[top] = '-';
			  else string[top] = '+';
			  if (m == '+') string[bottom] = '-';
			  else string[bottom] = '+';
		  }
		  top++;
		  bottom--;
	  }
  }
  
  public static int getFinalBlankP(byte[] string) {
	  int s = string.length - 1;
	  while (s >= 0) {
		  if (string[s] == '-') return s;
		  s--;
	  }
	  return -1;
  }
  
  public static int getFinalHappyP(byte[] string) {
	  int s = string.length - 1;
	  while (s >= 0) {
		  if (string[s] == '-') break;
		  s--;
	  }
	  while (s >= 0) {
		  if (string[s] == '+') return s;
		  s--;
	  }
	  return -1;
  }
  
}