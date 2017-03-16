import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class FairAndSquare{
	static boolean pal(String s){
		for(int i=0, j=s.length()-1; i<j; i++, j--){
			if(s.charAt(i)!=s.charAt(j))
				return false;
		}
		return true;
	}
	public static void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
		ArrayList<Long> fas = new ArrayList<Long>();
		for(long i=1; i<=10000000; i++){
			long j = i*i;
			if(pal(i+"") && pal(j+"")){
				fas.add(j);
			}
		}
		// out.println(fas.toString());
		int t = Integer.valueOf(br.readLine());
		for(int tt=0; tt<t; tt++){
			String[] ss = br.readLine().trim().split("\\s+");
			long a = Long.valueOf(ss[0]);
			long b = Long.valueOf(ss[1]);
			int cnt = 0;
			for(int i=0; i<fas.size(); i++){
				if(fas.get(i)>=a && fas.get(i)<=b){
					cnt++;
				}
			}
			out.printf("Case #%d: %d\n", tt+1, cnt);
		}
		bw.flush();
	}
}
