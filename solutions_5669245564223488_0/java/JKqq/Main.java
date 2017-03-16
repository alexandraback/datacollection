import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main
{
  static BufferedReader reader;
  static StringTokenizer tokenizer;
  static PrintWriter writer;
  
  static int nextInt() throws IOException
  {
    return Integer.parseInt(nextToken());
  }
  
  static long nextLong() throws IOException
  {
    return Long.parseLong(nextToken());
  }
  
  static double nextDouble() throws IOException
  {
    return Double.parseDouble(nextToken());
  }
  
  static boolean eof = false;
  
  static String nextToken() throws IOException
  {
    while (tokenizer == null || !tokenizer.hasMoreTokens())
    {
      tokenizer = new StringTokenizer(reader.readLine());
    }
    return tokenizer.nextToken();
  }
  
  public static void main(String[] args) throws IOException
  {
    tokenizer = null;
    reader = new BufferedReader(new FileReader("in"));
    writer = new PrintWriter(new FileWriter("out.txt"));
    banana();
    reader.close();
    writer.close();
  }
  
  static long gcd(long x, long y)
  {
    if (y == 0)
      return x;
    return gcd(y, x % y);
  }
  
  static void banana() throws IOException
  {
    int n = nextInt();
    long mod = 1_000_000_000 + 7;
    for (int i = 0; i < n; ++i)
    {
      writer.print("Case #" + (i + 1) + ": ");
      long count = 0;
      int k = nextInt();
      String s[] = new String[k];
      for (int j = 0; j < k; ++j)
        s[j] = nextToken();
      
      List<int[]> a = new ArrayList<>();
      
      int p[] = new int[k];
      for (int j = 0; j < k; ++j)
        p[j] = j;
      
      int prev[] = null;
      do
      {
        prev = new int[k];
        for (int j = 0; j < k; ++j)
          prev[j] = p[j];
        a.add(prev);
        
        // System.out.println(Arrays.toString(p));
      }
      while (nextPermutation(p));
      
      for (int j = 0; j < a.size(); ++j)
      {
        StringBuilder sb = new StringBuilder();
        
        for (int l = 0; l < k; ++l)
          sb.append(s[a.get(j)[l]]);
        
        boolean used[] = new boolean['z' - 'a' + 1];
        boolean ok = true;
        for (int q = 0; q < sb.length(); )
        {
          char cc = sb.charAt(q);
          if (used[cc - 'a'])
          {
            ok = false;
            break;
          }
          else
          {
            used[cc-'a'] = true;
            while (q < sb.length() && sb.charAt(q) == cc)
              ++q;
          }
        }
        if (ok)
          ++count;
      }
      
      writer.println(count);
    }
  }
  
  static boolean nextPermutation(int[] array)
  {
    // Find longest non-increasing suffix
    int i = array.length - 1;
    while (i > 0 && array[i - 1] >= array[i])
      i--;
    // Now i is the head index of the suffix
    
    // Are we at the last permutation already?
    if (i == 0)
      return false;
    
    // Let array[i - 1] be the pivot
    // Find rightmost element that exceeds the pivot
    int j = array.length - 1;
    while (array[j] <= array[i - 1])
      j--;
    // Now the value array[j] will become the new pivot
    // Assertion: j >= i
    
    // Swap the pivot with j
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;
    
    // Reverse the suffix
    j = array.length - 1;
    while (i < j)
    {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
    
    // Successfully computed the next permutation
    return true;
  }
}