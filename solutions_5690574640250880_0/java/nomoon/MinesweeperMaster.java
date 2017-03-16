/*
 * Copyright 1999-2004 Alibaba.com All right reserved. This software is the confidential and proprietary information of
 * Alibaba.com ("Confidential Information"). You shall not disclose such Confidential Information and shall use it only
 * in accordance with the terms of the license agreement you entered into with Alibaba.com.
 */
package hoho;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 类MinesweeperMaster.java的实现描述：TODO 类实现描述
 * 
 * @author noMoon Apr 12, 2014 10:42:22 PM
 */
public class MinesweeperMaster {

    public static void main(String[] args) throws IOException {

        File file = new File("C-small-attempt3.in.txt");
        File outputFile = new File("MinesweeperMaster.out");
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
        // 这里inputstream 未指定字符集
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        String line = br.readLine();
        int issueNumber = Integer.valueOf(line);
        for (int i = 0; i < issueNumber; i++) {
            String[] paramList = br.readLine().split(" ");
            int R = Integer.valueOf(paramList[0]);
            int C = Integer.valueOf(paramList[1]);
            int M = Integer.valueOf(paramList[2]);
            int area = R * C;
            int space = area - M;
            bw.write("Case #" + String.valueOf(i + 1) + ":");
            bw.newLine();
            if (0 == M) {
                bw.write("c");
                for (int j = 0; j < C - 1; j++) {
                    bw.write(".");
                }
                bw.newLine();
                for (int j = 0; j < R - 1; j++) {
                    for (int k = 0; k < C; k++) {
                        bw.write(".");
                    }
                    bw.newLine();
                }
                continue;
            }
            if (1 == space) {
                bw.write("c");
                for (int j = 0; j < C - 1; j++) {
                    bw.write("*");
                }
                bw.newLine();
                for (int j = 0; j < R - 1; j++) {
                    for (int k = 0; k < C; k++) {
                        bw.write("*");
                    }
                    bw.newLine();
                }
                continue;
            } else if (1 == R) {
                bw.write("c");
                for (int j = 0; j < C - M - 1; j++) {
                    bw.write(".");
                }
                for (int j = 0; j < M; j++) {
                    bw.write("*");
                }
                bw.newLine();
                continue;
            } else if (1 == C) {
                bw.write("c");
                bw.newLine();
                for (int j = 0; j < R - M - 1; j++) {
                    bw.write(".");
                    bw.newLine();
                }
                for (int j = 0; j < M; j++) {
                    bw.write("*");
                    bw.newLine();
                }
                continue;
            } else if (2 == R || 2 == C) {
                if (1 == M % 2 || 2 == space) {
                    bw.write("Impossible");
                    bw.newLine();
                    continue;
                } else if (2 == R) {
                    bw.write("c");
                    for (int j = 0; j < C - M / 2 - 1; j++) {
                        bw.write(".");
                    }
                    for (int j = 0; j < M / 2; j++) {
                        bw.write("*");
                    }
                    bw.newLine();
                    for (int j = 0; j < C - M / 2; j++) {
                        bw.write(".");
                    }
                    for (int j = 0; j < M / 2; j++) {
                        bw.write("*");
                    }
                    bw.newLine();
                    continue;
                } else {
                    bw.write("c.");
                    bw.newLine();
                    for (int j = 0; j < R - M / 2 - 1; j++) {
                        bw.write("..");
                        bw.newLine();
                    }
                    for (int j = 0; j < M / 2; j++) {
                        bw.write("**");
                        bw.newLine();
                    }
                    continue;
                }
            } else {

                if (space < 9) {
                    if (1 == space % 2 || 2 == space) {
                        bw.write("Impossible");
                        bw.newLine();
                        continue;
                    } else {
                        char map[][] = new char[R][C];
                        for (int j = 0; j < R; j++) {
                            for (int k = 0; k < C; k++) {
                                map[j][k] = '*';
                            }
                        }
                        map[0][0] = 'c';
                        int count = space - 1;
                        for (int j = 1; j < (C > space / 2 ? space / 2 : C); j++) {
                            count--;
                            map[0][j] = '.';
                        }
                        for (int j = 0; j < (C > space / 2 ? space / 2 : C); j++) {
                            count--;
                            map[1][j] = '.';
                        }
                        for (int j = 0; j < count; j++) {
                            map[2][j] = '.';
                        }
                        for (int j = 0; j < R; j++) {
                            for (int k = 0; k < C; k++) {
                                bw.write(map[j][k]);
                            }
                            bw.newLine();
                        }
                    }
                    continue;
                } else {
                    char map[][] = new char[R][C];
                    for (int j = 0; j < R; j++) {
                        for (int k = 0; k < C; k++) {
                            map[j][k] = '*';
                        }
                    }
                    map[0][0] = 'c';
                    long side = Math.round(Math.sqrt(space));
                    if (space % side != 0) {
                        side++;
                    }
                    if (side > C) {
                        side = C;
                    } else if (space / side + 1 > R) {
                        if (space % R == 0) {
                            side = space / R;
                        } else {
                            side = space / R + 1;
                        }
                    }

                    int count = space - 1;
                    for (int j = 1; j < side; j++) {
                        count--;
                        map[0][j] = '.';
                    }
                    if (space % side != 1) {
                        int lastRow = (int) ((int) space / side);
                        for (int j = 1; j < lastRow; j++) {
                            for (int k = 0; k < side; k++) {
                                count--;
                                map[j][k] = '.';
                            }
                        }
                        for (int j = 0; j < count; j++) {
                            map[lastRow][j] = '.';
                        }
                    } else {
                        int lastRow = (int) ((int) space / side) - 1;
                        for (int j = 1; j < lastRow; j++) {
                            for (int k = 0; k < side; k++) {
                                count--;
                                map[j][k] = '.';
                            }
                        }
                        for (int j = 0; j < side - 1; j++) {
                            count--;
                            map[lastRow][j] = '.';
                        }
                        lastRow++;
                        for (int j = 0; j < count; j++) {
                            map[lastRow][j] = '.';
                        }
                    }
                    for (int j = 0; j < R; j++) {
                        for (int k = 0; k < C; k++) {
                            bw.write(map[j][k]);
                        }
                        bw.newLine();
                    }
                    continue;
                }
            }
        }
        br.close();
        bw.close();

    }
}
