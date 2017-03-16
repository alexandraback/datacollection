import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class qualB {
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
				int D=Integer.parseInt(s);
				int[] nm=new int[D];
				s=fr.readLine();
				String[] tok=s.split(" ");				
				for (int j = 0; j < D; j++) 
					nm[j]=Integer.parseInt(tok[j]);
				Arrays.sort(nm);
				int mnm=nm[D-1];
				for (int lv = nm[D-1]-1; lv > 0; lv--) {
					int nmv=lv;
					for (int k = D-1; k>=0 && nm[k]>lv; k--)
						nmv+=(nm[k]-1)/lv;
					mnm=Math.min(mnm, nmv);
				}				
				System.out.println(mnm);
				fw.write("Case #"+i+": "+ mnm  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}