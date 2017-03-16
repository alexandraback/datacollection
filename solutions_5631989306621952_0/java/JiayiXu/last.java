import java.util.*;
public class last{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for(int i=0;i<num;i++){
            System.out.print("Case #" + (i+1) + ": ");
            String temp = sc.next();
            ArrayList<String> ar = new ArrayList<String>();
            String a = ""+temp.charAt(0);
            ar.add(a);
            int count = 0;
            int total = 1;
            int prev = total;
            for(int j=1;j<temp.length();j++){
                int size = ar.size();
                for(int k=0;k<size;k++){
                    String tt = ar.get(k);
                    String t1 = tt+temp.charAt(j);
                    String t2 = temp.charAt(j)+tt;
                    ar.add(t1);
                    ar.add(t2);              
                }
                for(int n=0;n<size;n++){
                    ar.remove(0);
                }
            }

           
            Collections.sort(ar);
            /*for(int m=0;m<ar.size();m++){
                System.out.println(ar.get(m));
            }*/


            System.out.println(ar.get(ar.size()-1));


        }

    }


}
