import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class QualifierB {
  class Task implements Runnable {
    private final int num;
    private final int n;
    private final int m;
    private final int[][] as;
    
    public Task(int num, int n, int m, int[][] as) {
      this.num = num;
      this.n = n;
      this.m = m;
      this.as = as;
    }
    
    public boolean maxInLane(int row, int col, int drow, int dcol) {
      int a = as[row][col];
      for (int crow = row, ccol = col; crow < n && ccol < m; crow += drow, ccol += dcol) {
        if (as[crow][ccol] > a) {
          return false;
        }
      }
      for (int crow = row, ccol = col; crow >= 0 && ccol >= 0; crow -= drow, ccol -= dcol) {
        if (as[crow][ccol] > a) {
          return false;
        }
      }
      return true;
    }
    
    @Override
    public void run() {
      String result = null;
      
      // BEGIN RESULT COMPUTATION
      // ------------------------------------------------------------
      
      for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
          System.out.print(as[row][col]);
        }
        System.out.println();
      }
      
      boolean possible = true;
      for (int row = 0; row < n && possible; ++row) {
        for (int col = 0; col < m; ++col) {
          if (!maxInLane(row, col, 1, 0) && !maxInLane(row, col, 0, 1)) {
            possible = false;
          }
        }
      }
      
      if (possible) {
        result = "YES";
      }
      else {
        result = "NO";
      }
      
      // END RESULT COMPUTATION
      // ------------------------------------------------------------
      
      System.out.println(result);
      reportResult(num, result);
    }
  }
  
  public static final int NUM_THREADS = 4;
  
  private final String file_name;
  private ArrayList<String> results;
  
  public QualifierB(String file_name) {
    this.file_name = file_name;
  }
  
  public ArrayList<String> calculate() throws IOException, InterruptedException {
    results = new ArrayList<String>();
    ThreadPoolExecutor tpe =
            new ThreadPoolExecutor(NUM_THREADS, NUM_THREADS, 2, TimeUnit.SECONDS,
                    new LinkedBlockingQueue<Runnable>());
    FileReader fr = new FileReader(file_name);
    BufferedReader br = new BufferedReader(fr);
    String line = br.readLine();
    System.out.println("Header: " + line);
    String[] ints = line.split(" ");
    
    // BEGIN HEADER PARSING
    // --------------------------------------------------------------------
    
    int total_num = Integer.parseInt(ints[0]);
    
    // END HEADER PARSING
    // --------------------------------------------------------------------
    
    for (int i = 0; i < total_num; ++i) {
      results.add("");
      
      // BEGIN READING CASE
      // ----------------------------------------------------------------
      
      line = br.readLine();
      String[] split_line = line.split(" ");
      int n = Integer.parseInt(split_line[0]);
      int m = Integer.parseInt(split_line[1]);
      int[][] as = new int[n][m];
      for (int row = 0; row < n; ++row) {
        line = br.readLine();
        split_line = line.split(" ");
        for (int col = 0; col < m; ++col) {
          as[row][col] = Integer.parseInt(split_line[col]);
        }
      }
      tpe.execute(new Task(i, n, m, as));
      
      // END READING CASE
      // ----------------------------------------------------------------
      
    }
    
    br.close();
    fr.close();
    tpe.shutdown();
    tpe.awaitTermination(8, TimeUnit.MINUTES);
    return results;
  }
  
  public synchronized void reportResult(int num, String result) {
    results.set(num, result);
  }
  
  public static void main(String[] args) throws IOException, InterruptedException {
    long time0 = System.currentTimeMillis();
    if (args.length < 1) {
      System.out.println("Remember command line argument");
      System.exit(1);
    }
    QualifierB runner = new QualifierB(args[0]);
    ArrayList<String> results = runner.calculate();
    System.out.println("Run time: " + (System.currentTimeMillis() - time0) / 1000 + "s\n");
    FileWriter fw = new FileWriter("results.txt");
    BufferedWriter bw = new BufferedWriter(fw);
    for (int i = 0; i < results.size(); ++i) {
      System.out.println("Case #" + (i + 1) + ": " + results.get(i));
      bw.write("Case #" + (i + 1) + ": " + results.get(i) + "\n");
    }
    bw.close();
    fw.close();
  }
}
