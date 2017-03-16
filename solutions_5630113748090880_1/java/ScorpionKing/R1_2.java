package google.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.TreeSet;

public class R1_2 {
    public R1_2() {
        super();
    }
    
    private static String convert(String[] inputArr) {
        int l=inputArr.length;
        TreeSet<Integer> tree = new TreeSet<Integer>();
        
        for(int i=0;i<l;i++) {
            String[] numArr = inputArr[i].split(" ");
            int l1=numArr.length;
            for(int i1=0;i1<l1;i1++) {
                Integer num = Integer.parseInt(numArr[i1]);
                if(tree.contains(num))
                    tree.remove(num);
                else
                    tree.add(num);
            }
            
        }
        StringBuilder sb = new StringBuilder();
        for(Integer num:tree)
            sb.append(num).append(" ");
        return sb.toString();
    }
    
    public static void main(String[] args) {
        try {
        BufferedReader reader = new BufferedReader(new FileReader("D:\\codejam\\2016\\A.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("D:\\codejam\\2016\\A.out"));

            //... Loop as long as there are input lines.
            String line = null;
            reader.readLine();
            int i=1;
            
            while ((line=reader.readLine()) != null) {
                int N = Integer.parseInt(line);
                int input = 2*N-1;
                String[] inputArr = new String[input];
                for(int j=0;j<input;j++)
                    inputArr[j]=reader.readLine();
                writer.write("Case #"+i+": "+convert(inputArr));
                writer.newLine();   // Write system dependent end of line.
                i++;
            }

            //... Close reader and writer.
            reader.close();  // Close to unlock.
            writer.close();  // Close to unlock and flush to disk.

    }
        catch(Exception ex) {
            ex.printStackTrace();
        }
    }
}
