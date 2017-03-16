import java.io.*;

/**
 * Created by IntelliJ IDEA.
 * User: YC14RP1
 * Date: 4/13/12
 * Time: 11:57 PM
 * To change this template use File | Settings | File Templates.
 */
public class Test {

    public static final String S_1 = "abcdefghijklmnopqrstuvwxyz";
    public static final String S_2 = "ynficwlbkuomxsevzpdrjgthaq";

    public static String decode(String x) {
        String res = "";
        for (int i=0;i<x.length();i++) {
            int i1 = S_2.indexOf(x.substring(i, i + 1));
            if (i1>-1) {
            res += S_1.substring(i1,i1+1);}
            else {
                res += " ";
            }
        }
        return res;        
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\YC14rp1\\Downloads\\A-small-attempt2.in";
        try{
            // Open the file that is the first
            // command line parameter
            FileInputStream fstream = new FileInputStream(path);
            // Get the object of DataInputStream
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            int i = 0;
            //Read File Line By Line
            strLine = br.readLine();
            while ((strLine = br.readLine()) != null)   {
                i++;
                // Print the content on the console
                System.out.println ("Case #"+i+": "+decode(strLine));
            }
            //Close the input stream
            in.close();
    } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }
}
