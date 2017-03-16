package google.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.Set;
import java.util.TreeSet;

public class Problem3 {
    public Problem3() {
        super();
    }
    public static void main(String[] args) {
        try {
        BufferedReader reader = new BufferedReader(new FileReader("D:\\codejam\\2012\\C.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("D:\\codejam\\2012\\C.out"));

                //... Loop as long as there are input lines.
                String line = null;
            reader.readLine();
            int i=1;
                while ((line=reader.readLine()) != null) {
                    writer.write("Case #"+i+": "+convert(line));
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
    

//public static void main(String[] args) {
//        System.out.println(convert("123 995"));
//    }
    private static boolean isInRange(String num,int A, int B) {
        
            int iNum = Integer.parseInt(num);
            if(iNum>=A && iNum<=B)
                return true;
        return false;
    }
    
    private static Set<String> cycle(String num, int A,int B) {
        Set<String> cycleSet = new TreeSet<String>();
        
        if(isInRange(num,A,B))
            cycleSet.add(num);
        
        for(int i=1;i<num.length();i++) {
            String tmp = num.substring(num.length()-i)+num.substring(0, num.length()-i);
            if(isInRange(tmp, A, B))
                cycleSet.add(tmp);
        }
       // System.out.println(cycleSet);
        return cycleSet;
    }
    
    private static int size(Set<String> set) {
        int size = set.size();
        return (size*(size-1))/2;
    }
    private static int convert(String input) {
        String[] inputArr = input.split(" ");
        
        try {
            int A = Integer.parseInt(inputArr[0]);
            int B = Integer.parseInt(inputArr[1]);
            
            Set<String> processedNumber = new TreeSet<String>();
            
            Set<String> childSet = null;
            int size=0;
            
            int totalCount = 0;
            for(Integer num = A;num<=B;num++) {
                
                if(processedNumber.contains(num.toString()))
                    continue;
                
                childSet = cycle(num.toString(), A, B);
                size = size(childSet);
                
                if(size>0) {
                    totalCount+=size;
                    processedNumber.addAll(childSet);
                }
                
            }
            
            return totalCount;
            
        }
        catch(Exception ex) {
            ex.printStackTrace();
        }
        return 0;
    }
}
