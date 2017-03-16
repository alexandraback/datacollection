public class Round1B_A
{
   static boolean debug = true;

   static void print(String str) { if (debug) System.out.print(str); }
   static void println(String str) { if (debug) System.out.println(str); }
   static void println(int str) { if (debug) System.out.println(str); }
   static void println() { if (debug) System.out.println(); }

   static final double MYVAL = -1.234567890123456789;

   public static void main(String[] args)
   {
      Utils.openInFile("A-large.in");
      Utils.openOutFile("out.txt", debug);
      String input = Utils.readFromFile();
      String[] split1 = input.split(" ");
      int lineCount = Integer.parseInt(split1[0]);

      //while ((input = Utils.readFromFile()) != null)
      for (int i = 1; i <= lineCount; i++)
      {
         input = Utils.readFromFile();
         // code here
         String[] split = input.split(" ");
         int n = split.length-1;
         int[] nums = new int[n];
         int total = 0;
         for (int j = 0; j < n; j++)
         {
            nums[j] = Integer.parseInt(split[j+1]);
            total += nums[j];
         }
         double[] targets = new double[n];
         for (int j = 0; j < n; j++)
         {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
               if (k == j) continue;
               sum += nums[k];
            }
            // > (sum+total)/nums.length
            targets[j] = 1.0*(sum+total-(n-1)*nums[j])/n;
            
             //System.out.println("target["+j+"] = "+targets[j]);
            //for (int k = 0; k < nums.length; k++)

            targets[j] = 100.0*targets[j]/total;
         }

         //if (targets[j] < 0) targets[j] = 0; + split btw other targets
         int count = n-1;
         for (int j = 0; j < n; j++)
         {
            if (targets[j] < 0)
            {
               double change = 1.0*targets[j]/count;
               count--;
               for (int k = 0; k < n; k++)
               {
                  if (k == j) continue;
                  if (targets[k] != MYVAL)
                  {
                     targets[k] += change;
                  }
               }
               targets[j] = MYVAL;
            }
         }

         for (int j = 0; j < n; j++)
            if (targets[j] == MYVAL)
               targets[j] = 0;

         println("input="+input);

         String output = "Case #" + i + ":";
         for (int j = 0; j < n; j++)
            output += " "+targets[j];

         Utils.writeToFile(output);
      }
      Utils.closeInFile();
      Utils.closeOutFile();
   }
}
