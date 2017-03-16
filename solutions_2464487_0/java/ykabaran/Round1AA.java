package codejam2013;

import java.io.*;

public class Round1AA extends CodeJam2013 {
    //variables here

    private long r;
    private long t;

    //solution algorithm here
    @Override
    public void solveCases(String inputSize) throws IOException {
        String infilename = "A" + inputSize + "in.in";
        String outfilename = "A" + inputSize + "out.in";

        //create output file if it does not exist, otherwise overwrite everything in it
        File file = new File("data/round1A/" + outfilename);
        if (!file.exists()) {
            file.createNewFile();
        }

        //create reader and writer for the input and output files
        BufferedReader br = new BufferedReader(new FileReader("data/round1A/" + infilename));
        BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));

        //get the number of test cases to use throughout solving process
        int numCases = Integer.parseInt(br.readLine());

        //create some temporary variables to use for storing input variabes and output string
        String line;
        String[] temp;
        for (int i = 1; i <= numCases; i++) {
            //read in variables here
            line = br.readLine();
            temp = line.split(" ");
            r = Long.parseLong(temp[0]);
            t = Long.parseLong(temp[1]);

            line = "Case #" + i + ": " + solve() + "\n"; //solve here
            bw.write(line);
            System.out.print(line);
        }
        br.close();
        bw.close();
    }

    private long solve() {
        long left = t;
        long currrad = r;
        long count = 0;

        long nextarea = 2 * currrad + 1;
        while (left >= nextarea) {
            left -= nextarea;
            currrad += 2;
            nextarea = 2 * currrad + 1;
            ++count;
        }

        return count;
    }

    public static void main(String inputSize) {
        CodeJam2013 prob = new Round1AA();
        try {
            prob.solveCases(inputSize);
        } catch (IOException e) {
            System.out.println("Cannot read or write to files.");
            System.out.println(e.getMessage());
        }
    }
}
