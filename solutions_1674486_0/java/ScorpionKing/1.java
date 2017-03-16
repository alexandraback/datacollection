package google.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import java.text.DecimalFormat;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class ProblemB_1 {
    public ProblemB_1() {
        super();
    }



    
    public static void main(String[] args) {
        try {
        BufferedReader reader = new BufferedReader(new FileReader("D:\\codejam\\2012\\ProblemA.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("D:\\codejam\\2012\\ProblemA.out"));

                //... Loop as long as there are input lines.
             
            int noOfTestCases = Integer.parseInt(reader.readLine());
            
            int no;
            String str;
            String[] tmp;
            int noOfParents;
            for(int i=1;i<=noOfTestCases;i++) {
                
                str = reader.readLine();
                no = Integer.parseInt(str);
             
                Map<Integer, List<Integer>> directPath = new HashMap<Integer, List<Integer>>();
                Map<Integer, List<Integer>> path = new HashMap<Integer, List<Integer>>();
                
                List<Integer> parentList = null;
                for(Integer j=1;j<=no;j++) {
                    str = reader.readLine();
                    tmp=str.split(" ");
                    noOfParents = Integer.parseInt(tmp[0]);
                    
                    if(noOfParents==0)
                        directPath.put(j, new ArrayList<Integer>());
                    else {
                        parentList = directPath.get(j);
                        if(parentList==null)
                            parentList = new ArrayList<Integer>();
                        for(Integer k=1;k<=noOfParents;k++) {
                            parentList.add(Integer.parseInt(tmp[k]));
                        }
                        directPath.put(j, parentList);
                    }
                    
                    
                }
                
                boolean found = false;
                for(Integer j=1;j<=no;j++) {
                    if(addParents(j, j, directPath, path)) {
                        found=true;
                        break;
                    }
                }
                
                writer.write("Case #"+i+": "+(found?"Yes":"No"));
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
    
    private static boolean addParents(Integer child, Integer child1, Map<Integer, List<Integer>> directPath, Map<Integer, List<Integer>> path ) {
        List<Integer> allDirects=directPath.get(child1);
        List<Integer> pathList;
        for(Integer x:allDirects) {
            pathList = path.get(child);
            if(pathList==null)
                pathList = new ArrayList<Integer>();
            if(pathList.contains(x))
                return true;
            pathList.add(x);
            path.put(child, pathList);
            if(addParents(child, x, directPath, path))
                return true;
        }
        return false;
    }
}
