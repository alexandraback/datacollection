import java.util.Scanner;

/**
 * Created by james on 16/04/10.
 */
public class CoinJam {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        int N = in.nextInt();
        int J = in.nextInt();
        System.out.println("Case #1:");
        String s;
        int count = 0;
        for(int i = 0; i < Math.pow(2, N); i++){
            s = Integer.toString(i, 2);
            s = new String(new char[N - 2 - s.length()]).replace("\0", "0") + s;
            s = "1" + s + "1";
            long num = Long.valueOf(s);
            long divs[] = new long[9];
            for(int j = 2; j <= 10; j++){
                long basej = Long.valueOf("" +num, j);
                long result = prime(basej);
                if(result == -1)
                    break;
                else
                    divs[j - 2] = result;
            }
            if(divs[8] > 0){
                System.out.print(s);
                for(int j = 0; j < divs.length; j++)
                    System.out.print(" " + divs[j]);
                System.out.println();
                count++;
                if(count >= J)
                    return;
            }
        }

    }
    public static long prime(long num){
        if(num <= 2)
            return -1;
        if(num % 2 == 0)
            return 2;
        for(int i = 3; i < Math.sqrt(num); i+=2){
            if(num % i == 0)
                return i;
        }
        return -1;
    }
}
