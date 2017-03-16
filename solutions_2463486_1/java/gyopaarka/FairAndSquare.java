package com.fg.codejam.qualification;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import com.fg.codejam.util.IOUtils;

public class FairAndSquare {

    public static final long compute(long from, long to, List<Long> fass) {
        long ret = 0;
        Iterator<Long> it = fass.iterator();
        while(it.hasNext()) {
            long curr = it.next().longValue();
            if(curr >= from && curr <= to) {
                ret++;
            }
        }
        return ret;
    }

    private static final boolean isPalindrome(long l) {
        String s = String.valueOf(l);
        int length = s.length();
        int lengthHalf = length / 2;
        int i = 0;
        boolean ret = true;
        while(i < lengthHalf) {
            if(s.charAt(i) != s.charAt(length - i - 1)) {
                ret = false;
                break;
            }
            i++;
        }
        return ret;
    }

    public static final void computeFile(InputStream is, OutputStream out)
    throws Exception {
        List<Long> fass = new ArrayList<Long>(100);
        for(long l = 1; l < 10000000l; l++) {
            if(isPalindrome(l) && isPalindrome(l * l)) {
                long sq = l * l;
                //System.out.println(l + "    " + sq);
                fass.add(sq);
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(is));
        try {
            String line;
            line = br.readLine(); // number of test cases
            int caseIndex = 1;
            while( (line = br.readLine()) != null ) {
                String[] parts = line.split(" ");
                out.write( ("Case #" + caseIndex + ": " + compute(Long.parseLong(parts[0]), Long.parseLong(parts[1]), fass) + "\n").getBytes() );
                caseIndex++;
            }
        } finally {
            IOUtils.close(br);
        }
    }

    public static void main(String[] args) throws Exception {
        InputStream in = new FileInputStream("c:\\work\\java\\GoogleCodeJam2003\\20130403-Qualification\\input\\FairAndSquare\\C-large-1.in");
        OutputStream out = new FileOutputStream("c:\\work\\java\\GoogleCodeJam2003\\20130403-Qualification\\input\\FairAndSquare\\C-large-1.out");
        try {
            computeFile(in, out);
        } finally {
            IOUtils.close(in);
            IOUtils.close(out);
        }
    }

}
