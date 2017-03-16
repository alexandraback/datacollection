import java.util.Scanner;

public class A
{
  String input;

  public A(String input)
  {
    this.input = input;
  }
  
  public String solve()
  {
    String result = "";
  
    for(int i = 0; i < input.length(); ++i)
    {
      char c = input.charAt(i);
      
      if(result.length() == 0)
        result = c+result;
      else
      {
        char firstChar = result.charAt(0);
        
        if(c >= firstChar)
          result = c+result;
        else
          result = result+c;
      }
    }
  
    return result;
  }

  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    
    int N = in.nextInt();
    
    for(int i = 0; i < N; ++i)
    {
      String input = in.next();
      int caseN = i+1;
      
      A a = new A(input);
      String result = a.solve();
      
      String resultString = result;
      
      System.out.println("Case #"+caseN+": "+resultString);
    }
  }
}
