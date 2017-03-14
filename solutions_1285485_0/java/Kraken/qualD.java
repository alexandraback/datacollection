import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;

public class qualD {
	
	static int gcd(int a,int b) {
		if (b==0) return a;
		return gcd(b,a%b);		
	}
	
	static int countquad(int r,int c,int d,int nr,int nc) {
		int d2=d*d;
		boolean pr=false;
		HashSet<Integer> hs=new HashSet<Integer>();
		for (int i = nr; i*i <= d2; i+=(pr)?r:nr) {
			int lm=d2-i*i;
			boolean pc=true;
			for (int j = 0; j*j <= lm; j+=(pc)?c:nc) {
				if (i==0 && j==0) continue;
				int g=gcd(Math.max(i,j),Math.min(i,j));
				int ind=(i/g * 1000)+j/g;
				if (!hs.contains(ind)) {
					hs.add(ind);
				}
				pc^=true;
			}
			pr^=true;
		}
		return (hs.size());
	}
	
	public static void main(String[] args) {
		String prblm="D"; boolean fl=!true;
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
				int H=Integer.parseInt(tok[0]);
				int W=Integer.parseInt(tok[1]);
				int d=Integer.parseInt(tok[2]);
				int row=0,col=0;
				for (int j = 0; j < H; j++) {
					s=fr.readLine();
					int ind=s.indexOf("X");
					if (ind!=-1){ row=j*2-1; col=ind*2-1; }
				}
				H=2*H-4;
				W=2*W-4;
				int nrefl=countquad(row,col,d,H-row,W-col);
				nrefl+=countquad(H-row,W-col,d,row,col);
				nrefl+=countquad(col,H-row,d,W-col,row);
				nrefl+=countquad(W-col,row,d,col,H-row);
				System.out.println(i+" ("+d+"):  "+nrefl);
				fw.write("Case #"+i+": "+ nrefl  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}
