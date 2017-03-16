import java.util.Arrays;  //Arrays.toString(int[])
public class TicTacToeT {
    public int[][] board;
    public int[] score;
    public TicTacToeT(int[][] vec) {
        board = vec;        
        score = new int[10*2];
    }
    public String Result() {
        String res;
        int rescode = ScoreCal();
        if (rescode == 1)
            res = "X won";
        else if (rescode == -1)
            res = "O won";
        else if (rescode == 0)
            res = "Draw";
        else if (rescode == 100)
            res = "Game has not completed";
        else 
            res = "";
        return res;
    }
    public int ScoreCal() { //1: X win; -1: O win; 0: draw; 100: not completed
        boolean hasEmpty = false;
        int idxscr = 0;
        for (int row = 0; row < 4; row++) {
            score[idxscr] = 0; // T = X
            score[idxscr+1] = 0; // T = O
            for (int col = 0; col < 4; col++) {
                if (board[row][col] == 0) {
                    score[idxscr] += 1;
                    score[idxscr+1] += -1;
                }
                else {
                    score[idxscr] += board[row][col];
                    score[idxscr+1] += board[row][col];
                }
            }
            if (score[idxscr] == 4)
                return 1;
            else if (score[idxscr+1] == -4)
                return -1;
            else if (score[idxscr] > 4)
                hasEmpty = true;
            idxscr += 2;
        }
        for (int col = 0; col < 4; col++) {
            score[idxscr] = 0; // T = X
            score[idxscr+1] = 0; // T = O
            for (int row = 0; row < 4; row++) {
                if (board[row][col] == 0) {
                    score[idxscr] += 1;
                    score[idxscr+1] += -1;
                }
                else {
                    score[idxscr] += board[row][col];
                    score[idxscr+1] += board[row][col];
                }
            }
            if (score[idxscr] == 4)
                return 1;
            else if (score[idxscr+1] == -4)
                return -1;
            else if (score[idxscr] > 4)
                hasEmpty = true;
            idxscr += 2;
        }
        // diag1
        for (int i = 0; i < 4; i++) {
            if (board[i][i] == 0) {
                    score[idxscr] += 1;
                    score[idxscr+1] += -1;
                }
                else {
                    score[idxscr] += board[i][i];
                    score[idxscr+1] += board[i][i];
                }
        }
        if (score[idxscr] == 4)
            return 1;
        else if (score[idxscr+1] == -4)
            return -1;
        else if (score[idxscr] > 4)
            hasEmpty = true;
        idxscr += 2;
        // diag2
        for (int i = 0; i < 4; i++) {
            if (board[i][3 - i] == 0) {
                score[idxscr] += 1;
                score[idxscr+1] += -1;
            }
            else {
                score[idxscr] += board[i][3 - i];
                score[idxscr+1] += board[i][3 - i];
            }
        }
        if (score[idxscr] == 4)
            return 1;
        else if (score[idxscr+1] == -4)
            return -1;
        else if (score[idxscr] > 4)
            hasEmpty = true;
        
        if (hasEmpty)
            return 100;
        else
            return 0; //draw
        
    }
   
    public static void main(String[] args) {
        if (args.length == 0) {
//            int[] vec1 = {1, 2, 3, 4, 5};
//            int[] vec2 = {1, 0, 1, 0, 1};
//            TicTacToeT blk = new TicTacToeT(vec1, vec2);
//            StdOut.println(blk.MinProd());
//            return;
        }
        In in = new In(args[0]);
        int T = in.readInt(); // # of test cases
        Out out = new Out(args[0]+".Out");
        for (int i = 0; i < T; i++) {
            int[][] vec = new int[4][4];
            for (int row = 0; row < 4; row++) {
                String rowB = in.readString();
                for (int col = 0; col < 4; col++) {
                    if (rowB.charAt(col) == 'X')
                        vec[row][col] = 1;
                    else if (rowB.charAt(col) == 'O')
                        vec[row][col] = -1;
                    else if (rowB.charAt(col) == 'T')
                        vec[row][col] = 0;
                    else if (rowB.charAt(col) == '.')
                        vec[row][col] = 100;
                }
            }
            in.readLine();
            TicTacToeT blk = new TicTacToeT(vec);
            
            out.println("Case #" + (i+1) + ": " + blk.Result());
//            StdOut.println("Case #" + (i+1) + ": " + blk.Result());
        }
        out.close();
    }
}