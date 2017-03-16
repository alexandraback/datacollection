import java.io.*;
import java.math.*;
import java.util.*;

public class CodeJam {

    void runCase(int caseNum) throws IOException {
        Map<Character, Character> map = new HashMap<Character, Character>();

        map.put('a', 'y');
        map.put('b', 'h');
        map.put('c', 'e');
        map.put('d', 's');
        map.put('e', 'o');
        map.put('f', 'c');
        map.put('g', 'v');
        map.put('h', 'x');
        map.put('i', 'd');
        map.put('j', 'u');
        map.put('k', 'i');
        map.put('l', 'g');
        map.put('m', 'l');
        map.put('n', 'b');
        map.put('o', 'k');
        map.put('p', 'r');
        map.put('q', 'z');
        map.put('r', 't');
        map.put('s', 'n');
        map.put('t', 'w');
        map.put('u', 'j');
        map.put('v', 'p');
        map.put('w', 'f');
        map.put('x', 'm');
        map.put('y', 'a');
        map.put('z', 'q');


        String line = in.readLine();

        char[] arr = new char[line.length()];
        for (int i = 0; i < line.length(); ++i) {
            if (line.charAt(i) >= 'a' && line.charAt(i) <= 'z')
                arr[i] = map.get(line.charAt(i));
            else
                arr[i] = line.charAt(i);
        }

        System.out.print(new StringBuilder().append("Case #").append(caseNum).append(": ").append(new String(arr)).toString());

        System.out.println();
    }


    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream(new File(
                "input.txt")));
        PrintStream ps = new PrintStream(new File(
                "output.txt"));
        System.setOut(ps);
        new CodeJam().runit();
        ps.flush();
        ps.close();
        return;
    }

    BufferedReader in;
    private StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }



    void runit() throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer("");

        int N = nextInt();
        for (int i = 0; i < N; i++) {
            runCase(i + 1);
        }

        out.flush();
    }

}
