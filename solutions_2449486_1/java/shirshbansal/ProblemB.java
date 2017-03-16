import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class ProblemB {
	public static void main(String...args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		for(int i = 0; i < t; i++) {
			PriorityQueue<Block> pQueue = new PriorityQueue<Block>(10000, new BlockComparator());
			int n = scan.nextInt();
			int m = scan.nextInt();
			int a[][] = new int[n][m];
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < m; k++) {
					pQueue.offer(new Block(scan.nextInt(), j, k));
				}
			}
			System.out.println(calcResult(i+1, pQueue));
		}
	}

	private static String calcResult(int testCase, PriorityQueue<Block> pQueue) {
		boolean row[] = new boolean[100];
		boolean column[] = new boolean[100];
		int rowHeight[] = new int[100];
		int columnHeight[] = new int[100]; 
		
		while(!pQueue.isEmpty()) {
			Block block = pQueue.poll();
			if(row[block.i] && column[block.j] && rowHeight[block.i] > block.h && columnHeight[block.j] > block.h) return "Case #" + testCase + ": NO";
			if(!row[block.i]) rowHeight[block.i] = block.h;
                        if(!column[block.j]) columnHeight[block.j] = block.h;

			row[block.i] = true;
			column[block.j] = true;
		}
		
		return "Case #" + testCase + ": YES";
	}	
}

class Block {
	int h;
	int i;
	int j;
	Block(int h, int i, int j) {
		this.i = i;
		this.j = j;
		this.h = h;
	}
	public String toString() {
		return i + " " + j + " " + h;
	}
}

class BlockComparator implements Comparator<Block> {

	@Override
	public int compare(Block o1, Block o2) {
		if(o1.h > o2.h) return -1;
		if(o1.h < o2.h) return 1;
		return 0;
	}		
}
