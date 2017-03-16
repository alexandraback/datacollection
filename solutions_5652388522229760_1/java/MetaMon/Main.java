
import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(new File("src/A-large.in")))));
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    StringBuffer sb = new StringBuffer();
    for (int i = 1; i <= t; i++){
    	int n = in.nextInt();
    	int res = countSheep(n);
    	if (res != -1){
//			  System.out.println("Case #" + i + ": " + res);
    		sb.append("Case #" + i + ": " + res + "\n");
		  }else {
//			  System.out.println("Case #" + i + ": " + "INSOMNIA");
			  sb.append("Case #" + i + ": " + "INSOMNIA" + "\n");
		  }
    	
    }
    
    String path="src/output.txt";
    File file=new File(path);
    if(!file.exists())
        file.createNewFile();
    FileOutputStream out=new FileOutputStream(file,false);
    out.write(sb.toString().getBytes("utf-8"));
    out.close();
//    for (int i = 1; i <= t; ++i) {
//      int n = in.nextInt();
//      int m = in.nextInt();
//      System.out.println("Case #" + i + ": " + (n + m) + " " + (n * m));
//	  for (int i = 0; i < 1000001; i ++){
//		  int res = countSheep(i);
//		  if (res != -1){
//			  System.out.println("Case #" + i + ": " + res);
//		  }else {
//			  System.out.println("Case #" + i + ": " + "INSOMNIA");
//		  }
//		  
//	  }
    }
//  
  public static int countSheep(int start){
	  int flag = 0;
	  int goal = 0;
	  for (int i = 1; i <= 10; i ++){
		  goal = goal | (1 << i);
	  }
	  for ( int i = 1; i <= 1000; i ++){
		  int next = start * i;
		  int tmp = next;
		  while (tmp != 0){
			  flag = flag | (1 << (tmp % 10 + 1));
			  tmp = tmp / 10;
			  if (flag == goal)
				  return next;
		  }
		  
	  }
	  return -1;
  }
}
