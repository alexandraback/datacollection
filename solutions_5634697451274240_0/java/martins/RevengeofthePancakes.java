import java.util.*;
import java.io.*;
public class RevengeofthePancakes {
	static PrintWriter w;
	public static void main(String...thegame)throws Exception{
		w = new PrintWriter("pancakes.txt", "UTF-8");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int c = 0; c < t; c++){
			w.println(String.format("Case #%d: %d", c+1,process(br.readLine())));
		}
		w.close();
	}
	public static int process(String st){
		char[] s = st.toCharArray();
		int res = 0; boolean flip = true;
		for(int i = s.length-1; i >= 0; i--){
			if(s[i] == '-' && flip){
				flip = false; res++;
			}
			if(s[i] == '+' && !flip){
				flip = true; res++;
			}
		}
		return res;
	}
}
