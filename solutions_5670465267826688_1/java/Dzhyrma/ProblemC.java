/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package qr2015;

/**
 *
 * @author Andrii
 */
import java.util.NavigableSet;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.TreeSet;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.FileOutputStream;
import java.util.SortedSet;
import java.io.File;
import java.util.Set;

/**
 * Built using CHelper plug-in Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class ProblemC {

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }
}

class TaskC {

    private static int[][] IJK = {{0, 0, 0, 0, 0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};
    private static int[][] IJKPow = {{0, 0, 0, 0}, {1, 1, 1, 1}, {1, 2, -1, -2}, {1, 3, -1, -3}, {1, 4, -1, -4}};

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int L = in.readInt();
        long X = in.readLong();
        String s = in.readString();
        if (L * X < 3) {
            out.printLine("Case #" + testNumber + ":", "NO");
            return;
        }
        int curRes = 1;
        int searching = 2;
        int totalRes = 1;
        int curNum = 0;
        int lastIndex = 0;
        for (int i = 0; i < L; i++) {
            switch (s.charAt(i)) {
                case 'i':
                    curNum = 2;
                    break;
                case 'j':
                    curNum = 3;
                    break;
                case 'k':
                    curNum = 4;
                    break;
            }
            totalRes = totalRes > 0 ? IJK[totalRes][curNum] : -IJK[-totalRes][curNum];
            curRes = curRes > 0 ? IJK[curRes][curNum] : -IJK[-curRes][curNum];
            if (searching < 4 && curRes == searching) {
                lastIndex = i;
                searching++;
                curRes = 1;
            }
        }
        totalRes = totalRes > 0 ? IJKPow[totalRes][(int)(X & 3)] : (((X & 1) == 1) ? -IJKPow[-totalRes][(int)(X & 3)] : IJKPow[-totalRes][(int)(X & 3)]);
        if (totalRes != -1 || ((searching < 4 || lastIndex == L - 1) && X == 1)) {
            out.printLine("Case #" + testNumber + ":", "NO");
            return;
        }
        if (searching == 4) {
            out.printLine("Case #" + testNumber + ":", "YES");
            return;
        }
        int curTry = 2;
        while (searching < 4 && curTry <= X && curTry <= 10) {
            for (int i = 0; i < L; i++) {
                switch (s.charAt(i)) {
                    case 'i':
                        curNum = 2;
                        break;
                    case 'j':
                        curNum = 3;
                        break;
                    case 'k':
                        curNum = 4;
                        break;
                }
                curRes = curRes > 0 ? IJK[curRes][curNum] : -IJK[-curRes][curNum];
                if (searching < 4 && curRes == searching) {
                    if (searching == 3 && (X > curTry || i < L - 1)) {
                        out.printLine("Case #" + testNumber + ":", "YES");
                        return;
                    }
                    lastIndex = i;
                    searching++;
                    curRes = 1;
                }
            }
            curTry++;
        }
        out.printLine("Case #" + testNumber + ":", "NO");
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1) {
            throw new InputMismatchException();
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0) {
                return -1;
            }
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
    
    public long readLong() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        long sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c)) {
                res.appendCodePoint(c);
            }
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public boolean isSpaceChar(int c) {
        if (filter != null) {
            return filter.isSpaceChar(c);
        }
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public char readCharacter() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        return (char) c;
    }

    public String next() {
        return readString();
    }

    public interface SpaceCharFilter {

        public boolean isSpaceChar(int ch);
    }
}

class OutputWriter {

    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

class IntPair implements Comparable<IntPair> {

    public final int first, second;

    public IntPair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        IntPair intPair = (IntPair) o;

        return first == intPair.first && second == intPair.second;

    }

    public int hashCode() {
        int result = first;
        result = 31 * result + second;
        return result;
    }

    public int compareTo(IntPair o) {
        if (first < o.first) {
            return -1;
        }
        if (first > o.first) {
            return 1;
        }
        if (second < o.second) {
            return -1;
        }
        if (second > o.second) {
            return 1;
        }
        return 0;
    }
}

class ReverseComparator<T extends Comparable<T>> implements Comparator<T> {

    public int compare(T o1, T o2) {
        return o2.compareTo(o1);
    }
}
