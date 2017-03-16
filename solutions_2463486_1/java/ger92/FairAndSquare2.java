/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.text.DecimalFormat;
import java.util.Scanner;

/**
 *
 * @author German
 */
public class FairAndSquare2 {

    public static void main(String[] args) {
        String[] chanchada = {"000000000000001", "000000000000004", "000000000000009",
            "000000000000121", "000000000000484", "000000000010201", "000000000012321",
            "000000000014641", "000000000040804", "000000000044944", "000000001002001",
            "000000001234321", "000000004008004", "000000100020001", "000000102030201",
            "000000104060401", "000000121242121", "000000123454321", "000000125686521",
            "000000400080004", "000000404090404", "000010000200001", "000010221412201",
            "000012102420121", "000012345654321", "000040000800004", "001000002000001",
            "001002003002001", "001004006004001", "001020304030201", "001022325232201",
            "001024348434201", "001210024200121", "001212225222121", "001214428244121",
            "001232346432321", "001234567654321", "004000008000004", "004004009004004"};

        // DecimalFormat d = new DecimalFormat("00000000000000");
        Scanner in = new Scanner(System.in);
        int casos = in.nextInt();
        in.nextLine();
        for (int i = 0; i < casos; i++) {
            int posMin = 0;
            String[] nums = in.nextLine().split(" ");
            String num1 = padLeft(nums[0]);
            String num2 = padLeft(nums[1]);
            while (posMin < chanchada.length && num1.compareTo(chanchada[posMin]) > 0) {
                posMin++;
            }
            int posMax = posMin;
            while (posMax < chanchada.length && num2.compareTo(chanchada[posMax]) >= 0) {
                posMax++;
            }
            System.out.println("Case #"+(i+1)+": "+(posMax-posMin));
          }
    }

    public static String padLeft(String s) {
        return String.format("%1$15s", s).replace(" ", "0");
    }
}
