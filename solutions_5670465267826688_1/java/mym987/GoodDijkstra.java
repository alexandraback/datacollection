import java.io.*;
import java.util.*;

public class GoodDijkstra {
	public static void main(String args[]) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("C-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());

		int n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(f.readLine());
			int L = Integer.parseInt(st.nextToken());
			String s = st.nextToken();
			int X;
			if(s.length()>2) X = Integer.parseInt(s.substring(s.length()-2))%4+4;
			else X = Integer.parseInt(s);
			
			StringBuilder sb = new StringBuilder();
			st = new StringTokenizer(f.readLine());
			s = st.nextToken();
			for(int j=0;j<X;j++){
				sb.append(s);
			}
			//System.out.println(sb.toString());
			int pos1 = 0, pos2 = sb.length()-1;
			boolean sign = true;
			char c = '1';
			for(;pos1<sb.length();pos1++){
				//System.out.print(sign+" "+c+" ");
				char c1 = sb.charAt(pos1);
				//System.out.print(c1+" ");
				if(c == '1') c = c1;
				else if (c1 != '1'){
					if(c==c1){sign=!sign;c='1';}
					else{
						if((c=='i'&&c1=='k')||(c=='j'&&c1=='i')||(c=='k'&&c1=='j'))sign=!sign;
						c=(char)(318-c-c1);
					}
				}
				//System.out.println(c+" "+sign);
				if(c=='i' && sign)break;
			}
			if(pos1>=sb.length()){
				out.format("Case #%d: NO\n", i+1);
				continue;
			}
			
			c='1';sign=true;
			for(;pos2>0;pos2--){
				char c1 = sb.charAt(pos2);
				//System.out.print(sign+" "+c1+" "+c+" ");
				if(c == '1') c = c1;
				else if (c1 != '1'){
					if(c==c1){sign=!sign;c='1';}
					else{
						if((c=='k'&&c1=='i')||(c=='i'&&c1=='j')||(c=='j'&&c1=='k'))sign=!sign;
						c=(char)(318-c-c1);
					}
				}
				//System.out.println(c+" "+sign);
				if(c=='k' && sign)break;
			}
			if(pos2<=0){
				out.format("Case #%d: NO\n", i+1);
				continue;
			}
			if(pos1>=pos2){
				out.format("Case #%d: NO\n", i+1);
				continue;
			}
			//out.println(pos1+" "+pos2);
			c='1';sign=true;
			for(int pos=pos1+1;pos<pos2;pos++){
				char c1 = sb.charAt(pos);
				if(c == '1') c = c1;
				else if (c1 != '1'){
					if(c==c1){sign=!sign;c='1';}
					else{
						if((c=='i'&&c1=='k')||(c=='j'&&c1=='i')||(c=='k'&&c1=='j'))sign=!sign;
						c=(char)(318-c-c1);
					}
				}
			}
			if(c!='j' || !sign){
				out.format("Case #%d: NO\n", i+1);
				continue;
			}

			out.format("Case #%d: YES\n", i+1);
		}
		out.close();
		System.exit(0);
	}
}