import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws FileNotFoundException {
	  //new FileInputStream (new File("A-large.in") ) 
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader( new FileInputStream (new File("A-large.in") )  ) ));
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    //int[] divisor = new int[9];
    for (int i = 1; i <= t; ++i) {
    	int n = in.nextInt();
    	int j = in.nextInt();
    	writeLog("Case #"+t+":\n");
    	create(0,0,j,n);
    	
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