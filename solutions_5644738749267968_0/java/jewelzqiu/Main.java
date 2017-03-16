import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new FileReader("input"));
			PrintWriter writer = new PrintWriter(new BufferedWriter(
					new FileWriter("output")));
			int n = Integer.valueOf(reader.readLine());
			int count, right, current, score;
			double[] a, b;
			String msg;
			StringTokenizer tokenizer;
			for (int i = 0; i < n; i++) {
				msg = "Case #" + (i + 1) + ": ";
				count = Integer.valueOf(reader.readLine());
				
				a = new double[count];
				tokenizer = new StringTokenizer(reader.readLine());
				for (int j = 0; j < count; j++) {
					a[j] = Double.valueOf(tokenizer.nextToken());
				}
				Arrays.sort(a);
				b = new double[count];
				tokenizer = new StringTokenizer(reader.readLine());
				for (int j = 0; j < count; j++) {
					b[j] = Double.valueOf(tokenizer.nextToken());
				}
				Arrays.sort(b);
				
				// Deceitful War
				right = count - 1;
				current = right;
				score = 0;
				while (current >= 0) {
					if (a[right] > b[current]) {
						score++;
						right--;
						current--;
					} else {
						current--;
					}
				}
				msg += score + " ";
				
				// War
				right = count - 1;
				current = right;
				score = 0;
				while (current >= 0) {
					if (a[current] > b[right]) {
						score++;
						current--;
					} else {
						right--;
						current--;
					}
				}
				msg += score + "\n";
				
				writer.print(msg);
			}
			
			reader.close();
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
