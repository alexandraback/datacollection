package com.fg.codejam.qualification;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

import com.fg.codejam.util.IOUtils;

public class TicTacToeTomek {

    public static final String compute(String[] lines) {
        boolean wasDot = false;
        // horizontally
        char[][] chars = new char[lines.length][];
        for(int li = 0; li < lines.length; li++) {
            char[] curr = lines[li].toCharArray();
            chars[li] = curr;
            int xc = 0;
            int oc = 0;
            for(int ci = 0; ci < chars.length; ci++) {
                char c = curr[ci];
                if(c == '.') {
                    wasDot = true;
                } else if(c == 'X') {
                    xc++;
                } else if(c == 'O') {
                    oc++;
                } else if(c == 'T') {
                    xc++;
                    oc++;
                } else {
                    throw new IllegalArgumentException("Invalid character '" + c + " in line " + lines[li]);
                }
            }
            if(xc == 4) {
                return "X won";
            } else if(oc == 4) {
                return "O won";
            }
        }
        // vertically
        for(int ci = 0; ci < chars[0].length; ci++) {
            int xc = 0;
            int oc = 0;
            for(int li = 0; li < lines.length; li++) {
                char c = chars[li][ci];
                if(c == '.') {
                    wasDot = true;
                } else if(c == 'X') {
                    xc++;
                } else if(c == 'O') {
                    oc++;
                } else if(c == 'T') {
                    xc++;
                    oc++;
                } else {
                    throw new IllegalArgumentException("Invalid character '" + c + " in line " + lines[li]);
                }
            }
            if(xc == 4) {
                return "X won";
            } else if(oc == 4) {
                return "O won";
            }
        }
        // diagonally
        for(int i = 0; i < 2; i++) {
            int xc = 0;
            int oc = 0;
            for(int li = 0; li < lines.length; li++) {
                char c = chars[li][i == 0 ? li : 3 - li];
                if(c == '.') {
                    wasDot = true;
                } else if(c == 'X') {
                    xc++;
                } else if(c == 'O') {
                    oc++;
                } else if(c == 'T') {
                    xc++;
                    oc++;
                } else {
                    throw new IllegalArgumentException("Invalid character '" + c + " in line " + lines[li]);
                }
            }
            if(xc == 4) {
                return "X won";
            } else if(oc == 4) {
                return "O won";
            }
        }
        if(wasDot) {
            return "Game has not completed";
        } else {
            return "Draw";
        }
    }

    public static final void computeFile(InputStream is, OutputStream out)
    throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(is));
        try {
            String[] lines = new String[4];
            String line;
            line = br.readLine(); // number of test cases
            int caseIndex = 1;
            int i = 0;
            while( (line = br.readLine()) != null ) {
                lines[i] = line;
                i++;
                if(i == 4) {
                    out.write( ("Case #" + caseIndex + ": " + compute(lines) + "\n").getBytes() );
                    i = 0;
                    line = br.readLine();
                    caseIndex++;
                }
            }
        } finally {
            IOUtils.close(br);
        }
    }

    public static void main(String[] args) throws Exception {
        InputStream in = new FileInputStream("c:\\work\\java\\GoogleCodeJam2003\\20130403-Qualification\\input\\Tic-Tac-Toe-Tomek\\A-small-attempt0.in");
        OutputStream out = new FileOutputStream("c:\\work\\java\\GoogleCodeJam2003\\20130403-Qualification\\input\\Tic-Tac-Toe-Tomek\\A-small-attempt0.out");
        try {
            computeFile(in, out);
        } finally {
            IOUtils.close(in);
            IOUtils.close(out);
        }
    }

}
