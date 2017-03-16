package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for (int i = 0; i < cases; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int w = scanner.nextInt();
            int checksPerRow = c / w;
            int insuranceChecks = checksPerRow * r;
            int totalChecks = insuranceChecks;
            int length = w + c % w;
            if(length > w)
            {
                totalChecks+= 1;
            }
            totalChecks += w - 1;
            int[] checks = new int[length];

            System.out.println("Case #" + Integer.toString(i + 1) + ": " + Integer.toString(totalChecks));
        }
    }
}
