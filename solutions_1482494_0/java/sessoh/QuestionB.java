import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.TreeSet;


public class QuestionB {

	public static void doPuzzle() {
		try {
	
			File questionfile = new File("B.in");
			BufferedReader questionreader = new BufferedReader(new FileReader(questionfile));
	
			File answerfile = new File("B.out");
			PrintWriter answerwriter = new PrintWriter(new BufferedWriter(new FileWriter(answerfile)));

			String question = questionreader.readLine();
			String[] params = question.split(" ");
			int T = Integer.parseInt(params[0]);
			
			for (int i = 0; i < T; i++) {
				question = questionreader.readLine();
				params = question.split(" ");
				int N = Integer.parseInt(params[0]);
				int A[] = new int[N];
				int B[] = new int[N];
				for (int j = 0; j < N; j++) {
					question = questionreader.readLine();
					params = question.split(" ");
					A[j] = Integer.parseInt(params[0]);
					B[j] = Integer.parseInt(params[1]);
				}
				answerwriter.println("Case #" + (i+1) + ": " + analyze(N, A, B));
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

	private static String analyze(int N, int[] A, int[] B) {
		int score = 0;
		int answer = 0;
		
		long[] data = new long[N];
		for (int i = 0; i < N; i++) {
			data[i] = B[i] * 65536 + A[i];
		}
		Arrays.sort(data);

		int index = 0;
		while (index < N) {
			if ((data[index] / 65536) <= score) {
				if ((data[index] % 65536) == 65535) score++;
				else score += 2;
				answer++;
				index++;
			} else {
				int i = 0;
				for (i = N-1; i >= index; i--) {
					if ((data[i] % 65536) <= score) {
						score++;
						answer++;
						data[i] |= 65535;
						break;
					}
				}
				if (i < index) return "Too Bad";
			}
		}
		return "" + answer;
	}
}

