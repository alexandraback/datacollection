import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;
import java.math.BigInteger;


class Round1A1 {
    public static void main(String args[] ) throws Exception {
        Round1A1 sol = new Round1A1();
        sol.solve();
    }

    void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();
        int T = Integer.parseInt(line);

        for (int t = 0; t < T; t++) {
            
            line = br.readLine();

            String[] tt = line.split(" ");
            String r = tt[0];
            String thick = tt[1];
            String answer = calc(r, thick);
            System.out.println("Case #" + (t+1) + ": " + answer);
        }
    }

    String calc(String r, String t) {
        // System.out.println(r + "  " + t);
        BigInteger rBig = new BigInteger(r);
        BigInteger tBig = new BigInteger(t);

        BigInteger temp2 = rBig.multiply(new BigInteger("2"));
        temp2 = temp2.subtract(new BigInteger("1"));
        BigInteger temp = temp2.multiply(temp2);
        BigInteger temp1 = tBig.multiply(new BigInteger("8"));
        temp = temp.add(temp1);
        
        temp = sqrt(temp);
        temp = temp.subtract(temp2);
        temp = temp.divide(new BigInteger("4"));
        
        temp1 = temp.add(new BigInteger("1"));
        while(true) {
            if(!comp(temp1, rBig, tBig)) {
                break;
            }
            temp = temp1;
            temp1 = temp1.add(new BigInteger("1"));
        }

        return temp.toString();
    }

    boolean comp(BigInteger k, BigInteger r, BigInteger t) {
        BigInteger temp1 = k.multiply(k);
        temp1 = temp1.multiply(new BigInteger("2"));

        BigInteger temp2 = r.multiply(new BigInteger("2"));
        temp2 = temp2.subtract(new BigInteger("1"));
        temp2 = temp2.multiply(k);

        temp1 = temp1.add(temp2);

        if (t.compareTo(temp1) > 0)
            return true;
        return false;
    }

    BigInteger sqrt(BigInteger n) {
      BigInteger a = BigInteger.ONE;
      BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
      while(b.compareTo(a) >= 0) {
        BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
        if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
        else a = mid.add(BigInteger.ONE);
      }
      return a.subtract(BigInteger.ONE);
    }

}