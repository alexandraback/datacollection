import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;


public class ProblemA {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(
				"A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("outA.txt"));
		int runs = Integer.parseInt(in.readLine());
		
		for (int run = 0; run < runs; run++) {
			String line[] = in.readLine().split(" ");
			int size = Integer.parseInt(line[0]);
			int num_motes = Integer.parseInt(line[1]);
			int moves = 0;
			String motes[] = in.readLine().split(" ");
			ArrayList<Integer> array = new ArrayList<Integer>(num_motes);
			for (int i = 0  ; i< num_motes ; i++) {
				array.add(Integer.parseInt(motes[i]));
			}
			Collections.sort(array);
			int dd = -1;
			for (int i = 0  ; i< num_motes ; i++) {
				
				if (dd != -1) {
				for (int d = dd; d < i; d++) {
					if (size > array.get(d)) {
						size += array.get(d);
						dd++;
					}
					else {
						break;
					}
				}
				}
					if (size > array.get(i)) {
						size += array.get(i);
						dd = -1;
					}
					else if (2*size -1 > array.get(i)) {
						size += size -1 + array.get(i);
						dd = -1;
						moves++;
					}
					else {
						size += size -1;
						if (dd == -1)
							dd = i;
						moves ++;
					}
				

				
			}
			out.println("Case #" + (run + 1) + ": " + moves);
		}
		in.close();
		out.close();

	}
}
