import java.io.*;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by IntelliJ IDEA.
 * User: YC14RP1
 * Date: 4/14/12
 * Time: 12:57 AM
 * To change this template use File | Settings | File Templates.
 */
public class Test3 {


    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\YC14rp1\\Downloads\\C-small-attempt0.in";
        try{
            // Open the file that is the first
            // command line parameter
            FileInputStream fstream = new FileInputStream(path);
            // Get the object of DataInputStream
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            //Read File Line By Line
            strLine = br.readLine();
            int n = Integer.valueOf(strLine);
            for (int i=1;i<=n;i++) {
                strLine = br.readLine();
                String[] split = strLine.split(" ");
                String s1 = split[0];
                long d1 = Long.valueOf(s1);
                String s2 = split[1];
                long d2 = Long.valueOf(s2);
                int res = 0;
                for (long j=d1;j<=d2;j++) {
                    Set<Long> cSet = new HashSet<Long>();
                    String ss = String.valueOf(j);
                    for (int k=0;k<s1.length()-1;k++) {
                        String s = ss.substring(k+1)+ss.substring(0,k+1);
                        Long r = Long.valueOf(s);
                        if ((r>j) && (r>=d1) && (r<=d2)) {
                            if (!cSet.contains(r)) {
                                //System.out.println(j+"/"+r);
                                res++;
                            }
                            cSet.add(r);
                            //res++;
                        }
                    }
                }
                // Print the content on the console
                System.out.println("Case #" + i + ": " + res);
            }
            //Close the input stream
            in.close();
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

}
