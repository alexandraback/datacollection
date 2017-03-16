package com.nwollmann.codejam.year_2016.round1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Nicholas on 4/30/2016.
 */
public class Technobabble {

    static final boolean CONSOLE_MODE = false;
    static String fileName = "C-small-attempt4";

    static File in, out;
    static PrintWriter writer;
    static Scanner reader;

    public static void main(String[] args) throws Exception{
        if(CONSOLE_MODE) {
            writer = new PrintWriter(System.out);
            reader = new Scanner(System.in);
        } else {
            in = new File("C:/Codejam/in/" + fileName + ".in");
            out = new File("C:/Codejam/result.out");
            writer = new PrintWriter(new FileOutputStream(out));
            reader = new Scanner(new FileInputStream(in));
        }

        solve();

        writer.close();
        reader.close();
    }

    public static void solve(){

        int cases = reader.nextInt();

        for(int i = 1; i <= cases; i++) {
            System.out.println("On case " + i);
            writer.println("Case #" + i + ": " + solveCase());
        }

    }

    public static int solveCase(){

        int count = reader.nextInt();

        HashMap<String, Integer> occurancesFirst = new HashMap<>();
        HashMap<String, Integer> occurancesSecond = new HashMap<>();

        ArrayList<Topic> topics = new ArrayList<>();

        for(int i = 0; i < count; i++) {
            Topic topic = new Topic();
            topic.first = reader.next();
            topic.second = reader.next();
            topics.add(topic);
            occurancesFirst.put(topic.first, occurancesFirst.getOrDefault(topic.first, 0) + 1);
            occurancesSecond.put(topic.second, occurancesSecond.getOrDefault(topic.second, 0) + 1);
        }

        int fakes = 0;

        /*for(Topic topic : topics) {
            if(occurancesFirst.getOrDefault(topic.first, 0) > 1 && occurancesSecond.getOrDefault(topic.second, 0) > 1) {
                occurancesFirst.put(topic.first, occurancesFirst.getOrDefault(topic.first, 0) - 1);
                occurancesSecond.put(topic.second, occurancesSecond.getOrDefault(topic.second, 0) - 1);
                fakes++;
            }
        }*/

        HashSet<String> realFirst = new HashSet<>();
        HashSet<String> realSecond = new HashSet<>();


        ArrayList<Topic> realTopics = new ArrayList<>();
        Iterator<Topic> iterator = topics.iterator();
        while(iterator.hasNext()){
            Topic topic = iterator.next();
            if(occurancesFirst.getOrDefault(topic.first, 1) == 1 || occurancesSecond.getOrDefault(topic.second, 1) == 1) {
                realTopics.add(topic);
                realFirst.add(topic.first);
                realSecond.add(topic.second);
            }
        }
        topics.removeAll(realTopics);

        ArrayList<Topic> toRemove;

        while(topics.size() > 0) {
            Topic bestToAdd = null;
            int score = -1;

            iterator = topics.iterator();
            toRemove = new ArrayList<>();

            while(iterator.hasNext()) {
                Topic topic = iterator.next();
                if(realFirst.contains(topic.first) && realSecond.contains(topic.second)) {
                    fakes++;
                    toRemove.add(topic);
                } else {
                    int possible = 0;
                    if(!realFirst.contains(topic.first))
                        possible += occurancesFirst.get(topic.first);
                    if(!realSecond.contains(topic.second))
                        possible += occurancesSecond.get(topic.second);
                    if(possible > score){
                        score = possible;
                        bestToAdd = topic;
                    }
                }
            }
            topics.removeAll(toRemove);
            if(bestToAdd != null) {
                realTopics.add(bestToAdd);
                realFirst.add(bestToAdd.first);
                realSecond.add(bestToAdd.second);
            }
        }

        /*iterator = topics.iterator();
        while(iterator.hasNext()) {
            Topic topic = iterator.next();
            if(realFirst.contains(topic.first) && realSecond.contains(topic.second)) {
                fakes++;
            } else {
                realTopics.add(topic);
                realFirst.add(topic.first);
                realSecond.add(topic.second);
            }
        } */

        return fakes;

    }

    public static class Topic {
        String first;
        String second;
    }
}
