package gcj2016.round1B;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Technobabble {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt(); 
        for (int i = 1; i <= t; ++i) {
            int n = in.nextInt();
            String[] topics = new String[n];
            for (int j=0; j<n; ++j){
                String first = in.next();
                String second = in.next();
                topics[j] = first+" "+second;
            }
            int ans = f(topics, n);
            System.out.println("Case #" + i + ": " + ans);
        }
        in.close();
    }
    
    public static int f(String[] topics, int n){
        int pow = (int) Math.pow(2, n);
        int max = 0;
        for (int i=0; i<pow; ++i){
            boolean[] fakes = new boolean[n];
            int temp = i;
            for (int j=0; j<n; ++j){
                fakes[j] = temp%2==1;
                temp /=2;
            }
            int count = 0;
            for (int j=0; j<n; ++j){
                if (fakes[j]){
                    if (couldBeFake(topics,fakes,topics[j])){
                        ++count;
                    }
                }
            }
            if (count>max) max = count;
        }
        return max;
    }
    
    public static boolean couldBeFake(String[] topics, boolean[] fakes, String topic){
        boolean[] found = {false,false};
        String[] ts = topic.split(" ");
        for (int i=0; i<topics.length; ++i){
            if (!fakes[i]){
                String[] td = topics[i].split(" ");
                if (ts[0].compareTo(td[0])==0) found[0] = true;
                if (ts[1].compareTo(td[1])==0) found[1] = true;
            }
        }
        return found[0]&&found[1];
    }
    /*
    public static int f(ArrayList<String> topicsLeft, ArrayList<String> topicsDone, int n, int a){
        if (n==0) return a;
        int max = 0;
        for (int i=0; i<n; ++i){
            String topic = topicsLeft.get(i);
            ArrayList<String> cl = (ArrayList<String>)topicsLeft.clone(),
                    cl2 = (ArrayList<String>)topicsDone.clone();
            cl.remove(i);
            cl2.add(topic);
            int r = f(cl,cl2,n-1, a+(couldBeFake(topicsDone,topic) ? 1 : 0));
            if (r>max) max = r;
        }
        return max;
    }
    
    public static boolean couldBeFake(ArrayList<String> topics, String topic){
        boolean[] done = {false,false};
        String[] ts = topic.split(" ");
        for (int i=0; i<topics.size(); ++i){
            String[] td = topics.get(i).split(" ");
            if (ts[0].compareTo(td[0])==0)done[0] = true;
            if (ts[1].compareTo(td[1])==0)done[1] = true;
        }
        return (done[0]&&done[1]);
    }
    */
}