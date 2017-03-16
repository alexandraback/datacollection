import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Problem3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int case2 = input.nextInt();input.nextLine();
		for(int a = 0; a < case2; a++){
			int n = input.nextInt();
			int[] graph = new int[n+1];
			ArrayList<Integer>[] inverseGraph = new ArrayList[n+1];
			for(int b = 0; b <= n; b++){
				inverseGraph[b] = new ArrayList<Integer>();
			}
//			System.out.println(Arrays.toString(inverseGraph));
			for(int b = 0; b < n; b++){
				graph[b+1] = input.nextInt();
				inverseGraph[graph[b+1]].add(b+1);
			}
			//2 Cases: Giant cycle, or 2-cycle with chains
			ArrayList<Integer> twoCycleStart = new ArrayList<Integer>();
			ArrayList<Integer> twoCycleSecond = new ArrayList<Integer>();
			int maxCycleLength = -1;
			for(int b = 1; b <= n; b++){
				int length = cycleDetect(b, graph);
//				System.out.println("Cycle Length" + length);
				if(length == 2){
					twoCycleStart.add(b);
					twoCycleSecond.add(graph[b]);
				}
				if(length > maxCycleLength){
					maxCycleLength = length;
				}
			}
			//2 cycle detection
			int sum = 0;
			for(int b = 0; b < twoCycleStart.size(); b++){
				//for each 2 cycle, find the best route
//				System.out.println(twoCycleStart + " " + twoCycleSecond);
				sum += maxDFSDepth(twoCycleStart.get(b), twoCycleSecond.get(b), inverseGraph);
				sum += maxDFSDepth(twoCycleSecond.get(b), twoCycleStart.get(b), inverseGraph);
			}
			sum /= 2;
			System.out.print("Case #" + (a+1) + ":" + " ");
			System.out.println(Math.max(sum, maxCycleLength));
		}
		
	}

	private static int maxDFSDepth(Integer integer, Integer integer2, ArrayList<Integer>[] inverseGraph) {
		return maxDFSDepthHelper(integer, integer2, inverseGraph, 1);
	}
	private static int maxDFSDepthHelper(Integer integer, Integer integer2, ArrayList<Integer>[] inverseGraph, int depth) {
//		System.out.println("Evaluating " + integer + " " + " cannot go on " + integer2 + " " + depth);
//		Scanner input = new Scanner(System.in); input.nextLine();
		int max = depth;
		for(Integer i:inverseGraph[integer]){
			if(!i.equals(integer2)){
				int dep = maxDFSDepthHelper(i, integer2, inverseGraph, depth+1);
				if(dep > max){
					max = dep;
				}
			}
		}
		return max;
	}

	private static int cycleDetect(int b, int[] graph) {
		int start = b;
		int cycleLength = 0;
		int iterate = start;
		while(iterate != start || cycleLength == 0){
			cycleLength++;
			if(cycleLength > graph.length + 1500){
				break;
			}
			iterate = graph[iterate];
		}
		if(cycleLength > 1499){
			return 0;
		}
		return cycleLength;
	}

}
