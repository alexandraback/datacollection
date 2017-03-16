import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Lottery {
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T =Integer.parseInt(in.readLine());
		for (int caso = 1; caso <=T; caso++) {
			String[] l = in.readLine().split(" ");
			int A = Integer.parseInt(l[0]);
			int B = Integer.parseInt(l[1]);
			int K = Integer.parseInt(l[2]);
			int ans = 0;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < B; j++) {
					if((i&j)<K)
						ans++;
				}
			}
			System.out.println("Case #"+caso+": "+ans);
		}
	}
}
