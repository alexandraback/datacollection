package com.petrodavi.exercises.R123;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import com.petrodavi.utils.ReadDataFromFile;


public class Ex_2015_R1C_B {
	
	private static ArrayList<String> generateCombinations(int arraySize, ArrayList<String> possibleValues)
	{
	    int carry;
	    ArrayList<String> res = new ArrayList<String>();
	    int[] indices = new int[arraySize];
	    do
	    {
	    	String tmp = "";
	        for(int index : indices)
	            tmp = tmp.concat(possibleValues.get(index) + " ");
	        res.add(tmp);

	        carry = 1;
	        for(int i = indices.length - 1; i >= 0; i--)
	        {
	            if(carry == 0)
	                break;

	            indices[i] += carry;
	            carry = 0;

	            if(indices[i] == possibleValues.size())
	            {
	                carry = 1;
	                indices[i] = 0;
	            }
	        }
	    }
	    while(carry != 1); // Call this method iteratively until a carry is left over
	return res;
	}
	
/*	public static void permutation(String str) { 
	    permutation("", str); 
	}

	private static String permutation(String prefix, String str) {
	    int n = str.length();
	    if (n == 0) System.out.println(prefix);
	    else {
	        for (int i = 0; i < n; i++)
	            permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
	    }
	    return null;
	}*/
	
	private static ArrayList<String> permDizionario(HashMap<Character, Double> hash, int lenght){
		ArrayList<String> al_str = new ArrayList<String>();
		for (Character a : hash.keySet()){
			al_str.add(a.toString());
		}
		return generateCombinations(lenght, al_str);
	}
	
	private static double prob_singoli_casi(String tmp, HashMap<Character, Double> hash){
		double prob = 1;
		for (Character s : tmp.toCharArray()){
			if (hash.get(s) != null){
				prob = prob * hash.get(s);
			}
		}
		return prob;
	}
	
	  public static int count(final String substring, final String string)
	  {
	     int count = 0;
	     int idx = 0;

	     while ((idx = string.indexOf(substring, idx)) != -1)
	     {
	        idx++;
	        count++;
	     }

	     return count;
	  }
	
/*	private static int occorrenze_singoli_casi(String target, String check){
	    
		//String str = "helloslkhellodjladfjhello";
	    Pattern p = Pattern.compile(target);
	    Matcher m = p.matcher(check);
	    int count = 0;
	    while (m.find()){
	    	count +=1;
	    }
	    System.out.println(count);
		return count;
	}*/
	
	
	public static void main(String[] args) throws Throwable {

		List<String> mList = null;

		try {
			mList = ReadDataFromFile.readStringsArraysFromFile(
					"Ex/R123/Ex_2015_R1C_B_S.in");
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}

		String outString = "";
		int numrow=0;
		int T = Integer.parseInt(mList.get(numrow++));
		int t=1;

		while ( t<=T ) {

			StringTokenizer strTkn = new  StringTokenizer(mList.get(numrow++));
			int K = Integer.parseInt(strTkn.nextToken());
			int L = Integer.parseInt(strTkn.nextToken());
			int S = Integer.parseInt(strTkn.nextToken());
			String _dict = mList.get(numrow++);
			String _target = mList.get(numrow++);
	
			HashMap<Character, Double> m_hash = new HashMap<Character, Double>();
			int dict_len = 0;
			
			for ( Character a : _dict.toCharArray() ) {
				if ( m_hash.get(a) != null ) {
					double tmp = m_hash.get(a);
					tmp++;
					m_hash.put(a, tmp);
					dict_len++;
				}
				else {
					m_hash.put(a, (double) 1);
					dict_len++;
				}
			}
			
			for (Character a : m_hash.keySet()){
				m_hash.put(a, (double)(m_hash.get(a)/dict_len));
			}
			
			boolean nosol = false;
			double bananas = 0;
			
			for ( Character a : _target.toCharArray() ) {
				if ( m_hash.get(a) == null )  {
					// Impossible,no bananas!!!
					nosol = true;
					break;
				}
			}

			if ( nosol != true ) {
				ArrayList<String> m_comb = permDizionario(m_hash, S);
				double[] prob = new double[m_comb.size()];
				int[] occ = new int[m_comb.size()];
				int i = 0;
				for (String str : m_comb) {
					prob[i] = prob_singoli_casi(str.replaceAll("\\s",""), m_hash);
					occ[i] = count(_target, str.replaceAll("\\s",""));
					i++;
				}
				int max_occ = 0;
				for (i = 0; i<m_comb.size() ; i++){
					if (occ[i] > max_occ){
						max_occ = occ[i];
					}
				}
				for (i = 0; i<m_comb.size() ; i++){
					bananas += prob[i]*occ[i];
				}
				bananas = max_occ - bananas;
			}
			else {
				bananas = 0;
			}

			String m_outString=String.format("Case #%d: %f", t++, bananas);
			m_outString+=String.format("\n");
			System.out.print(m_outString);
			outString+=m_outString;

		}


		try {
			ReadDataFromFile.writeToFile("Sol/"+"solution.txt", outString);
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
