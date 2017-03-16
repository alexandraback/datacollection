package qr16;

import java.io.*;

/**
 * Created by dzhang on 5/4/16.
 */
public class A {
//    private static final String MODE = "sample";
    private static final String MODE = "small-attempt0";
//    private static final String MODE = "large";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("in/" + A.class.getPackage().getName() + "/" + A.class.getSimpleName() + "-" + MODE + ".in"));

        File outFile = new File("out/" + A.class.getPackage().getName() + "/" + A.class.getSimpleName() + "-" + MODE + ".out");
        outFile.createNewFile();
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));

        A solution = new A();

        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t ++){
            long num = Long.parseLong(br.readLine());
            String output = solution.solve(num);
            System.out.printf("Case #" + t + ": " + output + "\n");
            bw.write("Case #" + t + ": " + output + "\n");
        }
        br.close();
        bw.close();
    }

    private String solve(long num) {
        if(num == 0){
            return "INSOMNIA";
        }
        boolean[] nums = new boolean[10];
        int count = 1;
        for (; !finish(nums); count ++){
            calculate(nums, num * count);
        }
        return String.valueOf(num * (count - 1));
    }

    private void calculate(boolean[] nums, long num) {
        while (num > 0){
            nums[(int)(num % 10)] = true;
            num /= 10;
        }
    }

    private boolean finish(boolean[] nums) {
        for (boolean num : nums){
            if (!num){
                return false;
            }
        }
        return true;
    }

}
