import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws FileNotFoundException {
	  //new FileInputStream (new File("A-large.in") ) 
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader( new FileInputStream (new File("D-large.in") )    ) ));
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    //int[] divisor = new int[9];
    for (int i = 1; i <= t; ++i) {
    	int K = in.nextInt();
    	int C = in.nextInt();
    	int S = in.nextInt();
    	if( C == 1 ){
    		//
    		if( S < K )
    			writeLog("Case #"+i+": IMPOSSIBLE\n");
    		else{
    			writeLog("Case #"+i+":");
    			for(int m =1 ;m<=K;m++){
    				writeLog(" "+ m );
    			}
    			writeLog("\n");
    		}
    		continue;
    	}
    	int num = (K+1)/2;
    	int[] r = new int[num];
    	r[0] = Math.min(2, K);
    	int j = 1;
    	while( j < num ){
    		r[j] = r[j-1] + 2;
    		if( r[j] > K)
    			r[j] = K;
    		
    		j++;
    	}
    	if (S < num ){
    		writeLog("Case #"+i+": IMPOSSIBLE\n");
    	}else{
    		writeLog("Case #"+i+": "+r[0]);
    		for( int z = 1; z < num; z++){
    			writeLog(" "+r[z]);
    		}
    		writeLog("\n");

    	}
    	
    	
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