import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class B {
	static char[] s1,s2,s;
	static int min=1000000000,minn1=1000000000,minn2=1000000000;
	
	static void rec(int ind){
		if(ind==s.length){
			calc();
			return;
		}
		if(s[ind]!='?'){
			rec(ind+1);
		}
		else{
			for(int i=0;i<10;i++){
				s[ind]=(char)('0'+i);
				rec(ind+1);
				s[ind]='?';
			}
		}
	}
	static void calc(){
		int n1 = 0,n2=0;
		for(int i=0;i<s.length/2;i++){
			n1*=10;
			n1+=s[i]-'0';
		}
		for(int i = s.length/2;i<s.length;i++){
			n2*=10;
			n2+=s[i]-'0';
		}
		if(Math.abs(n1-n2)<min){
			min = Math.abs(n1-n2);
			minn1=n1;
			minn2=n2;
		}
		else if(Math.abs(n1-n2)==min){
			if(n1<minn1){
				minn1=n1;
				minn2=n2;
			}
			else if(n1==minn1 && n2<minn2){
				minn2=n2;			}
		}
	}
	static public void main(String[] args)throws Exception{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter("output.txt");
		
		int t  = Integer.parseInt(br.readLine());
		for(int z=1;z<=t;z++){
			String[]in = br.readLine().split(" ");
			s1 = in[0].toCharArray();
			s2 = in[1].toCharArray();
			String str = in[0]+in[1];
			s = str.toCharArray();
			min=minn1=minn2=1000000000;
			rec(0);
			
			StringBuilder res = new StringBuilder();
			for(int i=0;i<s1.length-Integer.toString(minn1).length();i++){
				res.append(0);
			}
			res.append(minn1);
			res.append(" ");
			for(int i=0;i<s1.length-Integer.toString(minn2).length();i++){
				res.append(0);
			}
			res.append(minn2);
			out.println("Case #"+z+": "+res.toString());
		}
		br.close();
		out.close();
	}
}
