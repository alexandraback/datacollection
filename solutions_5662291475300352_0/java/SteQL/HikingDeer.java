/**
 * Created by LaiQX on 05/02/15.
 *
 2
 2
 180 1 100000
 180 1 1
 1
 180 2 1
 */
import java.util.*;
import java.io.*;

public class HikingDeer {
    public static void main(String[] args) throws FileNotFoundException {
        File input = new File("src/C-small-1-attempt0.in");
        Scanner sc = new Scanner(input);
        PrintWriter wr = new PrintWriter("output4");
        int T = Integer.parseInt(sc.nextLine());
        for (int i = 0; i< T ; i++) {

            StringBuilder ans = new StringBuilder();
            ans.append("Case #"+(i+1)+": ");

            int N = Integer.parseInt(sc.nextLine());
            ArrayList<Hiker> hk_list = new ArrayList<Hiker>();

            int pos;
            int num;
            int spd;

            for (int j = 0; j<N ;j++) {
                String[] tmp = sc.nextLine().split(" ");
                pos = Integer.parseInt(tmp[0]);
                num = Integer.parseInt(tmp[1]);
                spd = Integer.parseInt(tmp[2]);
                for (int k = 0; k< num; k++) {
                    Hiker hk = new Hiker(pos,spd+k);
                    hk_list.add(hk);
                }
            }

//            for samll1
            Hiker hk1 = hk_list.get(0);
            Hiker hk2 = hk_list.get(1);
            double time_a_1 = (1-hk1.pos/360.0)*hk1.spd;

            double time_b_1 = (1-hk2.pos/360.0)*hk2.spd;

            if (time_a_1<time_b_1) {
                if ((time_b_1-time_a_1)<hk1.spd) {
                    ans.append("0");
                } else {
                    ans.append("1");
                }
            } else if (time_a_1==time_b_1) {
                ans.append("0");
            } else {
                if ((time_a_1-time_b_1)<hk2.spd) {
                    ans.append("0");
                } else {
                    ans.append("1");
                }
            }


            wr.println(ans);
            System.out.println("case # "+(i+1)+" done!");

        }
        wr.close();
    }
}
