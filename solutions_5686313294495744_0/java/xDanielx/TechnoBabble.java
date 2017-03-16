
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class TechnoBabble {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int numCases = scanner.nextInt();
    for (int i = 1; i <= numCases; ++i) {
      int numTopics = scanner.nextInt();
      List<Topic> topics = new ArrayList<>();
      for (int j = 0; j < numTopics; ++j)
        topics.add(new Topic(scanner.next().intern(), scanner.next().intern()));
      System.out.printf("Case #%d: %s\n", i, getMaxFakes(topics));
    }
  }

  private static int getMaxFakes(List<Topic> topics) {
    int n = topics.size();
    int highest = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
      Collection<Topic> realTopics = new ArrayList<>(), fakeTopics = new ArrayList<>();
      for (int i = 0; i < n; ++i) {
        Topic topic = topics.get(i);
        if ((mask >>> i & 1) != 0)
          realTopics.add(topic);
        else
          fakeTopics.add(topic);
      }
      Set<String> realFirstWords = new HashSet<>(), realSecondWords = new HashSet<>();
      realTopics.forEach(t -> { realFirstWords.add(t.a); realSecondWords.add(t.b); });
      if (fakeTopics.stream().allMatch(t -> realFirstWords.contains(t.a) && realSecondWords.contains(t.b)))
        highest = Math.max(highest, fakeTopics.size());
    }
    return highest;
  }

  private static class Topic {
    final String a, b;

    Topic(String a, String b) {
      this.a = a;
      this.b = b;
    }
  }
}
