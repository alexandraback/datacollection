import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C2015 {


    public static void main(String[] args) throws IOException {
        C2015 trans = new C2015();
        trans.doMe();
    }

    private static final String NAME = "C-small-attempt0";

    public void doMe() throws IOException {
        File file = new File("./inputs/"+NAME + ".in");
        BufferedWriter out = new BufferedWriter(new FileWriter("./output/"+NAME+".out"));
        try {
            //use buffering, reading one line at a time
            //FileReader always assumes default encoding is OK!
            BufferedReader input = new BufferedReader(new FileReader(file));
            try {
                String line = input.readLine();
                int count = Integer.parseInt(line);

                for (int i=0;i<count;i++) {
                    line = input.readLine();
                    String line2 = input.readLine();
                    String str = this.proccessLine(line.trim(), line2.trim());
                    out.write("Case #"+(i+1)+": "+str);
                    if (i<count-1)
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

    int[] toIntArray(String str) {
        StringTokenizer tokens = new StringTokenizer(str);
        int[] a= new int[tokens.countTokens()];
        int i = 0;
        while(tokens.hasMoreElements()) {
            a[i++] = Integer.parseInt(tokens.nextToken());
        }
        return a;
    }

    int currentScore = Integer.MAX_VALUE;
    String proccessLine(String line, String line2) {
        currentScore = Integer.MAX_VALUE;
        int[]i1= toIntArray(line);
        int[]i2= toIntArray(line2);
        int C = i1[0];
        int D = i1[1];
        int V = i1[2];

        int denominations[] = toIntArray(line2);

        boolean visited[] = new boolean[V + 1];
        visited[0] = true;

        for (int v:denominations) {
            boolean visitedNew[] = new boolean[V + 1];
            for (int j = 0; j <= V ; j++) {
                if (visited[j]) {
                    visitedNew[j] = true;
                    for (int i = 1; i <= C; i++) {
                        int h = j + (i * v);
                        if (h<=V) visitedNew[h] = true;
                    }
                }
            }
            visited = visitedNew;
        }
        boolean finished = true;
        for (boolean b:visited) {
            if (!b) {
                finished = false;
                break;
            }
        }
        if (finished) return Integer.toString(0);

        boolean[] hasDen = new boolean[ V + 1];
        for (int v:denominations) {
            hasDen[v] = true;
        }
        int next = 1;
        while(next <=V && hasDen[next]) {
            next++;
        }
        minAdd(visited, hasDen, next, C, V, 0);
        return Integer.toString(currentScore);
    }


    public void minAdd(boolean visited[], boolean[] hasDen, int v, int C, int V, int score) {
        if (v > V || score > currentScore) return;
        boolean visitedNew[] = new boolean[V + 1];
        for (int j = 0; j <= V ; j++) {
            if (visited[j]) {
                visitedNew[j] = true;
                for (int i = 1; i <= C; i++) {
                    int h = j + i * v;
                    if (h<=V) visitedNew[h] = true;
                }
            }
        }
        boolean finished = true;
        for (boolean b:visitedNew) {
            if (!b) {
                Arrays.toString(visitedNew);
                finished = false;
                break;
            }
        }
        if (finished) {
            currentScore = Math.min(currentScore, score + 1);
            return;
        }
        int next = v + 1;
        while(next <=V && hasDen[next]) {
            next++;
        }
        if (next<=V) {
            minAdd(visitedNew, hasDen, next, C, V, score + 1);
            minAdd(visited, hasDen, next, C, V, score);
        }
    }

}
