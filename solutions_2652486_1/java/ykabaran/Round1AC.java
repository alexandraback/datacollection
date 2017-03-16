package codejam2013;

import java.io.*;

public class Round1AC extends CodeJam2013 {
    //variables here

    private int numcases;
    private int num;
    private int max;
    private int numprods;
    private long[][] prods;

    //solution algorithm here
    @Override
    public void solveCases(String inputSize) throws IOException {
        String infilename = "C" + inputSize + "in.in";
        String outfilename = "C" + inputSize + "out.in";

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
            numcases = Integer.parseInt(temp[0]);
            num = Integer.parseInt(temp[1]);
            max = Integer.parseInt(temp[2]);
            numprods = Integer.parseInt(temp[3]);
            prods = new long[numcases][numprods];
            for (int j = 0; j < numcases; ++j) {
                line = br.readLine();
                temp = line.split(" ");
                for (int k = 0; k < numprods; ++k) {
                    prods[j][k] = Long.parseLong(temp[k]);
                }
            }

            line = "Case #" + i + ": " + solve() + "\n"; //solve here
            bw.write(line);
            System.out.print(line);
        }
        br.close();
        bw.close();
    }

    private int[] primeFactors(long n) {
        int[] res = new int[max < 7 ? 3 : 4];
        int[] primes = {2, 3, 5, 7};
        long temp = n;
        int p;
        for (int i = 0; i < res.length; ++i) {
            p = primes[i];
            res[i] = 0;
            while (temp % p == 0) {
                ++res[i];
                temp /= p;
            }
        }
        return res;
    }

    private String solveCase(int n) {
        int l = max < 7 ? 3 : 4;
        int[] gurfactors = new int[l];
        long[] set = prods[n];
        long curr;
        for (int i = 0; i < numprods; ++i) {
            curr = set[i];
            if (curr > 1) {
                int[] factors = primeFactors(curr);
                for (int j = 0; j < l; ++j) {
                    if (gurfactors[j] < factors[j]) {
                        gurfactors[j] = factors[j];
                    }
                }
            }
        }
        int count = num;
        int[] primes = {2, 3, 5, 7};
        String res = "";
        if (max < 7) {
            for (int i = 1; i < l; ++i) {
                count -= gurfactors[i];
                for (int j = 0; j < gurfactors[i]; ++j) {
                    res += primes[i];
                }
            }
            int twos = gurfactors[0];
            while (twos > count) {
                res += "4";
                twos -= 2;
                --count;
            }
            for (int i = 0; i < count; ++i) {
                res += "2";
            }
        } else {
            for (int i = 2; i < l; ++i) {
                count -= gurfactors[i];
                for (int j = 0; j < gurfactors[i]; ++j) {
                    res += primes[i];
                }
            }
            if (count == gurfactors[1]) {
                for (int j = 0; j < gurfactors[0]; ++j) {
                    res += "6";
                    --count;
                }
                for (int j = 0; j < count; ++j) {
                    res += "3";
                }
            } else {
                int sixes = gurfactors[0] < gurfactors[1] ? gurfactors[0] : gurfactors[1];
                for (int j = 0; j < sixes; ++j) {
                    res += "6";
                    --gurfactors[0];
                    --gurfactors[1];
                    --count;
                }
                for (int j = 0; j < gurfactors[1]; ++j) {
                    res += "3";
                    --count;
                }
                int twos = gurfactors[0];
                while (twos > count + 1) {
                    res += "8";
                    twos -= 3;
                    --count;
                }
                while (twos > count) {
                    res += "4";
                    twos -= 2;
                    --count;
                }
                for (int i = 0; i < count; ++i) {
                    res += (2 + (int) (Math.random() * ((max - 2) + 1)));
                }
            }
        }
        return res;
    }

    private String solve() {
        String res = "";
        for (int i = 0; i < numcases; ++i) {
            res += "\n" + solveCase(i);
        }
        return res;
    }

    public static void main(String inputSize) {
        CodeJam2013 prob = new Round1AC();
        try {
            prob.solveCases(inputSize);
        } catch (IOException e) {
            System.out.println("Cannot read or write to files.");
            System.out.println(e.getMessage());
        }
    }
}
