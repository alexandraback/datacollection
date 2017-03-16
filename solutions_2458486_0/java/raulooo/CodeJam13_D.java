import java.awt.Point;
import java.io.File;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.math.*;


public class CodeJam13_D {

	Scanner in;
	PrintWriter out;
	int NN;
	String ress = "";
	int [][] chestsContent;
	int [] chestKey;
	
	int [] myChestKeys;
	int [] chestTaken;
	HashMap<String,Integer> dp;
	
	long go(int i, int t, String res, long a, long b){
//		pr("t i",t,i,"res",res, dp);
		pr(Long.toBinaryString(a));
		if(t==0){
			if(ress.equals("")){
				ress=res;
//				return 1;
			}
			return 1;
		}
		String p = a+" "+b;
		if(dp.get(p)==null){
			int r = 0;
			for (int j = 1; j <= NN; j++) {
				if((a&(1<<(j-1)))!=0){
					continue;
				}
				if(myChestKeys[chestKey[j]]>0){
					myChestKeys[chestKey[j]]--;
//					a|=(j-1);
					for(int jj = 0 ; jj< chestsContent[j].length;jj++){
						myChestKeys[jj]+=chestsContent[j][jj];
					}
//					node q = new node();
//					String q= ""+(a|j)+" "+(b&~j);
					long x = go(j,t-1,res+" "+j,a|(1<<(j-1)),b&~(j-1));
//					if(x)
					if(x==1){
						r= 1;
						return 1;
					}
//					a=(a&~(j-1));
					myChestKeys[chestKey[j]]++;
					for(int jj = 0 ; jj< chestsContent[j].length;jj++){
						myChestKeys[jj]-=chestsContent[j][jj];
					}
				}
			}
			dp.put(p,r);
		}
		return dp.get(p);
//		return 0;
	}
	public void solve() throws Exception{
		in = new Scanner(new File("/Users/rc/test1/D-small-attempt5.in"));
		
//		pr(res2);
//		if(true)return;
//		Scanner in = new Scanner(new File("/Users/rc/Eclipse-Workspaces/Algorithm-Competitions-EWS/HuaHCodingProject/src/input_temp_case"));
//		in = new Scanner(new File("src/D_example"));
		
		
//		Scanner in = new Scanner(new File("D:/in.txt"));
		String writtenFile = "/Users/rc/test1/D-small-attempt5.in.out-2.txt";
//		out = new PrintWriter(System.out);
		out = new PrintWriter(new File(writtenFile));
		int casos = Integer.parseInt(in.nextLine());
//		pr(aa,T);k\k
		int MAX=41;
		for (int i = 0; i < casos; i++) {
			ress="";
			String ab[]= in.nextLine().split(" +");
			pr(ab);
			int K = Integer.parseInt(ab[0]);
			int N = Integer.parseInt(ab[1]);
			myChestKeys = new int[MAX];
			String []ar = in.nextLine().split(" ");
			pr(ar);
			for (int j2 = 0; j2 < ar.length; j2++) {
				myChestKeys[Integer.parseInt(ar[j2])]++;
			}
			chestsContent= new int[N+1][MAX];
			chestKey=new int[N+1];
			for (int j = 0; j < N; j++) {
				String ar2[]=in.nextLine().split(" +");
				int chesType=Integer.parseInt(ar2[0]);
				int chesContentCount=Integer.parseInt(ar2[1]);
				pr(ar2);
				chestKey[j+1]=chesType;
				for (int l = 2; l < ar2.length; l++) {
					chestsContent[j+1][Integer.parseInt(ar2[l])]++;
				}
			}
			NN=N;
			chestTaken=new int[N+1];
			pr(myChestKeys,"chestsContent",chestsContent,
					"chestKey",chestKey);
			dp=new HashMap<String,Integer>();
			go(1,N,"",0,N);
//			for (int j = 0; j < K; j++) {
//				chestTaken=new int[N+1];
//				if(myChestKeys[j]>0){
//					myChestKeys[j]--;
//				}
//			}
			
			
			if(ress.equals("")){
				out.println("Case #"+(i+1)+": IMPOSSIBLE");
			}else{
				out.println("Case #"+(i+1)+": "+ress.trim());
			}
			out.flush();
		}
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws Exception {
		new CodeJam13_D().solve();
	}
	void pr(Object... ob) {
		if(true)return;
		out.println(Arrays.deepToString(ob).replace("],", "],\n"));
		out.flush();
//		}
	}
}