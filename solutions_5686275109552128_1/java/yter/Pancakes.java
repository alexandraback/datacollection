
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author yter
 */
public class Pancakes {
    public static void main( String[] args ){
        try{
            String parentDir = "e:/codejam/";
            String problemName = "B-large";
            
            Scanner sc = new Scanner(new File( parentDir + problemName + ".in") );
            FileOutputStream fos = new FileOutputStream( new File( parentDir + problemName + ".out" ) );
            BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( fos ) );
            
            int n = sc.nextInt();

            for( int i=0; i<n;i++ ){
                int nc = sc.nextInt();
                
                int arr[] = new int[nc];
                
                for ( int j=0; j<nc; j++ ){
                    arr[j] = sc.nextInt();
                }
                
                bw.write( "Case #" + (i+1) +": " + getMinT(arr) );
                if( i<n-1 )
                    bw.newLine();
            }
            
            bw.close();
        }catch( Exception ex ){
            ex.printStackTrace();
        }
        
        
    }
    
    public static long getMinT( int[] aux ){
        int maxT = getMax( aux ); 
        long min = Long.MAX_VALUE;
        
        for( int i=1; i<=maxT; i++ ){
            long s=0;
            for( int j=0; j<aux.length; j++ ){
                s+=getTPartitions( aux[j], i);
            }
            if( s+i < min ){
                min = s+i;
            }
        }
        
        return min;
    }
    
    public static long getTPartitions( long N , long p ){
        if( N<=p )
            return 0;
        
        if( N%p==0 )
            return (N/p)-1;

        return N/p;
    }
    
    public static int getMax( int[] arr ){
        int max=0;
        for( int i=0; i<arr.length; i++ ){
            if( arr[i]>max )
                max = arr[i];
        }
        
        return max;
    }
}
