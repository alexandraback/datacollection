import java.io.*;
import java.util.Arrays;
import java.util.HashMap;

/**
 * Created by IntelliJ IDEA.
 * User: yc14rp1
 * Date: 5/5/12
 * Time: 9:03 AM
 * To change this template use File | Settings | File Templates.
 */
public class Test11 {

    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\YC14rp1\\Downloads\\a00.in";
        try {
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
            for (int t = 1; t <= n; t++) {
                strLine = br.readLine();
                String[] split = strLine.split(" ");
                int k = Integer.valueOf(split[0]);
                int[] scores = new int[k];
                int[] idx = new int[k];
                float sum = 0;
                for (int i = 0; i < k; i++) {
                    scores[i] = Integer.valueOf(split[i + 1]);
                    idx[i] = i;
                    sum += scores[i];
                }
                System.out.println();
                System.out.print("Case #" + t + ": ");
                boolean flag = true;
                HashMap<Integer,Integer> idxs = new HashMap<Integer, Integer>();
                while (flag) {
                    flag = false;
                    for (int i = 0; i < k - 1; i++) {
                        if (scores[i] > scores[i + 1]) {
                            int r = scores[i];
                            scores[i] = scores[i + 1];
                            scores[i + 1] = r;
                            r = idx[i];
                            idx[i] = idx[i + 1];
                            idx[i + 1] = r;
//                            idxs.put(idx[i],i);
//                            idxs.put(idx[i+1],i+1);
                            flag = true;
                        }
                    }
                }
                for (int ci=0;ci<k;ci++) {
                    idxs.put(idx[ci],ci);
                }
                //System.out.println(Arrays.toString(scores));
                //System.out.println(Arrays.toString(idx));
                for (int i = 0; i < k; i++) {
                    long debt = 0;
                    long xn = 0;
                    //System.out.println(i);
                    int id;
                    id = idxs.get(i);
                    flag = false;
                    int cn = 0;
                    int c_sum = 0;
                    while (!flag) {
                        if (idx[cn]!=i) {
                            c_sum += scores[id]-scores[cn];
                            cn++;
                        } else {
                            flag = true;
                        }
                    }
                    float res = 0;
                    if (c_sum > sum) {
                        res = 0;
                    } else {
                        int cur_v = scores[id];
                        boolean has_debt = true;
                        float debt_left = sum - c_sum;
                        cn++;
                        while (has_debt && cn<k) {
                            int next = scores[cn];
                            int step = (cn) * (next - cur_v);
                            if (step < debt_left) {
                                debt_left = debt_left - step;
                                cur_v = next;
                                cn++;
                            } else {
                                has_debt = false;
                                res = (100*(cur_v-scores[id]+debt_left/(cn)))/sum;
                            }
                        }
                        if (has_debt) {
                            res = (100*(cur_v-scores[id]+debt_left/(cn)))/sum;
                        }
                    }
                    System.out.print(res + " ");
                }
                //System.out.println("Case #" + t + ": " + scores[k-1]);
            }
            //Close the input stream
            in.close();
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

}
