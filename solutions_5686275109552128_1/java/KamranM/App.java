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
    private static final int MAX_PANCAKE = 1001;
    int pancIdx = MAX_PANCAKE-1;
    BufferedReader br;
    BufferedWriter bw;

    public App(BufferedReader br, BufferedWriter bw) {
        this.br = br;
        this.bw = bw;
    }

    private int currentAnswer(int[] panc) {
        while (pancIdx >= 0 && panc[pancIdx] == 0) {
            pancIdx--;
        }
        assert pancIdx >= 0;
        return pancIdx;
    }

    public int algo1(int[] panc, String[] PStr) {
        int ans = currentAnswer(panc);

        if (PStr.length == 1) {
            int num = Integer.parseInt(PStr[0]);
            if (num > 3) {
                int sqr = (int) Math.sqrt(num);
                ans = Math.min(ans, sqr - 1 + sqr + num - (sqr * sqr));
            }
        }

        int sleeps = 0;
        for (int i=MAX_PANCAKE-1; i>1; --i) {
            while (panc[i] > 0) {
                sleeps++;
                int first = i/2;
                int second = i-first;
                panc[first]++;
                panc[second]++;
                panc[i]--;
                int temp_ans = sleeps + currentAnswer(panc);
                if (temp_ans < ans) {
                    ans = temp_ans;
                }
            }
        }
        ans = Math.min(ans, sleeps + (panc[1]>0?1:0));
        return ans;
    }

    private int algo2(int[] panc2) {
        int ans = currentAnswer(panc2);
        for (int bound=1; bound<=ans; ++bound) {
            int[] panc = new int[MAX_PANCAKE];
            System.arraycopy(panc2, 0, panc, 0, panc2.length);
            int curans = 0;
            for (int i=MAX_PANCAKE-1; i>bound; --i) {
                panc[bound] += panc[i];
                panc[i-bound] += panc[i];
                curans += panc[i];
            }
            ans = Math.min(ans, curans+bound);
        }
        return ans;
    }

    public void run() throws IOException {
        int T = Integer.parseInt(br.readLine());
        for (int ts=1; ts<=T; ++ts) {
            int D = Integer.parseInt(br.readLine());
            String[] PStr = br.readLine().split(" ");
            int[] panc = new int[MAX_PANCAKE];

            for (int i=0; i< PStr.length; ++i) {
                panc[Integer.parseInt(PStr[i])]++;
            }

            pancIdx = MAX_PANCAKE-1;
            int[] panccopy = new int[MAX_PANCAKE];
            System.arraycopy(panc, 0, panccopy, 0, panc.length);
            int ans = algo1(panccopy, PStr); //it seems algo1 always >= algo2

            pancIdx = MAX_PANCAKE-1;
            System.arraycopy(panc, 0, panccopy, 0, panc.length);
            int algo2ans = algo2(panccopy);

            if (algo2ans < ans) {
                System.out.println("TEST: " + ts);
                System.out.println("ans: " + ans);
                System.out.println("algo2ans: " + algo2ans);
            }
            ans = Math.min(ans, algo2ans);
            //ans = algo2ans;
            String ansLine = "Case #" + ts + ": " + ans + "\n";
            bw.write(ansLine);
            bw.flush();
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
