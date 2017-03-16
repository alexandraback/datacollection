
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
public class Ovation {
    public static void main(String[] a){
        try{
            String parentDir = "e:/codejam/";
            Scanner sc = new Scanner(new File( parentDir + "A-small-attempt2.in"));
            FileOutputStream fos = new FileOutputStream( new File( parentDir + "output.out" ) );
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));
            
            int n = sc.nextInt();

            for( int i=0; i<n;i++ ){
                int sh = sc.nextInt();
                bw.write( "Case #" + (i+1) +": " + getMinGuest( sc.next() ) );
                if( i<n-1 )
                    bw.newLine();
            }
            
            bw.close();
        }catch( Exception ex ){
            ex.printStackTrace();
        }
    }
    
    public static long getMinGuest( String cad ){
        long s=0,add=0;
        for(int i=0;i<cad.length();i++){
            int c = Integer.parseInt( "" + cad.charAt(i) );
            if( s>=i || c==0 ){
                s+=c;
            }else{
                long dif = i-s;
                add+=dif;
                s+=dif;
                s+=c;
            }
        }
        return add;
    }
}
