import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;

class state {
	boolean opened[];
	
	public int hashCode() {
		int r=0;
		int b=2;
		for (int i=0;i<opened.length;i++) {
			r+=b*(opened[i]?1:0);
			b*=2;
		}
		return r;
	}
	public boolean equals(Object obj) {
		if (!(obj instanceof state)) {return false;}
		state a = (state) obj;
		boolean r=true;
		for (int i=0;i<this.opened.length;i++) {
			if (this.opened[i]!=a.opened[i]) {r=false;break;}
		}
		return r;
	}
}

public class asdf {

	static short steps[];
	static short starts[];
	static short needs[];
	static short has[][];
	static HashSet<state> hs;
	
	static int iter(state st, int steppnt) {
		if (steppnt>needs.length) {return 1;}

		short nowhas[]=new short[400];
		for (short x : starts) {
			nowhas[x]++;
		}
		for (int i=0;i<st.opened.length;i++) {
			if (st.opened[i]) {
				nowhas[needs[i]]--;
				for (short s : has[i]) {
					nowhas[s]++;
				}
			}
		}
		
		for (int i=0;i<needs.length;i++) {
			if (!st.opened[i] && nowhas[needs[i]]>0) {
				state n = new state();
				n.opened=new boolean[needs.length];
				for (int j=0;j<n.opened.length;j++) {
					n.opened[j]=st.opened[j];
				}
				n.opened[i]=true;
				steps[steppnt-1] = (short)i;
				if (hs.contains(n)) {continue;} 
				int ret = iter(n, steppnt+1);
				if (ret==1) {return 1;}
				hs.add(n);
			}
		}
		return 0;
	}
	
	static void calc(int cid) {
		hs = new HashSet<state>();
		steps=new short[needs.length];
		state st = new state();
		st.opened=new boolean[needs.length];
		int ret = iter (st, 1);
		if (ret==1) {
			System.out.printf("Case #%d:",cid);
			for (int i=0;i<steps.length;i++) {
				System.out.printf(" %d",1+steps[i]);
			}
			System.out.println();
		}
		else {
			System.out.printf("Case #%d: IMPOSSIBLE%n", cid);
		}
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
				int k = sc.nextInt();
				int cc = sc.nextInt();
				starts = new short[k];
				for (int j=0;j<k;j++) {
					starts[j]=sc.nextShort();
				}
				needs = new short[cc];
				has = new short[cc][];
				for (int j=0;j<cc;j++) {
					needs[j]=sc.nextShort();
					has[j]=new short[sc.nextInt()];
					for (int jj=0;jj<has[j].length;jj++) {
						has[j][jj]=sc.nextShort();
					}
				}
				calc(cid);
				//System.out.println(cid);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}

}
