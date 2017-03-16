import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CloseMatch {
	
	private void solve(File in, File out) throws FileNotFoundException {
		Scanner s = new Scanner(in);
		PrintWriter pw = new PrintWriter(out);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			pw.println("Case #" + (i+1) + ": " + solve(s.next(), s.next()));
		}
		pw.flush();
		pw.close();
	}
	
	private String solve(String text1, String text2) {
		StringBuilder sb1 = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();
		int greater = 0;
		boolean go = false;
		for (int i = 0; i < text1.length(); i++) {
			if (greater == 1) {
				sb1.append(0);
				sb2.append(9);
				continue;
			} 
			if (greater == 2) {
				sb1.append(9);
				sb2.append(0);
				continue;
			}
			go = false;
			if (text1.charAt(i) == '?' && text2.charAt(i) == '?') {
				int c = 1;
				while (i + c < text1.length()) {
					if (text1.charAt(i+1) == '?' || text2.charAt(i+1) == '?') {
						c++;
						continue;
						/*sb1.append(0);
						sb2.append(0);
						c++;*/
					}
					if (text1.charAt(i+1) > text2.charAt(i+1) + 5) {
						sb1.append(0);
						sb2.append(1);
						greater = 2;
						go = true;
						break;	
					}
					c++;
				}
				if (go) {
					continue;
				}
				c = 1;
				while (i + c < text1.length()) {
					if (text1.charAt(i+1) == '?' || text2.charAt(i+1) == '?') {
						c++;
						continue;
					}
					if (text2.charAt(i+1) > text1.charAt(i+1) + 5) {
						sb1.append(1);
						sb2.append(0);
						greater = 1;
						go = true;
						break;
					}
					c++;
				}
				if (go) {
					continue;
				}
				sb1.append(0);
				sb2.append(0);
			}
			if (text1.charAt(i) == '?' && text2.charAt(i) != '?') {
				if (greater == 1) {
					sb1.append(0);
					continue;
				} 
				if (greater == 2) {
					sb1.append(9);
					continue;
				}
				sb2.append(text2.charAt(i));
				int c = 1;
				while (i + c < text1.length()) {
					if (text1.charAt(i+1) == '?' || text2.charAt(i+1) == '?') {
						c++;
						continue;
					}
					if (text1.charAt(i+1) > text2.charAt(i+1) + 4) {
						if (text2.charAt(i) == '0') {
							sb1.append(text2.charAt(i));
							go = true;
							break;
						}
						sb1.append((char)(text2.charAt(i) - 1));
						greater = 2;
						go = true;
						break;	
					}
					if (text2.charAt(i+1) > text1.charAt(i+1) + 4) {
						if (text2.charAt(i) == '9') {
							sb1.append(text2.charAt(i));
							go = true;
							break;
						}
						sb1.append((char)(text2.charAt(i) + 1));
						greater = 1;
						go = true;
						break;	
					}	
					c++;
				}
				if (go) {
					continue;
				}
				sb1.append(text2.charAt(i));
			}
			if (text1.charAt(i) != '?' && text2.charAt(i) == '?') {
				if (greater == 1) {
					sb2.append(9);
					continue;
				} 
				if (greater == 2) {
					sb2.append(0);
					continue;
				}
				sb1.append(text1.charAt(i));
 
				int c = 1;
				while (i + c < text1.length()) {
					if (text1.charAt(i+1) == '?' || text2.charAt(i+1) == '?') {
						c++;
						continue;
					}
					if (text2.charAt(i+1) > text1.charAt(i+1) + 4) {
						if (text1.charAt(i) == '0') {
							sb1.append(text1.charAt(i));
							go = true;
							break;
						}
						sb2.append((char)(text1.charAt(i) - 1));
						greater = 1;
						go = true;
						break;
					} 
					if (text1.charAt(i+1) > text2.charAt(i+1) + 4) {
						if (text1.charAt(i) == '9') {
							sb2.append(text1.charAt(i));
							go = true;
							break;
						}
						sb2.append((char)(text1.charAt(i) + 1));
						greater = 2;
						go = true;
						break;
					}
					c++;
				}
				if (go) {
					continue;
				}
				sb2.append(text1.charAt(i));
			}
			if (text1.charAt(i) != '?' && text2.charAt(i) != '?') {
				sb1.append(text1.charAt(i));
				sb2.append(text2.charAt(i));
				if (greater != 0) {
					continue;
				}
				if (text1.charAt(i) < text2.charAt(i)) {
					greater = 2;
				}
				if (text1.charAt(i) > text2.charAt(i)) {
					greater = 1;
				}
			}			
		}
		
		return sb1.toString() + " " + sb2.toString();
	}

	public static void main(String[] args) throws FileNotFoundException {
		File in = new File("in.txt");
		File out = new File("out.txt");
		CloseMatch cm = new CloseMatch();
		cm.solve(in, out);
	}

}
