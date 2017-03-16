import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;


public class P1 {
	//private static final String vowels = "aeiou";
	public static void main(String[] args){
		BufferedReader inputStream = null;
		PrintWriter outputStream = null;

		File inputfile = new File("C:/users/Kevin/Desktop/A-small-attempt0.in");
		File outputFile = new File ("C:/users/Kevin/Desktop/P1.txt");
		try{
			inputStream = new BufferedReader(new FileReader(inputfile));
			outputStream = new PrintWriter(new FileWriter(outputFile));

			int num_cases = Integer.valueOf(inputStream.readLine()); //Grabs the # on the first line.
			for (int i=1; i<=num_cases; i++){
				StringBuffer sb = new StringBuffer("Case #" + i + ": ");
				String[] name_n = inputStream.readLine().split(" ");
				String name = name_n[0];
				int n = Integer.valueOf(name_n[1]);
				int outcome = findSolution(name, n);
				sb.append(outcome + "\n");
				outputStream.write(sb.toString());
			}	
		}catch (Exception e){
			e.printStackTrace();
		}finally{
			try {
				inputStream.close();
				outputStream.close();
			} catch (IOException e) {
				e.printStackTrace();
			}	
		}
	}
	public static int findSolution(String name, int n){
		int length = name.length();
		/*int vowels = 0;
		for (int i=0; i<name.length(); i++){
			if (name.charAt(i) == 97 ||
					name.charAt(i) == 101 ||
					name.charAt(i) == 105 ||
					name.charAt(i) == 111 ||
					name.charAt(i) == 117)
				vowels++;
		}
		int consonants = length - vowels;*/
		ArrayList<String> substrings = new ArrayList<String>();
		int val = 0;
		for (int i = 0; i < length - n + 1; i++){	
			for (int j = i+n-1; j < length; j++){
				String substring = name.substring(i, j+1);
				
				if (qualifies(substring, n))
					val++;
			}
		}
		return val;
	}
	public static boolean qualifies(String s, int n){
		int cons = 0;
		for (int i=0; i<s.length(); i++){
			if (s.charAt(i) == 97 ||
					s.charAt(i) == 101 ||
					s.charAt(i) == 105 ||
					s.charAt(i) == 111 ||
					s.charAt(i) == 117){
				cons = 0;
			}
			else {
				cons++;
			}
			if (cons >= n)
				return true;
		}
		System.out.println(s + "   cons = " + cons);
		
		return false;
	}
	
}
