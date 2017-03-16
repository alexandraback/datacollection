import java.io.*;
import java.util.HashMap;
import java.util.Scanner;

public class R1BA {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new BufferedReader(new FileReader(new File("R1BA.in"))));
        PrintWriter pw = new PrintWriter(new FileWriter(new File("R1BA.out")));
        int testNum = sc.nextInt();
        for (int t = 0; t < testNum; ++t) {
            long result;
            long num = sc.nextInt();
            result = try1(num);
            //result = try2(num);
            pw.println("Case #" + (t + 1) + ": " + result);
        }
        pw.close();
        sc.close();
    }

    private static HashMap<Long, Long> cache = new HashMap<>() ;

    private static long count(long num) {
        if (cache.containsKey(num)) {
            return cache.get(num) ;
        }
        long c1 = count(num-1) ;
        long c2 = (long) 1e15;
        if (num%10 != 0 && reverse(num) != num && reverse(num) < num*1.1) {
            c2 = count(reverse(num));
        }
        if (c1 > c2) {
            cache.put(num, c2+1);
            return c2 + 1;
        } else {
            cache.put(num, c1+1);
            return c1 + 1;
        }
    }

    private static long try2(long num) {
        cache.put(1l, 1l);
        try {
            return count(num);
        } catch (StackOverflowError e) {
            return -1;
        }
    }

    private static long try1(long num) {
        long result = 1;
        int lgnum = getLength(num);
        long cur = 1 ;
        if (getLastHalf(num) == 0) {
            num--;
            result++ ;
        }
        while (cur < num) {
            System.out.println("" + cur + "(" + result + ")" + " -> " + num);
            int length = getLength(cur);
            if (length < lgnum && is1000001(cur)) {
                if (length == 1) {
                    result+=8;
                    cur = 9;
                }
                // 999..9-ig megyünk
                else if (length % 2 == 0) {
                    result += ((long) Math.pow(10, length/2)-2)*2+1;
                    cur = (long)Math.pow(10, length)-1;
                }
                else {
                    result += ((long) Math.pow(10, length/2)-2)+1+((long) Math.pow(10, length/2+1)-2);
                    cur = (long)Math.pow(10, length)-1;
                }
            } else if (length < lgnum) {
                result++;
                cur++;
            } else if (length == lgnum && is1000001(cur)) {
                if (length == 1) {
                    result += num - cur;
                    cur = num;
                } else if (length % 2 == 0) {
                    // Végét megnöveljük
                    cur += getLastHalf(num) - 1;
                    result += getLastHalf(num) - 1;
                    // Ha kell, akkor az elejét
                    if (getFistHalf(num) != ((long) Math.pow(10, length / 2 - 1))) {
                        result++; // Fordítás
                        result += reverse(getFistHalf(num)) - 1;
                        cur = num;
                    }
                } else {
                    // Végét megnöveljük
                    cur += getLastHalf(num) - 1;
                    result += getLastHalf(num) - 1;

                    // Ha kell, akkor az elejét
                    if (num / ((long) Math.pow(10, length / 2 + 1)) != ((long) Math.pow(10, length / 2 - 1))) {
                        result++; // Fordítás
                        result += reverse(getFistHalf(num)) - 1;
                        cur = num;
                    }
                }
            } else {
                result++;
                cur++;
                System.out.println("H");
            }
        }
        return result;
    }

    private static long reverse(long num) {
        long reverse = 0;
        while (num != 0)
        {
            reverse *= 10;
            reverse += num%10;
            num /= 10;
        }
        return reverse;
    }

    private static long getLastHalf(long num) {
        int length = getLength(num);
        if (length % 2 == 0) {
            return num % ((long) Math.pow(10, length / 2));
        } else {
            return num % ((long) Math.pow(10, length / 2 + 1));
        }
    }

    private static long getFistHalf(long num) {
        int length = getLength(num);
        if (length % 2 == 0) {
            return num / ((long) Math.pow(10, length/2));
        } else {
            return num / ((long) Math.pow(10, length/2+1));
        }
    }

    private static boolean is1000001(long cur) {
        int length = getLength(cur);
        return cur == (long)Math.pow(10, length-1)+1 || cur == 1;
    }

    private static int getLength(long num) {
        return (int) Math.floor(Math.log10(num)) + 1;
    }
}
