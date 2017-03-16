package com.company;


import java.util.Scanner;

public class Main {


    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        for (int qNum=1; qNum<=T; qNum++) {
            int R = scanner.nextInt();
            int C = scanner.nextInt();
            int W = scanner.nextInt();

            int sol = getSol(R, C, W);

            System.out.println("Case #"+qNum+": "+sol);
//            if (ret == 0) {
//                System.out.println("error in case #"+qNum);
//                return;
//            }
        }
    }

    static int getSol(int R, int C, int W) {
        int numForR = C / W;
        return (R-1) * numForR + (C-1)/W + W;
    }

}


