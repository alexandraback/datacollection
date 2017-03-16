import java.io.*;
import java.util.*;


public class B {
    static final String filename = "B";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        B solver = new B();
        solver.solve(s, w);
        w.close();
    }

    int X,Y;
    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            X=s.nextInt();
            Y=s.nextInt();
            String ans=solve();

            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";

            w.write(out);
            System.out.print(out);
        }

    }
    int[]dx={0,0,-1,1};
    int[]dy={-1,1,0,0};
    char[]dc={'S','N','W','E'};
    Set<P>set;
    String solve(){
        set=new HashSet<P>();
        PriorityQueue<P>q=new PriorityQueue<P>();
        q.offer(new P(0,0,"",0));
        while(!q.isEmpty()){
            P p=q.poll();
            if(p.x==X&&p.y==Y)
                return p.s;
            if(p.l>=500)continue;
            if(set.contains(p))continue;
            set.add(p);
            //System.out.println(p);
            //int D=p.l*(p.l+1)/2;
            for(int d=0;d<4;d++){
                q.offer(new P(p.x+dx[d]*(p.l+1),p.y+dy[d]*(p.l+1),p.s+dc[d],p.l+1));
            }
        }

        return "";
    }
}

class P implements Comparable<P>{
    int x,y;
    String s;
    int l;

    P(int x, int y, String s, int l) {
        this.x = x;
        this.y = y;
        this.s = s;
        this.l = l;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof P)) return false;

        P p = (P) o;

        if (l != p.l) return false;
        if (x != p.x) return false;
        if (y != p.y) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        result = 31 * result + l;
        return result;
    }

    @Override
    public int compareTo(P o) {
        return l-o.l;
    }

    @Override
    public String toString() {
        return "P{" +
                "x=" + x +
                ", y=" + y +
                ", s='" + s + '\'' +
                ", l=" + l +
                '}';
    }
}