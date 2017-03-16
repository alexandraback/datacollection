import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class OminousOmino {
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileReader("D-small-attempt1.in"));
	        int T = scanner.nextInt();
	        int[] Xs = new int[T];
	        int[] Rs = new int[T];
	        int[] Cs = new int[T];
	        for(int i=0; i<T; i++) {
	        	Xs[i] = scanner.nextInt(); 
	        	Rs[i] = scanner.nextInt();
	        	Cs[i] = scanner.nextInt();
	        }
	        PrintWriter out = new PrintWriter(new FileWriter("output4.txt"));        
	        for(int i=0; i<T; i++) {
	        	boolean RWin = true;
	        	int X = Xs[i];
	        	int R = Rs[i];
	        	int C = Cs[i];
	        	int small = Math.min(R, C);
	        	int big = Math.max(R, C);
	        	if((R*C) % X != 0) {
	        		RWin = true;
	        	} else if(X >= 7) {
	        		RWin = true;
	        	} else if(X <= small) {
	        		RWin = false;
	        	} else if(X > big) {
	        		RWin = true;
	        	} else if(X >= 2*small+1){
	        		RWin = true;
	        	} else if(X == 4 && small == 2){
	        		RWin = true;
	        	} else {
	        		RWin = false;
	        	}
	        	if(RWin) {
	        		out.println("Case #" + (i+1) + ": RICHARD");
	        	} else {
	        		out.println("Case #" + (i+1) + ": GABRIEL");
	        	}	          
	        }
	        out.close();	       
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}
