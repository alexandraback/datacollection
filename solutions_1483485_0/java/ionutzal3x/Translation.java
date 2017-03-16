/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package translation;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author ALEX
 */
public class Translation {

    public Map s;
    public Translation()
    {
        s=new HashMap();
        this.populateMap();
    }
    /**
     * @param args the command line arguments
     */
    public void populateMap()
    {
        s.put('a','y');
        s.put('b','h');
        s.put('c','e');
        s.put('d','s');
        s.put('e','o');
        s.put('f','c');
        s.put('g','v');
        s.put('h','x');
        s.put('i','d');
        s.put('j','u');
        s.put('k','i');
        s.put('l','g');
        s.put('m','l');
        s.put('n','b');
        s.put('o','k');
        s.put('p','r');
        s.put('q','z');
        s.put('r','t');
        s.put('s','n');
        s.put('t','w');
        s.put('u','j');
        s.put('v','p');
        s.put('w','f');
        s.put('x','m');
        s.put('y','a');
        s.put('z','q');
        s.put(' ',' ');
    }  
    
    public String translate(String str)
    {
        String r=new String();
        for(int i=0;i<str.length();i++)
            r=r+s.get(str.charAt(i));
        return r;            
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Translation t=new Translation();
        try {
             FileReader fin=new FileReader("A-small-attempt2.in");
             BufferedReader in = new BufferedReader(fin);
             FileWriter fout=new FileWriter("result.txt");
             BufferedWriter out=new BufferedWriter(fout);
             String str;
             str=in.readLine();
             int nr=Integer.valueOf(str);
             for(int i=1;i<=nr;i++)
             {
                 str=in.readLine();
                 out.write("Case #"+i+": ");
                 out.write(t.translate(str));
                 out.newLine();
             }
             in.close();
             fin.close();
             out.close();
             fout.close();
             }
        catch(Exception e){} 
    }
}
