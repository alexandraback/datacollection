package problemb;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 *
 * @author huls
 */
public class ProblemB {

    private static String fileName = ProblemB.class.getSimpleName().replaceFirst("_.*", "");
    private static String inputFileName = fileName + ".in";
    private static String outputFileName = fileName + ".out";
    private static Scanner in;
    private static PrintWriter out;
    
    private static int numberOfTests;
    
    private static String[] compass = {"N","S","E","W"};
    private static String oneSouth = "NS";
    private static String oneNorth = "SN";
    private static String oneEast = "WE";
    private static String oneWest = "EW";
    
    private int getDistance(int currentX, int targetX){
        int val = 0;
        if(currentX>=0 && targetX>=0){
            val = Math.abs(targetX-currentX);
        }else if(currentX<0 && targetX>=0){
            val = Math.abs(currentX)+targetX;
        }else if(currentX>=0 && targetX<0){
            val = currentX+ Math.abs(targetX);
        }else{
            val = Math.abs(Math.abs(currentX)-Math.abs(targetX));
        }
        return val;
    }
    
    public String solve(){
        String sol = "";
        int targetX = in.nextInt();
        int targetY = in.nextInt();
        
        int tempX = targetX;
        int tempY = targetY;
        int currentX = 0;
        int currentY = 0;
        int stepSize = 1;
        int distX = 0;
        int distY = 0;
        while(!(currentX==targetX && currentY==targetY)){
            distX = getDistance(currentX, targetX);
            distY = getDistance(currentY, targetY);
            if(distX>distY){
                if(distX<stepSize){
                    if(currentX<targetX){
                        for (int i = 0; i < distX; i++) {
                            sol += oneEast;  
                        }
                        currentX=targetX;
                    }else{
                        for (int i = 0; i < distX; i++) {
                            sol += oneWest;  
                        }
                        currentX=targetX;
                    }
                }else{
                    if(currentX<targetX){
                        sol += "E";
                        currentX +=stepSize;
                    }else{
                        sol += "W";
                        currentX -= stepSize;
                    }
                }
            }else{
                if(distY<stepSize){
                    if(currentY<targetY){
                        for (int i = 0; i < distY; i++) {
                            sol += oneNorth;  
                        }
                        currentY=targetY;
                    }else{
                        for (int i = 0; i < distY; i++) {
                            sol += oneSouth;  
                        }
                        currentY=targetY;
                    }
                }else{
                    if(currentY<targetY){
                        sol += "N";
                        currentY +=stepSize;
                    }else{
                        sol += "S";
                        currentY -= stepSize;
                    }
                }
            }
            stepSize++;
        }
        return sol;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
         Locale.setDefault(Locale.US);
        if (args.length >= 2) {
                inputFileName = args[0];
                outputFileName = args[1];
        }
        in = new Scanner(new FileReader(inputFileName));
        out = new PrintWriter(outputFileName);
        numberOfTests = in.nextInt();
        
        for (int t = 1; t <= numberOfTests; t++) {
            System.out.println(t);
            out.print("Case #" + t + ": ");
            out.print(new ProblemB().solve()+"\n");
        }
        in.close();
        out.close();
    }
}
