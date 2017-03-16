import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				String line = br.readLine();
				BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
				int tests = Integer.valueOf(line.trim());
				for (int i = 0; i < tests; i++) {
					int n = Integer.valueOf(br.readLine());
					Set<int[]> elems = new HashSet<int[]>(); 
					for (int j = 0; j < n; j++) {
						String[] values = br.readLine().split(" ");
						elems.add(new int[]{Integer.valueOf(values[0]), Integer.valueOf(values[1])});
					}
					Set<int[]> possibleTurns = new HashSet<int[]>(); 
					int result = 0;
					int stars = 0;
					boolean found;
					while (true) {
						found = false;
						for (Iterator<int[]> iterator = elems.iterator(); iterator
								.hasNext();) {
							int[] js = iterator.next();
							if (js[0] <= stars) {
								iterator.remove();
								possibleTurns.add(js);
							}
						}
						int[] best = null;
						for (Iterator<int[]> iterator = possibleTurns.iterator(); iterator
								.hasNext();) {
							int[] js = iterator.next();
							if (js[1] == -1) {
								iterator.remove();
								result++;
								stars++;
								found = true;
							}
							else if (js[1] <= stars) {
								iterator.remove();
								result++;
								stars +=2;
								found = true;
							}
							
							if (found) {
								break;
							}
							else {
								if (best == null || best[1] < js[1]) {
									best = js;
								}
							}
						}
						if (!found && best != null) {
							possibleTurns.remove(best);
							elems.add(new int[]{best[1], -1});
							stars++;
							result++;
							found = true;
						}
						
						if (!found || (possibleTurns.isEmpty() && elems.isEmpty())) {
							break;
						}
					}
					String strResult;
					if (found) {
						strResult = String.valueOf(result);
					}
					else {
						strResult = "Too Bad";
					}
					out.write("Case #"+ (i + 1) +": " + strResult + "\n");
				}
				out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}