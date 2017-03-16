import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class LastWord {
	static PrintWriter w; static final String url = "A-large.in";
	public static void main(String...thegame)throws Exception{
		BufferedReader br = new BufferedReader(new FileReader(new File(url)));
		w = new PrintWriter("lastword.txt", "UTF-8");
		int T = Integer.parseInt(br.readLine());
		for(int t = 0; t < T; t++){
			w.print(String.format("Case #%d: %s\n",t+1,process(br.readLine())));
		}
		w.close();
	}
	public static String process(String s){
		char[] ch = s.toCharArray();
		StringBuilder sb = new StringBuilder();
		char maxc = 'A'-1;
		for(char c : ch){
			if(c >= maxc){
				sb.replace(0,0,c+"");
				maxc = c;
			}
			else{
				sb.append(c);
			}
		}
		return sb.toString();
	}
}
