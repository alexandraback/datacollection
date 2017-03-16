package round1b;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Scanner;

public class ProblemA {

    public static String input = "A-small-attempt3.in";
    
    public static double[] getResult(int[] value, boolean[] care, int n){
    	double total = 0;
    	int max = -1;
    	int maxIndex = -1;
    	for (int j = 0; j < n; j++)
    		if (care[j])
	    	{
	    		total+=value[j];
	    		if (value[j] > max)
	    		{
	    			max = value[j];
	    			maxIndex = j;
	    		}
	    	}
    	if (max == 0)
    	{
    		double[] result = new double[n];
    		double count = 0;
    		for (int j = 0; j < n; j++)
    			if (care[j])
    				count++;
    		for (int j = 0; j < n; j++)
    			if (care[j])
    				result[j] = 100.0/count;
    		return result;
    	}
    	double left = 0;
    	double count = 0;
    	for (int j = 0; j < n; j++)
    		if (care[j])
    			left += (max - value[j]);
    	for (int j = 0; j < n; j++)
			if (care[j])
				count++;
    	
    	double minscore = (total - left)/total/count;
    	if (minscore < 0){
    		care[maxIndex] = false;
    		return null;
    	}
    	double[] result = new double[n];
    	
    	for (int j = 0; j < n; j++)
    		if (care[j])
    			result[j] = (minscore + 1.0*(max - value[j])/total)*100;
    	return result;
    }
    
    public static double get(int i, int[] value, double epsi, double total, int n){
    	double high = 1.0,low=0.0,mid = 0;
		while(high - low > epsi)	{
			mid = (high+low)/2;
			double s = value[i]+ total*mid;
			double ts = 0;
			for(int j = 0; j < n;j++)	{
				if( i == j )
					continue;
				if(value[j] >= s){
					continue;
				}
				else {
					ts += (s - value[j])/total;
				}
			}
			if(ts + mid > 1.0)	{
				high = mid;
			}
			else {
				low = mid;
			}
			System.out.println(low + " " + high + " " + mid);
		}
		return mid*100;
    }

    public static void main(String[] args) throws IOException {
//        Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new FileReader(input));
//        PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter(new FileWriter(input+".out"));
        
        int num = in.nextInt();
        double epsi = 0.000000001;
        for (int i = 0; i < num; i++){
        	int n = in.nextInt();
        	int[] value = new int[n];
        	boolean[] care = new boolean[n];
        	for (int j = 0; j < n; j++)
        		care[j] = true;
        	double total = 0;
        	for (int j = 0; j < n; j++)
        	{
        		value[j] = in.nextInt();
        		total += value[j];
        	}
        	double[] result = new double[n];
        	for(int j = 0; j < n;j++)	{
    			result[j] = get(j, value, epsi, total, n);
    		}
//        	while((result = getResult(value, care, n)) == null);
        	
        	out.write("Case #" + (i+1) + ":");
        	for (int j = 0; j < n; j++)
        		out.printf(" %.6f", result[j]);
        	out.write("\n");
        }
        
        
        out.close();
    }

}
