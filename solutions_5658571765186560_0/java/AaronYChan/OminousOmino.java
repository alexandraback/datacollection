import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class OminousOmino {

	public static void main (String [] args) throws IOException {
		String fileRoot = "D-small-attempt3";
		String fileName = "C:\\Users\\Aaron\\Downloads\\" + fileRoot + ".in";
		BufferedReader reader = new BufferedReader (new FileReader(new File(fileName)));
		int nTestCases = Integer.parseInt(reader.readLine());
		ArrayList<String> out = new ArrayList<String>();
		for (int t = 0; t < nTestCases; t++) {
			
			String[] parts = reader.readLine().split(" ");
			int n = Integer.parseInt(parts[0]);
			int r = Integer.parseInt(parts[1]);
			int c = Integer.parseInt(parts[2]);
			String ans = null;
			
			switch (n) {
			case 1:
				ans = "GABRIEL";
				break;
			case 2:
				if (r % 2 == 0 || c % 2 == 0) {
					ans = "GABRIEL";
				}
				else ans = "RICHARD";
				break;
			case 3:
				if ((r % 3 == 0 && c % 3 == 0) || (r == 3 && c % 2 == 0) || (r % 2 == 0 && c == 3)) {
					ans = "GABRIEL";
				}
				else ans = "RICHARD";
				break;
			case 4:
				if (r % 4 == 0 && c % 4 == 0 || (r == 4 && c == 3) || (r == 3 && c == 4)) {
					ans = "GABRIEL";
				}
				else {
					ans = "RICHARD";
				}
			}
			System.out.println(ans);
			out.add("Case #" + (t+1) + ": " + ans);
		}
		
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Aaron\\Downloads\\" + fileRoot + "-sol.out")));
		for (String s : out) {
			writer.write(s + "\n");
		}
		
		
		writer.close();
		reader.close();
	}
	
	
}
