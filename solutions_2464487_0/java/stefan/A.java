import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {
	public static final String FILENAME = "A-small-attempt0";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		for(int i = 1; i <= T; i++) {
			long r = s.nextLong();
			long t = s.nextLong();
			int ret = -1;
			while(t >= 0) {
				t -= 2*r+1;
				r += 2;
				ret++;
			}
			out.write("Case #"+i+": "+ret+"\n");
		}
		in.close();
		out.close();
	}
}
