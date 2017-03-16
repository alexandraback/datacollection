import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class qualB {
	public static void main(String[] args) {
		String prblm="B"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int n=Integer.parseInt(s);
			for (int i = 1; i <= n; i++) {
				s=fr.readLine();
				String[] tok=s.split(" ");
				int N=Integer.parseInt(tok[0]);
				int S=Integer.parseInt(tok[1]);
				int p=Integer.parseInt(tok[2]);
				int ng=0;
				int nag=0;
				for (int j = 3; j < tok.length; j++) {
					int ssc=Integer.parseInt(tok[j]);
					int bsc=(ssc+2)/3;
					if (bsc>=p) ng++;
					else if (bsc==p-1 && ssc%3!=1 && ssc>0) nag++;
				}
				System.out.println((ng+Math.min(S, nag)));
				fw.write("Case #"+i+": "+ (ng+Math.min(S, nag))  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
