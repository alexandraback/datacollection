import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Consonants{
	static boolean vowel(char c){
		return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
	}
	public static void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
		int t = Integer.valueOf(br.readLine());
		for(int tt=0; tt<t; tt++){
			String[] ss = br.readLine().trim().split("\\s+");
			int n = Integer.valueOf(ss[1]);
			int cnt = 0;
			for(int i=0; i<ss[0].length(); i++){
				for(int j=i+1; j<=ss[0].length(); j++){
					String s = ss[0].substring(i, j);
					int cons = 0;
					int maxcon = 0;
					// out.println("substring: "+s);
					for(int k=0; k<s.length(); k++){
						if(vowel(s.charAt(k))){
							cons = 0;
						}else{
							cons++;
							maxcon = max(maxcon, cons);
						}
					}
					if(maxcon>=n)
						cnt++;
				}
			}
			out.printf("Case #%d: %d\n", tt+1, cnt);
		}
		bw.flush();
	}
}
