package c1;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t=1;t<=T;t++){
			int X = in.nextInt();
			int Y = in.nextInt();
			HashSet<String> mem = new HashSet<String>();
			String res = bfs(0,0,1,mem,"",X,Y);
			System.out.println("Case #" + t + ": " +res);
		}

	}
	

	
	public static String bfs(int x, int y, int d, Set<String> mem, String way, int X, int Y){
		class s{
			int x,y,d;
			String p;
			public s(int x, int y, int d,String path){
				this.x=x;
				this.y=y;
				this.d=d;
				p=path;
			}
		}
		LinkedList<s> q = new LinkedList<>();
		s cur = new s(x,y,d,"");
		q.addLast(cur);
		
		while(q.size()!=0){
			
			cur = q.removeFirst();
			if(mem.contains(cur.x+" "+cur.y+" "+cur.d)) continue;
			mem.add(cur.x+" "+cur.y+" "+cur.d);
			if(cur.x==X && cur.y==Y){
				return cur.p;
			}
			q.addLast(new s(cur.x+cur.d,cur.y,cur.d+1,cur.p+"E"));
			q.addLast(new s(cur.x-cur.d,cur.y,cur.d+1,cur.p+"W"));
			q.addLast(new s(cur.x,cur.y+cur.d,cur.d+1,cur.p+"N"));
			q.addLast(new s(cur.x,cur.y-cur.d,cur.d+1,cur.p+"S"));
		}
		return "";
	}
	
}
