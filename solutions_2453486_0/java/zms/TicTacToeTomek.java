package com.meituan.tests.topcoder.jam2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class TicTacToeTomek {

    private int[] ints = new int[120];

    private boolean hasEmpty;

    private void reset() {
        ints['X'] = 0;
        ints['O'] = 0;
        ints['T'] = 0;
        ints['.'] = 0;
    }

    private String guess() {
        if (ints['.'] > 0) {
            hasEmpty = true;
        }
        if (ints['X'] == 4 || (ints['X'] == 3 && ints['T'] == 1)) {
            return "X won";
        }
        if (ints['O'] == 4 || (ints['O'] == 3 && ints['T'] == 1)) {
            return "O won";
        }
        return null;
    }

    public String test(String[] lines) {
        hasEmpty = false;
        String s;
        for (String line : lines) {
            reset();
            for (int i = 0; i < 4; i++) {
                ints[line.charAt(i)]++;
            }
            if ((s = guess()) != null) {
                return s;
            }
        }
        char[] chars = new char[4];
        String[] ls = new String[6];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                chars[j] = lines[j].charAt(i);
            }
            ls[i] = new String(chars);
        }
        for (int i = 0; i < 4; i++) {
            chars[i] = lines[i].charAt(i);
        }
        ls[4] = new String(chars);
        for (int i = 0; i < 4; i++) {
            chars[i] = lines[i].charAt(3 - i);
        }
        ls[5] = new String(chars);
        for (String line : ls) {
            reset();
            for (int i = 0; i < 4; i++) {
                ints[line.charAt(i)]++;
            }
            if ((s = guess()) != null) {
                return s;
            }
        }
        if (hasEmpty) {
            return "Game has not completed";
        } else {
            return "Draw";
        }
    }

    public static void main(String[] args) throws Exception {
        TicTacToeTomek test = new TicTacToeTomek();
        File file = new File("/Users/zms/Downloads/A-small-attempt1.in");
        System.out.println(file.exists());
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            File out = new File(file.getParentFile(), "a10.dat");
            try (PrintWriter writer = new PrintWriter(out)) {
                int count = Integer.parseInt(reader.readLine());
                String[] lines = new String[4];
                for (int i = 0; i < count; i++) {
                    for (int j = 0; j < 4; j++) {
                        lines[j] = reader.readLine();
                    }
                    String line = reader.readLine();
                    assert line==null || line.length() < 1;
                    writer.printf("Case #%d: %s\n", i + 1, test.test(lines));
                }
                writer.flush();
            }
        }
    }

}
