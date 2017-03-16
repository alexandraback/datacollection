import java.util.*;
import java.io.*;
import java.lang.Math;

public class C {
    public static void main(String[] args) throws IOException {
        Scanner inFile = new Scanner(new FileReader("c.in"));
        PrintWriter outFile = new PrintWriter(new FileWriter("c.out"));
        
        int caseAmount = Integer.parseInt(inFile.nextLine());
        for (int caseNum = 1; caseNum <= caseAmount; caseNum++) {
            String line = inFile.nextLine();
            int n = Integer.parseInt(line.split(" ")[0]);
            int[] s = new int[500];
            for (int i = 0; i < n; i++)
                s[i] = Integer.parseInt(line.split(" ")[i + 1]);
            
            HashMap <Long, String> hm;
            hm = new HashMap <Long, String> ();
            
            String result = "Impossible", bs = "";
            
            for (long k = 0; k < Math.pow(2, n); k++) {
                bs = "";
                long temp = k, sum = 0;
                int j = 0;
                while (temp > 0) {
                    if (temp % 2 == 1) {
                        bs += "1";
                        sum += s[j];
                    } else {
                        bs += "0";
                    }
                    temp /= 2;
                    j++;
                }
                
                if (hm.get(sum) != null) {
                    result = hm.get(sum);
                    
                    break;
                    
                } else {
                    hm.put(sum, bs);
                }
                
            }
            
            outFile.println("Case #" + caseNum + ":");
            
            for (int i = 0; i < bs.length(); i++) {
                if (bs.charAt(i) == '1')
                    outFile.print(s[i] + " ");
            }
            outFile.println();
            
            for (int i = 0; i < result.length(); i++) {
                if (result.charAt(i) == '1')
                    outFile.print(s[i] + " ");
            }
            outFile.println();
            
            outFile.flush();
        }
        
        inFile.close();
        outFile.close();
    }
}
