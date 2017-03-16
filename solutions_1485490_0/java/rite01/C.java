import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.NumberFormat;

/**
 * Created with IntelliJ IDEA. User: Welcome Date: 6/5/12 Time: 3:30 PM To change this template use File | Settings |
 * File Templates.
 */
public class C {
    public static String path = "./";
    //    public static String path = "C:/users/Welcome/downloads/";
    public static String fname = "C-small-attempt2.in";
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(path + fname));
        BufferedWriter writer = new BufferedWriter(new FileWriter(path + fname + ".out"));
        int tests = Integer.parseInt(reader.readLine());
        for (int test = 1; test <= tests; test++) {
            String[] splits = reader.readLine().split("[ ]");
            int N = Integer.parseInt(splits[0]);
            int M = Integer.parseInt(splits[1]);
            Batch[] boxes = batchup(reader.readLine(), N);
            Batch[] toys = batchup(reader.readLine(), M);
            int ibox = 0; int itoy = 0;
            double retval = 0;
            while (ibox < N && itoy < M) {
                Batch box = boxes[ibox];
                Batch toy = toys[itoy];
                if (box.type == toy.type) {
                    if (box.volume < toy.volume) {
                        retval += box.volume;
                        toy.volume = toy.volume - box.volume;
                        ibox++;
                    } else if (box.volume > toy.volume) {
                        retval += toy.volume;
                        box.volume = box.volume - toy.volume;
                        itoy++;
                    } else  {
                        retval += toy.volume;
                        ibox++;
                        itoy++;
                    }
                } else {
                        Tuple throwBox = canMake(toys[itoy], boxes, itoy);
                        Tuple throwToy = canMake(boxes[ibox], toys, ibox);
//                        System.out.println("Throw Box = " + throwBox  +"; Throw Toy = " + throwToy + "; ibox = " + ibox + "; itoy = " + itoy);
                        if (throwBox == null && throwToy != null) {
                           itoy++;
                        } else if (throwBox != null && throwToy == null) {
                            ibox++;
                        } else if (throwBox == null && throwToy == null) {
                            itoy++; ibox++;
                        } else {
                                if (throwBox.volume > throwToy.volume) {
                                    ibox++;
                                } else if (throwBox.volume < throwToy.volume) {
                                    itoy++;
                                } else {
                                    if (throwBox.index > throwToy.index) {
                                        itoy++;
                                    } else {
                                        ibox++;
                                    }
//                                    System.out.println(throwBox.index + "; " + throwToy.index + "; it = " + itoy +"; ib = " + ibox);
                                }
                        }
//                    System.out.println("box = " + ibox + "; toy = " + itoy  +"; retval = " + retval);
                }
            }
            NumberFormat nf = NumberFormat.getInstance();
            nf.setMaximumFractionDigits(0);
            nf.setGroupingUsed(false);
            String msg = "Case #" + test + ": " + nf.format(retval) + "\n";
            writer.write(msg);
//            System.out.print(msg);
        }
        reader.close();
        writer.close();
    }

    private static Tuple canMake(Batch batch, Batch[] batches, int current) {
        for (int i = current; i < batches.length; i++) {
            if (batches[i].type == batch.type) {
                return new Tuple(i, Math.min(batch.volume, batches[i].volume));
            }
        }
        return null;
    }

    private static class Tuple {
        private final int index;
        private final double volume;

        private Tuple(int index, double volume) {
            this.index = index;
            this.volume = volume;
        }

        @Override
        public String toString() {
            return "Tuple{" +
                    "index=" + index +
                    ", volume=" + volume +
                    '}';
        }
    }

    private static Batch[] batchup(String line, int batches) {
        Batch[] retval = new Batch[batches];
        String[] splits = line.trim().split("[ ]");
        int j = 0;
        for (int i =0; i < batches; i++) {
            retval[i] = new Batch(Integer.parseInt(splits[j+1]), Double.parseDouble(splits[j]));
            j+=2;
        }
        return retval;
    }

    private static class Batch {
        private final int type;
        private double volume;

        private Batch(int type, double volume) {
            this.type = type;
            this.volume = volume;
        }
    }
}