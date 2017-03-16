import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Task1 {
    public static int[][] verts;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(new File("t.txt")));
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File("out.txt")));
        int num = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < num; i++) {
            String orig = reader.readLine();
            writer.write("Case #" + (i + 1) + ": ");
            int v = Integer.parseInt(orig);
            verts = new int[v][];
            for (int j = 0; j < v; j++) {
                String[] vv = reader.readLine().split(" +");
                verts[j] = new int[vv.length];
                for (int k = 0; k < vv.length; k++) {
                    verts[j][k] = Integer.parseInt(vv[k]);
                }
            }
            boolean b2 = false;
            for (int j = 0; j < verts.length; j++) {
                if (verts[j][0] > 1) {
                    b2 = false;
                    int[] mas = new int[verts.length+1];
                    for (int k = 1; k <= verts[j][0]; k++) {
                        List<Integer> res = pathExist(verts[j][k]);
                        for (Integer it : res) {
                            if (mas[it] > 0) {
                                b2 = true;
                                break;
                            } else {
                                mas[it]++;
                            }
                        }


                    }
                }
                if (b2) {
                    writer.write("Yes");
                    break;
                }
            }
        if (!b2) {
            writer.write("No");
        }
        if (i < num - 1) {
            writer.write('\n');
        }
    }

    writer.close();
    reader.close();
}

    private static List<Integer> pathExist(int k) {
        int curr = 0;
        List<Integer> q = new ArrayList<Integer>();
        q.add(0, k);
        while (curr < q.size()) {
            if (verts[q.get(curr) - 1][0] == 0) {
                curr++;
            } else {
                for (int j = 1; j <= verts[q.get(curr) - 1][0]; j++) {
                    if (!q.contains(verts[q.get(curr) - 1][j])) {
                        q.add(verts[q.get(curr) - 1][j]);
                    }
                }
                curr++;
            }
        }
        return q;
    }
}

