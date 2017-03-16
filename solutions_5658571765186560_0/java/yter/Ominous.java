

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
public class Ominous {
    public static void main( String[] args ){
        try{
            //test();
            //if( 1==1 ) return;
            
            String parentDir = "e:/codejam/";
            String problemName = "D-small-attempt1";
            
            Scanner sc = new Scanner(new File( parentDir + problemName + ".in") );
            FileOutputStream fos = new FileOutputStream( new File( parentDir + problemName + ".out" ) );
            BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( fos ) );
            
            int n = sc.nextInt();

            for( int i=0; i<n;i++ ){
                int x = sc.nextInt();
                int r = sc.nextInt();
                int c = sc.nextInt();
                
                bw.write( "Case #" + (i+1) +": " + ( existsBadFig(r, c , x) ? "RICHARD" : "GABRIEL" ) );
                if( i<n-1 )
                    bw.newLine();
            }
            
            bw.close();
        }catch( Exception ex ){
            ex.printStackTrace();
        }
    }
    
    public static boolean existsBadFig( int R, int C , int X ){
        
        if( R*C%X==0 ){
            if( X>R && X>C ){
                return true;
            }
        }else{
            return true;
        }
        
        int maxc = X%2 != 0 ? (X/2) + 1 : X/2;
        
        for( int i=X; ; i-- ){
            int a = i;
            int b = X-i+1;
            
            if( a*b > R*C ){
                return true;
            }
            
            if( b>maxc ){
                break;
            }
            
        } 
        
      
                
        if( X==4 && R==2 && C==4 ){
            return true;
        }
        
        if( X==4 && R==4 && C==2 ){
            return true;
        }
        return false;
    }
    
   
    
    public static void test(){
        existsBadFig(1, 4, 4);
        for( int i=1; i<5; i++ ){
            for( int j=i; j<5; j++ ){
                int m = i*j;
                
                for( int z=2; z<=m; z++ ){
                    if( !existsBadFig( i , j , z ) ){
                        System.out.println(""+i+"x"+j+"="+z);
                    }
                }
            }
        }
    }
    
    
}
