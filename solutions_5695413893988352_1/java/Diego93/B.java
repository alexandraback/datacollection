import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class B {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("b.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("b.out"));
		int N = s.nextInt();
		s.nextLine();
		for(int i=0; i<N; i++){
			StringBuffer str = new StringBuffer();
			String[] inString = s.nextLine().split(" ");
			char[] s1 = inString[0].toCharArray();
			char[] s2 = inString[1].toCharArray();
			int c_j = 0;
			for(int j=0; j<s1.length; j++){
				switch (c_j) {
				case 1:
					if(s1[j]=='?'){
						s1[j]='0';
					}
					if(s2[j]=='?'){
						s2[j]='9';
					}
					break;
				case 0:
					if(s1[j]=='?' && s2[j]=='?'){
						s1[j]='0';
						s2[j]='0';
						break;
					}
					if(s1[j]!='?' && s2[j]!='?'){
						if(s1[j]==s2[j]) break;
						c_j = (s1[j]>s2[j]?1:-1);
						break;
					}
					if(s1[j]=='?'){
						s1[j]=s2[j];
					}else{
						s2[j]=s1[j];
					}
					break;
				case -1:
					if(s1[j]=='?'){
						s1[j]='9';
					}
					if(s2[j]=='?'){
						s2[j]='0';
					}
					break;
				}
			}
			out.write("Case #"+(i+1)+": "+String.valueOf(s1)+" "+String.valueOf(s2)+"\n");
		}
		out.close();	
	}
}
