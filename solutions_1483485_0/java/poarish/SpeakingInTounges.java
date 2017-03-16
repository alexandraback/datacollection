/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package SpeakingInTounges;

import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Scanner;

/**
 *
 * @author Rishabh
 */
public class SpeakingInTounges {
    
    private char[] mapped_array = new char[26];
    
    
    public SpeakingInTounges(){
        for(int i=0;i<mapped_array.length;i++){
            mapped_array[i] = '*';
        }
    }
    
    public void createMapping(String[][] maps){
        int counter = 0;
        for(int i=0;i<maps.length;i++){
            String goog = maps[i][0];
            String normal = maps[i][1];
            for(int j=0;j<goog.length();j++){
                int index = goog.charAt(j) - 'a';
                if(goog.charAt(j) != ' ' && mapped_array[index] == '*'){
                    counter++;
                    mapped_array[index] = normal.charAt(j);
                }
                else if(goog.charAt(j) != ' ' && normal.charAt(j) != mapped_array[index]){
                    System.out.println("Its an error");
                    System.exit(0);
                }
            }
        }
//        System.out.println("Done for " + counter + " characters");
//        for(int i=0;i<mapped_array.length;i++){
//            System.out.println((char)('a'+i) + " is mapped to " + mapped_array[i]);
//        }
    }
    
    public void readFile(String path) throws Exception{
        File f = new File(path);
        Scanner scanner = new Scanner(f);
        String name = f.getName().substring(0,f.getName().indexOf('.'));
        Writer writer = new FileWriter(name+".out");
        int n = Integer.parseInt(scanner.nextLine());
        int count=0;
        while(scanner.hasNextLine()){
            count++;
            writer.write("Case #"+count+": "+convert(scanner.nextLine())+"\r\n");
        }
        writer.close();
        scanner.close();
    }
    
    private String convert(String s){
        String ans = "";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == ' '){
                ans += " ";
            }
            else{
//                System.out.println(s.charAt(i));
                ans += String.valueOf(mapped_array[s.charAt(i)-'a']);
            }
        }
        return ans;
    }
    
    public static void main(String args[]) throws Exception{
        String[][] maps = new String[][]{ 
            new String[]{
                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "our language is impossible to understand"
            }, 
            new String[]{
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "there are twenty six factorial possibilities"
            }, 
            new String[]{
                "de kr kd eoya kw aej tysr re ujdr lkgc jv",
                "so it is okay if you want to just give up"
            },
            new String[]{
                "zq",
                "qz"
            }
        };
        SpeakingInTounges speakingInTounges = new SpeakingInTounges();
        speakingInTounges.createMapping(maps);
        speakingInTounges.readFile("A-small-practice.in");
    }
    
}
