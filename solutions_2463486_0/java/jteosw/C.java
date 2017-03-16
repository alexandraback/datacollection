import java.util.*;
public class C{
    static Scanner s;
    static Set<Long> nums;
    public static void main(String[] args){
        nums = new TreeSet<Long>();

        nums.add(1L);
        nums.add(2L);
        nums.add(3L);
        nums.add(11L);
        nums.add(22L);
        nums.add(101L);
        nums.add(111L);
        nums.add(121L);
        nums.add(202L);
        nums.add(212L);
        nums.add(1001L);
        nums.add(1111L);
        nums.add(2002L);
        nums.add(10001L);
        nums.add(10101L);
        nums.add(10201L);
        nums.add(11011L);
        nums.add(11111L);
        nums.add(11211L);
        nums.add(20002L);
        nums.add(20102L);
        nums.add(100001L);
        nums.add(101101L);
        nums.add(110011L);
        nums.add(111111L);
        nums.add(200002L);
        nums.add(1000001L);
        nums.add(1001001L);
        nums.add(1002001L);
        nums.add(1010101L);
        nums.add(1011101L);
        nums.add(1012101L);
        nums.add(1100011L);
        nums.add(1101011L);
        nums.add(1102011L);
        nums.add(1110111L);
        nums.add(1111111L);
        nums.add(2000002L);
        nums.add(2001002L);
        nums.add(10000001L);
        nums.add(10011001L);
        nums.add(10100101L);
        nums.add(10111101L);
        nums.add(11000011L);
        nums.add(11011011L);
        nums.add(11100111L);
        nums.add(11111111L);
        nums.add(20000002L);
        nums.add(100000001L);
        nums.add(100010001L);
        nums.add(100020001L);
        nums.add(100101001L);
        nums.add(100111001L);
        nums.add(100121001L);
        nums.add(101000101L);
        nums.add(101010101L);
        nums.add(101020101L);
        nums.add(101101101L);
        nums.add(101111101L);
        nums.add(110000011L);
        nums.add(110010011L);
        nums.add(110020011L);
        nums.add(110101011L);
        nums.add(110111011L);
        nums.add(111000111L);
        nums.add(111010111L);
        nums.add(111101111L);
        nums.add(111111111L);
        nums.add(200000002L);
        nums.add(200010002L);
        nums.add(1000000001L);
        nums.add(1000110001L);
        nums.add(1001001001L);
        nums.add(1001111001L);
        nums.add(1010000101L);
        nums.add(1010110101L);
        nums.add(1011001101L);
        nums.add(1011111101L);
        nums.add(1100000011L);
        nums.add(1100110011L);
        nums.add(1101001011L);
        nums.add(1101111011L);
        nums.add(1110000111L);
        nums.add(1110110111L);
        nums.add(1111001111L);
        nums.add(2000000002L);
        s = new Scanner(System.in);
        int rounds = s.nextInt();
        for(int i = 1; i <= rounds; i++) {
            long min = s.nextLong();
            long max = s.nextLong();
            int result = play(min, max);
            System.out.printf("Case #%d: %d\n", i, result);
        }
    }

    public static int play(long min, long max) {
        int result = 0;
        for(Long curr : nums) {
            long num = curr * curr;
            if (num >= min && num <= max) {
                result++;
            } else if (num > max) {
                return result;
            }
        }
        return result;
    }
}


