import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class qualD {
public static void main(String[] args) {
		String prblm="D"; boolean fl=true;
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
				int X=Integer.parseInt(tok[0]);
				int R=Integer.parseInt(tok[1]);
				int C=Integer.parseInt(tok[2]);
				int r=Math.max(R, C),c=Math.min(R, C);
				boolean rw=(X>r || (r*c)%X!=0 || (X+1)/2>c || X>6 || (X>=4 && c==2) || (X>=5 && c==3));				
				s=rw? "RICHARD":"GABRIEL";
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