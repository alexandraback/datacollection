package current.b;


import com.google.common.base.Function;
import com.google.common.collect.Lists;
import org.apache.commons.io.IOUtils;

import java.io.*;
import java.util.List;
import java.util.Scanner;

public class B extends Problem<Case> {
    @Override
    public String solve(Case aCase) {
        int count = 0;
        for (int ta = 0; ta < aCase.getA(); ta++) {
            for (int tb = 0; tb < aCase.getB(); tb++) {
                int tc = ta & tb;
                if (tc < aCase.getK()) {
                    count++;
                }
            }
        }
        return String.valueOf(count);
    }

    @Override
    public List<Case> parse(String data) {
        final Scanner sc = new Scanner(data);
        final List<Case> cases = Lists.newArrayList();
        long num_cases = sc.nextLong();
        for (int case_num = 0; case_num < num_cases; case_num++) {
            Case aCase = new Case(sc.nextInt(), sc.nextInt(), sc.nextInt());
            cases.add(aCase);
        }
        return cases;
    }

    @Override
    public void preCompute() {
    }

    public static void main(String[] args) {
        Problem problem = new B();
        problem.main(args[0]);
    }
}

class Case {
    private int a, b, k;
    public Case(int a, int b, int k) {
        this.a = a;
        this.b = b;
        this.k = k;
    }

    public int getA() {
        return a;
    }

    public int getB() {
        return b;
    }

    public int getK() {
        return k;
    }
}


abstract class Problem<T> {
    public abstract String solve(T t);
    public abstract List<T> parse(final String data);
    public abstract void preCompute();

    public void display(final List<String> results, final String filename) {
        final String base = filename.substring(0, filename.lastIndexOf('.'));
        final String outFileName = base + ".out";

        BufferedWriter writer = null;
        try {
            writer = new BufferedWriter(new FileWriter(new File(outFileName)));
            int case_num = 1;
            for(String result: results) {
                final String answer = String.format("Case #%d: %s", case_num, result);
                System.out.println(answer);
                writer.write(answer + "\n");
                case_num++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            IOUtils.closeQuietly(writer);
        }
    }

    public void main(String filename) {
        preCompute();
        final String data = readLines(filename);
        final List<T> cases = parse(data);
        final List<String> results = Lists.transform(cases, new Function<T, String>() {
            @Override
            public String apply(T t) {
                return solve(t);
            }
        });
        display(results, filename);
    }

    private String readLines(final String filename) {
        try {
            final String content = new Scanner(new File(filename)).useDelimiter("\\Z").next();
            return content;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(1);
        }
        return null;
    }
}
