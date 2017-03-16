import java.util.*;
import java.io.*;


public class Main {
	
  public static void main(String[] args) {
	  try {
		System.setIn(new FileInputStream("g:/D-large.in"));
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	}
	  
	  Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	  int line = in.nextInt();
	  int i = 1;
	  while (i <= line) {
		  System.out.println("Case #" + i + ": " + hello(in.nextInt(), in.nextInt(), in.nextInt()));
		  i++;
	  }
	  in.close();
  }
  
  public static String hello(int k, int c, int s) {
	  String hello = "";
	  int i = 1;
	  if (c == 1) {
		  if (s == k) {
			  while (i <= k) {
				  if (i == 1) hello = hello + i;
				  else hello = hello + " " + i;
				  i++;
			  }
			  return hello;
		  }
		  else return "IMPOSSIBLE";
	  }
	  if (k == 1) return "1";
	  i = 2;
	  while (i <= k) {
		  if (i == 2) hello = hello + i;
		  else hello = hello + " " + i;
		  i++;
	  }
	  return hello;
  }

}