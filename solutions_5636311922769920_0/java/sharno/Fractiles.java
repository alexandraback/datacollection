import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created by mohamedelsharnouby on 4/9/2016.
 */
public class Fractiles {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();
        for (int z = 1; z <= t; ++z) {
            int K = in.nextInt();
            int C = in.nextInt();
            int S = in.nextInt();

//            for (long i = 0; i < K; i++) {
                // build the binary representing G as 1
//                String original = Long.toBinaryString((long) Math.pow(2, i));
//                for(int j = original.length(); j < K; j++) {
//                    original = "0".concat(original);
//                }

//                ArrayList<Boolean> original2 = new ArrayList<>();
//                for (char c : original.toCharArray()) {
//                    if (c == '1') original2.add(true);
//                    else original2.add(false);
//                }
//
//                ArrayList<Boolean> binary = new ArrayList<>();
//                for (boolean b : original2) {
//                    binary.add(b);
//                }
//                ArrayList<Boolean> gold = new ArrayList<>(K);
//                for (int j = 0; j < K; j++) {
//                    gold.add(true);
//                }
//
//                // grow the pattern
//                for (int j = 1; j < C; j++) {
//                    ArrayList<Boolean> temp = new ArrayList<>();
//                    for (boolean b : binary) {
//                        if (b == true) {
//                            temp.addAll(gold);
//                        } else {
//                            temp.addAll(original2);
//                        }
//                    }
//                    binary = temp;
//                    System.out.println(binary);
//                }
//            }

            System.out.print("Case #" + z + ":");
            for (int i = 0; i < K; i++) {
                System.out.print(" " + ( i * (long)Math.pow(K, C-1) + 1));
            }
            System.out.println();
        }
    }
}
