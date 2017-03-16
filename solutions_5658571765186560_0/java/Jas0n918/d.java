import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by jianghaiting on 15/4/8.
 */
public class Main {

    private static final int MAX_SIZE = 7;
    public static Omino[][] allOminos = new Omino[MAX_SIZE][];
    public static List<List<List<Omino>>> allOminosCateogry;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        initOminos();
        t = sc.nextInt();
        List<Integer> p = new ArrayList<>();
        for (int cid = 1; cid <= t; cid++) {
            int x = sc.nextInt();
            int r = sc.nextInt();
            int c = sc.nextInt();
            System.out.printf("Case #%d: %s\n", cid, solve(x, r, c) ? "GABRIEL" : "RICHARD");
        }
    }

    private static void initOminos() {
        allOminos[0] = new Omino[1];
        allOminos[0][0] = new Omino(new Square(0, 0));
        Set<Omino> ominoSet = new HashSet<>();
        allOminosCateogry = new ArrayList<>();
        allOminosCateogry.add(Arrays.asList(Arrays.asList(allOminos[0][0])));
        for (int i = 1; i < MAX_SIZE; i++) {
            ominoSet.clear();
            for (int j = 0; j < allOminos[i - 1].length; j++) {
                ominoSet.addAll(expandOmino(allOminos[i - 1][j]));
            }
            allOminos[i] = ominoSet.toArray(new Omino[ominoSet.size()]);
            allOminosCateogry.add(split(ominoSet));
        }
    }

    private static List<List<Omino>> split(Set<Omino> ominoSet) {
        List<List<Omino>> result = new ArrayList<>();
        for (Omino omino : ominoSet) {
            boolean isCategorised = false;
            for (List<Omino> category : result) {
                if (isSameCategory(omino, category.get(0))) {
                    category.add(omino);
                    isCategorised = true;
                    break;
                }
            }
            if (!isCategorised) {
                List<Omino> newCategory = new ArrayList<>();
                newCategory.add(omino);
                result.add(newCategory);
            }
        }
        return result;
    }

    private static boolean isSameCategory(Omino a, Omino b) {
        Omino o = new Omino(a);
        for (int m = 0; m < 2; m++) {
            for (int d = 0; d < 4; d++) {
                if (o.equals(b)) {
                    return true;
                }
                o.rotate();
            }
            o.mirror();
        }
        return false;
    }


    static int[][] dir = new int[][] { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };

    private static Set<Omino> expandOmino(Omino omino) {
        Set<Omino> result = new HashSet<>();
        Set<Square> squareSet = new HashSet<>(omino.squares);
        for (Square square : omino.squares) {
            for (int d = 0; d < 4; d++) {
                Square newSquare = new Square(square.x + dir[d][0], square.y + dir[d][1]);
                if (!squareSet.contains(newSquare)) {
                    result.add(new Omino(omino, newSquare));
                }
            }
        }
        return result;
    }

    private static boolean solve(int x, int r, int c) {
        if (x >= 7 || x > Math.max(r, c)) {
            return false;
        }
        if (x == 1) {
            return true;
        }
        if (x == 2) {
            return (r * c) % 2 == 0;
        }
        if (r * c % x != 0) {
            return false;
        }
        boolean[][] grids = new boolean[r][c];

        Omino[] ominos = allOminos[x - 1];
        List<List<Omino>> ominoCategory = allOminosCateogry.get(x - 1);
        for (List<Omino> category : ominoCategory) {
            boolean cover = false;
            for (Omino o : category) {
                if (haveSolution(r, c, grids, o, ominos)) {
                    cover = true;
                    break;
                }
            }
            if (!cover) {
                return false;
            }
        }
        return true;
    }

    private static boolean haveSolution(int r, int c, boolean[][] grids, Omino o, Omino[] ominos) {
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (canPutDown(r, c, grids, x, y, o, o.squares.get(0))) {
                    fillGrids(grids, x, y, o.squares.get(0), o, true);
                    int loc = 0;
                    while (loc < r * c && grids[loc / c][loc % c]) loc++;
                    if (loc == r * c) {
                        fillGrids(grids, x, y, o.squares.get(0), o, false);
                        return true;
                    }
                    for (Omino nextOmino : ominos) {
                        if (search(r, c, grids, loc / c, loc % c, nextOmino, ominos)) {
                            fillGrids(grids, x, y, o.squares.get(0), o, false);
                            return true;
                        }
                    }
                    fillGrids(grids, x, y, o.squares.get(0), o, false);
                }
            }
        }
        return false;
    }

    private static boolean search(int r, int c, boolean[][] grids, int x, int y, Omino omino, Omino[] ominos) {
        for (Square square : omino.squares) {
            if (canPutDown(r, c, grids, x, y, omino, square)) {
                fillGrids(grids, x, y, square, omino, true);
                int loc = x * c + y;
                while (loc < r * c && grids[loc / c][loc % c]) loc++;
                if (loc == r * c) {
                    fillGrids(grids, x, y, square, omino, false);
                    return true;
                }
                for (Omino nextOmino : ominos) {
                    if (search(r, c, grids, loc / c, loc % c, nextOmino, ominos)) {
                        fillGrids(grids, x, y, square, omino, false);
                        return true;
                    }
                }
                fillGrids(grids, x, y, square, omino, false);
            }
        }
        return false;
    }

    private static void fillGrids(boolean[][] grids, int x, int y, Square base, Omino omino, boolean value) {
        for (Square s : omino.squares) {
            grids[x + s.x - base.x][y + s.y - base.y] = value;
        }
    }

    private static boolean canPutDown(int r, int c, boolean[][] grids, int x, int y, Omino omino, Square base) {
        for (Square s : omino.squares) {
            int nx = x + s.x - base.x;
            int ny = y + s.y - base.y;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || grids[nx][ny]) {
                return false;
            }
        }
        return true;
    }


    static class Omino {
        List<Square> squares;

        public Omino(Square... squareArray) {
            init(Arrays.asList(squareArray));
        }

        private void init(List<Square> squareList) {
            squares = new ArrayList<>();
            for (Square square : squareList) {
                squares.add(new Square(square.x, square.y));
            }
            rebase();
        }

        public Omino(Omino o) {
            init(o.squares);
        }

        public void rebase() {
            if (squares == null || squares.size() == 0) {
                return;
            }
            Collections.sort(squares);
            int x = -squares.get(0).x;
            int y = -squares.get(0).y;
            for (Square square : squares) {
                square.x += x;
                square.y += y;
            }
        }

        public Omino(Omino omino, Square newSquare) {
            squares = new ArrayList<>();
            for (Square square : omino.squares) {
                squares.add(new Square(square.x, square.y));
            }
            squares.add(new Square(newSquare.x, newSquare.y));
            rebase();
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj instanceof Omino) {
                Omino that = (Omino) obj;
                return this.squares.equals(that.squares);
            }
            return false;
        }

        @Override
        public int hashCode() {
            return squares.hashCode();
        }

        public void rotate() {
            for (Square square : squares) {
                square.rotate();
            }
            rebase();
        }

        public void mirror() {
            for (Square square : squares) {
                square.mirror();
            }
            rebase();
        }

        @Override
        public String toString() {
            return "Omino{" +
                "squares=" + squares +
                '}';
        }
    }

    static class Square implements Comparable {
        int x, y;

        public Square(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj instanceof Square) {
                Square that = (Square) obj;
                return this.x == that.x && this.y == that.y;
            }
            return false;
        }


        @Override
        public int compareTo(Object o) {
            if (o instanceof Square) {
                Square that = (Square) o;
                if (this.x != that.x) {
                    return this.x - that.x;
                }
                return this.y - that.y;
            }
            return 0;
        }

        @Override
        public int hashCode() {
            return 31 * x + y;
        }

        public void rotate() {
            int tmp = x;
            x = y;
            y = -tmp;
        }

        public void mirror() {
            x = -x;
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ')';
        }
    }

}
