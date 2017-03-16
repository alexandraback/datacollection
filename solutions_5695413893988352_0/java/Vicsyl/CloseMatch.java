package gj;

import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class CloseMatch {

    public static void main(String[] args) {



        try (Stream<String> ln = Files.lines(Paths.get(args[0]))) {

            String[] lines = ln.toArray(String[]::new);

            int cases = Integer.parseInt(lines[0].trim());
            for (int i = 1; i < cases + 1; i++) {
                String[] s = lines[i].split(" ");
                solveFor(s[0].trim(), s[1].trim(), i);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solveFor(String coders, String jammers, int cs) {

        Solution s = solveForRec(coders, jammers, 0, new StringBuilder(), new StringBuilder(), Comparison.Unknown);
        System.out.println("Case #" + cs + ": " + s.sc + " " + s.sj);


    }

    private enum Comparison {CodersHigher, JammersHigher, Unknown}

    private static class Solution {
        BigInteger difference;
        BigInteger coders;
        BigInteger jammers;
        String sj;
        String sc;
    }

    private static Solution solveForRec(String coders, String jammers, int position, StringBuilder completeCoders, StringBuilder completeJammers, Comparison comparison) {
        if(position == coders.length()) {
            Solution ret = new Solution();
            ret.coders = new BigInteger(completeCoders.toString(), 10);
            ret.jammers = new BigInteger(completeJammers.toString(), 10);
            ret.difference = ret.coders.subtract(ret.jammers).abs();
            ret.sc = completeCoders.toString();
            ret.sj = completeJammers.toString();
            return ret;
        }

        char codersDigit = coders.charAt(position);
        char jammersDigit = jammers.charAt(position);

        if(codersDigit != '?' && jammersDigit != '?') {
            Comparison c = comparison;
            if(c == Comparison.Unknown) {
                if(codersDigit > jammersDigit) {
                    c = Comparison.CodersHigher;
                } else if (jammersDigit > codersDigit) {
                    c = Comparison.JammersHigher;
                }
            }
            return solveForRec(coders, jammers, position + 1, completeCoders.append(codersDigit), completeJammers.append(jammersDigit), c);
        }


        switch (comparison) {
            case CodersHigher:
            case JammersHigher:
                if (codersDigit == '?') {
                    completeCoders.append(comparison == Comparison.CodersHigher ? '0' : '9');
                } else {
                    completeCoders.append(codersDigit);
                }

                if (jammersDigit == '?') {
                    completeJammers.append(comparison == Comparison.JammersHigher ? '0' : '9');
                } else {
                    completeJammers.append(jammersDigit);
                }
                return solveForRec(coders, jammers, position + 1, completeCoders, completeJammers, comparison);
            case Unknown:
                Solution currentSolution;
                Solution bestSolution = null;

                if(jammersDigit == '?' && codersDigit == '?') {

                    char[][] options = new char[][]{{'0', '0'}, {'0', '1'}, {'1', '0'}};
                    Comparison[] comparisons = new Comparison[]{Comparison.Unknown, Comparison.JammersHigher, Comparison.CodersHigher};

                    for (int i = 0; i < options.length; i++) {
                        StringBuilder sbc = new StringBuilder(completeCoders).append(options[i][0]);
                        StringBuilder sbj = new StringBuilder(completeJammers).append(options[i][1]);
                        currentSolution = solveForRec(coders, jammers, position + 1, sbc, sbj, comparisons[i]);
                        bestSolution = pickBetterSolution(currentSolution, bestSolution);
                    }

                    return bestSolution;
                } else if(jammersDigit == '?') {

                    for (int i = -1; i <= 1; i++) {
                        if(i == -1 && codersDigit == '0') {
                            continue;
                        }
                        if(i == 1 && codersDigit == '9') {
                            continue;
                        }
                        StringBuilder sbc = new StringBuilder(completeCoders).append(codersDigit);
                        StringBuilder sbj = new StringBuilder(completeJammers).append((char)(codersDigit + i));
                        Comparison c = Comparison.Unknown;
                        if(i == 1) {
                            c = Comparison.JammersHigher;
                        } else if (i == -1) {
                            c = Comparison.CodersHigher;
                        }
                        currentSolution = solveForRec(coders, jammers, position + 1, sbc, sbj, c);
                        bestSolution = pickBetterSolution(currentSolution, bestSolution);
                    }

                    return bestSolution;
                } else if (codersDigit == '?') {

                    for (int i = -1; i <= 1; i++) {
                        if(i == -1 && jammersDigit == '0') {
                            continue;
                        }
                        if(i == 1 && jammersDigit == '9') {
                            continue;
                        }
                        StringBuilder sbc = new StringBuilder(completeCoders).append((char)(jammersDigit + i));
                        StringBuilder sbj = new StringBuilder(completeJammers).append(jammersDigit);
                        Comparison c = Comparison.Unknown;
                        if(i == 1) {
                            c = Comparison.CodersHigher;
                        } else if (i == -1) {
                            c = Comparison.JammersHigher;
                        }
                        currentSolution = solveForRec(coders, jammers, position + 1, sbc, sbj, c);
                        bestSolution = pickBetterSolution(currentSolution, bestSolution);
                    }

                    return bestSolution;
                }
            default:
                throw new AssertionError();
        }


    }

    private static Solution pickBetterSolution(Solution current, Solution best) {
        if(best == null) {
            return current;
        }
        int comp = best.difference.compareTo(current.difference);
        if(comp != 0) {
            return comp < 0 ? best : current;
        }

        comp = best.coders.compareTo(current.coders);
        if(comp != 0) {
            return comp < 0 ? best : current;
        }

        comp = best.jammers.compareTo(current.jammers);
        return comp <= 0 ? best : current;

    }

}
