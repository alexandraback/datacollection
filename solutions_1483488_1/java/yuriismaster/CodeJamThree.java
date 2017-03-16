import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by IntelliJ IDEA.
 * User: nickg
 * Date: 4/13/12
 * Time: 9:57 PM
 * To change this template use File | Settings | File Templates.
 */
public class CodeJamThree {
    public static int numNumbers(int a, int b){
        int digits = (int) Math.log10(b);
        digits++;
        Set<Integer> seen = new HashSet<Integer>();
        int total = 0;
        for(int x = a; x < b; x++){
            int pow = 10;
            seen.clear();
            for(int y = 1; y < digits; y++){
                int moved = move(x, pow);
                pow*= 10;
                if(moved <= b && moved > x)
                    seen.add(moved);
            }
            total+= seen.size();
        }
        return total;
    }

    public static int move(int src, int pow){
        int smallPart = src / pow;
        int bigPart = src % pow;
        int factor =  (int) Math.log10(smallPart) + 1;
        pow = (int) Math.pow(10, factor);
        return bigPart * pow + smallPart;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numTrials = scanner.nextInt();
        for(int i = 0; i < numTrials; i++){
            int i1 = numNumbers(scanner.nextInt(), scanner.nextInt());
            System.out.println("Case #" + (i+1) + ": " + i1);
        }
    }
}
