import java.io.*;

public class a_tic_tac_toe_tomek {
   
   public static void main (String[] args) throws IOException {
      (new a_tic_tac_toe_tomek()).Run();
   }

   boolean won(char player, char[][] B) {
      boolean ok;
      for (int r = 0; r < 4; ++r) {
         ok = true;
         for (int c = 0; c < 4; ++c) {
            if (B[r][c] != player && B[r][c] != 'T') {
               ok = false;
               break;
            }
         }
         if (ok) return true;
      }

      for (int c = 0; c < 4; ++c) {
         ok = true;
         for (int r = 0; r < 4; ++r) {
            if (B[r][c] != player && B[r][c] != 'T') {
               ok = false;
               break;
            }
         }
         if (ok) return true;
      }

      ok = true;
      for (int i = 0; i < 4; ++i) {
         if (B[i][i] != player && B[i][i] != 'T') {
            ok = false;
            break;
         }
      }
      if (ok) return true;

      ok = true;
      for (int i = 0; i < 4; ++i) {
         if (B[i][3-i] != player && B[i][3-i] != 'T') {
            ok = false;
            break;
         }
      }
      if (ok) return true;

      return false;
   }
   
   int countPlays(char[][] B) {
      int res = 0;
      for (int r = 0; r < 4; ++r)
         for (int c = 0; c < 4; ++c)
            if (B[r][c] != '.')
               ++res;
      return res;
   }
   
   String getState(char[][] B) {
      if (won('X', B)) return "X won";
      if (won('O', B)) return "O won";
      int cnt = countPlays(B);
      return cnt == 16 ? "Draw" : "Game has not completed";
   }
   
   void Run() throws IOException {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      int TC = Integer.parseInt( in.readLine().trim() );
      char[][] B = new char[4][];
      for (int tc = 1; tc <= TC; ++tc) {
         for (int r = 0; r < 4; ++r)
            B[r] = in.readLine().trim().toCharArray();
         in.readLine();
         System.out.println("Case #" + tc + ": " + getState(B));
      }
   }
}

