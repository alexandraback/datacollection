import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class LastWord {
	public static void main(String[] args) throws Exception
    {
		String inPath = "/Users/Lynn/Downloads/B-small-attempt0.in.txt";
        String outPath = "/Users/Lynn/Downloads/B-small-attempt0.in.out.txt";

        Scanner input = new Scanner(new FileReader(inPath));

        File outFile = new File(outPath);
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
        	int N = input.nextInt();
      	
    		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    		       	
        	for (int l = 0; l < (2*N*N) -N; l ++){
        		int s = input.nextInt();
        		if (!map.containsKey(s)) {
        			map.put(s, 1);
        		}else{
        			map.replace(s, map.get(s) + 1);
        		}
        	}
        	
        	ArrayList<Integer> R = new ArrayList<Integer>();

        	for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        		if (entry.getValue() % 2 != 0){
        			R.add(entry.getKey());
        		}
        	}
        	
        	Collections.sort(R);
        	System.out.println(R.toString());
        	String answer = "";
        	for (int r : R) {
        		answer = answer + " " + r;
        	}

            bw.write("Case #" + (n + 1) + ":" + answer);
            bw.newLine();
        }
        

        bw.close();
    }
}
