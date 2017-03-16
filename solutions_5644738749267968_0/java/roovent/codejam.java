import java.util.*;
import java.io.*;

public class codejam {
    private static String filename = "D-small-attempt1";

    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(directory + filename + ".in"));
        StringBuilder sb = new StringBuilder();
        
        String line = br.readLine();
        int caseTotal = Integer.parseInt(line);
        int caseNum = 1;
        
        while (caseNum <= caseTotal) {
            int N = Integer.parseInt(br.readLine());
            String[] row1 = br.readLine().split("\\s+");
            String[] row2 = br.readLine().split("\\s+");
            double[] p1 = new double[N];
            double[] p2 = new double[N];
            for (int i = 0; i < N; ++i) {
                p1[i] = Double.parseDouble(row1[i]);
                p2[i] = Double.parseDouble(row2[i]);
            }
     
            Arrays.sort(p1);
            Arrays.sort(p2);
            
            int r1 = 0, r2 = 0;
            int i = 0, j = 0;
            
            while (i < N) {
                if (p1[i] > p2[j]) {
                    i++;
                    j++;
                } else {
                    i++;
                }
            }
            r1 = j;
            
            i = 0; j = 0;
            while (j < N) {
                if (p1[i] < p2[j]) {
                    ++i;
                    ++j;
                } else {
                    ++j;
                }
            }
            r2 = N - i;
            
            sb.append(String.format("Case #%d: %d %d" + newLineChar, caseNum++, r1, r2));
        }
 
        writeToFile(sb);
		System.out.println("Done");
    }
    
    public static void writeToFile(StringBuilder sb) throws IOException { 
		File file = new File(directory + filename + ".out");
        if (!file.exists()) {
            file.createNewFile();
        }

        FileWriter fw = new FileWriter(file.getAbsoluteFile());
        BufferedWriter bw = new BufferedWriter(fw);
        bw.write(sb.toString());
        bw.close();
    }
    
    private static String newLineChar = System.getProperty("line.separator");
    private static String directory = "C:\\Users\\Qing\\Desktop\\";
}

