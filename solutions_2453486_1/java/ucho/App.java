package net.purevirtual.googlejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import org.apache.commons.lang.StringUtils;

/**
 * Hello world!
 *
 */
public class App {
    private static class Board {
        char[][] board;
        public Board(char[][] board) {
            this.board = board;
        }
        
        public int getWinner(int[][] fields) {
            boolean winnerX = true;
            boolean winnerO = true;
            for (int[] cord : fields) {
                char val = board[cord[0]][cord[1]];
                winnerX &= (val == 'T' || val == 'X');
                winnerO &= (val == 'T' || val == 'O');
            }
            if (winnerX) {
                return 1;
            }
            if (winnerO) {
                return 2;
            }
            return 0;
        }
    
        public boolean isFull(char[][] board) {
            for (char[] line : board) {
                for (char ch : line) {
                    if (ch == '.') {
                        return false;
                    }
                }
            }
            return true;
        }
        
        public int getRowWinner(int row) {
            int[][] arg = {{row,0},{row,1},{row,2},{row,3}};
            return getWinner(arg);
        }
        
        public int getColWinner(int col) {
            int[][] arg = {{0,col},{1,col},{2,col},{3,col}};
            return getWinner(arg);
        }
        
        public int getDiagonalWinner1() {
            int[][] arg = {{0,0},{1,1},{2,2},{3,3}};
            return getWinner(arg);
        }
        
        public int getDiagonalWinner2() {
            int[][] arg = {{0,3},{1,2},{2,1},{3,0}};
            return getWinner(arg);
        }
    }
    
    
    
        
    public static void main(String[] args) throws FileNotFoundException, IOException {
        PrintWriter writer = new PrintWriter(new FileWriter("output"));
        Scanner scanner = new Scanner(new FileReader("input"));
        int tests = scanner.nextInt();
        scanner.nextLine();
        for(int t=0;t<tests;t++) {
            char[][] board = new char[4][4];
            for(int i =0;i<4;i++) {
                board[i] = scanner.nextLine().toCharArray();
            }
            

            Board b = new Board(board);
            Set<Integer> winners = new HashSet<Integer>();
            for(int i=0;i<4;i++) {
                winners.add(b.getColWinner(i));
                winners.add(b.getRowWinner(i));
            }
            winners.add(b.getDiagonalWinner1());
            winners.add(b.getDiagonalWinner2());
            boolean winnerX = winners.contains(1);
            boolean winnerO = winners.contains(2);
            String result;
            if (winnerX && winnerO) {
                result = "Draw";
            } else if (winnerX) {
                result = "X won";
            } else if (winnerO) {
                result = "O won";
            } else if (!b.isFull(board)) {
                result = "Game has not completed";
            } else {
                result = "Draw";
            }
            String msg = "Case #"+(t+1)+": "+result;
            System.out.println(msg);
            writer.println(msg);
            
            scanner.nextLine();
        }
        writer.close();
    }
}
