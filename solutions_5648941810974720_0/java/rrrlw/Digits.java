import java.io.*;
import java.util.*;

public class Digits
{
    public static void main(String[] args) throws IOException
    {
        Scanner cin = new Scanner(new File("README.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("Digits.out"));
        int numTests = cin.nextInt();
        cin.nextLine();
        String temp;
        char[] tempArray;
        String keepTrack;
        for (int run=1; run<=numTests; run++)
        {
            temp = cin.nextLine();
            keepTrack = "";
            while (temp.indexOf("Z")!=-1)
            {
                temp = remove(temp, "ZERO");
                keepTrack += "0";
            }
            while (temp.indexOf("W")!=-1)
            {
                temp = remove(temp, "TWO");
                keepTrack += "2";
            }
            while (temp.indexOf("U")!=-1)
            {
                temp = remove(temp, "FOUR");
                keepTrack += "4";
            }
            while (temp.indexOf("X")!=-1)
            {
                temp = remove(temp, "SIX");
                keepTrack += "6";
            }
            while (temp.indexOf("F")!=-1)
            {
                temp = remove(temp, "FIVE");
                keepTrack += "5";
            }
            while (temp.indexOf("O")!=-1)
            {
                temp = remove(temp, "ONE");
                keepTrack += "1";
            }
            while (temp.indexOf("V")!=-1)
            {
                temp = remove(temp, "SEVEN");
                keepTrack += "7";
            }
            while (temp.indexOf("G")!=-1)
            {
                temp = remove(temp, "EIGHT");
                keepTrack += "8";
            }
            while (temp.indexOf("R")!=-1)
            {
                temp = remove(temp, "THREE");
                keepTrack += "3";
            }
            while (temp.indexOf("N")!=-1)
            {
                temp = remove(temp, "NINE");
                keepTrack += "9";
            }
            tempArray = keepTrack.toCharArray();
            Arrays.sort(tempArray);
            out.println("Case #"+run+": "+ (new String(tempArray)));
        }
        out.close();
    }
    static String remove(String a, String rem)
    {
        for (int i=0; i<rem.length(); i++)
        {
            a = a.replaceFirst(""+rem.charAt(i),"");
        }
        return a;
    }
}