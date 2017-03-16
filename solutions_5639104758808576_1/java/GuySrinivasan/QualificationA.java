import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class QualificationA {
	public static void main(String[] args) throws Exception {
		String fileName = "C:\\Users\\Srinivgp\\Documents\\A-large.in";
		List<String> lines = Files.readAllLines(Paths.get(fileName));
		int T = Integer.parseInt(lines.get(0));
		for (int t = 0; t < T; t++) {
			String[] parts = lines.get(t+1).split(" ");
			int maxSi = Integer.parseInt(parts[0]);
			int c = 0;
			int n = 0;
			for (int i = 0; i <= maxSi; i++) {
				int si = Integer.parseInt(parts[1].charAt(i)+"");
				n += si == 0 ? 0 : Math.max(0, i - (c + n));
				c += si;
			}
			System.out.println("Case #" + (t+1) +": " + n);
		}
    }
}		
