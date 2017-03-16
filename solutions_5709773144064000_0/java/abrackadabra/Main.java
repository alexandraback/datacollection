import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author abra
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		CookieClickerAlpha solver = new CookieClickerAlpha();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class CookieClickerAlpha extends SavingChelperSolution {

  public void solve() {
    double farmCost = in.nextDouble();
    double farmEfficiency = in.nextDouble();
    double goal = in.nextDouble();

    double rate = 2.0;
    double time = 0.0;

    double result = Double.MAX_VALUE;

    double prev = Double.MAX_VALUE;

    while (true) {
      double now = goal / rate + time;
      result = Math.min(result, now);

      if (now > prev) {
        break;
      } else {
        prev = now;
      }

      time += farmCost / rate;
      rate += farmEfficiency;
    }

    out.println(result);
  }
}

abstract class SavingChelperSolution {

  public InputReader in;
  public OutputWriter out;

  private OutputWriter toFile;

  public SavingChelperSolution() {
    try {
      toFile = new OutputWriter("gcj-output.txt");
    } catch (FileNotFoundException e) {
      throw new RuntimeException(e);
    }
  }

  public abstract void solve();

  public void solve(int testNumber, InputReader in, OutputWriter out) {

    ByteArrayOutputStream saved = new ByteArrayOutputStream();

    OutputWriter savingOut = new OutputWriter(saved);

    this.in = in;
    this.out = savingOut;

    solve();
    savingOut.flush();

    String result = "Case #" + testNumber + ": " + saved.toString();
    if (!result.endsWith("\n")) {
      result += "\n";
    }

    out.write(result);
    out.flush();
    toFile.write(result);
    toFile.flush();
  }

}

class InputReader {

  BufferedReader br;
  StringTokenizer in;

  public InputReader(String fileName) {
    try {
      br = new BufferedReader(new FileReader(fileName));
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  public InputReader(InputStream inputStream) {
    br = new BufferedReader(new InputStreamReader(inputStream));
  }

  boolean hasMoreTokens() {
    while (in == null || !in.hasMoreTokens()) {
      String s = nextLine();
      if (s == null) {
        return false;
      }
      in = new StringTokenizer(s);
    }
    return true;
  }

  public String nextString() {
    return hasMoreTokens() ? in.nextToken() : null;
  }

  public String nextLine() {
    try {
      in = null; // riad legacy
      return br.readLine();
    } catch (Exception e) {
      e.printStackTrace();
      return null;
    }
  }

  public double nextDouble() {
    return Double.parseDouble(nextString());
  }

  public String next() {
    return nextString();
  }
}

class OutputWriter extends PrintWriter {

  public OutputWriter(String fileName) throws FileNotFoundException {
    super(fileName);
  }

  public OutputWriter(OutputStream outputStream) {
    super(outputStream);
  }

  public OutputWriter(Writer writer) {
    super(writer);
  }

}

