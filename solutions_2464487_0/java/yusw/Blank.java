import java.util.Arrays;  //Arrays.toString(int[])
public class Blank {
    public long r;
    public long t;
    
    public Blank(long r, long t) {
        this.r = r;
        this.t = t;
    }
    
    public long MaxCircle() {
        long ans = 0;
        while (TotPaint(ans) <= t)
            ans++;
        return ans - 1;
    }
    public long TotPaint(long n) {
        long ans = 2 * n * n + n * (2 * r - 1);
        return ans;
    }
   
    public static void main(String[] args) {
//        if (args.length == 0) {
//            int[] vec1 = {1, 2, 3, 4, 5};
//            int[] vec2 = {1, 0, 1, 0, 1};
//            Blank blk = new Blank(vec1, vec2);
//            StdOut.println(blk.MinProd());
//            return;
//        }
        In in = new In(args[0]);
        int T = in.readInt(); // # of test cases
//        StdOut.println(T);
        Out out = new Out(args[0]+".Out");
        for (int i = 0; i < T; i++) {
            long r = in.readLong();
            long t = in.readLong();
//            StdOut.println(r);
//            StdOut.println(t);
            Blank blk = new Blank(r, t);
            
            out.println("Case #" + (i+1) + ": " + blk.MaxCircle());
            
            //StdOut.println("Case #" + (i+1) + ": " + msp.MinProd());
        }
        out.close();
    }
}