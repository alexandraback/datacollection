package Qualification2015;

import java.util.Scanner;

public class C {
    static class Quaternion {
        int t, x, y, z;

        Quaternion() {}
        Quaternion(char c) {
            if (c == 'i')
                x = 1;
            else if (c == 'j')
                y = 1;
            else if (c == 'k')
                z = 1;
        }
        Quaternion(int t, int x, int y, int z) {
            this.t = t;
            this.x = x;
            this.y = y;
            this.z = z;
        }
        Quaternion mult(Quaternion other) {
            Quaternion result = new Quaternion();
            result.t = this.t * other.t - this.x * other.x - this.y * other.y - this.z * other.z;
            result.x = this.t * other.x + this.x * other.t + this.y * other.z - this.z * other.y;
            result.y = this.t * other.y + this.y * other.t + this.z * other.x - this.x * other.z;
            result.z = this.t * other.z + this.z * other.t + this.x * other.y - this.y * other.x;
            return result;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Quaternion that = (Quaternion) o;

            if (t != that.t) return false;
            if (x != that.x) return false;
            if (y != that.y) return false;
            if (z != that.z) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = t;
            result = 31 * result + x;
            result = 31 * result + y;
            result = 31 * result + z;
            return result;
        }

        @Override
        public String toString() {
            return "Quaternion{" +
                    "t=" + t +
                    ", x=" + x +
                    ", y=" + y +
                    ", z=" + z +
                    '}';
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            long l = sc.nextLong();
            long x = sc.nextLong();
            String word = sc.next();
            Quaternion current = new Quaternion(1, 0, 0, 0);
            boolean seenI = false;
            boolean seenK = false;
            Quaternion I = new Quaternion('i');
            Quaternion K = new Quaternion('k');
            Quaternion overall = null;
            for (long j = 0; j < Math.min(6, x); ++j) {
                for (int i = 0; i < l; ++i) {
                    char c = word.charAt(i);
                    current = current.mult(new Quaternion(c));
                    if (current.equals(I)) {
                        seenI = true;
                    }
                    if (seenI && current.equals(K)) {
                        seenK = true;
                    }
//                    System.out.println(current);
                }
                if (j == 0)
                    overall = current;
            }
            current = new Quaternion(1, 0, 0, 0);
            for (int i = 0; i < x % 8; ++i)
                current = current.mult(overall);
            System.out.printf("Case #%d: ", testCase);
            if (seenI && seenK && current.equals(new Quaternion(-1, 0,0,0)))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}