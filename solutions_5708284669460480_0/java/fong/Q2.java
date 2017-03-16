import java.util.Scanner;

/**
 * Created by wing on 5/10/15.
 */
public class Q2 {

    public static double ignore = 0.000001;
    public static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {

        int numInputs = input.nextInt();
        for(int i = 0; i<numInputs;i++){
            int lengthKb = input.nextInt();
            int lengthK = input.nextInt();
            int times = input.nextInt();
            String keyboard = input.next();
            String key = input.next();
            double bananaGiving = bananaGive(keyboard,key, times);
            System.out.println("Case #"+(i+1)+": "+String.format("%.7f",bananaGiving));
        }
    }

    public static double bananaBring(String keyboard, String key, int times){
        if(!isExist(keyboard, key))
            return 0;
        else {
            String reducedString = reduced(key);
            int numBanana = times/key.length();
            return numBanana;
        }
    }

    public static double bananaGive(String keyboard, String key, int times){
        double bananaGive = bananaBring(keyboard,key, times);
        double prob = 1;
        for(int i = 0; i<key.length();i++){
            prob *= getProb(keyboard, key.charAt(i));
        }
        if(prob<ignore){
            prob=0;
        }
        return bananaGive*(1-prob);
    }

    public static boolean isExist(String keyboard, String key){
        char[] charatKey = key.toCharArray();
        for(int i = 0; i <charatKey.length;i++){
            if(keyboard.indexOf(charatKey[i])==-1){
                return false;
            }
        }
        return true;
    }

    private static String reduced(String word) {

        String result = new String("");

        for (int i = 0; i < word.length(); i++) {
            if (!result.contains("" + word.charAt(i))) {
                result += "" + word.charAt(i);
            }
        }

        return result;
    }

    public static double getProb(String keyboard,char a){
        int b = 0;
        for (int i = 0; i<keyboard.length();i++){
            if(keyboard.charAt(i)==a){
                b++;
            }
        }

        return (double)b/keyboard.length();
    }

}
