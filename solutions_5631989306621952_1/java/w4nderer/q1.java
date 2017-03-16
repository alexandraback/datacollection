package r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;


public class q1 {

	public static void main(String[] args) {
		BufferedReader reader = null;
		File file = new File("C:\\Users\\vincent\\workspace\\code jam\\src\\r1a\\A-large.txt");
		File answer = new File("C:\\Users\\vincent\\workspace\\code jam\\src\\r1a\\output.txt");
	    Writer writer = null;
		try{
			reader = new BufferedReader(new FileReader(file));
			writer = new BufferedWriter(new OutputStreamWriter(
		    		new FileOutputStream(answer), "utf-8"));
		    String text = null;
		    
		    text = reader.readLine();
		    int numberOfTestCases = Integer.parseInt(text);
		    int index = 1;

		    while (numberOfTestCases > 0) {
		    	solve(index, reader.readLine(), writer);
		    	numberOfTestCases--;
		        index++;
		    }
		} catch (IOException x) {
		    System.err.format("IOException: %s%n", x);
		} finally {
		    try {
		        if (reader != null) {
		            reader.close();
		        }
		        if (writer != null) {
		        	writer.close();
		        }
		    } catch (IOException e) {
		    }
		}
		System.out.println("done");
	}

	private static void solve(int index, String text, Writer writer) throws IOException {
		String answer = solveHelper(text);
		writer.write("Case #" + String.valueOf(index) + ": " + answer + "\n");
	}

	private static String solveHelper(String text) {
		String answer = "";
		char firstLetter = '\0';
		 for (int i = 0; i < text.length(); i++) {
	    	   char tmpLetter = text.charAt(i);
		       if (firstLetter == '\0') {
		    	   firstLetter = tmpLetter;
		    	   answer += tmpLetter;
		       } else if (firstLetter > tmpLetter) {
		    	   answer += tmpLetter;
		       } else {
		    	   firstLetter = tmpLetter;
		    	   answer = tmpLetter + answer;
		       }
		 }
	   return answer;
	}

}
