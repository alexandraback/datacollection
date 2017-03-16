import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.RandomAccessFile;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.InputMismatchException;

public class Main {
	
	public static void main(String[] args) throws Exception {

    /*		
		FileInputStream fin=new FileInputStream("C:/Users/4dm1n/Desktop/C-small-attempt1.in");
		BufferedReader br=new BufferedReader(new InputStreamReader(fin));	
		File myfile=new File("C:/Users/4dm1n/Desktop/z_output.out");
		RandomAccessFile rand=new RandomAccessFile(myfile,"rw");
    */		
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		
		int t,P,J,S,K,sc,pc,jc,i,j,k,tt,c,total;
		long ff,ll;
		String s[];
		char sf[],sl[];
		StringBuilder sb,st;
		t=Integer.parseInt(br.readLine());
		for(tt=1;tt<=t;tt++){
			sb=new StringBuilder("Case #"+tt+": ");
			st=new StringBuilder("");
			s=br.readLine().split(" ");
			J=Integer.parseInt(s[0]);P=Integer.parseInt(s[1]);S=Integer.parseInt(s[2]);K=Integer.parseInt(s[3]);
			sc=pc=jc=c=0;
		//	System.out.println(J+" "+P+" "+S);
			for(i=1;i<=J;i++){
				pc=0;
				for(j=1;j<=Math.min(P, K);j++){
					k=(jc/K+pc/K)*K+1;
				//	System.out.print("k= "+k);
					sc=0;
					for(;k<=Math.min(S, K);k++){
						st.append("\n"+i+" "+j+" "+k);
						sc++;c++;
						if(sc==K) break;
					}
					pc++;
				}
				jc++;
			}
			
/*			
			for(i=1;i<=S;i++){
				pc=0;
				for(j=1;j<=P;j++){
					k=(sc/K+pc/K)*K+1;
					System.out.print("k= "+k);
					jc=0;
					for(;k<=J;k++){
						st.append("\n"+i+" "+j+" "+k);
						jc++;c++;
						if(jc==K) break;
					}
					pc++;
				}
				sc++;
			}
*/			sb.append(c);
			sb.append(st);
			
			
			
			
			
			sb.append("\n");
//			rand.writeBytes(sb.toString());
			System.out.print(sb);
		}
	}
}