import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream (new File("A-large.in") ) ) ) );
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    HashSet<Long> st = new HashSet<Long>();
    int base = 0;
    for(int i =0;i<=9;i++){
    	base = base | (1 << i);
    }
    for (int i = 1; i <= t; ++i) {
      int n = in.nextInt();
    	//int n = i;
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
    	  writeLog("Case #" + i + ": " + "INSOMNIA\n");
      }else{
    	  writeLog("Case #" + i + ": " + (long)times*n+"\n");
      }
    }
  }
  
  public static void writeLog(String str)
  {
      try
      {
      String path="1.txt";
      File file=new File(path);
      if(!file.exists())
          file.createNewFile();
      //SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
      FileOutputStream out=new FileOutputStream(file,true); //如果追加方式用true        
      out.write(str.getBytes("utf-8"));//注意需要转换对应的字符集
      out.close();
      }
      catch(IOException ex)
      {
          System.out.println(ex.getStackTrace());
      }
  } 
}