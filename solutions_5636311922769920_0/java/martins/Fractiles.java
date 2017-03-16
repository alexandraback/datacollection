import java.io.*;
import java.util.*;
public class Fractiles {
	static PrintWriter w;
	public static void main(String...thegame)throws Exception{
		w = new PrintWriter("fractiles.txt", "UTF-8");
		Scanner seer = new Scanner(System.in);
		int T = seer.nextInt();
		for(int t = 1; t <= T; t++){
			StringBuilder sb = new StringBuilder();
			sb.append(String.format("Case #%d:", t));
			int K = seer.nextInt();
			int C = seer.nextInt();
			int S = seer.nextInt();
			for(int i = 1; i <= S; i++){
				sb.append(" "+i);
			}
			w.println(sb.toString().trim());
		}
		w.close();
	}
}
