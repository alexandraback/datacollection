package magictrick;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemC {

    public static int N;

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File("problemD.in");
        File f2 = new File("ProblemDSolve.out");
        Scanner sc = new Scanner(f);
        FileWriter fw = new FileWriter(f2);

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            N = sc.nextInt();

            double[] naomiArr = new double[N];
            double[] kenArr = new double[N];

            for (int j = 0; j < N; j++) {
                naomiArr[j] = sc.nextDouble();
            }
            for (int j = 0; j < N; j++) {
                kenArr[j] = sc.nextDouble();
            }

            MyArray naomi = new MyArray(N);
            naomi.setArray(naomiArr);
            naomi.sort();

            MyArray ken = new MyArray(N);
            ken.setArray(kenArr);
            ken.sort();

            int war = playWar(naomi, ken);
            
            naomi.reset();
            ken.reset();

            int dwar = playDWar(naomi, ken);

            fw.append("Case #" + (i + 1) + ": " + dwar + " " + war);

            if (i < T - 1) {
                fw.append("\n");
            }
        }
        fw.close();
    }

    public static int playWar(MyArray naomi, MyArray ken) {
        int points = 0;
        for (int i = 0; i < N; i++) {
            double f = naomi.popFirst();
            int biggerIdx = ken.firstBiggerIdx(f);
            if(biggerIdx != -1){
                ken.removeAt(biggerIdx);
            }else{
                ken.popFirst();
                points++;
            }
        }
        return points;
    }

    public static int playDWar(MyArray naomi, MyArray ken) {
        int points = 0;
        for (int i = 0; i < N; i++) {
            double f = ken.popFirst();
            int biggerIdx = naomi.firstBiggerIdx(f);
            if(biggerIdx != -1){
                naomi.removeAt(biggerIdx);
                points++;
            }else{
                naomi.popFirst();
            }
        }
        return points;
    }
}

class MyArray{

    private int first;
    private int last;
    private double[] array;
    private boolean isSorted;

    public MyArray(int size) {
        array = new double[size];
        first = 0;
        last = size - 1;
        isSorted = false;
    }

    public void sort() {
        if (!isSorted) {
            Arrays.sort(array);
        }
        isSorted = true;
    }

    public void setArray(double[] array) {
        this.array = array;
    }

    public double peekFirst() {
        return array[first];
    }

    public double peekLast() {
        return array[last];
    }

    public double popFirst() {
        return array[first++];
    }

    public double popLast() {
        return array[last--];
    }

    public double at(int idx) {
        idx += first;
        if (idx >= first && idx <= last) {
            return array[idx];
        }
        return -1;
    }

    public int firstBiggerIdx(double biggerThan) {
        sort();
        return qs(biggerThan, first, last + 1, true);
    }

    public int firstSmallerIdx(double smallerThan) {
        sort();
        return qs(smallerThan, first, last + 1, false);
    }

    private int qs(double num, int startIdx, int endIdx, boolean bigger) {
        int best = -1;
        while (endIdx > startIdx) {
            int testpos = ((endIdx + startIdx) / 2);

            if (array[testpos] > num) {
                if (bigger) {
                    best = testpos;
                }
                endIdx = testpos;
            } else if(array[testpos] < num){
                if (!bigger) {
                    best = testpos;
                }
                startIdx = testpos + 1;
            }else{
                endIdx--;
            }
        }
        return best;
    }
    
    public void removeAt(int idx){
        if(at(idx) != -1){
            idx += first;
            array[idx] *= 100000;
            isSorted = false;
            sort();
            last--;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{");
        for (int i = first; i < last; i++) {
            sb.append(array[i]);
            sb.append(", ");
        }
        sb.append(array[last]);
        sb.append("}");
        return sb.toString();
    }
    
    public void reset(){
        first = 0;
        last = array.length - 1;
        for (int i = 0; i < array.length; i++) {
            if(array[i] > 1){
                array[i] /= 100000;
            }
        }
        sort();
    }
}
