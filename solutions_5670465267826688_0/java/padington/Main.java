import java.io.FileInputStream;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.List;
import java.io.FilenameFilter;
import java.util.Locale;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author padington
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        final int L = in.nextInt();
        final int X = in.nextInt();
        final int N = L * X;
        String s = in.next();

        List<Integer> listI = new ArrayList<>();
        Struct res = Struct.getOne();
        for (int i = 0; i < N - 2; i++) {
            multiply(res, s.charAt(i % L));
            if (res.sign == 1 && res.c == 'i') {
                listI.add(i);
            }
        }

        List<Integer> listK = new ArrayList<>();
        res = Struct.getOne();
        for (int i = N - 1; i > 1; i--) {
            char sw = res.c;
            res.c = s.charAt(i % L);
            multiply(res, sw);
            if (res.sign == 1 && res.c == 'k') {
                listK.add(i);
            }
        }
        Collections.reverse(listK);

        for (int I : listI) {
            res = Struct.getOne();
            int last = I + 1;
            for (int K : listK) {
                if (K < I) {
                    continue;
                }
                for (int j = last; j < K; j++) {
                    multiply(res, s.charAt(j % L));
                }
                if (res.sign == 1 && res.c == 'j') {
                    out.println(String.format("Case #%d: YES", testNumber));
                    return;
                }
                last = K;
            }
        }

        out.println(String.format("Case #%d: NO", testNumber));
    }

    public static class Struct {
        int sign;
        char c;

        public Struct(int sign, char c) {
            this.sign = sign;
            this.c = c;
        }

        public static Struct getOne() {
            return new Struct(1, '1');
        }
    }

    private void multiply(Struct res, char b) {
        if (b == '1') {
            return;
        }

        if (res.c == '1') {
            res.c = b;
        } else if (res.c > b) {
            res.sign *= -1;
            char sw = res.c; res.c = b; b = sw; //swap
            multiply(res, b);
        } else if (res.c == b) {
            res.sign *= -1;
            res.c = '1';
        } else if (res.c == 'i') {
            if (b == 'j') {
                res.c = 'k';
            } else {
                res.sign *= -1;
                res.c = 'j';
            }
        } else {
            res.c = 'i';
        }
    }

}

