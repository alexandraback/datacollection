import java.io.FileInputStream;
import java.util.*;
import java.math.*;

public class Main {
    
    static int[] toDigits(int val) {
        int count = 1;
        int temp = val / 10;
        while (temp > 0) {
            count++;
            temp /= 10;
        }
        int[] arr = new int[count];
        temp = val;
        for (int i = 0; i < arr.length; i++) {
            arr[i] = temp % 10;
            temp /= 10;
        }
        return arr;
    }
    
    static int toInt(int[] digits) {
        int res = 0;
        int p = 1;
        for (int i = 0; i < digits.length; i++) {
            res += p * digits[i];
            p *= 10;
        }
        return res;
    }
    
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(System.in);
        //Scanner scan  = new Scanner(new FileInputStream("C:\\Users\\wd\\Desktop\\"));
        char[] map = "yhesocvxduiglbkrztnwjpfmaq".toCharArray();
        int taskCount = scan.nextInt();
        scan.nextLine();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            int A = scan.nextInt();
            int B = scan.nextInt();
            long result = 0;
            for (int i = A; i <= B; i++) {
                HashSet<Integer> checker = new HashSet<Integer>();
                int[] base = toDigits(i);
                int[] copy = new int[base.length];
                for (int j = 0; j < base.length; j++) {
                    int index = base.length - 1;
                    for (int k = j; k >= 0; k--) {
                        copy[index--] = base[k];
                    }
                    for (int k = base.length - 1; k > j; k--) {
                        copy[index--] = base[k];
                    }
                    int convert = toInt(copy);
                    if (convert <= i || convert > B || checker.contains(convert)) {
                        continue;
                    }
                    //System.out.println(i + " " + convert);
                    checker.add(convert);
                    result++;
                }
            }
            System.out.println("Case #" + taskIndex + ": " + result);
        }
    }
}