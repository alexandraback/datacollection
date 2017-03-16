import java.util.*;
import java.math.*;

public class Main {
    
    static double cal(boolean[] left, int[] speed, double[] pos, HashSet<Integer> checker) {
        int N = left.length;
        double result = 0;
        int low = -1, high = -1;
        double min = Double.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (left[i] != left[j]) {
                    continue;
                }
                if (pos[i] < pos[j] && speed[i] > speed[j]) {
                    double temp = (pos[j] - pos[i] - 5) / (speed[i] - speed[j]);
                    if (temp < min) {
                        min = temp;
                        low = j;
                        high = i;
                    }
                }
                else if (pos[i] > pos[j] && speed[i] < speed[j]) {
                    double temp = (pos[i] - pos[j] - 5) / (speed[j] - speed[i]);
                    if (temp < min) {
                        min = temp;
                        low = i;
                        high = j;
                    }
                }
            }
        }
        if (low == -1) {
            return -1;
        }
        if (min == 0) {
            if (checker.contains(low) || checker.contains(high)) {
                return result;
            }
            checker.add(low);
            checker.add(high);
        }
        else {
            checker.clear();
        }
        result += min;
        for (int i = 0; i < N; i++) {
            pos[i] += speed[i] * min;
        }
        left[high] = !left[high];
        boolean check = true;
        for (int i = 0; i < N; i++) {
            if (i == high || left[i] != left[high]) {
                continue;
            }
            if (Math.abs(pos[i] - pos[high]) < 5) {
                check = false;
                break;
            }
        }
        double increase = -1;
        if (check) {
            HashSet<Integer> copy = new HashSet<Integer>();
            for (int val : checker) {
                copy.add(val);
            }
            double temp = cal(Arrays.copyOf(left, N), Arrays.copyOf(speed, N), Arrays.copyOf(pos, N), copy);
            if (temp < 0) {
                return temp;
            }
            increase = temp;
        }
        
        check = true;
        left[high] = !left[high];
        left[low] = !left[low];

        for (int i = 0; i < N; i++) {
            if (i == low || left[i] != left[low]) {
                continue;
            }
            if (Math.abs(pos[i] - pos[low]) < 5) {
                check = false;
                break;
            }
        }
        
        if (check) {
            HashSet<Integer> copy = new HashSet<Integer>();
            for (int val : checker) {
                copy.add(val);
            }
            double temp = cal(Arrays.copyOf(left, N), Arrays.copyOf(speed, N), Arrays.copyOf(pos, N), copy);
            if (temp < 0) {
                return temp;
            }
            if (increase < 0) {
                increase = temp;
            }
            else {
                increase = Math.min(increase, temp);
            }
        }
        
        if (increase < 0) {
            return result;
        }
        return result + increase;
    }
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int task = scan.nextInt();
        scan.nextLine();
        int current = 1;
        while(task-- > 0)
        {
            int N = scan.nextInt();
            scan.nextLine();
            boolean[] left = new boolean[N];
            int[] speed = new int[N];
            double[] pos = new double[N];
            
            for (int i = 0; i < N; i++) {
                left[i] = scan.next().charAt(0) == 'L';
                speed[i] = scan.nextInt();
                pos[i] = scan.nextInt();
            }
            double result = cal(left, speed, pos, new HashSet<Integer>());
            System.out.println("Case #" + current + ": " + (result < 0 ? "Possible" : result));
            current++;
        }
    }
}