import java.io.*;
import java.util.Vector;

public class CodeJam1C2 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("B-small.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("B-small.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                String[] values = line.split(" ");
                int x = Integer.parseInt(values[0]);
                int y = Integer.parseInt(values[1]);

                String result = solve2(x, y);

                pw.println("Case #" + (i + 1) + ": " + result);
            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static class Node {
        public int x;
        public int y;
        public int step;
        public int previous;
        public char direction;

        private Node(int x, int y, int step, int previous, char direction) {
            this.x = x;
            this.y = y;
            this.step = step;
            this.previous = previous;
            this.direction = direction;
        }
    }

    private static String solve2(int x, int y) {
        String h = (x < 0) ? "EW" : "WE";
        String v = (y < 0) ? "NS" : "SN";

        String result = "";
        for (int i = 0; i < Math.abs(x); i++) {
            result += h;
        }
        for (int i = 0; i < Math.abs(y); i++) {
            result += v;
        }
        if (result.length() > 500) {
            System.out.println("***");
        }
        return result;
    }


    private static String solve(int x, int y) {
        Vector<Node> queue = new Vector<Node>();
        queue.add(new Node(0, 0, 0, -1, '*'));
        int current = 0;
        while (true) {
            int xx = queue.elementAt(current).x;
            int yy = queue.elementAt(current).y;
            int step = queue.elementAt(current).step;
            System.out.println(xx + " " + yy + " " + step);
            if (xx == x && yy == y) {
                break;
            }
            queue.add(new Node(xx + step + 1, yy, step + 1, current, 'E'));
            queue.add(new Node(xx - step - 1, yy, step + 1, current, 'W'));
            queue.add(new Node(xx, yy + step + 1, step + 1, current, 'N'));
            queue.add(new Node(xx, yy - step - 1, step + 1, current, 'S'));
            current++;
        }
        System.out.println("DONE");
        int position = current;
        String result = "";
        while (position > 0) {
            result = queue.elementAt(position).direction + result;
            position = queue.elementAt(position).previous;
        }
        return result;
    }
}
