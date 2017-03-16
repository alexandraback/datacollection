   import java.util.*;
   import java.io.*;
   import java.math.*;
   public class pass{
      public static void main(String[] args) throws Exception
      {
         BufferedReader f = new BufferedReader(new FileReader("pass.in"));
         PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pass.out")));
         int cases = Integer.parseInt(f.readLine());
         for(int cas = 1; cas<=cases; cas++){
            StringTokenizer st = new StringTokenizer(f.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            double[] array = new double[a];
            st = new StringTokenizer(f.readLine());
            int max = (int)Math.pow(2, a);
            for(int i = 0; i<array.length; i++)
               array[i] = Double.parseDouble(st.nextToken());
            double[][] matrix = new double[max][a+2];
            for(int i = 0; i<max; i++){
               String s = Integer.toBinaryString(i);
               while(s.length()<a)
                  s = "0"+s;
               double temp = 1;
               int min = a;
               for(int j = 0;j<a; j++){
                  if(s.charAt(j) == '0'){
                     temp*=array[j];
                  }
                  else
                  {
                     temp*=1-array[j];
                     if(min ==a)
                        min = j;
                  } 
               }
               matrix[i][a+1]=temp;
               for(int bb = 0; bb<=a; bb++){
                  if(a-bb<=min){
                     matrix[i][bb] = 2*bb+b-a+1;
                  }
                  else{
                     matrix[i][bb] = 2*bb+2+b+b-a;
                  }
               }
            }
            double ans = 2+b;
            for(int e = 0; e<=a; e++){
               double temp = 0;
               for(int r = 0; r<max; r++)
                  temp+=matrix[r][e]*matrix[r][a+1];
               ans = Math.min(ans, temp);
            }
            out.println("Case #"+cas+": "+ans);
         }      
         out.close();
         System.exit(0);
      }
   }