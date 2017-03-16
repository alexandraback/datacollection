import java.io.*;

public class Consonants
{
    static int numberOfCases;
    static String name;
    static int nValue;
    public static void main() {
        try{
            BufferedReader reader = new BufferedReader(new FileReader("A-large.in"));
            PrintWriter writer = new PrintWriter("TUSmallA.in");
            String s = reader.readLine();
            numberOfCases = Integer.parseInt(s);
            int answer;
            for (int i = 0; i < numberOfCases; i++) {
                intialize(reader);
                
                
                
                answer = solve(0, 0, 0);
                
                //System.out.println("Case " + (1+i) + " " + name + " " + nValue + " " + answer);
                 
                writer.print("Case #" + (i + 1) + ": " + answer);
                if (i != numberOfCases - 1) writer.println();
            }
            writer.flush();
        }catch(Exception e){e.printStackTrace();}
        System.out.println("CHA!");
    }
    
    public static int solve(int start, int numOfCons, int rStart) {
        int k = 0;
        for (int i = start; i < name.length(); i++) {
            if (isConsonant(name.charAt(i))) {
                numOfCons++;
                if (numOfCons == nValue) {
                    int pos = (name.length() - i)*(i-rStart - (nValue - 1) +1);
                    k = k + pos;
                    //System.out.println(name.charAt(i) + " " + pos + " " + rStart);
                    numOfCons--;
                    rStart = i - nValue + 2;
                    //return solve(i + 1, numOfCons - 1, i - nValue + 2) + pos;
                }
            }
            else {numOfCons = 0;}
        }
        
        return k;
    }
    
    public static boolean isConsonant(char c) {
        int val =  "aeiou".indexOf(c);
        return val == -1;
    }

    public static void intialize(BufferedReader reader) {
        try{
            String[] data = reader.readLine().split(" ");
            name = (data[0]);
            nValue = Integer.parseInt(data[1]);
            

        }catch(Exception e) {e.printStackTrace();}
    }

    

}
