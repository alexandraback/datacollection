
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alex
 */
public class Dancing {
    private class Data {
        public int N;
        public int S;
        public int p;
        public int[] totalScores;
        public int[][] scores;
        
        public Data(String s) {
            String[] parts = s.trim().split(" ");
            N = Integer.parseInt(parts[0]);
            S = Integer.parseInt(parts[1]);
            p = Integer.parseInt(parts[2]);
            totalScores = new int[N];
            scores = new int[N][3];
            for (int i=0;i<N;i++) {
                totalScores[i] = Integer.parseInt(parts[3+i]);
            }            
        }
        
        public Data(int n_, int s_, int p_, int[] tS) {
            N = n_;
            S = s_;
            p = p_;
            totalScores = tS;
            scores = new int[N][3];
        }
        
        public int Solve() {
            for (int i=0; i<N;i++) {
                double avgScore = totalScores[i]/3.0;
                //System.out.println(avgScore);
                if (avgScore == (int)avgScore) {
                    scores[i][0] = scores[i][1] = scores[i][2] = (int)avgScore;
                    continue;
                }

                scores[i][1] = Math.round((float)avgScore);

                double rem = totalScores[i] - scores[i][1]; //remaining two numbers sum
                scores[i][0] = (int)(rem/2);
                scores[i][2] = totalScores[i] - scores[i][0] - scores[i][1];
                //System.out.println(""+scores[i][0]+" "+scores[i][1]+" "+scores[i][2]);
                Arrays.sort(scores[i]);
            }

            int i=-1;
            while (S > 0 && ++i<N) {
                //int max = Math.max(scores[i][0],Math.max(scores[i][1], scores[i][2]));
                if (scores[i][2] == p - 1) { //can change 
                    if (scores[i][0] == scores[i][1] && scores[i][2] > scores[i][1]) //it's like 3,3,4 therefore can't fix it
                        continue;
                    if (scores[i][1] == 0) //can't decrease
                        continue;
                    scores[i][1]--;
                    scores[i][2]++;
                    S--;
                }
            }
            if (S > 0) {
                System.err.println("What the fuck");
                //return;
            }

            int above = 0;
            for (i=0; i<N;i++) {
                System.out.println(""+scores[i][0]+" "+scores[i][1]+" "+scores[i][2]);
                if (scores[i][2] >= p)
                    above++;
            }
            return above;
        }
    }
    
    private static String IN = ".\\B-small-attempt0.in";
    private static String OUT = ".\\B-small-attempt0.out";
    
    private Data[] datas;
    
    private void go() {
        File file = new File(IN);
        System.out.println(file.getAbsolutePath());
        File fo = new File(OUT);
        try {
            if (!fo.createNewFile()) {
                fo.delete();
                fo.createNewFile();
            }
            BufferedReader br = new BufferedReader(new FileReader(file));
            BufferedWriter bw = new BufferedWriter(new FileWriter(fo));
            String line;
            int num = Integer.parseInt(br.readLine());
            datas = new Data[num];
            int i = 0;
            while ((line = br.readLine()) != null && num-->0) {
                datas[i] = new Data(line);
                int solv = datas[i].Solve();
                String ss = "Case #"+(i+1)+": "+solv+"\n";
                System.out.print(ss);
                bw.write(ss);
                i++;
            }
            br.close();
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public Dancing() {
        go();
        //test();
    }
    
    public void test() {
        int N = 3; //num of googlers
        int S = 1; //num surprising scores
        int p = 5; //greater high score than 5
        int[] ns = new int[]{15,13,11};
        
        int[][] scores = new int[3][3];
        
        for (int i=0; i<N;i++) {
            double avgScore = ns[i]/3.0;
            System.out.println(avgScore);
            if (avgScore == (int)avgScore) {
                scores[i][0] = scores[i][1] = scores[i][2] = (int)avgScore;
                continue;
            }
            
            scores[i][1] = Math.round((float)avgScore);
            
            double rem = ns[i] - scores[i][1]; //remaining two numbers sum
            scores[i][0] = (int)(rem/2);
            scores[i][2] = ns[i] - scores[i][0] - scores[i][1];
            //System.out.println(""+scores[i][0]+" "+scores[i][1]+" "+scores[i][2]);
            Arrays.sort(scores[i]);
        }
        
        int i=0;
        while (S > 0 && i<N) {
            //int max = Math.max(scores[i][0],Math.max(scores[i][1], scores[i][2]));
            if (scores[i][2] == p - 1) { //can change 
                if (scores[i][0] == scores[i][1] && scores[i][2] > scores[i][1]) //it's like 3,3,4 therefore can't fix it
                    continue;
                scores[i][1]--;
                scores[i][2]++;
                S--;
            }
            i++;
        }
        if (S > 0) {
            System.err.println("What the fuck");
            return;
        }
        
        int above = 0;
        for (i=0; i<N;i++) {
            System.out.println(""+scores[i][0]+" "+scores[i][1]+" "+scores[i][2]);
            if (scores[i][2] >= p)
                above++;
        }
        System.out.println("The answer is " + above);
    }
    
    public void comb(int total) {
        
    }
    
    public static void main(String[] args) {
        new Dancing();
    }
}
