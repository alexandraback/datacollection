import java.io.*;
import java.util.*;

public class Probability {
    public static void main(String[] args) {
        int T, counter = 1;
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("output.txt"))));
            String input = reader.readLine();

            T = Integer.parseInt(input);
            while (T-- > 0) {
                Map<Integer,Integer> inputMap = new HashMap<Integer, Integer>();
                Map<Integer,Double> sol = new HashMap<Integer, Double>();
                System.out.println("case #:" + (counter));
                int zeroCount = 0;
                input = reader.readLine();
                String[] in = input.split(" ");
                int N;
                List<Integer> points = new ArrayList<Integer>();
                N = Integer.parseInt(in[0]);
                int count = 1;
                for (int i = 0; i < N; i++) {
                    int i1 = Integer.parseInt(in[count]);
                    points.add(i1);
                    inputMap.put(i,i1);
                    count = count + 1;
                    if (i1 == 0) {
                        zeroCount++;
                    }
                }

                List<Double> minPer = new ArrayList<Double>();
                int X = 0;
                for (int i : points) {
                    X += i;
                }
                System.out.println("zeroCount:" + zeroCount);
                Collections.sort(points);
                if (zeroCount == N - 1) {
                    for (int i = 0; i < N; i++) {
                        if (points.get(i) == 0) {
                            sol.put(points.get(i),1.0 / (N - 1));
                        } else {
                            sol.put(points.get(i),0.0);
                        }
                    }
                } else {
                    System.out.println("X:" + X);
                    int negCount = 0;
                    int total = N;
                    int Y=X;
                    int sub=0;
                    for (int i = N-1; i >=0; i--) {
                        int interestedSum = Y-points.get(i);
                        double per = (X+ interestedSum - ((total-1) * points.get(i)))/(double) (total * X);
                        if (per >= 0) {
                            if(negCount>0)
                            {
                                i++;
                                total= total-negCount;
                                negCount=0;
                                Y-=sub;
                                continue;
                            }
                            sol.put(points.get(i),per);
                            minPer.add(per);
                        } else {
                            minPer.add(0.0);
                            sol.put(points.get(i),0.0);
                            negCount++;
                            sub+=points.get(i);
                        }
                    }
                }
                for (double d : minPer) {
                    System.out.println(d * 100);
                }

                writer.write("Case #" + counter + ":");
                List<Double> mm= new ArrayList<Double>();
                for(int i=0;i<N;i++)
                {
                   mm.add(sol.get(inputMap.get(i)));
                }
                for (double d : mm) {
                    {
                        double dd= d*1000000000;
                        writer.write(" " + ((double) Math.round(dd) / 10000000));
                    }
                }
                writer.write("\n");
                counter++;
            }
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
