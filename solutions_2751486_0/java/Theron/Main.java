package com.company;

import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        final String in = args[0];
        final String out = args[1];

        BufferedReader br = null;
        BufferedWriter bw = null;

        try {
            br = new BufferedReader(new FileReader(in));
            bw = new BufferedWriter(new FileWriter(out));

            int numCases = Integer.parseInt(br.readLine());

            for (int i = 0; i < numCases; i++) {
                String[] line1 = br.readLine().split("\\s");
                String name = line1[0];
                int n = Integer.parseInt(line1[1]);

                int nValue = calculate(name.toCharArray(), n);

                bw.write("Case #" + (i + 1) + ": " + nValue);
                bw.newLine();
            }
        } finally {
            try {
                if (br != null) br.close();
                if (bw != null) bw.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    private static int calculate(char[] name, int n) {
        int count = 0;
        for (int i = 0; i < name.length - n + 1; i++) {
            int match = 0;
            for (int j = i; j < name.length; j++) {

                if (isConsonant(name[j]))
                {
                    match++;
                    if (match == n) {
                        count += name.length-j;
                        break;
                    }
                }
                else
                {
                    match = 0;
                }
            }
        }
        return count;
    }

    private static boolean isConsonant(char c) {
        return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
    }
}
