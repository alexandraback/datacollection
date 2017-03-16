import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;


public class Pogo {
	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int c = 1; c <= cases; c++) {
			String[] p = br.readLine().split(" ");
			int x = Integer.parseInt(p[0]);
			int y = Integer.parseInt(p[1]);
			
			LinkedList<Node> q = new LinkedList<Node>();
			q.add(new Node(0,0,1,null, '_'));
			
			while(q.size() > 0) {
				Node current = q.pop();
				
				if(current.x == x && current.y == y) {
					Node parent  = current;
					String result = "";
					while(parent != null) {
						if(parent.direction != '_')
							result = parent.direction + result;
						parent = parent.parent;
					}
					System.out.println("Case #"+c+": "+result);
					break;
				}
				else {
					if (current.x == x) {
						if(y-current.y > current.steps)
							q.add(new Node(current.x, current.y+current.steps, current.steps+1, current, 'N'));
						else if(current.y-y > current.steps)
							q.add(new Node(current.x, current.y-current.steps, current.steps+1, current, 'S'));
						else {
							q.add(new Node(current.x, current.y+current.steps, current.steps+1, current, 'N'));
							q.add(new Node(current.x, current.y-current.steps, current.steps+1, current, 'S'));
						}
					}
					else {
						if(x-current.x > current.steps)
							q.add(new Node(current.x+current.steps, current.y, current.steps+1, current, 'E'));
						else if(current.x-x > current.steps)
							q.add(new Node(current.x-current.steps, current.y, current.steps+1, current, 'W'));
						else {
							q.add(new Node(current.x+current.steps, current.y, current.steps+1, current, 'E'));
							q.add(new Node(current.x-current.steps, current.y, current.steps+1, current, 'W'));
						}
					}
				}
			}
		}
	}
}

class Node {
	Node parent;
	int steps;
	int x,y;
	char direction;
	
	public Node(int x, int y, int steps, Node parent, char direction) {
		this.parent = parent;
		this.steps = steps;
		this.x = x;
		this.y = y;
		this.direction = direction;
	}
}
