import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class A {
    private static final Map<Character, Character> map = new HashMap<Character, Character>();
    static {
        String[] inputs = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                           "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                           "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
        String[] outputs = {
                "our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up"};

        for (int i = 0; i < inputs.length; i++) {
            String in = inputs[i];
            String out = outputs[i];
            for (int j = 0; j < in.length(); j++) {
                char from = in.charAt(j);
                char to = out.charAt(j);
                if (map.get(from) == null || map.get(from) == to) {
                    map.put(from, to);
                } else {
                    throw new RuntimeException();
                }
            }
        }
        map.put('z', 'q');
        map.put('q', 'z');
        /*
        Set<Character> all = new HashSet<Character>();
        for (int i = 0; i < 26; i++) {
            all.add((char) ('a' + i));
        }
        Set<Character> inSet = new HashSet<Character>();
        Set<Character> outSet = new HashSet<Character>();
        for (Character character : map.keySet()) {
            inSet.add(character);
        }
        for (Character character : map.values()) {
            outSet.add(character);
        }
        Set<Character> missingIn = new HashSet<Character>(all);
        missingIn.removeAll(inSet);
        Set<Character> missingOut = new HashSet<Character>(all);
        missingOut.removeAll(outSet);
        System.out.println(missingIn);
        System.out.println(missingOut);
        */
    }

	private static String FILENAME = "stdin";
	static {
		//FILENAME = "A-sample";
		FILENAME = "A-small";
		//FILENAME = "A-large";
	}

	public static void main(String[] args) throws IOException {
		new A().run();
	}

	private PrintStream out;
	private final BufferedReader reader;
	private StringTokenizer tokenizer = new StringTokenizer("");

	public A() {
		try {
			out = System.out;
			if (FILENAME == "stdin") {
				reader = new BufferedReader(new InputStreamReader(System.in));
			} else {
				out = new PrintStream(new FileOutputStream("source/" + FILENAME + ".out"));
				reader = new BufferedReader(new FileReader("source/" + FILENAME + ".in"));
			}
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}
	}

	public void run() throws IOException {
		try {
			runCases();
		} finally {
			closeAll();
		}
	}

	private void runCode() throws IOException {
        String s = reader.readLine();
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            Character to = map.get(c);
            if (to == null) {
                throw new RuntimeException("Could not find translation for '" + c + "'");
            }
            res.append(to);
        }
		out.println(res.toString());
	}

	private void runCases() throws IOException {
		int cases = getInt();
		for (int c = 1; c <= cases; c++) {
			out.print("Case #" + c + ": ");
			runCode();
		}
	}

	private void closeAll() {
		out.close();
	}

	private String getToken() {
		try {
			while (true) {
				if (tokenizer.hasMoreTokens()) {
					return tokenizer.nextToken();
				}
				String s = reader.readLine();
				if (s == null) {
					return null;
				}
				tokenizer = new StringTokenizer(s, " \t\n\r");
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	public double getDouble() {
		return Double.parseDouble(getToken());
	}

	public int getInt() {
		return Integer.parseInt(getToken());
	}

	public long getLong() {
		return Long.parseLong(getToken());
	}

	public BigInteger getBigInt() {
		return new BigInteger(getToken());
	}

	public BigDecimal getBigDec() {
		return new BigDecimal(getToken());
	}

}
