package google2012;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;

public class QRound_A {
	
	static private char trans[];
	static public void main(String[] args) {
		try {
			trans = new char[100];
			trans[24]=0;
			trans[0]=24;
			trans[4]=14;
			trans[9]=20;
			trans[15]=17;
			trans[12]=11;
			trans[18]=13;
			trans[11]=6;
			trans[2]=4;
			trans[17]=19;
			trans[1]=7;
			trans[3]='s'-'a';
			trans[5]=2;
			trans[6]=21;
			trans[7]=23;
			trans[8]=3;
			trans[10]=8;
			trans[13]=1;
			trans[14]=10;
			trans[16]=0;
			trans['x'-'a']='m'-'a';
			trans['v'-'a']='p'-'a';
			trans['t'-'a']='w'-'a';
			trans['w'-'a']='f'-'a';
			trans['u'-'a']='j'-'a';
			trans['z'-'a']='q'-'a';
			BufferedReader br = new BufferedReader(new FileReader("d:/in.txt"));
			int i=0;
			while (true) {
				String x = br.readLine();
				if (x==null) break;
				if (i!=0)
					run (x, i);
				i++;
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static private void run(String input, int caseid) {
		StringBuilder sb =new StringBuilder();
		for (int i=0;i<input.length();i++) {
			if (' '==input.charAt(i)) {sb.append(' ');continue;}
			char c=(char) (trans[input.charAt(i)-'a']+'a');
			sb.append(c);
		}
		System.out.printf("Case #%d: %s%n", caseid, sb);
	}
}