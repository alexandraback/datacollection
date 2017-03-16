package concursoprogramacion;

import java.util.*;

public class Ejercicio3 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        
        int cases = in.nextInt();
        
        for (int k = 1; k <= cases; k++) {
            ArrayList<String> leftWord = new ArrayList<String>();
            ArrayList<String> rightWord = new ArrayList<String>();
            
            int topics = in.nextInt();
            in.nextLine();
            for (int i = 0; i < topics; i++) {
                String topic = in.nextLine();
                String[] words = topic.split(" ");
                leftWord.add(words[0]);
                rightWord.add(words[1]);
            }
            
            int ret = 0;
            for (int i = 0; i < leftWord.size(); i++) {
                int a = Collections.frequency(leftWord, leftWord.get(i));
                int b = Collections.frequency(rightWord, rightWord.get(i));
                if(Collections.frequency(leftWord, leftWord.get(i)) > 1) {
                    if(Collections.frequency(rightWord, rightWord.get(i)) > 1) {
                        ret ++;
                        leftWord.remove(i);
                        rightWord.remove(i);
                        i--;
                    }
                }
            }
            
            System.out.println("Case #" + k + ": " + ret);
        }
    
    }
    

}
