import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Created by yilinhe on 4/10/15. All right reserved.
 */
public class StandingOvation {

    public static int calculate(String line){
        String[] info = line.split(" ");
        int[] people = new int[Integer.valueOf(info[0])+1];
        int i = 0;
        for (char c : info[1].toCharArray()){
            people[i++] = Integer.valueOf(c)-48;
        }
        int needed = 0;
        int sum = 0;
        for (i =0;i<people.length;i++){
            if (sum < i){
                sum++;
                needed++;
            }
            sum+=people[i];
        }
        return needed;
    }

    public static void main(String args[]) throws FileNotFoundException {
        Scanner input = new Scanner(new FileInputStream( new File("p1large.txt")));
        int counter = 0;
        input.nextLine();
        while(input.hasNext()){
            String line = input.nextLine();
            int ans = calculate(line);
            System.out.printf("Case #%d: %d\n", ++counter, ans);
        }
    }
}
