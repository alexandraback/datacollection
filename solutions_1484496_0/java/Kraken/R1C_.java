import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1C_ {
	
	static boolean[][] sm;
	static int[] assgn;
	static int[] rt;
	static int nassg=0;
	static int[] num;
	
	static boolean ssm(int nm,int diff){
		//System.out.println(nm+" "+diff);
		if (diff==0 && nassg>0) return true;
		if (nm>=num.length) return false;
		if (diff>rt[nm]) return false;
		if (!sm[diff][nm]){
			if (ssm(nm+1,diff)) {
				assgn[nm]=0;
				return true;
			}
			nassg++;
			if (ssm(nm+1,diff+num[nm])) {
				assgn[nm]=1; 
				return true;
			}			
			if (ssm(nm+1,Math.abs(diff-num[nm]))) {
				if (diff-num[nm]>=0) assgn[nm]=-1;
				else assgn[nm]=-2;
				return true;
			}
			nassg--;
			sm[diff][nm]=true;
		}
		return false;
	}
	
public static void main(String[] args) {
		String prblm="C"; boolean fl=!true;
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
				num=new int[N];
				assgn=new int[N];
				rt=new int[N];
				sm=new boolean[2000000][N];
				for (int j = 0; j < N; j++) {
					num[j]=Integer.parseInt(tok[j+1]);									
				}
				rt[N-1]=num[N-1];
				for (int j = N-2; j >=0; j--) {
					rt[j]=num[j]+rt[j+1];									
				}
				s="Case #"+i+":\n";
				nassg=0;
				if (ssm(0,0)) {
					String s1="";
					String s2="";
					for (int j = 0; j < N; j++) {
						if (assgn[j]==0) continue;
						if (assgn[j]>0) s1+=num[j]+" ";
						if (assgn[j]<0) s2+=num[j]+" ";
						if (assgn[j]==-2) {
							String tmp=s1; s1=s2; s2=tmp;
						}
					}
					s+=s1.substring(0,s1.length()-1)+"\n"+s2.substring(0,s2.length()-1)+"\n";
				}
				else s+="Impossible\n";
				System.out.println(s);
				fw.write(s);
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
