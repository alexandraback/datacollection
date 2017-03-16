import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				String line = br.readLine();
				BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
				int tests = Integer.valueOf(line.trim());
				for (int i = 0; i < tests; i++) {
					String[] numbers = br.readLine().split(" ");
					int a = Integer.valueOf(numbers[0]);
					int b = Integer.valueOf(numbers[1]);
					String[] probs = br.readLine().split(" ");
					double lowest = b + 2;
					double correctProb = 1;
					for (int j = 0; j < a; j++) {
						correctProb = correctProb * Double.valueOf(probs[j]);
						double cur = (b + 1)*(1-correctProb) + b - a + 1 + 2*(a - j - 1);
						if (cur < lowest) {
							lowest = cur;
						}
					}
					out.write("Case #"+ (i + 1) +": " + String.format("%.6f\n", lowest).replace(",", "."));
				}
				out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}