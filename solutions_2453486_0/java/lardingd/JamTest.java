package com.amazon.shrek.test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.StringUtils;

public class JamTest {

    public static void main(String[] args) throws IOException {
        BufferedReader br = null;
        BufferedWriter bw = null;
        try {
            br = new BufferedReader(new FileReader("randomFile.txt"));
            bw = new BufferedWriter(new FileWriter("output.txt"));
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
        try {
            String thisLine = br.readLine();
            int cases = Integer.parseInt(thisLine);
            int which = 1;
            List<String> game = new ArrayList<String>();
            String[] rows = new String[4];
            while ((thisLine = br.readLine()) != null) {
                if (StringUtils.isBlank(thisLine)) {
                    rows[0] = game.get(0);
                    rows[1] = game.get(1);
                    rows[2] = game.get(2);
                    rows[3] = game.get(3);
                    FourToe fourToe = new FourToe(rows);
                    bw.write(String.format("Case #%s: %s",which,fourToe.getSituation()));
                    bw.newLine();
                    game.clear();
                    which++;
                } else {
                    game.add(thisLine);
                }
            }
            rows[0] = game.get(0);
            rows[1] = game.get(1);
            rows[2] = game.get(2);
            rows[3] = game.get(3);
            FourToe fourToe = new FourToe(rows);
            bw.write(String.format("Case #%s: %s",which,fourToe.getSituation()));
            game.clear();
            which++;
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        bw.close();
    }
    
    private static class FourToe {
        List<String> cases;
        public FourToe(String[] rows) {
            cases = new ArrayList<String>();
            cases.add(rows[0]);
            cases.add(rows[1]);
            cases.add(rows[2]);
            cases.add(rows[3]);
            for (int i = 0; i < 4; i++) {
                cases.add(rows[0].substring(i,i+1) + rows[1].substring(i,i+1) + rows[2].substring(i,i+1) + rows[3].substring(i,i+1));
            }
            cases.add(rows[0].substring(0,1) + rows[1].substring(1,2) + rows[2].substring(2,3) + rows[3].substring(3,4));
            cases.add(rows[0].substring(3,4) + rows[1].substring(2,3) + rows[2].substring(1,2) + rows[3].substring(0,1));
        }
        
        private String getSituation() {
            for (String consider : cases) {
                if (consider.matches("[XT]{4}")) {
                    return "X won";
                }
                if (consider.matches("[OT]{4}")) {
                    return "O won";
                }
            }
            for (int i = 0; i< 4; i++) {
                if (cases.get(i).contains(".")) {
                    return "Game has not completed";
                }
            }
            
            return "Draw";
        }
    }
}
