package com.company;


import java.util.Scanner;

public class Main {


    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        for (int qNum=1; qNum<=T; qNum++) {
            int K = scanner.nextInt();
            int L = scanner.nextInt();
            int S = scanner.nextInt();

            String keys = scanner.next();
            String target = scanner.next();

            float sol = getSol(K, L, S, keys, target);

            System.out.println("Case #"+qNum+": "+sol);
//            if (ret == 0) {
//                System.out.println("error in case #"+qNum);
//                return;
//            }
        }
    }

    static float getSol(int K, int L, int S, String keys, String target) {
        int cnt[] = new int[L];

        for (int i=0; i<L; i++) {
            for (int j=0; j<K; j++) {
                if (target.charAt(i) == keys.charAt(j)) cnt[i]++;
            }
            if (cnt[i] == 0) return 0f;
        }
        int realLen = L;
        for (int i=1; i<L; i++) {
            String front = target.substring(0, L-i);
            String back = target.substring(i);
            if (front.equals(back)) {
                realLen = i;
                break;
            }
        }
        int max = (S - L + realLen)/realLen;
        float rate1 = 1f;
        float rate2 = 1f;
        for (int i=0; i<L; i++) {
            if (i<realLen)
                rate1 *= (float)cnt[i]/K;
            else
                rate2 *= (float)cnt[i]/K;
        }
//        System.out.println("real:"+realLen+"max:"+max+"rate1:"+rate1 + "rate2:"+rate2);
        float sum = 0f;
        float rateSum = 0f;
        for (int i=max; i>=1; i--) {
            sum += i*((Math.pow(rate1,i)*rate2)*(S-realLen*(i-1)-L+1)-rateSum);
            rateSum = (float)Math.pow(rate1,i)*rate2*i;
//            System.out.println("sum:"+sum);
//            System.out.println("ret:"+i*(Math.pow(rate1,i)*rate2)*(S-realLen*(i-1)-L+1));
        }
        return max - sum;
    }

}


