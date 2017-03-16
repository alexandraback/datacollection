import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;


public class Problem1 {
	public static boolean notvowel(char s){
		return s != 'a' && s != 'e' && s != 'i' && s!= 'o' && s != 'u';
	}
	
	public static long count(String s, int n){
		long result = 0;
		ArrayList<Integer> consonants = new ArrayList<Integer>();
		for(int i = 0; i < s.length(); i++){
			boolean isconsecutive = true;
			if(notvowel(s.charAt(i))){
				for(int j = 0; j < n; j++){
					if(i+j >= s.length()){
						isconsecutive = false;
						break;
					}
					if(!notvowel(s.charAt(i+j))){
						isconsecutive = false;
						break;
					}
				}
				if(isconsecutive){
					consonants.add(i);
				}
			}
		}
		System.out.println(consonants);
		for(int i = 0; i < s.length(); i++){
			if(consonants.isEmpty()){
				break;
			} else {
				result = result + s.length() - consonants.get(0) - n +1;
				if(i == consonants.get(0)){
					consonants.remove(0);
				}
			}
		}
		return result;
	}
	
	public static void main(String[] args) {
		FileReader input;
		try {
			input = new FileReader("A-small-attempt0.in.txt");
			BufferedReader reader = new BufferedReader(input);
			PrintStream out = new PrintStream(
					new FileOutputStream("output.txt"));
			int test = Integer.parseInt(reader.readLine());
			for (int k = 1; k <= test; k++) {
				// Solution here
				Scanner scanner = new Scanner(reader.readLine());
				String s = scanner.next();
				int n = scanner.nextInt();
				long result = count(s,n);
				out.println("Case #" + k + ": "+result);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
