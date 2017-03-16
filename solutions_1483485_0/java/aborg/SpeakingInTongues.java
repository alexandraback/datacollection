package googlecodejam2012.qualification.speakingintongues;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

public class SpeakingInTongues {
	static char[] decode = new char[] { 'y'/* a */, 'h'/* b */, 'e'/* c */,
			's'/* d */, 'o'/* e */, 'c'/* f */, 'v'/* g */, 'x'/* h */,
			'd'/* i */, 'u'/* j */, 'i'/* k */, 'g'/* l */, 'l'/* m */,
			'b'/* n */, 'k'/* o */, 'r'/* p */, 'z'/* q */, 't'/* r */,
			'n'/* s */, 'w'/* t */, 'j'/* u */, 'p'/* v */, 'f'/* w */,
			'm'/* x */, 'a'/* y */, 'q' /* z */};

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(args[1]): new OutputStreamWriter(System.out));
			try {
				int numLines = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= numLines;++i) {
					String line = br.readLine();
					out.write("Case #" + i + ": "+decode(line) + lineSep);
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
	}

	private static String decode(String line) {
		char[] content = line.toCharArray();
		for (int i = 0; i < content.length; i++) {
			char c = content[i];
			if (c != ' ') {
				content[i] = decode[c - 'a'];
			}
		}
		return new String(content);
	}

}
