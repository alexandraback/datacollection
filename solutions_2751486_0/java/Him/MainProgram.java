import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;


public class MainProgram {

	static BufferedReader in = null;
	static String name;
	static int n;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		in = new BufferedReader(new FileReader("/Users/himanshugupta/workspace/practice/Consonants/A-small-attempt0.in")); 
		int T = Integer.parseInt(in.readLine());
		for (int i=0; i<T; i++){
			readInput();
			System.out.println("Case #"+(i+1)+": "+getOutput());
		}
		in.close();
	}

	public static void readInput() throws IOException{
		String[] strA = in.readLine().split(" ");
		name = strA[0];
		n = Integer.parseInt(strA[1]);
	}
	
	public static int maxConsecutiveConsonants(String str){
		int m = 0, M = 0;
		int length = str.length();
		List<Character> vowels = Arrays.asList('a', 'e', 'i', 'o', 'u');
		for (int i=0; i<length; i++){
			if (vowels.contains(str.charAt(i))){
				M = (m > M) ? m : M;
				m = 0;
			}
			else{
				m++;
			}
		}
		M = (m > M) ? m : M;
		return M;
	}
	
	public static int getOutput(){
		int lengthOfSubstring = n;
		int length = name.length();
		int noOfSubstrings = 0;
		while (lengthOfSubstring <= length){
			for (int i=0; i<=length - lengthOfSubstring; i++){
				if (maxConsecutiveConsonants(name.substring(i, i+lengthOfSubstring)) >= n)
					noOfSubstrings++;
			}
			lengthOfSubstring++;
		}
		return noOfSubstrings;
	}
}
