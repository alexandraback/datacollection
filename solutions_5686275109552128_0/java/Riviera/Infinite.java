import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Created by yilinhe on 4/10/15. All right reserved.
 */
public class Infinite {

    public static int getTime(List<Integer>p, int max){
        int splitTime = 0;
        for (int plate : p){
            splitTime+= plate/max;
            if (plate % max == 0){
                splitTime--;
            }
        }
        return splitTime+max;
    }

    public static int calculate(int d, List<Integer> p){
        Collections.sort(p);
        List<Integer> results = new ArrayList<>();
        for (int i = p.get(p.size()-1);i>0;i--){
            results.add(getTime(p, i));
        }
        Collections.sort(results);
        return results.get(0);
    }

    public static void main(String args[]) throws IOException {
        Scanner input = new Scanner(new FileInputStream( new File("p2small.txt")));
        FileWriter output = new FileWriter("p2.small.result");
        int counter = 1;
        input.nextLine();
        while(input.hasNext()){
            int d = input.nextInt();
            List<Integer> p = new ArrayList<>();
            for (int i = 0;i<d;i++){
                p.add(input.nextInt());
            }
            int ans = calculate(d,p);
            System.out.print("Case #" + counter++ + ": " + ans + "\n");
        }
    }
}
