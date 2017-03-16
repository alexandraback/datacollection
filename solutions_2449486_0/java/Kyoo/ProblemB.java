

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Set;
import java.util.TreeSet;

/**
 *
 * @author Kyoo
 */
public class ProblemB {
    public static void main(String[] args) throws IOException{
        BufferedReader leer= new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(leer.readLine());
        for (int i = 1; i <= T; i++) {
            System.out.print("Case #"+i+": ");
            int[][] lawn=leerLawn(leer);
            LinkedList<Integer> heights= obtenerHeights(lawn);
            if(resolver(lawn,heights))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }

    private static int[][] leerLawn(BufferedReader leer) throws IOException {
        String[] linea=leer.readLine().trim().split(" ");
        int N=Integer.parseInt(linea[0]);
        int M=Integer.parseInt(linea[1]);
        int[][] lawn= new int[N][M];
        for (int i = 0; i < N; i++){
            linea=leer.readLine().trim().split(" ");
            for (int j = 0; j < M; j++)
                lawn[i][j]=Integer.parseInt(linea[j]);
        }
        return lawn;
    }

    private static LinkedList<Integer> obtenerHeights(int[][] lawn) {
        Set<Integer> heights= new TreeSet<>();
        for (int i = 0; i < lawn.length; i++)
            for (int j = 0; j < lawn[i].length; j++)
                heights.add(lawn[i][j]);
        return new LinkedList<>(heights);
    }

    private static boolean resolver(int[][] lawn, LinkedList<Integer> heights) {
        
        int[][] lawnTemp=new int[lawn.length][];
        for (int i = 0; i < lawn.length; i++)
            lawnTemp[i]=Arrays.copyOf(lawn[i], lawn[i].length);
        do{
            int x=heights.poll();
            int y=heights.isEmpty()?x+1:heights.peek();
//            System.out.println(heights+" "+x+" "+y);
//            for (int i = 0; i < lawn.length; i++) 
//                System.out.println(Arrays.toString(lawn[i]));
//            System.out.println("----");
            for (int i = 0; i < lawn.length; i++)
                for (int j = 0; j < lawn[i].length; j++)
                    if(lawn[i][j]==x){
                        if(i==0){
                            boolean iguales=true;
                            for (int k = 0; k < lawn.length; k++)
                                if(lawn[k][j]!=x)
                                    iguales=false;
                            if(iguales)
                                for (int k = 0; k < lawn.length; k++)
                                    lawnTemp[k][j]=y;
                        }
                        if(j==0){
                            boolean iguales=true;
                            for (int k = 0; k < lawn[i].length; k++)
                                if(lawn[i][k]!=x)
                                    iguales=false;
                            if(iguales)
                                for (int k = 0; k < lawn[i].length; k++)
                                    lawnTemp[i][k]=y;
                        }
                    }
//            for (int i = 0; i < lawn.length; i++) 
//                System.out.println(Arrays.toString(lawnTemp[i]));
            for (int i = 0; i < lawn.length; i++)
                for (int j = 0; j < lawn[i].length; j++){
                    lawn[i][j]=lawnTemp[i][j];
                    if(lawnTemp[i][j]==x) return false;
                }
            
        }while(!heights.isEmpty());
        return true;
    }
}