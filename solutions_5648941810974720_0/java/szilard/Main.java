import java.util.ArrayList;
import java.util.List;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Map;
import java.util.Locale;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.File;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "A-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();

        Map<Character, Integer> sureMap = new HashMap<Character, Integer>();
        sureMap.put('Z', 0);
        sureMap.put('W', 2);
        sureMap.put('U', 4);
        sureMap.put('X', 6);
        sureMap.put('G', 8);


        Map<Character, Integer> sureMap2 = new HashMap<Character, Integer>();
        sureMap2.put('O', 1);
        sureMap2.put('R', 3);
        sureMap2.put('F', 5);
        sureMap2.put('S', 7);

        // 9 remains;

        Map<Character, Integer> histA = new HashMap<Character, Integer>();

        for (int i = 0; i < 26; i++) {
            histA.put((char) ('A' + i), 0);
        }

        for (int i = 0; i < s.length(); i++) {
            histA.put(s.charAt(i), histA.get(s.charAt(i)) + 1);
        }

        int[] hist = new int[10];

        List<Integer> list = new ArrayList<Integer>();

        for (Map.Entry<Character, Integer> e : histA.entrySet()) {
            if (sureMap.containsKey(e.getKey())) {
                hist[sureMap.get(e.getKey())] += e.getValue();

                for (int i = 0; i < e.getValue(); i++) {
                    list.add(sureMap.get(e.getKey()));
                }
            }
        }

        String[] aa = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

        for (Integer i : list) {
            for (int k = 0; k < aa[i].length(); k++) {
                char c = aa[i].charAt(k);

                histA.put(c, histA.get(c) - 1);
            }
        }

        list.clear();

        for (Map.Entry<Character, Integer> e : histA.entrySet()) {
            if (sureMap2.containsKey(e.getKey())) {
                hist[sureMap2.get(e.getKey())] += e.getValue();

                for (int i = 0; i < e.getValue(); i++) {
                    list.add(sureMap2.get(e.getKey()));
                }
            }
        }

        for (Integer i : list) {
            for (int k = 0; k < aa[i].length(); k++) {
                char c = aa[i].charAt(k);

                histA.put(c, histA.get(c) - 1);
            }
        }

        int rem = 0;

        for (Map.Entry<Character, Integer> e : histA.entrySet()) {
           rem += e.getValue();
        }

        if (rem % 4 != 0) {
            System.out.println("ERRRRRR: " + rem);
        }

        hist[9] = rem / 4;

        StringBuilder builder = new StringBuilder();


        for (int i = 0; i < 10; i++) {
            while (hist[i] != 0) {
                builder.append("" + i);
                hist[i]--;
            }
        }

        out.println(String.format("Case #%d: %s", testNumber, builder.toString()));
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;


    public InputReader(InputStream stream){
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String next(){
        while (tokenizer == null || !tokenizer.hasMoreTokens()){
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException("FATAL ERROR", e);
            }
        }

        return tokenizer.nextToken();
    }

}

