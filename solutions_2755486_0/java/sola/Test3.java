import java.io.*;
import java.util.*;


public class Test3 {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    static int[] w;
    public static final int CENTER = 450;
    public static void main (String[] args) throws IOException {
        
        
        //generateInput(100);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "3.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "3.out"));
        
        int tc = sc.nextInt();
        
        for (int tci=1;tci<=tc;tci++) {
            w = new int[900];
            int N = sc.nextInt();
            int cnt = 0;
            PriorityQueue<Tribe> pq = new PriorityQueue<Tribe>();
            for (int n=0;n<N;n++) {
                pq.offer(new Tribe(n,sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt()));
            }
            
            List<Tribe> l;
            int cD;
            while (!pq.isEmpty()) {
                cD = pq.peek().d;
                l = new LinkedList<Tribe>();
                while (!pq.isEmpty() && pq.peek().d==cD) {
                    l.add(pq.poll());
                }
                boolean broken = false;
                
                for (Tribe cT:l){
                    for (int i=cT.w;i<=cT.e;i++) {
                        if (w[i]<cT.s) {
                            broken = true;
                            cT.broke = true;
                            cnt++;
                            break;
                        }
                    }
                }
                for (Tribe cT:l) {
                    if (cT.broke) {
                        for (int i=cT.w;i<=cT.e;i++) {
                            if (w[i]<cT.s)
                                w[i] = cT.s;
                        }
                    }
                    cT.broke = false;
                }
                for (Tribe cT:l) {
                    cT.d += cT.dd;
                    cT.w += cT.dp;
                    cT.e += cT.dp;
                    cT.s += cT.ds;
                    cT.n = cT.n - 1;
                    if (cT.n>0) pq.offer(cT);
                }
            }
            
            pw.println("Case #" + tci + ": " + cnt);
            System.out.println(tci);
        }
        pw.close();
        sc.close();
    }
    
    private static class Tribe implements Comparable<Tribe> {
        int id;
        int d;
        int n;
        int w;
        int e;
        int s;
        int dd;
        int dp;
        int ds;
        boolean broke;
        
        public Tribe (int i,int D, int N, int W, int E, int S, int DD, int DP, int DS) {
            id = i;
            d = D;
            n = N;
            w = W*2+CENTER;
            e = E*2+CENTER;
            s = S;
            dd = DD;
            dp = DP*2;
            ds = DS;
            broke = false;
        }

        @Override
        public int compareTo(Tribe t) {
            return d-t.d;
        }
        
        
    }
    
    public static void generateInput (int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "3.in"));
        int maxL = 1000000;
        pw.print(tc);
        Random rd = new Random();
        for (int tci=1;tci<=tc;tci++) {
            pw.println();
            int l = rd.nextInt(maxL);
            int n = rd.nextInt(l);
            String s="";
            for (int i=0;i<l;i++) {
                s += (char) rd.nextInt('a'+26);
            }
            pw.println(s+ " "+n);
        } 
        pw.close();
    }
}
