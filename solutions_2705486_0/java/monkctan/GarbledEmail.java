package gcj2013.rd1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.PriorityQueue;

public class GarbledEmail {
    private static String folder = "src/gcj2013/rd1b";
    private static String filename = "C-small-attempt1";

    // private TrieNode root = new TrieNode((char) ('z' + 1), false, null);
    private TrieNode root = new TrieNode(false);
    private String s;

    private static class TrieNode {
        // public char ch;
        public boolean isWord;
        // public TrieNode parent;
        public TrieNode[] children;

        // public TrieNode(char c, boolean isWord, TrieNode parent) {
        public TrieNode(boolean isWord) {
            // this.ch = c;
            this.isWord = isWord;
            // this.parent = parent;
            this.children = null;
        }
    }

    private static class SearchState implements Comparable<SearchState> {
        public int index;
        public int numChanges;
        public int lastChangeIndex;

        public SearchState(int index, int numChanges, int lastChangeIndex) {
            this.index = index;
            this.numChanges = numChanges;
            this.lastChangeIndex = lastChangeIndex;
        }

        @Override
        public int compareTo(SearchState o) {
            int d1 = this.numChanges - o.numChanges;
            if (d1 != 0) {
                return d1;
            }

            int d2 = o.index - this.index;
            if (d2 != 0) {
                return d2;
            }

            return this.lastChangeIndex - o.lastChangeIndex;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + index;
            result = prime * result + lastChangeIndex;
            result = prime * result + numChanges;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            SearchState other = (SearchState) obj;
            if (index != other.index)
                return false;
            if (lastChangeIndex != other.lastChangeIndex)
                return false;
            if (numChanges != other.numChanges)
                return false;
            return true;
        }
    }

    private void buildTrie() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(new File(folder,
                                                                               "garbled_email_dictionary.txt")));
            while (true) {
                String line = reader.readLine();
                if (line == null) {
                    break;
                }

                addWord(line);
            }
            reader.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void addWord(String word) {
        TrieNode curr = root;
        for (int i = 0; i < word.length(); ++i) {
            if (curr.children == null) {
                curr.children = new TrieNode[26];
            }

            char c = word.charAt(i);
            TrieNode child = curr.children[c - 'a'];
            if (child == null) {
                // child = new TrieNode(c, false, curr);
                child = new TrieNode(false);
                curr.children[c - 'a'] = child;
            }

            if (i == word.length() - 1) {
                child.isWord = true;
            } else {
                curr = child;
            }
        }
    }

    private int findMinChanges(String s) {
        this.s = s;
        PriorityQueue<SearchState> pq = new PriorityQueue<SearchState>();
        SearchState init = new SearchState(0, 0, -5);
        pq.add(init);

        HashSet<SearchState> visited = new HashSet<SearchState>();
        visited.addAll(pq);

        while (true) {
            SearchState currSS = pq.remove();
//            System.out.println("index=" + currSS.index);
//            System.out.println("numChanges=" + currSS.numChanges);
//            System.out.println("lastChangeIndex=" + currSS.lastChangeIndex);
//            System.out.println();

            if (currSS.index == s.length()) {
                return currSS.numChanges;
            }
            
            HashSet<SearchState> newStates = searchWord(currSS);
            for (SearchState ss : newStates) {
                if (!visited.contains(ss)) {
                    pq.add(ss);
                    visited.add(ss);
                }
            }
        }
    }

    private HashSet<SearchState> searchWord(SearchState currSS) {
        TrieNode currNode = root;
        HashSet<SearchState> newStates = searchWordRecursive(currNode,
                                                             currSS.index,
                                                             currSS.numChanges,
                                                             currSS.lastChangeIndex);

        // for (SearchState ss : newStates) {
        // System.out.println("index=" + ss.index);
        // System.out.println("numChanges=" + ss.numChanges);
        // System.out.println("lastChangeIndex=" + ss.lastChangeIndex);
        // }

        return newStates;
    }

    private HashSet<SearchState> searchWordRecursive(TrieNode currNode,
                                                     int index,
                                                     int numChanges,
                                                     int lastChangeIndex) {
        HashSet<SearchState> newStates = new HashSet<SearchState>();
        if (currNode.isWord) {
            newStates.add(new SearchState(index, numChanges, lastChangeIndex));
        }

        if (index == s.length()) {
            return newStates;
        }

        if (currNode.children != null) {
            char currChar = s.charAt(index);
            TrieNode nextNode = currNode.children[currChar - 'a'];
            if (nextNode != null) {
                newStates.addAll(searchWordRecursive(nextNode,
                                                     index + 1,
                                                     numChanges,
                                                     lastChangeIndex));
            }

            if (lastChangeIndex + 5 <= index) {
                for (int i = 0; i < 26; ++i) {
                    if (i != currChar - 'a') {
                        nextNode = currNode.children[i];
                        if (nextNode != null) {
                            newStates
                                    .addAll(searchWordRecursive(nextNode,
                                                                index + 1,
                                                                numChanges + 1,
                                                                index));
                        }
                    }
                }
            }
        }

        return newStates;
    }

    public static void main(String[] args) {
        try {
            File inputFile = new File(folder, filename + ".in");
            File outputFile = new File(folder, filename + ".out");

            GarbledEmail ge = new GarbledEmail();

            ge.buildTrie();

            BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            PrintWriter pw = new PrintWriter(outputFile);
            int numTestCases = Integer.parseInt(reader.readLine());
            for (int t = 0; t < numTestCases; ++t) {
                String s = reader.readLine().trim();
                int minChanges = ge.findMinChanges(s);

                String result = String
                        .format("Case #%d: %d", t + 1, minChanges);
                System.out.println(result);
                pw.println(result);
            }
            reader.close();
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
