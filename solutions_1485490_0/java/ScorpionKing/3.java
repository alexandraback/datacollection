package google.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.ArrayList;
import java.util.List;

public class ProblemC_3 {
    public ProblemC_3() {
        super();
    }

    public static void main(String[] args) {
        try {
        BufferedReader reader = new BufferedReader(new FileReader("D:\\codejam\\2012\\ProblemA.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("D:\\codejam\\2012\\ProblemA.out"));

                //... Loop as long as there are input lines.
             
            int noOfTestCases = Integer.parseInt(reader.readLine());
            
            int noOfB, noOfT;
            String str;
            String[] tmp;
            
            for(int i=1;i<=noOfTestCases;i++) {
             
                str = reader.readLine();
                tmp = str.split(" ");
                noOfB = Integer.parseInt(tmp[0]);
                noOfT = Integer.parseInt(tmp[1]);
                
                List<Integer> boxNumList = new ArrayList<Integer>();
                List<Integer> boxTypeList = new ArrayList<Integer>();
                
                List<Integer> toyNumList = new ArrayList<Integer>();
                List<Integer> toyTypeList = new ArrayList<Integer>();
                
                Integer totalBoxCount=0;
                Integer totalToyCount=0;
                str = reader.readLine();
                tmp = str.split(" ");
                for(int j=0;j<noOfB;j++) {
                    boxNumList.add(Integer.parseInt(tmp[2*j]));
                    boxTypeList.add(Integer.parseInt(tmp[(2*j)+1]));
                    totalBoxCount += boxNumList.get(j);
                }
                
                str = reader.readLine();
                tmp = str.split(" ");
                for(int j=0;j<noOfT;j++) {
                    toyNumList.add(Integer.parseInt(tmp[2*j]));
                    toyTypeList.add(Integer.parseInt(tmp[(2*j)+1]));
                    totalToyCount += toyNumList.get(j);
                }
                
               Integer score = calculate(boxNumList, boxTypeList, toyNumList, toyTypeList, 0, 0);
                System.out.println("Case #"+i+": "+score);
                writer.write("Case #"+i+": "+score);
                writer.newLine();
            }
                //... Close reader and writer.
                reader.close();  // Close to unlock.
                writer.close();  // Close to unlock and flush to disk.

    }
        catch(Exception ex) {
            ex.printStackTrace();
        }
    }
    
   private static Integer calculate(List<Integer> boxNumList,
                                    List<Integer> boxTypeList,
                                    List<Integer> toyNumList,
                                    List<Integer> toyTypeList,
                                    int i, int j) {
    
        Integer holdBoxScore =0 ;
        Integer holdToyScore= 0;
        
        //System.out.println(i+":"+j);
        if(i>=boxTypeList.size() || j>=toyTypeList.size())
            return 0;
        
        Integer score = 0;
        if((boxNumList.get(i)==0) || (toyNumList.get(j)==0)) {
            if(boxNumList.get(i)==0)
                i++;
            if(toyNumList.get(j)==0)
                j++;
            score = calculate(boxNumList, boxTypeList, toyNumList, toyTypeList, i, j);        
        }
        else {
            List<Integer> boxTmpList = new ArrayList<Integer>(boxNumList);
            List<Integer> toyTmpList = new ArrayList<Integer>(toyNumList);
            
            if(boxTypeList.get(i).equals(toyTypeList.get(j))) {
                score = boxTmpList.get(i)<toyTmpList.get(j)?boxTmpList.get(i):toyTmpList.get(j);
                boxTmpList.set(i, boxTmpList.get(i) - score);
                toyTmpList.set(j, toyTmpList.get(j) - score);
            }

            holdBoxScore = calculate(boxTmpList, boxTypeList, toyTmpList, toyTypeList, i, j+1);
            holdToyScore = calculate(boxTmpList, boxTypeList, toyTmpList, toyTypeList, i+1, j);
       //     System.out.println(i+":"+j+" "+holdBoxScore+":"+holdToyScore+":"+score);
        }
        return (holdBoxScore>holdToyScore? holdBoxScore:holdToyScore)+score;
    }
}
