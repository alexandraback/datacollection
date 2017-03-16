import java.io.*;

public class Lawn {
    public static void main(String[] args) {
        BufferedReader br = null;
        BufferedWriter bw = null;

        try {
            File outputFile = new File("./Lawn_out.txt");
            br = new BufferedReader(new FileReader("./Lawn_in.txt"));

            if (!outputFile.exists()) {
              outputFile.createNewFile();
            }

            bw = new BufferedWriter(new FileWriter(outputFile));

            String currentLine;

            currentLine = br.readLine();
            int T = Integer.valueOf(currentLine);

            out:
            for (int t = 1; t <= T; t++) {
                currentLine = br.readLine();
                String[] split = currentLine.split(" ");
                int N = Integer.valueOf(split[0]);
                int M = Integer.valueOf(split[1]);

                int[][] grid = new int[N][M];

                for (int n = 0; n < N; n++) {
                    currentLine = br.readLine();
                    String[] split2 = currentLine.split(" ");
                    for (int m = 0; m < M; m++) {
                        grid[n][m] = Integer.valueOf(split2[m]);
                    }
                }

                if ((N == 1) || (M == 1)) {
                    bw.write("Case #" + t + ": YES");
                    bw.newLine();
                    continue;
                } 

                for (int j = 0; j < N; j++) {
                    for (int i = 0; i < M; i++) {
                        boolean horizontal = true;
                        boolean vertical = true;

                        for (int x = 0; x < M; x++) {
                            if ((x != i) && (grid[j][x] > grid[j][i])) {
                                horizontal = false;
                                break;
                            } 
                        }

                        for (int y = 0; y < N; y++) {
                            if ((y != j) && (grid[y][i] > grid[j][i])) {
                                vertical = false;
                                break;
                            }
                        }
                        if ((!horizontal) && (!vertical)) {
                            bw.write("Case #" + t + ": NO");
                            bw.newLine();
                            continue out;
                        }
                    }
                }

                bw.write("Case #" + t + ": YES");
                bw.newLine();
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
