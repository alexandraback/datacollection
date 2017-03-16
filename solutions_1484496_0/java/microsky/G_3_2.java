import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class G_3_2 {

    public static void main(String[] args) throws Exception {
        G_3_2 instance = new G_3_2();
        instance.func();
    }

    PrintWriter bw;
    HashSet<Integer> set;
    HashSet<Integer> set1;
    HashSet<Integer> set2;
    int[] S;
    int N;
    int len1;
    int exp_sum;

    boolean find(int pos, int cur_len, int sum) {
        if (cur_len == len1) {
            exp_sum = sum;
            return find_eq(0, 0);
        } else {
            for (int i = pos; i < N; ++i) {
                if (!set1.contains(S[i])) {
                    set1.add(S[i]);
                    if (find(i + 1, cur_len + 1, sum + S[i])) {
                        return true;
                    }
                    set1.remove(S[i]);
                }
            }
        }
        return false;
    }

    boolean find_eq(int pos, int sum) {
        if (sum == exp_sum) {
            return true;
        }
        for (int i = pos; i < N; ++i) {
            if (!set1.contains(S[i]) && !set2.contains(S[i]) && sum + S[i] <= exp_sum) {
                set2.add(S[i]);
                if (find_eq(i + 1, sum + S[i])) {
                    return true;
                }
                set2.remove(S[i]);
            }
        }
        return false;
    }

    public void func() throws Exception {
        bw = new PrintWriter(new FileWriter("1.txt"));
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        next_i: for (int i = 0; i < T; i++) {
            N = scan.nextInt();
            S = new int[N];
            set = new HashSet<Integer>();
            set1 = new HashSet<Integer>();
            set2 = new HashSet<Integer>();
            for (int j = 0; j < N; ++j) {
                S[j] = scan.nextInt();
                set.add(S[j]);
            }
            Arrays.sort(S);
            print(String.format("Case #%d:\n", (i + 1)));
            boolean impl = true;
            for (len1 = 1; len1 < N; ++len1) {
                if (find(0, 0, 0)) {
                    impl = false;
                    boolean first = true;
                    for (int key : set1) {
                        if (first) {
                            first = false;
                            print(String.format("%d", key));
                        } else {
                            print(String.format(" %d", key));
                        }
                    }
                    print("\n");
                    first = true;
                    for (int key : set2) {
                        if (first) {
                            first = false;
                            print(String.format("%d", key));
                        } else {
                            print(String.format(" %d", key));
                        }
                    }
                    print("\n");
                    continue next_i;
                }
            }
            if (impl) {
                print("Impossible\n");
            }
        }
        bw.flush();
        bw.close();
    }

    void print(String s) {
        System.out.print(s);
        bw.write(s);
    }
}
