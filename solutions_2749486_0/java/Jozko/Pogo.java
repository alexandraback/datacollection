import java.io.*;

public class Pogo
{
    static int numberOfCases;
    static int x;
    static int y;
    public static void main() {
        try{
            BufferedReader reader = new BufferedReader(new FileReader("B-small-attempt0.in"));
            PrintWriter writer = new PrintWriter("BTU.in");
            String s = reader.readLine();
            numberOfCases = Integer.parseInt(s);
            String answer;
            for (int i = 0; i < numberOfCases; i++) {
                intialize(reader);
                
                
                
                answer = solve(x, y, 1);
                
                System.out.println("Case " + (1+i) + " " + x + " " + y + " " + answer);
                 
                writer.print("Case #" + (i + 1) + ": " + answer);
                if (i != numberOfCases - 1) writer.println();
            }
            writer.flush();
        }catch(Exception e){e.printStackTrace();}
        System.out.println("CHA!");
    }
    
    public static String solve(int xx, int yy, int step) {
        String ret = "";
        if (xx > 0) {
            for (int i = 0; i < xx; i++) { 
                
                ret += "WE";
            }
        }
        else if (xx < 0) {
            for (int i = 0; i < -xx; i++) { 
                
                ret += "EW";
            }
        }
        
        if (yy > 0) {
            for (int i = 0; i < yy; i++) { 
                
                ret += "SN";
            }
        }
        else if (yy < 0) {
            for (int i = 0; i < -yy; i++) { 
                ret += "NS";
            }
        }
        
        return ret;
    }

    public static void intialize(BufferedReader reader) {
        try{
            String[] data = reader.readLine().split(" ");
            x = Integer.parseInt(data[0]);
            y = Integer.parseInt(data[1]);
            

        }catch(Exception e) {e.printStackTrace();}
    }

    

}
