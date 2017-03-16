import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class C {
    BufferedReader in;
    StringTokenizer str;
    PrintWriter out;

    String next() throws IOException {
        while ((str == null) || (!str.hasMoreTokens())) {
            str = new StringTokenizer(in.readLine());
        }
        return str.nextToken();
    };

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    };

    BigInteger[][] powTen = new BigInteger[101][3];
    BigInteger A, B;
    int res;

    boolean verifyIfFairAndSquare(BigInteger x){
        if(x.compareTo(A) < 0) return false;
        if(x.compareTo(B) > 0) return false;
        String y = x.toString();
        int m = y.length();
        for(int i=0; i < m/2 ;i++){
            if(y.charAt(i) != y.charAt(m-i-1))
                return false;
        }
        return true;
    }

    void dfsPalindrome(int it1, int it2, BigInteger num) {
        int ini = 0;
        if(it1 == 0) ini = 1;
        if(it1 < it2) {
            for(int i=ini; i<=2 ;i++) {
                dfsPalindrome(it1+1, it2-1, num.add( powTen[it1][i].add(powTen[it2][i]) ));
            }
        }
        else{
            if(it1 == it2) {
                for(int i=ini; i<=2 ;i++) {
                    BigInteger x = num.add( powTen[it1][i] ); // TODO analise
                    if(verifyIfFairAndSquare(x.multiply(x))) {
                        res++;
//                        System.out.println(x + " " + x.multiply(x));
                    }
                }
            }
            else {
                // TODO analise
                if(verifyIfFairAndSquare(num.multiply(num))) {
                    res++;
//                    System.out.println(num + " " + num.multiply(num));
                }
            }
        }
    }

    void generator() {
        for(int i=1; i<=2 ;i++) {
            powTen[0][i] = BigInteger.valueOf(i);
        }
        for(int i=1; i<=100 ;i++) {
            powTen[i][1] = powTen[i-1][1].multiply(BigInteger.TEN);
            for(int j=0; j<=2 ;j++){
                powTen[i][j] = powTen[i][1].multiply(BigInteger.valueOf(j));
            }
        }
    }

    void solve() throws IOException {
        int T = nextInt();
        generator();
        for(int cas=1; cas<=T ;cas++) {
            res = 0;
            A = new BigInteger(next());
            B = new BigInteger(next());
            BigInteger aux = BigInteger.valueOf(9);
            if(aux.compareTo(A) >= 0 && aux.compareTo(B) <= 0)
                res++;
            for(int i=1; i<=8 ;i++) {
                dfsPalindrome(0, i-1, BigInteger.ZERO);
            }
            out.println("Case #" + cas + ": " + res);
        }
    }

    void run() throws IOException {
//        in = new BufferedReader(new InputStreamReader(System.in));
//        out = new PrintWriter(System.out);
//        in = new BufferedReader(new FileReader("input.txt"));
        in = new BufferedReader(new FileReader("C-large-1.in"));
        out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}
