import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;


public class LastWord {
	public static void main(String[] args) throws IOException{
		Scanner kb = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("lastword.out"));
		//PrintStream out = System.out;
		int cases = kb.nextInt();
		for(int n=0; n < cases; n++) {
			out.print("Case #" + (n + 1) + ": ");
			
			String word = kb.next();
			String newWord = "";
			
			for(int i=0; i < word.length(); i++) {
				char c = word.charAt(i);
				
				int j=0;
				while (j < newWord.length() && c == newWord.charAt(j))
					j++;
				
				if (j == newWord.length() || (c < newWord.charAt(j)))
					newWord += c;
				else
					newWord = c + newWord;
			}
			
			out.print(newWord);
			out.println();
		}
		out.close();
	}
}
