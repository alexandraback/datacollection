import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;


public class User {


		public static class LastWord {

			public static String doTest(String line) {
				LinkedList<Character> word = new LinkedList<Character>();
				char[] chars = line.toCharArray();
				for (char theChar : chars){
					if (word.isEmpty()){
						word.addFirst(theChar);
					} else if (theChar >= word.getFirst().charValue()){
						word.addFirst(theChar);
					} else {
						word.addLast(theChar);
					}
				}
				
				StringBuffer result = new StringBuffer();
				for (Character theChar: word){
					result.append(theChar);
				}
				
				return result.toString();
			}

	}

		private static final String FILENAME = "A-large.in";
		private static final String OUTFILENAME = FILENAME.substring(0,FILENAME.lastIndexOf("."))+".out";
		public static String newline = System.getProperty("line.separator");

		private static PrintWriter out;
		private static BufferedReader input;
		
		public static void main(String[] args) throws IOException {
			setupIO();
			
			int T = Integer.parseInt(input.readLine());
			
			for (int t=1; t<=T; t++){
				String line = input.readLine();
				String result = LastWord.doTest(line);
				out.println("Case #" + t + ": " +result);
				System.out.println("Case #" + t + ": " +result);
			}
			out.close();
		}
		
		private static void setupIO() throws IOException{
			out = new PrintWriter(new FileWriter(OUTFILENAME));
			//	PrintStream out = System.out;
				
				FileReader fr = null;
				try {
					fr = new FileReader(FILENAME);
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}
				input = new BufferedReader(fr);
		}
	}


