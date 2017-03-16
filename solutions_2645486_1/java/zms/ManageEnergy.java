package com.meituan.tests.topcoder.jam2013;

import com.meituan.service.GarUtils;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class ManageEnergy {

    public BigInteger cal(int e, int r, int n, int[] v) {
        Map<Integer,Integer> map=new LinkedHashMap<>();
        for(int i=1;i<=n;i++) {
            map.put(i,v[i]);
        }
        map = GarUtils.sortMapByValue(map,true);

        boolean[] p=new boolean[n+2];
        int[] spends=new int[n+2];
        int[] remain=new int[n+2];

        p[0]=true;
        spends[0]=0;
        remain[0]=Math.max(0,e-r);

        p[n+1]=true;
        spends[n+1]=0;
        remain[n+1]=r;

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int index=entry.getKey();
            int min=index;
            while(!p[min]) {
                min--;
            }
            int max=index;
            while(!p[max]) {
                max++;
            }
            long val=remain[min]+r*1L*(index-min);
            if(val>e) {
                val=e;
            }
            long a=spends[max]+0L+remain[max]-(max-index)*1L*r;
            if(a<0) {
                a=0;
            }
            assert val>=a;
            p[index]=true;
            spends[index]=(int)(val-a);
            remain[index]=(int)a;
        }

        BigInteger total=BigInteger.ZERO;
        for(int i=1;i<=n;i++) {
            total=total.add(BigInteger.valueOf(spends[i]*1L*v[i]));
        }
        return total;
    }

    public static void main(String[] args) throws Exception {
        ManageEnergy test = new ManageEnergy();
        //test.test();
        File file = new File("/Users/zms/Downloads/B-large.in");
        System.out.println(file.exists());
        try (Scanner scanner = new Scanner(new FileReader(file))) {
            File out = new File(file.getParentFile(), "b.dat");
            try (PrintWriter writer = new PrintWriter(out)) {
                int count = scanner.nextInt();
                for (int i = 0; i < count; i++) {
                    int a = scanner.nextInt();
                    int b = scanner.nextInt();
                    int c = scanner.nextInt();
                    int[] v = new int[c+1];
                    for (int j = 1; j <= c; j++) {
                        v[j] = scanner.nextInt();
                    }
                    writer.printf("Case #%d: ", i + 1);
                    writer.println(test.cal(a, b, c, v));
                }
                writer.flush();
            }
        }
    }

}
