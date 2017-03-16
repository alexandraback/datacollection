import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class Rd1B {
	
	static int md=1000000007;
	
	static int fact(int n){
		if (n<=1) return 1;
		long d=fact(n-1);
		return (int)((d*n)%md);
	}
	
public static void main(String[] args) {
		String prblm="B"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();				
				int N=Integer.parseInt(s);
				s=fr.readLine();
				String[] tok=s.split(" ");
				boolean[] appin=new boolean[27];
				boolean[] appls=new boolean[27];
				boolean[] apprs=new boolean[27];
				int[] mp=new int[27]; int[] mpi=new int[27];
				Arrays.fill(mp, -1); Arrays.fill(mpi, -1);
				int[] npc=new int[27];
				boolean fg=true;
				for (int j = 0; j < N && fg; j++) {
					char in=tok[j].charAt(0);
					int k=0;
					while (k<tok[j].length() && tok[j].charAt(k)==in) k++;
					if (k==tok[j].length()) npc[in-'a']++;
					else {
						if (appls[in-'a'] || appin[in-'a']) fg=false;
						appls[in-'a']=true;
						int h=tok[j].length()-1;
						char ls=tok[j].charAt(h);
						while (tok[j].charAt(h)==ls) h--;
						if (apprs[ls-'a'] || appin[ls-'a'] || ls==in) fg=false;
						apprs[ls-'a']=true;
						mp[ls-'a']=in-'a'; mpi[in-'a']=ls-'a';
						char mdc=0;
						for (int d = k; d <= h && fg; d++) {
							if (tok[j].charAt(d)!=mdc){
								mdc=tok[j].charAt(d);
								if (appin[mdc-'a'] || appls[mdc-'a'] || apprs[mdc-'a']) fg=false;
								appin[mdc-'a']=true;
							}
						}
					}
				}
				long rt=1;
				int ndc=0;
				if (!fg) rt=0;
				else {
					//System.out.println(Arrays.toString(mp)+"\n"+Arrays.toString(mpi));
					//System.out.println(Arrays.toString(npc));
					int nus=0;
				for (int j = 0; j < 27; j++) {
					if (!apprs[j] && (appls[j] || npc[j]>0)){						
						int nch=j;
						ndc++;
						while (nch>=0){
							nus+=npc[nch]+((appls[j])?1:0);
							rt=(rt*fact(npc[nch]))%md;					
							nch=mpi[nch];
						}
						//System.out.println(nch+" "+rt+" "+npc[nch]);
					}
				}				
				rt=(rt*fact(ndc))%md;
				if (nus<N) rt=0;
				}
				System.out.println(rt);
				fw.write("Case #"+i+": "+ rt  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}