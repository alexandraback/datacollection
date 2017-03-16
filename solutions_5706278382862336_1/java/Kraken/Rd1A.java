import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class Rd1A {
	
	static long gcd(long a, long b){
		if (a%b==0) return b;		
		return gcd(b,a%b);
	}
	
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
				String[] tok=s.split("/");
				long P=Long.parseLong(tok[0]);
				long Q=Long.parseLong(tok[1]);
				long g=gcd(P,Q);
				P=P/g; Q=Q/g;
				int na=-1; boolean fg=true;
				for (int j = 0; j <= 40 && fg; j++) {
					long nf=(1l<<j);
					while (true) {
						//System.out.println(P+" "+Q+" "+j);
						long dn=gcd(Q,nf);						
						double d=((double)nf/dn)*Q;
						if (d>1l<<40) {
							fg=false;
							break;
						}
						if (P==0 || Q/dn>P*(nf/dn)) break;
						long q=(nf/dn)*Q;
						P=P*(nf/dn)-(Q/dn);
						Q=q;
						if (na<0) na=j;
					}
				}
				if (fg && P==0) s=""+na;
				else s="impossible";
				System.out.println(s);
				fw.write("Case #"+i+": "+ s  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}