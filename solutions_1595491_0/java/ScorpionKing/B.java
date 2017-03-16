package google.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Problem2 {
    public Problem2() {
        super();
    }
    
    private static int convert(String input) {
    
        String[] inputArray = input.split(" ");
        
        int noOfCases = Integer.parseInt(inputArray[0]);
        int noOfSurpriseCasesPossible = Integer.parseInt(inputArray[1]);
        int p = Integer.parseInt(inputArray[2]);
        
        List<Integer> cases = new ArrayList<Integer>();
        for(int i = 3;i<inputArray.length; i++)
            cases.add(Integer.parseInt(inputArray[i]));
        
        Collections.sort(cases, Collections.reverseOrder());
        
        int minSurprisingSum = p*3 - 4;
        int minNonSurprisingSum = p*3 -2;
        
        int countNonSurprisingCases = 0;
        int countSurprisingCases = 0;
        
        for(int score:cases) {
            if(score<minSurprisingSum || score<=p)
                break;
            if(score>=minNonSurprisingSum)  
                countNonSurprisingCases++;
            else if(score>=minSurprisingSum)
                countSurprisingCases++;
        }
        
        countNonSurprisingCases+=Math.min(countSurprisingCases, noOfSurpriseCasesPossible);
        
        //System.out.println(countNonSurprisingCases);
        
        return countNonSurprisingCases;    
    }
    
    public static void main(String[] args) {
        try {
        BufferedReader reader = new BufferedReader(new FileReader("D:\\codejam\\2012\\B.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("D:\\codejam\\2012\\B.out"));

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
}
