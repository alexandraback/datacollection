import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Input {

  BufferedReader br;

  Input(String input) throws Exception {
    br = new BufferedReader(new FileReader(input));
  }

  int readint() throws Exception {
    return Integer.parseInt(br.readLine());
  }

  int[] readints() throws Exception {
    StringTokenizer st = new StringTokenizer(br.readLine());
    int count = st.countTokens();
    int[] a = new int[count];
    for (int i = 0; i < count; i++) {
      a[i] = Integer.parseInt(st.nextToken());
    }
    return a;
  }

  long readlong() throws Exception {
    return Long.parseLong(br.readLine());
  }

  long[] readlongs() throws Exception {
    StringTokenizer st = new StringTokenizer(br.readLine());
    int count = st.countTokens();
    long[] a = new long[count];
    for (int i = 0; i < count; i++) {
      a[i] = Long.parseLong(st.nextToken());
    }
    return a;
  }

  String readString() throws Exception {
    return br.readLine();
  }

  String[] readStrings() throws Exception {
    StringTokenizer st = new StringTokenizer(br.readLine());
    int count = st.countTokens();
    String[] a = new String[count];
    for (int i = 0; i < count; i++) {
      a[i] = st.nextToken();
    }
    return a;
  }

  void close() throws Exception {
    br.close();
  }

}

abstract class Worker implements Runnable {

  Master master;
  int id;

  void init(Master master, int id) {
    this.master = master;
    this.id = id;
  }

  public synchronized void run() {
    solve();
    master.onDone(this);
  }

  abstract void read(Input input) throws Exception;
  abstract void solve();
  abstract void write(PrintStream out);

}

class Master {

  int threads = 1;
  Class<? extends Worker> workerClass;
  ExecutorService executor;
  CountDownLatch latch;

  Master(Class<? extends Worker> workerClass) {
    this.workerClass = workerClass;
  }

  void main(String input) throws Exception {
    Input in = new Input(input);
    int t = in.readint();
    if (threads == 1) {
      for (int i = 0; i < t; i++) {
        Worker worker = workerClass.newInstance();
        worker.init(this, i + 1);
        worker.read(in);
        worker.solve();
        worker.write(System.out);
      }
    } else {
      executor = Executors.newFixedThreadPool(threads);
      latch = new CountDownLatch(t);
      LinkedList<Worker> workers = new LinkedList<Worker>();
      for (int i = 0; i < t; i++) {
        Worker worker = workerClass.newInstance();
        synchronized (worker) {
          worker.init(this, i + 1);
          worker.read(in);
        }
        workers.add(worker);
        executor.submit(worker);
      }
      in.close();
      latch.await();
      for (Worker worker : workers) {
        synchronized (worker) {
          worker.write(System.out);
        }
      }
      executor.shutdown();
    }
  }

  void onDone(Worker worker) {
    if (threads == 1) {
      return;
    }
    synchronized (this) {
      System.err.print("deb: ");
      worker.write(System.err);
    }
    latch.countDown();
  }

}
