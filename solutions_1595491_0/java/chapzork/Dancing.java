import java.util.Scanner;
import java.io.*;

public class Dancing {

  public static void main(String[] args) throws FileNotFoundException, IOException {
    Scanner input = new Scanner(new File(args[0]));
    Scanner lin;
    int lines = 0;
    
    if (input.hasNextInt()) {
      lines = input.nextInt();
      input.nextLine();
    }
    
    String nLine;
    
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
    
    int googlers, surprising, p;
    int divThree, rem, cases, surprisingCases, answer;
    int[] points;

    for (int i = 0; i < lines; i++) {
      nLine = input.nextLine();
      lin = new Scanner(nLine);
      out.print("Case #" + (i + 1) + ": ");
      
      googlers = lin.nextInt();
      surprising = lin.nextInt();
      p = lin.nextInt();
      points = new int[googlers];
      for (int j = 0; j < googlers; j++) {
        points[j] = lin.nextInt();
      }
      
      cases = 0;
      surprisingCases = 0;
      
      for (int k = 0; k < googlers; k++) {
        divThree = points[k] / 3;
        rem = points[k] % 3;
        if (rem == 0) {
          if (divThree >= p)
            cases++;
          else if (divThree + 1 >= p && divThree != 0)
            surprisingCases++;
        }
        else if (rem == 1) {
          if (divThree + 1 >= p)
            cases++;
        }
        else if (rem == 2) {
          if (divThree + 1 >= p)
            cases++;
          else if (divThree + 2 >= p)
            surprisingCases++;
        }
      }
      
      if (surprisingCases >= surprising) {
        answer = surprising;
      }
      else {
        answer = surprisingCases;
      }
      answer += cases;
        
      out.println(answer);
    }
    
    out.close();
  
  }

}