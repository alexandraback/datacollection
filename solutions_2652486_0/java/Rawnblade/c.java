import java.util.*;

public class c {
	static TreeMap<ProductSet, Integer>[][][] map;
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int r = reader.nextInt(); //Actual case counter
			int n = reader.nextInt(); //3, not used
			int m = reader.nextInt();
			int w = reader.nextInt();
			
			map = new TreeMap[m+1][m+1][m+1];
			for(int i = 2; i <= m; i++)
				for(int j = i; j <= m; j++)
					for(int k = j; k <= m; k++){
						map[i][j][k] = new TreeMap<ProductSet, Integer>();
						f(i,j,k,new LinkedList<Integer>(),w);
					}
			
			System.out.println("Case #"+t+":");
			for(int c = 0; c < r; c++){
				ArrayList<Integer> q = new ArrayList<Integer>();
				for(int j = 0; j < w; j++)
					q.add(reader.nextInt());
				ProductSet p = new ProductSet(q);
				
				int x = -1;
				int y = -1;
				int z = -1;
				int max = 0;
				for(int i = 2; i <= m; i++)
					for(int j = i; j <= m; j++)
						for(int k = j; k <= m; k++)
							if(get(i,j,k,p) > max){
								x = i;
								y = j;
								z = k;
								max = get(i,j,k,p);
							}
				
				System.out.println(x+""+y+""+z);
			}
		}
	}
	
	public static int get(int n, int m, int k, ProductSet p){
		if(!map[n][m][k].containsKey(p))
			return 0;
		return map[n][m][k].get(p);
	}
	
	public static void inc(int n, int m, int k, ProductSet p){
		if(!map[n][m][k].containsKey(p))
			map[n][m][k].put(p,0);
		map[n][m][k].put(p, 1 + map[n][m][k].get(p));
	}
	
	public static void f(int n, int m, int k, LinkedList<Integer> q, int z){
		if(z == 0){
			ArrayList<Integer> add = new ArrayList<Integer>();
			add.addAll(q);
			inc(n,m,k,new ProductSet(add));
//			System.out.println("Adding " + q + " to " + n + " " + m + " " + k);
			return;
		}
		
		int[] v = {n,m,k};
		for(int i = 0; i < 8; i++){
			int p = 1;
			for(int j = 0; j < 3; j++)
				if(((1<<j)&i) > 0)
					p *= v[j];
			q.add(p);
			f(n,m,k,q,z-1);
			q.removeLast();
		}
	}
	
	public static class ProductSet implements Comparable<ProductSet>{
		ArrayList<Integer> pr;
		public ProductSet(ArrayList<Integer> set){
			pr = set;
			Collections.sort(pr);
		}
		public int compareTo(ProductSet p){
			for(int i = 0; i < pr.size(); i++)
				if(pr.get(i) != p.pr.get(i))
					return pr.get(i)-p.pr.get(i);
			return 0;
		}
	}
}
