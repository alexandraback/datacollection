package com.elders.code.jam;

import java.io.*;
import java.util.*;

public class Main {
    final String file = "C-small-attempt0";

    FastScanner in;
    PrintWriter out;

    void solve() {
        long tc = in.nextLong();
        System.out.println("tc = " + tc);
        for (long t = 0; t < tc; t++) {
            System.out.println("t = " + t);
            out.print("Case #" + (t + 1) + ": ");

            int N = in.nextInt();
            List<KidNode> kids = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                kids.add(new KidNode(in.nextInt() - 1));
            }

            Set<Integer> initializedKids = new HashSet<>();
            int largestCycle = 0;
            int largestCycleIndex = 0;
            Set<KidNode> mutualFriends = new HashSet<>();

            for (int i = 0; i < N; i++) {
                if (!initializedKids.contains(i)) {
                    Set<Integer> loopKids = new HashSet<>();
                    int currentKid = i;
                    while (!loopKids.contains(currentKid)) {
                        initializedKids.add(currentKid);
                        loopKids.add(currentKid);
                        currentKid = kids.get(currentKid).bff;
                    }

                    int currentKidBff = kids.get(currentKid).bff;
                    if (currentKid == kids.get(currentKidBff).bff) {
                        mutualFriends.add(kids.get(currentKid));
                        kids.get(currentKid).type = KidNode.KidType.MUTUAL;

                        if (kids.get(currentKid).treeLength < loopKids.size() - 1) {
                            kids.get(currentKid).treeRoot = i;
                            kids.get(currentKid).treeLength = loopKids.size() - 1;
                        }

                        mutualFriends.add(kids.get(currentKidBff));
                        kids.get(currentKidBff).type = KidNode.KidType.MUTUAL;
                        if (kids.get(currentKidBff).treeLength == 0) {
                            kids.get(currentKidBff).treeRoot = currentKidBff;
                            kids.get(currentKidBff).treeLength = 1;
                        }

                        int nextKid = i;
                        int treeHeight = loopKids.size() - 1;
                        while (nextKid != currentKid && nextKid != currentKidBff) {
                            kids.get(nextKid).type = KidNode.KidType.TREE;
                            kids.get(nextKid).treeLength = treeHeight;
                            kids.get(nextKid).treeRoot = currentKid;
                            treeHeight--;
                            nextKid = kids.get(nextKid).bff;
                        }
                    } else {
                        int deadKids = 0;
                        int possiblyDeadKid = i;
                        while (possiblyDeadKid != currentKid) {
                            deadKids++;
                            possiblyDeadKid = kids.get(possiblyDeadKid).bff;
                        }
                        if (loopKids.size() - deadKids > largestCycle) {
                            largestCycle = loopKids.size() - deadKids;
                            largestCycleIndex = currentKid;
                        }
                        for (int cycleKid : loopKids) {
                            kids.get(cycleKid).type = KidNode.KidType.CYCLE;
                            kids.get(cycleKid).treeLength = loopKids.size();
                        }
                    }
                }
            }


            int mutualFriendScore = 0;
            for (KidNode friend : mutualFriends) {
                mutualFriendScore += friend.treeLength;
            }

            /*if (mutualFriendScore > largestCycle) {
                System.out.println("Printing Friends");
                while (!mutualFriends.isEmpty()) {
                    KidNode dude = mutualFriends.iterator().next();
                    KidNode dudeFriend = kids.get(dude.bff);
                    int dudeIndex = dudeFriend.bff;
                    int dudeFriendIndex = dude.bff;
                    mutualFriends.remove(dude);
                    mutualFriends.remove(dudeFriend);

                    int chain1kid = dude.treeRoot;
                    while (chain1kid != dudeIndex) {
                        System.out.print(" " + chain1kid);
                        chain1kid = kids.get(chain1kid).bff;
                    }

                    System.out.print(" " + dudeIndex); // dude
                    System.out.print(" " + dudeFriendIndex); // dudeFriend

                    List<Integer> chain2 = new ArrayList<>();
                    int chain2kid = dudeFriend.treeRoot;
                    while (chain2kid != dudeFriendIndex) {
                        chain2.add(chain2kid);
                        chain2kid = kids.get(chain2kid).bff;
                    }

                    for (int i = chain2.size() - 1; i >= 0; i--) {
                        System.out.print(" " + chain2.get(i));
                    }
                }
            } else {
                System.out.println("Printing cycle");
                int currentKid = largestCycleIndex;
                for (int i = 0; i < largestCycle; i++) {
                    System.out.print(" " + currentKid);
                    currentKid = kids.get(currentKid).bff;
                }
            }

            System.out.print("\n");*/

            out.println(mutualFriendScore > largestCycle ? mutualFriendScore : largestCycle);
        }
    }

    static class KidNode {
        KidNode(int theBff) {
            bff = theBff;
        }

        final int bff;
        KidType type;
        int treeRoot;
        int treeLength = 0;

        enum KidType {CYCLE, MUTUAL, TREE, DEAD};
    }

    void run() {
        try {
            in = new FastScanner(new File(file + ".in"));
            out = new PrintWriter(new File(file + ".out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !(st.hasMoreTokens())) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null) {
                    return null;
                }
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(this.next());
        }

        long nextLong() {
            return Long.parseLong(this.next());
        }

        double nextDouble() {
            return Double.parseDouble(this.next());
        }


    }

    public static void main(String ... args) {
        System.out.println("Starting...");
        new Main().run();
    }
}
