package qualification;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;



public class ProblemD {
    
    static class Chest implements Comparable<Chest> {
        int type;
        List<Integer> keys;
        int number;
        boolean opened = false;

        @Override
        public int compareTo(Chest o) {
            int res = Integer.compare(type, o.type);
            if (res == 0) {
                return Integer.compare(number, o.number);
            } else {
                return res;
            }
        }
        
        @Override
        public String toString() {
            return "Type " + type + "; keys: " + keys.toString();
        }
    }
    
    private static final boolean FROM_FILE = true;
    private static final String INPUT_FILE = "input.txt";
    
    private InputStream getInputStream() throws FileNotFoundException {
        if (FROM_FILE) {
            return new FileInputStream(new File(INPUT_FILE));
        } else {
            return System.in;
        }
    }
    
    private void closeInputStream(InputStream is) throws IOException {
        if (FROM_FILE) {
            is.close();
        }
    }
    
    public static <T extends Comparable<? super T>> void insertSorted(List<T> l, T el) {
        int index = Collections.binarySearch(l, el);
        if (index < 0) {
            index = - (index + 1);
        }
        l.add(index, el);
    }
    
    int K;
    int N;
    int[] keys;
    List<Chest> chests;
    List<Chest> chestsSequence;
    
    int findNext() {
        int index = -1;
        for (int i = 0; i < chests.size(); i++) {
            if (keys[chests.get(i).type] > 0) {
                index = i;
                break;
            } 
        }
        
        return index;
    }
    
    int findPrevious(int key) {
       int index = -1;
       for (int i = 0; i < chests.size(); i++) {
           if (chests.get(i).keys.contains(key)
                   && (keys[chests.get(i).type] > 0) || (chests.get(i).type == key)) {
               index = i;
               break;
           } 
       }
       
       return index;
    }
    
    void makeSequence() {
        for (int i = 0; i < N; i++) {
            int index = findNext();
            if (index != -1) {
                Chest chest = chests.get(index);
                chestsSequence.add(chest);
                keys[chest.type]--;
                for (int key : chest.keys) {
                    keys[key]++;
                }
                chests.remove(index);
                continue;
            }
            
            if (chestsSequence.size() > 0) {
                index = findPrevious(chestsSequence.get(0).type);
                if (index != -1) {
                    Chest chest = chests.get(index);
                    chestsSequence.add(0, chest);
                    keys[chest.type]--;
                    for (int key : chest.keys) {
                        keys[key]++;
                    }
                    chests.remove(index);
                    continue;
                }
            }
            
            break;
        }
    }
    
    
    int recursion = 0;
    boolean find() {
        boolean result = false;
        boolean allOpened = true;
        //System.out.println(recursion++);
        for (Chest chest : chests) {
            if (!chest.opened) {
                allOpened = false;
                if (keys[chest.type] > 0) {
                    chest.opened = true;
                    keys[chest.type]--;
                    chestsSequence.add(chest);
                    for (int key : chest.keys) {
                        keys[key]++;
                    }
                    
                    result = find();
                    if (result) {
                        break;
                    }
                    
                    // revert all back
                    chest.opened = false;
                    keys[chest.type]++;
                    chestsSequence.remove(chestsSequence.size() - 1);
                    for (int key : chest.keys) {
                        keys[key]--;
                    }  
                }
            }   
        }
        
        recursion--;
        if (allOpened) {
            return true;
        }
        
        return result;
    }
    
    public void solve() {
        InputStream is = null;
        
        try {
            is = getInputStream();
            Scanner scanner = new Scanner(new File("input.txt"));
            FileWriter writer = new FileWriter(new File("output.txt"));
            
            int T = scanner.nextInt();
            scanner.nextLine();
            
            for (int t = 1; t <= T; t++) {
                
                K = scanner.nextInt();
                N = scanner.nextInt();
                scanner.nextLine();
                
                //keys = new ArrayList<Integer>(K);
                keys = new int[201];
                for (int i = 0; i < K; i++) {
                    int key = scanner.nextInt();
                    keys[key]++;
                    //insertSorted(keys, key);
                }
                scanner.nextLine();
                
                chests = new ArrayList<Chest>(N);
                //chestsTypes = new int[N];
                //chestsKeys = new List[N];
                for (int i = 0; i < N; i++) {
                    Chest chest = new Chest();
                    chest.type = scanner.nextInt();
                    int keysCountInChest = scanner.nextInt();
                    chest.keys = new ArrayList<Integer>(keysCountInChest);
                    chest.number = i + 1;
                    for (int j = 0; j < keysCountInChest; j++) {
                        int key = scanner.nextInt();
                        chest.keys.add(key);
                    }
                    chests.add(chest);
                    try {
                        scanner.nextLine();
                    } catch (NoSuchElementException e) {}
                }
                
                Collections.sort(chests);
                
                //System.out.println("Keys " + Arrays.toString(keys));
                //System.out.println("Chests: " );
                //for (Chest chest : chests) {
                //    System.out.println(chest.toString());
                //}
                                
                String result = "Case #" + t + ":";
                
                chestsSequence = new ArrayList<Chest>();
                makeSequence();
                if (chestsSequence.size() == N) {
                    for (Chest chest : chestsSequence) {
                        result += " " + chest.number;
                    }
                } else {
                    result += " IMPOSSIBLE";
                }

                System.out.println(result);
                writer.write(result + "\n");

            }
            
            scanner.close();
            writer.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if ( is != null) {
                try {
                    closeInputStream(is);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        (new ProblemD()).solve();
    }
    
    
    
}
