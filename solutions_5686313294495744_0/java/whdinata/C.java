import java.util.*;

public class C{
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        List<String> dict = new ArrayList<>();
        Map<String, Integer> firstWord = new HashMap<>();
        Map<String, Integer> secondWord = new HashMap<>();
        int test = in.nextInt();

        for(int i = 0; i < test; i++){
            int n = in.nextInt();
            dict.clear();
            firstWord.clear();
            secondWord.clear();
            in.nextLine();

            for(int j = 0; j < n; j++){
                String temp = in.nextLine();
                dict.add(temp);
                String s[] = temp.split(" ");

                if(firstWord.containsKey(s[0])){
                    firstWord.put(s[0], firstWord.get(s[0]) + 1);
                } else{
                    firstWord.put(s[0], 1);
                }

                if(secondWord.containsKey(s[1])){
                    secondWord.put(s[1], secondWord.get(s[1]) + 1);
                } else{
                    secondWord.put(s[1], 1);
                }
            }

            //System.out.println(firstWord);

            Set<String> keys = firstWord.keySet();
            List<String> tempList = new ArrayList<>();

            for(String word : keys){
                //System.out.println(firstWord);

                if(firstWord.get(word) == 1){
                //System.out.println(word + " " + firstWord.get(word));
                    for(int j = 0; j < dict.size(); j++){

                        String temp = dict.get(j);
                        String s[] = temp.split(" ");

                        if(s[0].equals(word)){
                            //System.out.println(temp);
                            dict.remove(j);

                            firstWord.put(s[0], firstWord.get(s[0]) - 1);
                            tempList.add(s[1]);
                        }
                    }
                }
            }

            //System.out.println(dict);

            keys = secondWord.keySet();

            for(String word : keys){
                if(secondWord.get(word) == 1){
                //System.out.println(word + " " + firstWord.get(word));
                    for(int j = 0; j < dict.size(); j++){

                        String temp = dict.get(j);
                        String s[] = temp.split(" ");

                        if(s[1].equals(word)){
                            //System.out.println(temp);
                            dict.remove(j);

                            secondWord.put(s[1], secondWord.get(s[1]) - 1);
                        }
                    }
                }
            }
            //
            // System.out.println(dict);
            //
            // for(String s : tempList){
            //     secondWord.put(s, secondWord.get(s) - 1);
            // }

            // keys = firstWord.keySet();
            // int counter = 0;
            // int max = 0;
            //
            // for(String word : keys){
            //     counter = counter + firstWord.get(word);
            //
            //     if(firstWord.get(word) > 1){
            //         counter -= 1;
            //     }
            // }

            int max = dict.size();

            // keys = secondWord.keySet();
            // counter = 0;
            //
            // for(String word : keys){
            //     counter = counter + secondWord.get(word) - 1;
            //
            //     if(secondWord.get(word) > 1){
            //         counter -= 1;
            //     }
            // }
            //
            // max = Math.max(max, counter);

            System.out.println("Case #" + (i+1) + ": " + max);
        }
    }
}
