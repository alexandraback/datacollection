import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A {

	public String solve(String src, String dst, String line) {
		char[] map = new char[26];
		map['z'-'a'] = 'q';
		map['q'-'a'] = 'z';
		for (int i=0; i<dst.length(); i++) {
			if (dst.charAt(i) == ' ') {
				if (src.charAt(i) != ' ') {
					System.out.println("index " + i + " not a space");
				}
				continue;
			} else {
				int c = dst.charAt(i) - 'a';
				char d = src.charAt(i);
				if (map[c] != 0) {
					if (map[c] != d) {
						System.out.println("index " + i + " should be " + map[c] + " but is " + d);
					}
				} else {
					map[c] = d;
				}
			}
		}
		for (int i=0; i<26; i++) {
			if (map[i] == 0) {
				System.out.println("no map for char " + (char)(i+'a'));
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<line.length(); i++) {
			if (line.charAt(i) == ' ') {
				sb.append(' ');
			} else {
				int c = line.charAt(i) - 'a';
				char d = map[c];
				if (d != 0) {
					sb.append(d);
				} else {
					System.out.println("append unknow index " + i);
				}
			}
		}
		return sb.toString() + "\n";
	}

	////////////////////////////////////////
	// read input
	////////////////////////////////////////
	public String runInput(BufferedReader br) throws IOException {
		String src = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
		String dst = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";

		String line = br.readLine();
		return solve(src, dst, line);
	}

	////////////////////////////////////////
	// main
	////////////////////////////////////////
	public static void main(String[] args) {
		A a = new A();
		try {
			a.parseFile("A-sample");
			a.parseFile("A-small-attempt0");
			//a.parseFile("A-large");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	////////////////////////////////////////
	// library
	////////////////////////////////////////
	public void parseFile(String filePrefix) throws IOException {
		String fileIn = filePrefix + ".in";
		String fileOut = filePrefix + ".out";

		BufferedReader br = new BufferedReader(new FileReader(fileIn));
		BufferedWriter bw = new BufferedWriter(new FileWriter(fileOut));

		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			String ret = "Case #" + i + ": ";
			ret += runInput(br);
			System.out.print(ret);
			bw.write(ret);
		}
		br.close();
		bw.close();
	}

}
