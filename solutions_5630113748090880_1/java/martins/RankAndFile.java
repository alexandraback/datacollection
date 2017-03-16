import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;

public class RankAndFile {
	static PrintWriter w; static final String url = "B-large.in";
	static int[] count;
	static int N;
	public static void main(String...thegame)throws Exception{
		BufferedReader br = new BufferedReader(new FileReader(new File(url)));
		w = new PrintWriter("rankandfile.txt", "UTF-8");
		int T = Integer.parseInt(br.readLine());
		for(int t = 0; t < T; t++){
			count = new int[2501];
			N = Integer.parseInt(br.readLine());
			for(int i = 0; i < 2*N-1; i++){
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++){
					int k = Integer.parseInt(st.nextToken());
					count[k]++;
				}
			}
			w.print(String.format("Case #%d: %s\n",t+1,process()));
		}
		w.close();
	}
	public static String process(){
		StringBuilder res = new StringBuilder();
		ArrayList<Integer> l = new ArrayList<>();
		for(int i = 1; i <= 2500; i++){
			if(count[i]%2!=0) l.add(i);
		}
		Collections.sort(l);
		for(int k: l) res.append(k+" ");
		return res.toString().trim();
	}
}
