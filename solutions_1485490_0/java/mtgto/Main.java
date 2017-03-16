import java.util.*;
import java.math.*;

class Pair {
    long count;
    int type;

    Pair(long _c, int _t) {
        count = _c;
        type = _t;
    }
}

class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    public void solve() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.printf("Case #%d: ", t+1);
            int N = sc.nextInt();
            int M = sc.nextInt();
            Pair[] ary1 = new Pair[N];
            Pair[] ary2 = new Pair[M];
            for (int n=0; n<N; n++) {
                long count = sc.nextLong();
                int type = sc.nextInt();
                ary1[n] = new Pair(count, type);
            }
            for (int m=0; m<M; m++) {
                long count = sc.nextLong();
                int type = sc.nextInt();
                ary2[m] = new Pair(count, type);
            }
            //System.err.println("N,M="+N+","+M);
            System.out.println(find(ary1, ary2, 0, 0, 0L));
        }
    }

    public long find(Pair[] ary1, Pair[] ary2, int idx1, int idx2, long score) {
        if (idx1 >= ary1.length || idx2 >= ary2.length) {
            return score;
        }
        //System.err.println("idx1="+idx1+",idx2="+idx2);
        if (ary1[idx1].type == ary2[idx2].type) {
            long use = Math.min(ary1[idx1].count, ary2[idx2].count);
            //System.err.println("type="+ary1[idx1].type+",use="+use+",idx1="+idx1+",idx2="+idx2+",score="+score);
            ary1[idx1].count -= use;
            ary2[idx2].count -= use;
            score = Math.max(score, find(ary1, ary2, ary1[idx1].count == 0 ? idx1+1 : idx1, ary2[idx2].count == 0 ? idx2+1 : idx2, score + use));
            ary1[idx1].count += use;
            ary2[idx2].count += use;
        } else {
            score = Math.max(find(ary1, ary2, idx1+1, idx2, score), find(ary1, ary2, idx1, idx2+1, score));
        }
        return score;
    }
}