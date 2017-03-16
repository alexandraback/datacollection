import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class Recycled {
	
	public static void main(String[] args) throws IOException {
		Path input = Paths.get("/Users/mdymczyk/google-codejam/Tongues/src/input.in");
		List<String> lines = Files.readAllLines(input, Charset.forName("UTF-8"));
		lines.remove(0);
		int i = 1;
		for(String line : lines) {
			Set<Pair> pairs = new HashSet<Pair>();
			StringBuilder sb = new StringBuilder();
			sb.append("Case #"+i+": ");
		
			int lower = Integer.parseInt(line.split(" ")[0]); 
			int upper = Integer.parseInt(line.split(" ")[1]); 
			int length = line.split(" ")[0].length();
			
			for(int j = lower ; j <= upper ; j++) {
				for(int k = 1; k < length; k++) {
					int rearranged = rearrangeLastNDigits(j, k);
					if(rearranged != j && (rearranged >= lower && rearranged <= upper)){
						pairs.add(new Pair(j, rearranged));
					}
				}
			}
			sb.append(pairs.size());
			System.out.println(sb);
			i++;
		}
	}

	private static int rearrangeLastNDigits(int j, int k) {
		String stringRepresentation = Integer.toString(j);
		String reordered = stringRepresentation.substring(k, stringRepresentation.length()) + stringRepresentation.substring(0, k);
		return Integer.parseInt(reordered);
	}
	
}

class Pair {
	int n, m;

	public Pair(int n, int m) {
		this.n = n;
		this.m = m;
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * m*n;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pair other = (Pair) obj;
		if (m != other.m && m != other.n)
			return false;
		if (n != other.n && n != other.m)
			return false;
		return true;
	}
}
