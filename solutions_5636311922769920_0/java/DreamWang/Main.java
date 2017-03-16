import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws FileNotFoundException {
	  //new FileInputStream (new File("A-large.in") ) 
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader( new FileInputStream (new File("D-small-attempt0.in") )    ) ));
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    //int[] divisor = new int[9];
    for (int i = 1; i <= t; ++i) {
    	int K = in.nextInt();
    	int C = in.nextInt();
    	int S = in.nextInt();
    	//System.out.println(K);
    	long[] r = new long[K];
    	r[0] = 1;
    	int j = 1;
    	
    	while( j < K){
    		r[j] = r[j-1] + (long)Math.pow(K, C-1) ;
    		j++;
    	}
    	StringBuffer sb = new StringBuffer();
    	sb.append("1");
    	for( int m = 1; m< K;m++){
    		sb.append(" "+r[m]);
    	}
    	writeLog("Case #"+i+": "+sb.toString()+"\n");
    	
    }
  }
  
  public static void create(int number, int count, int total_count, int n){
	  if( count == total_count )
		  return;
	  String rest = Integer.toBinaryString(number);
	  int length = rest.length();
	  StringBuffer sb =new StringBuffer();
	  sb.append("1");
	  for(int i = 0; i< n/2-2-length;i++){
			  sb.append("0");
	  }
	  sb.append(rest);
	  sb.append("1");
	  writeLog(sb.toString() +sb.toString());
	  for( int i= 2;i<=10;i++){
		  writeLog(" "+ ((long)Math.pow(i, n/2) +1));
	  }
	  writeLog("\n");
	  
	  create(number+1, count+1, total_count, n);
	  
	  
  }
  
  public static void writeLog(String str)
  {
      try
      {
      String path="1.txt";
      File file=new File(path);
      if(!file.exists())
          file.createNewFile();
      FileOutputStream out=new FileOutputStream(file,true);        
      out.write(str.getBytes("utf-8"));
      out.close();
      }
      catch(IOException e)
      {
          e.printStackTrace();
      }
  } 
}