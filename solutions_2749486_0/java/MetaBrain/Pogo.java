
import java.util.*;

public class Pogo {

	static int target_x ;
	static int target_y ; 
	
	public static State explore(PriorityQueue<State> q) {
//		Queue<State> new_q = new LinkedList<State>() ;
		
		while(!q.isEmpty()) {
			State state = q.poll() ;
			if(state.target())
				return state ;

			q.add(state.N()) ;
			q.add(state.S()) ;
			q.add(state.E()) ;
			q.add(state.W()) ;
		}
		
		return null;		
	}

	public static void go(Scanner in, int caze) {
		String[] line = in.nextLine().split(" ") ;
		target_x = Integer.parseInt(line[0]) ;
		target_y = Integer.parseInt(line[1]) ;
		
		PriorityQueue<State> q = new PriorityQueue<State>() ;
		q.add(new State(0,0)) ;
		State r = explore(q) ;
		
//		System.out.printf("x:%d y:%d\n",r.x,r.y);
		System.out.printf("Case #%d: %s\n",caze,r.dirs);
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		int N = Integer.parseInt(in.nextLine());
		
		for(int caze = 1; caze<=N ; caze++) {
			go(in,caze);
//			if(caze<N && in.hasNextLine()) 
//				System.out.println("###"+in.nextLine()+"###");
//				in.nextLine();
		} 
	}
	
	
}

class State implements Comparable<State> {
	int x;
	int y;
	String dirs ;
	State(int x, int y) {this.x=x;this.y=y;this.dirs="";}
	State(int x, int y, String dirs) {this.x=x;this.y=y;this.dirs=dirs;};
	public State W() {
		//west (decreasing x)
		return new State(x-(dirs.length()+1) , y, new String(dirs+'W'));
	}
	public State E() {
		//east (increasing x)
		return new State(x+(dirs.length()+1) , y, new String(dirs+'E'));
	}
	public State S() {
		//south (decreasing y)
//		System.out.printf("S (%d,%d,'%s')->(%d,%d,'%s')\n",x,y,dirs,x,y-(dirs.length()+1),new String(dirs+'S'));
		return new State(x, y-(dirs.length()+1), new String(dirs+'S'));
	}
	public State N() {
		//north (increasing y)
//		System.out.printf("N (%d,%d,'%s')->(%d,%d,'%s')\n",x,y,dirs,x,y+dirs.length()+1,new String(dirs+'N'));
		return new State(x, y+(dirs.length()+1), new String(dirs+'N'));
	}
	boolean target() {return (x==Pogo.target_x && y==Pogo.target_y);}
	
	@Override
	public int compareTo(State o) {
		//heuristica
//		System.out.println("USING");
		return Math.abs(Pogo.target_x-this.x)+Math.abs(Pogo.target_y-this.y)
				- Math.abs(Pogo.target_x-o.x)+Math.abs(Pogo.target_y-o.y);
	}
}

