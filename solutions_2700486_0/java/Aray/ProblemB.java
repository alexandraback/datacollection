import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;


public class ProblemB {
	public static void main(String[] args) throws IOException {
		//BufferedReader in = new BufferedReader(new FileReader("B.in"));
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new FileWriter("outB.txt"));
		int runs = Integer.parseInt(in.readLine());
		
		int pyramid[] = new int[1000];
		pyramid[0] = 1;
		int index = 1;
		int level = 1;
		while (pyramid[index - 1] < 1000000) {
			pyramid[index] = pyramid[index - 1] + 2*level + 3;
			level +=2;
			index++;
		}
		DecimalFormat df = new DecimalFormat("0.0#####");
		for (int run = 0; run < runs; run++) {
			String line[] = in.readLine().split(" ");
			int diamonds = Integer.parseInt(line[0]);
			int x = Math.abs(Integer.parseInt(line[1]));
			int y = Integer.parseInt(line[2]);
			int closest;
			for (closest = 0 ; closest < index ; closest++) {
				if (diamonds < pyramid[closest]) {
					closest--;
					break;
				}
			}
			System.out.println (closest);
			if (x + y <= closest * 2) {
				out.println("Case #" + (run + 1) + ": 1.0");
			}
			else if (x + y == (closest+1) *2) {
				int extra = diamonds - pyramid[closest];
				
				if (extra <= (closest+1) * 2) {
					double total = 0;
					double cur = 1.0;
					for (int j = 0; j < extra; j++) {
						cur *=0.5;
						if (j >= y)
							total += cur;
					}
					out.println("Case #" + (run + 1) + ": " + df.format(total));
				}
				else {
					double total = 0;
					double cur = 1.0;
					int over = extra - (closest+1) * 2;
					System.out.println ("close " + closest + "      extra" + extra + "   over" + over);
					if (over - 1 >=y )
						out.println("Case #" + (run + 1) + ": 1.0");
					else {
						for (int j = over; j < (closest+1) * 2; j++) {
							cur *=0.5;
							if (j >= y)
								total += cur;
						}
						out.println("Case #" + (run + 1) + ": " + df.format(total));
					}
					
				}
			} else
			out.println("Case #" + (run + 1) + ": 0.0");
		}
		in.close();
		out.close();

	}
}
