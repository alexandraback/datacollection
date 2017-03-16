
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author ZuoZhong
 */
public class Recycled {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File file = new File("C-small-attempt0.in");
        BufferedReader in = new BufferedReader(new FileReader(file));
        BufferedWriter out = new BufferedWriter(new FileWriter("Recycled_output.txt"));
        ArrayList<String> list = new ArrayList();

        int T = Integer.parseInt(in.readLine());

        for (int x = 1; x <= T; x++) {
            int ans = 0;
            list.clear();
            String[] input = in.readLine().split(" ");
            if (Integer.parseInt(input[1]) > 10) {
                int start = Integer.parseInt(input[0]);
                int end = Integer.parseInt(input[1]);
                for (int y = end; y >= start; y--) {
                    String value = Integer.toString(y);
                    for (int z = 0; z < value.length(); z++) {
                        String temp = value + value;
                        //System.out.print(value);
                        temp = temp.substring(z, z + value.length());
                        //System.out.print(" to " + temp);
                        if (temp.charAt(0) == '0') {
                            //skip
                            //System.out.println(" skip");
                        } else if (temp.compareTo(value) == 0) {
                            //skip
                            //System.out.println(" skip");
                        } else if (Integer.parseInt(temp) > end) {
                            //skip
                            //System.out.println(" skip");
                        } else if (Integer.parseInt(temp) < Integer.parseInt(value)) {
                            //skip
                            //System.out.println(" skip");
                        } else {
                            boolean exist = false;
                            try {
                                for (int a = 1; a < value.length(); a++) {
                                    String pre = list.get(ans - a);
                                    if (pre.compareTo(temp) == 0) {
                                        exist = true;
                                        break;
                                    }
                                }
                            } catch (Exception e) {
                            }
                            if (!exist) {
                                ans++;
                                list.add(temp);
                                //System.out.println(" added : " + ans);
                            } else {
                                //System.out.println(" skip");
                            }
                        }
                    }
                }

                for (String v : list) {
                    System.out.print(v + " ");
                }
                System.out.println();
            }
            out.write("Case #" + x + ": " + ans);
            System.out.println("Case #" + x + ": " + ans);
            out.newLine();
        }
        out.close();
    }
}
