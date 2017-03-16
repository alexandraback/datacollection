import java.io.BufferedReader;
import java.io.FileReader;

/**
 * Created with IntelliJ IDEA.
 * User: skhan
 * Date: 2013-04-27
 * Time: 10:40 AM
 * To change this template use File | Settings | File Templates.
 */
public class codejam {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(args[0]));

            int cases = Integer.parseInt(br.readLine());
            for (int i = 1; i < cases + 1; ++i) {
                String line = br.readLine();
                String[] split = line.split(" ");
                long r = Long.parseLong(split[0]);
                long t = Long.parseLong(split[1]);
                long y = 0;
                while (true) {
                    long thisGo = (r+1)*(r+1) - r*r;
                    if (t < thisGo) break;
                    y+=1;
                    r+=2;
                    t-=thisGo;
                }
                System.out.println("Case #" + i + ": " + y);
            }

            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
