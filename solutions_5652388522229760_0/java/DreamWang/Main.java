import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream (new File("A-small-attempt1.in") ) ) ) );
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    HashSet<Long> st = new HashSet<Long>();
    int base = 0;
    for(int i =0;i<=9;i++){
    	base = base | (1 << i);
    }
    for (int i = 1; i <= t; ++i) {
      int n = in.nextInt();
      int times = 1;
      int result = 0;
      st.clear();
      boolean z = false;
      while(true){
    	  long tmp = times* n;
    	  if( st.contains(tmp) )
    		  break;
    	  else
    		  st.add(tmp);
    	  while(tmp>0){
    		  long mod = tmp%10;
    		  result = result | (1 << mod);
    		  tmp = tmp/10;
    	  }
    	  if( result == base ){
    		  z = true;
    		  break;
    	  }
    	  times++;
      }
      if (!z){
    	  System.out.println("Case #" + i + ": " + "INSOMNIA");
      }else{
    	  System.out.println("Case #" + i + ": " + (long)times*n);
      }
    }
  }
}