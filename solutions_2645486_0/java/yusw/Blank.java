import java.util.Arrays;  //Arrays.toString(int[])
public class Blank {
    public int E;
    public int R;
    public int[] Arr;
    public int taskNum;
    public Blank(int e, int r, int[] vec) {
        E = e;
        R = r;
        Arr = vec;
        taskNum = vec.length;
    }
    public int Res() {
        return MaxG(0, E);
    }
    public int MaxG(int idx, int Eng) {
        if (idx >= taskNum) return 0;
        int ans = 0;
        Eng = Math.min(E, Eng);
        for (int e = 0; e <= Eng; e++) {
            int temp = e*Arr[idx] + MaxG(idx + 1, Eng - e + R);
            if (temp > ans)
                ans = temp;
        }
        return ans;
    }
    public static void main(String[] args) {
        if (args.length == 0) {
//            int[] vec1 = {1, 2, 3, 4, 5};
//            int[] vec2 = {1, 0, 1, 0, 1};
//            Blank blk = new Blank(vec1, vec2);
//            StdOut.println(blk.MinProd());
//            return;
        }
        In in = new In(args[0]);
        int T = in.readInt(); // # of test cases
        Out out = new Out(args[0]+".Out");
        for (int i = 0; i < T; i++) {
            int E = in.readInt();
            int R = in.readInt();
            int N = in.readInt();
            int[] vec = new int[N];
            for (int j = 0; j < N; j++) {
                vec[j] = in.readInt();
            }
            Blank blk = new Blank(E, R, vec);
            
            out.println("Case #" + (i+1) + ": " + blk.Res());
            
            //StdOut.println("Case #" + (i+1) + ": " + msp.MinProd());
        }
        out.close();
    }
}