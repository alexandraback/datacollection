import java.util.Scanner;

public class Technobabble {

  static Scanner scanner;
  static int parent[];
  public static void main(String[] args) {
    scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    for (int i = 1; i <= n; i++) {
      processTestCase(i);
    }
  }

  private static void processTestCase(int t) {
    int n = scanner.nextInt();
    String arr[][] = new String[n][2];
    for(int i = 0; i< n; i++) {
      arr[i][0] = scanner.next();
      arr[i][1] = scanner.next();
    }
    parent = new int[n];
    int size[] = new int[n];
    for(int i = 0 ;i< n ; i++) {
      parent[i] = i;
      size[i] = 1;
    }
    for(int i = 0 ;i < n; i++) {
      for(int j = 0; j < i; j++) {
        if(arr[i][0].equals(arr[j][0]) || arr[i][1].equals(arr[j][1])) {
          int parentOfJ = getParent(j);
          int parentOfI = getParent(i);
          if(parentOfI == parentOfJ) {
            continue;
          }
          parent[parentOfJ] = parentOfI;
          size[parentOfI] += size[parentOfJ];
        }
      }
    }
    int geniune = 0;
    for(int i = 0; i< n; i++) {
      if(parent[i] == i) {
        geniune += (size[i]+1)/2;
      }
    }
    System.out.println("Case #" + t + ": " + geniune);
  }

  private static int getParent(int i) {
    if(parent[i] == i) {
      return i;
    } else {
      return getParent(parent[i]);
    }
  }
}
