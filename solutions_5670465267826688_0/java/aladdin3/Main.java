import java.util.Map;
import java.io.IOException;
import java.util.HashMap;
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
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

    public int[][] map;
    public Map<Character, Integer> index;

    public TaskC() {
        index = new HashMap<Character, Integer>();
        index.put('i', 1);
        index.put('j', 2);
        index.put('k', 3);
        map = new int[8][8];
        map[0] = new int[]{0, 1, 2, 3, 4, 5, 6, 7};
        map[1] = new int[]{1, 4, 3, 6, 5, 0, 7, 2};
        map[2] = new int[]{2, 7, 4, 1, 6, 3, 0, 5};
        map[3] = new int[]{3, 2, 5, 4, 7, 6, 1, 0};
        map[4] = new int[]{4, 5, 6, 7, 0, 1, 2, 3};
        map[5] = new int[]{5, 0, 7, 2, 1, 4, 3, 6};
        map[6] = new int[]{6, 3, 0, 5, 2, 7, 4, 1};
        map[7] = new int[]{7, 6, 1, 0, 3, 2, 5, 4};
    }


    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        long l = jin.int64();
        long x = jin.int64();

        String token = jin.token();

        int curr = 0;
        boolean iFound = false;
        boolean jFound = false;
        boolean kFound = false;
        //int rem = (int) (x % 4);
        for(int i = 0; i < x; i++) {
            for(char xx: token.toCharArray()) {
                curr = map[curr][index.get(xx)];
                if(!iFound) {
                    iFound = curr == 1;
                    curr = curr == 1? 0: curr;
                } else if(!jFound) {
                    jFound = curr == 2;
                    curr = curr == 2? 0: curr;
                } else if(!kFound) {
                    kFound = curr == 3;
                    curr = curr == 3? 0: curr;
                }
            }
        }

        jout.print("Case #" + testNumber + ": ");
        jout.println(iFound && jFound && kFound && curr == 0? "YES" : "NO");
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

