
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.*;

/**
 *
 * @author
 */
public class Q1{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
    	        Q1 p = new Q1();
        p.start();

    }

    public void start() throws Exception{
        // TODO code application logic here
        Scanner inFile = new Scanner(new File("A-small-practice.in"));
        PrintWriter outFile = new PrintWriter(new File("smallout.file"));
        //Scanner inFile = new Scanner(new File("A-large-practice.in"));
        //PrintWriter outFile = new PrintWriter(new File("largeout.file"));

        int caseN =inFile.nextInt();
        System.out.println("Number of Case  "+caseN);

 		for(int i = 1; i<caseN+1; i++){

 			int A = inFile.nextInt();
 			int B = inFile.nextInt();
 			double p[] = new double[A];
 			double St[] = new double[A+2];
			double product = 1;

 			for(int j =0;j<A;j++){
 				p[j] = Double.parseDouble(inFile.next());
 				product *=p[j];
 			}

			double minExp =0;
			St[0] = 2+B;
			minExp = St[0];

			for(int t= 1; t<=A;t++){
				double temp = product + product/p[A-t]*(1-p[A-t]);
				St[t]=(2*t+B-A+1)*temp+ (2*t+B-A+1+B+1)*(1-temp);
				if (minExp>St[t]) minExp = St[t];
			}

			St[A+1] = (B-A+1)*product + (B-A+1+B+1)*(1-product);
			if (minExp>St[A+1]) minExp = St[A+1];


            System.out.println("Case #"+i+": "+minExp);
            outFile.println("Case #"+i+": "+minExp);
        }

        //close the file
         inFile.close();
         outFile.close();


       }
}
