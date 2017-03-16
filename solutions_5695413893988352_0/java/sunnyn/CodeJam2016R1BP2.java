import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CodeJam2016R1BP2 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int caseid=1; caseid<=T; caseid++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			String s1 = st.nextToken();
			String s2 = st.nextToken();

			int len = s1.length();
			int low = 0; 
			int high = 0;
			if(len ==1) {
				high = 10;
			} else if(len == 2) {
				high = 100;
			} else {
				high = 1000;
			}

			int mindiff = 1000;
			int minscore = 100000;
			int C =0,J=0;
			for(int i = 0; i < high; i++) {
				for(int j = 0; j < high; j++) {
					if(match(s1,i)&&match(s2,j)) {
						int score = Math.abs(i-j);
						if(Math.abs(i-j) < mindiff) {
							mindiff = score;
							minscore = i + j;
							C = i;
							J = j;
						} else if(score == mindiff) {
							if(i + j < minscore) {
								minscore = i + j;
								C = i; 
								J = j;
							} else if(i+j == minscore) {
								if(j < J) {
									J = j;
									C = i;
								}
							}
						}
					}
				}
			}
			
			String c = C+"";
			int cc = c.length();
			String j = J+"";
			int jj = j.length();


			System.out.println("Case #"+caseid + ": " + ("000".substring(0, len-cc)+c) + " " + ("000".substring(0, len-jj)+j));
		}
	}
	public static boolean match(String s, int tt) {
		String ttt = tt+"";
		int len = ttt.length();
		int l = s.length();
		String t = "000".substring(0, l-len) + ttt;
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) != '?') {
				if(s.charAt(i)!=t.charAt(i)) return false;
			}
		}
		return true;
	}

}
