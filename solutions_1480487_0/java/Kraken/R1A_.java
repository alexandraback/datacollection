import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class R1A_ {
public static void main(String[] args) {
		String prblm="A"; boolean fl=!true;
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
				int tot=0;
				int N=Integer.parseInt(tok[0]);
				int[] pt=new int[N];
				for (int j = 1; j < tok.length; j++) {
					pt[j-1]=Integer.parseInt(tok[j]);
					tot+=pt[j-1];
				}
				int[] npt=Arrays.copyOf(pt, pt.length);
				Arrays.sort(pt);
				double av=tot*2.0/N;
				double nasg=tot*2.0;
				int n=N;
				for (int j = N-1; j >= 0; j--) {
					if (pt[j]>=av) {
						nasg-=pt[j];
						n--;
						av=nasg/n;					
					}
					else break;
				}
				s="Case #"+i+": ";
				for (int j = 0; j < N; j++) {
					if (npt[j]>av) s+=0.0;
					else s+=(av-npt[j])/tot*100;
					if (j<N-1) s+=" ";
				}
				System.out.println(s);
				fw.write(s+"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}