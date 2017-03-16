import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class A2 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        String[] strs = {"TWO", "ZERO", "SIX", "SEVEN", "FIVE", "FOUR", "EIGHT", "THREE", "NINE", "ONE"};
        char[] sps = {'W', 'Z', 'X', 'S', 'V', 'F', 'G', 'H', 'I', 'O'};
        int[] vals = {2, 0, 6, 7, 5, 4, 8, 3, 9, 1};
        int t = sc.nextInt();
        String s = sc.nextLine();
        for (int i = 0; i < t; i++) {
            System.out.print("Case #" + (i+1) + ": ");
            s = sc.nextLine();
            int[] count = new int[27];
            int[] res = new int[10];
            for (int j = 0; j < s.length(); j++) {
                count[s.charAt(j) - 'A']++;
            }
            for (int j = 0; j < strs.length; j++) {
                int temp = count[sps[j] - 'A'];
                
                boolean flag = false;
                for (int k = 0; k < strs[j].length(); k++) {
                    if (count[strs[j].charAt(k) - 'A'] - temp < 0) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    continue;
                }
                for (int k = 0; k < strs[j].length(); k++) {
                    count[strs[j].charAt(k) - 'A'] -= temp;
                }
                res[vals[j]] += temp;
            }
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < res[j]; k++) {
                    System.out.print(j);
                }
            }
            System.out.println();
        }
        sc.close();
    }
}
