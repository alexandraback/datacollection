package com.googlerese.file;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class FileRead {

    private static FileRead instance = new FileRead();

    private FileRead() {
    }

    public static FileRead getInstance() {
        return instance;
    }

    public Map<Integer, GooglersBean> read( final String fileName ) {
        FileInputStream fstream = null;
        DataInputStream in = null;
        BufferedReader br = null;
        Map<Integer, GooglersBean> input = null;
        try {
            // Open the file that is the first 
            // command line parameter
            fstream = new FileInputStream( fileName );
            // Get the object of DataInputStream
            in = new DataInputStream( fstream );
            br = new BufferedReader( new InputStreamReader( in ) );
            String strLine;
            //Read File Line By Line
            int count = 0;
            while ( ( strLine = br.readLine() ) != null ) {
                // Print the content on the console
                if ( count == 0 ) {
                    input = new HashMap<Integer, GooglersBean>( Integer.parseInt( strLine ) );
                } else {
                    System.out.println( count + " : " + strLine );
                    GooglersBean bean = new GooglersBean();
                    String[] arr = strLine.split( "\\s+" );
                    bean.setNumGooglers( Integer.parseInt( arr[0] ) );
                    bean.setSurprising( Integer.parseInt( arr[1] ) );
                    bean.setResult( Integer.parseInt( arr[2] ) );
                    for ( int i = 3; i < arr.length; i++ ) {
                        bean.addScore( ( i - 3 ), Integer.parseInt( arr[i] ) );
                    }
                    input.put( count, bean );
                }
                count++;
            }
        } catch ( Exception e ) {//Catch exception if any
            System.err.println( "Error: " + e.getMessage() );
        } finally {
            //Close the input stream
            try {
                if ( br != null ) {
                    br.close();
                }
                if ( in != null ) {
                    in.close();
                }
                if ( fstream != null ) {
                    fstream.close();
                }
            } catch ( IOException e ) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        return input;
    }
}
