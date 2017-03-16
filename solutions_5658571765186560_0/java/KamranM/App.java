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

            int X, R, C;
            String line = br.readLine();
            String[] args = line.split(" ");
            X = Integer.parseInt(args[0]);
            R = Integer.parseInt(args[1]);
            C = Integer.parseInt(args[2]);

            boolean gabriel = false;
            if (Math.max(R,C) >= X &&
                    (R*C)%X==0 &&
                    (X<3||((int)Math.sqrt(X)+1)<=Math.min(R,C))) {
                gabriel = true;
            }


            String ans = "Case #" + ts + ": " + (gabriel?"GABRIEL":"RICHARD") + "\n";
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
