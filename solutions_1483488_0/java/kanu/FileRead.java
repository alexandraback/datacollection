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

    public Map<Integer, String[]> read( final String fileName ) {
        FileInputStream fstream = null;
        DataInputStream in = null;
        BufferedReader br = null;
        Map<Integer, String[]> input = null;
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
                    input = new HashMap<Integer, String[]>( Integer.parseInt( strLine ) );
                } else {
                    System.out.println( count + " : " + strLine );
                    String[] arr = strLine.split( "\\s+" );
                    input.put( count, arr );
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
