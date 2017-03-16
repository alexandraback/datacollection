import java.util.HashMap;
import java.util.Map;


public class Googlerese {

	private static Map<String, String> lang = new HashMap<String, String>();
	
	static {
		lang.put("a", "y"); lang.put("e", "o"); lang.put("i", "d"); lang.put("m", "l"); lang.put("q", "z"); lang.put("u", "j");
		lang.put("b", "h"); lang.put("f", "c"); lang.put("j", "u"); lang.put("n", "b"); lang.put("r", "t"); lang.put("v", "p");
		lang.put("c", "e"); lang.put("g", "v"); lang.put("k", "i"); lang.put("o", "k"); lang.put("s", "n"); lang.put("w", "f");
		lang.put("d", "s"); lang.put("h", "x"); lang.put("l", "g"); lang.put("p", "r"); lang.put("t", "w"); lang.put("x", "m");
		lang.put("y", "a"); lang.put("z", "q"); lang.put(" ", " ");
	}
	
	public static String convert(String in) {
		StringBuffer buff = new StringBuffer();
		for (char ch : in.toCharArray()) {
			buff.append(lang.get("" + ch));
		}
		return buff.toString();
	}
	
	public static void main(String[] args) throws Exception {
		String[] in = ProblemUtils.readInput("/home/laf/Downloads/A-small-attempt3.in");
		String[] out = new String[in.length];
		for (int i = 0; i < in.length; i++) {
			out[i] = convert(in[i]);
		}
		ProblemUtils.writeOutput("/home/laf/Desktop/out.txt", out);
	}
	
}
