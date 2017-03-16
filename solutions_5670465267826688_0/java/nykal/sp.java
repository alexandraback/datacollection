import java.util.*;

public class sp {

  public class quat {
    public char c;
    public int s;
    public quat(char a, int b) {
      c = a;
      s = b;
    }
  }

  public quat multiply(quat a, quat b) {
    if(a.c == 'x') return new quat(b.c, a.s*b.s);
    if(b.c == 'x') return new quat(a.c, a.s*b.s);

    int ind1 = a.c - 'i';
    int ind2 = b.c - 'i';
    char[][] out = {{'x', 'k', 'j'},
      {'k','x','i'},
      {'j','i','x'}};
    int[][] signs = {{-1,1,-1},
      {-1,-1,1},
      {1,-1,-1}};
    return new quat(out[ind1][ind2], a.s*b.s*signs[ind1][ind2]);
  }

  public int find(String s, quat q) {
    quat cur = new quat('x', 1);

    for(int i=0;i<s.length();i++) {
      quat temp = new quat(s.charAt(i), 1);
      cur = multiply(cur, temp);
      if(cur.c == q.c && cur.s == q.s) return i+1;
    }

    return -1;
  }

  public void tester() {
    char[] temp = {'x','i','j','k'};
    for(int i=0;i<4;i++) {
      for(int j=0;j<4;j++) {
        for(int k=0;k<2;k++) {
          int s = (k==0) ? 1 : -1;
          quat a = new quat(temp[i],1);
          quat b = new quat(temp[j],s);
          quat out = multiply(a,b);
          System.out.printf("(%c %d) * (%c %d) = (%c %d)\n",
              a.c, a.s, b.c, b.s, out.c, out.s);
        }
      }
    }
  }

  public void solve() {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int ii=1;ii<=T;ii++) {
      int L = sc.nextInt();
      int X = sc.nextInt();
      String s = sc.next();
      String S = "";
      if(X > 16) X = 16 + X % 4;
      for(int i=0;i<X;i++) {
        S += s;
      }
      //System.out.println(S);

      String ans = "YES";
      int n1 = find(S, new quat('i', 1)); 
      if(n1 == -1) ans = "NO";
      else {
        //System.out.printf("%d\n", n1);
        S = S.substring(n1);
      //System.out.println(S);
        int n2 = find(S, new quat('j', 1));
        if(n2 == -1) ans = "NO";
        else {
          //System.out.printf("%d\n", n2);
          S = S.substring(n2);
      //System.out.println(S);
          int n3 = find(S, new quat('k', 1));
          if(n3 == -1) ans = "NO";
          else {
            //System.out.printf("%d\n", n3);
            S = S.substring(n3);
      //System.out.println(S);
            quat cur = new quat('x', 1);
            for(int i=0;i<S.length();i++) {
              quat temp = new quat(S.charAt(i), 1);
              cur = multiply(cur, temp);
            }
            if(!(cur.c == 'x' && cur.s == 1)) ans = "NO";
          }
        }
      }


      System.out.printf("Case #%d: %s\n", ii, ans);
    }


  }


  public static void main(String[] args) {
    sp s = new sp();
    //s.tester();
    s.solve();

  }

}
