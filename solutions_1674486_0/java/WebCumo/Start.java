package net.webcumo.codejam.c1.a;

import java.awt.FileDialog;
import java.awt.Frame;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 * @author Cumo
 */
public class Start {

    public static void main(String... agrs) {
        Frame d = null;
        FileDialog fd = new FileDialog(d, "Load in file", FileDialog.LOAD);
        fd.setVisible(true);
        String file = fd.getDirectory() + fd.getFile();
        if (file != null) {
            File f = new File(file);
            File fo = new File ("result.out");
            if (!f.exists())
                return;
            try {
                BufferedWriter bw = new BufferedWriter(new FileWriter(fo));
                BufferedReader br = new BufferedReader(new FileReader(f));
                String t = br.readLine();

                int countSamples = Integer.parseInt(t);

                for (int i = 0 ; i < countSamples ; i++) {
                    String result = "Case #" + (i + 1) + ": " + DataLoader.checkSample(br) + "\n";
                    bw.write(result);
                }

                bw.close();
                br.close();
            } catch (NullPointerException npe) {
                //ignore at current
            } catch (Exception e) {
                //ignore at current
            }
        }
        fd.dispose();
    }
}
