import java.util.*;

public class A{
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        int test = in.nextInt();

        for(int i = 0; i < test; i++){
            String temp = in.next();
            int length = temp.length();
            int c[] = new int[26];
            int digits[] = new int[10];
            int counter = 0;

            for(int j = 0; j < length; j++){
                c[temp.charAt(j) - 'A']++;
                counter++;
            }

            while(counter > 0){
                if(c['U'-'A'] > 0){
                    digits[4]++;
                    c['F'-'A']--;
                    c['O'-'A']--;
                    c['U'-'A']--;
                    c['R'-'A']--;
                    counter-=4;
                } else if(c['Z' - 'A'] > 0){
                    digits[0]++;
                    c['Z'-'A']--;
                    c['E'-'A']--;
                    c['R'-'A']--;
                    c['O'-'A']--;
                    counter-=4;
                } else if(c['G' - 'A'] > 0){
                    digits[8]++;
                    c['E'-'A']--;
                    c['I'-'A']--;
                    c['G'-'A']--;
                    c['H'-'A']--;
                    c['T'-'A']--;
                    counter-=5;
                } else if(c['X' - 'A'] > 0){
                    digits[6]++;
                    c['S'-'A']--;
                    c['I'-'A']--;
                    c['X'-'A']--;
                    counter-=3;
                } else if(c['W' - 'A'] > 0){
                    digits[2]++;
                    c['T'-'A']--;
                    c['W'-'A']--;
                    c['O'-'A']--;
                    counter-=3;
                } else if(c['F' - 'A'] > 0){
                    digits[5]++;
                    c['F'-'A']--;
                    c['I'-'A']--;
                    c['V'-'A']--;
                    c['E'-'A']--;
                    counter-=4;
                } else if(c['S' - 'A'] > 0){
                    digits[7]++;
                    c['S'-'A']--;
                    c['E'-'A']--;
                    c['V'-'A']--;
                    c['E'-'A']--;
                    c['N'-'A']--;
                    counter-=5;
                } else{
                    if(c['I' - 'A'] > 0){
                        digits[9]++;
                        c['N'-'A']--;
                        c['I'-'A']--;
                        c['N'-'A']--;
                        c['E'-'A']--;
                        counter-=4;
                    } else if(c['O' - 'A'] > 0){
                        digits[1]++;
                        c['O'-'A']--;
                        c['N'-'A']--;
                        c['E'-'A']--;
                        counter-=3;
                    } else{
                        digits[3]++;
                        c['T'-'A']--;
                        c['H'-'A']--;
                        c['R'-'A']--;
                        c['E'-'A']--;
                        c['E'-'A']--;
                        counter-=5;
                    }
                }
            }


            System.out.print("Case #" + (i+1) + ": ");
            for(int j = 0; j < 10; j++){
                while(digits[j] > 0){
                    System.out.print(j);
                    digits[j]--;
                }
            }

            System.out.println();
        }
    }
}
