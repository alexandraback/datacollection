package com.rabby250.codejam;

public class TheLastWord {
    public static String solve(final String input) {
        if (input == null || "".equals(input)) return input;
        final StringBuilder sb = new StringBuilder();
        sb.append(input.charAt(0));
        char lastHead = '\0';
        for (int i = 1; i < input.length(); i++) {
            char currentHead = sb.length() > 0 ?
                    sb.charAt(0) : '\0';
            char newHead = input.charAt(i);
            if (newHead > currentHead) {
                sb.insert(0, newHead);
                lastHead = currentHead;
            } else if (newHead < currentHead) {
                sb.append(newHead);
            } else {
                if (newHead > lastHead) {
                    sb.insert(0, newHead);
                } else {
                    sb.append(newHead);
                }
            }
        }
        return sb.toString();
    }
}
