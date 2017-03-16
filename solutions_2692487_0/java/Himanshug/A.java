package gcj.r1b;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class A {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        //String inPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\in.txt";
        
        String inPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\A-small-attempt0.in";
        
        String outPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\out.txt";
        
        Scanner scanner = new Scanner(new File(inPath));
        
        PrintWriter out = pw(outPath);
        //PrintWriter out = pw(null);

        A x = new A();
        
        int T = Integer.parseInt(scanner.nextLine().trim());
        for(int c = 1; c <= T; c++) {
            String[] tmp = scanner.nextLine().trim().split("\\s+");
            long A = Long.parseLong(tmp[0]);
            int N = Integer.parseInt(tmp[1]);
            int[] as = new int[N];
            tmp = scanner.nextLine().trim().split("\\s+");
            for(int i = 0; i < N; i++) {
                as[i] = Integer.parseInt(tmp[i]);
            }
            
            Arrays.sort(as);
            
            //System.out.println("solving case# " + c);
            out.println("Case #" + c + ": " + x.solve(A, as));
        }
        
        
        scanner.close();
        out.close();
    }

    static class P {
        long A;
        int i;
        boolean b;
        
        P(long x, int y, boolean b) {
            A = x;
            i = y;
            this.b = b;
        }
        @Override
        public boolean equals(Object that) {
            if(that instanceof P) {
                P x = (P)that;
                return x.A == A && x.i == i && x.b == b;
            } else {
                return false;
            }
        }
        
        @Override
        public int hashCode() {
            return (Long.valueOf(A).hashCode()) ^ i ^ Boolean.valueOf(b).hashCode() + 31;
        }
    }

    public  long solve(long A, int[] as) {
        P root = new P(A,0,false);
        
        Set<P> visiting = new HashSet<P>();
        Set<P> visited = new HashSet<P>();
        Map<P, P> parents = new HashMap<P, P>();
        
        Queue<P> s = new LinkedList<P>();
        s.offer(root);
        visiting.add(root);
        parents.put(root, null);
        
        P terminal = null;
        
        while(!s.isEmpty()) {
            P u = s.poll();
            
            if(u.i == as.length) {
                terminal = u;
                break;
            }
            
            if(u.A > as[u.i]) {
                P v = new P(u.A + as[u.i], u.i + 1, false);
                add(u,v,visiting,visited,parents,s);
            } else if(u.b){
                P v = new P(u.A, u.i+1, false);
                add(u,v,visiting,visited,parents,s);
            } else {
                P v = new P(2*u.A - 1, u.i, false);
                add(u,v,visiting,visited,parents,s);
                
                v = new P(u.A, u.i, true);
                add(u,v,visiting,visited,parents,s);
            }
            
            visiting.remove(u);
            visited.add(u);
        }
        
        if(terminal != null) {
            long count = 0;
            P x = terminal;
            while((x = parents.get(x)) != null) {
                count++;
            }
            return count - as.length;
        } else {
            throw new RuntimeException("no term found");
        }
    }

    private void add(P u, P v, Set<P> visiting, Set<P> visited, Map<P, P> parents,
                     Queue<P> s) {
        if (!visiting.contains(v) && !visited.contains(v)) {
            visiting.add(v);
            s.offer(v);
            parents.put(v, u);
        }
    }

    private static PrintWriter pw(String file) throws Exception {
        if(file == null) {
            return new PrintWriter(System.out);
        } else {
            return new PrintWriter(new BufferedOutputStream(new FileOutputStream(file)));
        }
    }
}


