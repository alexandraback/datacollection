package round1A;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

class C {
  public static class Student implements Comparable {
    public Student bbf;
    public ArrayList<Student> adores;

    public Student left;
    public Student right;

    public Student() {
      bbf = null;
      adores = new ArrayList<Student>();

      left = null;
      right = null;
    }

    @Override
    public int compareTo(Object o) {
      Student other = (Student) o;
      return other.adores.size() - adores.size();
    }
  }

  static int want(Student[] students, HashSet<Student> in, Student now, int max) {
    Student bbf = now.bbf;
    if (in.contains(bbf)) {
      if (bbf.left == now || bbf.right == now) {
        in.add(now);
        for (Student next: students) {
          if (!in.contains(next)) {
            next.left = null;
            next.right = null;
            HashSet<Student> copyin = new HashSet<Student>(in);
            if (now.left == null) {
              now.left = next;
              next.right = now;
              max = Math.max(max, want(students, copyin, next, max));
              now.left = null;
            }
            else if (now.right == null) {
              now.right = next;
              next.left = now;
              max = Math.max(max, want(students, copyin, next, max));
              now.right = null;
            }
            else {
              System.out.println("Never in.");
            }
          }
        }
        return Math.max(max, in.size());
      } else if (now.right == null && bbf.left == null) {
//        now.right = bbf;
//        bbf.left = now;
        in.add(now);
        return Math.max(in.size(), max);
      } else if (now.left == null && bbf.right == null) {
//        now.left = bbf;
//        bbf.right = now;
        in.add(now);
        return Math.max(in.size(), max);
      } else {
        return 0;
      }
    } else {
      bbf.left = null;
      bbf.right = null;
      if (now.right == null) {
        now.right = bbf;
        bbf.left = now;
        in.add(now);
        return want(students, in, bbf, max);
      }
      else if (now.left == null) {
        now.left = bbf;
        bbf.right = now;
        in.add(now);
        return want(students, in, bbf, max);
      }
    }

    return 0;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      int N = scanner.nextInt();

      Student students[] = new Student[N];
      for (int i = 0; i < N; i ++) {
        students[i] = new Student();
      }
      for (int i = 0; i < N; i ++) {
        int bbf = scanner.nextInt()-1;
        students[i].bbf = students[bbf];
        students[bbf].adores.add(students[i]);
      }

      int max = 0;
      for (Student next: students) {
        next.left = null;
        next.right = null;
        HashSet<Student> copyin = new HashSet<Student>();
        max = Math.max(max, want(students, copyin, next, max));
      }

      System.out.printf("Case #%d: %d\n", t, max);
    }
  }
}