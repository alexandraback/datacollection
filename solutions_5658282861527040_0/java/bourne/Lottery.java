import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Lottery {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File("l_1.in")));
		PrintWriter writer = new PrintWriter(new File("l.txt"));
		int t = Integer.parseInt(reader.readLine());
		for(int i=0; i<t; i++) {
			String[] abk = reader.readLine().split(" ");
			int a = Integer.parseInt(abk[0]);
			int b = Integer.parseInt(abk[1]);
			int k = Integer.parseInt(abk[2]);
			int d = go(a, b, k);
			writer.write("Case #"+(i+1) + ": " + d+"\n");
		}
		reader.close();
		writer.close();
	}
	
	public static int go(int a, int b, int k) {
		int t = 0;
		for(int i=0; i<a; i++) {
			for(int j=0; j<b; j++) {
				if((i&j) < k) {
					t++;
				}
			}
		}
		return t;
	}
}
