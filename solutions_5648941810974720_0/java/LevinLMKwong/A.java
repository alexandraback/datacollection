package gcj2016.roundOneA;

import java.util.Scanner;

/**
 * Created by LevinLMKwong on 1/5/16.
 */
public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t=1; t<=T; t++) {
            String s = in.next();
            int[] count = new int[10];
            for (int i = 0; i < s.length(); i++) {
                switch (s.charAt(i)) {
                    case 'Z' : {
                        ++count[0];
                        --count[1];
                        break;
                    }
                    case 'O' : {
                        ++count[1];
                        break;
                    }
                    case 'W' : {
                        ++count[2];
                        --count[1];
                        --count[3];
                        break;
                    }
                    case 'T' : {
                        ++count[3];
                        break;
                    }
                    case 'U' : {
                        ++count[4];
                        --count[5];
                        --count[1];
                        break;
                    }
                    case 'F' : {
                        ++count[5];
                        break;
                    }
                    case 'X' : {
                        ++count[6];
                        --count[7];
                        break;
                    }
                    case 'S' : {
                        ++count[7];
                        break;
                    }
                    case 'G' : {
                        ++count[8];
                        --count[3];
                        break;
                    }
                }
            }
            String ans = "";
            int total = 0;
            for (int i = 0; i < 9; i++) {
                if (count[i] > 0) {
                    for (int j = 0; j < count[i]; j++) {
                        ans += (char) ('0' + i);
                        switch (i) {
                            case 0:
                                total += 4;
                                break;
                            case 1:
                                total += 3;
                                break;
                            case 2:
                                total += 3;
                                break;
                            case 3:
                                total += 5;
                                break;
                            case 4:
                                total += 4;
                                break;
                            case 5:
                                total += 4;
                                break;
                            case 6:
                                total += 3;
                                break;
                            case 7:
                                total += 5;
                                break;
                            case 8:
                                total += 5;
                                break;
                        }
                    }
                }
            }
            total = (s.length() - total) / 4;
            for (int i = 0; i < total; i++) {
                ans += '9';
            }
            System.out.format("Case #%d: %s\n", t, ans);
        }
    }
}
