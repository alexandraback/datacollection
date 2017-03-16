import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class A_Consonants {
  Scanner in;

  public static void main(String[] args) throws Exception  {
    new A_Consonants().run();
  }

  void run() throws Exception {
    //System.setIn(new FileInputStream("A-test.in"));
    System.setIn(new FileInputStream("A-small-attempt1.in"));
    System.setOut(new PrintStream("A-small-attempt1.out"));
    //System.setIn(new FileInputStream("A-large.in"));
    //System.setOut(new PrintStream("A-large.out"));
    in = new Scanner(System.in);
    int T = in.nextInt();

    for (int c = 1; c <=T; ++c) {
      String S = in.next();
      int N = in.nextInt();
      long res = solveFast(S,N);
      //long res2 = solveSlow(S,N);
      //if(res != res2) System.out.printf("error at case %d:  %d vs %d\n", c, res, res2);
      System.out.printf("Case #%d: %d\n", c, res);
    }

  }

  long solveSlow(String S, int N){
    int L = S.length();
    long res = 0;
    for (int i = 0; i <L; ++i)
      for (int j = i; j < L; ++j) {
        boolean valid = false;
        int cont = 0;
        for (int k = i; k <=j; ++k ) {
          if("aeiou".contains(""+S.charAt(k)))
            cont = 0;
          else
            cont++;
          if(cont>=N)
            valid = true;
        }
        if (valid) res ++;
      }
    return res;
  }

  long solveFast(String S, int N){
    int L = S.length();
    int []M =  new int [L];
    for(int i = 0; i < L; ++i)
      M[i] = !isVocal(S.charAt(i))?(i==0?1:1+M[i-1]):0;
      int count[] = new int [L];
      for(int i = 0; i < L; ++i)
        count[i] = (M[i]>=N?1:0) + (i==0?0:count[i-1]);

      long res = 1L*L*(L+1)/2;
      if(N>1)
        for(int i = 0; i < L; ++i) {
          int p = prev(count, i);
          int len = N-1 + (i-p);
          len = Math.min(len,i+1);
          res -= len;
        }
      else
        for(int i = 0; i < L; ++i) {
          int p = prev(count, i);
          if(!isVocal(S.charAt(p)) && N==1) p++;
          int len = N + (i-p);
          len = Math.min(len,i+1);
          res -= len;
        }
      return res;
  }


  int prev(int []A, int pos){
    int lo = -1;
    int hi = pos;
    while(hi-lo>1) {
      int mid = (lo + hi)/2;
      if(A[mid]==A[pos]) hi = mid;
      else lo = mid;
    }
    return hi;
  }

  boolean isVocal(char c) {
    switch(c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
    }
    return false;
  }


}
