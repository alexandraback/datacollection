package c2014_c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Z2_1 {
    //x/c-2/f

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\2014\\z2.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-large.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            double c = scanner.nextDouble();
            double f = scanner.nextDouble();
            double x = scanner.nextDouble();
            double speed = 2;
            double time = 0;
            int i =0 ;
            //System.out.println((x/c)-(2/f));
            do {
                double s1 = c/speed;
                double s2 = x/speed;
                double v = x / (speed);
                double v2 = (c/speed) + (x  / (speed+f));
                if ((x<c) || (v < v2)) {
                    time += s2;
                    break;
                } else {
                    time += s1;
                    speed += f;
                    i++;
                }
            } while (true);
            String s;
                s = "Case #" + ti + ": " + time;
            System.out.println(s);
            //System.out.println(i);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

}
