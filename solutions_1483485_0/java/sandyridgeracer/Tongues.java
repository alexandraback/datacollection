import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Tongues {

	public static void putMap(Map<String, String> map) {

		map.put("a", "y");
		map.put("b", "h");
		map.put("c", "e");
		map.put("d", "s");
		map.put("e", "o");
		map.put("f", "c");
		map.put("g", "v");
		map.put("h", "x");
		map.put("i", "d");
		map.put("j", "u");
		map.put("k", "i");
		map.put("l", "g");
		map.put("m", "l");
		map.put("n", "b");
		map.put("o", "k");
		map.put("p", "r");
		map.put("q", "z");
		map.put("r", "t");
		map.put("s", "n");
		map.put("t", "w");
		map.put("u", "j");
		map.put("v", "p");
		map.put("w", "f");
		map.put("x", "m");
		map.put("y", "a");
		map.put("z", "q");
		map.put(" ", " ");
	}

	public static void main(String[] args) throws IOException {
		String msg = "";
		BufferedReader br = null;
		String sCurrentLine = null;
		Map<String, String> map = new HashMap<String, String>();
		putMap(map);
		br = new BufferedReader(new FileReader("test"));
		sCurrentLine = br.readLine();
		int x = 0;
		if (sCurrentLine != null) {
			while ((sCurrentLine = br.readLine()) != null) {
				msg = "";
				x++;
				char[] words = sCurrentLine.toCharArray();
				char[] newWords = new char[sCurrentLine.length()];
				int xx = 0;
				for (char single : words) {
					String mappedValue = map.get(Character.toString(single));
					newWords[xx] = mappedValue.charAt(0);
					xx++;
				}
				String newString = new String(newWords);
				msg += "Case #" + x + ": " + newString;
				System.out.println(msg);
			}
		}

	}
}
