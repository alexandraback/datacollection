import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class P1 {


    public static void main(String[] args) throws IOException {
        P1 trans = new P1();
        trans.doMe();
    }

    private static final String NAME = "p1l";

    public void doMe() throws IOException {
        File file = new File(NAME + ".in");
        BufferedWriter out = new BufferedWriter(new FileWriter(NAME + ".out"));
        try {
            //use buffering, reading one line at a time
            //FileReader always assumes default encoding is OK!
            BufferedReader input = new BufferedReader(new FileReader(file));
            try {
                String line = input.readLine();
                int count = Integer.parseInt(line);
                for (int i = 0; i < count; i++) {
                    String str = this.processLine(input.readLine().trim(),input.readLine().trim());
                    out.write("Case #" + (i + 1) + ": " + str);
                    if (i < count - 1)
                        out.write(System.getProperty("line.separator"));
                    System.out.println(str);
                }
            } finally {
                input.close();
                out.flush();
                out.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    String processLine(String line, String line2) {
        String s1[] = line.split(" ");
        String s2[] = line2.split(" ");
        long A = Long.parseLong(s1[0]);
        int N = Integer.parseInt(s1[1]);
        List<Integer> other = new ArrayList<Integer>(N);
        for (int i = 0; i < N; i++) {
            other.add(Integer.parseInt(s2[i]));
        }
        Collections.sort(other);
        return ""+rec(other, A);
    }

    public int rec(List<Integer>es, Long mo) {
        List<Integer> e = new ArrayList(es);
        while (e.size()>0 && e.get(0) < mo) {
            mo = mo + e.remove(0);
        }
        if (e.size()==0) return 0;
        else {
            if (mo==1) return e.size();
            int u = 1 + rec(e,mo+mo-1);
            int v = e.size();
            return Math.min(u, v);
        }
    }

    String proccessLines(String lines[]) {
        return null;
    }

}
