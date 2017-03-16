import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Graph {
	public List<List<Integer>> xToY;
	public List<List<Integer>> yToX;
	
	public Graph() {
		xToY = new ArrayList<List<Integer>>();
		yToX = new ArrayList<List<Integer>>();
	}
	
	public void addEdge(int x, int y) {
		while (xToY.size() <= x) {
			xToY.add(new ArrayList<Integer>());
		}
		
		xToY.get(x).add(y);
		
		while (yToX.size() <= y) {
			yToX.add(new ArrayList<Integer>());
		}
		
		yToX.get(y).add(x);
	}
}

public class C {
	private static boolean match(Graph graph, int size) {
//		System.out.println("-- match");
		
		int[] xTo = new int[size];
		int[] yTo = new int[size];
		int matched = 0;
		
		for (int i = 0; i < size; i++) {
			xTo[i] = -1;
			yTo[i] = -1;
		}
		
		// pick up a bunch of easy wins
		
		for (int i = 0; i < size; i++) {
			if (xTo[i] == -1) {
				if (i < graph.xToY.size()) {
					for (int j : graph.xToY.get(i)) {
						if (yTo[j] == -1) {
							xTo[i] = j;
							yTo[j] = i;
							matched++;
							break;
						}
					}
				} else {
					for (int j = 0; j < size; j++) {
						if (yTo[j] == -1) {
							xTo[i] = j;
							yTo[j] = i;
							matched++;
							break;
						}
					}
				}
			}
		}
		
		while (matched < size) {
			int xSteps[] = new int[size];
			
			for (int i = 0; i < size; i++) {
				if (xTo[i] == -1) {
					xSteps[i] = 0;
				} else {
					xSteps[i] = -1;
				}
			}
			
			int winSteps = -1;
			int winY = -1;
			boolean active = true;
			
			out: while (active) {
				active = false;
				
				// y
				
				for (int i = 0; i < size; i++) {
					int minSteps = -1;
					
					if (i < graph.yToX.size()) {
						for (int j : graph.yToX.get(i)) {
							if (yTo[i] != j) {
								if (xSteps[j] != -1 && (minSteps == -1 || minSteps > xSteps[j] + 1)) {
									minSteps = xSteps[j];
								}
							}
						}
					} else {
						for (int j = 0; j < size; j++) {
							if (yTo[i] != j) {
								if (xSteps[j] != -1 && (minSteps == -1 || minSteps > xSteps[j] + 1)) {
									minSteps = xSteps[j];
								}
							}
						}
					}
					
					if (minSteps > -1) {					
						if (yTo[i] == -1) {
							// congratulations -- you've won an alternating path!
							winSteps = minSteps;
							winY = i;
							break out;
						} else {
							if (xSteps[yTo[i]] == -1) {
								xSteps[yTo[i]] = minSteps + 1;
								active = true;
							}
						}
					}
				}
			}
			
			if (winSteps != -1) {
				// build this path
				
				while (winSteps >= 0) {
					if (winY < graph.yToX.size()) {
						for (int j : graph.yToX.get(winY)) {
							if (yTo[winY] != j && xSteps[j] == winSteps) {
								int currentY = winY;
								
								if (winSteps > 0) {
									if (xTo[j] == -1) {
										throw new RuntimeException("BADNESS");
									}
									
									winY = xTo[j];
								}
								
								xTo[j] = currentY;
								yTo[currentY] = j;
								
								break;
							}
						}
					} else {
						for (int j = 0; j < size; j++) {
							if (yTo[winY] != j && xSteps[j] == winSteps) {
								int currentY = winY;
								
								if (winSteps > 0) {
									if (xTo[j] == -1) {
										throw new RuntimeException("BADNESS");
									}
									
									winY = xTo[j];
								}
								
								xTo[j] = currentY;
								yTo[currentY] = j;
								
								break;
							}
						}
					}
					
					winSteps--;
				}
					
				matched++;
			} else {
				break;
			}
		}
		
//		System.out.printf("-- matched: %d / %d\n", matched, size);
		
		return matched == size;
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		
		for (int Q = 1; Q <= T; Q++) {
			int N = scan.nextInt();

			Graph graph = new Graph();

			{
				List<String> words1 = new ArrayList<String>();
				List<String> words2 = new ArrayList<String>();
				
				for (int i = 0; i < N; i++) {
					String word1 = scan.next();
					String word2 = scan.next();
					
					int x = words1.indexOf(word1);
					
					if (x == -1) {
						x = words1.size();
						words1.add(word1);
					}
					
					int y = words2.indexOf(word2);
					
					if (y == -1) {
						y = words2.size();
						words2.add(word2);
					}
					
					graph.addEdge(x, y);
				}
			}
			
			// do some matching behind a binary search, left fails, right succeeds
			
			int left = Math.max(graph.xToY.size(), graph.yToX.size()) - 1;
			int right = N;
			
//			System.out.printf("-- left: %d right: %d\n", left, right);
			
			while (right > left + 1) {
				int c = (left + right) / 2;
				
				if (match(graph, c)) {
//					System.out.printf("-- succeed -- %d\n", c);
					right = c;
				} else {
//					System.out.printf("-- fail -- %d\n", c);
					left = c;
				}
			}
			
			// right is smallest number of original topics
			
			System.out.printf("Case #%d: %d\n", Q, N - right);
		}
	}
}
