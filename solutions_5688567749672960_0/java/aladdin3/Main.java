import java.io.IOException;
import java.util.Arrays;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collection;
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
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        int[] solution = new int[(int)1e7];
        Arrays.fill(solution, -1);
        jout.print("Case #" + testNumber + ": ");
        int n = jin.int32();
        Queue<Integer> que = new LinkedList<Integer>();
        que.add(1); solution[1] = 1;
        while(!que.isEmpty()) {
            int x = que.poll();
            if(x == n) {
                jout.println(solution[x]);
                return;
            }
            int rev = reverse(x);
            if(solution[rev] == -1) {
                solution[rev] = solution[x] + 1;
                que.add(rev);
            }
            if(solution[x + 1] == -1) {
                solution[x + 1] = solution[x] + 1;
                que.add(x + 1);
            }

        }

    }

    private int reverse(int i) {
        if(i == 0) return 0;
        int x = 0;
        while (i > 0) {
            x = x * 10 + i % 10;
            i /= 10;
        }
        return x;
    }
}

class Pair {
    public int i;
    public int j;

    public Pair(int _a, int _b) {
        i = _a; j = _b;
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

