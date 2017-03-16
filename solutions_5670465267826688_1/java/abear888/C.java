import java.io.*;
import java.util.*;

public class C {
	public static void main (String[]args)throws IOException{
		BufferedReader f=new BufferedReader(new FileReader("Clarge.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Clarge.out")));
		int t=Integer.parseInt(f.readLine());
		for (int cases=1; cases<=t; cases++){
			StringTokenizer st=new StringTokenizer(f.readLine());
			int l=Integer.parseInt(st.nextToken());
			long x=Long.parseLong(st.nextToken());
			String stuff=f.readLine();
			String s="";
			if (x<8){
				for (int i=0; i<x; i++){
					s+=stuff;
				}
			}else{
				for (int i=0; i<8; i++){
					s+=stuff;
				}
			}
			char cur=s.charAt(0);
			boolean pos=true;
			boolean hasi=false;
			boolean hask=false;
			char blockend='0';
			boolean posend=false;
			for (int i=1; i<s.length(); i++){
				char c=s.charAt(i);
				if (cur=='i'){hasi=true;}
				if (cur=='k' && hasi){hask=true;}
				if (cur=='1'){
					cur=c;
				}else if (cur=='i'){
					if (c=='i'){cur='1';pos=!pos;}
					if (c=='j'){cur='k';}
					if (c=='k'){cur='j';pos=!pos;}
				}else if (cur=='j'){
					if (c=='i'){cur='k';pos=!pos;}
					if (c=='j'){cur='1';pos=!pos;}
					if (c=='k'){cur='i';}
				}else if (cur=='k'){
					if (c=='i'){cur='j';}
					if (c=='j'){cur='i';pos=!pos;}
					if (c=='k'){cur='1';pos=!pos;}
				}
				if (i==l-1){
					blockend=cur;
					posend=pos;
				}
			}
			if (x<8){
				if (hask && cur=='1' && !pos){
					out.println("Case #"+cases+": YES");
				}else{
					out.println("Case #"+cases+": NO");
				}
			}else{
				if (hask && ((blockend=='1' && !posend && x%2==1)||(blockend!='1' && x%4==2))){
					out.println("Case #"+cases+": YES");
				}else{
					out.println("Case #"+cases+": NO");
				}
			}
		}
		out.close();
		System.exit(0);
	}
}