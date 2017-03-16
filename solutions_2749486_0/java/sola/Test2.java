import java.io.*;
import java.util.*;


public class Test2 {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    final static boolean[] isVowel = {true,false,false,false,true,false,false,false,true,false,false,false,false,false,true,false,false,
        false,false,false,true,false,false,false,false,false};
    static int X;
    static int Y;
    
    public static void main (String[] args) throws IOException {
        
        
        //generateInput(100);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "2.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "2.out"));
        
        int tc = sc.nextInt();

        for (int tci=1;tci<=tc;tci++) {
            X = sc.nextInt();
            Y = sc.nextInt();
            String ans="";
            PriorityQueue<Node> pq = new PriorityQueue<Node>();
            pq.add(new Node(0,0,1,""));
            while (!pq.isEmpty()) {
                Node curNode = pq.poll();
                if (curNode.x==X&&curNode.y==Y) {
                    ans = curNode.p;
                    break;
                }//System.out.println(curNode.x + " " + curNode.y);
                List<Node> l = getSuccessors(curNode);
                for (Node n:l) {
                    pq.add(n);
                }
            }
            pw.println("Case #" + tci + ": " + ans);
            System.out.println(tci);
        }
        pw.close();
        sc.close();
    }
    
    private static List<Node> getSuccessors (Node n) {
        List<Node> l = new LinkedList<Node>();
        Node N = new Node(n.x,n.y+n.s,n.s+1,n.p+"N");
        Node S = new Node(n.x,n.y-n.s,n.s+1,n.p+"S");
        Node E = new Node(n.x+n.s,n.y,n.s+1,n.p+"E");
        Node W = new Node(n.x-n.s,n.y,n.s+1,n.p+"W");
        
        l.add(N);
        l.add(S);
        l.add(W);
        l.add(E);
        return l;
    }
    
    private static class Node implements Comparable<Node> {
        public int x;
        public int y;
        public int s;
        public String p;
        
        public Node (int x,int y,int s, String p) {
            this.x = x;
            this.y = y;
            this.s = s;
            this.p = p;
        }

        @Override
        public int compareTo(Node n) {
            // TODO Auto-generated method stub
            return Math.abs(this.x - X)+Math.abs(this.y-Y)-Math.abs(n.x - X)+Math.abs(n.y-Y);
            //return 0;
        }
    }
    
    
    public static void generateInput (int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "2.in"));
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
