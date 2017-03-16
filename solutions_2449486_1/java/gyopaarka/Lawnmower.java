package com.fg.codejam.qualification;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

import com.fg.codejam.util.IOUtils;

public class Lawnmower {

    public static final String compute(String[][] lines, int rowCount, int colCount) {
        int[][] ints = new int[rowCount][colCount];
        int[] maxHoriz = new int[rowCount];
        int[] maxVert = new int[colCount];
        for(int hv = 0; hv < 2; hv++) {
            boolean horiz = hv == 0;
            for(int li = 0; li < (horiz ? rowCount : colCount); li++) {
                int max = -1;
                for(int ci = 0; ci < (horiz ? colCount : rowCount); ci++) {
                    int curr = Integer.parseInt(lines[horiz ? li : ci][horiz ? ci : li]);
                    ints[horiz ? li : ci][horiz ? ci : li] = curr;
                    if(curr > max) {
                        max = curr;
                    }
                }
                if(horiz) {
                    maxHoriz[li] = max;
                } else {
                    maxVert[li] = max;
                }
            }
        }
        boolean[][] fail = new boolean[rowCount][colCount];

        for(int hv = 0; hv < 2; hv++) {
            boolean horiz = hv == 0;
            for(int li = 0; li < (horiz ? rowCount : colCount); li++) {
                for(int ci = 0; ci < (horiz ? colCount : rowCount); ci++) {
                    int curr = ints[horiz ? li : ci][horiz ? ci : li];
                    int max = horiz ? maxHoriz[li] : maxVert[li];
                    if(curr < max) {
                        if(horiz) {
                            fail[li][ci] = true;
                        } else {
                            if(fail[ci][li]) {
                                return "NO";
                            }
                        }
                    }
                }
            }
        }
        return "YES";
    }

    public static final void computeFile(InputStream is, OutputStream out)
    throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(is));
        try {
            String[][] mm = new String[100][100];
            String line;
            line = br.readLine(); // number of test cases
            int caseIndex = 1;
            int ri = -1;
            int rowCount = -1;
            int colCount = -1;
            while( (line = br.readLine()) != null ) {
                String[] parts = line.split(" ");
                if(ri == -1) {
                    rowCount = Integer.parseInt(parts[0]);
                    colCount = Integer.parseInt(parts[1]);
                } else {
                    mm[ri] = parts;
                    if(ri == rowCount - 1) {
                        out.write( ("Case #" + caseIndex + ": " + compute(mm, rowCount, colCount) + "\n").getBytes() );
                        ri = -2;
                        caseIndex++;
                    }
                }
                ri++;
            }
        } finally {
            IOUtils.close(br);
        }
    }

    public static void main(String[] args) throws Exception {
        InputStream in = new FileInputStream("c:\\work\\java\\GoogleCodeJam2003\\20130403-Qualification\\input\\Lawnmower\\B-large.in");
        OutputStream out = new FileOutputStream("c:\\work\\java\\GoogleCodeJam2003\\20130403-Qualification\\input\\Lawnmower\\B-large.out");
        try {
            computeFile(in, out);
        } finally {
            IOUtils.close(in);
            IOUtils.close(out);
        }
    }

}
