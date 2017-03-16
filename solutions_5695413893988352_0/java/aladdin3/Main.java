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
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        String s1 = jin.next();
        String s2 = jin.next();

        int mi = 0;
        int mj = 0;
        int diff = Integer.MAX_VALUE;
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) {
                if(Math.abs(i - j) <= diff) {
                    if(Validate(i, s1) && Validate(j, s2)) {
                        int ndiff = Math.abs(i - j);
                        if(ndiff < diff) {
                            diff = ndiff; mi = i; mj = j;
                        } else if(i < mi) {
                            mi = i;
                            mj = j;
                        } else if(i == mi && j < mj) {
                            mj = j;
                        }
                    }
                }
            }
        }
        jout.println("Case #" + testNumber + ": " + Convert(mi, s1) + " " + Convert(mj, s2));
    }

    private boolean Validate(int number, String orig) {
        String sNumber = Convert(number, orig);
        if(sNumber == null) return false;
        for(int i = 0; i < sNumber.length(); i++) {
            if(orig.charAt(i) != '?' && orig.charAt(i) != sNumber.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    private String Convert(int number, String orig) {
        String sNumber = Integer.toString(number);
        if(sNumber.length() > orig.length()) return null;
        while(sNumber.length() < orig.length()) {
            sNumber = "0" + sNumber;
        }
        return sNumber;
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

    public String line() {
        StringBuffer tok = new StringBuffer();
        Byte first;
        while((first = readChar()) != null) {
            tok.append((char)first.byteValue());
            if((char)first.byteValue() == '\n')
                break;
        }
        return tok.toString();
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

