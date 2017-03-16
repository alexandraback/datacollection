package abishev.gcj2015.round1c.p2;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

class TypewriterMonkey implements TaskFactory {

  @Override
  public Task create() {
    return new Task() {
      int k;
      int l;
      int s;
      String alphabet;
      String word;

      @Override
      public void input(Scanner input) {
        k = input.nextInt();
        l = input.nextInt();
        s = input.nextInt();
        input.nextLine();
        alphabet = input.nextLine();
        word = input.nextLine();
      }

      int maxWords = 0;
      int genCount = 0;
      int overallWords = 0;

      @Override
      public void run() {
        run(new char[s], 0);
      }

      private void run(char[] chars, int pos) {
        if (pos == chars.length) {
          genCount++;
          int words = calc(chars);
          maxWords = Math.max(maxWords, words);
          overallWords += words;
          return;
        }
        for (int i = 0; i < k; i++) {
          chars[pos] = alphabet.charAt(i);
          run(chars, pos + 1);
        }
      }

      private int calc(char[] chars) {
        int count = 0;
        for (int i = 0; i <= chars.length - word.length(); i++) {
          boolean ok = true;
          for (int j = 0; j < word.length(); j++) {
            if (word.charAt(j) != chars[i + j]) {
              ok = false;
              break;
            }
          }
          if (ok) count++;
        }
        return count;
      }

      @Override
      public void output(PrintWriter output) {
        output.printf("%.9f\n", (maxWords - overallWords * 1.0 / genCount));
      }
    };
  }

  public static void main(String[] args) throws InterruptedException, IOException {
//    Runner.run(new TypewriterMonkey());
    Runner.run(new TypewriterMonkey(), "B-small-attempt0");
//    Runner.run(new TypewriterMonkey(), "B-large");
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