

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.stream.IntStream;

public class ProblemB2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			
			int D = readInt();
			int[] plates = readInts();
			
			SortedMap<Integer, Integer> platesMap = new TreeMap<Integer, Integer>();
			for (int p : plates) {
				if (!platesMap.containsKey(p)) {
					platesMap.put(p,1);
				} else {
					platesMap.put(p,platesMap.get(p)+1);
				}
			}
			
			int best = platesMap.lastKey();
			
			for (int threshold=1; threshold<best; threshold++) {
				int splits = 0;
				for (int p : platesMap.tailMap(threshold+1).keySet()) {
					splits += ((int)Math.ceil((double)p / threshold) - 1) * platesMap.get(p);
					if (splits+threshold>=best) break;
				}
				if (splits + threshold < best) best = splits + threshold;
			}
			
			
			System.out.println(String.format("Case #%d: %d", caseNum+1, best));
		}

	}
	
	
	
	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
}
