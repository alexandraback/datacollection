package qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class MinesweeperMaster {
	
	private static int R;
	private static int C;
	private static int M;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt1.in"));
		PrintWriter out = new PrintWriter("out");
		int t = Integer.parseInt(in.readLine());
		
		for(int i = 1; i <= t; i++) {
			
			String ss[] = in.readLine().split(" ");
			R = Integer.parseInt(ss[0]);
			C = Integer.parseInt(ss[1]);
			M = Integer.parseInt(ss[2]);
			int centerR = 0, centerC = 0;
			boolean found = false;
			boolean marked[][] = null;
			for(int r = 0; r < R; r++) {
				
				for(int c = 0; c < C; c++) {
					
					marked = new boolean[R][C];
					for(int k = 0; k < R; k++) {
						
						Arrays.fill(marked[k], false);
						
					}
					if(fillMines(r,c,marked)) {
						
						found = true;
						centerR = r;
						centerC = c;
						break;
						
					}
					
				}
				if(found)
					break;
				
			}
			out.println("Case #" + i + ":");
			if(!found) {
			
				out.println("Impossible");
			
			}
			else {
				
				for(int r = 0; r < R; r++) {
					
					String s = "";
					for(int c = 0; c < C; c++) {
						
						if(r == centerR && c == centerC) {
							
							s += "c";
							
						}
						else {
						
							s += (marked[r][c] ? "." : "*");
						
						}
						
					}
					out.println(s);
					
				}
				
			}
			
		}
		out.close();
		
	}
	
	private static boolean fillMines(int r, int c, boolean[][] marked) {
		
		Stack<Node> pq = new Stack<Node>();
		pq.add(new Node(r,c));
		boolean visited[][] = new boolean[R][C];
		for(int i = 0; i < R; i++) {
			
			Arrays.fill(visited[i], false);
			
		}
		marked[r][c] = true;
		int found = 1;
		while(!pq.isEmpty()) {
			
			Node n = pq.pop();
			if(visited[n.r][n.c]) {
				
				continue;
				
			}
			visited[n.r][n.c]= true;
			if(found + M == R*C) {
				
				return true;
				
			}
			List<Node> unMarked = new ArrayList<Node>();
			for(int i = -1; i <= 1; i++) {
				
				for(int j = -1; j <= 1; j++) {
					
					if(i == 0 && j == 0) 
						continue;
					if(n.r + i < 0 || n.r + i >= R)
						continue;
					if(n.c + j < 0 || n.c + j >= C)
						continue;
					if(marked[n.r+i][n.c+j])
						continue;
					unMarked.add(new Node(n.r+i, n.c+j));
					
				}
				
			}
			if(found + unMarked.size() + M > R*C)
				continue;
			found += unMarked.size();
			for(Node t : unMarked) {
				
				marked[t.r][t.c]= true; 
				pq.push(t);
				
			}
			
		}
		return false;
 		
	}

}

class Node {
	
	int r;
	int c; 
	int neighbours;
	
	public Node(int r, int c) {
		
		this.r = r;
		this.c = c;
		/*
		assert(r >= 0 && r < R);
		assert(c >= 0 && c < C);
		neighbours = Math.min(1, r);
		neighbours = Math.min(1, c);
		neighbours = (neighbours == 2 ? neighbours : neighbours + 1);
		int neighbours2 = Math.min(1, R-r);
		neighbours2 = Math.min(1, C-c);
		neighbours2 = (neighbours2 == 2 ? neighbours2 : neighbours2 + 1);
		neighbours = neighbours2 + neighbours + (Math.min(Math.min(neighbours,2), Math.min(neighbours2,2)));
		/*
		if(r == 0) {
			
			if(c == 0) {
				
				neighbours = Math.min(a, b)
				
			}
			
		}*/
		
	}
	
}