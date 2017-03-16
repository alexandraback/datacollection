   import java.io.*;
   import java.lang.*;

   public class LawnMower
   {
      public static int [][] lawn = new int [100][100];
      public static void main(String [] args)throws IOException
      {
         BufferedReader read = new BufferedReader(new FileReader("B-large.in"));
         BufferedWriter write = new BufferedWriter(new FileWriter("ans.txt"));
         int T = Integer.valueOf(read.readLine());
         int N = 0, M = 0, count;
         boolean possible;
         String input, temp;
         for(int i = 0; i < T; i++)
         {
         //read input
            temp = "";
            input = read.readLine();
            for(int j = 0; j < input.length(); j++)
            {
               if(input.charAt(j) == ' ')
               {
                  N = Integer.valueOf(temp); // maxrow
                  temp = "";
               }
               else
               {
                  temp += input.charAt(j);
               }
            }
            M = Integer.valueOf(temp); // maxcol
            //lawn[maxrow][maxcol]  => lawn[N][M]
            temp = "";
            for(int j = 0; j < N; j++)
            {
               input = read.readLine()+" ";
               count = 0;
               for(int k = 0; k < input.length(); k++)
               {
                  if(input.charAt(k) == ' ')
                  {
                     lawn[j][count] = Integer.valueOf(temp);
                     count++;
                     temp = "";
                  }
                  else
                  {
                     temp += input.charAt(k);
                  }
               }
            }
            //check lawn
            possible = true;
            for(int j = 0; j < N && possible; j++)
            {
               for(int k = 0; k < M && possible; k++)
               {
                  if(!checkRow(j, M, lawn[j][k]) && !checkCol(k, N, lawn[j][k]))
                     possible = false;
               }
            }
         	
            if(possible)
            {
               //System.out.println("Case #"+(i+1)+": YES");
               write.write("Case #"+(i+1)+": YES");
            }
            else
            {
               //System.out.println("Case #"+(i+1)+": NO");
               write.write("Case #"+(i+1)+": NO");
            }
            write.newLine();
         }
         write.close();
      }
      public static boolean equal(int N, int M)
      {
         int height = lawn[0][0];
         for(int i = 0; i < N; i++)
         {
            for(int j = 0; j < M; j++)
            {
               if(lawn[i][j] != height)
                  return false;
            }
         }
         return true;
      }
      public static boolean checkRow(int row, int M, int height)
      {
         for(int i = 0; i < M; i++)
         {
            if(lawn[row][i] > height)
               return false;
         }
         return true;
      }
      public static boolean checkCol(int col, int N, int height)
      {
         for(int i = 0; i < N; i++)
         {
            if(lawn[i][col] > height)
               return false;
         }
         return true;
      }
      public static void addRow(int row, int M)
      {
         for(int i = 0; i < M; i++)
         {
            lawn[row][i]++;
         }
      }
      public static void addCol(int col, int N)
      {
         for(int i = 0; i < N; i++)
         {
            lawn[i][col]++;
         }
      }
   }