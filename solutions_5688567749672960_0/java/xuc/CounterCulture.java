package CounterCulture;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by xuchen on 5/2/15.
 */
public class CounterCulture {

    public static int reverse(int x) {
        if(x == Integer.MIN_VALUE) return 0;

        int result = 0, remainder = 0;

        boolean flag = (x > 0);

        x = Math.abs(x);


        while(x != 0){
            remainder = x%10;
            if(result > Integer.MAX_VALUE/10) return 0;
            if(result == Integer.MAX_VALUE/10 && ((remainder > 7 && flag) || (remainder > 8 && !flag)) ) return 0;
            result *= 10;
            result += remainder;
            x /= 10;
        }

        return (flag)?result:-result;
    }

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("src/CounterCulture/A-small-attempt0.in"));
            PrintWriter writer = new PrintWriter(new File("src/CounterCulture/result.txt"));

            int caseCnt = scanner.nextInt();

            for (int i = 0; i < caseCnt; i++){

                int length = scanner.nextInt() + 1;

                int[] arr = new int[length];

                for (int j = 1; j < length; j++){

                    if (arr[j] == 0){
                        arr[j] = arr[j-1] + 1;
                    }else {
                        arr[j] = Math.min(arr[j],arr[j-1] + 1);
                    }

                    int reversed = reverse(j);

                    if (reversed > j && reversed < length){

                        if (arr[reversed] == 0){
                            arr[reversed] = arr[j] + 1;
                        }else {
                            arr[reversed] = Math.min(arr[reversed],arr[j] + 1);
                        }

                    }

                }


                writer.println("Case #" + (i + 1) + ": " + arr[length-1]);
            }

            writer.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
