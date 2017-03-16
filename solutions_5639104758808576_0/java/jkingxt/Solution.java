
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.Stack;

public class Solution {
    public int reverse(int x) {
        int sum = 0;
        while (x != 0) {
            if (sum > 0) {
                if (Integer.MAX_VALUE / sum < 10 || (Integer.MAX_VALUE / sum == 10 && Integer.MAX_VALUE % 10 < x % 10)) {
                    return 0;
                }
            }
            else if (sum < -10) {
                if (Integer.MIN_VALUE / sum < 10 || (Integer.MIN_VALUE / sum == 10 && Integer.MIN_VALUE % 10 > x % 10)) {
                    return 0;
                }
            }
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        
        return sum;
    }
} 