package com.spawn.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;



// https://github.com/google/guava/
import com.google.common.collect.*;
import com.google.common.collect.Multiset.Entry;

class Case {

	public int caseNumber;
	public String result;

	public Case(int i, Scanner s) {
		caseNumber = i;
		parse(s);
	}

	public String getResult() {
		return "Case #" + caseNumber + ": " + result + "\n";
	}

	int k, l, s;
	String keys, trgt;

	public void parse(Scanner sc) {
		k = sc.nextInt();
		l = sc.nextInt();
		s = sc.nextInt();
		keys = sc.next();
		trgt = sc.next();
	}

	Multiset<Character> set = HashMultiset.create();
	Pattern p;
    int count = 0;
    double diff = 0;
    int max = 0;
	public void append(StringBuilder sb, int i){
		if(i<s){
			for(char x : set.elementSet()){
				sb.setCharAt(i, x);
				append(sb,i+1);
			}
		}
		else{
			String str = sb.toString();
		    Matcher m = p.matcher(str);
		    int matches = 0;
		    for(int j=0;j<s;j++){
		    	if(m.find(j)){
		    		j = m.start();
		    		matches++;
		    	}
		    }
		    if(matches > 0){
		    	double prob = 1;
		    	int denom = 1;
		    	for(char c : str.toCharArray()){
		    		prob *= set.count(c);
		    		denom *= k;
		    	}
		    	prob = prob / denom;
		    	diff += matches*prob;
		    }
		    max = Math.max(max, matches);
		    count+= matches;
		    
		}
	}
	
	public void solve() {
		for (char c : keys.toCharArray()) {
			set.add(c);
		}
		StringBuilder sb = new StringBuilder(new String(new char[s]).replace('\0', ' '));
	    p = Pattern.compile(trgt);
		append(sb,0);
		double res = max - diff;
		result = Double.toString(res);
		
		System.out.println("#" + caseNumber + " done; "
				+ Main.casesRemaining.decrementAndGet() + " remaining");
	}

}

public class Main {

	public static AtomicInteger casesRemaining = new AtomicInteger();

	public static void main(String[] args) {
		try {
			String name = readLine();
			Scanner s = new Scanner(new File("../" + name + ".in"));

			int t = s.nextInt();
			casesRemaining.set(t);
			ArrayList<Case> cases = new ArrayList<Case>(t);
			File f = new File("../" + name + ".out");
			FileWriter output = new FileWriter(f);
			for (int i = 0; i < t; i++) {
				cases.add(i, new Case(i + 1, s));
			}
			if (name.equals("test"))
				cases.stream().forEach(Case::solve);
			else
				cases.parallelStream().forEach(Case::solve);

			for (int i = 0; i < t; i++) {
				output.write(cases.get(i).getResult());
			}
			output.close();
			s.close();

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static String readLine() throws IOException {
		if (System.console() != null) {
			return System.console().readLine();
		}
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		return reader.readLine();
	}

}
