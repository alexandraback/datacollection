import java.util.*;
import java.io.*;


public class A {	
 public static void main(String[] args) throws IOException {
  BufferedReader in = new BufferedReader(new FileReader("C:/Users/disha/Desktop/codejam/A/A-small.in"));
  FileWriter fw = new FileWriter("C:/Users/Disha/Desktop/codejam/A/A-small.out");
  /*BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
  FileWriter fw = new FileWriter("A-large.out");*/
  
  int N = new Integer(in.readLine());
  //System.out.println("N= " +N);
  
  int a = 0;
  int b = 0;
  int left = 0;
  
  for (int cases = 1; cases <= N; cases++) {
	  a = 0;
	  b = 0;
	  String[] ss = in.readLine().split(" ");
	  a = Integer.parseInt(ss[0]);
	  b = Integer.parseInt(ss[1]);
	  left = b - a;
	  String[] perc = in.readLine().split(" ");
	  double[] array = new double[a];
	  for (int i = 0; i < a; i++){
	      array[i] = Double.parseDouble(perc[i]);
	  }
	  double mult = 1;
	  for (int i = 0; i < a; i++)
	      mult = mult * array[i];
	  //System.out.println(cases + "mult" + mult);
	  
	   // if I keep typing
	  double expect1 = (b - a + 1)* mult + (1 - mult)* (2*b - a + 2);
	  //System.out.println(cases + "expect1" + expect1);
	  double minexp = expect1;
	  // if I press enter
	  double expect2 = (b+2);
	  //System.out.println(cases + "expect2" + expect2);
	  if (expect2 < minexp){
		  minexp = expect2;
		  //System.out.println("yes");
	  }
	  
	  // if I backspace and delete all which were wrong
	  for (int back = 1; back <= a;  back++) {
		  double mult2 = 1;
		  for (int x = 0; x < (a-back) ; x++){
			  mult2 = mult2 * array[x];
			  //System.out.println(expect3);
		  }
		  
	  double expect3 = (2 * back + b - a + 1)* mult2	+ (2 * back + b - a + 1 + b + 1)* (1 - mult2);
	  if (expect3 < minexp){
		  minexp = expect3;
	  }
	  //System.out.println(cases + "expect3" + expect3);
	  
	 }
	  //System.out.println(cases + "minexp" + minexp);
	  String out = Double.toString(minexp);
	  fw.write ("Case #" + cases + ": " + out + "\n" );	  
	  
  }
 
  fw.flush();
  fw.close();
}
}
