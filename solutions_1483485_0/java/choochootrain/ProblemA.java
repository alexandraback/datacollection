/*
choochootrain
Google Code Jam 2012
*/
import java.io.*;
import java.util.*;

class ProblemA 
{
  public static void main (String [] args) throws IOException 
  {
    String filename = "A-small-attempt0";  
    String[][] map = {
      {"a","y"}, 
      {"b","h"},
      {"c","e"},
      {"d","s"},
      {"e","o"},
      {"f","c"},
      {"g","v"},
      {"h","x"},
      {"i","d"},
      {"j","u"},
      {"k","i"},
      {"l","g"},
      {"m","l"},
      {"n","b"},
      {"o","k"},
      {"p","r"},
      {"q","z"},
      {"r","t"},
      {"s","n"},
      {"t","w"},
      {"u","j"},
      {"v","p"},
      {"w","f"},
      {"x","m"},
      {"y","a"},
      {"z","q"}, 
    };

    BufferedReader f = new BufferedReader(new FileReader(filename + ".in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")));
    int numberOfTests = Integer.parseInt(f.readLine());
    for(int n = 1; n <= numberOfTests; n++)
    {
      String line = f.readLine();
      String translated = "";

      for(char c : line.toCharArray()) {
        if (c == ' ')
          translated = translated + ' ';
        else
          translated = translated + map[c - 97][1];
      }
      
      String solution = translated;
      out.println("Case #" + n + ": " + solution);
    }
    out.close();
    System.exit(0);
  }
}
