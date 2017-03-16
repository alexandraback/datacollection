import java.util.*;
import java.io.*;

public class codejam {
    private static String filename = "B-small-attempt0";

    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(directory + filename + ".in"));
        StringBuilder sb = new StringBuilder();
        
        String line = br.readLine();
        int caseTotal = Integer.parseInt(line);
        int caseNum = 1;
        
        while (caseNum <= caseTotal) {
            line = br.readLine();
            String[] num = line.split("\\s+");
            
            double C = Double.parseDouble(num[0]);
            double F = Double.parseDouble(num[1]);
            double X = Double.parseDouble(num[2]);
            
            double rate = 2.0;
            double min = X / rate;
            double time = 0;
            
            while (true) {
                time += C / rate;
                rate += F;
                double _t = X / rate + time;
                if (_t < min) {
                    min = _t;
                } else {
                    break;
                }
                
            }
            
            sb.append(String.format("Case #%d: %.7f" + newLineChar, caseNum++, min));
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

