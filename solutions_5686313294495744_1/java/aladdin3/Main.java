import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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


    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        int n = jin.int32();

        List<String> first = new ArrayList<String>();
        List<String> second = new ArrayList<String>();

        Set<String> sFirst = new HashSet<String>();
        Set<String> sSecond = new HashSet<String>();

        for(int i = 0; i < n; i++) {
            String f = jin.next();
            String s = jin.next();

            first.add(f); sFirst.add(f);
            second.add(s); sSecond.add(s);
        }

        int index= 0;
        Map<String, Integer> iFirst = new HashMap<String, Integer>();
        for(String val : sFirst) {
            iFirst.put(val, index++);
        }


        index = 0;
        Map<String, Integer> iSecond = new HashMap<String, Integer>();
        for(String val : sSecond) {
            iSecond.put(val, index++);
        }

        graph = new boolean[iFirst.size()][iSecond.size()];
        for(boolean[] row : graph)
            Arrays.fill(row, false);

        for(int i = 0; i < n; i++) {
            int u = iFirst.get(first.get(i));
            int v = iSecond.get(second.get(i));
            graph[u][v] = true;
        }

        matchL = new int[iFirst.size()];
        matchR = new int[iSecond.size()];
        seen = new boolean[iSecond.size()];

        int matched = maximumMatching();
        //System.err.println(matched);
        for(int val : matchL) {
            //System.err.print(val + " ");
            if(val == -1) matched++;
        }
        //System.err.println(matched);
        for(int val : matchR) {
            //System.err.print(val + " ");
            if(val == -1) matched++;
        }
        //System.err.println(matched);
        int rem = n - matched;
        jout.println("Case #" + testNumber + ": " + rem);
    }


    boolean[][] graph;
    boolean seen[];
    int matchL[];
    int matchR[];

    int maximumMatching() {

        Arrays.fill(matchL, -1);
        Arrays.fill(matchR, -1);

        int count = 0;
        for (int i = 0; i < graph.length; i++) {
            Arrays.fill(seen, false);
            if (bpm(i)) count++;
        }
        return count;
    }

    boolean bpm(int u) {
        for (int v = 0; v < graph[u].length; v++) {
            if (!graph[u][v] || seen[v]) continue;
            seen[v] = true;

            if (matchR[v] == -1 || bpm(matchR[v])) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
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

