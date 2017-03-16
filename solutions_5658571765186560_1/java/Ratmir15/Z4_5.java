package c2015_c.c2015_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;
import java.util.function.BooleanSupplier;

import static c2015_c.c2015_r1.Z4_5.PointFactory.getPoint;
import static c2015_c.c2015_r1.Z4_5.PointFactory.init;

public class Z4_5 {

    private static int[][] figures_3 = {{1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 1, 0, 0}, {1, 1, 0, 1, 0, 0, 0, 0, 0}};

    static class PointFactory {
        private static Point[][] points = new Point[20][20];

        public static void init() {
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                    points[i][j] = new Point(i, j);
                }
            }
        }

        public static Point getPoint(int x, int y) {
            return points[x][y];
        }
    }

    public static void main(String[] args) throws Exception {

        init();
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z4_1.txt";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-generated.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-small-attempt2.in";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
//        for (int i=1;i<=6;i++) {
//            Set<Figure> figures = generateFigures(i);
//            for (Figure figure : figures) {
//                System.out.println(figure);
//                System.out.println("-----");
//            }
//        }
        for (int ti = 1; ti <= tn; ti++) {
            int x = scanner.nextInt();
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            if (r < c) {
                int rc = r;
                r = c;
                c = rc;
            }
            // r >= c always
            if (ti == 22) {
                System.out.println("test");
            }
            boolean flag = false;
            if ((x>6) || (r * c % x != 0)) {
                flag = true;
            } else {
                if (x < r && x < c) {
                    flag = false;
                } else {
                    if (x % 2 == 0) {
                        if (x==4 && c<3) {
                            flag = true;
                        }
                        if (x==6 && c<4) {
                            flag = true;
                        }
                    } else {
                        int t1 = (x + 1) / 2;
                        if (t1 > c) {
                            flag = true;
                        }
                    }
                    if (!flag) {
                        //String s1 = "Case #" + ti + ": " + x + " " + r + " " + c;
                        //System.out.println(s1);
                        if (x <= r) {
                            switch (x) {
                                case 1: {
                                    flag = false;
                                    break;
                                }
                                case 2: {
                                    flag = r * c % 2 != 0;
                                    break;
                                }
                                default: {
                                    Set<Figure> figureSet = generateFigures(x);
                                    List<Figure> figures = new ArrayList<Figure>();
                                    figures.addAll(figureSet);
                                    //System.out.println(figures);
                                    int[][] board = new int[c][r];
                                    boolean log = false;
                                    next_figure:
                                    for (int figure_i = 0; figure_i < figures.size(); figure_i++) {
                                        Figure figure = figures.get(figure_i);
                                        //System.out.println("Trying to find solution for figure " + figure_i);
                                        next_rotation:
                                        for (int rot = 0; rot < 4; rot++) {
                                            //System.out.println("Rotation  " + rot);
                                            if (rot>0) {
                                                figure = figure.rotate();
                                            }
                                            if (log) {
                                                System.out.println(figure);
                                            }
                                            if (ti == 2386) {
                                                //System.out.println("test");
                                            }
//                                            if (x == 5 && r==10 && c==3) {
//                                                System.out.println("test");
//                                                log = true;
//                                            }
                                            for (int i = 0; i < c; i++) {
                                                next_position:
                                                for (int j = 0; j < r; j++) {
                                                    board = new int[c][r];
                                                    boolean ok = tryToPlace(board, figure, i, j, 1);
                                                    if (log) {
                                                        System.out.println("tried "+i+" "+j);
                                                    }
                                                    if (i == 0 && j == 0 && !ok) {
                                                        //this rotation of figure is not inside but we still need to try other rotations
                                                        continue next_position;
                                                    }
                                                    if (ok) {
                                                        continue next_figure;
                                                    } else {
                                                        continue next_position;
                                                    }
                                                }
                                            }
                                        }
                                        System.out.println("WTF " + x + " " + r + " " + c);
                                        System.out.println(figure);
                                        flag = true;
                                        break next_figure;
                                    }
                                }
                            }
                        } else {
                            flag = true;
                        }
                    }
                }
            }
            String s;
            if (flag) {
                s = "RICHARD";
            } else {
                s = "GABRIEL";
            }
            s = "Case #" + ti + ": " + s;
            //System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

    private static void printBoard(int r, int c, int[][] board) {
        for (int di = 0; di < c; di++) {
            for (int dj = 0; dj < r; dj++) {
                System.out.print(board[di][dj]);
            }
            System.out.println();
        }
        System.out.println();
    }

    private static Point findTopLeft(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 0) {
                    return getPoint(i, j);
                }
            }
        }
        return null;
    }

    private static boolean tryToPlace(int[][] board, Figure figure, int i, int j, int figureNumber) {
        boolean flag = true;
        for (Point point : figure.points) {
            if (onBoard(board, point.x + i, point.y + j)) {
                if (board[point.x + i][point.y + j] != 0) {
                    flag = false;
                }
            } else {
                flag = false;
            }
        }
        if (flag) {
            if (board[board.length - 1][0] == 0) {
                if (board[board.length - 1][1] == 1) {
                    if (board[board.length - 2][1] == 1) {
                        if (board[board.length - 2][0] == 1) {
                            flag = false;
                        }
                    }
                }
            }
        }
        if (flag) {
            for (Point point : figure.points) {
                board[point.x + i][point.y + j] = figureNumber;
            }
            boolean emptySpace = checkAndFillEmptySpace(board, figure.tiles);
//            if (!emptySpace) {
//                for (Point point : figure.points) {
//                    board[point.x + i][point.y + j] = 0;
//                }
                return emptySpace;
//            }
        }
        return flag;
    }

    private static boolean checkEmptySpace(int[][] board, int tiles) {
        Point topLeft = findTopLeft(board);
        if (topLeft != null) {
            Queue<Point> queue = new LinkedList<Point>();
            queue.add(topLeft);
            Set<Point> visited = new HashSet<Point>();
            while (queue.size() > 0) {
                Point point = queue.poll();
                addToQueue(board, queue, visited, point.x - 1, point.y);
                addToQueue(board, queue, visited, point.x + 1, point.y);
                addToQueue(board, queue, visited, point.x, point.y - 1);
                addToQueue(board, queue, visited, point.x, point.y + 1);
                visited.add(point);
            }
            return (visited.size() % tiles) == 0;
        } else {
            return true;
        }
    }

    private static boolean checkAndFillEmptySpace(int[][] board, int tiles) {
        Point topLeft = findTopLeft(board);
        int figCnt = 2;
        while (topLeft != null) {
            Queue<Point> queue = new LinkedList<Point>();
            queue.add(topLeft);
            Set<Point> visited = new HashSet<Point>();
            while (queue.size() > 0) {
                Point point = queue.poll();
                addToQueue(board, queue, visited, point.x - 1, point.y);
                addToQueue(board, queue, visited, point.x + 1, point.y);
                addToQueue(board, queue, visited, point.x, point.y - 1);
                addToQueue(board, queue, visited, point.x, point.y + 1);
                visited.add(point);
            }
            if ((visited.size() % tiles) != 0) {
                return false;
            }
            for (Point point : visited) {
                board[point.x][point.y] = figCnt;
            }
            figCnt++;
            //return (visited.size() % tiles) == 0;
            topLeft = findTopLeft(board);
        }
        return true;
    }


    private static void addToQueue(int[][] board, Queue<Point> queue, Set<Point> visited, int nx, int ny) {
        if (onBoard(board, nx, ny)) {
            if (board[nx][ny] == 0) {
                Point o = getPoint(nx, ny);
                if (!visited.contains(o)) {
                    queue.add(o);
                }
            }
        }
    }

    private static boolean onBoard(int[][] board, int x, int y) {
        return x >= 0 && y >= 0 && x < board.length && y < board[0].length;
    }

    private static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            if (y != point.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

    private static class Figure {
        int tiles;
        Set<Point> points;
        List<Point> pointList;

        public Figure(int tiles, Set<Point> points) {
            this.tiles = tiles;
            this.points = points;
            pointList = new ArrayList<Point>(points);
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < tiles; i++) {
                for (int j = 0; j < tiles; j++) {
                    if (points.contains(getPoint(i, j))) {
                        sb.append("X");
                    } else {
                        sb.append(" ");
                    }
                }
                sb.append("\n");
            }
            return sb.toString();
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Figure figure = (Figure) o;

            if (tiles != figure.tiles) return false;
            if (points != null ? !points.equals(figure.points) : figure.points != null) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = tiles;
            result = 31 * result + (points != null ? points.hashCode() : 0);
            return result;
        }

        public Figure rotate() {
            HashSet<Point> new_figure = new HashSet<Point>();
            for (int i=0; i<tiles;i++) {
                for (int j=0;j<tiles;j++) {
                    if (points.contains(getPoint(i,j))) {
                        new_figure.add(getPoint(tiles - j - 1, i));
                    }
                }
            }
            int min_x = tiles;
            int min_y = tiles;
            for (Point point : new_figure) {
                if (point.x<min_x) {
                    min_x = point.x;
                }
                if (point.y<min_y) {
                    min_y = point.y;
                }
            }
            if (min_x>0 || min_y>0) {
                Set<Point> shifted = new HashSet<Point>();
                for (Point point : new_figure) {
                    shifted.add(getPoint(point.x-min_x,point.y-min_y));
                }
                return new Figure(tiles, shifted);
            }
            return new Figure(tiles, new_figure);
        }

    }

    private static Set<Figure> generate(Figure prototype) {
        Set<Figure> next = new HashSet<Figure>();
        for (Point point : prototype.points) {
            //go left
            int dx;
            int dy;
            dx = -1;
            dy = 0;
            if (point.x == 0) {
                shiftAndAdd(prototype, next, 0, point.y, dx, dy);
            } else {
                addWithPoint(prototype, next, point, dx, dy);
            }
            dx = 0;
            dy = -1;
            if (point.y == 0) {
                shiftAndAdd(prototype, next, point.x, 0, dx, dy);
            } else {
                addWithPoint(prototype, next, point, dx, dy);
            }
            dx = 1;
            dy = 0;
            addWithPoint(prototype, next, point, dx, dy);
            dx = 0;
            dy = 1;
            addWithPoint(prototype, next, point, dx, dy);
        }
        return next;
    }

    private static void addWithPoint(Figure prototype, Set<Figure> next, Point point, int dx, int dy) {
        if (!prototype.points.contains(getPoint(point.x + dx, point.y + dy))) {
            HashSet<Point> ps = new HashSet<Point>();
            ps.addAll(prototype.points);
            ps.add(getPoint(point.x + dx, point.y + dy));
            next.add(new Figure(prototype.tiles + 1, ps));
        }
    }

    private static void shiftAndAdd(Figure prototype, Set<Figure> next, int nx, int ny, int dx, int dy) {
        HashSet<Point> ps = new HashSet<Point>();
        for (Point p : prototype.points) {
            ps.add(getPoint(p.x - dx, p.y - dy));
        }
        ps.add(getPoint(nx, ny));
        next.add(new Figure(prototype.tiles + 1, ps));
    }

    private static Set<Figure> generateFigures(int tiles) {
        Set<Point> ps = new HashSet<Point>();
        ps.add(getPoint(0, 0));
        Figure f = new Figure(1, ps);
        Set<Figure> res = new HashSet<Figure>();
        res.add(f);
        int t = 1;
        while (t < tiles) {
            t++;
            Set<Figure> next = new HashSet<Figure>();
            for (Figure figure : res) {
                next.addAll(generate(figure));
            }
            res = next;
        }
        return res;
    }

}
