

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
            String problemName = "D-large";
            
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
        
        if( X<3 ){
            return false;
        }
        
        int maxc = X%2 != 0 ? (X/2) + 1 : X/2;
        
        for( int i=X; ; i-- ){
            int a = i;
            int b = X-i+1;
            
            if( a<1||b<1){
                break;
            }
            
            if( a*b > R*C ){
                return true;
            }
            
            if( !( ( R>=a && C>=b ) || ( R>=b && C>=a ) ) ){
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
        
        
        if( X>2*(R+C-2) && X<R*C ){
            return true;
        }
            
        if( X>=6 ){
            return true;
        }
        
        if( ( R==2 || C==2 ) && X==4 ){
            return true;
        }
        
        return false;
    }
    
   
    
    public static void test(){
        existsBadFig(1, 6, 3);
        int maxo=21;
        int h=1;
        for( int i=1; i<maxo; i++ ){
            for( int j=i; j<maxo; j++ ){
                int m = i*j;   
                for( int z=2; z<=m; z++ ){
                    if( !existsBadFig( i , j , z ) ){
                        if( z!=2 )
                            System.out.println(""+ h++ + ".-" + i+"x"+j+"->"+z);
                    }
                }
            }
        }
    }
    
    
}
