import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class qualC {
	
	static int mlt(int a,int b){
		int va=Math.abs(a),vb=Math.abs(b);
		if (va==1 || vb==1) return a*b;
		if (va==vb) return (a*b>0)?-1:1;
		for (int i = 2; i <= 4; i++) {
			if (va!=i && vb!=i)
				return i*((a*b>0)?1:-1)*((va<vb)?1:-1)*((Math.abs(va-vb)<2)?1:-1);			
		}
		return 0;
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
				int L=Integer.parseInt(tok[0]);
				int X=Integer.parseInt(tok[1]);
				s=fr.readLine();
				int tt=1;
				for (int j = 0; j < L; j++) tt=mlt(tt,s.charAt(j)-'g');				
				boolean rs=false;
				if ((tt==-1 && X%2==1) || (Math.abs(tt)>1 && X%4==2)) {					
					System.out.println(tt);
					int op=1,tp=tt; 
					boolean io=false,it=false,jo=false,jt=false;
					if (X==1){
						for (int j = 0; j < L && !rs; j++) {
							op=mlt(op,s.charAt(j)-'g');
							if (Math.abs(op)==2) io=true;
							if (Math.abs(op)==4) rs=io;
						}
					}
					else if (X==2) {
						for (int j = 0; j < L && !rs; j++) {
							op=mlt(op,s.charAt(j)-'g');
							if (Math.abs(op)==2) {io=true; rs=jt;}
							if (Math.abs(op)==4) rs=io;
							tp=mlt(tp,s.charAt(j)-'g');
							if (Math.abs(tp)==2) it=true;
							if (Math.abs(tp)==4) {jt=true; rs=(io || it);}
						}
					}
					else {
						for (int j = 0; j < L && !rs; j++) {
							op=mlt(op,s.charAt(j)-'g');
							if (Math.abs(op)==2) {io=true; rs=(jt || jo);}
							if (Math.abs(op)==4) {jo=true; rs=(io || it);}
							tp=mlt(tp,s.charAt(j)-'g');
							if (Math.abs(tp)==2) {it=true; rs=jo;}
							if (Math.abs(tp)==4) {jt=true; rs=(io || it);}
						}
					}
				}
				s=rs? "YES":"NO";
				System.out.println(s);
				fw.write("Case #"+i+": "+ s +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}