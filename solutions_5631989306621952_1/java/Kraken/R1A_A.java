import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1A_A {
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
				char[] ca=s.toCharArray();
				int j=s.length()-1;
				String rh="",rt="";
				while (j>=0){
					int lj=j;
					for (int k = j-1; k >= 0; k--) {
						if (ca[k]>ca[j]) j=k;
					}
					rh+=ca[j]; 
					rt=s.substring(j+1,lj+1)+rt;
					j--;
				}								
				System.out.println(rh+rt);
				fw.write("Case #"+i+": "+ rh+rt  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}