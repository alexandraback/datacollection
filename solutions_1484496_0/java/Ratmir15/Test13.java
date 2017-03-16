import java.io.*;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Created by IntelliJ IDEA.
 * User: yc14rp1
 * Date: 5/5/12
 * Time: 9:26 AM
 * To change this template use File | Settings | File Templates.
 */
public class Test13 {

    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\YC14rp1\\Downloads\\a0.in";
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
            for (int t=1;t<=n;t++) {
                strLine = br.readLine();
                String[] split = strLine.split(" ");
                int k = Integer.valueOf(split[0]);
                int [] num = new int[k];
                for (int i=0;i<k;i++) {
                    num[i] = Integer.valueOf(split[i+1]);
                }
                double nn = Math.pow(2,k);
                int i=0;
                boolean flag = true;
                Map<Long,Set<Integer>> m = new HashMap<Long,Set<Integer>>();
                while (i<nn && flag) {
                    double c = i;
                    Set<Integer> s = new HashSet<Integer>();
                    long sum = 0;
                    for (int z=0;z<k;z++) {
                        double b = c %2;
                        c = Math.round((c-b)/2);
                        if (b>0) {
                            s.add(num[z]);
                            sum += num[z];
                        }
                    }
                    //System.out.println(s);
                    if (m.containsKey(sum)) {
                        Set<Integer> set = m.get(sum);
                        if (!s.equals(set)) {
                            flag = false;
                            System.out.println("Case #" + t + ":");
                            String o = "";
                            for (Integer integer : set) {
                                o += integer+" ";
                            }
                            System.out.println(o);
                            o = "";
                            for (Integer integer : s) {
                                o += integer+" ";
                            }
                            System.out.println(o);
                        }
                    } else {
                        m.put(sum,s);
                    }
                    i++;
                }
                if (flag) {
                    System.out.println("Case #" + t + ": Impossible");
                }
            }
            //Close the input stream
            in.close();
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

}
