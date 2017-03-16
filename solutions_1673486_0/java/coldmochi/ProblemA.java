package codejam2012.round1a;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class ProblemA {

    public static void main(String[] args) throws IOException {
        String problem = "ProblemA";
        Scanner in = new Scanner(ClassLoader.getSystemResourceAsStream(String.format("%s.in", problem)));
        PrintStream out = new PrintStream(String.format("C:\\Users\\Terry\\workspace\\GoogleCodeJam\\src\\codejam2012\\round1a\\%s.out", problem));
//        out = System.out;

        int numInputs = in.nextInt();
        for (int i = 0; i < numInputs; i++) {
        	int A = in.nextInt();
        	int B = in.nextInt();
        	double[] prob = new double[A];
        	double allCorrect = 1;
        	for (int j = 0; j < A; j++) {
        		prob[j] = in.nextDouble();
        		allCorrect *= prob[j];
        	}
        	
        	double result = 0d;
        	
        	double option1 = allCorrect * (B - A + 1) + (B - A + 1 + B + 1) * (1 - allCorrect);
        	double option3 = 1 + B + 1;
        	
        	double option2 = Double.MAX_VALUE;
        	for (int j = 0; j < A; j++) {
        		int numDelete = j+1;
        		double correct = 1d;
        		for (int k = 0; k < A - numDelete; k++) {
        			correct *= prob[k];
        		}
        		double temp = (numDelete + (B - A + numDelete) + 1) * correct + (numDelete + (B - A + numDelete) + 1 + B + 1) * (1 - correct);
        		if (temp < option2) {
        			option2 = temp;
        		}
        	}
        	result = Math.min(Math.min(option1, option2), option3);        	
            out.println(String.format("Case #%d: %.6f", (i+1), result));
        }
    }
}
