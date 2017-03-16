import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class qualB {
public static void main(String[] args) {
		String prblm="B"; boolean fl=true;
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
				int N=Integer.parseInt(tok[0]);
				int M=Integer.parseInt(tok[1]);
				int[][] ht=new int[N][M];
				for (int j = 0; j < N; j++) {
					s=fr.readLine();
					tok=s.split(" ");
					for (int k = 0; k < M; k++) {
						ht[j][k]=Integer.parseInt(tok[k]);
					}
				}
				boolean vld=true;
				for (int j = 0; j < N && vld; j++) {
					for (int k = 0; k < M && vld; k++) {
						for (int r = 0; r < N; r++) {
							if (ht[j][k]<ht[r][k]){
								vld=false;
								break;
							}
						}
						if (!vld){
							vld=true;
							for (int r = 0; r < M; r++) {
								if (ht[j][k]<ht[j][r]){
									vld=false;
									break;
								}
							}
						}
					}					
				}
				s=(vld)?"YES":"NO";
				System.out.println(s);
				fw.write("Case #"+i+": "+  s +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
