package Main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.PriorityQueue;

public class ProblemBRound1C {

    static BufferedReader br;
    static BufferedWriter bw;

    public static void main(String[] args) {
        try {

            readInputFile();
            createOutputFile();

            String line1 = br.readLine();
            int testCases = Integer.parseInt(line1);

            int testIndex = 0;

            while (testCases != testIndex) {

                String answer = getAnswer();
                bw.write("Case #" + ++testIndex + ": " + answer + "\n");

            }

            bw.close();
            br.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException("File not found.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String getAnswer() throws IOException {
        String[] info1 = br.readLine().split(" ");

        int x = Integer.parseInt(info1[0]);
        int y = Integer.parseInt(info1[1]);
        
        StringBuilder out = new StringBuilder();
        
        if (x>0){
            for (int i = 0; i < x; i++){
                out.append("WE");
            }
        } else {
            for (int i = 0; i < -x; i++){
                out.append("EW");
            }
        }
        
        if (y>0){
            for (int i = 0; i < y; i++){
                out.append("SN");
            }
        } else{
            for (int i = 0; i < -y; i++){
                out.append("NS");
            }
        }
        return out.toString();
    }

   

    private static void readInputFile() throws IOException {

        br = new BufferedReader(new FileReader("filesB1C/test.in"));
        //br = new BufferedReader(new FileReader("filesA1C/input.txt"));
    }

    private static void createOutputFile() throws IOException {

        int counter = 0;
        File outputFile;
        while ((outputFile = new File("filesB1C/output" + counter + ".txt"))
                .exists()) {
            counter++;
        }

        outputFile.createNewFile();

        FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
        bw = new BufferedWriter(fw);
    }

}
