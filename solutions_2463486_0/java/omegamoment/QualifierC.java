import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class QualifierC {
  public HashSet<Long> squares;
  
  public boolean isPalindrome(String num) {
    if (num.length() < 2) {
      return true;
    }
    int i = 0;
    int j = num.length() - 1;
    while (i < j) {
      if (num.charAt(i) != num.charAt(j)) {
        return false;
      }
      ++i;
      --j;
    }
    return true;
  }
  
  class Task implements Runnable {
    private final int num;
    private final long a;
    private final long b;
    
    public Task(int num, long a, long b) {
      this.num = num;
      this.a = a;
      this.b = b;
    }
    
    @Override
    public void run() {
      String result = null;
      
      // BEGIN RESULT COMPUTATION
      // ------------------------------------------------------------
      
      int count = 0;
      
      for (long num = a; num <= b; ++num) {
        if (squares.contains(num) && isPalindrome(String.valueOf(num))) {
          ++count;
        }
      }
      
      result = String.valueOf(count);
      
      // END RESULT COMPUTATION
      // ------------------------------------------------------------
      
      System.out.println(result);
      reportResult(num, result);
    }
  }
  
  public static final int NUM_THREADS = 4;
  
  private final String file_name;
  private ArrayList<String> results;
  
  public QualifierC(String file_name) {
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
    
    long min = 1L;
    long max = 10000000L;
    squares = new HashSet<Long>();
    for (long num = min; num <= max; ++num) {
      if (isPalindrome(String.valueOf(num))) {
        squares.add(num * num);
      }
    }
    System.out.println(squares);
    System.out.println(Long.MAX_VALUE);
    
    // END HEADER PARSING
    // --------------------------------------------------------------------
    
    for (int i = 0; i < total_num; ++i) {
      results.add("");
      
      // BEGIN READING CASE
      // ----------------------------------------------------------------
      
      line = br.readLine();
      String[] split_line = line.split(" ");
      long a = Long.parseLong(split_line[0]);
      long b = Long.parseLong(split_line[1]);
      tpe.execute(new Task(i, a, b));
      
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
    QualifierC runner = new QualifierC(args[0]);
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
