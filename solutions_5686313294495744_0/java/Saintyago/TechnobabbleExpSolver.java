/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author santiago
 */
public class TechnobabbleExpSolver {

    private static final String PATH_IN = "C:\\Users\\santiago\\Desktop\\codeJam\\small.in";
    private static final String PATH_OUT = "C:\\Users\\santiago\\Desktop\\codeJam\\small.out";

    private static class Topic {

        private final String first;
        private final String second;

        public Topic(String line) {
            String[] split = line.split(" ");
            first = split[0];
            second = split[1];
        }

        public String getFirst() {
            return first;
        }

        public String getSecond() {
            return second;
        }

    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new java.io.FileReader(PATH_IN));
            BufferedWriter bw = new BufferedWriter(new FileWriter(PATH_OUT));
            int numberOfTests = Integer.parseInt(br.readLine());
            for (int test = 1; test <= numberOfTests; test++) {
                int numberOfTopics = Integer.parseInt(br.readLine());
                Topic[] topics = new Topic[numberOfTopics];
                for (int i = 0; i < numberOfTopics; i++) {
                    topics[i] = new Topic(br.readLine());
                }
                bw.write("case #" + test + ": " + solve(topics));
                bw.newLine();
            }
            br.close();
            bw.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(TechnobabbleExpSolver.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(TechnobabbleExpSolver.class.getName()).log(Level.SEVERE, null, ex);
        } catch (Exception ex) {
            Logger.getLogger(TechnobabbleExpSolver.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static int solve(Topic[] topics) {
        return solve(topics, 0, new ArrayList<Topic>());
    }

    private static int solve(Topic[] topics, int position, List<Topic> originals) {
        if (position == topics.length) {
            return validSolution(topics, originals) ? topics.length - originals.size() : 0;
        } else {
            originals.add(topics[position]);
            int sol1 = solve(topics, position + 1, originals);
            originals.remove(topics[position]);
            int sol2 = solve(topics, position + 1, originals);
            return Math.max(sol1, sol2);
        }
    }

    private static boolean validSolution(Topic[] topics, List<Topic> originals) {
        for (Topic topic : topics) {
            if (!mayBeFake(topic, originals)) {
                return false;
            }
        }
        return true;
    }

    private static boolean mayBeFake(Topic topic, List<Topic> existing) {
        boolean existFirst = false;
        boolean existsSecond = false;
        for (Topic original : existing) {
            if (topic.getFirst().equals(original.getFirst())) {
                if (existsSecond) {
                    return true;
                }
                existFirst = true;
            }
            if (topic.getSecond().equals(original.getSecond())) {
                if (existFirst) {
                    return true;
                }
                existsSecond = true;
            }
        }
        return existFirst && existsSecond;
    }

}
