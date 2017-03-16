import com.sun.deploy.util.ArrayUtil;

import javax.xml.bind.attachment.AttachmentUnmarshaller;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main implements Runnable {

    boolean canLose(int i, double p, int sum, int[] s) {
        double pro = 1-p;
        double have = s[i] + p*sum;
        for (int j = 0; j < s.length; j++) {
            if (j == i) continue;
            double cur = s[j];
            if (cur >= have) continue;
            double need = have-cur;
            pro -= need/sum;
        }
        return pro >= 0;
    }

    void solveCase(int tc) throws Exception {
        out.print("Case #" + (tc + 1) + ":\n");
        int n = nextInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i++)
            t[i] = nextInt();
        HashMap<Integer, Integer> have = new HashMap<Integer, Integer>();
        Arrays.sort(t);
        boolean good = false;
        for (int i = 0; i < (1<<20); i++) {
            int sum = 0;
            for (int j = 0; j < 20; j++)
                if (((i>>j)&1) == 0)
                    sum += t[j];
            if (have.containsKey(sum)) {
                int mask0 = have.get(sum);
                if ((mask0&i)!=0) continue;
                for (int k = 0; k < 20; k++)
                    if (((mask0>>k)&1) == 1)
                        out.print(t[k] + " ");
                out.println();
                for (int k = 0; k < 20; k++)
                    if (((i>>k)&1) == 1)
                        out.print(t[k] + " ");
                good = true;
                break;
            }
            else
                have.put(sum, i);
        }
        if (!good)
            out.print("Impossible");
        out.println();
    }

    void solution() throws Exception {
        int tc = nextInt();
        for (int i = 0; i < tc; i++)
            solveCase(i);
    }

    ///////////////////// Template definitions //////////////////////////
    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String l = in.readLine();
            if (l == null) return null;
            st = new StringTokenizer(l);
        }
        return st.nextToken();
    }

    public static void main(String args[]) {
        //Locale.setDefault(Locale.UK);
        new Thread(new Main()).start();
    }

    public void run() {
        try {
            //boolean online = System.getProperty("ONLINE_JUDGE") != null;
            boolean online = false;
            Reader reader = online
                    ? new InputStreamReader(System.in)
                    : new FileReader("C-small-attempt1.in");
            in = new BufferedReader(reader);
            //out = new PrintWriter(System.out);
            out = new PrintWriter(new File("C-small-attempt1.out"));
            solution();
            out.flush();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(202);
        }
    }

    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
}