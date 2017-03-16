
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author yter
 */
public class dijkstra {
    public static Map<String,String> mapData = new HashMap<String,String>();
    
    public static void main( String[] args ){
        mapData.put("11", "1");
        mapData.put("1i", "i");
        mapData.put("1j", "j");
        mapData.put("1k", "k");
        
        mapData.put("i1", "i");
        mapData.put("ii", "-1");
        mapData.put("ij", "k");
        mapData.put("ik", "-j");
        
        mapData.put("j1", "j");
        mapData.put("ji", "-k");
        mapData.put("jj", "-1");
        mapData.put("jk", "i");
        
        mapData.put("k1", "k");
        mapData.put("ki", "j");
        mapData.put("kj", "-i");
        mapData.put("kk", "-1");
        
        try{
            String parentDir = "e:/codejam/";
            String problemName = "C-small-attempt6";
            
            Scanner sc = new Scanner(new File( parentDir + problemName + ".in") );
            FileOutputStream fos = new FileOutputStream( new File( parentDir + problemName + ".out" ) );
            BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( fos ) );
            
            //genAllCombinations();
            //checkMul();
            
            int n = sc.nextInt();

            for( int i=0; i<n;i++ ){
                int a = sc.nextInt();
                int b= sc.nextInt();
                
                String c = sc.next();
                
                String test="";
                for( int z=0;z<b;z++ ){
                        test += c;
                }
                
               
                bw.write( "Case #" + (i+1) +": " + ( checkCad(test )  ? "YES" : "NO" ) );
                if( i<n-1 )
                    bw.newLine();
                System.out.println(""+i);
            }
            
            bw.close();
        }catch( Exception ex ){
            ex.printStackTrace();
        }
        
    }
    
    public static boolean checkCadKK_II( String target ){
        for( int i=1;i<target.length();i++ ){
            String a = target.substring(0,i);
            String b = target.substring(i);
            
            if(  mullAll(a).equals("i") && mullAll(b).equals("i") ){
                return true;
            }
            
            if(  mullAll(a).equals("k") && mullAll(b).equals("k") ){
                return true;
            }
        }
        return false;
    }
    
   
    
    public static String mul2( String a , String b ){
        int s = 0;
        
        if( a.equals("-1") )
            return "-" + b;
            
        if( a.contains("-") )
            s++;
        
        if( b.contains("-") )
            s++;
        
        a = a.replaceAll("\\-", "");
        b = b.replaceAll("\\-", "");
        
        String res="";
        if( mapData.containsKey(a+b) ){
            res = mapData.get(a+b);
        }else{
            int h=0;
        }
                
        
        if( s==1 ){
            if( res.contains("-") ){
                res = res.replaceAll("\\-", "");
            }else{
                res = "-" + res;
            }
        }
        return res;
    }
    
  
    
    public static void genAllCombinations(){
        Map<String,String> auxMap = new HashMap<String,String>();
        auxMap.put( "i", "jk" );
        auxMap.put( "j" , "ki" );
        auxMap.put( "k", "ij" );
        
        Set<String> s = new HashSet<String>();
        
        for( int z=0; z<1000; z++ ){
            String aux = "ijk";
            for(int i=0; i<200; i++ ){
                int pose = 0;
                String res = aux.substring( 0 , pose ) + auxMap.get(""+aux.charAt(pose)) + aux.substring(pose+1);
                aux = res;
                if( i>9  ){
                    checkCad( res );
                }
            }
        }
        
        
    }
    
    public static String mullAll( String cad ){
        String res = "" + cad.charAt(0);
        
        for( int i=1; i<cad.length(); i++ ){
            res = mul2( res , "" + cad.charAt(i) );
        }
        
        return res;
    }
    
    public static  boolean checkEasyCases( String target ){
        if(target.length()<3)
            return false;   
        if( !mullAll(target).equals("-1") ){
            return false;
        }
        if( target.replaceAll("i", "").equals("") ){
            return false;
        }
        if( target.replaceAll("j", "").equals("") ){
            return false;
        }
        if( target.replaceAll("k", "").equals("") ){
            return false;
        }
        
        return true;
    }
        
    public static void checkMul(){
        String aux = "ij";
        String aux2 = new StringBuilder(aux).reverse().toString();
        System.out.println( mullAll(aux) );
        System.out.println( mullAll(aux2) );
        int j=0;
    }
    
    public static boolean checkCad( String target ){
        if( !checkEasyCases( target ) ){
            return false;
        }
        
        if(target.length()==3  ){
            if( target.equals("ijk") )
                return true;
        }
        
        return checkCadRec(target, "i", "i");
    }
    
    public static boolean checkCadRec( String target , String pt1 , String pt2 ){
        String res = "" + target.charAt(0);
        String flagTest=res;
        
        int minus = pt2.equals("k") ? 1:2;
        
        for( int i=0; i<target.length()-minus; i++ ){
            if( res.equals( pt1 ) ){
                String p2 = target.substring(i+1);
                if( p2.length()<2 ){
                    return false;
                }
                if( mullAll(p2).equals( pt2 ) ){
                    if( pt2.equals("k") ){
                        return true;
                    }
                    
                    if( checkCadRec( p2 , "j" , "k" ) ){
                        return true;
                    }
                    
                    return false;
                }
            }
            String sig = "" + target.charAt(i+1);
            flagTest += sig;
            res = mul2( res , sig );
        }
        
        return false;
    }
}
