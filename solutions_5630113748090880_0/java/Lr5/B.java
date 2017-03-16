import java.util.*;

public class B
{
  private int N;
  
  List<List<Integer>> slips = new ArrayList<>();

  public B(int N)
  {
    this.N = N;
  }
  
  public void addSlip(List<Integer> slip)
  {
    slips.add(slip);
  }
  
  public String solve()
  {
    int[] counts = new int[10000];
    
    for(List<Integer> slip : slips)
    {
      for(Integer i : slip)
        counts[i]++;
    }
    
    StringBuilder result = new StringBuilder();
    
    for(int i = 1; i <= 2500; ++i)
    {
      if(counts[i]%2 != 0)
      {
        if(result.length() > 0)
          result.append(" ");
          
        result.append(""+i);
      }
    }
  
    return result.toString();
  }

  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    
    int N = in.nextInt();
    
    for(int i = 0; i < N; ++i)
    {
      int inputN = in.nextInt();
      int caseN = i+1;
      
      B b = new B(inputN);
      
      for(int e = 0; e < (2*inputN-1); ++e)
      {
        List<Integer> slip = new ArrayList<>();
        
        for(int f = 0; f < inputN; ++f)
          slip.add(in.nextInt());
          
        b.addSlip(slip);
      }
      
      String result = b.solve();
      
      String resultString = result;
      
      System.out.println("Case #"+caseN+": "+resultString);
    }
  }
}
