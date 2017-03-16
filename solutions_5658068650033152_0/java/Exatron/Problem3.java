
import java.io.*;

import java.util.*;



public class Problem3 {


    public static void main(String args[])throws Exception{

        String wd="C:\\Users\\prishriv.ORADEV\\";

        Scanner sc=new Scanner(new FileReader(wd+"input.txt"));

        PrintWriter pw=new PrintWriter(new FileWriter(wd+"output.txt"));

//      Scanner sc=new Scanner(System.in);

//      PrintWriter pw=new PrintWriter(System.out);

        int C=sc.nextInt();

        int n, m, k;

        int ans;

        for(int i=0;i<C;i++){

        n = sc.nextInt();

        m = sc.nextInt();

        k = sc.nextInt();

        	

        if (n < m){

        //swap n and m

        n = n+m;

        m = n-m;

        n = n-m;

        }

        ans = getNoOfStones(n, m, k);

        pw.println("Case #"+(i+1)+": "+ans);

        }

    pw.flush();

    pw.close();

    sc.close();

    }

    

    public static int getNoOfStones(int n, int m, int k){

    int noOfStones = 0;

    int i, j;

    int nodesCovered;

    int row, column;

    int flag=0;

    if (m <= 2 || k<=4)

    return k;

    if (k >= (m*n-4))

    return getNoOfStones(n, m)+(k-(m*n-4));

    if (n > 3 && k <= getNodesCovered(n-1, m	)){

    return getNoOfStones(Math.max(n-1, m), Math.min(n-1, m), k);

    }

    	

    int p = getNodesCovered(n-1, m);

    int pleft = k-p;

    if (Math.min(m, n-1)-2 < k-p)

    return getNoOfStones(n, m);

    else {

return getNoOfStones(n-1, m) + k-p;

}

//    	

//    for(i =1; i<= m-2; i++){

//    for (j=1; j<= n-2; j++){

//    nodesCovered = getNodesCovered(j,i);

//    if (k - nodesCovered < i+2){

//    noOfStones+= getNoOfStones(j, i);

//    noOfStones+=Math.max(k-nodesCovered, 2);

//    flag =1;

//    break;

//    }

//    }

//    if (flag == 1)

//    break;

//    }

//   return noOfStones;

    }

    

    

    public static int getNodesCovered(int n, int m){

    int noOfNodesCovered=0;

    n=n-2;

    m=m-2;

    noOfNodesCovered = n*m + 2*n +2*m;

    return noOfNodesCovered;

    }

    

    public static int getNoOfStones(int n, int m){

    int noOfStones=0;

    noOfStones = 2*(n-2) + 2*(m-2);

    return noOfStones;

    }

}