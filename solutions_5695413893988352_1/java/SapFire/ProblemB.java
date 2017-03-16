import java.util.Scanner;
public class ProblemB {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            String s1 = in.next();
            String s2 = in.next();
            String codersScore = "";
            String jammersScore = "";
            for (int j = 0; j < s1.length(); j++) {
                if (s1.charAt(j) == '?' && s2.charAt(j) == '?') {
                    boolean yes = false;
                    if (s1.length() > 1 && j != s1.length() - 1) {
                        if (
                            (s2.charAt(j + 1) == '6' ||
                            s2.charAt(j + 1) == '7' ||
                            s2.charAt(j + 1) == '8' ||
                            s2.charAt(j + 1) == '9') &&
                            s1.charAt(j + 1) != '?') {
                            codersScore += "1";
                            jammersScore += "0";
                            yes = true;
                        } else if (
                            (s1.charAt(j + 1) == '6' ||
                            s1.charAt(j + 1) == '7' ||
                            s1.charAt(j + 1) == '8' ||
                            s1.charAt(j + 1) == '9') &&
                            s2.charAt(j + 1) != '?') {
                            codersScore += "0";
                            jammersScore += "1";
                            yes = true;
                        } else {
                            char cf = s2.charAt(s2.length() - 1);
                            char cpf = s2.charAt(s2.length() - 2);
                            if (cpf == '9' && (cf == '8' || cf == '9')) {
                                codersScore += "1";
                                jammersScore += "0";
                                yes = true;
                            }
                            cf = s1.charAt(s1.length() - 1);
                            cpf = s1.charAt(s1.length() - 2);
                            if (cpf == '9' && (cf == '8' || cf == '9') && !yes) {
                                codersScore += "0";
                                jammersScore += "1";
                                yes = true;
                            }
                            else if (!yes) {
                                codersScore += "0";
                                jammersScore += "0";
                                yes = true;
                            }
                        }
                    } else if (j != s1.length() - 1) {
                        codersScore += "0";
                        jammersScore += "0";
                        yes = true;
                    }
                    if (!yes) {
                        long abs = -1;
                        for (int a = 0; a <= 9; a++) {
                            for (int b = 0; b <= 9; b++) {
                                String newA = codersScore + a;
                                String newB = jammersScore + b;
                                long na = Long.parseLong(newA);
                                long nb = Long.parseLong(newB);
                                long ab = Math.abs(na - nb);
                                if (abs == -1) {
                                    abs = ab;
                                } else if (ab < abs) {
                                    abs = ab;
                                }
                            }
                        }
                        for (int a = 0; a <= 9; a++) {
                            long ab = 0;
                            for (int b = 0; b <= 9; b++) {
                                String newA = codersScore + a;
                                String newB = jammersScore + b;
                                long na = Long.parseLong(newA);
                                long nb = Long.parseLong(newB);
                                ab = Math.abs(na - nb);
                                if (ab == abs) {
                                    codersScore = newA;
                                    jammersScore = newB;
                                    break;
                                }
                            }
                            if (ab == abs) {
                                break;
                            }
                        }
                    }
                } else if (s1.charAt(j) != '?' && s2.charAt(j) != '?') {
                    codersScore += s1.charAt(j);
                    jammersScore += s2.charAt(j);
                } else if (s1.charAt(j) == '?' && s2.charAt(j) != '?') {
                    long abs = -1;
                    for (int a = 0; a <= 9; a++) {
                        String newA = codersScore + a;
                        String newB = jammersScore + s2.charAt(j);
                        long na = Long.parseLong(newA);
                        long nb = Long.parseLong(newB);
                        long ab = Math.abs(na - nb);
                        if (abs == -1) {
                            abs = ab;
                        } else if (ab < abs) {
                            abs = ab;
                        }
                    }
                    for (int a = 0; a <= 9; a++) {
                        String newA = codersScore + a;
                        String newB = jammersScore + s2.charAt(j);
                        long na = Long.parseLong(newA);
                        long nb = Long.parseLong(newB);
                        long ab = Math.abs(na - nb);
                        if (ab == abs) {
                            codersScore += a;
                            jammersScore += s2.charAt(j);
                            break;
                        }
                    }
                } else {
                    long abs = -1;
                    for (int a = 0; a <= 9; a++) {
                        String newA = codersScore + s1.charAt(j);
                        String newB = jammersScore + a;
                        long na = Long.parseLong(newA);
                        long nb = Long.parseLong(newB);
                        long ab = Math.abs(na - nb);
                        if (abs == -1) {
                            abs = ab;
                        } else if (ab < abs) {
                            abs = ab;
                        }
                    }
                    for (int a = 0; a <= 9; a++) {
                        String newA = codersScore + s1.charAt(j);
                        String newB = jammersScore + a;
                        long na = Long.parseLong(newA);
                        long nb = Long.parseLong(newB);
                        long ab = Math.abs(na - nb);
                        if (ab == abs) {
                            codersScore += s1.charAt(j);
                            jammersScore += a;
                            break;
                        }
                    }
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + codersScore + " " + jammersScore);
        }
    }
    
}
