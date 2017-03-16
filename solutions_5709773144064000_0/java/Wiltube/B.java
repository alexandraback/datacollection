package qualifiers;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class B {
	final static Boolean DEBUG_ENABLE = true;
	final static Boolean TIMER_ENABLE = true;
	
	final static String FILE_NAME = "B-small-attempt0";//<<<--------
	
	final static String BASE = "C:/CodeJam/" + FILE_NAME;
	final static String INPUT = BASE + ".in";
	final static String OUTPUT = BASE + ".out";
	static Scanner in;
	static PrintWriter out;
	static double F;
	
    public static void main(String[] args){
        try {
            in = new Scanner(new FileReader(INPUT));
            in.useLocale(Locale.US);
            out = new PrintWriter(OUTPUT);

            int number_of_cases = in.nextInt();
            in.nextLine();
            for (int c = 0; c < number_of_cases; c++) {
            	out.print("Case #" + (c + 1) + ": ");
            	
                if(DEBUG_ENABLE) System.out.println("Solving case " + (c + 1) + "...");                
                if(TIMER_ENABLE){
	                long startTime = System.currentTimeMillis();
	                caseSolver();
	                long endTime = System.currentTimeMillis();
	                System.out.println((endTime - startTime) + " ms");
                } else
                	caseSolver();
                
                out.println();
            }
            out.println();
            out.flush();
            out.close();
            in.close();
        } catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    }
    
    private static double F(int n){
    	return 2 + n*F;
    }

	private static void caseSolver(){
		double C = in.nextDouble();
		F = in.nextDouble();
		double X = in.nextDouble();
		double seconds = X/F(0);
		double next_seconds = X/F(1) + C/F(0);
		
		for(int n = 1; next_seconds < seconds; n++){
			seconds = next_seconds;
			next_seconds = seconds + (C - X)/F(n) + X/F(n + 1);
		}
		out.print(seconds);
	}
}
