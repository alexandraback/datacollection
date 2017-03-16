import java.io.*;
import java.util.*;
import java.awt.Point;

public class C {
	
	public static void main(String[] args){
		assert(args.length == 1);
		parseTXT(args[0]);
	}
	
	private static void parseTXT(String file){
 		try{
			BufferedReader infile = new BufferedReader(new FileReader(file));
			int T = Integer.parseInt(infile.readLine());
			String[] s;
			int r, c, m;
			for(int i = 0; i < T; i++){
				s = infile.readLine().split("\\s+");
				r = Integer.parseInt(s[0]);
				c = Integer.parseInt(s[1]);
				m = Integer.parseInt(s[2]);				

				int id = i+1;
				System.out.println("Case #" + id + ": ");
				if(r * c <= m) System.out.println("Impossible");
				getResult(r, c, m);
			}
			infile.close();
 		}catch(IOException e){
 			System.err.println("wrong " + file );
 		}
	}
	
	private static void getResult(int r, int c, int m){
		char[][] board = fillBoard(r, c);
		PointBoard pb = new PointBoard(r, c);
		int blank = r*c - m;
		if(blank == 1){
			board[0][0] = 'c';
			printBoard(board, r, c);
			return;
		}
		
		Point start = pb.pb[0][0];
		int ct = 1; // start point
		Set<Point> v = new HashSet<Point>();
		v.add(start);
		
		Stack<Node> stack = new Stack<Node>();
		stack.push(new Node(start, ct, v));		
		board[0][0] = 'c';
		
		Set<Point> neis;
		Node node;
		while(!stack.isEmpty()){
			node = stack.pop();
			neis = pb.getNeighbors(node.p);
			// remove visited nodes
			Set<Point> remove = new HashSet<Point>();
			for(Point p : neis){
				if(node.visited.contains(p)) remove.add(p);
			}
			neis.removeAll(remove);
			// should not expand this node, this node is boundary
			Set<Point> visited = new HashSet<Point>();
			visited.addAll(node.visited);
			visited.addAll(neis);
			for(Point p : neis){
				stack.push(new Node(p, visited.size(), visited));
			}
			if(visited.size() == blank) {
				for(Point p : visited){
					board[p.x][p.y] = '.';
				}board[0][0] = 'c';
				printBoard(board, r, c);
				return;
			}
		}
		System.out.println("Impossible");
	}
	
	private static char[][] fillBoard(int r, int c){
		char[][] b = new char[r][c];
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				b[i][j] = '*';
			}
		}
		return b;
	}
	
	private static void printBoard(char[][] b, int r, int c){
		for(int i = 0; i < r; i++){
			System.out.println(String.valueOf(b[i]));
		}
	}

}

class Node{
	Point p;
	int count;
	Set<Point> visited;

	public Node(Point p, int count, Set<Point> v){
		this.p = p;
		this.count = count;
		this.visited = v;
	}
}

class PointBoard{
	int r;
	int c;
	public Point[][] pb;
	
	public PointBoard(int r, int c){
		this.r = r;
		this.c = c;
		pb = new Point[r][c];
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				pb[i][j] = new Point(i, j);
			}
		}
	}
	
	public Set<Point> getNeighbors(Point p){
		Set<Point> set = new HashSet<Point>();
		if(valid(p.x-1, p.y-1)) set.add(pb[p.x-1][p.y-1]);
		if(valid(p.x-1, p.y)) set.add(pb[p.x-1][p.y]);
		if(valid(p.x-1, p.y+1)) set.add(pb[p.x-1][p.y+1]);
		if(valid(p.x, p.y-1)) set.add(pb[p.x][p.y-1]);
		if(valid(p.x, p.y+1)) set.add(pb[p.x][p.y+1]);
		if(valid(p.x+1, p.y-1)) set.add(pb[p.x+1][p.y-1]);
		if(valid(p.x+1, p.y)) set.add(pb[p.x+1][p.y]);
		if(valid(p.x+1, p.y+1)) set.add(pb[p.x+1][p.y+1]);		
		return set;
	}
	
	private boolean valid(int x, int y){
		if(x >= 0 && x < r && y >= 0 && y < c) return true;
		return false;
	}
}






