import java.util.*;
import java.io.*;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/A-small-attempt2.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
            int A = input.nextInt();
            int B = input.nextInt();
            double[] pr = new double[A];
            for(int j = 0 ; j < pr.length ; j++){
            	pr[j] = input.nextDouble();
            }
            pw.println("Case #"+(i+1)+": "+num(A,B,pr));
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static double num(int A,int B,double[] pr){
    	double keeptype = 0.0;
    	double bstype = 999999999;
    	double retype = 0.0;
    	
    	double keepseki = 1;
    	for(int i = 0 ; i < pr.length ; i++){
    		keepseki *= pr[i];
    	}
    	keeptype = keepseki*(B-A+1)+(1-keepseki)*(2*B-A+2);
    	
    	retype = B+2;
    	
    	for(int i = 1 ; i <= A ; i++){
    		keepseki = 1;
    		for(int j = 0 ; j < A-i ; j++){
    			keepseki *= pr[j];
    		}
    		bstype = Math.min(bstype,keepseki*(B-A+2+i)+(1-keepseki)*(2*B-A+3+i));
    	}
    	
    	return Math.min(Math.min(keeptype,bstype),retype);

    }
}
