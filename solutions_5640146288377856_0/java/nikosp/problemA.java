package r1c_2015;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class problemA {
	
	private static int inst;

	public static void main(String[] args) {

        String input = "/Users/npapa/Documents/codejam/A-small-attempt1.in";
        //String input = "/Users/npapa/Documents/codejam/A-large.in";
        String output = "/Users/npapa/Documents/codejam/output";
		try {
            Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                checkInsatnce(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
        	ex.printStackTrace();
        } catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static void checkInsatnce(Scanner sc, PrintWriter pw) throws IOException {
		
		int r = sc.nextInt();
		int c = sc.nextInt();
		int n = sc.nextInt();
		System.out.println(r+" "+c+" "+n);
		
		
	  	int res = solve(r, c,n);
	  	
    	System.out.println(res);
    	pw.print(res);
		
	}

	private static int solve(int r, int c, int n) {

			
		int findRow =r*(c/n);
		int findShip=0;
		if(c%n==0)
			findShip = n-1;
		else
			findShip = n;

//		if(n==1){
//			findRow=r*c;
//			findShip=0;
//		}
		System.out.println("findRow: "+findRow+" findShip: "+findShip);
		return findRow+findShip;
	}


}
