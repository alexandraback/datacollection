import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.concurrent.CountDownLatch;


public class A {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	static boolean check(char c){
		return c != 'a' && c != 'e' && c !=  'i' && c != 'o'  && c !=  'u';
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("A-large.in")));
		PrintWriter out = new PrintWriter("out.txt");
		
		int T = Integer.parseInt(br.readLine());
		String [] sp;
		String name;
		int n;
		for (int i = 0; i < T; i++) {
			sp = br.readLine().split(" ");
			name = sp[0];
			n = Integer.parseInt(sp[1]);
			long counter = 0;
			long c = 0, maxc = 0;
			int l = 0, r = 0;
			boolean f = true;
			while(l < name.length() && f){
				while(r < name.length()){
					if(check(name.charAt(r)))
						c++;
					else
						c = 0;
					if(c >= n){
						counter += name.length() - r;
						if(r - l <= n-1)
							c--;
						c -= 1;
						break;
					}
					r++;
				}
				l++;
			}
			maxc = Math.max(maxc, counter);
			counter = 0;
			r = l = name.length() - 1;
			f = true;
			c = 0;
			while(l >= 0){
				while(r >= 0){
					if(check(name.charAt(r)))
						c++;
					else
						c = 0;
					if(c >= n){
						counter += r + 1;
						if( r - l <= n-1)
							c--;
						c -= 1;
						break;
					}
					r--;
				}
				l--;
			}
			maxc = Math.max(maxc, counter);
//			for (int j = 0; j < name.length(); j++) {
//				for (int k = j + n - 1; k < name.length(); k++) {
//					c = 0;
//					maxc = 0;
//					boolean f = false;
//					for (int l = j; l <= k; l++) {
//						if(check(name.charAt(l)))
//							c++;
//						else
//							c = 0;
//						maxc = Math.max(c, maxc);
//					}
//					if(maxc >= n && !f){
//						counter += name.length() - 1 - k;
//						f = true;
//					}
//				}
//			}
			out.append("Case #"+(i+1) +": "+ maxc + "\n");
		}
		out.close();

	}

}
