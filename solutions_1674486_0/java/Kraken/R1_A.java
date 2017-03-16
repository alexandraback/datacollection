import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class R1_A {
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
				boolean flag=false;
				int N=Integer.parseInt(s);
				boolean[][] mat=new boolean[N][N];
				for (int j = 0; j < mat.length; j++) {
					mat[j][j]=true;
				}
				ArrayList<int[]> ll=new ArrayList<int[]>();
				for (int j = 0; j < N; j++) {
					s=fr.readLine();
					String[] tok=s.split(" ");
					int[] lnk=new int[tok.length-1];
					for (int k = 1; k < tok.length; k++) {
						int ind=Integer.parseInt(tok[k])-1;
						lnk[k-1]=ind;
						mat[j][ind]=true;
						for (int l = 0; l < N; l++) {
							if (mat[ind][l]) mat[j][l]=true;							
						}
					}
					Arrays.sort(lnk);
					ll.add(lnk);
					for (int l = 0; l < N; l++) {
						if (!mat[l][j]) continue;						
						for (int l2 = 0; l2 < N; l2++) {					
							if (mat[j][l2]) mat[l][l2]=true;
						}
					}					
				}
				for (int j = 0; j < N && !flag; j++) {
					int[] lnk=ll.get(j);
					for (int k = 0; k < lnk.length-1 && !flag; k++) {
						for (int k2 = k+1; k2 < lnk.length && !flag; k2++) {
							for (int l = 0; l < N && !flag; l++) {
								if (mat[lnk[k]][l] && mat[lnk[k2]][l]) flag=true;
							}
						}
					}
				}
				s="Case #"+i+": "+((flag)?"Yes":"No");				
				fw.write(s +"\n");
				System.out.println(s);
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
