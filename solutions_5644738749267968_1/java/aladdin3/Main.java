import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Mahmoud Aladdin <aladdin3>
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {

    void reverse(double[] arr) {
        int i = 0, j = arr.length - 1;
        while(i < j) {
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }

    public void solve(int testNumber, InputReader jin, OutputWriter jout) {
        int n = jin.int32();

        double[] her = new double[n];
        for(int i = 0; i < n; i++) her[i] = jin.float64();
        Arrays.sort(her); reverse(her);

        double[] him = new double[n];
        for(int i = 0; i < n; i++) him[i] = jin.float64();
        Arrays.sort(him); reverse(him);


        int dwar = deceitfulWarGame(him, her);
        int war = warGame(him, her);
        jout.println("Case #" + testNumber +  ":", dwar, war);
    }

    private int deceitfulWarGame(double[] him, double[] her) {
        reverse(her);
        int dwar = 0;
        int rem = 0;
        int bi = 0, li = him.length - 1;
        for(int i = 0; i < her.length; i++) {
            if(her[i] > him[li]) {
                dwar++; li--;
            } else if(her[i] > him[bi]) {
                dwar++; bi++;
            } 
        }
        reverse(her);
        return dwar;
    }

    int warGame(double[] him, double[] her) {
        int war = 0;
        int bi = 0;
        for(int i = 0; i < her.length; i++) {
            if(her[i] > him[bi]) {
                war++;
            } else {
                bi++;
            }
        }
        return war;
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
    
    
    private Byte readChar() {
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

    public String next() {
        return token();
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
    
    public Integer int32() throws NumberFormatException {
        String tok = token();
        return tok == null? null : Integer.parseInt(tok);
    }

    public Double float64() throws NumberFormatException {
        String tok = token();
        return tok == null? null: Double.parseDouble(tok);
    }

    }

class OutputWriter {
    private final int bufferMaxOut = 1024;
    private PrintWriter out;
    private StringBuilder output;
    private boolean forceFlush = false;

    public OutputWriter(OutputStream outStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outStream)));
        output = new StringBuilder(2 * bufferMaxOut);
    }

    public OutputWriter(Writer writer) {
        forceFlush = true;
        out = new PrintWriter(writer);
        output = new StringBuilder(2 * bufferMaxOut);
    }

    private void autoFlush() {
        if(forceFlush || output.length() >= bufferMaxOut) {
            flush();
        }
    }

    public void print(Object... tokens) {
        for(int i = 0; i < tokens.length; i++) {
            if(i != 0) output.append(' ');
            output.append(tokens[i]);
        }
        autoFlush();
    }

    public void println(Object... tokens) {
        print(tokens);
        output.append('\n');
        autoFlush();
    }

    public void flush() {
        out.print(output);
        output.setLength(0);
    }

    public void close() {
        flush();
        out.close();
    }
}

