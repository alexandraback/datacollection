package net.webcumo.codejam.c1.a;

import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.DataFlavor;
import java.io.BufferedReader;
import java.io.StringReader;

/**
 *
 * @author Cumo
 */
public class Debug {
    
    public static void main(String... agrs) {
        Clipboard clp = Toolkit.getDefaultToolkit().getSystemClipboard();
        try {
            String s = (String)clp.getData(DataFlavor.stringFlavor);
            
            BufferedReader br = new BufferedReader(new StringReader(s));
            
            String t = br.readLine();

            int countSamples = Integer.parseInt(t);
            
            for (int i = 0 ; i < countSamples ; i++) {
                String result = "Case #" + (i + 1) + ": " + DataLoader.checkSample(br) + "\n";
                System.out.print(result);
            }

            br.close();
        } catch (NullPointerException npe) {
            npe.printStackTrace();
        } catch (Exception e) {
            System.out.println("Exception while reading");
            e.printStackTrace();
        }
    }
}