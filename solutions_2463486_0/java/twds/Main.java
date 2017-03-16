import java.util.*;

public class Main {
    
    static void v1(ArrayList<Long> list, int val) {
        String base = Integer.toString(val);
        StringBuilder builder = new StringBuilder();
        for (int i = base.length() - 1; i >= 0; i--) {
            builder.append(base.charAt(i));
        }
        String tail = builder.toString();
        v2(list, Long.parseLong(base + tail));
        for (char c = '0'; c <= '9'; c++) {
            v2(list, Long.parseLong(base + c + tail));
        }
    }
    
    static void v2(ArrayList<Long> list, long val) {
        long res = val * val;
        String str = Long.toString(res);
        for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
            if (str.charAt(i) != str.charAt(j)) {
                return;
            }
        }
        list.add(res);
    }
    
    public static void main(String[] args) throws Exception {
        ArrayList<Long> list = new ArrayList<Long>();
        for (int i = 0; i < 9; i++) {
            v2(list, i);
        }
        for (int i = 1; i <= 1000; i++) {
            v1(list, i);
        }
        long[] arr = new long[list.size()];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = list.get(i);
        }
        Scanner scan = new Scanner(System.in);
        int taskCount = scan.nextInt();
        scan.nextLine();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            long A = scan.nextLong();
            long B = scan.nextLong();
            int res = 0;
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] >= A && arr[i] <= B) {
                    res++;
                }
            }
            System.out.println(String.format("Case #%d: %d", taskIndex, res));
        }
    }
}
