import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class QualificationB {
	public static void main(String[] args) throws Exception {
		String fileName = "C:\\Users\\Srinivgp\\Documents\\B-large.in";
		List<String> lines = Files.readAllLines(Paths.get(fileName));
		int T = Integer.parseInt(lines.get(0));
		for (int t = 0; t < T; t++) {
			int D = Integer.parseInt(lines.get(t*2+1));
			String[] PString = lines.get(t*2+2).split(" ");
			int[] p = new int[1001];
			for (int i = 0; i < D; i++) {
				p[Integer.parseInt(PString[i])]++;
			}
			int best = 1000;
			for (int m = 1; m <= 1000; m++) {
				int n = 0;
				for (int s = 1; s <= 1000; s++) {
					n += p[s]*(((s + (m-1)) / m) - 1);
				}
				best = Math.min(best, m + n);
			}
			System.out.println("Case #" + (t+1) +": " + best);
		}
    }
}
