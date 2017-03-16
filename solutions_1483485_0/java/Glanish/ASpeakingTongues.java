/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejamqualifier;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;

/**
 *
 * @author Dean
 */
public class ASpeakingTongues {
    public static void main(String args[]) throws IOException {
        //char translateTable[] = new char[]{'y', 'n', 'f', 'i', 'c', 'w', 'l', 'x', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v','z', 'p','d','r','j', 'g','t','h','y','q'};
        //                                  a    b    c    d    e    f    g    h    i    j    k    l    m    n    o    p   q    r   s   t   u    v   w   x   y   z
        char translateTable[] = new char[]{'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r','z', 't','n','w','j', 'p','f','m','a','q'};
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int lines = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < lines; i++) {
            System.out.println("Case #" + (i+1) + ": " + translate(reader.readLine().trim(), translateTable));
        }
    }
    public static String translate(String line, char[] table) {
        char letters[] = line.toCharArray();
        for (int i = 0; i < letters.length; i++) {
            if (letters[i] == ' ') {
                continue;
            }
            else {
                letters[i] = table[(int)letters[i] - 97];
            }
        }
        return new String(letters);
    }


}
