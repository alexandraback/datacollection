import java.util.Arrays;  //Arrays.toString(int[])
public class LawnMower {
    public int N;
    public int M;
    public int[][] vec;
//    RedBlackBST<Integer, Integer[]> post = new RedBlackBST<Integer, Integer[]>(); // pos-tree
    LinearProbingHashST<Integer,RedBlackBST<Integer, Integer>> hh = new LinearProbingHashST<Integer, RedBlackBST<Integer, Integer>>(); //heigh hash
    MinPQ<Integer> pq = new MinPQ<Integer>();
    
    public LawnMower(int N, int M, int[][] vec) {
        this.N = N;
        this.M = M;
        this.vec = vec;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                int ht = vec[i][j];
                int idx = Pos2Int(i,j);
//                int[] pos = {i, j};
                if (hh.contains(ht)) {
                     RedBlackBST<Integer, Integer> post = hh.get(ht);
                     post.put(idx,0);
                     hh.put(ht,post);
                }
                else {
                    pq.insert(ht);
                    RedBlackBST<Integer, Integer> post = new RedBlackBST<Integer, Integer>(); // pos-tree
                    post.put(idx,0);
                    hh.put(ht,post);
                }
            }
        }
        
    }
    public String YesOrNo() {
        if (Verify()) return "YES";
        else return "NO";
    }
    public boolean Verify() {
//        boolean ans = true;
        while (!pq.isEmpty()) {
            int ht = pq.delMin();
            RedBlackBST<Integer, Integer> post = hh.get(ht);
            while (!post.isEmpty()) {
                int posint = post.min();
                post.delete(posint);
                int[] pos = Int2Pos(posint);
                boolean tmpjudge = true;
                for (int j = 0; j < M; j++) {
                    int ht2 = vec[pos[0]][j];
                    if (ht2 > ht) {
                        tmpjudge = false;
                        break;
                    }
                }
                if (tmpjudge) {
                    for (int j = 0; j < M; j++) {
                        int ht2 = vec[pos[0]][j];
                        if (ht2 == ht && j != pos[1]) {
//                            StdOut.println(j);
                            if (post.contains(Pos2Int(pos[0], j)))
                                post.delete(Pos2Int(pos[0], j));
                        }
                    }
                }
                else {
                    for (int i = 0; i < N; i++) {
                        int ht2 = vec[i][pos[1]];
                        if (ht2 > ht) return false;
                        else if (ht2 == ht && i != pos[0]) {
                            if (post.contains(Pos2Int(i, pos[1])))
                                post.delete(Pos2Int(i, pos[1]));
                        }
                    }
                }
            }
        }
        return true;
    }
    public int Pos2Int(int n, int m) {
        return n * M + m;
    }
    public int[] Int2Pos(int posint) {
        int[] pos = new int[2];
        pos[0] = posint / M;
        pos[1] = posint % M;
        return pos;
    }
   
    public static void main(String[] args) {
        if (args.length == 0) {
            int N = 3;
            int M = 3;
            int[][] vec = {{2, 1, 2},{1, 1, 1},{2, 1, 2}};
            LawnMower blk = new LawnMower(N, M, vec);
            StdOut.println(blk.Verify());
            return;
        }
        In in = new In(args[0]);
        int T = in.readInt(); // # of test cases
        Out out = new Out(args[0]+".Out");
        for (int i = 0; i < T; i++) {
            int N = in.readInt();
            int M = in.readInt();
            int[][] vec = new int[N][M];
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    vec[j][k] = in.readInt();
                }
            }
            LawnMower blk = new LawnMower(N, M, vec);
            
            out.println("Case #" + (i+1) + ": " + blk.YesOrNo());
            
            //StdOut.println("Case #" + (i+1) + ": " + msp.MinProd());
        }
        out.close();
    }
}