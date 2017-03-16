package gcj.r1c;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class B {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        //String inPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\in.txt";
        
        String inPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\B-small-attempt0.in";
        
        String outPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\out.txt";
        
        Scanner scanner = new Scanner(new File(inPath));
        
        PrintWriter out = pw(outPath);
        //PrintWriter out = pw(null);

        B x = new B();
        
        int T = Integer.parseInt(scanner.nextLine().trim());
        for(int c = 1; c <= T; c++) {
            String[] tmp = scanner.nextLine().trim().split("\\s+");
            int tx = Integer.parseInt(tmp[0]);
            int ty = Integer.parseInt(tmp[1]);
            
            //System.out.println("solving case# " + c);
            out.println("Case #" + c + ": " + x.solve(tx, ty));
        }
        
        
        scanner.close();
        out.close();
    }
    
   static class P {
        int x;
        int y;
        int l; 
        
        
        P(int x, int y, int l) {
            this.x = x;
            this.y = y;
            this.l = l;
        }
        @Override
        public boolean equals(Object that) {
            if(that instanceof P) {
                P p = (P)that;
                return p.x == x && p.y == y && p.l == l;
            } else {
                return false;
            }
        }
        
        @Override
        public int hashCode() {
            return 31 + x ^ y ^ l;
        }
        
        @Override
        public String toString() {
            return "{" + x + "," + y + "}";
        }
    }
   
    public String solve(int tX, int tY) {
        Set<P> visiting = new HashSet<P>();
        Set<P> visited = new HashSet<P>();
        Map<P, P> parents = new HashMap<P, P>();
        
        P root = new P(0,0,1);
        
        Queue<P> s = new LinkedList<P>();
        s.offer(root);
        visiting.add(root);
        parents.put(root, null);
        
        P terminal = null;
        
        while(!s.isEmpty()) {
            P u = s.poll();
            
            if(u.x == tX && u.y == tY) {
                terminal = u;
                break;
            }
            
            P v = null;
            //N
            v = new P(u.x, u.y + u.l, u.l+1);
            add(u,v,visiting,visited,parents,s);
            
            //S
            v = new P(u.x, u.y - u.l, u.l+1);
            add(u,v,visiting,visited,parents,s);
            
            //E
            v = new P(u.x + u.l, u.y, u.l+1);
            add(u,v,visiting,visited,parents,s);
            
            //W
            v = new P(u.x - u.l, u.y, u.l+1);
            add(u,v,visiting,visited,parents,s);
            
            visiting.remove(u);
            visited.add(u);
        }
        
        visiting = null;
        visited = null;
        
        StringBuilder sb = new StringBuilder();
        if(terminal != null) {
            P v = terminal;
            P u = null;
            while((u = (parents.get(v))) != null) {
                sb.append(getDir(u,v));
                v = u;
            }
            return sb.reverse().toString();
        } else {
            throw new RuntimeException("no term found");
        }
    }

    private String getDir(P u, P v) {
        if(u.x == v.x){
            //moved either n or s
            return v.y > u.y ? "N" : "S";
        } else {
            return v.x > u.x ? "E" : "W";
        }
    }
    
    private void add(P u, P v, Set<P> visiting, Set<P> visited, Map<P,P> parents, Queue<P> s) {
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


