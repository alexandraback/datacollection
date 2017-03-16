import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author coderbd
 */
public class Main {
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
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
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
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
}

class TaskC {

    public static class Hiker implements Comparable<Hiker> {
        public int startPos;
        public int speed;
        public Hiker(int startPos, int speed) {
            this.startPos = startPos;
            this.speed = speed;
        }
        public int compareTo(Hiker hiker) {
            if (this.speed < hiker.speed)
                return -1;
            if (this.speed > hiker.speed)
                return 1;
            if (this.startPos < hiker.startPos)
                return -1;
            if (this.startPos > hiker.startPos)
                return 1;
            return 0;
        }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int ans = 0;
        List<Hiker> hikers = new ArrayList<Hiker>();
        for (int i = 0; i < n; i++) {
            int d = in.readInt();
            int h = in.readInt();
            int m = in.readInt();
            for (int j = 0; j < h; j++)
                hikers.add(new Hiker(d, m + j));
        }
        Collections.sort(hikers);
        if (hikers.size() > 1) {
            int fastSpeed = hikers.get(0).speed;
            int slowSpeed = hikers.get(1).speed;
            int fastPos = hikers.get(0).startPos;
            int slowPos = hikers.get(1).startPos;
            int fastRemDist1 = 360 - fastPos;
            int fastRemDist2 = 720 - fastPos;
            int slowRemDist = 360 - slowPos;
            if ((long) slowRemDist * (long) slowSpeed >= (long) fastRemDist2 * (long) fastSpeed)
                ans = 1;
            if ((long) slowRemDist * (long) slowSpeed == (long) fastRemDist1 * (long) fastSpeed)
                ans = 0;
        }
        out.printLine("Case #" + testNumber + ": " + ans);
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            }
            catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String next() {
        return readString();
    }

}

class OutputWriter {

    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
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
