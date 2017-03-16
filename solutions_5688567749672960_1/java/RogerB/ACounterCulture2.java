package Round1B;

import java.util.Scanner;

public class ACounterCulture2 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int tests = sc.nextInt();
        for (int t = 1; t <= tests; t++) {
            long toCount = sc.nextLong();
            long currNumber = 1;
            long stepCount = 1;
            int toCountLength = (int)Math.ceil(Math.log10(toCount + 1));
            long toCountEnd = toCount % (long)Math.pow(10, toCountLength - (toCountLength / 2));
            //boolean flipped = false;
            while (true) {
                int numLength = (int)Math.ceil(Math.log10(currNumber + 1));
                long end = currNumber % (long)Math.pow(10, numLength - (numLength / 2));
                int endLength = numLength / 2;
                long front = (currNumber - end) / (long)Math.pow(10, numLength - (numLength / 2));
                long toCountFront = toCount / (long)Math.pow(10, toCountLength - endLength);
                if (flip(currNumber) > currNumber/* && ((numLength < toCountLength && end == (int)Math.pow(10, numLength - (numLength / 2)) - 1) || (numLength == toCountLength && flip(currNumber) <= toCount && flip(currNumber + 1) > toCount))*/) {
                    currNumber = flip(currNumber);
                    stepCount++;
                } else {
                    long target = 0;
                    if (numLength < toCountLength) {
                        target = currNumber - end + (long)Math.pow(10, numLength - (numLength / 2)) - 1;
                    } else {
                        if (front == toCountFront) {
                            target = toCount;
                        } else {
                            long endTarget = flip(toCountFront);
                            if (flip(front) > toCountEnd) {
                                endTarget = flip(toCountFront - 1);
                            }
                            target = currNumber - end + endTarget;
                            if (flip(front) == endTarget) {
                                target = toCount;
                            }
                        }
                    }
                    if (currNumber == target) {
                        target++;
                    }
                    stepCount += target - currNumber;
                    currNumber = target;
                }
                //System.out.println(currNumber);
                if (currNumber == toCount) {
                    System.out.printf("Case #%d: %d%n", t, stepCount);
                    break;
                }
            }
        }
        sc.close();
    }
    static long flip (long toFlip) {
        int length = (int)Math.ceil(Math.log10(toFlip + 1));
        long flipped = 0;
        for (int x = 0; x < length; x++) {
            int digit = (int) ((toFlip % (Math.pow(10, x + 1))) / Math.pow(10, x));
            flipped += digit * Math.pow(10, length - x - 1);
        }
        return flipped;
    }
}
