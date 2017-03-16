import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TaskA {

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	void run() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		String s1 = br.readLine();
		st = new StringTokenizer(s1);
		int t = Integer.parseInt(st.nextToken());
		for (int i1 = 1; i1 <= t; i1++) {
			out.print("Case #" + i1 + ": ");
			s1 = br.readLine();
			st = new StringTokenizer(s1);
			String s = st.nextToken();
			int n = Integer.parseInt(st.nextToken());
			long one = 1;
			long p = one * s.length() * (s.length() + 1) / 2;
			
			if (n > 1) {
				int l = 0;
				int k = 0;
				for (int i = 0; i < s.length(); i++) {
					if ((s.charAt(i) != 'a') && (s.charAt(i) != 'e')
							&& (s.charAt(i) != 'i') && (s.charAt(i) != 'o')&&(s.charAt(i) != 'u')) {
						k++;
					} else {
						k = 0;
					}
					if (k == n) {
						p = p - one * (i - l) * (i - l + 1) / 2 + one * (n - 2)
								* (n - 1) / 2;
						l = i - n + 2;
						k--;
					}
				}
				p = p - one * (s.length() - l) * (s.length() - l + 1) / 2;
			}
			if (n==1){
				int k = 0;
				for (int i = 0; i < s.length(); i++){
					if ((s.charAt(i) == 'a') || (s.charAt(i) == 'e')
							|| (s.charAt(i) == 'i') || (s.charAt(i) == 'o')||(s.charAt(i) == 'u')) {
						k++;
					} else {
						p -= one*k*(k+1)/2;
						k = 0;
					}
				}
				p -= one*k*(k+1)/2;
			}
			/*long pp = 0;
			for ( int i = 0; i < s.length(); i++){
				for ( int j = i; j <s.length(); j++){
					int k = 0;
					for (int q = i; q <=j; q++){
						if ((s.charAt(q) == 'a') || (s.charAt(q) == 'e')
								|| (s.charAt(q) == 'i') || (s.charAt(q) == 'o')) {
							k = 0;
						} else {
							k++;
						}
						if (k>=n){
							break;
						}
					}
					if (k>=n){
						pp++;
					}
				}
			}
			if (p!=pp){
				out.print("Case #" + i1 + ": ");
				out.print(p+" ");
				out.println(pp);
			}*/
			out.println(p);

		}

		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new TaskA().run();
	}

}