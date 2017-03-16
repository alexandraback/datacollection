package round1b;

import java.util.*;

/**
 * Created by Benedek on 4/30/2016.
 */
public class BB {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        in.nextLine();

        for (int t = 1; t <= T; t++) {
            String string = in.nextLine();
            String coders = string.split(" ")[0];
            String jammers = string.split(" ")[1];
            int lengthOfScore = jammers.length();
            ArrayList<HashSet<Integer>> digitsCoders = new ArrayList<>();
            ArrayList<HashSet<Integer>> digitsJammers = new ArrayList<>();


            int lastUnknown = -1;
            for (int i = 0; i < coders.length(); i++) {
                if (coders.charAt(i) == '?' && jammers.charAt(i) == '?') {
                    lastUnknown = i;
                } else {
                    break;
                }
            }
            for (int i = 0; i < coders.length(); i++) {
                if (coders.charAt(i) != '?') {
                    HashSet<Integer> temp = new HashSet<>();
                    temp.add(Integer.valueOf(coders.charAt(i) - 48));
                    digitsCoders.add(i, temp);
                } else if (coders.charAt(i) == '?' && jammers.charAt(i) != '?') {
                    HashSet<Integer> temp = new HashSet<>();
                    temp.add((int) jammers.charAt(i) - 48);
                    temp.add(((int) jammers.charAt(i) - 48 + 1) % 10);
                    temp.add(((int) jammers.charAt(i) - 48 - 1) % 10);
                    temp.add(0);
                    temp.add(1);
                    temp.add(9);
                    digitsCoders.add(i, temp);
                } else if (coders.charAt(i) == '?' && jammers.charAt(i) == '?') {
                    if (i < lastUnknown) {
                        HashSet<Integer> temp = new HashSet<>();
                        temp.add(0);
                        temp.add(1);
                        temp.add(9);
                        digitsCoders.add(i, temp);
                    } else {
                        HashSet<Integer> temp = new HashSet<>();
                        temp.add(0);
                        temp.add(1);
                        temp.add(9);
                        digitsCoders.add(i, temp);
                    }
                }


                if (jammers.charAt(i) != '?') {
                    HashSet<Integer> temp = new HashSet<>();
                    temp.add((int) jammers.charAt(i) - 48);
                    digitsJammers.add(i, temp);
                } else if (jammers.charAt(i) == '?' && coders.charAt(i) != '?') {
                    HashSet<Integer> temp = new HashSet<>();
                    temp.add((int) coders.charAt(i) - 48);
                    temp.add(((int) coders.charAt(i) - 48 + 1) % 10);
                    temp.add(((int) coders.charAt(i) - 48 - 1) % 10);
                    temp.add(0);
                    temp.add(1);
                    temp.add(9);
                    digitsJammers.add(i, temp);
                } else if (jammers.charAt(i) == '?' && coders.charAt(i) == '?') {
                    if (i < lastUnknown) {
                        HashSet<Integer> temp = new HashSet<>();
                        temp.add(0);
                        temp.add(1);
                        temp.add(9);
                        digitsJammers.add(i, temp);
                    } else {
                        HashSet<Integer> temp = new HashSet<>();
                        temp.add(0);
                        temp.add(1);
                        temp.add(9);
                        digitsJammers.add(i, temp);
                    }
                }
            }

            for (int i = 0; i < digitsCoders.size(); i++){
                if (digitsCoders.get(i).contains(-1)) {
                    digitsCoders.get(i).remove(-1);
                    digitsCoders.get(i).add(9);
                }
            }
            for (int i = 0; i < digitsJammers.size(); i++){
                if (digitsJammers.get(i).contains(-1)) {
                    digitsJammers.get(i).remove(-1);
                    digitsJammers.get(i).add(9);
                }
            }

            


            TreeSet<Long> numbersCoders = createNumbers(digitsCoders);
            TreeSet<Long> numbersJammers = createNumbers(digitsJammers);
            long minimalDifference = Long.MAX_VALUE;
            long ansCoders = 0;
            long ansJammers = 0;
            for (Long l1 : numbersCoders) {
                for (Long l2 : numbersJammers) {
                    if (Math.abs(l1 - l2) < minimalDifference) {
                        minimalDifference = Math.abs(l1 - l2);
                        ansCoders = l1;
                        ansJammers = l2;
                    } else if (Math.abs(l1 - l2) == minimalDifference) {
                        if (l1 < ansCoders) {
                            ansCoders = l1;
                            ansJammers = l2;
                        } else if (l1 == ansCoders) {
                            if (l2 < ansJammers) {
                                ansCoders = l1;
                                ansJammers = l2;
                            }
                        }
                    }
                }
            }

            String ansCodersString = String.format("%0" + lengthOfScore + "d", ansCoders);
            String ansJammersString = String.format("%0" + lengthOfScore + "d", ansJammers);

            System.out.printf("Case #%d: ", t);
            System.out.println(ansCodersString + " " + ansJammersString);
        }
    }

    private static TreeSet<Long> createNumbers(ArrayList<HashSet<Integer>> digits) {
        TreeSet<String> numbers = new TreeSet<>();
        TreeSet<Long> ans = new TreeSet<>();

        numbers.add("");
        for (int i = 0; i < digits.size(); i++) {
            Set<Integer> temp = digits.get(i);
            TreeSet<String> tempNumbers = new TreeSet<>();
            for (Integer j : temp) {
                for (String s : numbers) {
                    if (s.length() == i) {
                        tempNumbers.add(s + String.valueOf(j));
                    }
                }
            }
            numbers = new TreeSet<>(tempNumbers);
        }

        for (String s : numbers){
            if (s.length() >= digits.size()) {
                ans.add(Long.valueOf(s));
            }
        }

        return ans;
    }
}
