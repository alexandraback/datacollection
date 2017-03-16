/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package brattleship;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author mkozeny
 */
public class Brattleship {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BufferedReader br = null;
        long time = System.currentTimeMillis();

        try {

            File file = new File("result.out");

            // if file doesnt exists, then create it
            if (!file.exists()) {
                file.createNewFile();
            }

            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            BufferedWriter bw = new BufferedWriter(fw);

            String sCurrentLine;

            //br = new BufferedReader(new FileReader("A-small-attempt3.in"));
            br = new BufferedReader(new FileReader("A-large.in"));
            //br = new BufferedReader(new FileReader("test.in"));

            Integer numberOfTestCases = 0;
            if ((sCurrentLine = br.readLine()) != null) {
                numberOfTestCases = Integer.parseInt(sCurrentLine);
            }
            for (int i = 0; i < numberOfTestCases; i++) {
                String [] testCase = null;
                if ((sCurrentLine = br.readLine()) != null) {
                    testCase = sCurrentLine.split(" ");
                }
                Long r = Long.parseLong(testCase[0]);
                Long c = Long.parseLong(testCase[1]);
                Long w = Long.parseLong(testCase[2]);
                
                Long triesPerRow = 0L;
                Long result = 0L;
                if((c/w)>=1) {
                    triesPerRow = (c/w);
                }
                if((c%w)!=0) {
                    result = 1L;
                }
                result += triesPerRow * r + (w-1);
                
                
//                Long triesPerRow = 1L;
//                Long result = 0L;
//                if((c/(2*w-1))>1) {
//                    triesPerRow = (c/(2*w-1));
//                }
//                if(!(w==2 && c==3)) {
//                    if(w > 1 && c > w)result = 1L;
//                }
//                result += triesPerRow * r + (w-1);
                
                String resultStr = "Case #" + (i + 1) + ": " + result + "\n";
                System.out.print(resultStr);
                bw.write(resultStr);
            }
    
            System.out.println("Total time: " + (System.currentTimeMillis() - time) + " ms");
            bw.close();
    
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}
