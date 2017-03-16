import java.util.Scanner;
public class ProblemB {

    public static boolean one(String s) {
        int quest = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?') {
                quest++;
            }
        }
        return (quest == 1);
    }
    public static boolean all(String s) {
        int quest = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?') {
                quest++;
            }
        }
        return (quest == s.length());
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            String s1 = in.next();
            String s2 = in.next();
            String[] coders = new String[100];
            String[] jammers = new String[100];
            int index = 0;
            String codersScore = "";
            String jammersScore = "";
            if (s1.length() == 1 && all(s1) && all(s2)) {
                codersScore = "0";
                jammersScore = "0";
            } else if (s1.length() == 1) {
                if (all(s1) && !all(s2)) {
                    codersScore = s2;
                    jammersScore = s2;
                }
                if (!all(s1) && all(s2)) {
                    codersScore = s1;
                    jammersScore = s1;
                }
            } else {
                if (all(s1) && all(s2)) {
                    if (s1.length() == 2) {
                        codersScore = "00";
                        jammersScore = "00";
                    } else if (s1.length() == 3) {
                        codersScore = "000";
                        jammersScore = "000";
                    }
                } else if (s1.length() == 3) {
                    if (all(s1) && !all(s2)) {
                        String least = "";
                        for (int j = 0; j < s2.length(); j++) {
                            if (s2.charAt(j) == '?') {
                                least += "0";
                            } else {
                                least += s2.charAt(j);
                            }
                        }
                        codersScore = least;
                        jammersScore = least;
                    } else if (all(s2) && !all(s1)) {
                        String least = "";
                        for (int j = 0; j < s1.length(); j++) {
                            if (s1.charAt(j) == '?') {
                                least += "0";
                            } else {
                                least += s1.charAt(j);
                            }
                        }
                        codersScore = least;
                        jammersScore = least;
                    }
                    else {
                        for (int k = 0; k < 100; k++) {
                            if (s1.charAt(0) != '?') {
                                coders[k] = "" + s1.charAt(0);
                            } else {
                                coders[k] = "" + k / 10;
                            }
                        }
                        for (int k = 0; k < 100; k++) {
                            if (s1.charAt(1) != '?') {
                                coders[k] += s1.charAt(1);
                            } else {
                                if (s1.charAt(0) == '?') {
                                    coders[k] += k % 10;
                                } else {
                                    coders[k] += k / 10;
                                }
                            }
                        }
                        for (int k = 0; k < 100; k++) {
                            if (s1.charAt(2) != '?') {
                                coders[k] += s1.charAt(2);
                            } else {
                                coders[k] += k % 10;
                            }
                        }
                        for (int k = 0; k < 100; k++) {
                            if (s2.charAt(0) != '?') {
                                jammers[k] = "" + s2.charAt(0);
                            } else {
                                jammers[k] = "" + k / 10;
                            }
                        }
                        for (int k = 0; k < 100; k++) {
                            if (s2.charAt(1) != '?') {
                                jammers[k] += s2.charAt(1);
                            } else {
                                if (s2.charAt(0) == '?') {
                                    jammers[k] += k % 10;
                                } else {
                                    jammers[k] += k / 10;
                                }
                            }
                        }
                        for (int k = 0; k < 100; k++) {
                            if (s2.charAt(2) != '?') {
                                jammers[k] += s2.charAt(2);
                            } else {
                                jammers[k] += k % 10;
                            }
                        }
                    }
                } else {
                    for (int k = 0; k < 100; k++) {
                        if (s1.charAt(0) != '?') {
                            coders[k] = "" + s1.charAt(0);
                        } else {
                            coders[k] = "" + k / 10;
                        }
                    }
                    for (int k = 0; k < 100; k++) {
                        if (s1.charAt(1) != '?') {
                            coders[k] += s1.charAt(1);
                        } else {
                            if (s1.charAt(0) == '?') {
                                coders[k] += k % 10;
                            } else {
                                coders[k] += k / 10;
                            }
                        }
                    }
                    for (int k = 0; k < 100; k++) {
                        if (s2.charAt(0) != '?') {
                            jammers[k] = "" + s2.charAt(0);
                        } else {
                            jammers[k] = "" + k / 10;
                        }
                    }
                    for (int k = 0; k < 100; k++) {
                        if (s2.charAt(1) != '?') {
                            jammers[k] += s2.charAt(1);
                        } else {
                            if (s2.charAt(0) == '?') {
                                jammers[k] += k % 10;
                            } else {
                                jammers[k] += k / 10;
                            }
                        }
                    }
                }
            }
            int mincoders = 1000;
            int minjammers = 1000;
            int I = 0;
            int J = 0;
            int abs = 1000;
            if (codersScore.equals("") || jammersScore.equals("")) {
                for (int j = 0; j < 100; j++) {
                    for (int k = 0; k < 100; k++) {
                        int c = Integer.parseInt(coders[j]);
                        int jj = Integer.parseInt(jammers[k]);
                        int a = Math.abs(c - jj);
                        if (a < abs) {
                            mincoders = c;
                            minjammers = jj;
                            I = j;
                            J = k;
                            abs = a;
                        } else if (a == abs) {
                            if (c < mincoders || jj < minjammers) {
                                mincoders = c;
                                minjammers = jj;
                                I = j;
                                J = k;
                            }
                        }
                    }
                }
                if (codersScore.equals("") || jammersScore.equals("")) {
                    codersScore = coders[I];
                    jammersScore = jammers[J];
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + codersScore + " " + jammersScore);
        }
    }
    
}
