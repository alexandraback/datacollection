import java.util.*;
import java.io.*;
import java.math.*;

public class GoogleCodeJamBMain {
   static Scanner sc;

   public static String go(int j,int k) {
      int X = j;
      int Y = k;
      int currX=0;
      int currY=0;
      int moves=1;
      String out="";
      System.out.println("here");
      Stack<Character> movesList=new Stack<Character>();
      while(moves<500&&!(currX==X&&currY==Y)){
    	  if(currX>X){
    		  out=out+"EW";
    		  currX--;
    	  }
    	  else if(currX<X){
    		  out=out+"WE";
    		  currX++;
    	  }
    	  else if(currY>Y){
    		  out=out+"NS";
    		  currY--;
    	  }
    	  else if(currY<Y){
    		  out=out+"SN";
    		  currY++;
    	  }
    	  moves++;
    	  //System.out.println(currX+" "+currY);
      }
      System.out.println(out);
      return out;
   }

   public static void main(String[] args) {
	   Scanner scanner = null;
	   BufferedWriter bw = null;
	   String s="";

      try{
          scanner = new Scanner(new File("test.in"));
          bw = new BufferedWriter(new FileWriter("output.txt"));
      int T = scanner.nextInt();
      for (int i=1; i<=T; i++) {
         System.out.format("Case #%d: ", i);
         int j=scanner.nextInt();
         int k=scanner.nextInt();
         s=go(j,k);
         bw.write("Case #"+i+": "+s+'\n');
      }
      }
      catch(FileNotFoundException e){
			System.out.println("Not Found");
		}
	catch(IOException e){}
		finally{
			try{
				if(bw!=null){
					bw.flush();
					bw.close();
				}
			}
			catch(IOException e){}
		}
   }
}