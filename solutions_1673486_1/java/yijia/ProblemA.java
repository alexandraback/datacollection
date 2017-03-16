package round1a;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Scanner;

public class ProblemA {

    public static String input = "A-large.in";

    public static void main(String[] args) throws IOException {
//        Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new FileReader(input));
//        PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter(new FileWriter(input+".out"));
        
        int num = in.nextInt();
        NumberFormat formatter = new DecimalFormat("#0.000000");
        double temp;
        for (int i = 0; i < num; i++){
        	double best = Double.POSITIVE_INFINITY;
        	int typed = in.nextInt();
        	int length = in.nextInt();
        	double[] p = new double[typed];
        	for (int j = 0; j < typed; j++)
        		p[j] = in.nextDouble();
        	double[] t = new double[typed+1];
        	t[0] = 1.0;
        	for (int j = 1; j <= typed; j++){
        			t[j] = t[j-1] * p[j-1];
        	}
        	
        	//keep typing
        	temp = 0;
        	temp = t[typed]*(length - typed + 1) + (1 - t[typed])*(length + length - typed + 2);
        	if (best > temp)
        		best = temp;
        	
        	//give up
        	if (best > length + 2)
        		best = length + 2;
        	
        	for (int j = 0; j < typed; j++){
        		temp = t[j]*(length - j + typed - j + 1) + (1 - t[j])*(length - j + typed - j + length + 2);
        		if (best > temp)
        			best = temp;
        	}
        	out.write("Case #" + (i+1) + ": " + formatter.format(best) + "\n");
        }
        
        
        out.close();
    }

}
