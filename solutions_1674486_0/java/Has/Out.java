package inout;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Hasier Rodriguez
 */
public final class Out {

    private Out() {
    }

    public static void write(String path, int n, String result) throws FileNotFoundException, IOException {
        File f = new File(path);
        BufferedWriter br = new BufferedWriter(new FileWriter(f, true));
        String out = "Case #" + n + ": " + result;
        br.write(out);
        System.out.println(out);
        br.newLine();
        br.flush();
        br.close();
    }
}
