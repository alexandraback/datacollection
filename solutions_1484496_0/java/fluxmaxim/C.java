import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;

public class C extends Worker {

  long time = 3 * 60 * 1000;
  long[] numbers;
  private Set<Long> set1;
  private Set<Long> set2;

  @Override
  void read(Input input) throws Exception {
    long[] v = input.readlongs();
    numbers = new long[v.length - 1];
    for (int i = 0; i < numbers.length; i++) {
      numbers[i] = v[i+1];
    }
  }

  @Override
  void solve() {
    int n = numbers.length;
    long start = System.currentTimeMillis();
    Random r = new Random();

    Map<Long, Set<Long>> sums = new HashMap<Long, Set<Long>>();

    while(System.currentTimeMillis() - start < time) {
      int size = 1 + r.nextInt(n - 1);
      Set<Long> newNumbers = new HashSet<Long>();
      long sum = 0;
      for (int i = 0; i < size; i++) {
        int index = r.nextInt(n);
        while (newNumbers.contains(numbers[index])) {
          index = r.nextInt(n);
        }
        sum += numbers[index];
        newNumbers.add(numbers[index]);
      }
      if (sums.containsKey(sum)) {
        Set<Long> oldSum = sums.get(sum);
        if (!oldSum.equals(newNumbers)) {
          set1 = newNumbers;
          set2 = oldSum;
          break;
        }
      } else {
        sums.put(sum, newNumbers);
      }
    }
  }

  @Override
  void write(PrintStream out) {
    out.printf("Case #%d:\n", id);
    if (set1 != null) {

      List<Long> list1 = new ArrayList<Long>(set1);
      Collections.sort(list1);

      for (Iterator<Long> it = list1.iterator(); it.hasNext(); ) {
        System.out.print(it.next());
        if (it.hasNext()) {
          System.out.print(" ");
        }
      }
      System.out.println();

      List<Long> list2 = new ArrayList<Long>(set2);
      Collections.sort(list2);

      for (Iterator<Long> it = list2.iterator(); it.hasNext(); ) {
        System.out.print(it.next());
        if (it.hasNext()) {
          System.out.print(" ");
        }
      }
      System.out.println();
    } else {
      System.out.println("Impossible");
    }
  }

  public static void main(String[] args) throws Exception {
    Master master = new Master(C.class);
    master.main(args[0]);
  }

}
