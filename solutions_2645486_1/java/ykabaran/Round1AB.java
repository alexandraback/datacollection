package codejam2013;

import java.io.*;

public class Round1AB extends CodeJam2013 {
    //variables here

    private long energy;
    private long regain;
    private int numact;
    private long[] activities;

    //solution algorithm here
    @Override
    public void solveCases(String inputSize) throws IOException {
        String infilename = "B" + inputSize + "in.in";
        String outfilename = "B" + inputSize + "out.in";

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
            energy = Long.parseLong(temp[0]);
            regain = Long.parseLong(temp[1]);
            numact = Integer.parseInt(temp[2]);
            activities = new long[numact];

            line = br.readLine();
            temp = line.split(" ");
            for (int j = 0; j < numact; ++j) {
                activities[j] = Long.parseLong(temp[j]);
            }

            line = "Case #" + i + ": " + solve() + "\n"; //solve here
            bw.write(line);
            System.out.print(line);
        }
        br.close();
        bw.close();
    }

    private long solve() {
        long eng = energy;
        long lookahead = energy / regain;
        if (energy % regain == 0) {
            --lookahead;
        }

        long total = 0;
        long temp;
        long curr;

        for (int i = 0; i < numact - 1; ++i) {
            curr = activities[i];
            temp = eng;
            if (regain < energy) {
                for (int j = i + 1; j <= i + lookahead; ++j) {
                    if (j < numact) {
                        if (activities[j] > curr) {
                            temp = (j - i) * regain + eng - energy;
                            if (temp < 0) {
                                temp = 0;
                            } else if (temp > eng) {
                                temp = eng;
                            }
                            j = numact;
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
            eng -= temp;
            total += curr * temp;
            eng += regain;
            if (eng > energy) {
                eng = energy;
            }
        }
        total += activities[numact - 1] * eng;
        return total;
    }

    public static void main(String inputSize) {
        CodeJam2013 prob = new Round1AB();
        try {
            prob.solveCases(inputSize);
        } catch (IOException e) {
            System.out.println("Cannot read or write to files.");
            System.out.println(e.getMessage());
        }
    }
}
