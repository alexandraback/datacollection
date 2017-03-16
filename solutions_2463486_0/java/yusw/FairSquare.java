import java.util.Arrays;  //Arrays.toString(int[])
public class FairSquare {
    public char[] LB;
    public char[] UB;
  
    public FairSquare(String lb, String ub) {
        LB = lb.toCharArray();
        UB = ub.toCharArray();
    }
    public int NumOfFairSquare() {
        int ans = 0;
        char[] num = SqrtLB(LB);
        char[] numsqrd = num;
        while (CompareNum(numsqrd, UB) != 1) {
             numsqrd = Squared(num);
//             StdOut.println(Arrays.toString(num));
             if ((CompareNum(numsqrd, LB) != -1) && (CompareNum(numsqrd, UB) != 1)
                     && isPalind(numsqrd)) {
                 ans++;
//                 StdOut.println(Arrays.toString(num));
             }
             num = nextPalind(num);
        }
        return ans;
    }
    public static char[] SqrtLB(char[] num) {
        char[] ans = new char[1];
        int len = num.length;
        char msb = num[0];
        int msbint = (int) Math.sqrt(Character.getNumericValue(msb));
        ans[0] = Character.forDigit(msbint, 10);
        ans = NumETen(ans, (len - 1)/2);
        ans[(len - 1)/2] = ans[0];
        return ans;
    }
    public int NumOfPalind() { // LB must be Palind
        int ans = 0;
        char[] num = LB;
        if (isPalind(num))
            ans ++;
        while (!(CompareNum(num, UB) == 1)) {
            num = nextPalind(num);
//            StdOut.println(Arrays.toString(num));
            ans++;
//            StdOut.println(ans);
        }
        return ans - 1;
        
    }
    public static char[] nextPalind(char[] num) {
//        assert isPalind(num) : "num is not Palindromic";
        int len = num.length;
        int lenHalf;
        boolean isEven;
        if (len % 2 == 0) {
            lenHalf = len / 2;
            isEven = true;
        } else {
            lenHalf = len / 2 + 1;
            isEven = false;
        }
        char[] numHalf = Arrays.copyOfRange(num, 0, lenHalf);
        
        char[] One = {'1'};
        numHalf = AddNum(numHalf, One);
        if (numHalf.length > lenHalf) {
            if (isEven) lenHalf++;
            isEven = !isEven;
        }
//        lenHalf = numHalf.length;
//        if (lenHalf % 2 == 0) isEven = true;
//        else isEven = false;
//        StdOut.println(Arrays.toString(numHalf));
        if (isEven) {
            int lenans = 2 * lenHalf;
            char[] ans = new char[lenans];
            for (int i = 0; i < lenans; i++) {
                if (i < lenHalf) 
                    ans[i] = numHalf[i];
                else 
                    ans[i] = numHalf[(lenHalf - 1) - (i - lenHalf)];
            }
            return ans;
        } else {
            int lenans = 2*(lenHalf - 1) + 1;
            char[] ans = new char[lenans];
            for (int i = 0; i < lenans; i++) {
                if (i < lenHalf) {
//                    StdOut.println(i);
                    ans[i] = numHalf[i];
                }
                else
                    ans[i] = numHalf[(lenHalf - 2) - (i - lenHalf)];
            }
            return ans;
        }
    }
    public static boolean isPalind(char[] num) {
        for (int left=0, right=num.length-1; left<right; left++, right--) {
            // exchange the first and last
            if (num[left] != num[right])
                return false;
        }
        return true;
    }
    public static char[] Squared(char[] num) {
        int len = num.length;
        char[] ans = {'0'};
        for (int i = len - 1, j = 0; i >= 0; i--, j++) {
            ans = AddNum(NumETen(NumMultBit(num, Character.getNumericValue(num[i])), j), ans);
        }
        return ans;
    }
    public static char[] NumMultBit(char[] num, int bit) {
        if (bit == 0) {
            char[] ans = {'0'};
            return ans;
        }
        int len = num.length;
        char[] ans = new char[len];
        int carry = 0;
        for (int i = len-1; i >= 0; i--) {
            int tmp = Character.getNumericValue(num[i]) * bit + carry;
            int b = tmp % 10;
            ans[i] = Character.forDigit(b, 10);
            carry = tmp / 10;
        }
        if (carry != 0) {
            char[] ansnew = new char[len + 1];
            for (int i = 0; i < len; i++)
                ansnew[i + 1] = ans[i];
            ansnew[0] = Character.forDigit(carry, 10);;
            return ansnew;
        }
        return ans;
    }
    public static char[] AddNum(char[] num1, char[] num2) {
        int len1 = num1.length;
        int len2 = num2.length;
        int lenL, lenS; // long, short
        char[] numL, numS;
        char[] ans;
        int carry = 0;
        if (len1 > len2) {
            lenL = len1;
            lenS = len2;
            numL = num1;
            numS = num2;
        } else {
            lenL = len2;
            lenS = len1;
            numL = num2;
            numS = num1;
        }
        ans = new char[lenL];
//        StdOut.println(Arrays.toString(numL));
        for (int i = lenL - 1, j = lenS - 1; i >= 0; i--, j--) {
            int bitS = 0;
            if (j >= 0) bitS = Character.getNumericValue(numS[j]);
            int tmp = Character.getNumericValue(numL[i]) + bitS + carry;
            int bit = tmp % 10;
            ans[i] = Character.forDigit(bit, 10);
            carry = tmp / 10;
        }
        if (carry == 1) {
            char[] ansnew = new char[lenL + 1];
            for (int i = 0; i < lenL; i++)
                ansnew[i + 1] = ans[i];
            ansnew[0] = Character.forDigit(carry, 10);;
            return ansnew;
        }
         return ans;
    }
    public static char[] NumETen(char[] num, int tens) {
        if (tens == 0)
            return num;
        int len = num.length;
        if (len == 1 && num[0] == '0') // num is 0
            return num;
        char[] ans = new char[len+tens];
        for (int i = 0; i < len + tens; i++) {
            if (i >= len) 
                ans[i] = '0';
            else
                ans[i] = num[i];
        }
        return ans;
    }
    // positive case only, no preceding 0's
    public static int CompareNum(char[] num1, char[] num2) {
        int len1 = num1.length;
        int len2 = num2.length;
        if (len1 > len2)
            return 1;
        else if (len1 < len2)
            return -1;
        else {
            for (int i = 0; i < len1; i++) {
                if (num1[i] > num2[i])
                    return 1;
                else if (num1[i] < num2[i])
                    return -1;
                else
                    continue;
            }
            return 0;
        }
    }
    
   
    public static void main(String[] args) {
        if (args.length == 0) {
            FairSquare blk = new FairSquare("100", "1000");
            char[] num1 = {'1','0','0','1'};
            char[] num2 = {'3','4'};
//            for (int i = 0 ; i < 90; i++) {
//                num1 = blk.nextPalind(num1);
//                StdOut.println(Arrays.toString(num1));
//            }
            StdOut.println(blk.NumOfFairSquare());
            return;
        }
        In in = new In(args[0]);
        int T = in.readInt(); // # of test cases
        Out out = new Out(args[0]+".Out");
        for (int i = 0; i < T; i++) {
            String lb = in.readString();
            String ub = in.readString();
            
            FairSquare blk = new FairSquare(lb, ub);
            
            out.println("Case #" + (i+1) + ": " + blk.NumOfFairSquare());
            
            //StdOut.println("Case #" + (i+1) + ": " + msp.MinProd());
        }
        out.close();
    }
}