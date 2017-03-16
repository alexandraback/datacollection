package round1A2016;

import utils.FileIO;

import java.io.IOException;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        FileIO io = new FileIO(B.class);
        B solution = new B();
        int T = Integer.parseInt(io.readLine());

        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(io.readLine());

            int[][] H = new int[N * 2 - 1][];

            for (int i = 0; i < N * 2 - 1; i ++){
                H[i] = io.readInts(N);
            }
            io.readLine();
            String output = solution.solve(N, H);
            io.writeLineWithHeader(t, output);

        }
        io.close();
    }

    private String solve(int n, int[][] h) {
        Set<Integer> set = new HashSet<>();

        for (int r = 0; r < n * 2 - 1; r ++){
            for (int c = 0; c < n; c ++){
                if(set.contains(h[r][c])){
                    set.remove(h[r][c]);
                }else {
                    set.add(h[r][c]);
                }
            }
        }
        List<Integer> list = new ArrayList<>();
        list.addAll(set);
        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        for (Integer i : list){
            sb.append(" ");
            sb.append(i);
        }
        return sb.toString();
    }
}