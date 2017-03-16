import java.util.Scanner;
import java.io.*;

public class Recycled {

  public static void main(String[] args) throws FileNotFoundException, IOException {
    Scanner input = new Scanner(new File(args[0]));
    Scanner lin;
    int lines = 0;
    
    if (input.hasNextInt()) {
      lines = input.nextInt();
      input.nextLine();
    }
    
    String nLine;
    String numtostr;
    int tonumber;
    int count;
    int strl;
    int a, b;
    int addednums[];
    boolean didrepeat;
    
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));


    for (int i = 0; i < lines; i++) {
      nLine = input.nextLine();
      lin = new Scanner(nLine);
      out.print("Case #" + (i + 1) + ": ");
      
      a = lin.nextInt();
      b = lin.nextInt();
      
      count = 0;
      
      for (int k = a; k <= b; k++) {
        numtostr = "" + k;
        strl = numtostr.length();
        addednums = new int[strl];
        for (int j = 0; j < strl; j++) {
          didrepeat = false;
          tonumber = Integer.parseInt(numtostr.substring(j, strl) + numtostr.substring(0, j));
          addednums[j] = tonumber;
          for (int l = 0; l < j; l++) {
            if (tonumber == addednums[l]) didrepeat = true;
          }
          if (k > tonumber && tonumber >= a && didrepeat == false) {
            count++;
          }
        }
      }
      
      out.println(count);
      
    }
    
    out.close();
  
  }

}