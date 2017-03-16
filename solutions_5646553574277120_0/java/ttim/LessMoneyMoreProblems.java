package abishev.gcj2015.round1c.p3;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

class LessMoneyMoreProblems implements TaskFactory {

  @Override
  public Task create() {
    return new Task() {
      int c;
      int d;
      int v;
      int[] existing;
      int ans;

      @Override
      public void input(Scanner input) {
        c = input.nextInt();
        d = input.nextInt();
        v = input.nextInt();
        existing = new int[d];
        for (int i = 0; i < d; i++) existing[i] = input.nextInt();
      }

      @Override
      public void run() {
        assert c == 1;

        boolean[] possibles = new boolean[v + 1];
        possibles[0] = true;
        for (int nominal : existing) apply(possibles, nominal);

        ans = 0;
        for (int i = 1; i <= v; i++) {
          if (!possibles[i]) {
            ans++;
            apply(possibles, i);
          }
        }
      }

      private void apply(boolean[] possibles, int nominal) {
        for (int i = v - nominal; i >= 0; i--) {
          if (possibles[i]) {
            possibles[i + nominal] = true;
          }
        }
      }

      @Override
      public void output(PrintWriter output) {
        output.println(ans);
      }
    };
  }

  public static void main(String[] args) throws InterruptedException, IOException {
//    Runner.run(new LessMoneyMoreProblems());
    Runner.run(new LessMoneyMoreProblems(), "C-small-attempt0");
//    Runner.run(new LessMoneyMoreProblems(), "C-large");
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