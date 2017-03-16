package com.googlerese.file;

import java.io.*;
import java.util.Map;

public class FileWrite {

    private static FileWrite fileWrite = new FileWrite();

    private FileWrite() {
    }

    public static FileWrite getInstance() {
        return fileWrite;
    }

    public final void write( final String fileName, final Map<Integer, String> output ) {
        FileWriter fstream = null;
        BufferedWriter out = null;
        try {
            // Create file 
            fstream = new FileWriter( fileName );
            out = new BufferedWriter( fstream );
            int size = output.size();
            for ( int i = 1; i <= size; i++ ) {
                final String outputStr =
                    new StringBuffer( "Case #" ).append( i ).append( ": " ).append( output.get( i ) ).toString();
                out.write( outputStr );
                if ( i != size ) {
                    out.newLine();
                }
            }

        } catch ( Exception e ) {//Catch exception if any
            System.err.println( "Error: " + e.getMessage() );
        } finally {
            //Close the output stream

            try {
                if ( out != null ) {
                    out.close();
                }
                if ( fstream != null ) {
                    fstream.close();
                }
            } catch ( IOException e ) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
}
