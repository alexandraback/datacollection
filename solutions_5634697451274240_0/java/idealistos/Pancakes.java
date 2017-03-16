package shutovich;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.*;

/**
 * Created by U on 4/9/2016.
 */
public class Pancakes {
    static class LongBinary {
        // Number is (u << 64) | l
        long u = 0;
        long l = 0;
        int size = 0;

        LongBinary(LongBinary lb) {
            u = lb.u;
            l = lb.l;
            size = lb.size;
        }

        LongBinary(String s) {
            size = s.length();
            l = getBits(s, 0);
            if (size > 64) {
                u = getBits(s, 64);
            }
        }

        long getBits(String s, int offset) {
            long b = 1;
            long result = 0;
            for (int p = offset; p < Math.min(size, offset + 64); p++) {
                if (s.charAt(p) == '+') {
                    result |= b;
                }
                b <<= 1;
            }
            return result;
        }

        static int getInversionCount(long x, int length) {
            boolean bit = true;
            long b = 1l << (length - 1);
            int inversionCount = 0;
            for (int i = 0; i < length; i++) {
                boolean bit1 = (x & b) != 0l;
                if (bit1 != bit) {
                    inversionCount++;
                }
                bit = bit1;
                b >>>= 1l;
            }
            return inversionCount;
        }

        int getInversionCount() {
            if (size <= 64) {
                return getInversionCount(l, size);
            } else {
                return getInversionCount(l, 64) + getInversionCount(u, size - 64)
                        + (((u & 1l) == 1l)? 0 : 1);
            }
        }

        boolean getBit(int i) {
            if (i < 64) {
                return (l & (1l << i)) != 0;
            } else {
                return (u & (1l << (i - 64))) != 0;
            }
        }

        void setBit(int i, boolean bit) {
            if (i < 64) {
                long b = 1l << i;
                if (((l & b) != 0) != bit) {
                    l ^= b;
                }
            } else {
                long b = 1l << (i - 64);
                if (((u & b) != 0) != bit) {
                    u ^= b;
                }
            }
        }

        LongBinary flip(int i) {
            LongBinary lb = new LongBinary(this);
            for (int j = 0; j < i; j++) {
                lb.setBit(i - j - 1, !getBit(j));
            }
            return lb;
        }

        @Override
        public boolean equals(Object o) {
            return (o instanceof LongBinary) && ((LongBinary) o).l == l && ((LongBinary) o).u == u;
        }

        @Override
        public int hashCode() {
            return new Long(l).hashCode() ^ new Long(u * 31).hashCode();
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < size; i++) {
                sb.append(getBit(i)? '+' : '-');
            }
            return sb.toString();
        }

    }

    static int getFlipCount(String s) {
        LongBinary lb = new LongBinary(s);
        Set<LongBinary> visited = new HashSet<>(Arrays.asList(lb));
        List<LongBinary> queue = new ArrayList<>(Arrays.asList(lb));
        List<Integer> flipCounts = new ArrayList<>(Arrays.asList(0));
        int index = 0;
        int inversionCount = lb.getInversionCount();
        if (inversionCount == 0) {
            return 0;
        }
        while (index < queue.size()) {
            LongBinary lb1 = queue.get(index);
            for (int i = 1; i <= lb1.size; i++) {
                LongBinary lb2 = lb1.flip(i);
                int inversionCount2 = lb2.getInversionCount();
                if (inversionCount2 == 0) {
                    return flipCounts.get(index) + 1;
                }
                if ((inversionCount2 < inversionCount || inversionCount2 < 3) && !visited.contains(lb2)) {
                    if (inversionCount2 < inversionCount) {
                        System.out.println("" + inversionCount2 + ": " + lb2);
                    }
                    inversionCount = Math.min(inversionCount, inversionCount2);
                    visited.add(lb2);
                    queue.add(lb2);
                    flipCounts.add(flipCounts.get(index) + 1);
                }
            }
            index++;
        }
        return -1;
    }

    static int getFlipCount2(String s) {
        return new LongBinary(s).getInversionCount();
    }

    static int getFlipCount3(String s) {
        int flipCount = 0;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = (i == s.length() - 1)? '+' : s.charAt(i + 1);
            flipCount += (c1 != c2)? 1 : 0;
        }
        return flipCount;
    }

    public static void main(String[] args) throws IOException{
        List<String> lines = Files.readAllLines(new File("input2").toPath());
        int count = Integer.parseInt(lines.get(0));
        List<String> resultLines = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            int flipCount = getFlipCount3(lines.get(i + 1));
            resultLines.add("Case #" + (i + 1) + ": " + flipCount);
        }
        Files.write(new File("output2").toPath(), resultLines);
    }

}
