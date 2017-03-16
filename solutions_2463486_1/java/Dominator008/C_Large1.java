import java.util.*;

public class C_Large1 {

  private static List<Long> palinSquare = new ArrayList<Long>(){/**
     * 
     */
    private static final long serialVersionUID = 1L;
  {
    add(0L);
    add(1L);
    add(4L);
    add(9L);
    add(121L);
    add(484L);
    add(10201L);
    add(12321L);
    add(14641L);
    add(40804L);
    add(44944L);
    add(1002001L);
    add(1234321L);
    add(4008004L);
    add(100020001L);
    add(102030201L);
    add(104060401L);
    add(121242121L);
    add(123454321L);
    add(125686521L);
    add(400080004L);
    add(404090404L);
    add(10000200001L);
    add(10221412201L);
    add(12102420121L);
    add(12345654321L);
    add(40000800004L);
    add(1000002000001L);
    add(1002003002001L);
    add(1004006004001L);
    add(1020304030201L);
    add(1022325232201L);
    add(1024348434201L);
    add(1210024200121L);
    add(1212225222121L);
    add(1214428244121L);
    add(1232346432321L);
    add(1234567654321L);
    add(4000008000004L);
    add(4004009004004L);
  }};

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for (int k = 1; k <= n; k++) {
      long A = in.nextLong();
      long B = in.nextLong();
      long count = 0;
      for (int i = 0; i < palinSquare.size(); i++) {
        if (palinSquare.get(i) > B) {
          break;
        }
        if (palinSquare.get(i) >= A) {
          count++;
        }
      }
      System.out.printf("Case #%d: %d\n", k, count);
    }
    in.close();
  }
}