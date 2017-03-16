import java.io.*;

public class c_dijkstra {
   
   public static void main (String[] args) throws IOException {
      (new c_dijkstra()).run();
   }
   
   int[][] MULT_TABLE = new int[8][8];
   public c_dijkstra() {
      MULT_TABLE[0][0] = 0;  MULT_TABLE[0][1] = 1;  MULT_TABLE[0][2] = 2;  MULT_TABLE[0][3] = 3;
      MULT_TABLE[1][0] = 1;  MULT_TABLE[1][1] = 4;  MULT_TABLE[1][2] = 3;  MULT_TABLE[1][3] = 6;
      MULT_TABLE[2][0] = 2;  MULT_TABLE[2][1] = 7;  MULT_TABLE[2][2] = 4;  MULT_TABLE[2][3] = 1;
      MULT_TABLE[3][0] = 3;  MULT_TABLE[3][1] = 2;  MULT_TABLE[3][2] = 5;  MULT_TABLE[3][3] = 4;

      for (int a = 0; a < 4; ++a)
         for (int b = 4; b < 8; ++b)
            MULT_TABLE[a][b] = ( MULT_TABLE[a][b-4] + 4 ) % 8;

      for (int a = 4; a < 8; ++a)
         for (int b = 0; b < 4; ++b)
            MULT_TABLE[a][b] = ( MULT_TABLE[a-4][b] + 4 ) % 8;

      for (int a = 4; a < 8; ++a)
         for (int b = 4; b < 8; ++b)
            MULT_TABLE[a][b] = MULT_TABLE[a-4][b-4];
   }

   static int valueOf(char c) {
      if (c == '1') return 0;
      return c - 'i' + 1;
   }
   
   static String valueOf(int v) {
      String res = "";
      if (v >= 4) {
         res += '-';
         v -= 4;
      }
      if (v == 0) res += '1';
      else res += (char) ('i' + v - 1);
      return res;
   }
   
   void run() throws IOException {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      int TC = Integer.parseInt(in.readLine());
      for (int tc = 1; tc <= TC; ++tc) {
         String[] tok = in.readLine().split(" ");
         int L = Integer.parseInt(tok[0]);
         int X = Integer.parseInt(tok[1]);
         String S = in.readLine();
         StringBuilder sb = new StringBuilder();
         for (int x = 0; x < X; ++x)
            sb.append(S);
         int cur = 0;
         int stage = 0;
         for (int i = 0; i < sb.length(); ++i) {
            int v = valueOf( sb.charAt(i) );
         //   System.err.print( i + " " + sb.charAt(i) + ": " + valueOf(cur) + " * " + valueOf(v) + " = ");
            cur = MULT_TABLE[cur][v];
         //   System.err.println(valueOf(cur));
            if (cur == 1 && stage == 0)
               stage = 1;
            else if (cur == 3 && stage == 1)
               stage = 2;
         }
         if (cur == 4 && stage == 2) stage = 3;
         String res =  stage == 3 ? "YES" : "NO";
         System.out.printf("Case #%d: %s\n", tc, res);
      }
   }
}

