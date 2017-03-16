import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class R1A_C {
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
				int N=Integer.parseInt(s);
				s=fr.readLine();
				String[] tok=s.split(" ");
				int[] id=new int[N];
				for (int j = 0; j < N; j++) {
					id[j]=Integer.parseInt(tok[j])-1;					
				}
				int[] nc=new int[N],lch=new int[N];
				int mxc=-1; 
				Arrays.fill(nc,-1);
				for (int j = 0; j < id.length; j++) {
					int p=0,k=j;
					boolean[] v=new boolean[N];
					Arrays.fill(v,false);
					while (!v[k]) {v[k]=true; p++; 
						if (!v[id[k]] && id[id[k]]!=k) lch[id[k]]=Math.max(p, lch[id[k]]);
						k=id[k];
					}
					if (k==j) {nc[j]=p; mxc=Math.max(mxc, p);}
				}
				int res=0;
				for (int j = 0; j < id.length; j++) 
					if (nc[j]==2) res+=lch[j]+1;
				res=Math.max(res, mxc);
				//System.out.println(Arrays.toString(lch)+" - "+Arrays.toString(nc));
				System.out.println(res);
				fw.write("Case #"+i+": "+ res  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}