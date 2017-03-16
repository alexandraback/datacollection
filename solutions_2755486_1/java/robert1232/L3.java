package com.googlejam.robert;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class L3 {
	public static void main(String[] args) {
		List<String> inputString = getInputStrings("C:\\Users\\Robert\\Documents\\Java\\input\\C-large.in");
		int iterations = Integer.parseInt(inputString.get(0));
		inputString.remove(0);
		List<Object> objectList = S2Parser(inputString, iterations);
		int counter = 1;
		for (Object i: objectList){
			String output="";
			output+="Case #" + counter + ": ";	
			output+=S2Result(i);
			try {
			    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Robert\\Documents\\Java\\output\\C-large.out", true)));
			    out.println(output);
			    out.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			System.out.println(output);
			counter++;
		}
		
	}
	private static List<Object> S2Parser(List<String> inputString,
			int iterations) {
		List<Object> list = new ArrayList<Object>();
		for(int i = 0; i<iterations;i++){
			int attackers = Integer.parseInt(inputString.get(0));
			inputString.remove(0);
			String aggregate="";
			for(int a = 0; a<attackers;a++){
				aggregate+=inputString.get(0)+"a";				
				inputString.remove(0);
				
			}
			aggregate=aggregate.substring(0,aggregate.length()-1);
			//System.out.println(aggregate);
			list.add(aggregate);
		}
		return list;
	}
	
	private static List<Object> doubleParse(List<String> inputString, int iterations){
		List<Object> list = new ArrayList<Object>();
		boolean second = false;
		String line = "";
		for(String i: inputString){			
			if(!second){
				line+=i.split(" ")[0];
				second = true;
			}
			else{
				line+=" "+i;
				list.add(line);
				line="";
				second = false;
			}
		}
		return list;
	}
	
	private static List<Integer> convertList(String s){
		List<Integer> list = new ArrayList<Integer>();
		for(String a: s.split(" ")){
			list.add(Integer.parseInt(a));
		}
		return list;
	}
	
	private static String S2Result(Object i) {
		String aggregate = (String)i;
		String[] attacks = aggregate.split("a");
		List<List<Integer>> attackList = new ArrayList<List<Integer>>();
		for(String s: attacks){
			if(s!=""){
				List<Integer> values = new ArrayList<Integer>();
				values = convertList(s);		
				System.out.println(values);
				attackList.addAll(generateAttacks(values));
			}
		}
		Collections.sort(attackList, new Comparator<List<Integer>>(){
			public int compare(List<Integer> a, List<Integer> b){
				return (a.get(0)).compareTo(b.get(0));
			}
		});
		int[] wall = new int[20000000];
		for(int a = 0; a<201;a++){
			wall[a]=0;
		}
		List<Integer> days = new ArrayList<Integer>();
		for(List<Integer> a: attackList){
			days.add(a.get(0));
		}
		int successes=0;
		for(int day: days){
			List<List<Integer>> fix = new ArrayList<List<Integer>>();
			for(List<Integer> a: attackList){
				if(a.get(0)==day){
					int power = a.get(1);
					int west = a.get(2)+5000000;
					int east = a.get(3)+5000000;
					boolean succeed = false;
					for(int x = west; x<east; x++){
						if(power > wall[x]){
							succeed = true;
							List<Integer> fixpart = new ArrayList<Integer>();
							fixpart.add(x);
							fixpart.add(power);
							fix.add(fixpart);
						}
					}
					if(succeed){
						successes++;
					}
				}
			}
			for(List<Integer> a: fix){
				if(wall[a.get(0)]<a.get(1)){
					wall[a.get(0)]=a.get(1);
				}
			}
		}
		return String.valueOf(successes);
	}
	private static List<List<Integer>> generateAttacks(
			List<Integer> values) {
		List<List<Integer>> attackList = new ArrayList<List<Integer>>();
		int firstDay = values.get(0);
		int numAttacks = values.get(1);
		int firstWest = values.get(2);
		int firstEast = values.get(3);
		int firstStrength = values.get(4);
		int deltaD = values.get(5);
		int deltaP = values.get(6);
		int deltaS = values.get(7);
		int day = firstDay;
		int power = firstStrength;
		int east = firstEast;
		int west = firstWest;
		for(int i = 0; i<numAttacks;i++){
			List<Integer> attack = new ArrayList<Integer>();
			attack.add(day);
			attack.add(power);
			attack.add(west);
			attack.add(east);
			day+=deltaD;
			power+=deltaS;
			east+=deltaP;
			west+=deltaP;
			attackList.add(attack);
		}
		return attackList;
	}
	public static List<String> getInputStrings(String filename){
		
		List<String> inputString = new ArrayList<String>();
		BufferedReader br = null;
		 
		try { 
			String sCurrentLine;
	 
			br = new BufferedReader(new FileReader(filename));
	 
			while ((sCurrentLine = br.readLine()) != null) {
				//System.out.println(sCurrentLine);
				inputString.add(sCurrentLine);
			}
	 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
		return inputString;
	}
}
