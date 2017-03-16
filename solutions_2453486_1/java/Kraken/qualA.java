import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class qualA {
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
				boolean[] incm=new boolean[10];
				char[][] mt=new char[10][4];				
				for (int j = 0; j < 4; j++) {
					s=fr.readLine();
					for (int k = 0; k < s.length(); k++) {
						char t=s.charAt(k);
						mt[j][k]=mt[k+4][j]=t;
						incm[j]|=(t=='.'); incm[k+4]|=(t=='.'); 
						if (j==k){ mt[8][j]=t;
							incm[8]|=(t=='.');
						}
						if (j==3-k) {
							mt[9][j]=t;
							incm[9]|=(t=='.');
						}
					}
				}
				char win=0;
				boolean inc=false;
				for (int j = 0; j < mt.length; j++) {
					//System.out.println(Arrays.toString(mt[j])+ " "+incm[j]);
					inc|=incm[j];
					if (incm[j]) continue;
					char c=0; boolean flg=true;
					for (int k = 0; k < 4; k++) {
						if (c==0) {
							if (mt[j][k]!='T') c=mt[j][k];
						}
						else flg &= (c==mt[j][k] || mt[j][k]=='T');
					}
					if (flg) {
						win=c;
						break;
					}
				}
				if (win!=0) s=win+" won";
				else if (inc) s="Game has not completed";
				else s="Draw";
				System.out.println(s);
				fw.write("Case #"+i+": "+ s +"\n");
				s=fr.readLine();
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
