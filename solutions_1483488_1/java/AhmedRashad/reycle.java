
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;

public class reycle {

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-large.out")));
        boolean state[] = new boolean[2000001];
        HashSet<Integer> mem=new HashSet<Integer>();
        int t = Integer.parseInt(in.readLine());
 
        for (int q = 1; q <= t; q++) {
            String[] st = in.readLine().split(" ");
            int A = Integer.parseInt(st[0]);
            int B = Integer.parseInt(st[1]);
            int count = 0;
            for (int i = A; i <= B; i++) {
                state[i] = true;
                String temp = i + "";
                for (int j = 1; j < temp.length(); j++) {
                    String r = temp.substring(j) + temp.substring(0, j);
                    int b = Integer.parseInt(r);
                    if ((b + "").length() == temp.length() && b >= A && b <= B && !state[b]&&!mem.contains(b)) {
                      mem.add(b);
                        count++;
                    }
                }

            mem.clear();
            }
            out.write("Case #"+q+": "+count+"\n");
            Arrays.fill(state, false);
        }
        out.close();

    }
}
