using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



class Program
{

     static void Main(string[] args)
     {
         StreamReader sr = new StreamReader("D:\\in.in");
         StreamWriter sw = new StreamWriter("D:\\out.out");
         sw.AutoFlush = true;
         int n = int.Parse(sr.ReadLine());
         Console.WriteLine(n);
         for (int i = 0; i < n; i++)
         {
             sw.WriteLine("Case #" + (i + 1).ToString() + ": " + (Solution(sr) ? "RICHARD" : "GABRIEL"));
             Console.WriteLine(i);
         }
         sw.Close();
         sr.Close();
         Console.WriteLine("Finished");
         Console.ReadLine();
     }


     static bool Solution(StreamReader sr)
     {
         string[] t = sr.ReadLine().Split(' ');
         int X = int.Parse(t[0]);
         int R = int.Parse(t[1]);
         int C = int.Parse(t[2]);

         if(R > C)
         {
             int v = R;
             R = C;
             C = v;
         }

         if (X == 1)
             return false;
         if (X == 2)
             return R * C % 2 == 1;
         if (X == 3)
         {
             if (R == 1)
                 return true;
             return R * C % 3 != 0;
         }
         if (X == 4)
         {
             if (R <= 2)
                 return true;
             return R * C % 4 != 0;
         }
         if (X == 5)
         {
             if (R <= 3)
                 return true;
             return R * C % 5 != 0;
         }
         if (X == 6)
         {
             if (R <= 3)
                 return true;
             return R * C % 6 != 0;
         }

         return true;
     }
}