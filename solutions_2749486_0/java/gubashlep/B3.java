import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class B3 {
    private static String charsetName = "ISO-8859-1";
    private static Locale usLocale = new Locale("en", "US");

    public static void main(String[] args) throws FileNotFoundException {
        String name = "B-small-attempt0.in";
        // String name = "B-large.in";
        // String name = "B.in";

        File file = new File(name);
        Scanner in = new Scanner(file, "UTF-8");
        in.useLocale(usLocale);

        int count = in.nextInt();
        String line = in.nextLine();

        for (int caseNum = 1; caseNum <= count; caseNum++) {
            int targetX = in.nextInt();
            int targetY = in.nextInt();

            Board initial = new Board(0, 0, targetX, targetY, "", 1);

            Solver solver = new Solver(initial);
            String result = "";
            for (Board board : solver.solution()) {
                result += board.getDirection();
            }

            System.out.print("Case #" + caseNum + ": " + result);
            System.out.print("\n");
            if (!in.hasNextLine()) {
                break;
            }
        }

    }

    private static class Solver {
        private final Board initial;
        private boolean solvable = true;
        private List<Board> moves;

        public Solver(Board initial) {
            this.initial = initial;
            solve();
        }

        private void solve() {
            MinPQ<SearchNode> queue = new MinPQ<SearchNode>();

            queue.insert(new SearchNode(initial, null, 0));
            SearchNode solution = null;
            while (!queue.isEmpty()) {

                SearchNode board = queue.delMin();
                Board grandParent = null;
                // if (board.previous != null) {
                // grandParent = board.previous.board;
                // }
                if (!board.board.isGoal()) {
                    for (Board neighbour : board.board.neighbors()) {
                        // if (grandParent == null || grandParent != null
                        // && !grandParent.equals(neighbour)) {
                        queue.insert(new SearchNode(neighbour, board,
                                board.moves + 1));
                        // }
                    }
                } else {
                    solution = board;
                    break;
                }
            }
            if (solution != null) {
                moves = reconstructPath(solution);
            } else {
                solvable = false;
            }
        }

        private List<Board> reconstructPath(SearchNode board) {
            List<Board> steps = new ArrayList<Board>();
            SearchNode step = board;
            do {
                steps.add(step.board);
                step = step.previous;
            } while (step != null);
            Collections.reverse(steps);
            return steps;
        }

        public boolean isSolvable() {
            return solvable;
        }

        public int moves() {
            if (solvable) {
                return moves.size() - 1;
            } else {
                return -1;
            }
        }

        public Iterable<Board> solution() {
            if (solvable) {
                return moves;
            } else {
                return null;
            }
        }
    }

    private static class SearchNode implements Comparable<SearchNode> {
        private final Board board;
        private final SearchNode previous;
        private final int moves;

        public SearchNode(Board board, SearchNode previous, int moves) {
            this.board = board;
            this.previous = previous;
            this.moves = moves;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            int hashCode = 0;
            if ((board != null)) {
                hashCode = board.hashCode();
            }
            result = prime * result + hashCode;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            SearchNode other = (SearchNode) obj;
            if (board == null) {
                if (other.board != null) {
                    return false;
                }
            } else if (!board.equals(other.board)) {
                return false;
            }
            return true;
        }

        @Override
        public int compareTo(SearchNode o) {
            return (board.distance() + moves) - (o.board.distance() + o.moves);
        }

    }

    private static class Board {
        private final int x;
        private final int y;
        private final int targetX;
        private final int targetY;
        private final String direction;
        private final int step;

        public Board(int x, int y, int targetX, int targetY, String direction,
                int step) {
            this.x = x;
            this.y = y;
            this.targetX = targetX;
            this.targetY = targetY;
            this.direction = direction;
            this.step = step;
        }

        public String getDirection() {
            return direction;
        }

        public int distance() {
            return (int) Math.sqrt(Math.pow(targetX - x, 2)
                    + Math.pow(targetY - y, 2));
        }

        public Iterable<Board> neighbors() {
            List<Board> neighbors = new ArrayList<Board>();
            Board north = new Board(x, y + step, targetX, targetY, "N",
                    step + 1);
            Board south = new Board(x, y - step, targetX, targetY, "S",
                    step + 1);
            Board east = new Board(x + step, y, targetX, targetY, "E", step + 1);
            Board west = new Board(x - step, y, targetX, targetY, "W", step + 1);

            neighbors.add(north);
            neighbors.add(south);
            neighbors.add(east);
            neighbors.add(west);
            return neighbors;
        }

        public boolean isGoal() {
            return x == targetX && y == targetY;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + x;
            result = prime * result + y;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            Board other = (Board) obj;
            if (x != other.x) {
                return false;
            }
            if (y != other.y) {
                return false;
            }
            return true;
        }

        @Override
        public String toString() {
            return "Board [x=" + x + ", y=" + y + "]";
        }

    }

}
