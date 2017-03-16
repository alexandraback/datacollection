package gcj2015.s1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class ProblemASolver {
    


    public static void main(String[] args) throws FileNotFoundException, IOException {
        File dataDir = new File("data\\gcj2015\\s1c");
        //String fileBaseName = "A-sample-practice";
        String fileBaseName = "A-small-attempt0";
        //String fileBaseName = "A-large";
        //String fileBaseName = "A-large-practice";
        
        
        File inputFile = new File(dataDir, fileBaseName + ".in");
        File outputFile = new File(dataDir, fileBaseName + ".out");
        
        
        try (BufferedReader br = new BufferedReader(new FileReader(inputFile)); PrintStream ps = new PrintStream(outputFile)) {
            String line = br.readLine();
            int numOfProb = Integer.parseInt(line);
            for (int i = 1; i <= numOfProb; i++) {
                line = br.readLine();
                
                ps.printf("Case #%d: %s\n", i, solve(line));
                //ps.printf("%d\n", solve(line));
            }
            
        }

    }

    private static long solve(String line) {
        String[] args = line.split(" ");
        
        int count = 0;
        int r = Integer.parseInt(args[0]);
        int c = Integer.parseInt(args[1]);
        int w = Integer.parseInt(args[2]);
        
        count = (c / w + - 1) + w;
        if (c % w != 0) {
            count++;
        }
        return count;
    }
    

}
