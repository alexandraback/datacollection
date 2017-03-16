package gcj2013.r1c;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class C {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2013/r1c/C-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");            
            int res = solve(s);
            out.print(res);
            out.println();          
        }
        out.close();
    }

    static int solve(Scanner sc) {
        int tn = sc.nextInt();
        List<Attack> list = new ArrayList<Attack>();
        for(int i=0; i<tn; i++) {
            int d = sc.nextInt();
            int n = sc.nextInt();
            int w = sc.nextInt();
            int e = sc.nextInt();
            int s = sc.nextInt();
            int dd = sc.nextInt();
            int dp = sc.nextInt();
            int ds = sc.nextInt();
            for(int j=0; j<n; j++) {
                list.add(new Attack(d + dd * j, w + dp * j, e + dp * j, s + ds * j));
            }
        }
        Collections.sort(list);
        int[] wall = new int[200000];
        int[] nextwall = new int[200000];
        int center = 100000;
        int day = -1;
        int res = 0;
        for(Attack a : list) {
            boolean success = false;
            if(day != a.d) {
                System.arraycopy(nextwall, 0, wall, 0, 200000);
                day = a.d;
            }
            for(int pos = a.w; pos < a.e; pos++) {
                if(wall[center+pos] < a.s) {
                    nextwall[center+pos] = Math.max(nextwall[center+pos], a.s);
                    success = true;
                }
            }
            if(success) {
                res ++;
            }
            
        }
        return res;
    }
    
    static class Attack implements Comparable<Attack>{
        public int d;
        public int w;
        public int e;
        public int s;
        public Attack(int d, int w, int e, int s) {
            this.d = d;
            this.w = w;
            this.e = e;
            this.s = s;
        }
        @Override
        public String toString() {
            return String.format("a(d:%d w:%d e:%d s:%d)", d, w, e, s);
        }
        @Override
        public int compareTo(Attack o) {
            return d - o.d;
        }
    }
    
}
