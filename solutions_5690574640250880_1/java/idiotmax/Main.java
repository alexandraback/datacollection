import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int roundCount = 0;

        BufferedReader br = null;
        BufferedWriter bw = null;
        try {
            br = new BufferedReader(new FileReader("C-large.in"));
            bw = new BufferedWriter(new FileWriter("C-large.out"));
            String line = br.readLine();

            roundCount = Integer.parseInt(line);
            for (int roundIndex = 0; roundIndex < roundCount; roundIndex++) {
                Round round = parseRound(roundIndex + 1, br.readLine());
                if (round == null) {
                    break;
                }
                doCompute(round);

                bw.write(String.format("Case #%d:\n%s", roundIndex + 1, round));
            }

        } catch (IOException e) {
        } catch (NumberFormatException e) {
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                }
            }
            if (bw != null) {
                try {
                    bw.close();
                } catch (IOException e) {
                }
            }
        }

    }

    private static Round parseRound(int index, String args) {
        int mineCount = 0;

        String[] a = args.split(" ");
        char[][] board = new char[Integer.parseInt(a[0])][Integer.parseInt(a[1])];
        mineCount = Integer.parseInt(a[2]);

        return new Round(index, board, mineCount);
    }

    private static final class Round {
        final int index;

        int mine;

        int mineCount;

        final int width;

        final int height;

        final char[][] board;

        Round(int index, char[][] board, int mineCount) {
            this.index = index;
            this.mine = mineCount;
            this.mineCount = mineCount;
            this.board = board;
            height = board.length;
            width = board[0].length;

            for (char[] row : board) {
                Arrays.fill(row, '.');
            }
            board[0][0] = 'c';
        }

        @Override
        public String toString() {
            if (mineCount < 0) {
                return "Impossible\n";
            }

            if (width == 1) {
                for (int i = height - 1; i > 0 && mineCount > 0; i--, mineCount--) {
                    board[i][0] = '*';
                }
            } else if (height == 1) {
                for (int i = width - 1; i > 0 && mineCount > 0; i--, mineCount--) {
                    board[0][i] = '*';
                }
            } else {
                // phase1
                for (int i = height - 1; i > 1 && mineCount > 0; i--) {
                    for (int j = width - 1; j > 1 && mineCount > 0; j--) {
                        if (i == 2 && j == 2) {
                            continue;
                        }
                        board[i][j] = '*';
                        mineCount--;
                    }
                }

                // phase2
                for (int i = height - 1; i > 2 && mineCount > 1; i--) {
                    board[i][0] = '*';
                    board[i][1] = '*';
                    mineCount -= 2;
                }

                // phase3
                for (int j = width - 1; j > 2 && mineCount > 1; j--) {
                    board[0][j] = '*';
                    board[1][j] = '*';
                    mineCount -= 2;
                }

                if ((width == 2 || height == 2)) {
                    if (height >= 3 && mineCount > 1) {
                        board[2][0] = '*';
                        board[2][1] = '*';
                        mineCount -= 2;
                    }

                    if (width >= 3 && mineCount > 1) {
                        board[0][2] = '*';
                        board[1][2] = '*';
                        mineCount -= 2;
                    }

                    if ((width * height) - mine == 1) {

                        for (int i = 1; i >= 0 && mineCount > 0; i--) {
                            for (int j = 1; j >= 0 && mineCount > 0; j--) {
                                if (i == 0 && j == 0) {
                                    continue;
                                }
                                board[i][j] = '*';
                                mineCount--;
                            }
                        }

                    } else if (mineCount == 4 || mineCount == 1 || mineCount == 2) {
                        return "Impossible\n";
                    } else {
                    }
                } else {
                    switch (mineCount) {
                        case 2:
                        case 4:
                        case 6:
                        case 7:
                            return "Impossible\n";
                        case 8:
                            board[0][1] = '*';
                            board[1][0] = '*';
                            board[1][1] = '*';
                            mineCount -= 3;
                        case 5:
                            board[0][2] = '*';
                            board[1][2] = '*';
                            mineCount -= 2;
                        case 3:
                            board[2][0] = '*';
                            board[2][1] = '*';
                            mineCount -= 2;
                        case 1:
                            board[2][2] = '*';
                            mineCount -= 1;
                        case 0:
                            break;
                        default:
                            break;
                    }
                }

                if (mineCount != 0) {
                    println("ERR:%d(%d,%d,%d)%d", index, height, width, mine, mineCount);
                    println(exportBoard(board));
                }
            }

            return exportBoard(board);
        }
    }

    private static String exportBoard(char[][] board) {
        StringBuilder sb = new StringBuilder();
        for (char[] row : board) {
            for (char cell : row) {
                sb.append(cell);
            }
            sb.append('\n');
        }
        return sb.toString();
    }

    private static void doCompute(Round round) {
        int width = round.width;
        int height = round.height;
        if (width < 2 && height < 2) {
            round.mineCount = round.mineCount == 0 ? 0 : -1;
            return;
        } else if (round.mineCount == width * height) {
            round.mineCount = -1;
        } else if (width == 1 || height == 1) {
        } else {
            int space = width * height - round.mineCount;
            if (space == 2 || space == 3) {
                round.mineCount = -1;
                return;
            }
            if (space == 1) {
                return;
            }
        }

        return;
    }

    private static void println(String format, Object... args) {
        System.out.println(String.format(format, args));
    }

}
