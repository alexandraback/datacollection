import java.io.*;

/**
 * Created by IntelliJ IDEA.
 * User: YC14RP1
 * Date: 4/14/12
 * Time: 12:29 AM
 * To change this template use File | Settings | File Templates.
 */
public class Test2 {

    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\YC14rp1\\Downloads\\B-small-attempt0.in";
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
                int k = Integer.valueOf(split[0]);
                int s = Integer.valueOf(split[1]);
                int m = Integer.valueOf(split[2]);
                int res = 0;
                int res2 = 0;
                for (int j=3;j<=2+k;j++) {
                    int score = Integer.valueOf(split[j]);
                    int c_m = score % 3;
                    if (score>3*m-3) {
                        res++;
                    } else {
                        if ((score-1>3*m-6) && (res2<s) && (m>=2)) {
                            //System.out.println(score-1);
                            //System.out.println(3*m-6);
                            res2++;
                        }
                    }
                }
                // Print the content on the console
                res = res + res2;
                System.out.println("Case #" + i + ": " + res);
            }
            //Close the input stream
            in.close();
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

}
