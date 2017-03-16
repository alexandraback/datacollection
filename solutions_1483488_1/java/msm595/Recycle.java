
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashSet;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alex
 */
public class Recycle {
    private class Data {
        public int A;
        public int B;
        public HashSet<String> list;
        
        public Data(String s) {
            String[] parts = s.trim().split(" ");
            A = Integer.parseInt(parts[0]);
            B = Integer.parseInt(parts[1]);
            list = new HashSet<String>();
        }
        
        public Data(int n_) {
        
        }
        
        public int Solve() {
            list.clear();
            int sols = 0;
            for (int i=A;i<=B;i++) {
                sols += permutate(i);
                //sols += countPerms(i);
            }
            //System.out.println(sols);
            if (sols != list.size())
                System.err.println("WTF");
            return list.size();
        }
        
        public int permutate(int i) {
            int count = 0;
            int c = i;
            int length = (int)(Math.log10(i)+1);
            int power = length-1;
            //System.out.println("Length: "+length);
            for (int h=0;h<power;h++) {
                int ones = c%10;
                int rest = c/10;
                //System.out.println("ones: "+ones);
                //System.out.println("rest: "+rest);
                c = (int)((c%10)*Math.pow(10,power)) + c/10;
                if (ones != 0 && !(""+c).replaceAll(""+ones, "").equals("") && c <= B && c > i && i >= A) {
                    count++;
                    //System.out.println(""+i+": "+c);
                    //System.out.println("Counts");
                    list.add(""+i+""+c);
                }
            }
            //System.out.println(list.size());
            return count;
        }
    }
    
    private static String IN = ".\\C-large.in";
    private static String OUT = ".\\C-large.out";
    
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
                int solv = datas[i].Solve();
                String ss = "Case #"+(i+1)+": "+solv+"\n";
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
    
    public Recycle() {
        go();
    }
    
    public static void main(String[] args) {
        new Recycle();
    }
}
