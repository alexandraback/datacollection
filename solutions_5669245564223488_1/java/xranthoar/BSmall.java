import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by xianran on 5/11/14.
 */
public class BSmall {

    static boolean[] used;
    static List<String> cars;
    static int N;
    static String finalResult = "";
    static long magic = 1000000007;

    static boolean checkPass(String str) {
        long len = str.length();

        for (char c = 'a'; c <= 'z'; c++) {
            int last = 0;
            boolean first = true;
            for (int i = 0; i < len; i++) {
                if (str.charAt(i) == c) {
                    if (first) {
                        last = i;
                        first = false;
                    } else {
                        if (i != last+1) {
                            return false;
                        } else {
                            last = i;
                        }
                    }
                }
            }
        }

        return true;
    }

    public static long solve(int step)
    {
        if (step == N) {
            if (checkPass(finalResult))
                return 1;
            else
                return 0;
        }
        long sum = 0;

        for (int i = 0; i < N; i++) {
            if (used[i])
                continue;

            String temp = finalResult;
            used[i] = true;
            finalResult += cars.get(i);
            sum += solve(step+1) % 1000000007;
            used[i] = false;
            finalResult = temp;
        }

        return sum;
    }

    public static void simpler() {
        int len = cars.size();

        for (int i = 0; i < len; i++) {
            String handle = "";
            handle += String.valueOf(cars.get(i).charAt(0));

            for (int j = 1; j < cars.get(i).length(); j++) {
                if (cars.get(i).charAt(j) == handle.charAt(handle.length()-1)) {
                    // nothing
                } else {
                    handle += String.valueOf(cars.get(i).charAt(j));
                }
            }
            cars.set(i, handle);
        }
    }

    static boolean testValid()
    {
        for (int i = 0; i < cars.size(); i++) {
            if (!checkPass(cars.get(i))) {
                return false;
            }
        }

        for (int i = 0; i < cars.size(); i++) {
            String icar = cars.get(i);
            for (int j = 1; j < icar.length()-1; j++) {
                if (icar.charAt(j) != icar.charAt(0) && icar.charAt(j) != icar.charAt(icar.length()-1)) {
                    for (int k = 0; k < cars.size(); k++) {
                        if (k == i)
                            continue;
                        String kcar = cars.get(k);
                        for (int l = 0; l < kcar.length(); l++) {
                            if (icar.charAt(j) == kcar.charAt(l))
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    static List<String> startswith(char c) {
        List<String> alist = new ArrayList<String>();
        List<String> toremove = new ArrayList<String>();
        for (int i = 0; i < cars.size(); i++) {
            String s = cars.get(i);
            if (s.charAt(0) == c) {
                alist.add(cars.get(i));
                toremove.add(cars.get(i));
            }
        }

        for (String i : toremove) {
            cars.remove(i);
        }

        return alist;
    }

    static List<String> endswith(char c) {
        List<String> alist = new ArrayList<String>();
        List<String> toremove = new ArrayList<String>();
        for (int i = 0; i < cars.size(); i++) {
            String s = cars.get(i);
            if (s.charAt(s.length()-1) == c) {
                alist.add(cars.get(i));
                toremove.add(cars.get(i));
            }
        }

        for (String i : toremove) {
            cars.remove(i);
        }

        return alist;
    }

    static List<String> allwith(char c) {
        List<String> alist = new ArrayList<String>();
        List<String> toremove = new ArrayList<String>();
        for (int i = 0; i < cars.size(); i++) {
            String s = cars.get(i);
            if (s.charAt(0) == c && s.charAt(s.length()-1) == c) {
                alist.add(cars.get(i));
                toremove.add(cars.get(i));
            }
        }

        for (String i : toremove) {
            cars.remove(i);
        }

        return alist;
    }

    static long fac(long n) {
        if (n == 1 || n == 0)
            return 1;
        else return ((fac(n-1) % magic) * (n % magic)) % magic;
    }

    static long combine() {
        long sum = 1;
        for (char c = 'a'; c <= 'z'; c++) {
            List<String> alls = allwith(c);
            List<String> starts = startswith(c);
            List<String> ends = endswith(c);

            if (starts.size() == 0 && alls.size() == 0 && ends.size() == 0)
                continue;

            if (starts.size() > 1 || ends.size() > 1) {
                return 0;
            } else {
                String after;
                long factor = fac(alls.size());
                sum = ((sum % magic) * (factor % magic)) % magic;
                String st = String.valueOf(c), ed = String.valueOf(c), mi = String.valueOf(c);
                if (ends.size() == 1) {
                    st = ends.get(0);
                }

                if (starts.size() == 1) {
                    ed = starts.get(0);
                }

                after = st.substring(0, st.length()-1) + String.valueOf(c) + ed.substring(1, ed.length());
                cars.add(after);
            }
        }
        System.out.println(cars);
        sum = ((sum % magic) * (fac(cars.size()) % magic)) % magic;

        return sum;
    }

    static public void main(String[] args) throws Exception {
        int ntest;
        Scanner scanner = new Scanner(System.in);
        ntest = scanner.nextInt();
        PrintWriter writer = new PrintWriter(new FileWriter("answer.txt"));

        scanner.nextLine();
        for (int nt = 1; nt <= ntest; nt++) {
            N = scanner.nextInt();
            scanner.nextLine();
            String[] sp = scanner.nextLine().split(" ");

            cars = new ArrayList<String>();

            for (String s : sp) {
                cars.add(s);
            }
            simpler();

            boolean valid = testValid();

            if (!valid) {
                writer.println("Case #" + nt + ": " + 0);
            } else {
                long res = combine();
                writer.println("Case #" + nt + ": " + res);
            }
        }

        scanner.close();
        writer.close();
    }
}
