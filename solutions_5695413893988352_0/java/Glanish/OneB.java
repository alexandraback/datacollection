package codejam2026.round1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Dean
 */
public class OneB {

    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < cases; i++) {

            String line = reader.readLine().trim();
            String split[] = line.split("\\s+");
            int c[] = new int[split[0].length()];
            int j[] = new int[split[1].length()];
            for (int k = 0; k < split[0].length(); k++) {
                if (split[0].charAt(k) == '?') {
                    c[k] = -1;
                } else {
                    c[k] = Integer.parseInt(split[0].charAt(k) + "");
                }
            }
            for (int k = 0; k < split[1].length(); k++) {
                if (split[1].charAt(k) == '?') {
                    j[k] = -1;
                } else {
                    j[k] = Integer.parseInt(split[1].charAt(k) + "");
                }
            }
            longBest lb = getBestDifference(c, j, 0, 0);
            String ans = lb.bestC + " " + lb.bestJ;
            System.out.println(String.format("Case #%d: %s", (i + 1), ans));
        }
    }

    public static longBest getBestDifference(int numsC[], int numsJ[], int pos, int whichOne) {
        if (pos == numsJ.length) {
            return getDifference(numsC, numsJ);
        }
        if (numsC[pos] == numsJ[pos] && numsC[pos] != -1) {
            return getBestDifference(numsC, numsJ, pos + 1, whichOne);
        } else if (numsC[pos] != -1 && numsJ[pos] != -1) {
            if (whichOne != 0) {
                return getBestDifference(numsC, numsJ, pos + 1, whichOne);
            } else if (numsC[pos] > numsJ[pos]) {
                return getBestDifference(numsC, numsJ, pos + 1, 1);
            } else {
                return getBestDifference(numsC, numsJ, pos + 1, -1);
            }
        }
        if (numsC[pos] == -1 && numsJ[pos] != -1) {
            if (whichOne == 1) {
                numsC[pos] = 0;
                longBest ret = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsC[pos] = -1;
                return ret;
            }
            if (whichOne == -1) {
                numsC[pos] = 9;
                longBest ret = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsC[pos] = -1;
                return ret;
            }
            if (whichOne == 0) {
                numsC[pos] = numsJ[pos];
                longBest ret1 = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsC[pos] = -1;
                if (numsJ[pos] < 9) {
                    numsC[pos] = numsJ[pos] + 1;
                    longBest ret2 = getBestDifference(numsC, numsJ, pos + 1, 1);
                    if (ret1.num > ret2.num) {
                        ret1 = ret2;
                    } else if (ret1.num == ret2.num && ret1.scoreC > ret2.scoreC) {
                        ret1 = ret2;
                    } else if (ret1.num == ret2.num && ret1.scoreC == ret2.scoreC && ret1.scoreJ > ret2.scoreJ) {
                        ret1 = ret2;
                    }
                    numsC[pos] = -1;
                }
                if (numsJ[pos] > 0) {
                    numsC[pos] = numsJ[pos] - 1;
                    longBest ret2 = getBestDifference(numsC, numsJ, pos + 1, -1);
                    if (ret1.num > ret2.num) {
                        ret1 = ret2;
                    } else if (ret1.num == ret2.num && ret1.scoreC > ret2.scoreC) {
                        ret1 = ret2;
                    } else if (ret1.num == ret2.num && ret1.scoreC == ret2.scoreC && ret1.scoreJ > ret2.scoreJ) {
                        ret1 = ret2;
                    }
                    numsC[pos] = -1;
                }
                return ret1;

            }
        } else if (numsC[pos] != -1 && numsJ[pos] == -1) {
            if (whichOne == -1) {
                numsJ[pos] = 0;
                longBest ret = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsJ[pos] = -1;
                return ret;
            }
            if (whichOne == 1) {
                numsJ[pos] = 9;
                longBest ret = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsJ[pos] = -1;
                return ret;
            }
            if (whichOne == 0) {
                numsJ[pos] = numsC[pos];
                longBest ret1 = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsJ[pos] = -1;
                if (numsC[pos] < 9) {
                    numsJ[pos] = numsC[pos] + 1;
                    longBest ret2 = getBestDifference(numsC, numsJ, pos + 1, -1);
                    if (ret1.num > ret2.num) {
                        ret1 = ret2;
                    } else if (ret1.num == ret2.num && ret1.scoreC > ret2.scoreC) {
                        ret1 = ret2;
                    } else if (ret1.num == ret2.num && ret1.scoreC == ret2.scoreC && ret1.scoreJ > ret2.scoreJ) {
                        ret1 = ret2;
                    }
                    numsJ[pos] = -1;
                }
                if (numsC[pos] > 0) {
                    numsJ[pos] = numsC[pos] - 1;
                    longBest ret2 = getBestDifference(numsC, numsJ, pos + 1, 1);
                    if (ret1.num > ret2.num) {
                        ret1 = ret2;
                    } else if (ret1.num == ret2.num && ret1.scoreC > ret2.scoreC) {
                        ret1 = ret2;
                    } else if (ret1.num == ret2.num && ret1.scoreC == ret2.scoreC && ret1.scoreJ > ret2.scoreJ) {
                        ret1 = ret2;
                    }
                    numsJ[pos] = -1;
                }
                return ret1;

            }
        } else if (numsC[pos] == -1 && numsJ[pos] == -1) {
            if (whichOne == 1) {
                numsC[pos] = 0;
                numsJ[pos] = 9;
                longBest ret = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsC[pos] = -1;
                numsJ[pos] = -1;
                return ret;
            }
            if (whichOne == -1) {
                numsC[pos] = 9;
                numsJ[pos] = 0;
                longBest ret = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsC[pos] = -1;
                numsJ[pos] = -1;
                return ret;
            }
            if (whichOne == 0) {
                numsC[pos] = 0;
                numsJ[pos] = 0;
                longBest ret = getBestDifference(numsC, numsJ, pos + 1, whichOne);
                numsC[pos] = -1;
                numsJ[pos] = -1;

                numsC[pos] = 0;
                numsJ[pos] = 1;
                longBest ret1 = getBestDifference(numsC, numsJ, pos + 1, -1);
                numsC[pos] = -1;
                numsJ[pos] = -1;

                if (ret.num > ret1.num) {
                    ret = ret1;
                } else if (ret.num == ret1.num && ret.scoreC > ret1.scoreC) {
                    ret = ret1;
                } else if (ret.num == ret1.num && ret.scoreC == ret1.scoreC && ret.scoreJ > ret1.scoreJ) {
                    ret = ret1;
                }
                numsC[pos] = 1;
                numsJ[pos] = 0;
                ret1 = getBestDifference(numsC, numsJ, pos + 1, 1);
                numsC[pos] = -1;
                numsJ[pos] = -1;
                if (ret.num > ret1.num) {
                    ret = ret1;
                } else if (ret.num == ret1.num && ret.scoreC > ret1.scoreC) {
                    ret = ret1;
                } else if (ret.num == ret1.num && ret.scoreC == ret1.scoreC && ret.scoreJ > ret1.scoreJ) {
                    ret = ret1;
                }
                return ret;
            }
        }
        return null;
    }

    public static longBest getDifference(int numsC[], int numsJ[]) {
        long scoreC = toLong(numsC);
        long scoreJ = toLong(numsJ);
        long ans = scoreC - scoreJ;

        StringBuilder c = new StringBuilder();
        for (int i = 0; i < numsC.length; i++) {
            c.append(numsC[i]);
        }
        StringBuilder j = new StringBuilder();
        for (int i = 0; i < numsC.length; i++) {
            j.append(numsJ[i]);
        }
        longBest l = new longBest();
        l.num = Math.abs(ans);
        l.bestC = c.toString();
        l.bestJ = j.toString();
        l.scoreC = scoreC;
        l.scoreJ = scoreJ;
        return l;
    }

    public static long toLong(int nums[]) {
        long ans = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            ans += nums[i] * Math.pow(10, nums.length - 1 - i);
        }
        return ans;
    }
}

class longBest {

    long num;
    String bestC;
    String bestJ;
    long scoreC;
    long scoreJ;
}
