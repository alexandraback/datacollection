import java.util.*;
import java.io.*;

public class CodeJam {
    private final static String INPUT_FILE_NAME = "A-small.in";
    private final static String OUTPUT_FILE_NAME = "A-small.out";
    public static void main(String[] args) {
        try {

            // read
            FileInputStream instream = new FileInputStream(CodeJam.INPUT_FILE_NAME);
            DataInputStream in = new DataInputStream(instream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));

            // write
            FileOutputStream outstream = new FileOutputStream(CodeJam.OUTPUT_FILE_NAME);
            DataOutputStream out = new DataOutputStream(outstream);
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));

            // reading file information
            int testcases = Integer.parseInt(br.readLine());
            for (int i = 0; i < testcases; i++) {
                // -------------------------------------------------------------------------------------------------------------
                int N = Integer.parseInt(br.readLine());

                Map<Integer, List<Integer>> adjacencyList = new HashMap<Integer, List<Integer>>();
                for(int j=0; j<N;j++){
                    String[] split = br.readLine().split(" ");
                    int numberOfInheritedClasses = Integer.parseInt(split[0]);
                    List<Integer> classes = new ArrayList<Integer>();
                    for(int k=1; k<split.length;k++) { classes.add(Integer.parseInt(split[k])); }
                    adjacencyList.put(j+1, classes);
                }
                //printMap(adjacencyList);
                String result = "No";
                for(int k=0; k < adjacencyList.size(); k++){
                   if (visit(adjacencyList, k+1) == true){
                        result = "Yes";
                   }
                }

                // -------------------------------------------------------------------------------------------------------------
                bw.write("Case #" + (i + 1) + ": " + result + "\r\n");
            }

            // close input file
            in.close();
            // close output file
            bw.flush();
            out.close();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    private static void printMap(Map<Integer, List<Integer>> map){
        for(int i=1; i < map.size(); i++){
            List<Integer> values = map.get(i);
            String str = i + " -> ";
            for(int j =0; i <values.size(); j++) {
                str += values.get(j) + ",";
            }
            System.out.println(str);
        }
    }

    private static boolean visit(Map<Integer, List<Integer>> map, int clazz){
        List<Integer> alreadyVisited = new ArrayList<Integer>();
        Queue<Integer> queue = new LinkedList();
        queue.add(clazz);
        while(!queue.isEmpty()){
          int chlidClass = queue.remove();
           if (alreadyVisited.contains(chlidClass)){
               return true;
           } else {
               alreadyVisited.add(chlidClass);
               queue.addAll(map.get(chlidClass));
           }
        }
        return false;
    }

}

