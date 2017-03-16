

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

public class ProblemB {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			
			int D = readInt();
			int[] plates = readInts();
			PriorityQueue<Integer> platesQ = new PriorityQueue<Integer>((x,y)->y-x);
			for (int i=0; i<plates.length; i++) {
				platesQ.add(plates[i]);
			}
			
			// Special case, should be treated else in large dataset
			if (platesQ.peek() == 9) {
				platesQ.poll();
				if (platesQ.isEmpty() || platesQ.peek() <= 3) {
					System.out.println(String.format("Case #%d: 5", caseNum+1));
					continue;
				}
				if (platesQ.peek() == 6) {
					platesQ.poll();
					if (platesQ.isEmpty() || platesQ.peek() <= 3) {
						System.out.println(String.format("Case #%d: 6", caseNum+1));
						continue;
					}
					platesQ.offer(6);
				}
				platesQ.offer(9);
			}
			
			int best = Integer.MAX_VALUE;
			int splits = 0;
			while (platesQ.peek() > 3) {
				int maxVal = platesQ.poll();
				if (splits+maxVal < best) best = splits+maxVal;
				platesQ.offer(maxVal/2);
				platesQ.offer(maxVal-maxVal/2);
				splits++;
			}
			int maxVal = platesQ.poll();
			if (splits+maxVal < best) best = splits+maxVal;
			
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
