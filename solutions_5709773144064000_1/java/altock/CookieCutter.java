
package Cookie;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Field;
import java.util.ArrayList;


public class CookieCutter{
    public CookieCutter(){    
    }
    public void CookieCutter(String filename) throws NumberFormatException, NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException{
   	 BufferedReader greyparse = new BufferedReader(new FileReader(filename));
   	 greyparse.readLine();
   	 PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
   	 int thiscase = 1;
   	 String thisString;
   	 Double cps;
   	 Double cpf;
   	 Double fp;
   	 Double goal;
   	 Double timetaken;
   	 Double timenofarm;
   	 Double timefarm;
   	 while(greyparse.ready()){
   		 thisString = "Case #" + thiscase + ": ";
   		 String[] curr = greyparse.readLine().split(" ");
   		 fp = Double.valueOf(curr[0]);
   		 cpf = Double.valueOf(curr[1]);
   		 goal = Double.valueOf(curr[2]);
   		 timetaken = 0.0;
   		 cps = 2.0;
   		 
   		 timenofarm = goal/cps + timetaken;
   		 timefarm = goal/(cps + cpf) + fp/cps + timetaken;
   		 while(timefarm < timenofarm){
   			 timetaken += fp/cps;
   			 cps += cpf;
   			 timenofarm = goal/cps + timetaken;
   			 timefarm = goal/(cps + cpf) + fp/cps + timetaken;
   		 }
   		 thisString += timenofarm;
   		 thiscase++;
   		 writer.println(thisString);
   	 }
   	 writer.close();
    }
    /**
    public static void main(String[] args) throws NumberFormatException, NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException{
   	 CookieCutter c = new CookieCutter();
   	 c.CookieCutter("src/CookieCutter/B-large.in");
    }
    */
    
}