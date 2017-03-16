package abishev.gcj2015.qual.p4;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

public class OminousOmino implements TaskFactory {
  @Override
  public Task create() {
    return new Task() {
      int x, r, c; // r <= c
      boolean cannotFill;

      @Override
      public void input(Scanner input) {
        x = input.nextInt();
        r = input.nextInt();
        c = input.nextInt();
        if (r > c) {
          int tmp = r;
          r = c;
          c = tmp;
        }
      }

      @Override
      public void run() {
        if ((r * c) % x != 0) {
          cannotFill = true;
          return;
        }

        if (x == 1) {
          cannotFill = false;
          return;
        }
        if (x == 2) {
          cannotFill = false;
          return;
        }
        if (x == 3) {
          cannotFill = r == 1;
          return;
        }
        if (x == 4) {
          cannotFill = r <= 2;
          return;
        }

        throw new IllegalStateException();
      }

      @Override
      public void output(PrintWriter output) {
        output.println(cannotFill ? "RICHARD" : "GABRIEL");
      }
    };
  }

  public static void main(String[] args) throws InterruptedException, IOException {
//    Runner.run(new OminousOmino());
    Runner.run(new OminousOmino(), "D-small-attempt0");
//    Runner.run(new OminousOmino(), "D-large");
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