/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ronda1A2012;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 *
 * @author G
 */
public class B {
    static File input=new File("B-large.in");
    public static void main(String...args)throws Exception{
        System.setOut(new PrintStream("B.out"));
        BufferedReader br=new BufferedReader(new FileReader(input));
        int T=Integer.parseInt(br.readLine());
        for(int caso=1;caso<=T;caso++){
            int N=Integer.parseInt(br.readLine());
            Level[] niveles1=new Level[N],niveles2=new Level[N];
            for(int e=0;e<N;e++)niveles2[e]=niveles1[e]=new Level(br.readLine().split(" +"));
            Arrays.sort(niveles1,new Comparator<Level>() {public int compare(Level o1, Level o2) {return o1.req1-o2.req1;}});
            Arrays.sort(niveles2,new Comparator<Level>() {public int compare(Level o1, Level o2) {return o1.req2-o2.req2;}});
            PriorityQueue<Level> cola1=new PriorityQueue<Level>(10,new Comparator<Level>(){
                public int compare(Level o1, Level o2) {
                    return o2.req2-o1.req2;
                }
            });
            PriorityQueue<Level> cola2=new PriorityQueue<Level>(10,new Comparator<Level>(){
                public int compare(Level o1, Level o2) {
                    return o2.req1-o1.req1;
                }
            });
            int stars=0;
            int t=0,t2=0;
            while(true){
                while(t<N&&niveles1[t].req1<=stars)cola1.add(niveles1[t++]);
                while(t2<N&&niveles2[t2].req2<=stars)cola2.add(niveles2[t2++]);
                if(cola1.isEmpty()&&cola2.isEmpty())break;
                if(cola2.isEmpty()){
                    stars+=cola1.poll().usar1();
                }else{
                    while(!cola2.isEmpty())stars+=cola2.poll().usar2();
                }
            }
            System.out.print("Case #"+caso+": ");
            if(stars!=2*N){
                System.out.println("Too Bad");
            }else{
                int pasos=N;
                for(Level l:niveles1){
                    if(l.usado1)pasos++;
                }
                System.out.println(pasos);
            }
        }
        System.out.flush();
        System.out.close();
    }

    static class Level{
        int req1,req2;
        boolean usado1,usado2;
        public Level(int req1, int req2) {
            this.req1 = req1;
            this.req2 = req2;
        }
        public Level(String[] j){
            this(Integer.parseInt(j[0]),Integer.parseInt(j[1]));
        }
        public int usar1(){
            if(usado1||usado2)return 0;
            usado1=true;
            return 1;
        }
        public int usar2(){
            if(usado1)return 1;
            if(usado2)return 0;
            usado2=true;
            return 2;
        }
    }
}
