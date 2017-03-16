import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class QuestionB {
	
	public static void doPuzzle() {

		try {
	
			File questionfile = new File("B.in");
			BufferedReader questionreader = new BufferedReader(new FileReader(questionfile));
	
			File answerfile = new File("B.out");
			PrintWriter answerwriter = new PrintWriter(new BufferedWriter(new FileWriter(answerfile)));

			String[] params = null;
			String question = questionreader.readLine();
			int T = Integer.parseInt(question);
			
			int[][] table = makeTable();
			
			for (int i = 0; i < T; i++) {
				question = questionreader.readLine();
				params = question.split(" ");
				int N = Integer.parseInt(params[0]);
				int S = Integer.parseInt(params[1]);
				int p = Integer.parseInt(params[2]);
				int[] t = new int[N];
				for (int j = 0; j < N; j++) t[j] = Integer.parseInt(params[3+j]);
				answerwriter.println("Case #" + (i+1) + ": " + analyze(table, N, S, p, t));
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

	private static int[][] makeTable() {
		int[][] scoreTable = new int[31][11];
		for (int i = 0; i < 31; i++) {
			if (i == 0) {
				for (int j = 0; j < 1; j++) scoreTable[i][j] = 2;
				for (int j = 1; j < 11; j++) scoreTable[i][j] = 0;
				continue;
			}
			if (i == 1) {
				for (int j = 0; j < 2; j++) scoreTable[i][j] = 2;
				for (int j = 2; j < 11; j++) scoreTable[i][j] = 0;
				continue;
			}
			if (i >= 28) {
				for (int j = 0; j < 11; j++) scoreTable[i][j] = 2;
				continue;
			}
			int shou = i / 3;
			int amari = i % 3;
			switch (amari) {
			case 0:
				for (int j = 0; j < shou+1; j++) scoreTable[i][j] = 2;
				scoreTable[i][shou+1] = 1;
				for (int j = shou+2; j < 11; j++) scoreTable[i][j] = 0;
				break;
			case 1:
				for (int j = 0; j < shou+2; j++) scoreTable[i][j] = 2;
				for (int j = shou+2; j < 11; j++) scoreTable[i][j] = 0;
				break;
			case 2:
				for (int j = 0; j < shou+2; j++) scoreTable[i][j] = 2;
				scoreTable[i][shou+2] = 1;
				for (int j = shou+3; j < 11; j++) scoreTable[i][j] = 0;
				break;
			}
			
		}
		
		return scoreTable;
	}
	
	private static int analyze(int[][] table, int N, int S, int p, int[] t) {
		int[] count = new int[3];
		for (int i = 0; i < t.length; i++) {
			count[table[t[i]][p]]++;
		}
		int border = (count[1] < S) ? count[1] : S;
		
		return count[2] + border;
	}
}

