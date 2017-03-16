package abishev.gcj2015.qual.p3;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

public class Dijkstra implements TaskFactory {
  @Override
  public Task create() {
    return new Task() {
      int l;
      long x;
      int[] s;
      boolean res;

      // 1 - 1
      // i - 2
      // j - 3
      // k - 4
      @Override
      public void input(Scanner input) {
        l = input.nextInt();
        x = input.nextLong();
        input.nextLine();
        String line = input.nextLine();
        s = new int[l];
        for (int i = 0; i < l; i++) {
          if (line.charAt(i) == 'i') {
            s[i] = 2;
          } else if (line.charAt(i) == 'j') {
            s[i] = 3;
          } else if (line.charAt(i) == 'k') {
            s[i] = 4;
          } else throw new IllegalStateException();
        }
      }

      @Override
      public void run() {
        if (x > 48) {
          x = x % 48 + 48;
        }
        int cur = 1;
        int awaiting = 2;
        for (int pos = 0; pos < x * l; pos++) {
          cur = mult(cur, s[pos % l]);
          if (cur == awaiting) {
            cur = 1;
            awaiting++;
          }
        }
        res = awaiting == 5 && cur == 1;
      }

      private int mult(int fst, int snd) {
        if ((fst > 0 && snd > 0) || (fst < 0 && snd < 0)) {
          return multAbs(Math.abs(fst), Math.abs(snd));
        } else {
          return -multAbs(Math.abs(fst), Math.abs(snd));
        }
      }

      private int multAbs(int fst, int snd) {
        if (fst == 1) return snd;
        if (snd == 1) return fst;
        if (fst == snd) return -1;
        if (fst == 2) {
          if (snd == 3) return 4;
          if (snd == 4) return -3;
        }
        if (fst == 3) {
          if (snd == 2) return -4;
          if (snd == 4) return 2;
        }
        if (fst == 4) {
          if (snd == 2) return 3;
          if (snd == 3) return -2;
        }
        throw new IllegalStateException();
      }

      @Override
      public void output(PrintWriter output) {
        output.println(res ? "YES" : "NO");
      }
    };
  }

  public static void main(String[] args) throws InterruptedException, IOException {
//    Runner.run(new Dijkstra());
//    Runner.run(new Dijkstra(), "C-small-attempt0");
    Runner.run(new Dijkstra(), "C-large");
  }
}

interface TaskFactory {
  Task create();
}

interface Task {
  void input(Scanner input);

  void run();

  void output(PrintWriter output);
}

class Runner {
  public static void run(TaskFactory taskFactory, InputStream is, OutputStream os) throws InterruptedException {
    Scanner input = new Scanner(is);
    PrintWriter output = new PrintWriter(os);
    int t = input.nextInt();
    input.nextLine();
    List<Task> tasks = Collections.synchronizedList(new ArrayList<Task>());
    for (int tt = 1; tt <= t; tt++) {
      Task task = taskFactory.create();
      task.input(input);
      tasks.add(task);
    }

    final AtomicInteger doneTasks = new AtomicInteger(0);
    final CountDownLatch latch = new CountDownLatch(t);
    ExecutorService executor = Executors.newFixedThreadPool(8);
    for (final Task task : tasks) {
      executor.execute(new Runnable() {
        @Override
        public void run() {
          task.run();
          int doneTasksV = doneTasks.incrementAndGet();
          if (doneTasksV % 5 == 0) {
            System.out.println("done tasks: " + doneTasksV);
          }
          latch.countDown();
        }
      });
    }
    latch.await();
    executor.shutdown();

    int tt = 0;
    for (Task task : tasks) {
      output.print("Case #" + (++tt) + ": ");
      task.output(output);
      output.flush();
    }
  }

  public static void run(TaskFactory taskFactory) throws InterruptedException {
    run(taskFactory, System.in, System.out);
  }

  public static void run(TaskFactory taskFactory, String taskName) throws IOException, InterruptedException {
    FileInputStream is = new FileInputStream(new File(taskName + ".in"));
    FileOutputStream os = new FileOutputStream(new File(taskName + ".out"));
    run(taskFactory, is, os);
    is.close();
    os.close();
  }
}