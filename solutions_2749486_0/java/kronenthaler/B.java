package r1c;


import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.Point;

/**
 *
 * @author kronenthaler
 */
public class B {
	public static void main(String[] args) {
        try{
			boolean small = true;
			String file = small ? "b-small.in" : "b-large.in"; 
			String out = small ? "b-small.out" : "b-large.out";
			Scanner in = new Scanner(new FileInputStream(file));
			System.setOut(new PrintStream(new FileOutputStream(out)));
			
			int T = in.nextInt();
			for(int cases = 1; cases <= T; cases++){
				int ox = 0;
				int oy = 0;
				int dx = in.nextInt();
				int dy = in.nextInt();
				
				System.out.printf("Case #%d:%s\n",cases, solve(ox,oy,dx,dy));
			}
		}catch(Exception e){
			e.printStackTrace();
		}
    }
	static char[] dir = {'N','S','E','W'};
	static int[] cx ={ 0, 0, 1, -1};
	static int[] cy ={ 1, -1, 0, 0};
	
	public static String solve(int ox,int oy, int dx, int dy){
		ArrayList<node> q= new ArrayList<node>();
		q.add(new node(new Point(ox,oy),1,null,' '));
		HashMap<Point, Boolean> visited = new HashMap<Point, Boolean>();
		while(!q.isEmpty()){
			node c = q.remove(0);
			if(c.p.x == dx && c.p.y == dy){
				StringBuffer sol = new StringBuffer();
				while(c != null){
					sol.insert(0, c.d);
					c = c.parent;
				}
				return sol.toString();
			}
			
			for(int i=0;i<4;i++){
				Point t = new Point(c.p.x+cx[i]*c.j, c.p.y+cy[i]*c.j);
				if(visited.get(t) == null){
					visited.put(t, true);
					q.add(new node(t, c.j+1, c, dir[i]));
				}
			}
		}
		
		return null;
	}
	
	static class node{
		Point p;
		int j;
		char d;
		node parent;
		node(Point _p, int _j, node _parent, char _d){ parent = _parent; j=_j; p=_p; d=_d;}
	}

}
