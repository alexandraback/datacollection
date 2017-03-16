import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class QuestionC {

	public static void doPuzzle() {
		try {
			
			File questionfile = new File("C.in");
			BufferedReader questionreader = new BufferedReader(new FileReader(questionfile));
	
			File answerfile = new File("C.out");
			PrintWriter answerwriter = new PrintWriter(new BufferedWriter(new FileWriter(answerfile)));

			String[] params = null;
			String question = questionreader.readLine();
			int T = Integer.parseInt(question);
			int[] A = new int[T];
			int[] B = new int[T];
			
			for (int i = 0; i < T; i++) {
				question = questionreader.readLine();
				params = question.split(" ");
				A[i] = Integer.parseInt(params[0]);
				B[i] = Integer.parseInt(params[1]);
			}

			int[] answer = analyze(T, A, B);
			
			for (int i = 0; i < T; i++) {
				answerwriter.println("Case #" + (i+1) + ": " + answer[i]);
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
	
	private static int[] analyze(int T, int[] A, int[] B) {
		
		int[][] blockA = new int[9][T];
		int[][] blockB = new int[9][T];
		int[][] blockT = new int[9][T];
		int[][] blockX = new int[9][T];
		int[] blockLen = new int[9];
		
		for (int i = 0; i < T; i++) {
			int len = String.valueOf(A[i]).length();
			blockA[len][blockLen[len]] = A[i];
			blockB[len][blockLen[len]] = B[i];
			blockT[len][blockLen[len]] = i;
			blockLen[len]++;
		}
		
		for (int i = 1; i <= 20000000; i++) {
			String str = String.valueOf(i);
			int len = str.length();
			StringBuilder sb = new StringBuilder(str);
			for (int j = 1; j < len; j++) {
				sb = sb.append(sb.charAt(0)).deleteCharAt(0);
				int value = Integer.parseInt(sb.toString());
				if (i == value) break;
				for (int k = 0; k < blockLen[len]; k++) {
					if (blockA[len][k] > i) continue;
					if (blockA[len][k] > value) continue;
					if (blockB[len][k] < i) continue;
					if (blockB[len][k] < value) continue;
					blockX[len][k]++;
				}
			}
		}

		int[] answer = new int[T];

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < blockLen[i]; j++) {
				answer[blockT[i][j]] = blockX[i][j] / 2;
			}
		}
		
		return answer;
	}
}

