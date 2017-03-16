public class Round1B_C
{
   static boolean debug = true;

   static void print(String str) { if (debug) System.out.print(str); }
   static void println(String str) { if (debug) System.out.println(str); }
   static void println(int str) { if (debug) System.out.println(str); }
   static void println() { if (debug) System.out.println(); }

   public static void main(String[] args)
   {
      Utils.openInFile("in.txt");
      Utils.openOutFile("out.txt", debug);
      String input = Utils.readFromFile();
      String[] split = input.split(" ");
      int lineCount = Integer.parseInt(split[0]);

      //while ((input = Utils.readFromFile()) != null)
      for (int i = 1; i <= lineCount; i++)
      {
         input = Utils.readFromFile();
         // code here
         println("input="+input);

         String output = "Case #" + lineCount + ": ";
         output += 0;

         Utils.writeToFile(output);
      }
      Utils.closeInFile();
      Utils.closeOutFile();
   }
}
