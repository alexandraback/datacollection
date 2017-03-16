import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;

public class qualC {
	public static void main(String[] args) {
		String prblm="C"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int n=Integer.parseInt(s);
			HashSet<Integer> hs=new HashSet<Integer>();
			for (int i = 1; i <= n; i++) {
				s=fr.readLine();
				String[] tok=s.split(" ");
				int A=Integer.parseInt(tok[0]);
				int B=Integer.parseInt(tok[1]);
				int nd=1;
				int msk=1;
				for (int t=A/10; t > 0; t/=10) { nd++; msk*=10; }
				int nrn=0;
				for (int j = A; j <= B; j++) {
					hs.clear();
					int d=10;
					int res=msk;
					while (res>0) {
						int nj=(j%d)*res+j/d;
						if (nj>j && nj<=B && !hs.contains(nj)) {
							nrn++;
							hs.add(nj);
						}
						d*=10;
						res/=10;
					}					
				}
				System.out.println(nrn);
				fw.write("Case #"+i+": "+ nrn +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
