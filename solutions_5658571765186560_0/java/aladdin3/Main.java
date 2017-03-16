import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        jout.print("Case #" + testNumber + ": ");
        int x = jin.int32();
        int r = jin.int32();
        int c = jin.int32();

        if (x >= 7) {
            jout.println("RICHARD");
        } else {
            int area = r * c;
            if(area % x != 0) {
                jout.println("RICHARD");
            } else {
                for (int s1 = 1; s1 <= x; s1++) {
                    for(int s2 = 1; s2 <= x; s2++) {
                        if(s1 + s2 == x + 1) {
                            if(s1 > Math.max(r, c) || s2 > Math.max(r, c)) {
                                jout.println("RICHARD");
                                return;
                            }
                            if(s1 > Math.min(r, c) && s2 > Math.min(r, c)) {
                                jout.println("RICHARD");
                                return;
                            }
                            if(s1 + s2 == r + 3 || s1 + s2 == c + 3) {
                                jout.println("RICHARD");
                                return;
                            }
                        }
                    }
                }
                jout.println("GABRIEL");
            }
        }
    }
}

class InputReader {
    private static final int bufferMaxLength = 1024;
    private InputStream in;
    private byte[] buffer;
    private int currentBufferSize;
    private int currentBufferTop;
    private static final String tokenizers = " \t\r\f\n";

    public InputReader(InputStream stream) {
        this.in = stream;
        buffer = new byte[bufferMaxLength];
        currentBufferSize = 0;
        currentBufferTop = 0;
    }

    private boolean refill() {
        try {
            this.currentBufferSize = this.in.read(this.buffer);
            this.currentBufferTop = 0;
        } catch(Exception e) {}
        return this.currentBufferSize > 0;
    }


    public Byte readChar() {
        if(currentBufferTop < currentBufferSize) {
            return this.buffer[this.currentBufferTop++];
        } else {
            if(!this.refill()) {
                return null;
            } else {
                return readChar();
            }
        }
    }

    public String token()  {
        StringBuffer tok = new StringBuffer();
        Byte first;
        while((first = readChar()) != null && (tokenizers.indexOf((char) first.byteValue()) != -1));
        if(first == null) return null;
        tok.append((char)first.byteValue());
        while((first = readChar()) != null && (tokenizers.indexOf((char) first.byteValue()) == -1)) {
            tok.append((char)first.byteValue());
        }
        return tok.toString();
    }


    public String next() {
        return token();
    }

    public Integer int32() throws NumberFormatException {
        String tok = token();
        return tok == null? null : Integer.parseInt(tok);
    }

    public Long int64() throws NumberFormatException {
        String tok = token();
        return tok == null? null : Long.parseLong(tok);
    }
}

