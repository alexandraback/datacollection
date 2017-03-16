/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Jam2014;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek  May 11, 2014
 */
public class r1CB {
        
    static String jam = "Jam2014";
    static String round = "Round1C";
    
    static String problem = "B";
    static String inputSize = "small";
    static String attempt = "attempt0";
    
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-"+attempt+".in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) { 
            int N = Integer.parseInt(file.poll());
            String[] t = file.poll().split(" ");
            output.append("Case #").append(i+1).append(": ").append(solution(t)).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-"+attempt+".out", output.toString());
        System.out.println(output);
    }
    
    public static String solution(String[] t) {
        ArrayList<String> l = new ArrayList<>();
        l.addAll(Arrays.asList(t));
        
        return Long.toString(solutionSmall("", l));
    }
    
    public static long solutionSmall(String base, ArrayList<String> t) {
        if(!valid(base))
            return 0;
        
        if(t.isEmpty())
           return 1;
        
        long counter = 0;
        
        for(int i=0; i < t.size(); i++) {
            String j = base + t.get(i);
            if(valid(j)) {
               ArrayList<String> k = new ArrayList<>(t);
               k.remove(i);
               counter += solutionSmall(j, k);
            }
        }
        
        
        return counter;
    }

    private static ArrayList<String> concatinate(ArrayList<String> t) {
        ArrayList<String> r = new ArrayList<>();
        for(int i=0; i < t.size(); i++)
            for(int j=0; j < t.size(); j++) {
                if(i == j)
                   continue;
                
                String k = t.get(i)+t.get(j);
                if(valid(k))
                   r.add(k);
            }
        
        return r;
    }
    
    private static boolean valid(String string) {
        HashSet<Character> set = new HashSet<>();

        char last = 0;        
        for(int i=0; i < string.length(); i++) {
            if(string.charAt(i) != last) {
               if(set.contains(string.charAt(i)))
                  return false;
               
               set.add(string.charAt(i));
               last = string.charAt(i);
            }
        }
        
        return true;        
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
