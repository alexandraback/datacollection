import java.io.IOException;
import java.io.PrintStream;
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
		digits solver = new digits();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class digits {
    int[] alph = new int[26];

    String[] numbers = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    char[] significant = new char[]{'Z', 'O', 'W', 'T', 'U', 'F', 'X', 'S', 'G', 'I'};


    int Remove(int num) {
        int res = alph[significant[num] - 'A'];
        for(char tmp : numbers[num].toCharArray()) {
            alph[tmp - 'A'] -= res;
        }

        return res;
    }

    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        String s = jin.next();

        for(char ch : s.toCharArray()) {
            alph[ch - 'A']++;
        }

        int[] count = new int[10];
        int[] remOrd = new int[] {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        for(int i = 0; i < remOrd.length; i++) {
            count[remOrd[i]] = Remove(remOrd[i]);
        }
        System.err.print(s + "-> ");
        jout.print("Case #" + testNumber + ": ");
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < count[i]; j++) {
                jout.print(i);
                System.err.print(i);
            }
        }
        jout.println();
        System.err.println();
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

