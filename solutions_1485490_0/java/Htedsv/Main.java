import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;


public class Main {

       /**
        * @param args
        */
       public static void main(String[] args) {
               // TODO Auto-generated method stub
               int _ = cin.nextInt();
               for (int i = 1; i <= _; i++){
                       solve(i);
               }
       }

       public static void solve(int icase){
               int n = cin.nextInt();
               int m = cin.nextInt();
               for (int i = 1; i <= n; i++){
                       a[i] = cin.nextBigInteger();
                       Akind[i] = cin.nextInt();
               }
               for (int j = 1; j <= m; j++){
                       b[j] = cin.nextBigInteger();
                       Bkind[j] = cin.nextInt();
               }
               hashMap.clear();
               BigInteger r = calc(n, m, a[n], b[m]);
               System.out.print( "Case #" + icase + ": " );
               System.out.println(r);
       }

       public static BigInteger calc(int i, int j, BigInteger iLeft,
BigInteger jLeft ){
               if ( i <= 0 || j <= 0 ) return BigInteger.ZERO;

               HashType hash = new HashType(i, j, iLeft, jLeft);

               if ( hashMap.containsKey(hash) ){
                       return hashMap.get(hash);
               }

               BigInteger ret = null;
               if ( Akind[i] == Bkind[j] ){
                       int flag = iLeft.compareTo(jLeft);
                       if ( flag < 0 ){
                               // iLeft < jLeft
                               ret = calc(i-1, j, a[i-1], jLeft.subtract(iLeft)).add(iLeft) ;
                       } else if (flag > 0){
                               ret = calc(i, j-1, iLeft.subtract(jLeft), b[j-1]).add(jLeft);
                       } else {
                               ret = calc(i-1, j-1, a[i-1], b[j-1]).add(iLeft);
                       }
               } else {
                       BigInteger r1 = calc(i-1, j, a[i-1], jLeft);
                       BigInteger r2 = calc(i, j-1, iLeft, b[j-1]);
                       if (r1.compareTo(r2) > 0)
                               ret = r1;
                       else
                               ret = r2;
               }

               hashMap.put(hash, ret);
               return ret;
       }

       static HashMap< HashType, BigInteger > hashMap = new HashMap<
HashType, BigInteger >();

       static final int maxn = 100 + 5;
       static BigInteger []a = new BigInteger[maxn];
       static BigInteger []b = new BigInteger[maxn];
       static int []Akind = new int[maxn];
       static int []Bkind = new int[maxn];

       static Scanner cin = new Scanner( new BufferedInputStream(System.in) );

}

class HashType {
       int i, j;
       BigInteger iLeft, jLeft;
       public HashType(int i, int j, BigInteger iLeft, BigInteger jLeft){
               this.i = i;
               this.j = j;
               this.iLeft = iLeft;
               this.jLeft = jLeft;
       }
       public boolean equals(Object rhs){
               if ( rhs instanceof HashType ){
                       HashType other = (HashType)(rhs);
                       return this.i == other.i && this.j == other.j
                                       && this.iLeft == other.iLeft && this.jLeft == other.jLeft;
               }
               return false;
       }
}

