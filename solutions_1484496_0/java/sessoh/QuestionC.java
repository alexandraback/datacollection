import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;

public class QuestionC {

	public static void doPuzzle() {
		try {
	
			File questionfile = new File("C.in");
			BufferedReader questionreader = new BufferedReader(new FileReader(questionfile));
	
			File answerfile = new File("C.out");
			PrintWriter answerwriter = new PrintWriter(new BufferedWriter(new FileWriter(answerfile)));

			String question = questionreader.readLine();
			String[] params = question.split(" ");
			int T = Integer.parseInt(params[0]);
			
			for (int i = 0; i < T; i++) {
				question = questionreader.readLine();
				params = question.split(" ");
				int N = Integer.parseInt(params[0]);
				long[] S = new long[N];
				for (int j = 0; j < N; j++) {
					S[j] = Integer.parseInt(params[j+1]);
				}
				answerwriter.println("Case #" + (i+1) + ": " + analyze(N, S));
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
	
	public static String analyze(int N, long[] S) {
		HashMap<Long,String> hm = new HashMap<Long,String>();
		String answer = null;
		for (int i = 0; i < N; i++) {
			if ((answer = makePair(N, S, hm, 0, null, i+1, 0)) != null)
				return answer;
		}
		return "Impossible";
		
	}
	
	public static String makePair(int N, long[]S, HashMap<Long,String> hm, long value, String pair, int x, int y) {
		if (x == 0) {
			if (hm.get(value) == null) {
				hm.put(value, pair);
				return null;
			} else {
				return "\n" + hm.get(value) + "\n" + pair;
			}
			
		} else {
			for (int i = y; i < N; i++) {
				String newpair = null;
				if (pair == null) newpair = Long.toString(S[i]);
				else newpair = pair + " " + Long.toString(S[i]);
				String answer =  makePair(N, S, hm, value+S[i], newpair, x-1, i+1);
				if (answer != null) return answer;
			}
			return null;
		}
	}

}
