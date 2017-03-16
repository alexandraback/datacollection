import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;

class myinfo {
	int idx;
	int num;
}

class mycomp implements Comparator<myinfo> {

	@Override
	public int compare(myinfo arg0, myinfo arg1) {
		return arg1.num-arg0.num;
	}
	
}

public class abc {

	static public int E,R,N;
	static public myinfo v[];
	static void calc(int cid) {
		int pos[];
		pos =new int[N];
		for (int i=0;i<N;i++) {
			pos[i]=E;
		}
		Arrays.sort(v, new mycomp());
		long tot=0;
		for (int i=0;i<N;i++) {
			int idx=v[i].idx;
			tot+=v[i].num*pos[idx];
			pos[idx]=-1;
			for (int j=idx-1;j>=0;j--) {
				if (pos[j]==-1) break;
				if (pos[j+1]==-1) {
					pos[j]=R>E?E:R;
					continue;
				}
				pos[j]=(pos[j+1]-R >E)? pos[j+1]-R : E;
				
			}
			for (int j=idx+1;j<N;j++) {
				if (pos[j]==-1) break;
				if (pos[j-1]==-1) {
					pos[j]=R>E?E:R;
					continue;
				}
				if (pos[j-1]+R>E) {
					pos[j]=E;
					break;
				}
				else {
					pos[j]=pos[j-1]+R;
				}
			}
		}
		System.out.printf("Case #%d: %d%n", cid,tot);
	}
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) {
		try {
			
			Scanner sc =new Scanner(new File("d:/in"));
			int n = sc.nextInt();
			for (int cid =1;cid<=n;cid++) {
				E = sc.nextInt();
				R = sc.nextInt();
				N = sc.nextInt();
				v=new myinfo[N];
				for (int i=0;i<N;i++) {
					v[i]=new myinfo();
				}
				for (int j=0;j<N;j++) {
					v[j].num=sc.nextInt();
					v[j].idx=j;
				}
				calc(cid);
				//System.out.println(cid);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}

}
