import java.io.BufferedReader;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Vector;

public class Solver {
	
	public static void main(String[] args) {
		Solver solver = new Solver();
		solver.readFromFile("src/A-small-attempt1.in");
	}

	private long P;
	private long Q;
	private int nb_case = 0;
	private long total = (long)Math.pow(2, 40);
	
	
	ArrayList<ArrayList<String>> game;

	private long divisor( long  m, long  n){
        long  temp;
        if (m < n){     // if m<n,swap m,n 
           temp = m;
           m = n;
           n = temp;
       }
        while (m % n != 0 ){
           temp = n;
           n = m % n;
           m = temp;
       }
        return  n;
   }
	
	private static boolean checkPowerOfTwo(long number){
        return ((number & (number -1)) == 0);
    }
	
	private void solveACase() {
		
		if(false && !checkPowerOfTwo(Q) ) {
			System.out.println("impossible");
			return;
		} else {
			long res = divisor(P, Q);
			if (res <= P) {
				P = P/res;
				Q = Q/res;
			}
			if(!checkPowerOfTwo(Q) ) {
				System.out.println("impossible");
				return;
			}
			if (Q > total) {
				System.out.println("impossible");
				return;
			}
			boolean stop = false;
			double diff = ((double)P)/Q;
			int generation = 0;
			while (!stop) {
				diff = 2 * diff;
				generation++;
				if (diff >=1) {
					stop = true;
				}
			}
			System.out.println(generation);
		}
	}
	
	
	public void readFromFile(String f) {
		BufferedReader br=null;
		String chaine = null;
		
	    try {
	    	try {
	    		br = new BufferedReader(new FileReader(f));
	    		nb_case = Integer.parseInt(br.readLine());
	    		if (nb_case > 0) {
	    			for (int i = 1; i <= nb_case; i++) {
	    				String two_case[] = new String[2];
	    				chaine = br.readLine();
	    				two_case = chaine.split("/");
	    				System.out.print("Case #"+ i + ": ");
						P = Integer.parseInt(two_case[0]);
						Q = Integer.parseInt(two_case[1]);
	    				solveACase();
					}
	    		}
       		} catch(EOFException e) {
       			br.close();
       		}
	    } catch(FileNotFoundException e) {
	    	System.out.println("fichier inconnu : " + f);
	    } catch(IOException e) {
	    	System.out.println("IO Exception");
	    }
	}
}