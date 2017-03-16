import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

/**
 * Created by david on 4/30/16.
 */
public class B {
    public static void main(String[] args) {
        new B();
    }
    public B() {
        try {
            Scanner sc = new Scanner(System.in);
            PrintWriter pw = new PrintWriter("solution.txt", "UTF-8");

            int T = sc.nextInt();
            sc.nextLine();
            for (int i = 1; i <= T; ++i) {
                pw.print(String.format("Case #%d: ", i));
                run(sc, pw);
            }
            pw.close();
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    protected int toInt(char[] arr) {
        int base = 1;
        int sum = 0;
        for(int i = arr.length - 1; i>=0; --i) {
            sum += Character.getNumericValue(arr[i]) * base;
            base *= 10;
        }
        return sum;
    }

    protected char[] fill(char[] arr, int start, char fill) {
        char[] newArr =  arr.clone();
        for(int i = start; i < newArr.length; ++i) {
            if(arr[i] == '?')
                newArr[i] = fill;
        }
        return newArr;
    }

    protected void run(Scanner scanner, PrintWriter writer) {
        String[] line = scanner.nextLine().split(" ");
        char[] coders =  new char[line[0].length()];
        char[] jammers =  new char[line[0].length()];
        for(int i = 0; i < line[0].length();++i) {
            coders[i] = line[0].charAt(i);
            jammers[i] = line[1].charAt(i);
        }
        int start = coders.length - 1;
        for(int i = 0; i< coders.length; ++i) {
            if(coders[i] != '0' || jammers[i] != '0') {
                start = i;
                break;
            }
        }
        boolean last = false;
        char[] coders2 =  coders.clone();
        char[] jammers2 =  jammers.clone();

        int difference = Integer.MAX_VALUE;
        char[] coders3 = new char[line[0].length()];
        char[] jammers3 = new char[line[0].length()];
        for(; start < coders.length; ++start) {
            if(coders[start] == '?' && jammers[start] == '?') {

                coders[start] = jammers[start] = '0';
                last = true;

                jammers3 = jammers.clone();
                jammers3[start] =  '0';
                jammers3 = fill(jammers3, start+1, '9');
                coders3 = coders.clone();
                coders3[start] = '1';
                coders3 = fill(coders3, start+1, '0');
                int newDifference = toInt(coders3) - toInt(jammers3);
                if(newDifference < difference
                        || (newDifference == difference
                        && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                        ) {
                    jammers2 = jammers3;
                    coders2 = coders3;
                    difference = newDifference;
                }
                jammers3 = jammers.clone();
                jammers3[start] =  '1';
                jammers3 = fill(jammers3, start+1, '0');
                coders3 = coders.clone();
                coders3[start] = '0';
                coders3 = fill(coders3, start+1, '9');
                newDifference = toInt(jammers3) - toInt(coders3);
                if(newDifference < difference
                        || (newDifference == difference
                        && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                        ) {
                    jammers2 = jammers3;
                    coders2 = coders3;
                    difference = newDifference;
                }
            } else if (coders[start] == jammers[start]) {
                last = false;
            } else if(coders[start] == '?' || jammers[start] == '?') {
                last = false;
                if(coders[start] == '?') {
                    if(jammers[start] != '0') {
                        jammers3 = fill(jammers, start+1, '0');
                        coders3 = coders.clone();
                        coders3[start] = Integer.toString(Character.getNumericValue(jammers3[start]) -1).charAt(0);
                        coders3 = fill(coders3, start+1, '9');
                        int newDifference = toInt(jammers3) - toInt(coders3);
                        if(newDifference < difference
                                || (newDifference == difference
                                && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                                ) {
                            jammers2 = jammers3;
                            coders2 = coders3;
                            difference = newDifference;
                        }
                    }
                    if(jammers[start] != '9') {
                        jammers3 = fill(jammers, start+1, '9');
                        coders3 = coders.clone();
                        coders3[start] = Integer.toString(Character.getNumericValue(jammers3[start]) +1).charAt(0);
                        coders3 = fill(coders3, start+1, '0');
                        int newDifference = toInt(coders3) - toInt(jammers3);
                        if(newDifference < difference
                                || (newDifference == difference
                                && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                                ){
                            jammers2 = jammers3;
                            coders2 = coders3;
                            difference = newDifference;
                        }
                    }
                    coders[start] = jammers[start];
                } else {
                    if(coders[start] != '9') {
                        coders3 = fill(coders, start+1, '9');
                        jammers3 = jammers.clone();
                        jammers3[start] = Integer.toString(Character.getNumericValue(coders3[start]) +1).charAt(0);
                        jammers3 = fill(jammers3, start+1, '0');
                        int newDifference = toInt(jammers3) - toInt(coders3);
                        if(newDifference < difference
                                || (newDifference == difference
                                && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                                ) {
                            jammers2 = jammers3;
                            coders2 = coders3;
                            difference = newDifference;
                        }
                    }
                    if(coders[start] != '0') {
                        coders3 = fill(coders, start+1, '0');
                        jammers3 = jammers.clone();
                        jammers3[start] = Integer.toString(Character.getNumericValue(coders3[start]) -1).charAt(0);
                        jammers3 = fill(jammers3, start+1, '9');
                        int newDifference = toInt(coders3) - toInt(jammers3);
                        if(newDifference < difference
                                || (newDifference == difference
                                && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                        ){
                            jammers2 = jammers3;
                            coders2 = coders3;
                            difference = newDifference;
                        }
                    }

                    jammers[start] = coders[start];
                }
            } else {
                if(last) {
                    jammers3 =  jammers.clone();
                    coders3 = coders.clone();
                    coders3[start-1] = '1';
                    coders3 = fill(coders3, start, '0');
                    jammers3 = fill(jammers3, start, '9');
                    int newDifference = toInt(coders3) - toInt(jammers3);
                    if(newDifference < difference
                            || (newDifference == difference
                            && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                            ){
                        jammers2 = jammers3;
                        coders2 = coders3;
                        difference = newDifference;
                    }

                    jammers3 =  jammers.clone();
                    coders3 = coders.clone();
                    jammers3[start-1] = '1';
                    coders3 = fill(coders3, start, '9');
                    jammers3 = fill(jammers3, start, '0');
                    newDifference = toInt(jammers3) - toInt(coders3);
                    if(newDifference < difference
                            || (newDifference == difference
                            && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                            ) {
                        jammers2 = jammers3;
                        coders2 = coders3;
                        difference = newDifference;
                    }


                }
                break;
            }
        }

        jammers3 =  jammers.clone();
        coders3 = coders.clone();
        coders3 = fill(coders3, start, '0');
        jammers3 = fill(jammers3, start, '9');
        int newDifference = Math.abs(toInt(coders3) - toInt(jammers3));
        if(newDifference < difference
                || (newDifference == difference
                && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                ){
            jammers2 = jammers3;
            coders2 = coders3;
            difference = newDifference;
        }

        jammers3 =  jammers.clone();
        coders3 = coders.clone();
        coders3 = fill(coders3, start, '9');
        jammers3 = fill(jammers3, start, '0');
        newDifference = Math.abs(toInt(jammers3) - toInt(coders3));
        if(newDifference < difference
                || (newDifference == difference
                && (toInt(coders2) > toInt(coders3) ||(toInt(coders2)  ==  toInt(coders3) && toInt(jammers2) > toInt(jammers3))))
                ){
            jammers2 = jammers3;
            coders2 = coders3;
            difference = newDifference;
        }

        writer.println(String.format("%0"+ coders.length +"d %0"+ coders.length +"d", toInt(coders2), toInt(jammers2)));
    }
}
