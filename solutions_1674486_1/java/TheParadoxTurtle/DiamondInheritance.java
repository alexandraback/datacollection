import java.io.*;
import java.util.*;
public class DiamondInheritance {
	public ArrayList<DiamondInheritance> adjacent;
	public int ID;
	public static int[][] paths;
	public DiamondInheritance(int N) {
		ID = N;
		adjacent = new ArrayList<DiamondInheritance>();
	}
	public void add(DiamondInheritance node) {
		adjacent.add(node);
	}
	public static boolean findPaths(DiamondInheritance start, DiamondInheritance current) {
		if(current != start) {
			paths[start.ID][current.ID]++;
			if(paths[start.ID][current.ID] > 1)
				return true;
		}
		boolean temp = false;
		for(DiamondInheritance DI: current.adjacent) {
			temp = findPaths(start, DI)||temp;
		}
		return temp;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new FileReader("A-large.in.txt"));
		int T = Integer.parseInt(read.readLine());
		for(int i = 1; i <= T; i++){
			int N = Integer.parseInt(read.readLine());
			DiamondInheritance[] nodes = new DiamondInheritance[N];
	//		ArrayList<DiamondInheritance> in0 = new ArrayList<DiamondInheritance>();
			for(int k = 0; k < N; k++) {
				nodes[k] = new DiamondInheritance(k);
		//		in0.add(nodes[k]);
			}
			for(int k = 0; k < N; k++) {
				StringTokenizer st = new StringTokenizer(read.readLine());
				int M = Integer.parseInt(st.nextToken());
				for(int j = 0; j < M; j++) {
					int temp = Integer.parseInt(st.nextToken());
					nodes[k].add(nodes[temp-1]);
		//			in0.remove(nodes[temp]);
				}
			}
			paths = new int[N][N];
			boolean temp = true;
			for(int k = 0; k < N; k++) {
				if(findPaths(nodes[k], nodes[k])) {
					System.out.println("Case #" + i + ": Yes");
					temp = false;
					break;
				}
			}
			if(temp)
				System.out.println("Case #" + i + ": No");
		}
	}
}
