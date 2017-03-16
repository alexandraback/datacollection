import java.io.*;

public class Pancakes {

    public static void main (String[] args) {
        BufferedReader br;
        BufferedWriter bw;
        try {
            br = new BufferedReader(new FileReader("B-small-attempt5.in"));
            bw = new BufferedWriter(new FileWriter("B-small.out"));
            int n = Integer.parseInt(br.readLine());
            for (int iii = 1; iii <= n; iii++) {
                bw.write("Case #" + iii + ": ");
                int d = Integer.parseInt(br.readLine());
                String[] splits = br.readLine().split(" ");
                int max = 0;
                int[] nums = new int[d];
                for (int jjj = 0; jjj < d; jjj++) {
                    int temp = Integer.parseInt(splits[jjj]);
                    nums[jjj] = temp;
                    if (temp > max) {
                        max = temp;
                    }
                }
                int totalMin = 0;
                int eatingMin = 0;
                int[] numPerAmount = new int[max + 1];
                for (int jjj = 0; jjj < d; jjj++) {
                    numPerAmount[nums[jjj]]++;
                }
                boolean cont;
                int contNum;
                while (true) {
                    cont = false;
                    contNum = 0;
                    int i = max;
                    for (; i > eatingMin; i--) {
                        if (numPerAmount[i] == 0) continue;
                        int currentI = i - eatingMin;
                        if (currentI > max) {
                            max = i;
                        }
                        if ((currentI / 2) > numPerAmount[i] && !(currentI - 1 - contNum/2 <= numPerAmount[i])) {
                            if (currentI % 2 == 0) {
                                totalMin += numPerAmount[i];
                                numPerAmount[currentI/2 + eatingMin] += numPerAmount[i] * 2;
                                numPerAmount[i] = 0;
                                if (i == max) {
                                    max = 0;
                                }
                            } else if (!cont) {
                                cont = true;
                                contNum = currentI;
                            }
                        }
                    }
                    if (i == eatingMin) {
                        if (!cont) {
                            totalMin += (max - eatingMin);
                            break;
                        } else {
                            eatingMin++;
                            totalMin++;
                        }
                    }
                }
                bw.write("" + totalMin);
                bw.newLine();
            }
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
