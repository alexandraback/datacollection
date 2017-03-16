import java.io.*;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.List;

public class CodeJam1BB {
    private static InputReader in;
    private static OutputWriter out;

    private static int number;

    private static void solve() throws Exception {
        int t = in.readInt();
        for (int i = 1; i <= t; ++i) {
            out.print("Case #" + i + ": ");
            String c = in.readString();
            String j = in.readString();
            int difference = Integer.MAX_VALUE;
            int coders = Integer.MAX_VALUE;
            int jammers = Integer.MAX_VALUE;
            List<Integer> cod = new LinkedList<>();
            List<Integer> jam = new LinkedList<>();
            dfs(cod,c,0);
            dfs(jam,j,0);
            for(Integer y: cod){
                for(Integer z:jam){
                    int temp = Math.abs(y-z);
                    if(temp<difference){
                        difference = temp;
                        coders = y;
                        jammers = z;
                    }
                    else if(temp==difference){
                        if(y<coders){
                            coders=y;
                        }
                        else if(y==coders){
                            if(z<jammers){
                                jammers = z;
                            }
                        }
                    }
                }
            }
            out.println(nubmerFormat(coders,c.length())+" "+nubmerFormat(jammers,j.length()));


        }
    }

    private static String nubmerFormat(int number , int length){
        if(number==0){
            String result = "";
            while(length!=0){
                result += 0;
                length--;

            }
            return  result;
        }

        int digits = 0;
        int temp = number;
        while(temp!=0){
            temp = temp/10;
            digits++;
        }
        String result = "";
        while((length-digits)!=0){
            result += 0;
            digits++;
        }
        result += number;
        return  result;
    }

    private static void dfs(List<Integer> list, String s, int index){
        if(index==s.length()){
            list.add(number);
            return;
        }
        if(s.charAt(index)!='?'){
            number += (s.charAt(index)-48)*((int)Math.pow(10,s.length()-1-index));
            dfs(list,s,index+1);
            number -= (s.charAt(index)-48)*((int)Math.pow(10,s.length()-1-index));
        }
        else{
            for(int i=0; i<=9; ++i){
                number += i*((int)Math.pow(10,s.length()-1-index));
                dfs(list,s,index+1);
                number -= i*((int)Math.pow(10,s.length()-1-index));
            }
        }
    }


    public static void main(String[] args) throws Exception {
        in = new InputReader(new FileInputStream("input_b_small.in"));
        out = new OutputWriter(new FileOutputStream("output_b_small.txt"));
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