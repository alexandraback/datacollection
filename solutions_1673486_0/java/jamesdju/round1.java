import java.util.*;

class round1
{
  public static final int KEEP_TYPING = 1;
  public static final int BACKSPACE_ONCE = 2;
  public static final int BACKSPACE_TWICE = 3;
  public static final int BACKSPACE_THRICE = 4;
  public static final int ENTER = 5;
  
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int numCase, typed, length;
    double max_chance, min, current;
    double[] input;
    
    numCase = sc.nextInt();
    for(int i = 0; i < numCase; i++)
    {
      typed = sc.nextInt();
      length = sc.nextInt();
      input = new double[typed];
      max_chance = 1;
      
      for(int j = 0; j < typed; j++)
      {
        input[j] = sc.nextDouble();
        max_chance *= input[j];
      }
      
      min = length + 2;
      for(int j = 0; j < typed+1; j++)
      {
        if(j == 0)
          current = max_chance*(length-typed+1) + (1-max_chance)*(2*length-typed+2);
        else
          current = max_chance*(2*j + length - typed + 1) + (1-max_chance)*(2*j + 2*length - typed + 2);
        if(current < min)
          min = current;
        
        if(j != typed)
          max_chance /= input[typed-j-1];
      }
      System.out.print("Case #" + (i+1) + ": ");
      System.out.printf("%.6f\n",min);
    }
  }
}