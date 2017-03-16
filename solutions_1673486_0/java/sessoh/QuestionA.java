import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class QuestionA {

	public static void doPuzzle() {
		try {
	
			File questionfile = new File("A.in");
			BufferedReader questionreader = new BufferedReader(new FileReader(questionfile));
	
			File answerfile = new File("A.out");
			PrintWriter answerwriter = new PrintWriter(new BufferedWriter(new FileWriter(answerfile)));

			String question = questionreader.readLine();
			String[] params = question.split(" ");
			int T = Integer.parseInt(params[0]);
			
			for (int i = 0; i < T; i++) {
				question = questionreader.readLine();
				params = question.split(" ");
				int A = Integer.parseInt(params[0]);
				int B = Integer.parseInt(params[1]);
				question = questionreader.readLine();
				params = question.split(" ");
				double[] P = new double[A];
				for (int j = 0; j < A; j++) {
					P[j] = Double.parseDouble(params[j]);
				}
				answerwriter.println("Case #" + (i+1) + ": " + analyze(A, B, P));
			}
			
			answerwriter.close();
			questionreader.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}

	private static double analyze(int A, int B, double[] P) {
		// pattern 4
		double answer = 1.0 + B + 1.0;

		// pattern 1
		double probablity = 1.0;
		for (int i = 0; i < A; i++) probablity *= P[i];
		double expectation = ((B - A) + 1.0) * probablity + ((B - A) + 1.0 + B + 1.0) * (1.0 - probablity);
		answer = Math.min(answer, expectation);
		
		// pattern 2
		expectation = A + B + 1.0;
		answer = Math.min(answer, expectation);

		// pattern n
		probablity = 1.0;
		for (int i = 1; i < A; i++) {
			probablity *= P[i-1];
			expectation = ((A - i) + (B - i) + 1.0) * probablity + ((A - i) + (B - i) + 1.0 + B + 1.0) * (1.0 - probablity);
			answer = Math.min(answer, expectation);
		}
		return answer;
	}
}

