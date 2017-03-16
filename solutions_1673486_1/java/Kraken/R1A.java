import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1A {
public static void main(String[] args) {
		String prblm="A"; boolean fl=true;
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
				int A=Integer.parseInt(tok[0]);
				int B=Integer.parseInt(tok[1]);
				s=fr.readLine();
				tok=s.split(" ");
				double emin=2+B;
				double prc=1;
				for (int j = 0; j < A; j++) {
					double pr=Double.parseDouble(tok[j]);
					prc*=pr;
					double ev=(A-j-1)+(B-j-1)+(B+1)*(1-prc)+1;
					emin=Math.min(emin, ev);
				}
				System.out.println(emin);
				fw.write("Case #"+i+": "+ emin  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}

