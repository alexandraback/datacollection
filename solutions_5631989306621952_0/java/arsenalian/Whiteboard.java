import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Whiteboard {
	public static void main (String[] args) throws IOException {
		FileReader fin = new FileReader("WhiteboardInput.txt");
		BufferedReader bin = new BufferedReader (fin);
		int t = Integer.parseInt(bin.readLine());
		FileWriter fout = new FileWriter("WhiteboardOutput.txt");
		BufferedWriter bout = new BufferedWriter(fout);
		PrintWriter pout = new PrintWriter(bout);
		for (int i = 0; i < t; i++) {
			String s = bin.readLine();
			String answer = ""+s.charAt(0);
			for (int j = 1; j < s.length(); j++) {
				char x = s.charAt(j);
				if (x >= answer.charAt(0)) {
					answer = x + answer;
				}
				else {
					answer = answer + x;
				}
			}
			pout.println("Case #"+(i+1)+": "+answer);
		}
		pout.close();
	}
}
