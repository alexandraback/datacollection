import java.util.*;
import java.io.*;

public class B_large {
	static int N,M;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(new File("b-large.in"));
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt(); N = n;
			Pair[] p = new Pair[n];
			
			for(int i = 0; i < n; i++)
				p[i] = new Pair(reader.nextInt(), reader.nextInt(), i);
			
			int stars = 0;
			int cnt = 0;
			int[] used = new int[n];
			for(int i = 0; i < 2*n && stars < 2*n; i++){
				cnt++;
				boolean dubbed = false;
				
				ArrayList<Pair> q = new ArrayList<Pair>();
				//Grab candidate pairs
				for(int j = 0; j < n; j++){
					if(used[j] == 0 && stars >= p[j].b){
						dubbed = true;
						stars += 2;
						used[j] = 2;
						break;
					}
					
					if(used[j] == 1 && stars >= p[j].b){
						dubbed = true;
						stars++;
						used[j] = 2;
						break;
					}
					
					if(used[j] == 0 && p[j].a <= stars)
						q.add(p[j]);
				}
				
				if(dubbed)
					continue;
				if(q.size() == 0)
					break;
				
				Collections.sort(q);
				
				stars++;
				used[q.get(0).i]++;
			}
			
			System.out.print("Case #"+t+": ");
			if(stars < 2*n){
				System.out.println("Too Bad");
			}else{
				System.out.println(cnt);
			}
		}
	}
	
	public static class Pair implements Comparable<Pair>{
		int a,b,i;
		public Pair(int _a, int _b, int _i){
			a = _a;
			b = _b;
			i = _i;
		}
		public int compareTo(Pair p){
			if(b == p.b)
				return a-p.a;
			return p.b-b;
		}
		public String toString(){
			return "("+a+", "+b+")";
		}
	}
}
