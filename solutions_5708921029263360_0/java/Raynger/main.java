import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

public class main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter pw = new PrintWriter(System.out);
    public static String line;
    public static StringTokenizer st;
    public static ArrayList<ArrayList<Integer>> adjList;
    public static int[] dr = {-1, 0, 1, 0, -1, 1, 1, -1};
    public static int[] dc = {0, 1, 0, -1, 1, 1, -1, -1};

    public static int K, N;
    public static int[] dp;
    public static TreeMap<Pair, Integer> AB;
    public static TreeMap<Pair, Integer> BC;
    public static TreeMap<Pair, Integer> AC;
    public static int best, bestMap;
    public static ArrayList<Trip> A;

    public static void solve(int n, int map, int total){
        // System.out.println(n)
        if(n >= N){
            if(total > best){
                best = total;
                bestMap = map;
            }
            return;
        }

        solve(n + 1, map, total);

        Trip t = A.get(n); int i = t.a; int j = t.b; int k = t.c;
        Pair ab = new Pair(i, j);
        Pair bc = new Pair(j, k);
        Pair ac = new Pair(i, k);

        if(AB.get(ab) >= K || BC.get(bc) >= K || AC.get(ac) >= K){
            return;
        }
        AB.put(ab, AB.get(ab)+1);
        BC.put(bc, BC.get(bc)+1);
        AC.put(ac, AC.get(ac)+1);
        solve(n + 1, (map | (1 << n)), total+1);
        AB.put(ab, AB.get(ab)-1);
        BC.put(bc, BC.get(bc)-1);
        AC.put(ac, AC.get(ac)-1);
    }

    public static void main(String[] args) throws Exception{
        ArrayList<Trip> threes = new ArrayList<Trip>();
        boolean seen = false;
        int T = Integer.parseInt(br.readLine());
        int cases = 0;
        while(T-- != 0){
            pw.format("Case #%d: ", ++cases);
            st = new StringTokenizer(br.readLine());
            best = 0;
            bestMap = 0;
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            if(a == 3 && b== 3 && c == 3 && K >= 3 && seen){
                ArrayList<Trip> A1 = threes;
                pw.print(A1.size() + "\n");
                for(int i = 0; i < A1.size(); i++){
                    Trip t = A1.get(i);
                    pw.print(t.a + " " + t.b + " " + t.c + "\n");
                }
                continue;
            }

            AB = new TreeMap<Pair, Integer>();
            BC = new TreeMap<Pair, Integer>();
            AC = new TreeMap<Pair, Integer>();

            N = a * b * c;
            A = new ArrayList<Trip>();
            for(int i = 1; i <= a; i++){
                for(int j = 1; j <= b; j++){
                    for(int k = 1; k <= c; k++){
                        Pair ab = new Pair(i, j);
                        Pair bc = new Pair(j, k);
                        Pair ac = new Pair(i, k);

                        if(!AB.containsKey(ab)) AB.put(ab, 0);
                        if(!BC.containsKey(bc)) BC.put(bc, 0);
                        if(!AC.containsKey(ac)) AC.put(ac, 0);

                        A.add(new Trip(i, j, k));
                    }
                }
            }

            // pw.print(bestMap);
            solve(0, 0, 0);

            ArrayList<Trip> A1 = new ArrayList<Trip>();
            for(int i = 0; i < N; i++){
                if((bestMap & (1 << i)) != 0){
                    A1.add(A.get(i));
                }
            }

            pw.print(A1.size() + "\n");
            for(int i = 0; i < A1.size(); i++){
                Trip t = A1.get(i);
                pw.print(t.a + " " + t.b + " " + t.c + "\n");
            }
            if(a == 3 && b == 3 && c == 3 && K >= 3){
                threes = new ArrayList<Trip>(A1);
                seen = true;
            }
        }

        pw.close();
        br.close();
    }
}

class Trip{
    public int a, b, c;

    Trip(int a, int b, int c){
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

class Pair implements Comparable<Pair>{
    public int a, b;

    Pair(int a, int b){
        this.a = a;
        this.b = b;
    }

    @Override
    public int compareTo(Pair P){
        if(P.a != this.a){
            return this.a - P.a;
        } else{
            return b - P.b;
        }
    }

    public String toString(){
        return a + " " + b;
    }
}
