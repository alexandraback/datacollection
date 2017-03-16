package com.meituan.tests.topcoder.jam2013;

import com.meituan.service.GarUtils;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class ManageEnergy {

    public long cal(int e, int r, int n, int[] v) {
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
            int val=remain[min]+r*(index-min);
            if(val>e) {
                val=e;
            }
            int a=spends[max]+remain[max]-(max-index)*r;
            if(a<0) {
                a=0;
            }
            assert val>=a;
            p[index]=true;
            spends[index]=val-a;
            remain[index]=a;
        }
        long total=0;
        for(int i=1;i<=n;i++) {
            total+=spends[i]*v[i];
        }
        return total;
    }

    public static void main(String[] args) throws Exception {
        ManageEnergy test = new ManageEnergy();
        //test.test();
        File file = new File("/Users/zms/Downloads/B-small-attempt1.in");
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
                    writer.printf("Case #%d: %d\n", i + 1, test.cal(a, b, c, v));
                }
                writer.flush();
            }
        }
    }

}
