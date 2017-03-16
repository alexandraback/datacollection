package GCJ2015.Round1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Zhenyi Luo on 15-5-10.
 */
public class C {
    final static String PROBLEM_NAME = "C-small-attempt0";
    final static String WORK_DIR = "/Users/cecilia/Downloads/" + PROBLEM_NAME;
    public void solve(Scanner sc, PrintWriter pw){
        int C = sc.nextInt();
        int D = sc.nextInt();
        int V = sc.nextInt();
        HashSet<Integer> de = new HashSet<>();
        for(int i = 0; i < D; i++){
            de.add(sc.nextInt());
        }
        HashSet<Integer> tmp = new HashSet<>(de);
        while(true){
            boolean flag = true;
            for(int i = 1; i <= V && flag; i++){
                if(!check(i, tmp)){
                    flag = false;
                }
            }
            if(flag){
                break;
            }
            for(int i = 1; i <= V; i++){
                if(!tmp.contains(i)){
                    tmp.add(i);
                    break;
                }
            }
        }
        pw.println(tmp.size() - de.size());
    }

    public boolean check(int i, HashSet<Integer> tmp){
        if(i == 0){
            return true;
        }
        HashSet<Integer> copy = new HashSet<>(tmp);
        for(int num : tmp){
            if(num <= i){
                copy.remove(num);
                if(check(i-num, copy)){
                    return true;
                }
                copy.add(num);
            }
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + ".in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + ".out"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new C().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
