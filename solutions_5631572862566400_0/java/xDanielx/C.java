import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Deque;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int numCases = scanner.nextInt();
    for (int i = 1; i <= numCases; ++i) {
      int numKids = scanner.nextInt();
      int[] bffs = new int[numKids];
      for (int j = 0; j < numKids; ++j)
        bffs[j] = scanner.nextInt() - 1;
      System.out.printf("Case #%d: %d\n", i, getLargestCircle(bffs));
    }
  }

  private static int getLargestCircle(int[] bffs) {
    int numKids = bffs.length;
    Deque<PartialCircle> partialCircles = new ArrayDeque<>();
    partialCircles.add(new PartialCircle(-1, null, 0));
    int maxLength = 0;
    while (!partialCircles.isEmpty()) {
      PartialCircle partialCircle = partialCircles.pop();
      if (partialCircle.isValid(bffs))
        maxLength = Math.max(maxLength, partialCircle.length);
//      System.err.print(partialCircle);
      if (partialCircle.length < numKids) {
//        System.err.print(" -> " + partialCircle.extend(numKids));
        partialCircles.addAll(partialCircle.extend(numKids));
      }
//      System.err.println();
    }
    return maxLength;
  }

  private static class PartialCircle {
    final int head;
    final PartialCircle rest;
    final int length;

    PartialCircle(int head, PartialCircle rest, int length) {
      this.head = head;
      this.rest = rest;
      this.length = length;
    }

    Collection<PartialCircle> extend(int numKids) {
      Set<Integer> inCircle = new HashSet<>();
      PartialCircle current = this;
      while (current.head != -1) {
        inCircle.add(current.head);
        current = current.rest;
      }

      Collection<PartialCircle> children = new ArrayList<>();
      for (int kid = 0; kid < numKids; ++kid)
        if (!inCircle.contains(kid))
          children.add(new PartialCircle(kid, this, length + 1));
      return children;
    }

    boolean isValid(int[] bffs) {
      if (length == 0) return false;

      Set<Integer> inCircle = new HashSet<>();
      PartialCircle current = this;
      int[] circle = new int[length];
      int index = 0;
      while (current.head != -1) {
        inCircle.add(current.head);
        circle[index++] = current.head;
        current = current.rest;
      }

      for (int circleIndex = 0; circleIndex < length; ++circleIndex) {
        if (!inCircle.contains(circle[circleIndex]))
          continue;

        int bff = bffs[circle[circleIndex]];
        int left = (circleIndex - 1 + length) % length;
        int right = (circleIndex + 1) % length;
        if (circle[left] != bff && circle[right] != bff)
          return false;
      }

      return true;
    }

    @Override
    public String toString() {
      if (head == -1)
        return "";
      return head + " " + rest.toString();
    }
  }
}
