import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1_C {
	
	
	
	static long mt(int n,int m){
		if (n>=Av.length || m>=Bv.length) return 0;
		if (mem[n][m]==-1) {
			if (Av[n]!=Bv[m]){
				long af=mt(n+1,m);
				long bf=mt(n,m+1);
				mem[n][m]=Math.max(af, bf);
			}
			else {
				int nn=n; int nm=m;
				long cm=Math.min(av[n], bv[m]);
				long ccm=cm;
				long addt=mt(n+1,m+1)+cm;
				int tp=Av[n];
				long la=av[n]; long lb=bv[m];
				while (la!=lb) {
					if (la>lb){
						nm++;
						while (nm<Bv.length && Bv[nm]!=tp) nm++;
						if (nm==Bv.length) break;
						 ccm+=Math.min(la-lb, bv[nm]);
						addt=Math.max(mt(nn+1,nm+1)+ccm, addt);
						la=la-lb;
						lb=bv[nm];
					}
					if (la<lb){
						nn++;
						while (nn<Av.length && Av[nn]!=tp) nn++;
						if (nn==Av.length) break;
						ccm+=Math.min(lb-la, av[nn]);
						addt=Math.max(mt(nn+1,nm+1)+ccm, addt);
						lb=lb-la;
						la=av[nn];
					}
				}				
				mem[n][m]=addt;
			}
		}
		return mem[n][m];
	}
	
	static long[][] mem;
	static long[] av;
	static int[] Av;
	static long[] bv;
	static int[] Bv;
	
public static void main(String[] args) {
		String prblm="C"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();
				String[] tok=s.split(" ");
				int N=Integer.parseInt(tok[0]);
				int M=Integer.parseInt(tok[1]);
				s=fr.readLine();
				tok=s.split(" ");
				av=new long[N];
				Av=new int[N];
				for (int j = 0; j < N; j++) {					
					av[j]=Long.parseLong(tok[j*2]);
					Av[j]=Integer.parseInt(tok[j*2+1]);
				}
				s=fr.readLine();
				tok=s.split(" ");
				bv=new long[M];
				Bv=new int[M];
				mem=new long[N][M];
				for (int j = 0; j < M; j++) {					
					bv[j]=Long.parseLong(tok[j*2]);
					Bv[j]=Integer.parseInt(tok[j*2+1]);
					for (int j2 = 0; j2 < N; j2++) mem[j2][j]=-1;
				}
				long res=mt(0,0);
				System.out.println(res);
				fw.write("Case #"+i+": "+ res +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
