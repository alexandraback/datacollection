
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alex
 */
public class Speaking {
    public String Orig = "abcdefghijklmnopqrstuvwxyz";
    public String Goog = "ynficwlbkuomxsevzpdrjgthaq";
    private class Data {
        public String enc;
        
        public Data(String s) {
            //String[] parts = s.trim().split(" ");
            enc = s;
        }
        
        public Data(int n_) {
        
        }
        
        public String Solve() {
            String eng = "";
            for (int i=0;i<enc.length();i++) {
                char c = enc.charAt(i);
                if (c == ' ') {
                    eng += c;
                    continue;
                }
                //System.out.println(c);
                int ind = Goog.indexOf(c);
                if (ind == -1) {
                    eng += c;
                    continue;
                }
                //System.out.println(ind);
                char nC = Orig.charAt(ind);
                eng += nC;
            }
            return eng;
        }
    }
    
    private static String IN = ".\\A-small-attempt0.in";
    private static String OUT = ".\\A-small-attempt0.out";
    
    private Data[] datas;
    
    private void go() {
        File file = new File(IN);
        System.out.println(file.getAbsolutePath());
        File fo = new File(OUT);
        try {
            if (!fo.createNewFile()) {
                fo.delete();
                fo.createNewFile();
            }
            BufferedReader br = new BufferedReader(new FileReader(file));
            BufferedWriter bw = new BufferedWriter(new FileWriter(fo));
            String line;
            int num = Integer.parseInt(br.readLine());
            datas = new Data[num];
            int i = 0;
            while ((line = br.readLine()) != null && num-->0) {
                datas[i] = new Data(line);
                String ss = "Case #"+(i+1)+": "+datas[i].Solve()+"\n";
                System.out.print(ss);
                bw.write(ss);
                i++;
            }
            br.close();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public Speaking() {
        go();
    }
    
    public static void main(String[] args) {
        new Speaking();
    }
}
