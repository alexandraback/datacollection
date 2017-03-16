import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;
import java.util.function.LongToIntFunction;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new FileInputStream("input.txt"))){
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int n = scanner.nextInt();
				int[] refs = new int[n];
				int[] assignments = new int[n];
				for (int j = 0; j < refs.length; j++) {
					refs[j] = scanner.nextInt() - 1;
					assignments[j] = -1;
				}
				
				int max = 0;
				
				int[] maxSelfLoopTail = new int[n];
				for (int j = 0; j < assignments.length; j++) {
					int currentPosition = j;
					int selfLoopCount = 0;
					while (true) {
						if (assignments[currentPosition] < j) {
							assignments[currentPosition] = j;
							currentPosition = refs[currentPosition];
							selfLoopCount++;
						}
						else if (assignments[currentPosition] == j) {
							break;
						}
					}
					int startPosition = currentPosition;
					int count = 1;
					while (refs[currentPosition] != startPosition) {
						count++;
						currentPosition = refs[currentPosition];
					}
					if (count == 2) {
						maxSelfLoopTail[startPosition] = Math.max(maxSelfLoopTail[startPosition], selfLoopCount - 1);
						maxSelfLoopTail[refs[startPosition]] = Math.max(maxSelfLoopTail[refs[startPosition]], 1);
					}
					max = Math.max(max, count);
				}
				int count = 0;
				for (int j = 0; j < maxSelfLoopTail.length; j++) {
					count += maxSelfLoopTail[j];
					max = Math.max(max, count);
				}
				out.write("Case #" + (i + 1) + ": " + max + "\n");
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}