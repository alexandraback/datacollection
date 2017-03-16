import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class DancingWithGooglers {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		System.setErr(new PrintStream("qualification/B-small-attempt0.out"));
		FileReader reader = new FileReader("qualification/B-small-attempt0.in");
		BufferedReader br = new BufferedReader(reader);
		int tc = Integer.parseInt(br.readLine());
		for (int t = 0; t < tc; t++) {
			String[] line = br.readLine().split("\\s");
			int n = Integer.parseInt(line[0]);
			int s = Integer.parseInt(line[1]);
			int p = Integer.parseInt(line[2]);
			//System.out.println("s=" + s);
			//System.out.println("p=" + p);
			int answer = 0;
			for (int j = 0; j < n; j++) {
				int total = Integer.parseInt(line[j + 3]);
				int avg = total / 3;
				int remain = total % 3;
				int max = remain > 0 ? avg + 1 : avg;
				//System.out.println("max=" + max + "(" + avg + ")");
				if (max >= p) {
					answer ++;
				} else if (s > 0) {
					switch (remain) {
					case 2:
						if (avg >= p - 2) {
							s--;
							answer++;
						}						
						break;
					case 1:
					default:
						if (avg > 0 && avg == p - 1) {
							s--;
							answer++;							
						}
					}
				}
			}
			System.out.printf("Case #%d: %d\n", t + 1, answer);
			System.err.printf("Case #%d: %d\n", t + 1, answer);
		}
	}

}
