package GCJ2015.Round1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by Zhenyi Luo on 15-5-10.
 */
public class B {
    final static String PROBLEM_NAME = "B-small-attempt0";
    final static String WORK_DIR = "/Users/cecilia/Downloads/" + PROBLEM_NAME;

    public void solve(Scanner sc, PrintWriter pw){
        int K = sc.nextInt();
        int L = sc.nextInt();
        int S = sc.nextInt();
        char[] keys = sc.next().toCharArray();
        String target = sc.next();
        HashMap<Character, Integer> counts = new HashMap<>();
        for(char c : keys){
            if(counts.containsKey(c)){
                counts.put(c, counts.get(c) + 1);
            }else{
                counts.put(c, 1);
            }
        }

        HashMap<String, Double> probs = new HashMap<>();
        dfs("", probs, counts, 0, S, 1);
        int maxRepeat = 0;
        HashMap<String, Double> repeats = new HashMap<>();
        for(String s : probs.keySet()){
            int ret = count(s, target);
            if(ret > 0){
                repeats.put(s, probs.get(s) * ret / Math.pow(keys.length, S));
                maxRepeat = Math.max(maxRepeat, ret);
            }
        }

        double expected = 0;
        for(double d : repeats.values()){
            expected += d;
        }
        pw.println((double) maxRepeat - expected);
    }

    public int count(String s, String target){
        int ans = 0;
        for(int i = 0; i < s.length() - target.length() + 1; i++){
            if(s.startsWith(target, i)){
                ans++;
            }
        }
        return ans;
    }

    private void dfs(String s, HashMap<String, Double> probs, HashMap<Character, Integer> counts, int start, int end, double count) {
        if(start == end){
            probs.put(s, count);
            return;
        }
        for(char c : counts.keySet()){
            dfs(s + c, probs, counts, start+1, end, count * counts.get(c));
        }
    }


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + ".in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + ".out"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new B().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
