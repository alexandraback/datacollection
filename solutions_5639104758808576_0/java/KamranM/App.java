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

    public App(BufferedReader br, BufferedWriter bw) {
        this.br = br;
        this.bw = bw;
    }

    public void run() throws IOException {
        int T = Integer.parseInt(br.readLine());
        for (int ts=1; ts<=T; ++ts) {
            String line = br.readLine();
            String[] args = line.split(" ");
            int S = Integer.parseInt(args[0]);
            String aud = args[1];
            int added = 0;
            int total = 0;

            for (int i=0; i<=S; ++i) {
                int cur = aud.charAt(i) - 48;

                if (cur > 0 && i > total) {
                    added += (i-total);
                    total = i;
                }

                total += cur;
            }
            String ans = "Case #" + ts + ": " + String.valueOf(added) + "\n";
            bw.write(ans);
        }
        bw.close();
    }

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
