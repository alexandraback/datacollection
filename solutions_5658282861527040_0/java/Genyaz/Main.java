package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
        StringTokenizer tokens = new StringTokenizer(in.readLine());
        PrintWriter out = new PrintWriter("B-small-attempt0.out");
        int t = Integer.parseInt(tokens.nextToken());
        for (int tt = 1; tt <= t; tt++) {
            tokens = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(tokens.nextToken());
            int b = Integer.parseInt(tokens.nextToken());
            int k = Integer.parseInt(tokens.nextToken());
            int answer = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if ((i&j) < k) answer++;
                }
            }
            out.println("Case #" + tt + ": " + answer);
        }
        in.close();
        out.close();
    }
}
