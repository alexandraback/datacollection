package gcjpractice;

import java.util.HashSet;
import java.util.Scanner;

/**
 * FileName:     ReorderingTrainCars1.java
 * @Description: 
 *
 * @author Xunhu(Tiger) Sun
 *         email: sunx2013@my.fit.edu
 * @date May 11, 2014 6:15:58 AM 
 */
public class ReorderingTrainCars1 {
    final Scanner sc = new Scanner(System.in);

    void read () {
        n = sc.nextInt();
        sc.nextLine();
        str = sc.nextLine().split(" ");
        assert str.length == n;
    }

    int n;
    String[] str ;
    int arry[];
    
    void solve () {
        arry = new int[n];
        for (int i = 0; i < n; i++){
            arry[i] = i;
        }
        int count =0;
        do{
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++){
                sb.append(str[arry[i]]);
            }
            if (check(sb.toString())){
                count++;
            }
        }while(this.next());
        System.out.println(count);
    }

    private boolean check (String string) {
        HashSet<Character> table = new HashSet<Character>();
        char cur = 0;
        for (int i = 0; i < string.length(); i++){
            char c = string.charAt(i);
            if (c != cur){
                cur = c;
                if (table.contains(c)){
                    return false;
                } else {
                    table.add(c);
                }
            }
        }
        return true;
    }

    void run () {
        final int cn = sc.nextInt();
        sc.nextLine();
        for (int ci = 1; ci <= cn; ci++) {
            read();
            System.out.printf("Case #%d: ", ci);
            solve();
        }
    }

    
    private boolean next(){
        int pos1=-1;
        int pos2=-1;
        for(int i=arry.length-1;i>0;i--){
            if(arry[i-1]<arry[i]){
                pos1=i-1;
                break;
            }
        }
        if(pos1<0){
            return false;
        }
        
        for(int i=arry.length-1;i>pos1;i--){
            if(arry[i]>arry[pos1]){
                pos2=i;
                swap(pos2,pos1);
                reserve(pos1+1,arry.length-1);
                break;
            }
        }
        if(pos2<0){
            return false;
        }
        return true;
    }

    private void reserve(int i, int j) {
        for(;i<=j;i++,j--){
            swap(i,j);
        }
    }

    private void swap(int pos2, int pos1) {
        int temp=arry[pos1];
        arry[pos1]=arry[pos2];
        arry[pos2]=temp;
    }
    
    public static void main (String[] args) {
        new ReorderingTrainCars1().run();
    }
}
