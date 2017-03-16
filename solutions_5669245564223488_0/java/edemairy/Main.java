
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Formatter;
import java.util.Locale;

/**
 *
 * @author edemairy
 */
public class Main {
    
    private int nbTC;
    private StringBuilder result = new StringBuilder();
    
    private static class EndException extends RuntimeException {
    }
    
    public void run() throws IOException {
        //        Scanner scanner = new Scanner(System.in);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        nbTC = readInt(reader);
//         nbTC = Integer.MAX_VALUE;
//        scanner.nextLine();
        try {
            for (int tc = 1; tc <= nbTC; ++tc) {
                result.append("Case #" + tc + ": ");
                result.append(oneTestCase(reader));
                result.append('\n');
            }
        } catch (EndException e) {
        }
        System.out.print(result);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Main main = new Main();
        main.run();
    }
    
    public int N;    
    private String[] trains;
    private static final long MOD = 1000000007;
    
    public long mod(long i, long j) {        
        long r = i % j;
        if (r < 0) {
            r += j;
        }
        return r;
    }
    
    public int seen[] = new int[26];

    public boolean correct(String s) {
        boolean result = true;
        Arrays.fill(seen, -1);
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int p = seen[c - 'a'];
            if (p != -1) {
                if (i != p + 1) {
                    return false;
                }
            }
            seen[c - 'a'] = i;
        }
        return true;
    }
    
    public static boolean getNext(int[] Value) {
        int N = Value.length;
        int i = N - 1;
        while (i > 0 && Value[i - 1] >= Value[i]) {
            i = i - 1;
        }
        if (i == 0) {
            return false;
        }
        
        int j = N;
        while (Value[j - 1] <= Value[i - 1]) {
            j = j - 1;
        }
        
        swap(Value, i - 1, j - 1);    // swap values at positions (i-1) and (j-1)

        i++;
        j = N;
        while (i < j) {
            swap(Value, i - 1, j - 1);
            i++;
            j--;
        }
        return true;
    }

    static private void swap(int[] Value, int i, int i0) {
        int t = Value[i];
        Value[i] = Value[i0];
        Value[i0] = t;
    }
    
    private StringBuilder oneTestCase(BufferedReader reader) throws IOException {
        Formatter formatter = new Formatter(Locale.ENGLISH);
        StringBuilder output = new StringBuilder();
//        for (int i = 0; i < 5; ++i) {
//            formatter.format("%3d", n[i]);
//        }
        N = Integer.parseInt(reader.readLine());
        trains = reader.readLine().split(" ");
        
        int[] v = new int[N];
        for (int i = 0; i < N; i++) {
            v[i] = i;
        }
        StringBuilder sb = new StringBuilder();
        long r = 0;
        do {
            sb.setLength(0);
            for (int i = 0; i < N; i++) {
                sb.append(trains[v[i]]);
            }
            if (correct(sb.toString())) {
                r++;
            }
        } while (getNext(v));  
        formatter.format("%d", r);
        
        output.append(formatter.out());
        return output;
    }
    
    private int readInt(BufferedReader reader) throws IOException {
        int r = 0;
        boolean positive = true;
        char currentChar = (char) reader.read();
        
        while ((currentChar == ' ') || (currentChar == '\n')) {
            currentChar = (char) reader.read();
        }
        if (currentChar == (char) -1) {
            throw new IOException("end of stream");
        }
        if (currentChar == '-') {
            positive = false;
            currentChar = (char) reader.read();
        }
        while ((currentChar >= '0') && (currentChar <= '9')) {
            r = r * 10 + currentChar - '0';
            currentChar = (char) reader.read();
        }
        if (positive) {
            return r;
        } else {
            return -r;
        }
    }
    
    private long readLong(BufferedReader reader) throws IOException {
        long r = 0;
        boolean positive = true;
        char currentChar = (char) reader.read();
        
        while ((currentChar == ' ') || (currentChar == '\n')) {
            currentChar = (char) reader.read();
        }
        if (currentChar == (char) -1) {
            throw new IOException("end of stream");
        }
        if (currentChar == '-') {
            positive = false;
            currentChar = (char) reader.read();
        }
        while ((currentChar >= '0') && (currentChar <= '9')) {
            r = r * 10 + currentChar - '0';
            currentChar = (char) reader.read();
        }
        if (positive) {
            return r;
        } else {
            return -r;
        }
    }
    
    private char readChar(BufferedReader reader) throws IOException {
        return (char) reader.read();
    }
}
