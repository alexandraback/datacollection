import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class R1BA {
	
	public static void main(String[] args)throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int t=Integer.parseInt(br.readLine());
		
		for(int z=1; z<=t; z++){
			String s=br.readLine();
			//ONE
			//THREE
			//NINE
			int ch[]=new int[26];
			int l=s.length();
			for(int i=0; i<l; i++){
				ch[s.charAt(i)-'A']++;
			}
			int num[]=new int[10];
			num[0]=ch[26-1];//chars of z
			ch['E'-'A']-=num[0];
			ch['R'-'A']-=num[0];
			ch['O'-'A']-=num[0];
			num[2]=ch['W'-'A'];//chars of z
			ch['T'-'A']-=num[2];
			ch['O'-'A']-=num[2];
			num[4]=ch['U'-'A'];//chars of z
			ch['F'-'A']-=num[4];
			ch['O'-'A']-=num[4];
			ch['R'-'A']-=num[4];
			num[5]=ch['F'-'A'];//chars of z
			ch['I'-'A']-=num[5];
			ch['V'-'A']-=num[5];
			ch['E'-'A']-=num[5];
			num[6]=ch['X'-'A'];//chars of z
			ch['S'-'A']-=num[6];
			ch['I'-'A']-=num[6];
			num[7]=ch['S'-'A'];//chars of z
			ch['E'-'A']-=num[7];
			ch['E'-'A']-=num[7];
			ch['V'-'A']-=num[7];
			ch['N'-'A']-=num[7];
			num[8]=ch['G'-'A'];//chars of z
			ch['E'-'A']-=num[8];
			ch['I'-'A']-=num[8];
			ch['H'-'A']-=num[8];
			ch['T'-'A']-=num[8];
			num[9]=ch['I'-'A'];//chars of z
			ch['N'-'A']-=num[9];
			ch['N'-'A']-=num[9];
			ch['E'-'A']-=num[9];
			num[1]=ch['O'-'A'];//chars of z
			ch['N'-'A']-=num[1];
			ch['E'-'A']-=num[1];
			num[3]=ch['T'-'A'];//chars of z
			ch['H'-'A']-=num[7];
			ch['R'-'A']-=num[7];
			ch['E'-'A']-=num[7];
			ch['E'-'A']-=num[7];
			String ns="";
			for(int j=0;j<10; j++){
				for(int k=0; k<num[j]; k++){
					ns=ns+j;
				}
			}
			System.out.println("Case #"+z+": "+ns);
		}
	}
}
