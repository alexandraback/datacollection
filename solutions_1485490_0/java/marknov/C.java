package googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {

    /**
     * @param args
     */
    public static final String FILE_IN = "C-small-attempt0.in";
    public static final String FILE_OUT = "C.out";
    public Scanner scanner;
    public PrintStream printer;
    public PrintStream writer;
    public int T, N, M;
    public int cases = 0;
    List<Data> box;
    List<Data> toys;

    class Data {

        int type;
        long count;

        Data(int type, long count) {
            this.type = type;
            this.count = count;
        }
    }

    public void solveProblem() {
        T = scanner.nextInt();
        while (cases++ < T) {
            N = scanner.nextInt();
            M = scanner.nextInt();

            box = new ArrayList<Data>();
            toys = new ArrayList<Data>();

            for (int i = 0; i < N; i++) {
                long a = scanner.nextLong();
                int A = scanner.nextInt();
                box.add(new Data(A, a));
            }

            for (int i = 0; i < M; i++) {
                long b = scanner.nextLong();
                int B = scanner.nextInt();
                toys.add(new Data(B, b));
            }

            long sum = 0;
            int i = 0;
            int j = 0;
            while (i < N && j < M) {
                if (box.get(i).type == toys.get(j).type) {
                    if (box.get(i).count <= toys.get(j).count) {
                        sum += box.get(i).count;
                        toys.get(j).count -= box.get(i).count;
                        i++;
                    } else {
                        sum += toys.get(j).count;
                        box.get(i).count -= toys.get(j).count;
                        j++;
                    }
                    continue;
                }
                // Pocitane pre Box
                long cBox = 0;
                long sBox = 0;
                long pokBox = 0;
                for (int n = j; n < M; n++) {
                    if (box.get(i).type != toys.get(n).type) {
                        cBox += toys.get(n).count;
                    } else {
                        pokBox = Math.min(box.get(i).count, toys.get(n).count);
                        sBox = n - j;
                        break;
                    }
                }
                // Vypocet potrebnych krokov na zhodu
                long cToy = 0;
                long sToy = 0;
                long pokToy = 0;
                for (int m = i; m < N; m++) {
                    if (toys.get(j).type != box.get(m).type) {
                        cToy += box.get(m).count;
                    } else {
                        pokToy = Math.min(box.get(m).count, toys.get(j).count);
                        sToy = m - i;
                        break;
                    }
                }

                if (sToy == 0 && sBox == 0) {
                    break;
                }
                
                if (pokBox > pokToy) {
                    j += sBox;
                } else {
                    i += sToy;
                }

//                if (cToy <= cBox) {
//                    if (pokBox > pokToy) {
//                        j += sBox;
//                    } else {
//                        i += sToy;
//                    }
//                } else {
//                    if (pokToy > pokBox) {
//                        i += sToy;
//                    }
//                    j += sBox;
//                }
            }

            printer.format("Case #%d: %d\n", cases, sum);
            writer.format("Case #%d: %d\n", cases, sum);
        }
    }

    public void write(long num) {
        System.out.println(num);
    }

    public static void main(String[] args) {
        C googleJam = new C();
        googleJam.openFiles();
        googleJam.solveProblem();
        googleJam.closeFiles();
    }

    public int openFiles() {
        try {
            scanner = new Scanner(new File(FILE_IN));
            printer = new PrintStream(FILE_OUT);
            writer = System.out;
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
            return -1;
        }
        return 0;
    }

    public int closeFiles() {
        scanner.close();
        printer.close();
        return 0;
    }
}
