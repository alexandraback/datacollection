package round1b;

import java.io.*;
import java.util.*;
import java.math.*;

/**
 *
 * @author kronenthaler
 */
public class C {
	public static void main(String[] args) {
		try{
			Scanner in = new Scanner(new FileInputStream("c-small.txt"));
			System.setOut(new PrintStream("c.out"));
			int T = in.nextInt();
			for(int cases=1;cases<=T;cases++){
				ArrayList<node> q = new ArrayList<node>();
				HashMap<Integer,HashSet<Integer>> visited = new HashMap<Integer,HashSet<Integer>>();
				
				int N = in.nextInt();
				int s[] = new int[N];
				for(int i=0;i<N;i++){
					s[i]=in.nextInt();
					node n = new node(s[i]);
					q.add(n);
					visited.put(n.sum, n.v);
				}
				
				HashSet<Integer> sol1 = null;
				HashSet<Integer> sol2 = null;
				
				while(!q.isEmpty() && sol1==null){
					node current = q.remove(0);
					
					for(int i=0;i<N;i++){
						if(!current.v.contains(s[i])){
							if(visited.get(current.sum+s[i])!=null){
								//termine!
								current.v.add(s[i]);
								
								if(current.v.equals(visited.get(current.sum+s[i]))){
									current.v.remove(s[i]);
									continue;
								}else{
									sol1 = visited.get(current.sum+s[i]);
									sol2 = current.v;
									break;
								}
							}else{
								node newn = new node(current.v,s[i],current.sum);
								q.add(newn);
								visited.put(newn.sum, newn.v);
							}
						}
					}
				}
				System.out.printf("Case #%d:\n", cases);
				if(sol1 != null && sol2 !=null){
					Integer a[]=sol1.toArray(new Integer[0]);
					Integer b[]=sol2.toArray(new Integer[0]);
					Arrays.sort(a);
					Arrays.sort(b);
					for(int i=0;i<a.length;i++)
						System.out.print(a[i]+" ");
					System.out.println("");
					for(int i=0;i<b.length;i++)
						System.out.print(b[i]+" ");
					System.out.println("");
				}else{
					System.out.println("Impossible");
				}
			}
			
		}catch(Exception e){
			e.printStackTrace();
		} 
	}
	
	static class node{
		HashSet<Integer> v;
		int sum;
		public node(int _v){
			if(v==null)
				v = new HashSet<Integer>();
			v.add(_v);
			sum += _v;
		}
		public node(HashSet<Integer> _v, int newv, int oldsum){
			v = new HashSet<Integer>();
			for(Integer i:_v)
				v.add(i);
			v.add(newv);
			sum = oldsum+newv;
		}
	}
}
