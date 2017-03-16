import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.StreamSupport;

/**
 * Created by Derick on 4/8/2016.
 */
public class Main {



  public static void main(String[] args) throws IOException {
    BufferedReader input = new BufferedReader(new FileReader("inLarge"));
    BufferedWriter output = new BufferedWriter(new FileWriter("out.out"));
    ArrayList<String> answers = new ArrayList<>();
    int numCases = Integer.valueOf(input.readLine());

    for (int caseNo = 0; caseNo < numCases; caseNo++) {
      String[] tokens = input.readLine().split(" ");
      int k = Integer.valueOf(tokens[0]);
      int c = Integer.valueOf(tokens[1]);
      int s = Integer.valueOf(tokens[2]);

      if (s * c < k) {
        answers.add("IMPOSSIBLE");
        continue;
      }

      Queue<Integer> positionsToCheck = new LinkedList<>();
      IntStream.range(0, k).forEach(positionsToCheck::add);
      List<BigInteger> results = new ArrayList<>();

      BigInteger kBig = BigInteger.valueOf(k);
      while (!positionsToCheck.isEmpty()) {
        BigInteger presentTarget = BigInteger.ZERO;
        for (int depth = 0; depth < c && !positionsToCheck.isEmpty(); depth++) {
          BigInteger originalTarget = BigInteger.valueOf(positionsToCheck.poll());
          presentTarget = presentTarget.add(originalTarget.multiply(kBig.pow(c - depth - 1)));
        }
        results.add(presentTarget.add(BigInteger.ONE));
      }
      answers.add(String.join(" ", results.stream().map(Object::toString).collect(Collectors.toList())));
    }

    for (int i = 0; i < numCases; i++) {
      output.write(String.format("Case #%d: %s", i + 1, answers.get(i)));
      output.newLine();
    }
    output.flush();
  }

}
