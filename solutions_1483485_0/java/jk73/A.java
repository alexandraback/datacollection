import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;

public class A {
    private static byte[] code = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
            'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p',
            'f', 'm', 'a', 'q'
    };

    public static void main(String[] args) throws Throwable {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(
                System.in));
        final int numCases = Integer.parseInt(reader.readLine());

        for (int c = 1; c <= numCases; c++) {
            System.out.println("Case #" + c + ": " + translate(reader.readLine()));
        }
    }

    private static String translate(String line) throws UnsupportedEncodingException {
        final byte[] bytes = line.getBytes("us-ascii");
        for (int i = 0; i < bytes.length; i++) {
	    if (bytes[i] >= 'a') {
		bytes[i] = code[bytes[i] - 'a'];
	    }
        }
        return new String(bytes, "us-ascii");
    }
}
