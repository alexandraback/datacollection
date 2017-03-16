/**
 * Created by homulerdora on 3/31/14.
 */
import java.math.BigDecimal;
import java.util.*;
import java.io.*;

public class A {

    public static void main(String[] args){
        try {
            new A().solve();
        } catch (IOException e){
            e.printStackTrace();
            System.exit(1);
        }
    }

    public int getGen(long denom, long num){
        if(num == 0){
            return 0;
        }
        int count = 0;
        while(denom > num){
            if(denom%2 != 0){
                return -1000000000;
            }
            denom /= 2;
            count++;
        }
        num -= denom;
        if(num == 0){
            return count;
        }
        count = Math.min(count, count+getGen(denom, num));
        return count;
    }

    public void solve() throws IOException {
        try(BufferedReader br = new BufferedReader(new FileReader("A.in"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("A-output.txt"))
        ){

            int T = Integer.parseInt(br.readLine());
            for (int i = 1; i <= T; i++){
                String[] str = br.readLine().split("/");
                long num = Long.parseLong(str[0]);
                long denom = Long.parseLong(str[1]);
                int ans = getGen(denom, num);
                bw.write("Case #" + i + ": ");
                if(ans >= 0){
                    bw.write(ans + "\n");
                } else {
                    bw.write("impossible\n");
                }
            }
        }
    }

    public int[] nextInts(BufferedReader br) throws IOException {
        String[] strs = br.readLine().split(" ");
        int[] ret = new int[strs.length];
        for(int i = 0; i < ret.length; i++){
            ret[i] = Integer.parseInt(strs[i]);
        }
        return ret;
    }
}
