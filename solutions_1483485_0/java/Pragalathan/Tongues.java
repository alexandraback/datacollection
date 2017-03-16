

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.TreeMap;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author java
 */
public class Tongues {

    static BufferedReader in;

    private static void open() {
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    private static void close() {
        try {
            in.close();
        } catch (IOException ex) {
            Logger.getLogger(StoreCredit.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static int readInt() throws IOException {
        Integer i = Integer.parseInt(in.readLine());
        return i;
    }

    private static int[] readInts() throws IOException {
        String[] vals = in.readLine().split(" ");
        int[] arr = new int[vals.length];
        for (int i = 0; i < vals.length; i++) {
            arr[i] = Integer.parseInt(vals[i]);
        }
        return arr;
    }

    public static void main(String[] args) throws IOException {
        open();
        String[] a = {
            "ejp mysljylc kd kxveddknmc re jsicpdrysi",
            "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
            "de kr kd eoya kw aej tysr re ujdr lkgc jv"
        };

        String[] b = {
            "our language is impossible to understand",
            "there are twenty six factorial possibilities",
            "so it is okay if you want to just give up"
        };
        Map<Character, Character> chars = new TreeMap<Character, Character>();
        for (int i = 0; i < a.length; i++) {
            char[] in = a[i].toCharArray();
            char[] out = b[i].toCharArray();
            for (int j = 0; j < in.length; j++) {
                chars.put(in[j], out[j]);
            }
        }
        
        chars.put('q', 'z');
        chars.put('z', 'q');
        
        int T = readInt();
        for (int t = 0; t < T; t++) {
            String input = in.readLine();
             System.out.print("Case #" + (t + 1) + ": ");
            char[] in = input.toCharArray();
            for (int j = 0; j < in.length; j++) {
                System.out.print(chars.get(in[j]));
            }
            System.out.println();
        }
        close();
    }
}
