import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Jam1 {

	
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		FileWriter fstream = new FileWriter("jam1.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		int T = scan.nextInt();
		
		for (int k = 0; k < T; k++) {
			long r = scan.nextLong();
			long t = scan.nextLong();
			long area = 2 * r +1;
			long count = 0;
			while(true) {
				if(t - area >= 0) {
					count++;
					t -= area;
					area += 4;
				}
				else {
					break;
				}
			}
			out.write("Case #" + (k+1) + ": " + count);
			out.write("\n");
		}

		out.close();
	}

}
