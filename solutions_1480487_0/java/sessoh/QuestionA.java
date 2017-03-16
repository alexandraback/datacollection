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
				int N = Integer.parseInt(params[0]);
				long[] S = new long[N];
				for (int j = 0; j < N; j++) S[j] = Long.parseLong(params[j+1]);
				long total = 0;
				for (int j = 0; j < N; j++) total += S[j];
				answerwriter.print("Case #" + (i+1) + ":");
				for (int j = 0; j < N; j++) {
					double answer = Math.max(0.0, 100.0*((double)total * 2 / N - S[j])/total);
					answerwriter.print(" "+answer);
				}
				answerwriter.println();
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
}
