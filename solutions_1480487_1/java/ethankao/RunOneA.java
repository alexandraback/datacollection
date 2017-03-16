import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class RunOneA {
  double[] scores;
  double sum = 0;
  double avg = 0;

  public RunOneA(double[] scores) {
    this.scores = scores;
    for (double s : scores) {
      sum += s;
    }
    avg = sum / scores.length;
  }

  public String solve() {
    StringBuffer strBuffer = new StringBuffer();
    double target = avg * 2;
    double sumWithoutBig = 0;
    int nCount = 0;
    for (int i = 0; i < scores.length; ++i) {
      double s = scores[i];
      double p = (target - s) / sum;
      if (p < 0)
        nCount++;
      else
        sumWithoutBig += s;
      strBuffer.append(String.format("%6f", p * 100));
      if (i != scores.length - 1)
        strBuffer.append(" ");
    }
    if (nCount > 0) {
      strBuffer.setLength(0);
      strBuffer.trimToSize();
      target = (sum + sumWithoutBig) / (scores.length - nCount);
      for (int i = 0; i < scores.length; ++i) {
        double s = scores[i];
        double p = (target - s) / sum;
        if (p < 0)
          p = 0;
        strBuffer.append(String.format("%6f", p * 100));
        if (i != scores.length - 1)
          strBuffer.append(" ");
      }
    }
    return strBuffer.toString();
  }

  public static void main(String[] args) throws IOException {
//     RunOneA solver = new RunOneA(new double[]{2, 63, 9});
//     System.out.println(solver.solve());
    RunOneA solver;
    File folder = new File(".");
    for (File f : folder.listFiles()) {
      if (!f.getName().endsWith("in") || !f.isFile()) {
        continue;
      }
      System.out.println(f.getName());
      String outFileName = f.getName().replace("in", "out");

      BufferedReader reader = new BufferedReader(new FileReader(f));
      String str;
      int lineNum = 0, caseNum = 1;
      BufferedWriter writer = new BufferedWriter(new FileWriter(outFileName));
      lineNum = Integer.valueOf(reader.readLine());
      double[] scores;
      while ((str = reader.readLine()) != null) {
        str = str.trim();
        String[] tokens = str.split(" ");
        scores = new double[tokens.length - 1];
        for (int i = 1; i < tokens.length; ++i) {
          scores[i - 1] = Double.valueOf(tokens[i]);
        }
        solver = new RunOneA(scores);
        writer.write(String.format("Case #%d: %s\n", caseNum++, solver.solve()));
      }
      if (lineNum != caseNum - 1) {
        System.err.println("Case Number is not matched to input file.");
      }
      writer.flush();
      writer.close();
    }
  }
}
