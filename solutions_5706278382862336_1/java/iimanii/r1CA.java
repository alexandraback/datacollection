/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Jam2014;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek  May 11, 2014
 */
public class r1CA {
        
    static String jam = "Jam2014";
    static String round = "Round1C";
    
    static String problem = "A";
    static String inputSize = "large";
    static String attempt = "";
    
    static HashMap<String, Integer> memory = new HashMap<>();
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+""+attempt+".in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) { 
            String[] t = file.poll().split("/");
            long P = Long.parseLong(t[0]);
            long Q = Long.parseLong(t[1]);
            output.append("Case #").append(i+1).append(": ").append(solution(P, Q)).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+""+attempt+".out", output.toString());
        System.out.println(output);
    }
    
    public static String solution(long P, long Q) {
        if(P == 1 && Q == 1)
           return Integer.toString(0);
        
        int i = recurse(P, Q);
                
        return i < 0 ? "impossible" : Integer.toString(i);
    }

    private static int recurse(long P, long Q) {
        long gcd = gcd(P, Q);
        P /= gcd;
        Q /= gcd;
                
        if(P == 1 && Q == 1)
           return 0;
        
        if(Long.bitCount(Q) != 1)
           return -1;
        
        if((2 * P) / Q >= 1)
           return 1;
        
        return 1 + recurse(P*2, Q);
    }
    
    public static long gcd(long a, long b) {
        while(b != 0) {
            long c = b;
            b = a % c;
            a = c;
        }
        return a;
    }
    
    /* reads file into byte[] */
    public static byte[] getFile(String fileName) throws IOException {
        FileInputStream in = new FileInputStream(fileName);
        int size = in.available();
        byte[] imageBytes = new byte[size];

        /* read the whole image into array */
        int read = 0;
        while(read < size)
              read += in.read(imageBytes, read, size-read);
        
        return imageBytes;
    }
    
    /* mimic of php function file(fname) */
    public static Queue<String> file(String filename) throws IOException {
        byte[] fileBytes = getFile(filename);
        Queue<String> queue = new LinkedList();
        
        StringBuilder builder = new StringBuilder();
        for(int i=0; i < fileBytes.length; i++) {
            if(fileBytes[i] == '\n') {
               queue.add(builder.toString());
               builder.delete(0, builder.length());
               continue;
            } else if(fileBytes[i] == '\r')
               continue;

            builder.append((char)fileBytes[i]);
        }
        
        return queue;
    }
    
    /* write a string to file with the following name */
    public static void writeFile(String filename, String content) throws IOException {
        File outputFile = new File(filename);
        if(!outputFile.exists()) 
            outputFile.createNewFile();
        FileOutputStream output = new FileOutputStream(outputFile);
        output.write(content.getBytes());
        output.close();
    }
    
    public static void checkDir(String dirname) {
        File dir = new File(dirname);
        
        if(dir.exists())
           return;
        
        dir.mkdirs();
    }
}
