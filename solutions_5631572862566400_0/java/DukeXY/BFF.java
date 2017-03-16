import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class BFF {
	public static ArrayList<Integer> q;
	public static HashMap<Integer,Integer> Map;
	public static boolean[] visited;
	public static int head0;
	public static boolean check(int cur, int depth,int last) {
		//System.out.print(cur+" ");
		visited[cur]=true;
		if (depth==q.size()) {
			//System.out.println("***"+cur+" "+Map.get(cur));
			//System.out.println();
			if (q.contains(Map.get(cur)) && visited[Map.get(cur)]==true &&(Map.get(cur)==head0 || Map.get(cur)==last)) {
				//System.out.println("***"+cur+" "+Map.get(cur)+" "+head0+" "+last+" "+q.size());
				//System.out.println();
				return true;
			}else return false;
		}
		
		if (last==-1) {
			if (q.contains(Map.get(cur))) return check(Map.get(cur),depth+1,cur); else return false;
		} else {
			boolean flag=false;
			if (Map.get(cur)==last) {
				for (int i=0;i<q.size();i++) {
					if (visited[q.get(i)]==false) {
						//System.out.println(q.get(i));
						visited[q.get(i)]=true;
						flag=flag||check(q.get(i),depth+1,cur);
						visited[q.get(i)]=false;
					}
				}
				return flag;
			} else {
				//System.out.println(cur);
				if (q.contains(Map.get(cur)) && visited[Map.get(cur)]==false) {
					visited[Map.get(cur)]=true;
					boolean temp=check(Map.get(cur),depth+1,cur);
					visited[Map.get(cur)]=false;
					return temp;
				}else return false;
			}
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setOut(new PrintStream(new File("ans3.txt")));
		Scanner a=new Scanner(new BufferedInputStream(new FileInputStream("3.txt")));
		int casNum=a.nextInt();
		for (int cas=1;cas<=casNum;cas++) {
			int n=a.nextInt();
			int[] d=new int[n+1];
			int[] v=new int[n];
			d[0]=1;
			Map=new HashMap<Integer,Integer>();
			for (int i=0;i<n;i++) {
				v[i]=i+1;
				Map.put(i+1, a.nextInt());
			}
			int max=0;
			while (d[n]==0) {
				q=new ArrayList<Integer>();
				for (int i=0;i<n;i++) {
					if (d[i]==1) {
						q.add(v[i]);
					}
				}
				for (int k=0;k<q.size();k++) {
					/*for (int j=0;j<q.size();j++) {
						System.out.println(q.get(j));
					}
					System.out.println();*/
					head0=q.get(k);
					visited=new boolean[n+1];
					for (int j=0;j<=n;j++) {
						visited[j]=false;
					}
					visited[q.get(k)]=true;
					//System.out.println();
					if (check(q.get(k),1,-1) && q.size()>max) {
						max=q.size();
						//for (int j=0;j<q.size();j++) {
						//	System.out.println("ans="+q.get(j));
						//}
						//System.out.println(q.get(k));
						//System.out.println();
					}
				}
				int r=0;
				while (d[r]==1) {
					d[r]=0;
					r++;
				}
				d[r]=1;
			}
			System.out.println("Case #"+cas+": "+max);			
		}
	}
}
