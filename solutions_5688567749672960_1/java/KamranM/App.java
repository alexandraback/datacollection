package com.rocketfuel.kamran;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 * Hello world!
 *
 */
public class App
{
    BufferedReader br;
    BufferedWriter bw;

    public static final int MAX_SIZE = 1000001;
    public static int[] ANS = new int[MAX_SIZE+3];

    public App(BufferedReader br, BufferedWriter bw) {
        this.br = br;
        this.bw = bw;
    }



    public void run() throws IOException {
        int T = Integer.parseInt(br.readLine());
        //System.out.println(T);
        for (int ts=1; ts<=T; ++ts) {
            long N = Long.parseLong(br.readLine());

            long ans = 1L;
            while (N != 1L) {
                String str = String.valueOf(N);
                int len = str.length();
                //int len = (int)Math.log10(N+1e-13) + 1;
                len = (len+1)/2;
                if (N % ((long)(Math.pow(10, len)+(1e-13))) == 1) {
                    str = String.valueOf(N);
                    StringBuilder builder = new StringBuilder();
                    for (int j=str.length()-1; j>=0; --j) {
                        builder.append(str.charAt(j));
                    }
                    str = builder.toString();
                    long nextN = Long.parseLong(str);
                    if (nextN < N) {
                        N = nextN;
                    } else {
                        N--;
                    }
                } else {
                    N--;
                }
                //System.out.println(N);
                ++ans;
            }

            String ansStr = "Case #" + ts + ": " + String.valueOf(ans) + "\n";
            bw.write(ansStr);
            bw.flush();
        }

        br.close();
        bw.close();
    }

    /*public void run() throws IOException {

        for (int i=1; i<MAX_SIZE; ++i) {
            ANS[i] = i;
        }

        for (int i=1; i<MAX_SIZE; ++i) {
            String str = Integer.toString(i);
            StringBuilder builder = new StringBuilder();
            for (int j=str.length()-1; j>=0; --j) {
                builder.append(str.charAt(j));
            }
            str = builder.toString();
            int next = Integer.parseInt(str);
            //if (i==12)
            //    System.out.println(next);
            ANS[next] = Math.min(ANS[next], ANS[i]+1);
            ANS[i+1] = Math.min(ANS[i+1], ANS[i]+1);
            if (ANS[i] >= ANS[i+1])
                System.out.println("(" + i + " " + ANS[i] + ", " + (i+1) + " " + ANS[i+1] + ")");
        }

        /*int T = Integer.parseInt(br.readLine());
        for (int ts=1; ts<=T; ++ts) {
            int N = Integer.parseInt(br.readLine());
            String ans = "Case #" + ts + ": " + String.valueOf(ANS[N]) + "\n";
            bw.write(ans);
        }
        bw.flush();
        br.close();
        bw.close();
    }*/

    public static void main( String[] args )
    {
        BufferedReader br = null;
        BufferedWriter bw = null;
        if (System.getProperty("input.stdin").equals("true")) {
            br = new BufferedReader(new InputStreamReader(System.in));
            bw = new BufferedWriter(new PrintWriter(System.out));
        } else {
            ClassLoader classLoader = App.class.getClassLoader();
            try {
                br = new BufferedReader(new FileReader(
                        new File(classLoader.getResource("1.txt").getFile())));
                bw = new BufferedWriter(new FileWriter(
                        new File("src/main/resources/2.txt")
                ));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {

            }
        }
        try {
            new App(br, bw).run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
