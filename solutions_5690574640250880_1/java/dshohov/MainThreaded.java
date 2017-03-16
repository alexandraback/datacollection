package dmitry.shohov;

import java.io.*;
import java.text.DecimalFormat;
import java.util.*;
import java.util.concurrent.*;

public class MainThreaded {
    private static List<List<String>> input = new ArrayList<>();
    private static PrintWriter writer;
    private SortedMap<Integer, String> outputLines = Collections.synchronizedSortedMap(new TreeMap<Integer, String>());
    private String lsep = "\r\n";

    private ThreadPoolExecutor executor = new ThreadPoolExecutor(8, 8, 5, TimeUnit.DAYS, new LinkedBlockingQueue<Runnable>(), new ThreadFactory() {
        @Override
        public Thread newThread(Runnable r) {
            Thread thread = new Thread(r);
            thread.setDaemon(true);
            return thread;
        }
    });

    public MainThreaded() {

    }

    public void run() throws Exception {
        assert input.size() > 0;
        int numberOfCases = Integer.parseInt(input.get(0).get(0));
        List<Future<?>> tasks = new ArrayList<>(numberOfCases);
        for (int i = 0; i < numberOfCases; i++) {
            final int fi = i;
            tasks.add(executor.submit(new Runnable() {
                @Override
                public void run() {
                    try {
                        runCase(fi + 1, input.get(1 + fi));
                    } catch (Throwable t) {
                        t.printStackTrace();
                    }
                }
            }));
        }
        for (Future<?> task : tasks) {
            task.get();
        }
        for (String outputLine : outputLines.values()) {
            writer.println(outputLine);
        }
    }

    public void runCase(int caseNumber, List<String> caseData) {
        int rows = Integer.parseInt(caseData.get(0));
        int cols = Integer.parseInt(caseData.get(1));
        int mines = Integer.parseInt(caseData.get(2));

        //logic tries to place empty elements
        //unfortunately it doesn't have optimal strategy where to place next element with zero weight
        //so it tries several :)
        if (!runCase(caseNumber, rows, cols, mines, false, new ColsMoreThanRowsComparator())) {
            if (!runCase(caseNumber, rows, cols, mines, true, new ColsMoreThanRowsComparator())) {
                if (!runCase(caseNumber, rows, cols, mines, true, new InvertingComparator<>(new ColsMoreThanRowsComparator()))) {
                    if (!runCase(caseNumber, rows, cols, mines, false, new InvertingComparator<>(new ColsMoreThanRowsComparator()))) {
                        if (!runCase(caseNumber, rows, cols, mines, true, new ClosestToClickComparator())) {
                            if (!runCase(caseNumber, rows, cols, mines, false, new ClosestToClickComparator())) {
                                if (!runCase(caseNumber, rows, cols, mines, true, new InvertingComparator<>(new ClosestToClickComparator()))) {
                                    if (!runCase(caseNumber, rows, cols, mines, false, new InvertingComparator<>(new ClosestToClickComparator()))) {
                                        //looks like it's really impossible
                                        output(caseNumber, null);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    public boolean runCase(int caseNumber, int rows, int cols, int mines, boolean lowestFirst, Comparator<Point> comparator) {

        //10 - mine
        //11 - click
        int[][] field = new int[rows][cols];

        if (mines == 0) {
            //no mines - no problems
            field[0][0] = 11;
            output(caseNumber, field);
            return true;
        } else if (mines == rows * cols) {
            //always fail
            output(caseNumber, null);
            return true;
        } else {
            //fill with mines
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    field[i][j] = 10;
                }
            }

            if (mines == rows * cols - 1) {
                //we can always win if there is mines = rows*cols - 1
                field[0][0] = 11;
                output(caseNumber, field);
                return true;
            } else {
                //now interesting part
                //this map will hold calculated values, this will reduce array scanning
                //noinspection unchecked
                SortedSet<Point>[] points = new SortedSet[8];
                for (int i = 0; i < 8; i++) {
                    points[i] = new TreeSet<>(comparator);
                }
                //always start from corner
                calculatePoint(0, 0, field, points);

                int notMines = rows * cols - mines;
                --notMines;
                while (notMines > 0) {
                    //now we have to place notMines
                    Point point = null;
                    int pointValue = 0;
                    if (notMines <= 8 && !points[notMines - 1].isEmpty()) {
                        point = points[notMines - 1].iterator().next();
                        pointValue = notMines;
                    } else {
                        if (!lowestFirst) {
                            for (int i = notMines > 8 ? 7 : notMines - 1; i >= 0; i--) {
                                //find the point with biggest value
                                if (!points[i].isEmpty()) {
                                    point = points[i].iterator().next();
                                    pointValue = i + 1;
                                    break;
                                }
                            }
                        } else {
                            for (int i = 0; i <= (notMines > 8 ? 7 : notMines - 1); i++) {
                                //find the point with lowest value
                                if (!points[i].isEmpty()) {
                                    point = points[i].iterator().next();
                                    pointValue = i + 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (point == null) {
                        //impossible
                        //well... I have other strategies to try
                        return false;
                    } else {
                        setZero(point.row, point.col, field, points);
                        notMines -= pointValue;
                    }
                }

                field[0][0] = 11;
                output(caseNumber, field);
                return true;
            }
        }
    }

    private void setZero(int row, int col, int[][] field, Set<Point>[] points) {
        //remove surrounding mines
        for (int i = (row - 1 >= 0 ? row - 1 : row), l = (row + 1 < field.length ? row + 1 : row) + 1; i < l; i++) {
            for (int j = (col - 1 >= 0 ? col - 1 : col), m = (col + 1 < field[0].length ? col + 1 : col) + 1; j < m; j++) {
                int value = field[i][j];
                if (value == 10) {
                    removeMineAt(i, j, field, points);
                }
            }
        }
        assert field[row][col] == 0;
    }

    private void removeMineAt(int row, int col, int[][] field, Set<Point>[] points) {
        for (int i = (row - 1 >= 0 ? row - 1 : row), l = (row + 1 < field.length ? row + 1 : row) + 1; i < l; i++) {
            for (int j = (col - 1 >= 0 ? col - 1 : col), m = (col + 1 < field[0].length ? col + 1 : col) + 1; j < m; j++) {
                int value = field[i][j];
                assert value > 0;
                if (value != 10) {
                    Set<Point> valuePoints = points[value - 1];
                    Point point = new Point(i, j);
                    boolean removed = valuePoints.remove(point);
                    assert removed;
                    --value;
                    field[i][j] = value;
                    if (value > 0) {
                        valuePoints = points[value - 1];
                        valuePoints.add(point);
                    }
                }
            }
        }
        calculatePoint(row, col, field, points);
    }

    private void calculatePoint(int row, int col, int[][] field, Set<Point>[] points) {
        int value = 0;
        for (int i = (row - 1 >= 0 ? row - 1 : row), l = (row + 1 < field.length ? row + 1 : row) + 1; i < l; i++) {
            for (int j = (col - 1 >= 0 ? col - 1 : col), m = (col + 1 < field[0].length ? col + 1 : col) + 1; j < m; j++) {
                if (!(i == row && j == col) && field[i][j] == 10) {
                    //mine
                    ++value;
                }
            }
        }
        field[row][col] = value;
        if (value > 0) {
            Set<Point> valuePoints = points[value - 1];
            Point point = new Point(row, col);
            valuePoints.add(point);
        }
    }

    private void output(int caseNumber, int[][] field) {
        StringBuilder out = new StringBuilder();
        out.append("Case #").append(caseNumber).append(":");
        if (field == null) {
            out.append(lsep).append("Impossible");
        } else {
            for (int[] row : field) {
                out.append(lsep);
                for (int col : row) {
                    if (col == 10) {
                        out.append('*');
                    } else if (col == 11) {
                        out.append('c');
                    } else {
                        out.append('.');
                    }
                }
            }
        }
        outputLines.put(caseNumber, out.toString());
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        TimeZone.setDefault(TimeZone.getTimeZone("GMT"));

        if (args.length < 2) {
            System.err.println("Requires two arguments - input and output files");
            return;
        }
        File inputFile = new File(args[0]);
        if (!inputFile.exists()) {
            System.err.println("Input file (first argument) does not exist");
            return;
        }

        BufferedReader inputReader = new BufferedReader(new FileReader(inputFile));
        String line;
        while ((line = inputReader.readLine()) != null) {
            List<String> lineInput = new ArrayList<>();
            StringTokenizer tokenizer = new StringTokenizer(line, " ");
            while (tokenizer.hasMoreTokens()) {
                lineInput.add(tokenizer.nextToken());
            }
            input.add(lineInput);
        }
        inputReader.close();

        writer = new PrintWriter(new BufferedWriter(new FileWriter(args[1])));

        MainThreaded main = new MainThreaded();
        main.run();

        writer.flush();
        writer.close();

        inputReader = new BufferedReader(new FileReader(args[1]));
        int impossibleCount = 0;
        while ((line = inputReader.readLine()) != null) {
            if (line.equals("Impossible")) {
                ++impossibleCount;
            }
            System.out.println(line);
        }
        inputReader.close();
        System.out.println("Impossible count: " + impossibleCount);
    }

    public static class Point {
        int row;
        int col;

        public Point(int row, int col) {
            this.row = row;
            this.col = col;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (col != point.col) return false;
            if (row != point.row) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = row;
            result = 31 * result + col;
            return result;
        }
    }

    public static class ColsMoreThanRowsComparator implements Comparator<Point> {
        @Override
        public int compare(Point p1, Point p2) {
            if (p1.row > p2.row) {
                return 1;
            } else if (p1.row < p2.row) {
                return -1;
            } else {
                if (p1.col > p2.col) {
                    return 1;
                } else if (p1.col < p2.col) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }

    public static class ClosestToClickComparator implements Comparator<Point> {
        ColsMoreThanRowsComparator colsMoreThanRowsComparator = new ColsMoreThanRowsComparator();
        @Override
        public int compare(Point p1, Point p2) {
            int maxp1 = Math.max(p1.row, p1.col);
            int maxp2 = Math.max(p2.row, p2.col);
            if (maxp1 == maxp2) {
                return colsMoreThanRowsComparator.compare(p1, p2);
            } else if (maxp1 > maxp2) {
                return 1;
            } else {
                return -1;
            }
        }
    }

    public static class InvertingComparator<T> implements Comparator<T> {
        private Comparator<T> comparator;

        public InvertingComparator(Comparator<T> comparator) {
            this.comparator = comparator;
        }

        @Override
        public int compare(T o1, T o2) {
            return comparator.compare(o2, o1);
        }
    }
}
