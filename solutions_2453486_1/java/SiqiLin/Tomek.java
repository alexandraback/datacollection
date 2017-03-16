import java.io.*;

public class Tomek {
    private static void checkBoard(String[] board, BufferedWriter bw, int caseNumber) throws IOException {
        int emptyCount = 0;
        
        for (int x = 0; x < 4; x++) {
            int Xcount = 0;
            int Ocount = 0;

            for (int y = 0; y < 4; y++) {
                char c = board[x].charAt(y);
                if (c == '.') {
                    emptyCount++;
                } else if (c == 'T') {
                    Xcount++;
                    Ocount++; 
                } else if (c == 'X') {
                    Xcount++;
                } else if (c == 'O') {
                    Ocount++;
                } 
            }
            if (Xcount == 4) {
                bw.write("Case #" + caseNumber + ": X won");
                bw.newLine();
                return;
            } else if (Ocount == 4) {
                bw.write("Case #" + caseNumber + ": O won");
                bw.newLine();
                return;
            }
        } 

        for (int y = 0; y < 4; y++) {
            int Xcount = 0;
            int Ocount = 0;

            for (int x = 0; x < 4; x++) {
                char c = board[x].charAt(y);
                if (c == 'T') {
                    Xcount++;
                    Ocount++; 
                } else if (c == 'X') {
                    Xcount++;
                } else if (c == 'O') {
                    Ocount++;
                }
            }
            if (Xcount == 4) {
                bw.write("Case #" + caseNumber + ": X won");
                bw.newLine();
                return;
            } else if (Ocount == 4) {
                bw.write("Case #" + caseNumber + ": O won");
                bw.newLine();
                return;
            }
        }

        int Xcount = 0;
        int Ocount = 0;

        for (int i = 0; i < 4; i++) {
            char c = board[i].charAt(i);
            if (c == 'T') {
                Xcount++;
                Ocount++; 
            } else if (c == 'X') {
                Xcount++;
            } else if (c == 'O') {
                Ocount++;
            }
        }

        if (Xcount == 4) {
            bw.write("Case #" + caseNumber + ": X won");
            bw.newLine();
            return;
        } else if (Ocount == 4) {
            bw.write("Case #" + caseNumber + ": O won");
            bw.newLine();
            return;
        }

        Xcount = 0;
        Ocount = 0;

        for (int i = 0; i < 4; i++) {
            char c = board[3 - i].charAt(i);
            if (c == 'T') {
                Xcount++;
                Ocount++; 
            } else if (c == 'X') {
                Xcount++;
            } else if (c == 'O') {
                Ocount++;
            }
        }

        if (Xcount == 4) {
            bw.write("Case #" + caseNumber + ": X won");
            bw.newLine();
            return;
        } else if (Ocount == 4) {
            bw.write("Case #" + caseNumber + ": O won");
            bw.newLine();
            return;
        }

        if (emptyCount == 0) {
            bw.write("Case #" + caseNumber + ": Draw");
        } else {
            bw.write("Case #" + caseNumber + ": Game has not completed");
        }
        bw.newLine();
    }

    public static void main(String[] args) {
        BufferedReader br = null;
        BufferedWriter bw = null;

        try {
            File outputFile = new File("./Tomek_out.txt");
            br = new BufferedReader(new FileReader("./Tomek_in.txt"));

            if (!outputFile.exists()) {
              outputFile.createNewFile();
            }

            bw = new BufferedWriter(new FileWriter(outputFile));

            String currentLine;

            currentLine = br.readLine();
            int T = Integer.valueOf(currentLine);

            for (int t = 1; t <= T; t++) {
                String[] board = new String[4];
                for (int j = 0; j < 4; j++) {
                    currentLine = br.readLine();
                    board[j] = currentLine;
                }
                checkBoard(board, bw, t);
                br.readLine(); // Get rid of extra line;
            }
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
                if (bw != null) {
                    bw.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            } 
        }
    }
}
