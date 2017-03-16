package com.company;

import java.util.Scanner;

public class Main {

    static int[] tempArray;
    static int[] tempMergeArray;
    static int length;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        int[] primes = new int[]
                {
                        2,      3,      5,      7 ,    11,     13,     17,     19,     23,     29,
                        31
                };
        for(int T = 0; T < cases;T++)
        {
            int noCoinRepeats = scanner.nextInt(); // C
            int noCoinTypes = scanner.nextInt(); // D
            int maxPurchaseValue = scanner.nextInt(); //V
            int[] coinTypes = new int[noCoinTypes];
            for(int d = 0; d < noCoinTypes;d++)
            {
                coinTypes[d] = scanner.nextInt();
            }
            for(int i =1; i<= maxPurchaseValue;i++)
            {
                int currentTotal = 0;
                for(int q = coinTypes.length - 1; q>= 0 ;q--)
                {
                    if(currentTotal + coinTypes[q]> i){continue;}
                    currentTotal+= coinTypes[q];
                }
                int remaining = i- currentTotal;
                if(remaining != 0)
                {
                    coinTypes = Add(coinTypes,remaining);
                }
            }
            int newDs = coinTypes.length - noCoinTypes;
            System.out.println("Case #" + Integer.toString(T + 1) + ": " + Integer.toString(newDs));
        }
    }
    public static int[] Add(int[] coinTypes,int newCoinValue) {
        int newCoinTypes[] = new int[coinTypes.length + 1];
        for (int i = 0; i < coinTypes.length; i++)
        {
            newCoinTypes[i] = coinTypes[i];
        }
        newCoinTypes[newCoinTypes.length- 1]= newCoinValue;
        sort(newCoinTypes);
        return newCoinTypes;
    }
    public static void sort(int inputArr[]) {
        tempArray = inputArr;
        length = inputArr.length;
        tempMergeArray = new int[length];
        doMergeSort(0, length - 1);
    }

    private static void doMergeSort(int lowerIndex, int higherIndex) {

        if (lowerIndex < higherIndex) {
            int middle = lowerIndex + (higherIndex - lowerIndex) / 2;
            // Below step sorts the left side of the array
            doMergeSort(lowerIndex, middle);
            // Below step sorts the right side of the array
            doMergeSort(middle + 1, higherIndex);
            // Now merge both sides
            mergeParts(lowerIndex, middle, higherIndex);
        }
    }

    private static void mergeParts(int lowerIndex, int middle, int higherIndex) {

        for (int i = lowerIndex; i <= higherIndex; i++) {
            tempMergeArray[i] = tempArray[i];
        }
        int i = lowerIndex;
        int j = middle + 1;
        int k = lowerIndex;
        while (i <= middle && j <= higherIndex) {
            if (tempMergeArray[i] <= tempMergeArray[j]) {
                tempArray[k] = tempMergeArray[i];
                i++;
            } else {
                tempArray[k] = tempMergeArray[j];
                j++;
            }
            k++;
        }
        while (i <= middle) {
            tempArray[k] = tempMergeArray[i];
            k++;
            i++;
        }

    }
}

