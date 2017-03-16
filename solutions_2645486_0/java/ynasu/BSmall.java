import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BSmall {
    public long solve(int E, int R, int[] v) {
        int res = 0;
        int[] mem = new int[E + 1];
        Arrays.fill(mem, -1);
        mem[E] = 0;
        for(int i = 0; i < v.length; i++){
            int[] gains = new int[mem.length];
            Arrays.fill(gains, -1);
            for(int j = 1; j < mem.length; j++){
                int e = Math.min(E, j + R);
                gains[e] = Math.max(gains[e], mem[j]);
            }
            for(int j = 1; j < mem.length; j++){
                if(mem[j] >= 0){
                    for(int k = 1; j - k >= 0; k++){
                        int e = Math.min(E, j - k + R);
                        gains[e] = Math.max(gains[e], mem[j] + v[i] * k);
                        res = Math.max(res, gains[e]);
                    }
                }
            }
            mem = gains;
        }
        return res;
    }

    public static void main(String[] args) {
        try {
            int T;
            BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

            T = Integer.parseInt(input.readLine());
            for (int i = 0; i < T; i++) {
                String[] str = input.readLine().split(" ");
                if (str.length != 3) throw new RuntimeException();
                int E = Integer.parseInt(str[0]);
                int R = Integer.parseInt(str[1]);
                int N = Integer.parseInt(str[2]);
                str = input.readLine().split(" ");
                if (str.length != N) throw new RuntimeException();
                int[] v = new int[N];
                for (int j = 0; j < N; j++) {
                    v[j] = Integer.parseInt(str[j]);
                }
                System.out.println("Case #" + (i + 1) + ": " + new BSmall().solve(E, R, v));
            }
            if (input.readLine() != null) throw new RuntimeException();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
