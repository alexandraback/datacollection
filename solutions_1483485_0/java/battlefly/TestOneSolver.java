import java.io.BufferedReader;
import java.io.IOException;

public class TestOneSolver {

	public StringBuilder process(BufferedReader in, StringBuilder builder)
			throws IOException {
		in.readLine();
		String line = in.readLine();
		int count = 1;
		while (line != null) {
			line = line.replace('y', bigger('a'));
			line = line.replace('n', bigger('b'));
			line = line.replace('f', bigger('c'));
			line = line.replace('i', bigger('d'));
			line = line.replace('c', bigger('e'));
			line = line.replace('w', bigger('f'));
			line = line.replace('l', bigger('g'));
			line = line.replace('b', bigger('h'));
			line = line.replace('k', bigger('i'));
			line = line.replace('u', bigger('j'));
			line = line.replace('o', bigger('k'));
			line = line.replace('m', bigger('l'));
			line = line.replace('x', bigger('m'));
			line = line.replace('s', bigger('n'));
			line = line.replace('e', bigger('o'));
			line = line.replace('v', bigger('p'));
			line = line.replace('z', bigger('q'));
			line = line.replace('p', bigger('r'));
			line = line.replace('d', bigger('s'));
			line = line.replace('r', bigger('t'));
			line = line.replace('j', bigger('u'));
			line = line.replace('g', bigger('v'));
			line = line.replace('t', bigger('w'));
			line = line.replace('h', bigger('x'));
			line = line.replace('a', bigger('y'));
			line = line.replace('q', bigger('z'));

			for (int i = 0; i < 26; i++) {
				line = line.replace(bigger((char)('a'+i)), (char)('a'+i));
			}
			appendLine(line, builder,count);
			count++;
			line = in.readLine();
		}
		return builder;
	}

	private char bigger(char c) {
		c = (char) ((byte) c + 50);
		return c;
	}

	private static void appendLine(String line, StringBuilder builder, int count) {
		builder.append("Case #"+count+": "+line + "\r\n");
	}
}
