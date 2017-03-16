import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class GoogleCJ2014QC {

  public static char[][] getPattern(int R, int C, int M) {
    char[][] result = new char[R][C];
    int numEmpty = R * C - M;
    // In the case where R == 1 || C == 1
    if (R == 1) {
      for (int i = 0; i < M; i++) {
        result[0][i] = '*';
      }
      for (int i = M; i < C-1; i++) {
        result[0][i] = '.';
      }
      result[0][C-1] = 'c';
    }
    else if (C == 1) {
      for (int i = 0; i < M; i++) {
        result[i][0] = '*';
      }
      for (int i = M; i < R-1; i++) {
        result[i][0] = '.';
      }
      result[R-1][0] = 'c';
    }
    // In the case where there is only one space to click
    else if (numEmpty == 1) {
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          result[i][j] = '*';
        }
      }
      result[R-1][C-1] = 'c';
    }
    else if (numEmpty < 4) {
      return null;
    }
    else if (numEmpty % 2 == 0) {
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          result[i][j] = '*';
        }
      }
      if ((numEmpty / 2) % C == 1) {
        for (int i = 0; i < ((numEmpty / 2) / C); i++) {
          for (int j = 0; j < C; j++) {
            result[R-1-i*2][j] = '.';
            result[R-2-i*2][j] = '.';
          }
        }
        result[R - 1 - 2 * ((numEmpty/2) / C)][C-1] = '.';
        result[R - 1 - 2 * ((numEmpty/2) / C)][C-2] = '.';
      }
      else if (R % 2 == 1 && M < C) {
        for (int i = M; i < R * C; i++) {
          result[i / C][i % C] = '.';
        }
      }
      else {
        for (int i = 0; i < numEmpty / 2; i++) {
          result[R - 1 - 2 * (i / C)][C - 1 - (i % C)] = '.';
          result[R - 2 - 2 * (i / C)][C - 1 - (i % C)] = '.';
        }
      }
      result[R-1][C-1] = 'c';
    }
    else if (R > 2 && C > 2 && numEmpty > 8) {
      int tmpNumEmpty = numEmpty - 1;
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          result[i][j] = '*';
        }
      }
      if ((tmpNumEmpty / 2) % C == 1) {
        for (int i = 0; i < ((tmpNumEmpty / 2) / C); i++) {
          for (int j = 0; j < C; j++) {
            result[R-1-i*2][j] = '.';
            result[R-2-i*2][j] = '.';
          }
        }
        result[R - 1 - 2 * ((tmpNumEmpty/2) / C)][C-1] = '.';
        result[R - 1 - 2 * ((tmpNumEmpty/2) / C)][C-2] = '.';
        result[R - 1 - 2 * ((tmpNumEmpty/2) / C)][C-3] = '.';
      }
      else if (R % 2 == 1 && (M+1) < C) {
        for (int i = M; i < R * C; i++) {
          result[i / C][i % C] = '.';
        }
      }
      else if ((tmpNumEmpty/2 - 1) / C == 0) {
        for (int i = 0; i < tmpNumEmpty / 2 - 1; i++) {
          result[R - 1][C - 1 - (i % C)] = '.';
          result[R - 2][C - 1 - (i % C)] = '.';
        }
        result[R - 3][C - 1] = '.';
        result[R - 3][C - 2] = '.';
        result[R - 3][C - 3] = '.';
      }
      else {
        for (int i = 0; i < tmpNumEmpty / 2; i++) {
          result[R - 1 - 2 * (i / C)][C - 1 - (i % C)] = '.';
          result[R - 2 - 2 * (i / C)][C - 1 - (i % C)] = '.';
        }
        if ((tmpNumEmpty / 2) % C > 1) {
          result[R - 1 - 2 * ((tmpNumEmpty / 2) / C)][C - 1 - (tmpNumEmpty/2) % C] = '.';
        }
        else {
          result[R - 2 - 2 * ((tmpNumEmpty / 2 - 1) / C)][C - 1 - ((tmpNumEmpty / 2 - 1) % C)] = '*';
          result[R - 1 - 2 * ((tmpNumEmpty / 2) / C)][C - 1] = '.';
          result[R - 1 - 2 * ((tmpNumEmpty / 2) / C)][C - 2] = '.';
        }
      }
      result[R-1][C-1] = 'c';
      
    }
    else {
      return null;
    }
    return result;
  }
  
  public static boolean isTest = false;
  public static boolean isSmall = true;
  
  public static void main(String[] args) {
    try {
      BufferedReader br;
      BufferedWriter bw;
      if (isTest) {
        br = new BufferedReader(new FileReader("test.txt"));
        bw = new BufferedWriter(new FileWriter("test_out.txt"));
      }
      else {
        if (isSmall) {
          br = new BufferedReader(new FileReader("C-small-attempt1.in"));
          bw = new BufferedWriter(new FileWriter("C-small-out.txt"));
        }
        else {
          br = new BufferedReader(new FileReader("C-large.in"));
          bw = new BufferedWriter(new FileWriter("C-large-out.txt"));
        }
      }
      String[] line = br.readLine().trim().split("\\s+");
      int numProbs = Integer.parseInt(line[0]);
      for (int i = 1; i <= numProbs; i++) {
        line = br.readLine().trim().split("\\s+");
        int R = Integer.parseInt(line[0]);
        int C = Integer.parseInt(line[1]);
        int M = Integer.parseInt(line[2]);
        char[][] result = getPattern(R, C, M);
        System.out.print("Case #" + i + ": (" + R + "," + C + "," + M + ")" + "\n");
        bw.write("Case #" + i + ":\n");
        if (result == null) {
          System.out.print("Impossible\n");
          bw.write("Impossible\n");
        }
        else {
          for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
              System.out.print(result[j][k]);
              bw.write(result[j][k]);
            }
            System.out.println();
            bw.write("\n");
          }
        }
      }
      br.close();
      bw.close();
    }
    catch (IOException e) {
      System.out.println("Error in IO");
    }
  }

}
