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

			String[] params = null;
			String question = questionreader.readLine();
			int T = Integer.parseInt(question);
			
			char[] table = makeTable();
			
			for (int i = 0; i < T; i++) {
				question = questionreader.readLine();
				answerwriter.println("Case #" + (i+1) + ": " + analyze(table, question));
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

	private static char[] makeTable() {
		String before = "qz"
				+ "ejp mysljylc kd kxveddknmc re jsicpdrysi"
				+ "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
				+ "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String after  = "zq"
				+ "our language is impossible to understand"
				+ "there are twenty six factorial possibilities"
				+ "so it is okay if you want to just give up";

		char[] charTableB = new char[128];
		char[] charTableA = new char[128];
		
		for (int i = 0; i < charTableB.length; i++) charTableB[i] = '#';
		charTableB[' '] = ' ';
		for (int i = 0; i < charTableA.length; i++) charTableA[i] = '*';
		charTableA[' '] = ' ';
		
		for (int i = 0; i < before.length(); i++) {
			charTableB[after.charAt(i)] = before.charAt(i);
			charTableA[before.charAt(i)] = after.charAt(i);
		}
		
		System.out.println("abcdefghijklmnopqrstuvwxyz");
		for (int i = 'a'; i <= 'z'; i++) System.out.print(charTableB[i]);
		System.out.println();
		
		System.out.println("abcdefghijklmnopqrstuvwxyz");
		for (int i = 'a'; i <= 'z'; i++) System.out.print(charTableA[i]);
		System.out.println();
		
		return charTableA;
		
	}
	private static String analyze(char[] table, String question) {
		String answer = "";
		for (int i = 0; i < question.length(); i++) answer += table[question.charAt(i)];
		return answer;
	}
}

