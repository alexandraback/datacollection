import java.util.Map;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.HashMap;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
    String[] input = new String[]{
            "ejp mysljylc kd kxveddknmc re jsicpdrysi",
            "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
            "de kr kd eoya kw aej tysr re ujdr lkgc jv"
    };
    String[] output = {
            "our language is impossible to understand",
            "there are twenty six factorial possibilities",
            "so it is okay if you want to just give up"
    };

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        Map<Character, Character> map = new HashMap<Character, Character>();
        map.put('a', 'y');
        map.put('o', 'e');
        map.put('z', 'q');
        for (int i = 0; i < input.length; ++i)
            for (int j = 0; j < input[i].length(); ++j) {
                char inputChar = input[i].charAt(j);
                char outputChar = output[i].charAt(j);
                if (Character.isLetter(inputChar)) {
                    map.put(inputChar, outputChar);
                }
            }
        loop : for (char i = 'a'; i <= 'z'; ++i)
            for (char j = 'a'; j <= 'z'; ++j)
                if (!map.containsKey(i) && !map.containsValue(j)) {
                    map.put(i, j);
                    break loop;
                }
        if (testNumber == 1) in.nextLine();
        String s = in.nextLine(), res = "";
        for (int i = 0; i < s.length(); ++i)
            if (Character.isLetter(s.charAt(i)))
                res += map.get(s.charAt(i));
            else
                res += " ";
        out.print(String.format("Case #%d: %s\n", testNumber, res));
    }
}

