import java.util.*;
import java.io.*;


public class A {	
 public static void main(String[] args) throws IOException {
  BufferedReader in = new BufferedReader(new FileReader("C:/Users/Farnoosh/Desktop/A-small.in"));
  FileWriter fw = new FileWriter("C:/Users/Farnoosh/Desktop/A-small.out");
  /*BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
  FileWriter fw = new FileWriter("A-large.out");*/
  
  int N = new Integer(in.readLine());
  //System.out.println("N= " +N);
  
  int A = 0;
  int B = 0;
  int L = 0;
  
  for (int cases = 1; cases <= N; cases++) {
	  A = 0;
	  B = 0;
	  String[] ss = in.readLine().split(" ");
	  A = Integer.parseInt(ss[0]);
	  B = Integer.parseInt(ss[1]);
	  L = B - A;
	  String[] perc = in.readLine().split(" ");
	  double[] array = new double[A];
	  for (int i = 0; i < A; i++){
	      array[i] = Double.parseDouble(perc[i]);
	  }
	  double mult = 1;
	  for (int i = 0; i < A; i++)
	      mult = mult * array[i];
	  
	   // if I keep typing
	  double expect1 = (B - A + 1)* mult + (1 - mult)* (2*B - A + 2);
	  //System.out.println(cases + "expect1" + expect1);
	  double minexp = expect1;
	  // in case of enter
	  double expect2 = (B+2);
	  
	  if (expect2 < minexp){
		  minexp = expect2;
		  //System.out.println("yes");
	  }
	  
	  // if backspace and delete all wrong
	  for (int back = 1; back <= A;  back++) {
		  double mult2 = 1;
		  for (int x = 0; x < (A-back) ; x++){
			  mult2 = mult2 * array[x];
			  
		  }
		  
	  double expect3 = (2 * back + B - A + 1)* mult2	+ (2 * back + B - A + 1 + B + 1)* (1 - mult2);
	  if (expect3 < minexp){
		  minexp = expect3;
	  }
	  
	 }
	  String out = Double.toString(minexp);
	  fw.write ("Case #" + cases + ": " + out + "\n" );	  
	  
  }
 
  fw.flush();
  fw.close();
}
}
