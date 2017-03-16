import java.util.Scanner;

public class gcj_a {
    String[] board = new String[4];
    int emptyCells = 0;

    public void setBoard(int i, String s) {
        this.board[i] = s;
        this.emptyCells += dotCount(s);
    }

    private int dotCount(String s) {
        int ans = 0;
        for (char c : s.toCharArray()) {
            if(c == '.') ans++;
        }
        return ans;
    }

    public void printBoard() {
        System.out.println(emptyCells);
        for(int j = 0; j < 4; j++) {
            System.out.print(board[j].charAt(0));
            System.out.print(board[j].charAt(1));
            System.out.print(board[j].charAt(2));
            System.out.println(board[j].charAt(3));
        }
    }

    public boolean isWinningPositionFor(char P) {
        int diagCount1=0, diagCount2 = 0;
        for(int i = 0; i < 4; i++) {
            int rowCount = 0,colCount = 0;
            for(int j = 0; j < 4; j++) {
                if(this.board[i].charAt(j) == P || this.board[i].charAt(j) == 'T') rowCount++;
                if(this.board[j].charAt(i) == P || this.board[j].charAt(i) == 'T') colCount++;
            }
            if(this.board[i].charAt(i) == P || this.board[i].charAt(i) == 'T') diagCount1++;
            if(this.board[i].charAt(3 - i) == P || this.board[i].charAt(3 - i) == 'T') diagCount2++;
            if(rowCount == 4 || colCount == 4 || diagCount1 == 4 || diagCount2 == 4) return true;
        }
        return false;
    }

    public String boardStatus() {
        if(isWinningPositionFor('X')) return "X won";
        if(isWinningPositionFor('O')) return "O won";
        if(this.emptyCells == 0) return "Draw";
        return "Game has not completed";
    }

    public static void main(String[] args) {
        int t,i,j;
        Scanner input = new Scanner(System.in);
        t = Integer.parseInt(input.nextLine());
        //System.out.println(t);
        for(i = 1; i <= t; i++) {
            gcj_a g = new gcj_a();
            for(j = 0; j < 4; j++) {
                g.setBoard(j, input.nextLine());
            }
            //g.printBoard();
            System.out.println("Case #"+i+": "+g.boardStatus());
            input.nextLine();
        }
    }
}

