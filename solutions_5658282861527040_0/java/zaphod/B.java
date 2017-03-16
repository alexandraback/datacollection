
import java.io.*;
import java.util.Scanner;

public class B
{
        /**
         * @param args
         * @throws IOException
         */
        public static void main(String[] args) throws IOException
        {
                String fileName = "B-small0";
                Scanner in = new Scanner(new File(fileName + ".in"));
                PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

                int noOfCases = in.nextInt();
                for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
                {
                        int A = in.nextInt();
                        int B = in.nextInt();
                        int K = in.nextInt();
                        int noOfWins = 0 ;
                        
                        for (int first = 0; first < A; first++)
                        	for (int second = 0; second < B; second++)
                        	{
                        		int number = first & second;
                        		if (number < K)
                        			noOfWins++;
                        	}
       
                		System.out.printf("Case #%d: %d%n", caseNo , noOfWins);
            			out.printf("Case #%d: %d%n", caseNo , noOfWins);
                }
                in.close();
                out.close();

        }

}
