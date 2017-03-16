package codejam2016.round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ProblemA {
	static BufferedReader buffReader = null;
	static BufferedWriter buffWriter = null;
	static FileReader fileReader = null;
	static FileWriter fileWriter = null;
	static String input_test = "D:/Programming/workspace/test/test.in";
	static String input_small =  "D:/Programming/workspace/test/A-small-attempt0.in";
	static String input_large = "D:/Programming/workspace/test/A-large.in";

	public static final void main(String[] args){
		try {
//			fileReader = new FileReader(input_test);
			fileReader = new FileReader(input_small);
//			fileReader = new FileReader(input_large);
			buffReader = new BufferedReader(fileReader);
			fileWriter = new FileWriter("D:/Programming/workspace/test/problem_A.out");
			buffWriter = new BufferedWriter(fileWriter);

			int total_size = Integer.parseInt(buffReader.readLine());
			//iterate through every input line
			for(int i=1; i<=total_size; i++){
				String in = buffReader.readLine();
				char[] input = in.toCharArray();
				String result = "";
				result = lastWord(input);

				System.out.println("Case #" +i+": "+ result);
				buffWriter.write("Case #" +i+": " + result);
				buffWriter.newLine();
				buffWriter.flush();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				buffWriter.flush();		
				buffWriter.close();
				buffReader.close();
				fileReader.close();
				fileWriter.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private static String lastWord(char[] input) {
		int len = input.length;
//		StringBuilder out = new StringBuilder();
		String str = "";
		char cur = 'A';
		char head = 'A';
		for(int i=0; i<len; i++){

			if(i == 0) {
				cur = input[0]; 
				head = cur;
				str = str + cur;
			
			}else{
				cur = input[i]; 
				if(cur >= head) {
					head = cur;
					str = cur + str;
				}else{
					str = str + cur;
				}
			}
			
		}
		return str;
	}


}
