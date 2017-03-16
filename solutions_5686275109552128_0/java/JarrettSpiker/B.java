import java.util.Scanner;

/**
 * Created by jarrett on 10/04/15.
 */
public class B {
    public B() {

    }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int numCases =Integer.parseInt(in.nextLine());
        for(int i = 0; i<numCases; i++){
            int useless = Integer.parseInt(in.nextLine());
            String[] tmp = in.nextLine().split(" ");
            Integer[] diners = new Integer[tmp.length];
            int j;
            for(j=0;j<tmp.length; j++){
                diners[j] = Integer.parseInt(tmp[j]);
            }
            int tot = 0;
            int size;
            int cost = Integer.MAX_VALUE;
            int min = Integer.MAX_VALUE;
            B b = new B();
            for(j=1;j<=1000; j++){
                //we want to split all the stacks to size j
                int k;
                tot = 0;
                for(k=0;k<diners.length;k++){
                    if(diners[k] > j){
                        tot += b.downTo(diners[k], j);
                    }
                }
                if(min > tot + j){
                    size = j;
                    cost = tot;
                    min = tot + j;
                }
            }
            System.out.println("Case #" + (i+1) + ": " + min);
            /*
            B b = new B();
            int turns = b.calc(diners);
            System.out.println("Case #" + (i+1) + ": " + turns);
            */
            /*
            int turns = 0;
            boolean finish = false;
            int highest;
            int second;
            int largestCount;

            while(!finish){
                highest = 0;
                for(j=0;j<diners.length;j++){
                    if(diners[j] > highest)
                        highest = diners[j];
                }

                second = 0;
                for(j=0;j<diners.length;j++){
                    if((diners[j] > second)&&(diners[j] != highest))
                        second = diners[j];
                }
                largestCount = 0;
                for(j=0;j<diners.length;j++){
                    if(diners[j] == highest)
                        largestCount++;
                }
                if(largestCount + Math.max(second, half(highest)) < highest){
                    turns += largestCount;
                    Integer[] tmp2 = new Integer[diners.length + largestCount];
                    for(j=0;j<diners.length;j++){
                        if(diners[j] == highest)
                            tmp2[j] = half(diners[j]) ;
                        else
                            tmp2[j] = diners[j];
                    }
                    for(j=diners.length; j<tmp2.length; j++){
                        tmp2[j] = highest/2;
                    }
                    diners = tmp2;

                }
                else{
                    finish = true;
                }
            }
            highest = 0;
            for(j=0;j<diners.length;j++){
                if(diners[j] > highest)
                    highest = diners[j];
            }
            turns += highest;

            System.out.println("Case #" + (i+1) + ": " + turns);
            */
        }

    }

    public static int half(int in){
        if(in%2 == 0){
            return in/2;
        }
        else{
            return in/2 +1;
        }
    }

    public Integer calc(Integer[] diners){
        int highest = 0;
        int j;
        for(j=0;j<diners.length;j++){
            if(diners[j] > highest)
                highest = diners[j];
        }
        int largestCount = 0;
        for(j=0;j<diners.length;j++){
            if(diners[j] == highest)
                largestCount++;
        }
        if(highest == 1){
            return 1;
        }
        //turns += largestCount;
        Integer[] tmp2 = new Integer[diners.length + largestCount];
        for(j=0;j<diners.length;j++){
            if(diners[j] == highest)
                tmp2[j] = half(diners[j]) ;
            else
                tmp2[j] = diners[j];
        }
        for(j=diners.length; j<tmp2.length; j++){
            tmp2[j] = highest/2;
        }

        return Math.min(highest, calc(tmp2) + largestCount);
    }

    public int downTo(int in, int goal){
        int tmp = in;
        int steps = 0;
        while(tmp > goal){
            tmp -= goal;
            steps++;
        }
        return steps;
    }

}
