import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemC {

    static int T;
    static int N;
    static int M;
    static int K;
    //Calculate while N > 3
    final static int MAGIC = 3;
    //Magic numbers of impossibility
    final static int MAGIC1 = 2;
    final static int MAGIC2 = 3;
    final static int MAGIC3 = 5;
    final static int MAGIC4 = 7;
    //Magic numbers of possibility
    final static int MAGIC_1 = 1;
    final static int MAGIC_3 = 3;
    final static int MAGIC_5 = 5;

    public static void main(String args[]) throws Exception {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        scanner = new Scanner(new FileReader("ProblemC.txt"));
        FileWriter fileWriter = new FileWriter("ProblemС.out");
        BufferedWriter bw = new BufferedWriter(fileWriter);

        T = scanner.nextInt();
        for (int testNumber = 1; testNumber <= T; ++testNumber) {
            N = scanner.nextInt();
            M = scanner.nextInt();
            K = scanner.nextInt();

            StringBuilder answer = new StringBuilder("Case #" + testNumber + ": " + N + " " + M + " " + K);
            //System.out.println(answer.toString());
            //bw.write(answer.toString());
            bw.write("Case #" + testNumber + ":");
            bw.newLine();

            if (N == 1 || M == 1) {
                bw.write("c");
                bw.newLine();
            } else{
            if (N == 1 || M == 1) {
                for (int i = 1; i <= N; ++i) {
                    answer = new StringBuilder(M);
                    for (int j = M; j > 0; --j) {
                        if (K > 0) {
                            answer.insert(0, '*');
                            --K;
                        } else {
                            answer.insert(0, '.');
                        }
                    }
                    if (i == N) {
                        answer.replace(0, 1, "c");
                    }
                    //System.out.println(answer.toString());
                    bw.write(answer.toString());
                    bw.newLine();
                }
            } else if (N == 2 || M == 2) {
                if ((K % 2 == 1 && K != (N * M - 1)) || (K % 2 == 0 && K == (N * M - 2))) {
                    //System.out.println("Impossible");
                    bw.write("Impossible");
                    bw.newLine();
                } else {
                    int count = K;
                    for (int i = 1; i <= N; ++i) {
                        answer = new StringBuilder(M);
                        if (N == 2) {
                            count = (K + 1) / N;
                        }
                        for (int j = M; j > 0; --j) {
                            if (count > 0) {
                                answer.insert(0, '*');
                                --count;
                            } else {
                                answer.insert(0, '.');
                            }
                        }
                        if (i == N) {
                            answer.replace(0, 1, "c");
                        }
                        //System.out.println(answer.toString());
                        bw.write(answer.toString());
                        bw.newLine();
                    }
                }
            } else {
                int max = N * M;
                if ((K == max - MAGIC1) || (K == max - MAGIC2) || (K == max - MAGIC3) || (K == max - MAGIC4)) {
                    //System.out.println("Impossible");
                    bw.write("Impossible");
                    bw.newLine();
                } else {
                    char[][] array = new char[N][M];
                    if (K == max - 1) {
                        for (int i = 0; i < N; ++i) {
                            for (int j = 0; j < M; ++j) {
                                array[i][j] = '*';
                            }
                        }
                        array[0][0] = 'c';
                    } else {
                        for (int i = 0; i < N; ++i) {
                            for (int j = 0; j < M; ++j) {
                                array[i][j] = '.';
                            }
                        }
                        array[0][0] = 'c';

                        int currentN = N;
                        int currentM = M;
                        while (K > 0) {
                            if (currentN > MAGIC) {
                                if (K < currentM) {
                                    for (int i = currentM - 1; i > 1; --i) {
                                        if (K > 0) {
                                            array[currentN - 1][i] = '*';
                                            --K;
                                        }
                                    }
                                    if (K > 0) {
                                        array[currentN - 2][currentM - 1] = '*';
                                    }
                                } else {
                                    for (int i = 0; i < currentM; ++i) {
                                        array[currentN - 1][i] = '*';
                                        --K;
                                    }
                                    --currentN;
                                }
                            } else if (currentM > MAGIC) {
                                if (K >= MAGIC) {
                                    for (int i = 0; i < currentN; ++i) {
                                        array[i][currentM - 1] = '*';
                                        --K;
                                    }
                                    --currentM;
                                } else {
                                    for (int i = currentM - 1; i > 1; --i) {
                                        if (K > 0) {
                                            array[currentN - 1][i] = '*';
                                            --K;
                                        }
                                    }
                                }
                            } else {
                                if (K == MAGIC_1) {
                                    array[MAGIC - 1][MAGIC - 1] = '*';
                                    --K;
                                } else if (K == MAGIC_3) {
                                    for (int i = 0; i < MAGIC; ++i) {
                                        array[i][MAGIC - 1] = '*';
                                        --K;
                                    }
                                } else if (K == MAGIC_5) {
                                    for (int i = 0; i < MAGIC; ++i) {
                                        array[i][MAGIC - 1] = '*';
                                        --K;
                                    }
                                    for (int i = 0; i < MAGIC - 1; ++i) {
                                        array[MAGIC - 1][i] = '*';
                                        --K;
                                    }
                                    if (K != 0) {
                                        K = 0;
                                    }
                                }
                            }
                        }
                    }
                    for (int i = 0; i < N; ++i) {
                        answer = new StringBuilder(M);
                        for (int j = 0; j < M; ++j) {
                            answer.append(array[i][j]);
                        }
                        //System.out.println(answer.toString());
                        bw.write(answer.toString());
                        bw.newLine();
                    }
                }
            }
        }
        }
        bw.close();
    }
}