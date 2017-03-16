package com;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.text.Collator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;

public class DeceitfulWar {

    public static void main(String[] args) {
        
        String base="files/";
        String in=base + "D-large.in";
        String out=base + "output1.txt";
        
        
	    try {
	    	BufferedReader br = new BufferedReader(new FileReader(in));
	        
	        StringBuilder sb = new StringBuilder();
	        String line = br.readLine();
	        
	        int tctotal = 0;
	        int tc = 0;
	        
	        int i = -1;
	        int j = 0;
	        
	        int size = 0;
	        LinkedList<Double> naomi = new LinkedList<Double>();
	        LinkedList<Double> ken = new LinkedList<Double>();
	        
	        while (line != null) {
	        	i++;
	        	
		        if(i == 0){
	        		tctotal = Integer.parseInt(line);
	        		tc = 1;
	        	} else {
	        		if(j == 0){
	        			size = Integer.parseInt(line);
	        
	        			j++;
	        		} else if (j==1){
	        			String [] parse = line.split(" ");
	        			for(int a = 0; a< parse.length; a++){
	        				naomi.add(Double.parseDouble(parse[a]));
	        			}
	        			
	        			j++;
	        		} else if(j==2){
	        			String [] parse = line.split(" ");
	        			for(int a = 0; a< parse.length; a++){
	        				ken.add(Double.parseDouble(parse[a]));
	        			}
	        			
	        			// Analyze
	        			Collections.sort(naomi, new Comparator<Double>(){
							public int compare(Double arg0, Double arg1) {
								return Double.compare(arg0, arg1);
							}
	        			});
	        			
	        			Collections.sort(ken, new Comparator<Double>(){
							public int compare(Double arg0, Double arg1) {
								return Double.compare(arg0, arg1);
							}
	        			});
	        			
	        			int deceitwar = size;
	        			int war = size;
	        			
	        			LinkedList<Double> naomiWar = new LinkedList<Double>(naomi);
	        			LinkedList<Double> kenWar = new LinkedList<Double>(ken);
	        			
	        			// deceitwar
	        			while(notfull(naomi, ken)){
	        				naomi.removeFirst();
	        				ken.removeLast();
	        				deceitwar --;
	        			}
	        			
	        			// war
	        			while(naomiWar.getFirst() < kenWar.getLast()){
	        				double selected = naomiWar.removeFirst();
	        				
	        				int a = 0;
	        				double node = kenWar.get(0);
	        				while(node<selected){
	        					a++;
	        					node = kenWar.get(a);
	        				}
	        				kenWar.remove(a);
	        				war --;
	        				if(naomiWar.size()<=0){
	        					break;
	        				}
	        			}
	        			
	        			sb.append("Case #"+tc+": "+deceitwar+" "+war);
	        			sb.append(System.lineSeparator());
	        			// Reset
	        			tc ++;
	        			size = 0;
	        			j = 0;
	        			naomi = new LinkedList<Double>();
	        	        ken = new LinkedList<Double>();
	        		}
	        	}
		        String everything = sb.toString();

		        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(
		                new FileOutputStream("files/output.txt"), "utf-8"));
		          writer.write(everything);
		          writer.close();
	        	line = br.readLine();
	        }
	    } catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
	    }
    }

	private static boolean notfull(LinkedList<Double> naomi,
			LinkedList<Double> ken) {
		if(naomi.isEmpty()){
			return false;
		}
		for(int i = 0; i<naomi.size(); i++){
			if(naomi.get(i)<ken.get(i)){
				return true;
			}
		}
		return false;
	}
}
