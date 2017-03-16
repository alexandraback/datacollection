package gcj2014.qualification.d;

import gcj2014.qualification.c.MinesweeperMaster;

import java.io.*;
import java.net.URISyntaxException;
import java.util.ArrayList;

/**
 * Created by zeejfps on 4/12/14.
 */
public class DeceitfulWar {

    public static void main(String[] args) {

        try {

            File input_file = new File(DeceitfulWar.class.getResource("input.in").toURI());
            File output_file = new File("/home/zeejfps/Programming/Java/GoogleCodeJam/src/gcj2014/qualification/d/output.txt");

            BufferedReader br = new BufferedReader(new FileReader(input_file));
            BufferedWriter bw = new BufferedWriter(new FileWriter(output_file));

            int num_cases = Integer.parseInt(br.readLine());

            for (int i_case = 0; i_case < num_cases; i_case++) {

                bw.write("Case #" + (i_case+1) + ": ");
                System.out.println("Case #" + (i_case+1) + ": ");

                int num_blocks = Integer.parseInt(br.readLine());
                System.out.println("--> Blocks: " + num_blocks);

                String[] tokens = br.readLine().split(" ");

                System.out.print("--> Naomi's Blocks: ");
                ArrayList<Double> naomis_blocks = new ArrayList<Double>();
                for (int i = 0; i < num_blocks; i++) {

                    naomis_blocks.add(Double.parseDouble(tokens[i]));
                    System.out.print(tokens[i] + " ");

                }
                System.out.println();

                tokens = br.readLine().split(" ");

                System.out.print("--> Ken's Blocks: ");
                ArrayList<Double> kens_blocks = new ArrayList<Double>();
                for (int i = 0; i < num_blocks; i++) {

                    kens_blocks.add(Double.parseDouble(tokens[i]));
                    System.out.print(tokens[i] + " ");

                }
                System.out.println();

                int war_points = 0;
                int deceitful_war_points = 0;

                System.out.println("--> ~~~~WAR~~~~");

                deceitful_war_points = playDeceitfulWar(new ArrayList<Double>(naomis_blocks), new ArrayList<Double>(kens_blocks), num_blocks);
                war_points = playWar(new ArrayList<Double>(naomis_blocks), new ArrayList<Double>(kens_blocks), num_blocks);

                System.out.println("--> ~~~~END~~~~");

                System.out.println("--> Deceitful War Points: " + deceitful_war_points);
                System.out.println("--> War Points: " + war_points);
                bw.write(deceitful_war_points + " " + war_points);
                bw.newLine();
            }

            br.close();
            bw.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }

    }

    public static int playWar(ArrayList<Double> naomis_blocks, ArrayList<Double> kens_blocks, int num_blocks) {

        int points = 0;
        int turns = num_blocks;
        while (turns > 0) {

            Double naomis_block = naomis_blocks.get(0);
            //System.out.println("--> Naomi's block: " + naomis_block);

            Double ken_block = 1.0;
            for (int j = 0; j < kens_blocks.size(); j++) {

                if (kens_blocks.get(j) > naomis_block && kens_blocks.get(j) < ken_block) {

                    ken_block = kens_blocks.get(j);

                }

            }
            //System.out.println("--> Ken's Block: " + ken_block);

            if (ken_block == 1) {
                points++;
            }

            naomis_blocks.remove(naomis_block);
            kens_blocks.remove(ken_block);
            turns--;

        }

        return points;
    }

    public static int playDeceitfulWar(ArrayList<Double> naomis_blocks, ArrayList<Double> kens_blocks, int num_blocks) {

        int points = 0;

        int turn = num_blocks;
        while (turn > 0) {

            Double smallest = 1.0;
            for (int i = 0; i < naomis_blocks.size(); i++) {

                if (naomis_blocks.get(i) < smallest) {
                    smallest = naomis_blocks.get(i);
                }

            }

            Double largest = 0.0;
            for (int i = 0; i < kens_blocks.size(); i++) {

                if (smallest > kens_blocks.get(i)) {

                    largest = kens_blocks.get(i);
                    points++;
                    break;

                } else if (kens_blocks.get(i) > largest) {
                    largest = kens_blocks.get(i);
                }

            }

            naomis_blocks.remove(smallest);
            kens_blocks.remove(largest);
            turn--;

        }

        return points;
    }

}
