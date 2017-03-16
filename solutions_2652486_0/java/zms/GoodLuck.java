package com.meituan.tests.topcoder.jam2013;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class GoodLuck {

    public String[] cal(int r, int n, int m, int k,int[][] data) {
        int[] poss=new int[1+3+3+1];
        StringBuilder buffer=new StringBuilder();
        String[] result=new String[r];
        out1:for(int i=0;i<r;i++) {
            int[] one=data[i];
            for (int a = 2; a <= m; a++) {
                for (int b = 2; b <= m; b++) {
                    for (int c = 2; c <= m; c++) {
                        poss[0]=1;
                        poss[1]=a;
                        poss[2]=b;
                        poss[3]=c;
                        poss[4]=a*b;
                        poss[5]=a*c;
                        poss[6]=b*c;
                        poss[7]=a*b*c;
                        boolean ok=true;
                        out:for(int j=0;j<k;j++) {
                            for(int t=0;t<8;t++) {
                                if(poss[t]==one[j]) {
                                    continue out;
                                }
                            }
                            ok=false;
                            break;
                        }
                        if(ok) {
                            buffer.setLength(0);
                            buffer.append(a).append(b).append(c);
                            result[i]=buffer.toString();
                            continue out1;
                        }
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
        GoodLuck test = new GoodLuck();
        //test.test();
        File file = new File("/Users/zms/Downloads/C-small-1-attempt0.in");
        System.out.println(file.exists());
        try (Scanner scanner = new Scanner(new FileReader(file))) {
            File out = new File(file.getParentFile(), "b.dat");
            try (PrintWriter writer = new PrintWriter(out)) {
                int count = scanner.nextInt();
                for (int i = 0; i < count; i++) {
                    int a=scanner.nextInt();
                    int b=scanner.nextInt();
                    int c=scanner.nextInt();
                    int d=scanner.nextInt();
                    int[][] data=new int[a][d];
                    for(int j=0;j<a;j++) {
                        for(int k=0;k<d;k++) {
                            data[j][k]=scanner.nextInt();
                        }
                    }
                    String[] results=test.cal(a,b,c,d,data);
                    writer.printf("Case #%d: \n", i + 1);
                    for(int j=0;j<a;j++) {
                        writer.println(results[j]);
                    }
                }
                writer.flush();
            }
        }
    }
}
