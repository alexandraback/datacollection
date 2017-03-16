import java.io.OutputStream;
import java.io.IOException;
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

    int[] input;

    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        int n = jin.int32();
        input = IOUtils.read1DIntArray(jin, n);

        jout.print("Case #" + testNumber + ": ");
        jout.println(binarySearch());
    }

    private int binarySearch() {
        int start = 1;
        int end = Integer.MAX_VALUE / 2;
        int ans = -1;

        while(start <= end) {
            int mid = (start + end) >> 1;
            if(canDo(mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    private boolean canDo(int mid) {
        for(int eat = 1; eat <= mid; eat++) {
            int req = 0;
            for(int i = 0; i < input.length; i++) {
                int pte = (input[i] / eat) + ((input[i] % eat) == 0? 0 : 1);
                req += (pte - 1);
            }
            if(req + eat <= mid)
                return true;
        }
        return false;
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

class IOUtils {
    public static int[] read1DIntArray(InputReader in, int size) {
        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = in.int32();
        }
        return arr;
    }

    public static int[][] read2DIntArray(InputReader in, int rowSize, int colSize) {
        int[][] arr = new int[rowSize][];
        for(int i = 0; i < rowSize; i++) {
            arr[i] = IOUtils.read1DIntArray(in, colSize);
        }
        return arr;
    }
}

