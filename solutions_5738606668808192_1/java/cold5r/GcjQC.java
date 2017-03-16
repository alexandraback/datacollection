import java.io.*;
import java.util.InputMismatchException;

public class GcjQC {
    private static InputReader in;
    private static OutputWriter out;


    private static void solve() throws Exception {
        int t = in.readInt();
        for (int i = 1; i <= t; ++i) {
            out.println("Case #" + i + ":");
            int n = in.readInt();
            int j = in.readInt();
            int[] result = new int[n];
            result[0] = 1;
            result[n - 1] = 1;
            String divisors = " 3 4 5 6 7 8 9 10 11";
            for (int y = 0; y < n; ++y) {
                out.print(result[y]);
            }
            out.println(divisors);
            j--;

            outer:
            for (int k = 1; k < n - 1; k = k + 2) {
                result[k] = 1;
                for (int z = 2; z < n; z = z + 2) {
                    if (j == 0) {
                        break outer;
                    }
                    result[z] = 1;
                    for (int y = 0; y < n; ++y) {
                        out.print(result[y]);
                    }
                    out.println(divisors);
                    j--;
                    result[z] = 0;
                }
                result[k] = 0;
            }
            if (j > 0) {
                result[1] = 1;
                result[2] = 1;
                outer:
                for (int k = 3; k < n - 1; k = k + 2) {
                    result[k] = 1;
                    for (int z = 4; z < n; z = z + 2) {
                        if (j == 0) {
                            break outer;
                        }
                        result[z] = 1;
                        for (int y = 0; y < n; ++y) {
                            out.print(result[y]);
                        }
                        out.println(divisors);
                        j--;
                        result[z] = 0;
                    }
                    result[k] = 0;
                }
            }
            if (j > 0) {
                result[3] = 1;
                result[4] = 1;
                outer:
                for (int k = 5; k < n - 1; k = k + 2) {
                    result[k] = 1;
                    for (int z = 6; z < n; z = z + 2) {
                        if (j == 0) {
                            break outer;
                        }
                        result[z] = 1;
                        for (int y = 0; y < n; ++y) {
                            out.print(result[y]);
                        }
                        out.println(divisors);
                        j--;
                        result[z] = 0;
                    }
                    result[k] = 0;
                }
            }
        }

    }


    public static void main(String[] args) throws Exception {
        in = new InputReader(new FileInputStream("input.in"));
        out = new OutputWriter(new FileOutputStream("output.txt"));
        solve();
        out.close();
    }


    private static class InputReader {
        private InputStream stream;
        private byte[] buffer;
        private int currentIndex;
        private int bytesRead;

        public InputReader(InputStream stream) {
            this.stream = stream;
            buffer = new byte[131072];
        }


        public InputReader(InputStream stream, int bufferSize) {
            this.stream = stream;
            buffer = new byte[bufferSize];
        }


        private int read() throws IOException {
            if (currentIndex >= bytesRead) {
                currentIndex = 0;
                bytesRead = stream.read(buffer);
                if (bytesRead <= 0) {
                    return -1;
                }
            }
            return buffer[currentIndex++];
        }

        public String readString() throws IOException {
            int c = read();
            while (!isPrintable(c)) {
                c = read();
            }
            StringBuilder result = new StringBuilder();
            do {
                result.appendCodePoint(c);
                c = read();
            } while (isPrintable(c));
            return result.toString();
        }

        public int readInt() throws Exception {
            int c = read();
            int sign = 1;
            while (!isPrintable(c)) {
                c = read();
            }
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int result = 0;
            do {
                if ((c < '0') || (c > '9')) {
                    throw new InputMismatchException();
                }
                result *= 10;
                result += (c - '0');
                c = read();
            } while (isPrintable(c));
            return sign * result;
        }

        public long readLong() throws Exception {
            int c = read();
            int sign = 1;
            while (!isPrintable(c)) {
                c = read();
            }
            if (c == '-') {
                sign = -1;
                c = read();
            }
            long result = 0;
            do {
                if ((c < '0') || (c > '9')) {
                    throw new InputMismatchException();
                }
                result *= 10;
                result += (c - '0');
                c = read();
            } while (isPrintable(c));
            return sign * result;
        }

        public double readDouble() throws Exception {
            int c = read();
            int sign = 1;
            while (!isPrintable(c)) {
                c = read();
            }
            if (c == '-') {
                sign = -1;
                c = read();
            }
            boolean fraction = false;
            double multiplier = 1;
            double result = 0;
            do {
                if ((c == 'e') || (c == 'E')) {
                    return sign * result * Math.pow(10, readInt());
                }
                if ((c < '0') || (c > '9')) {
                    if ((c == '.') && (!fraction)) {
                        fraction = true;
                        c = read();
                        continue;
                    }
                    throw new InputMismatchException();
                }
                if (fraction) {
                    multiplier /= 10;
                    result += (c - '0') * multiplier;
                    c = read();
                } else {
                    result *= 10;
                    result += (c - '0');
                    c = read();
                }
            } while (isPrintable(c));
            return sign * result;
        }

        private boolean isPrintable(int c) {
            return ((c > 32) && (c < 127));
        }
    }

    private static class OutputWriter {
        private PrintWriter writer;

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

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }
    }
}