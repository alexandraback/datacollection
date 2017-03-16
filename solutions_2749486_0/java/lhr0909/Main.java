package gcj;

import java.io.*;
import java.util.*;

public class Main {

    public static HashMap<Point, Step> steps = new HashMap<Point, Step>();
    public static HashSet<Point> visited = new HashSet<Point>();

    public static void bfsStep(ArrayList<Step> q) {
        while(!q.isEmpty()) {
            System.out.println(q.size());
            Step current = q.remove(0); //pop
            //add this to the dict first
            Point p = current.p;
            if (!steps.containsKey(p)) {
                steps.put(p, current);
            }
            if (!visited.contains(p)) {
                visited.add(p);
            }
            //put more steps into the queue
            int ns = current.nextStep;
            int[] dx = {-ns, ns, 0, 0};
            int[] dy = {0, 0, -ns, ns};
            for (int i = 0; i < 4; i++) {
                String dStr = "";
                switch (i) {
                    case 0:
                        dStr = "W";
                        break;
                    case 1:
                        dStr = "E";
                        break;
                    case 2:
                        dStr = "S";
                        break;
                    case 3:
                        dStr = "N";
                        break;
                }

                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                Point np = new Point(nx, ny);
                if ((nx >= -100) && (nx <= 100) && (ny >= -100) && (ny <= 100)
                        && (!steps.containsKey(np)) && (!visited.contains(np))) {
                    //push into queue
                    visited.add(np);
                    ArrayList t = new ArrayList<String>(current.trail);
                    t.add(dStr);
                    q.add(new Step(np, ns + 1, t));
                }
            }
        }
    }

    public static void bfsInit() {
        // BFS
        ArrayList<Step> q = new ArrayList<Step>();
        q.add(new Step(new Point(0, 0), 1, new ArrayList<String>()));
        bfsStep(q);
    }

    public static String solve(int X, int Y) {
        String result = "";
        Point p = new Point(X, Y);
        if (steps.containsKey(p)) {
            ArrayList<String> t = steps.get(p).trail;
            for (int i = 0; i < t.size(); i++) {
                result += t.get(i);
            }
        }
        System.out.println(result);
        return result;
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Building BFS...");
        bfsInit();
        System.out.println("BFS Complete. Press any key to continue");

//        String filename = "B-tiny";
        String filename = "B-small-attempt0";
//        String filename = "B-large";
        String pwd = System.getProperty("user.dir");
        System.out.println(pwd);
        Scanner scanner = new Scanner(new FileReader(pwd + "\\" + filename + ".in"));
        PrintWriter printer = new PrintWriter(new FileWriter(pwd + "\\" + filename + ".out"));

        int caseCount = scanner.nextInt();
        for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
            printer.println("Case #" + caseNumber + ": " + solve(scanner.nextInt(), scanner.nextInt()));
        }

        printer.flush();
        printer.close();
        scanner.close();
    }

    private static class Step {
        public Point p;
        public int nextStep;
        public ArrayList<String> trail;

        public Step(Point p, int ns, ArrayList<String> t) {
            this.p = p;
            this.nextStep = ns;
            this.trail = new ArrayList<String>(t); //copy
        }
    }

    private static class Point {
        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) return false;
            if (obj == this) return true;
            if (obj.getClass() != this.getClass()) {
                return false;
            }
            if ((this.x == ((Point) obj).x) && (this.y == ((Point) obj).y)) {
                return true;
            } else {
                return false;
            }
        }

        @Override
        public int hashCode() {
            //needs to be changed to take in large set i think
            return this.x * 1000 + this.y;
        }
    }
}

