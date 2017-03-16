import java.io.*;
import java.util.*;


public class Test {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    public static void main (String[] args) throws IOException {
        
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "1.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "1.out"));
        int tc = sc.nextInt();

        for (int tci=1;tci<=tc;tci++) {
            char[][] g = new char[4][4];
            String temp;
            int nx=0,no=0,nd = 0;
            boolean ended = false;
            boolean going = false;
            char winner = 'X';
            sc.nextLine();
            for (int i=0;i<4 && !ended;i++) {
                temp = sc.nextLine();
                for (int j=0;j<4;j++) {
                    g[i][j] = temp.charAt(j);
                }
            }
            for (int i=0;i<4 && !ended;i++) {
                nx = 0;
                no = 0;
                nd = 0;
                for (int j=0;j<4;j++) {
                    if (g[i][j]=='X') nx++;
                    else if (g[i][j]=='O') no++;
                    else if (g[i][j]=='T') {no++;nx++;}
                    else if (g[i][j]=='.') nd++;
                }
                if (nx==4) {
                    ended = true;
                    winner = 'X';
                }
                else if (no==4) {
                    ended = true;
                    winner = 'O';
                }
                else if (nx+nd==4 || no+nd==4) {
                    going = true;
                }
            }
            for (int j=0;j<4 && !ended;j++) {
                no = 0;
                nx = 0;
                nd = 0;
                for (int i=0;i<4 && !ended;i++) {
                    if (g[i][j]=='X') nx++;
                    if (g[i][j]=='O') no++;
                    if (g[i][j]=='T') {no++;nx++;}
                }
                if (nx==4) {
                    ended = true;
                    winner = 'X';
                }
                else if (no==4) {
                    ended = true;
                    winner = 'O';
                }
                else if (nx+nd==4 || no+nd==4) {
                    going = true;
                }
            }
            
            if (!ended) {
                no = 0;
                nx = 0;
                nd = 0;
                for (int i=0;i<4;i++) {
                    if (g[i][i]=='X') nx++;
                    if (g[i][i]=='O') no++;
                    if (g[i][i]=='T') {no++;nx++;}
                }
                if (nx==4) {
                    ended = true;
                    winner = 'X';
                }
                else if (no==4) {
                    ended = true;
                    winner = 'O';
                }
                else if (nx+nd==4 || no+nd==4) {
                    going = true;
                }
            }
            if (!ended) {
                no = 0;
                nx = 0;
                nd = 0;
                for (int i=0;i<4;i++) {
                    if (g[3-i][i]=='X') nx++;
                    if (g[3-i][i]=='O') no++;
                    if (g[3-i][i]=='T') {no++;nx++;}
                }
                if (nx==4) {
                    ended = true;
                    winner = 'X';
                }
                else if (no==4) {
                    ended = true;
                    winner = 'O';
                }
                else if (nx+nd==4 || no+nd==4) {
                    going = true;
                }
            }
            pw.print("Case #" + tci + ": ");
            if (ended) pw.print(winner + " won");
            else if (going) pw.print("Game has not completed");
            else pw.print("Draw");
            if (tci<tc) pw.println();
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
