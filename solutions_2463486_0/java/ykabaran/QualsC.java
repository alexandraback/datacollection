package codejam2013;

import java.io.*;
import java.math.BigInteger;

public class QualsC extends CodeJam2013 {

    //variables here
    private String min;
    private String max;

    //solution algorithm here
    @Override
    public void solveCases(String inputSize) throws IOException {
        String infilename = "qC" + inputSize + "in.in";
        String outfilename = "qC" + inputSize + "out.in";

        //create output file if it does not exist, otherwise overwrite everything in it
        File file = new File("data/" + outfilename);
        if (!file.exists()) {
            file.createNewFile();
        }

        //create reader and writer for the input and output files
        BufferedReader br = new BufferedReader(new FileReader("data/" + infilename));
        BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));

        //get the number of test cases to use throughout solving process
        int numCases = Integer.parseInt(br.readLine());

        //create some temporary variables to use for storing input variabes and output string
        String line;
        String[] splitted;
        for (int i = 1; i <= numCases; i++) {
            //read in variables here
            line = br.readLine();
            splitted = line.split(" ");
            min = splitted[0];
            max = splitted[1];

            line = "Case #" + i + ": " + solve() + "\n"; //solve here
            bw.write(line);
            System.out.print(line);
        }
        br.close();
        bw.close();
    }

    private static boolean isPalindrome(BigInteger n) {
        String s = n.toString();
        int l = s.length();
        for (int i = 0; i < l / 2; ++i) {
            if (s.charAt(i) != s.charAt(l - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    private static BigInteger nextPalindrome(BigInteger n) {
        String full = n.toString();
        int l = full.length();
        int h = l / 2;
        int[] half;

        if ((l & 1) == 1) {
            half = new int[h + 1];
            for (int i = 0; i <= h; ++i) {
                half[i] = Integer.parseInt(full.substring(h - i, h - i + 1));
            }
        } else {
            half = new int[h];
            for (int i = 0; i < h; ++i) {
                half[i] = Integer.parseInt(full.substring(h - i - 1, h - i));
            }
        }

        int hl = half.length;
        boolean overflow = false;
        int index = 0;
        ++half[0];
        while (half[index] > 9) {
            half[index] = 0;
            ++index;
            if (index >= hl) {
                overflow = true;
                break;
            }
            ++half[index];
        }

        String res = "";
        if (overflow) {
            res = "1";
            for (int i = 0; i < l - 1; ++i) {
                res += "0";
            }
            res += "1";
        } else {
            for (int i = hl - 1; i >= 0; --i) {
                res += half[i];
            }
            if ((l & 1) == 1) {
                for (int i = 1; i < hl; ++i) {
                    res += half[i];
                }
            } else {
                for (int i = 0; i < hl; ++i) {
                    res += half[i];
                }
            }
        }

        return new BigInteger(res);
    }

    private static BigInteger firstPalindrome(BigInteger n) {
        String half;
        String full = n.toString();
        BigInteger temp;
        int l = full.length();

        if (l == 1) {
            return n;
        }

        if ((l & 1) == 1) {
            half = full.substring(0, l / 2);
            temp = new BigInteger(half + full.charAt(l / 2) + reverse(half));
        } else {
            half = full.substring(0, l / 2);
            temp = new BigInteger(half + reverse(half));
        }
        while (temp.compareTo(n) < 0) {
            temp = nextPalindrome(temp);
        }
        return temp;
    }

    private static String reverse(String s) {
        String res = "";
        int l = s.length();
        for (int i = 0; i < l; ++i) {
            res += s.charAt(l - 1 - i);
        }
        return res;
    }

    private static BigInteger ceilingIntegerRoot(BigInteger b) {
        BigInteger from = BigInteger.ONE;
        BigInteger to = new BigInteger(b.toString());
        BigInteger two = new BigInteger("2");
        BigInteger middle;

        while (from.compareTo(to) < 0) {
            middle = (from.add(to)).divide(two);
            if ((middle.pow(2)).compareTo(b) < 0) {
                from = middle.add(BigInteger.ONE);
            } else {
                to = new BigInteger(middle.toString());
            }
        }
        return from;
    }

    private static BigInteger floorIntegerRoot(BigInteger b) {
        BigInteger from = BigInteger.ONE;
        BigInteger to = new BigInteger(b.toString());
        BigInteger two = new BigInteger("2");
        BigInteger middle;

        while (from.compareTo(to) < 0) {
            middle = (from.add(to)).divide(two);
            if ((middle.pow(2)).compareTo(b) < 0) {
                from = middle.add(BigInteger.ONE);
                if ((from.pow(2)).compareTo(b) > 0) {
                    return middle;
                }
            } else {
                to = new BigInteger(middle.toString());
            }
        }
        return from;
    }

    private String solve() {
        BigInteger curr = ceilingIntegerRoot(new BigInteger(min));
        BigInteger end = floorIntegerRoot(new BigInteger(max));
        //String debug = "";
        //debug += curr.toString() + " " + end.toString() + " ";

        BigInteger count = BigInteger.ZERO;
        curr = firstPalindrome(curr);
        // debug += curr.toString() + " ";
        while (curr.compareTo(end) <= 0) {
            if (isPalindrome(curr.pow(2))) {
                count = count.add(BigInteger.ONE);
                // debug += curr.toString() + " ";
            }
            curr = nextPalindrome(curr);
        }
        //System.out.println(debug);
        return count.toString();
    }

    public static void main(String inputSize) {
        CodeJam2013 prob = new QualsC();
        try {
            prob.solveCases(inputSize);
        } catch (IOException e) {
            System.out.println("Cannot read or write to files.");
            System.out.println(e.getMessage());
        }
    }
}
