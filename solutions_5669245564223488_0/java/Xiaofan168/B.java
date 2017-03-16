package com.my.algo.gcj2014.r1c;

import java.util.*;
import java.io.*;

public class B {
    final static String PROBLEM_NAME = "B";
    final static String WORK_DIR = "D:\\GCJ\\2014\\r1c\\" + PROBLEM_NAME + "\\";
    final static String INPUT_FILE = "B-small-attempt0.in";
    static long counter = 0;
    static HashSet<Character> globalCharSet = new HashSet<Character>();
    
    B(){
    	for(char c = 'a'; c <= 'z'; c++){
    		globalCharSet.add(c);
    	}
    	globalCharSet.add('-');
    }

    void solve(Scanner sc, PrintWriter pw) {
    	int n = sc.nextInt();
    	LinkedList<String> strList = new LinkedList<String>();
    	for(int i = 0; i < n; i++){
    		strList.add(sc.next());
    	}
    	
    	counter = 0;
    	generateConnectedStr("" , strList);
    	
    	System.out.println(counter);
    	pw.println(counter);
    }
    
    void generateConnectedStr(String prefix, LinkedList<String> strList){
    	if(strList.size() == 0){
    		if(verify(prefix)){
    			counter++;
    		}
    	} else {
	    	for(int i = 0; i < strList.size(); i++){
	    		String newPrefix = prefix + strList.get(i);
	    		LinkedList<String> newStrList = (LinkedList<String>) strList.clone();
	    		newStrList.remove(i);
	    		generateConnectedStr(newPrefix, newStrList);    		
	    	}
    	}
    }
    
    boolean verify(String s){
    	boolean result = true;
    	HashSet<Character> charSet = (HashSet<Character>) globalCharSet.clone();
    	
    	char prev = '-';
    	char c = '-';
    	for(int i = 0; i < s.length(); i++){
    		c = s.charAt(i);
    		if(c != prev){
    			if(charSet.contains(c)){
    				charSet.remove(c);
    	    		prev = c;
    			} else {
    				return false;
    			}
    		}
    	}
    	
//    	if(!charSet.contains(c)){
//			return false;
//		}

    	return result;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + INPUT_FILE));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new B().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}