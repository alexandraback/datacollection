import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


public class BrutalForce {

    public static void main(String[] args) throws FileNotFoundException {
        //String fileName = "test";
        //String fileName = "C-small-attempt0";
        String fileName = "C-large-1";

        String inFile = fileName + ".in";
        String outFile = fileName + ".out";
                
        Scanner in = new Scanner(new FileInputStream(inFile));
        PrintStream out = new PrintStream(outFile);
        
        int T = in.nextInt();
       
        List<Long> A = new ArrayList<Long>(T);
        List<Long> B = new ArrayList<Long>(T);
        
        long minA = 0;
        long maxB = 0;
        
        BigInteger sumRange = BigInteger.valueOf(0);
        
        for (int i = 1;  i <= T;  i++) {
            long Ai = in.nextLong();
            long Bi = in.nextLong();
            
            if (i == 1) {
                minA = Ai;
                maxB = Bi;
            } else {
                if (minA > Ai) minA = Ai;
                if (maxB < Bi) maxB = Bi;
            }
            
            A.add(Ai); 
            B.add(Bi);
            
            sumRange = sumRange.add(BigInteger.valueOf(Bi-Ai));
        }
        
        if (sumRange.compareTo(BigInteger.valueOf(maxB-minA)) < 0) {
            solutionAsParts(in, out, A, B);
        } else {
            solutionAsWhole(in, out, A, B, minA, maxB);
        }
    }
    
    private static void solutionAsParts(Scanner in, PrintStream out, List<Long> A, List<Long> B) {
        int T = A.size();
        
        long time = System.currentTimeMillis();
        for (int i = 1;  i <= T;  i++) {
            System.out.println("Solving case #" + i);
            
            out.print("Case #"+i+": ");
            
            long c = countFairAndSquare(A.get(i-1), B.get(i-1));
            out.print(c);
            
            out.println();
        }
        
        float timePerCase = (System.currentTimeMillis() - time) / 1000f;
        System.out.println(String.format("Speed: %.3f seconds", timePerCase));
    }
    
    private static void solutionAsWhole(Scanner in, PrintStream out, List<Long> A, List<Long> B, long minA, long maxB) {
        int T = A.size();
        
        long time = System.currentTimeMillis();
        
        System.out.println("Computing fair and square numbers...");
        List<Long> nums = getFairAndSquare(minA, maxB);
        
        for (long l : nums) {
            long sqrt = (long)Math.sqrt(l);
            System.out.println(l + "(" + sqrt + "), ");
        }
        
        for (int i = 1;  i <= T;  i++) {
            System.out.println("Solving case #" + i);
            
            out.print("Case #"+i+": ");
            
            long c = countFairAndSquare(A.get(i-1), B.get(i-1), nums);
            out.print(c);
            
            out.println();
        }
        
        float timePerCase = (System.currentTimeMillis() - time) / 1000f;
        System.out.println(String.format("Speed: %.3f seconds", timePerCase));
    }

    private static long countFairAndSquare(long A, long B) {
        long count = 0;
        for (FairNumber root : new RootNumberGenerator(A, B)) {
            long l = root.toLong();
            long sqr = l*l;
            if (A <= sqr && sqr <= B && root.isSquareFair()) count++;
        }
        return count;
    }
    
    private static long countFairAndSquare(long A, long B, List<Long> nums) {
        long count = 0;
        for (long l : nums) {
            if (l >= A && l <= B) count++;
        }
        return count;
    }
    
    private static List<Long> getFairAndSquare(long A, long B) {
        List<Long> result = new ArrayList<Long>();
        
        for (FairNumber root : new RootNumberGenerator(A, B)) {
            if (root.isSquareFair()) {
                long l = root.toLong();
                result.add(l*l);
            }
        }
        
        return result;
    }
    
    private static boolean isPalindrom(String s) {
        int l = s.length();
        int bound = s.length() / 2;
        
        for (int i = 0; i < bound; i++) {
            if (s.charAt(i) != s.charAt(l-i-1)) {
                return false;
            }
        }
        
        return true;
    }
    
    private static class RootNumberGenerator implements Iterable<FairNumber> {

        private long minRoot;
        private long maxRoot;
        
        private FairNumber candidate;
        
        private boolean isFirst = true;
        
        public RootNumberGenerator(long A, long B) {
            minRoot = (long)Math.floor(Math.sqrt(A));
            maxRoot = (long)Math.ceil(Math.sqrt(B));
            
            while (A < minRoot*minRoot) minRoot++;
            while (B > maxRoot*maxRoot) maxRoot++;
            
            candidate = new FairNumber(minRoot);
        }

        @Override
        public Iterator<FairNumber> iterator() {
            return new Iterator<FairNumber>() {
                @Override
                public boolean hasNext() {
                    return candidate.toLong() < maxRoot;
                }

                @Override
                public FairNumber next() {
                    if (!isFirst) 
                        candidate.increment();
                    else
                        isFirst = false;
                    
                    return candidate;
                }

                @Override
                public void remove() {
                }
            };
        }
    }
    
    private static class FairNumber {
        private boolean isOddLen;
        private int[] nums;
        
        private boolean isLongValid = false;
        private long longValue;
        
        public FairNumber(long num) {
            String s = Long.toString(num);
            isOddLen = ((s.length() % 2) == 1);
            
            int l = s.length();
            int b = (l + 1) / 2 - 1;
            nums = new int[b+1];
            for (int i = 0; i <= b; i++) nums[i] = s.charAt(i) - '0'; 
        }
        
        public boolean isSquareFair() {
            long l = this.toLong();
            long sqr = l*l;
            
            return isPalindrom(Long.toString(sqr));
        }
        
        public long toLong() {
            if (isLongValid) return longValue;
            isLongValid = true;
            
            long l = 0;
            long dec = 1;
            
            for (int i = 0; i < nums.length; i++) {
                l += dec * nums[i];
                dec *= 10;
            }
            
            int start = (isOddLen) ? nums.length-2 : nums.length-1;
            for (int i = start; i >= 0; i--) {
                l += dec * nums[i];
                dec *= 10;
            }
            
            longValue = l;
            return longValue;
        }
        
        public void increment() {
            increment(nums.length-1);
            isLongValid = false;
        }
        
        private void increment(int place) {
            int d = nums[place];
            
            if (d < 9) {
                nums[place] = d + 1;
            } else if (place > 0) {
                nums[place] = 0;
                increment(place-1);
            } else {
                incrementLength();
            }
        }
        
        private void incrementLength() {
            if (isOddLen) {
                isOddLen = false;
            } else {
                isOddLen = true;
                nums = new int[nums.length+1];
            }
            
            Arrays.fill(nums, 0);
            nums[0] = 1;
        }
        
        private int highestDigitPlace() {
            if (isOddLen)
                return (2*nums.length - 1);
            else
                return (2*nums.length);
        }
    }
}
