import java.io.*;
import java.util.*;

public class PartElf {
    public static Scanner sc;

    public static void main(String[] args) throws Exception {
      sc = new Scanner(System.in);
      sc = new Scanner(new File("E:\\GitHub\\HHH\\CodeJam\\PartElf\\A-large.in"));
      int c = sc.nextInt();
      String sol = "";
      
      for (int i = 1; i <= c; i++)
          sol += "Case #" + i + ": " + solve() + "\n";
      
      System.out.print(sol);
      PrintWriter pw = new PrintWriter(new File("E:\\GitHub\\HHH\\CodeJam\\PartElf\\A-large.out"));
      pw.print(sol);
      pw.close();
    }

    public static String solve() {
    	String tempS = sc.next();
        long p = Long.parseLong(tempS.split("/")[0]);
        long q = Long.parseLong(tempS.split("/")[1]);
        
        double pq = (double)p / (double)q;

        if (Math.pow(2, 40) * p % q != 0)
            return "impossible";

//        System.out.println("pq: " + pq);
        for (int i = 1; i < 41; i++) {
        	// for (int j = (int) Math.pow(2, i); j > 0; j--) {
        	// 	System.out.println("now: " + j * Math.pow(2, -(i)));
        	// 	if (pq == j * Math.pow(2, -(i)))
         //            return "" + (int)(Math.pow(2, i) - j);
        	// }
            int n = (int) (pq / (1/Math.pow(2, i)));
            pq -= (1/Math.pow(2, i)) * n;
            if (n > 0)
                return "" + i;
        }
		return "??";
    }
    
    public static double abs(double c) {
    	if (c < 0)
    		return -c;
    	return c;
    }
}