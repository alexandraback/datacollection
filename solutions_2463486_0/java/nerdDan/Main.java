import java.math.*;
import java.util.*;

public class Main {

    public static boolean isPalindrome(String s) {
        for(int i = 0; i<s.length()/2; i++)
            if(s.charAt(s.length()-1-i)!=s.charAt(i))
                return false;
        return true;
    }

    public static void main(String[] args) {
        TreeSet<BigInteger> set = new TreeSet<BigInteger>();
        set.add(new BigInteger("3"));
        for(BigTernary t = new BigTernary("1");
            t.length()<=4;
            t = t.addOne()) {
            StringBuilder s = new StringBuilder(t.toString());
            int l = s.length();
            for(int i = l-1; i>=0; i--)
                s.append(s.charAt(i));
            set.add(new BigInteger(new String(s)));
            s.deleteCharAt(l);
            set.add(new BigInteger(new String(s)));
        }
        TreeSet<BigInteger> set1 = new TreeSet<BigInteger>();
        for(Iterator<BigInteger> i = set.iterator(); i.hasNext(); ) {
            BigInteger a = i.next();
            BigInteger b = a.multiply(a);
            if(isPalindrome(b.toString()))
                set1.add(b);
        }
        //for(Iterator<BigInteger> i = set1.iterator(); i.hasNext(); )
        //System.out.println(i.next());
        Scanner cin = new Scanner(System.in);
        int nCase = cin.nextInt();
        for(int iCase = 1; iCase<=nCase; iCase++)
            System.out.println("Case #"+iCase+": "
                               +set1.subSet(new BigInteger(cin.next()),
                                            true,
                                            new BigInteger(cin.next()),
                                            true).size());
    }

}

final class BigTernary {

    private String v;

    public BigTernary(String v) {
        this.v = v;
    }

    public String toString() { return v; }

    public boolean equals(BigTernary other) { return v.equals(other.v); }

    public int length() { return v.length(); }

    public BigTernary addOne() {
        StringBuilder a = new StringBuilder(v);
        addOne(a, a.length()-1);
        return new BigTernary(new String(a));
    }

    private void addOne(StringBuilder s, int i) {
        if(i==0 && s.charAt(0)=='2') {
            s.append('0');
            //System.out.println(s.length());
            for(int j = 1; j<s.length(); j++)
                s.setCharAt(j, '0');
            s.setCharAt(0, '1');
        }
        else if(s.charAt(i)!='2')
            s.setCharAt(i, (char)(s.charAt(i)+1));
        else {
            s.setCharAt(i, '0');
            addOne(s, i-1);
        }
    }

}
