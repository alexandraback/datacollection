import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class B {
  public static void main(String[] args) {
    Scanner stdin = new Scanner(System.in);

    int T = stdin.nextInt();
    for(int testCase = 1; testCase <= T; ++testCase) {
      char[] C = stdin.next().toCharArray();
      char[] J = stdin.next().toCharArray();
      String OC = new String(C);
      String OJ = new String(J);
      //
      // // CASE 1: Equality
      // boolean equal = true;
      // for(int i = 0; i < C.length; ++i) {
      //   if(C[i] != '?' && C[i] == J[i]) {
      //     continue;
      //   } else if(C[i] == '?' && J[i] == '?') {
      //     C[i] = '0';
      //     J[i] = '0';
      //   } else if(C[i] == '?') {
      //     C[i] = J[i];
      //   } else if(J[i] == '?'){
      //     J[i] = C[i];
      //   } else {
      //     equal = false;
      //     break;
      //   }
      // }
      //
      // if(equal) {
      //   System.out.printf("Case #%d: %s %s\n", testCase, new String(C), new String(J));
      //   continue;
      // }
      //
      // String[] it2 = doIt(OC, OJ);
      // String[] it3 = doIt(OJ, OC);
      //
      // BigInteger c2;
      // BigInteger j2;
      // try {
      //   c2 = new BigInteger(it2[0]);
      //   j2 = new BigInteger(it2[1]);
      // } catch (Exception e) {
      //   System.out.printf("Case #%d: %s %s\n", testCase, it3[0], it3[1]);
      //   continue;
      // }
      // BigInteger diff2 = c2.subtract(j2).abs();
      // BigInteger c3;
      // BigInteger j3;
      // try {
      //   c3 = new BigInteger(it3[0]);
      //   j3 = new BigInteger(it3[1]);
      // } catch (Exception e) {
      //   System.out.printf("Case #%d: %s %s\n", testCase, it2[0], it2[1]);
      //   continue;
      // }
      // BigInteger diff3 = c3.subtract(j3).abs();
      //
      // String ansC = "";
      // String ansJ = "";
      // if(diff2.compareTo(diff3) < 0) {
      //   ansC = it2[0];
      //   ansJ = it2[1];
      // } else if(diff2.compareTo(diff3) > 0) {
      //   ansC = it3[0];
      //   ansJ = it3[1];
      // } else {
      //   if(c2.compareTo(c3) < 0) {
      //     ansC = it2[0];
      //     ansJ = it2[1];
      //   } else if(c2.compareTo(c3) > 0) {
      //     ansC = it3[0];
      //     ansJ = it3[1];
      //   } else {
      //     if(j2.compareTo(j3) < 0) {
      //       ansC = it2[0];
      //       ansJ = it2[1];
      //     } else if(j2.compareTo(j3) > 0) {
      //       ansC = it3[0];
      //       ansJ = it3[1];
      //     } else {
      //       ansC = it3[0];
      //       ansJ = it3[1];
      //     }
      //   }
      // }

      String bf = bruteForce(OC, OJ);
      // String test = String.format("%s %s", ansC, ansJ);
      // if(test.compareTo(bf) != 0)
        // System.out.printf("FUCK!: ans: %s | best: %s | orig: %s %s\n", test, bf, OC, OJ);

      System.out.printf("Case #%d: %s\n", testCase, bf);
    }
  }

  // J > C
  static String[] doIt(String OC, String OJ) {
    char[] C = OC.toCharArray();
    char[] J = OJ.toCharArray();

    for(int i = 0; i < C.length; ++i) {
      if(C[i] == J[i]) {
        continue;
      } else if(J[i] != '?' && C[i] == '?') {
        continue;
      } else if((J[i] == '?' && C[i] == '9') || (J[i] != '?' && J[i] < C[i])) {
        int ind = i - 1;
        while(ind >= 0) {
          if(J[ind] == '?') {
            if(C[ind] == '?') {
              J[ind] = 1;
              C[ind] = 0;
              break;
            } else if (C[ind] < '9') {
              J[ind] = (char)(C[ind] + 1);
              break;
            }
          }
          --ind;
        }
        ind = max(0, ind);
        for(int j = ind - 1; j >= 0; --j) {
          if(J[j] == '?' && C[j] == '?') {
            J[j] = '0';
            C[j] = '0';
          }
          if(J[j] == '?')
            C[j] = J[j];
          if(C[j] == '?')
            C[j] = J[j];
        }
        for(int j = ind + 1; j < C.length; ++j) {
          if(C[j] == '?')
            C[j] = '0';
          if(J[j] == '?')
            J[j] = '9';
        }
        break;
      }
    }

    return new String[] { new String(C), new String(J) };
  }

  static String bruteForce(String C, String J) {
    String fstr = "%0" + C.length() + "d";
    int bestDiff = 1000000;
    int bestJ = 10000000;
    int bestI = 10000000;
    int max = 1000;
    if(C.length() == 2)
      max = 100;
    if(C.length() == 1)
      max = 10;
    for(int i = 0; i < max; ++i) {
      for(int j = 0; j < max; ++j) {
        if(abs(j - i) > bestDiff)
          continue;

        String cnew = String.format(fstr, i);
        if(bad(cnew, C)) {
          continue;
        }

        String jnew = String.format(fstr, j);
        if(bad(jnew, J)) {
          continue;
        }

        if(abs(j - i) < bestDiff) {
          bestDiff = abs(j - i);
          bestI = i;
          bestJ = j;
        } else if(bestDiff == abs(j - i)) {
          if(i < bestI) {
            bestI = i;
            bestJ = j;
          } else if (i == bestI && j < bestJ) {
            bestI = i;
            bestJ = j;
          }
        }
      }
    }

    return String.format(fstr, bestI) + " " + String.format(fstr, bestJ);
  }

  static boolean bad(String candidate, String law) {
    for(int i  = 0; i < law.length(); ++i) {
      if(candidate.charAt(i) != law.charAt(i) && law.charAt(i) != '?')
        return true;
    }
    return false;
  }
}
