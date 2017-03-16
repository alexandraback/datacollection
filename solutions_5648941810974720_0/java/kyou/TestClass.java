package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.FilenameFilter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Map.Entry;

public class TestClass {

	public static void main (String[] args) throws IOException {
		TestClass testClass = new TestClass();

		//testClass.fixUninitSend(new File("\\\\FM6GW7VPG130\\forSend"));
		
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt"));

		int caseNum = Integer.parseInt(reader.readLine());
		for(int i=0; i<caseNum; i++) {
			String cakeStr = reader.readLine();
			
			writer.write("Case #" + (i+1) + ":");
			writer.write(" " + testClass.findNum(cakeStr));
			writer.write("\n");

			writer.flush();
		}

		reader.close();
		writer.close();
	}
	
	private String findNum(String str) {
		Map<Character, Integer> charMap = new HashMap<Character, Integer>();
		for(int i=0; i<str.length(); i++) {
			if(charMap.containsKey(str.charAt(i))) {
				charMap.put(str.charAt(i), charMap.get(str.charAt(i)) + 1);
			} else {
				charMap.put(str.charAt(i), 1);
			}
		}
		String ret = "";
		int[] retInt = new int[10];
		if(charMap.containsKey('Z'))
		for(int i=0; i<charMap.get('Z'); i++) {
			retInt[0]++;
			charMap.put('O', charMap.get('O') - 1);
		}
		if(charMap.containsKey('W'))
		for(int i=0; i<charMap.get('W'); i++) {
			retInt[2]++;
			charMap.put('O', charMap.get('O') - 1);
			charMap.put('T', charMap.get('T') - 1);
		}
		if(charMap.containsKey('U'))
		for(int i=0; i<charMap.get('U'); i++) {
			retInt[4]++;
			charMap.put('F', charMap.get('F') - 1);
			charMap.put('O', charMap.get('O') - 1);
		}
		if(charMap.containsKey('X'))
		for(int i=0; i<charMap.get('X'); i++) {
			retInt[6]++;
			charMap.put('S', charMap.get('S') - 1);
			charMap.put('I', charMap.get('I') - 1);
		}
		if(charMap.containsKey('G'))
		for(int i=0; i<charMap.get('G'); i++) {
			retInt[8]++;
			charMap.put('I', charMap.get('I') - 1);
			charMap.put('T', charMap.get('T') - 1);	
		}
		if(charMap.containsKey('O'))
		for(int i=0; i<charMap.get('O'); i++) {
			retInt[1]++;
		}
		if(charMap.containsKey('T'))
		for(int i=0; i<charMap.get('T'); i++) {
			retInt[3]++;
		}
		if(charMap.containsKey('F'))
		for(int i=0; i<charMap.get('F'); i++) {
			charMap.put('I', charMap.get('I') - 1);
			retInt[5]++;
		}
		if(charMap.containsKey('S'))
		for(int i=0; i<charMap.get('S'); i++) {
			retInt[7]++;
		}
		if(charMap.containsKey('I'))
		for(int i=0; i<charMap.get('I'); i++) {
			retInt[9]++;
		}
		
		for(int i=0; i<10; i++) {
			for(int j=0; j< retInt[i]; j++) {
				ret += i;
			}
		}
		return ret;
	}
	
	private int findCakeCount(String cakeStr) {
		if(cakeStr.length() != 1) {
			char c = cakeStr.charAt(cakeStr.length() - 1);
			for(int i = cakeStr.length() - 2; i >= 0; i--) {
				if(cakeStr.charAt(i) == c) {
					cakeStr = cakeStr.substring(0, i) + cakeStr.substring(i+1);
				} else {
					c = cakeStr.charAt(i);
				}
			}
		}
		
		for(int i=cakeStr.length()-1; i>=0; i--) {
			if(cakeStr.charAt(i) == '+') {
				cakeStr = cakeStr.substring(0, cakeStr.length()-1);
			} else {
				break;
			}
		}
		return cakeStr.length();
	}
	
	private void findJamCoins() throws IOException {
		int jamCoinNum = 50;
		int jamCoinLength = 16;
//		int jamCoinNum = 3;
//		int jamCoinLength = 6;
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt"));
		writer.write("Case #" + "1:\n");
		writer.close();
		
		long jamCoinMax = (long)Math.pow(2, jamCoinLength - 2) - 1;
		int jamCoinFound = 0;
		for(long jamCoin = 0; jamCoin < jamCoinMax; jamCoin++) {
			String fullJamCoinStr = "1";
			if(Long.toBinaryString(jamCoin).length() < jamCoinLength - 2) {
				for(int i = 0; i < jamCoinLength - 2 - Long.toBinaryString(jamCoin).length(); i++) {
					fullJamCoinStr += "0";
				}
			}
			long fullJamCoin = Long.parseLong(fullJamCoinStr + Long.toBinaryString(jamCoin) + "1");
			if(isJamCoin(fullJamCoin)) {
				jamCoinFound++;
				System.out.println(fullJamCoin);
				System.out.println(jamCoinFound);
				if(jamCoinFound == jamCoinNum) {
					break;
				}
			}
			
		}
	}
	
	private boolean isJamCoin(long num) throws IOException {
		Integer primeNumbers[] = {
				2,3,5,7,11,13,17,19,23,29,
				31,37,41,43,47,53,59,61,67,71,
				73,79,83,89,97,101,103,107,109,113,
				127,131,137,139,149,151,157,163,167,173,
				179,181,191,193,197,199,211,223,227,229,
				233,239,241,251,257,263,269,271,277,281,
				283,293,307,311,313,317,331,337,347,349,
				353,359,367,373,379,383,389,397,401,409,
				419,421,431,433,439,443,449,457,461,463,
				467,479,487,491,499,503,509,521,523,541,
				547,557,563,569,571,577,587,593,599,601,
				607,613,617,619,631,641,643,647,653,659,
				661,673,677,683,691,701,709,719,727,733,
				739,743,751,757,761,769,773,787,797,809,
				811,821,823,827,829,839,853,857,859,863,
				877,881,883,887,907,911,919,929,937,941,
				947,953,967,971,977,983,991,997,1009,1013,
				1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,
				1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,
				1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,
				1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,
				1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,
				1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,
				1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,
				1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,
				1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,
				1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,
				1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,
				1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,
				1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,
				1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,
				2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,
				2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,
				2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,
				2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,
				2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,
				2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,
				2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,
				2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,
				2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,
				2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,
				2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,
				2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,
				2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,
				3079,3083,3089,3109,3119,3121,3137,3163,3167,3169,
				3181,3187,3191,3203,3209,3217,3221,3229,3251,3253,
				3257,3259,3271,3299,3301,3307,3313,3319,3323,3329,
				3331,3343,3347,3359,3361,3371,3373,3389,3391,3407,
				3413,3433,3449,3457,3461,3463,3467,3469,3491,3499,
				3511,3517,3527,3529,3533,3539,3541,3547,3557,3559,
				3571,3581,3583,3593,3607,3613,3617,3623,3631,3637,
				3643,3659,3671,3673,3677,3691,3697,3701,3709,3719,
				3727,3733,3739,3761,3767,3769,3779,3793,3797,3803,
				3821,3823,3833,3847,3851,3853,3863,3877,3881,3889,
				3907,3911,3917,3919,3923,3929,3931,3943,3947,3967,
				3989,4001,4003,4007,4013,4019,4021,4027,4049,4051,
				4057,4073,4079,4091,4093,4099,4111,4127,4129,4133,
				4139,4153,4157,4159,4177,4201,4211,4217,4219,4229,
				4231,4241,4243,4253,4259,4261,4271,4273,4283,4289,
				4297,4327,4337,4339,4349,4357,4363,4373,4391,4397,
				4409,4421,4423,4441,4447,4451,4457,4463,4481,4483,
				4493,4507,4513,4517,4519,4523,4547,4549,4561,4567,
				4583,4591,4597,4603,4621,4637,4639,4643,4649,4651,
				4657,4663,4673,4679,4691,4703,4721,4723,4729,4733,
				4751,4759,4783,4787,4789,4793,4799,4801,4813,4817,
				4831,4861,4871,4877,4889,4903,4909,4919,4931,4933,
				4937,4943,4951,4957,4967,4969,4973,4987,4993,4999,
				5003,5009,5011,5021,5023,5039,5051,5059,5077,5081,
				5087,5099,5101,5107,5113,5119,5147,5153,5167,5171,
				5179,5189,5197,5209,5227,5231,5233,5237,5261,5273,
				5279,5281,5297,5303,5309,5323,5333,5347,5351,5381,
				5387,5393,5399,5407,5413,5417,5419,5431,5437,5441,
				5443,5449,5471,5477,5479,5483,5501,5503,5507,5519,
				5521,5527,5531,5557,5563,5569,5573,5581,5591,5623,
				5639,5641,5647,5651,5653,5657,5659,5669,5683,5689,
				5693,5701,5711,5717,5737,5741,5743,5749,5779,5783,
				5791,5801,5807,5813,5821,5827,5839,5843,5849,5851,
				5857,5861,5867,5869,5879,5881,5897,5903,5923,5927,
				5939,5953,5981,5987,6007,6011,6029,6037,6043,6047,
				6053,6067,6073,6079,6089,6091,6101,6113,6121,6131
		};
		List<Integer> primeList = Arrays.asList(primeNumbers);
		
		List<Long> result = new ArrayList<Long>();
		result.add(num);
		for(int base = 2; base <= 10; base++) {
			long numBase = convertNumByBase(num, base);
			for(int primeNum : primeList) {
				if(numBase == primeNum) {
					return false;
				}
				if(numBase % primeNum == 0) {
					result.add((long)primeNum);
					break;
				}
			}
			if(result.size() < base) {
				return false;
			}
		}
		
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt", true));
		
		for(int i=0; i<result.size(); i++) {
			writer.write("" + result.get(i));
			if(i < result.size()-1) {
				writer.write(" ");
			}
			
		}
		writer.write("\n");

		writer.flush();
		writer.close();
		return true;
	}
	
	private long convertNumByBase(long num, int base) {
		if(base == 10) {
			return num;
		}
		long ret = 0;
		int i = 0;
		while(num != 0) {
			ret += num % 10 * Math.pow(base, i);
			i++;
			num /= 10;
		}
		
		return ret;
	}
	
	private boolean isPrimeOrNot(long num) { 
		if (num < 0) { 
			return false;
		} 
		if (num == 0 || num == 1) { 
			return false;
		} 
		if (num == 2 || num == 3) { 
			return true; 
		} 
		if ((num * num - 1) % 24 == 0) { 
			return true;
		} 
		else { 
			return false;
		} 
	}

	
	private void convertMyTracker() throws IOException {
		File file = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\EuGaEmFpu.txt");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		List<String> lines = new ArrayList<String>();
		String cline = "";
		while((cline = reader.readLine()) != null) {
			lines.add(cline);
		}
		reader.close();
		
		File fileWrite = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\test.txt");
		BufferedWriter writer = new BufferedWriter(new FileWriter(fileWrite));
		boolean lineOne = true;
		int subRegNum = 0;
		
		for(String line : lines) {
			if(line.startsWith("--") || line.equals("END")) {
				continue;
			}
			
			int srcCount = 0;
			String[] tokens = line.split(" ");
			for(int i = 0; i < tokens.length; i++) {
				String token = tokens[i];
				if(token.length() > 50) {
					if((lineOne && srcCount < 3) || (!lineOne && srcCount != 0 && srcCount < 3)) {
						for(int j = 0; j < 8; j++) {
							writer.write("mov (1) r3" + subRegNum + "." + j + ":ud 0x" + token.substring((7 - j) * 8, (8 - j) * 8) + ":ud {NoMask}\n");
						}
						writer.write("\n");
						subRegNum++;
					}
					srcCount++;
				}
			}
			
			if(!lineOne) {
				if(tokens[24].equals("1")) {
					writer.write("or (1) cr0.0:ud cr0.0:ud 0x00000080:ud {NoMask}      // SP Denorm\n");
				} else {
					writer.write("and (1) cr0.0:ud cr0.0:ud 0xffffff7f:ud {NoMask}     // clear SP denorm mode\n");
				}
				writer.write("and (1) cr0.0:ud cr0.0:ud 0xffffffcf:ud {NoMask}     // clear rounding mode\n");
				switch(Integer.parseInt(tokens[28])) {
				case 1: writer.write("or (1) cr0.0:ud cr0.0:ud 0x00000010:ud {NoMask}      // Round Up\n"); break;
				case 2: writer.write("or (1) cr0.0:ud cr0.0:ud 0x00000020:ud {NoMask}      // Round Down\n"); break;
				case 3: writer.write("or (1) cr0.0:ud cr0.0:ud 0x00000030:ud {NoMask}      // Round To Zero\n"); break;
				}
				
				writer.write("mad (8) acc0:nf r30.0<8;8,1>:f r31.0<8;8,1>:f r32.0<8;8,1>:f {NoMask}\n");
				writer.write("mad (8) r50.0<1>:f acc0:nf r33.0<8;8,1>:f r34.0<8;8,1>:f {NoMask}\n\n");
				
				subRegNum = 0;
			}

			lineOne = !lineOne;
		}
		writer.close();
	}
	
	private void convertBalaTracker() throws IOException {
		File file = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\EuGaEmFpu - Bala_new.txt");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		List<String> lines = new ArrayList<String>();
		String cline = "";
		while((cline = reader.readLine()) != null) {
			lines.add(cline);
		}
		reader.close();
		
		File fileWrite = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\test.txt");
		BufferedWriter writer = new BufferedWriter(new FileWriter(fileWrite));
		
		for(String line : lines) {
			if(line.startsWith("--") || line.equals("END")) {
				continue;
			}
			String[] tokens = line.split(" ");
			int[] srcMod = new int[5];
			int subRegNum = 0;
			for(int i = 0; i < tokens.length; i++) {
				String token = tokens[i];
				if(token.length() > 50) {
					for(int j = 0; j < 8; j++) {
						writer.write("mov (1) r3" + subRegNum + "." + j + ":ud 0x" + token.substring((7 - j) * 8, (8 - j) * 8) + ":ud {NoMask}\n");
					}
					writer.write("\n");
					srcMod[subRegNum] = Integer.parseInt(tokens[i + 2]);
					subRegNum++;
				}
			}
			
			if(tokens[24].equals("1")) {
				writer.write("or (1) cr0.0:ud cr0.0:ud 0x00000080:ud {NoMask}      // SP Denorm\n");
			} else {
				writer.write("and (1) cr0.0:ud cr0.0:ud 0xffffff7f:ud {NoMask}     // clear SP denorm mode\n");
			}
			writer.write("and (1) cr0.0:ud cr0.0:ud 0xffffffcf:ud {NoMask}     // clear rounding mode\n");
			switch(Integer.parseInt(tokens[28])) {
			case 1: writer.write("or (1) cr0.0:ud cr0.0:ud 0x00000010:ud {NoMask}      // Round Up\n"); break;
			case 2: writer.write("or (1) cr0.0:ud cr0.0:ud 0x00000020:ud {NoMask}      // Round Down\n"); break;
			case 3: writer.write("or (1) cr0.0:ud cr0.0:ud 0x00000030:ud {NoMask}      // Round To Zero\n"); break;
			}
			
			writer.write("mad (8) acc0:nf " + convertSrcMod(srcMod[0]) + "r30.0<8;8,1>:f " + convertSrcMod(srcMod[1]) + "r31.0<8;8,1>:f " + convertSrcMod(srcMod[2]) + "r32.0<8;8,1>:f {NoMask}\n");
			writer.write("mad (8) r50.0<1>:f acc0:nf " + convertSrcMod(srcMod[3]) + "r33.0<8;8,1>:f "  + convertSrcMod(srcMod[4]) + "r34.0<8;8,1>:f {NoMask}\n\n");
		}
		writer.close();
	}
	
	private String convertSrcMod(int srcMode) {
		switch(srcMode) {
		case 0: return "";
		case 1: return "(abs)";
		case 2: return "-";
		case 3: return "-(abs)";
		}
		return "wrong srcMod";
	}
	
	private void compound() {
		String sp500 = "-6.98% 6.51% 18.52% 31.74% -4.70% 20.42% 22.34% 6.15% 31.24% 18.49% 5.81% 16.54% 31.48% -3.06% 30.23% " +
				"7.49% 9.97% 1.33% 37.20% 22.68% 33.10% 28.34% 20.89% -9.03% -11.85% -21.97% 28.36% 10.74% 4.83% 15.61% 5.48% " +
				"-36.55% 25.94% 14.82% 2.10% 15.89% 32.15% 13.48%";
		//String sp500 = "4.83% 15.61% 5.48% -36.55% 25.94% 14.82% 2.10% 15.89% 32.15% 13.48%";
		String[] sp500s = sp500.split(" ");
		double[] sp500sf = new double[sp500s.length];
		for(int i=0; i<sp500s.length; i++) {
			sp500sf[i] = Double.parseDouble(sp500s[i].replace("%", "")) / 100.0;
		}
		double money = 0;
		int year = 1977;
		for(int i=0; i<sp500sf.length; i++) {
			if(i<5) {
				money += 20;
			}
			money *= 1.0 + sp500sf[i];
			if(i>=10) {
				money -= 25;
			}
			// System.out.format("%.3f%n"
			System.out.format("year: " + year++ + " money: %.3f\n", money);
		}
		System.out.format("final: %.3f\n", money);
	}
	
	private void fixUninitSend(File file) throws IOException {
		if(file.isDirectory()) {
			for(File f : file.listFiles()) {
				fixUninitSend(f);
			}
		} else {
			if(file.getName().endsWith(".asm")) {
				BufferedReader reader = new BufferedReader(new FileReader(file));
				List<String> lines = new ArrayList<String>();
				String cline = "";
				while((cline = reader.readLine()) != null) {
					lines.add(cline);
				}
				reader.close();
				
				File fileWrite = new File(file.getAbsolutePath() + "1");
				BufferedWriter writer = new BufferedWriter(new FileWriter(fileWrite));
				boolean hasAlign16 = false;
	
				for(String line : lines) {
					writer.write(line + "\n");
					if(line.contains("mov (8) r101 r21 {NoMask}")) {
						hasAlign16 = true;
						writer.write("	mov (8) r102<1>:ud 0x0:ud {NoMask}\n");
					}
				}
				writer.close();
				
				if(hasAlign16) {
					file.delete();
					fileWrite.renameTo(new File(fileWrite.getAbsolutePath().substring(0, fileWrite.getAbsolutePath().length() - 1)));
				} else {
					fileWrite.delete();
				}
			}
		}
	}	
	
	private void removeAlign16(File file) throws IOException {
		if(file.isDirectory()) {
			for(File f : file.listFiles()) {
				removeAlign16(f);
			}
		} else {
			if((file.getName().endsWith(".asm") || file.getName().matches(".*\\.g\\d*a"))) {
				BufferedReader reader = new BufferedReader(new FileReader(file));
				List<String> lines = new ArrayList<String>();
				String cline = "";
				while((cline = reader.readLine()) != null) {
					lines.add(cline);
				}
				reader.close();
				
				File fileWrite = new File(file.getAbsolutePath() + "1");
				BufferedWriter writer = new BufferedWriter(new FileWriter(fileWrite));
				boolean hasAlign16 = false;
	
				for(String line : lines) {
					/*if(line.contains(".x:") || line.contains(".xyzw")) {
						hasAlign16 = true;
					}
					if(line.contains("mad (4)")) {
						line = line.replace(".x:", ":").replace("(4)", "(1)");
					}
						
					
					line = line.replace("f0.0.x)", "f0.0)");
					line = line.replaceFirst(".xyzw", "<1>");
					line = line.replace(".xyzw", "<4;4,1>");*/
					
					while(line.contains("><")) {
						hasAlign16 = true;
						int iTmp = line.indexOf("><");
						String tmp = line.substring(iTmp - 2, iTmp + 1);
						line = line.replace(tmp, "");
					}
					writer.write(line + "\n");
				}
				writer.close();
				
				if(hasAlign16) {
					file.delete();
					fileWrite.renameTo(new File(fileWrite.getAbsolutePath().substring(0, fileWrite.getAbsolutePath().length() - 1)));
				} else {
					fileWrite.delete();
				}
			}
		}
	}
	
	private void lrpToMad() throws IOException {
		//File topDir = new File(".");
		//File topDir = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\plnTests");
		File file = new File("\\\\10.80.237.61\\tests\\PERF_Row\\basic\\perf_row_simd16_100dep_lrp\\kernel.asm");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		List<String> lines = new ArrayList<String>();
		String cline = "";
		while((cline = reader.readLine()) != null) {
			lines.add(cline);
		}
		reader.close();
		
		File fileWrite = new File(file.getAbsolutePath());
		BufferedWriter writer = new BufferedWriter(new FileWriter(fileWrite));
		for(String line : lines) {
			if(line.contains("lrp") && !line.matches(".*//.*lrp.*") && (!line.startsWith(".code"))) {
				String execSize = "", dst = "", src0 = "", src1 = "", src2 = "";
				line = line.replace("lrp", "").trim();
				if(line.startsWith("(")) {
					execSize = line.substring(0, line.indexOf(")") + 1);
					line = line.substring(line.indexOf(")") + 3).trim();
					
					for(char c : line.toCharArray()) {
						if(Character.isDigit(c)) {
							dst += c;
						} else {
							break;
						}
					}
					line = line.substring(line.indexOf("r")+1);
					
					for(char c : line.toCharArray()) {
						if(Character.isDigit(c)) {
							src0 += c;
						} else {
							break;
						}
					}
					line = line.substring(line.indexOf("r")+1);
					
					for(char c : line.toCharArray()) {
						if(Character.isDigit(c)) {
							src1 += c;
						} else {
							break;
						}
					}
					line = line.substring(line.indexOf("r")+1);
					
					for(char c : line.toCharArray()) {
						if(Character.isDigit(c)) {
							src2 += c;
						} else {
							break;
						}
					}
					
					writer.write("mad (8) acc0<1>:nf r" + src2 + ":f r" + src0 + ":f r" + src1 + ":f\n");
					writer.write("mad (8) r" + dst + ":f acc0<1>:nf -r" + src0 + ":f r" + src2 + ":f\n");
					if(execSize.equals("(16)")) {
						writer.write("mad (8) acc0<1>:nf r" + (Integer.parseInt(src2) + 1) + ":f r" + (Integer.parseInt(src0) + 1) + ":f r" 
								+ (Integer.parseInt(src1) + 1) + ":f\n");
						writer.write("mad (8) r" + (Integer.parseInt(dst) + 1) + ":f acc0<1>:nf -r" + (Integer.parseInt(src0) + 1) + ":f r" 
								+ (Integer.parseInt(src2) + 1) + ":f\n");
					}
				}
			} else {
				writer.write(line + "\n");
			}
		}
		writer.close();
	}
	
	private void plnToMac() throws IOException {
		//File topDir = new File(".");
		File topDir = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\plnTests\\New folder");
		//File topDir = new File("\\\\10.80.237.61\\tests\\DAP\\basic\\dap_random");
		plnToMacFile(topDir);
	}
	
	private void plnToMacFile(File file) throws IOException {
		if(file.isDirectory()) {
			for(File f : file.listFiles()) {
				plnToMacFile(f);
			}
		} else {
			if((file.getName().endsWith(".asm") || file.getName().matches(".*\\.g\\d*a")) && (!file.getName().contains("eu_op_plane_007"))) {
				BufferedReader reader = new BufferedReader(new FileReader(file));
				List<String> lines = new ArrayList<String>();
				String cline = "";
				while((cline = reader.readLine()) != null) {
					lines.add(cline);
				}
				reader.close();
				
				File fileWrite = new File(file.getAbsolutePath() + "1");
				BufferedWriter writer = new BufferedWriter(new FileWriter(fileWrite));
				boolean hasPln = false;
				int defaultExecSize = 0;

				for(String line : lines) {
					if(line.contains(".default_execution_size")) {
						defaultExecSize = Integer.parseInt(line.replaceAll("\\D*", ""));
					} else if(line.contains("pln") && !line.matches(".*//.*pln.*") && (!line.startsWith(".code"))) {
						hasPln = true;
							
						String pred = "", cmod = "", execSize = "", dst = "", dstOffset = "", dstRegioning = "", src0 = "", src0Offset = "", src1 = "", other = "";
						if(line.trim().startsWith("(")) {
							pred = line.substring(line.indexOf("("), line.indexOf(")") + 1);
							line = line.substring(line.indexOf("pln"));
						}
						
						if(line.contains("pln.")) {
							if(line.contains("(") && line.indexOf("(") < line.indexOf(" "))
							{
								cmod = line.substring(line.indexOf("."), line.indexOf("("));
								line = line.substring(line.indexOf("("));
							} else {
								cmod = line.substring(line.indexOf("."), line.indexOf(" "));
								line = line.substring(line.indexOf(" ")).trim();
							}
						} else {
							line = line.replace("pln", "").trim();
						}
						
						if(line.startsWith("(")) {
							execSize = line.substring(0, line.indexOf(")") + 1);
							line = line.substring(line.indexOf(")") + 1).trim();
						}
						
						dst = "r";
						boolean tmpSwitch = false;
						line = line.substring(1);
						for(char c : line.toCharArray()) {
							if(Character.isDigit(c)) {
								if(!tmpSwitch) {
									dst += c;
								} else {
									dstOffset += c;
								}
							} else if(c == '.') {
								tmpSwitch = true;
							}
							else if(c == '<') {
								dstRegioning = line.substring(line.indexOf("<"), line.indexOf(">") + 1);
								break;
							} else if(c == 'r') {
								break;
							}
						}
						line = line.substring(line.indexOf("r")+1);
						
						src0 = "r";
						tmpSwitch = false;
						for(char c : line.toCharArray()) {
							if(Character.isDigit(c)) {
								if(!tmpSwitch) {
									src0 += c;
								} else {
									src0Offset += c;
								}
							} else if(c == '.') {
								tmpSwitch = true;
							} else if(c == '<' || c == 'r' || c == ':') {
								break;
							}
						}
						line = line.substring(line.indexOf("r")+1);
						
						src1 = "r";
						for(char c : line.toCharArray()) {
							if(Character.isDigit(c)) {
								src1 += c;
							} else {
								break;
							}
						}
						
						if(line.contains("{")) {
							other = line.substring(line.indexOf("{"), line.indexOf("}") + 1);
						}
						
//						[pred] pln[.cmod] (exec_size) dst<dst_regioning>:f    src0.(src0_offset)<0;1,0>:f      src1:f [other: quarter control, NoMask, dep, etc]
//						[pred] mad (8) acc0<dst_regioning>:nf src0.(src0_offset+3)<0;1,0>:f src0.(src0_offset)<0;1,0>:f src1:f [other]
//						[pred] mad[.cond_mod/sat] (8) dst acc0:nf src0.(src0_offset+1)<0;1,0>:f src1+1 [other]
//						[pred] mad (8) acc0<dst_regioning>:nf src0.(src0_offset+3)<0;1,0>:f src0.(src0_offset)<0;1,0>:f src1+2:f {Q+1, other}
//						[pred] mad[.cond_mod/sat] (8) dst<dst_regioning>:f acc0:nf src0.(src0_offset+1)<0;1,0>:f src1+3 {Q+1, other}
					//(f0.0) pln.sat (8) r8.0<1>:f	r10.0<0;1,0>:f	r2.0<8;8,1>:f
						//(f0.0) pln.sat (16) r8.0<1>:f	r10.0<0;1,0>:f	r2.0<8;8,1>:f {Q1}
						if(src0Offset.equals("")) {
							src0Offset = "0";
						}
						if(dstOffset.equals("")) {
							dstOffset = "0";
						}
						if(other.contains("Compacted")) {
							String[] others = other.substring(1, other.length()-1).split(",");
							if(others.length == 1) {
								other = "";
							} else {
								other = "{";
								for(int i = 0; i < others.length; i++) {
									String s = others[i];
									if(!s.contains("Compacted")) {
										other += s;
										if(i != others.length - 1) {
											other += ", ";
										}
									} else if(i == others.length - 1){
										other = other.substring(0, other.length() - 2);
									}
								}
								other += "}";
							}
						}

						writer.write(pred + " mad (8) acc0" + dstRegioning + ":nf " + src0 + "." + (Integer.parseInt(src0Offset) + 3) + "<0;1,0>:f " 
								+ src0 + "." + src0Offset + "<0;1,0>:f " + src1 + ":f " + other + "\n");
						try {
						writer.write(pred + " mad" + cmod + " (8) " + dst + "." + dstOffset + dstRegioning + ":f acc0:nf " 
								+ src0 + "." + (Integer.parseInt(src0Offset) + 1) + "<0;1,0>:f r" + (Integer.parseInt(src1.substring(1)) + 1) + ":f " + other + "\n");
						}catch(NumberFormatException e) {
							System.out.println(src0Offset);
							System.out.println(src1);
							System.out.println(line);
							System.out.println(file.getAbsolutePath());
						}
						
						if(execSize.equals("(16)") || (execSize.equals("") && defaultExecSize == 16)) {
							if(other.contains("Q3") || other.contains("H2")) {
								other = other.replace("Q3", "Q4").replace("H2", "Q4");
							} else if(other.contains("Q1") || other.contains("H1")) {
								other = other.replace("Q1", "Q2").replace("H1", "Q2");
							} 
							else if(other.equals("")) {
								other = "{Q2}";
							} else {
								other = other.replace("}", ", Q2}");
							}
							
							writer.write(pred + " mad (8) acc0" + dstRegioning + ":nf " + src0 + "." + (Integer.parseInt(src0Offset) + 3) + "<0;1,0>:f " 
									+ src0 + "." + src0Offset + "<0;1,0>:f r" + (Integer.parseInt(src1.substring(1)) + 2) + ":f " + other + "\n");
							writer.write(pred + " mad" + cmod + " (8) r" + (Integer.parseInt(dst.substring(1)) + 1) + "." + dstOffset + dstRegioning + ":f acc0:nf " 
									+ src0 + "." + (Integer.parseInt(src0Offset) + 1) + "<0;1,0>:f r" + (Integer.parseInt(src1.substring(1)) + 3) + ":f " + other + "\n");
						}
						continue;
					}
					writer.write(line + "\n");
				}
				writer.close();
				
				if(hasPln) {
					file.delete();
					fileWrite.renameTo(new File(fileWrite.getAbsolutePath().substring(0, fileWrite.getAbsolutePath().length() - 1)));
				} else {
					fileWrite.delete();
				}
			}
		}
	}
	
	public void findMaxUlp() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\warnings\\PlnDpMismatch.txt"));
		String[] oneOut = new String[7];
		String[] maxOut = new String[7];
		String line = reader.readLine();
		double max = 0;
		double count = 0;
		
		for(int index = 0; line != null; index++, line = reader.readLine()) {
			if(line.isEmpty()) {
				index = -1;
				count++;
				continue;
			}
			
			if(line.startsWith("New") && Integer.parseInt(line.subSequence(12, 19).toString(), 16) == 0) {
				reader.readLine();
				reader.readLine();
				reader.readLine();
				index = -1;
				count++;
				continue;
			}
			
			oneOut[index] = line;
			if(line.startsWith("ULP")) {
				double tmp = Double.parseDouble(line.replace("ULP Error: ", ""));
				if(tmp > max) {
					max = tmp;
					for(int i = 0; i < 7; i++) {
						maxOut[i] = oneOut[i];
					}
				}
			}
		}
		
		System.out.println(count);
		for(int i = 0; i < 7; i++) {
			System.out.println(maxOut[i]);
		}
		
		reader.close();
	}
	
	public int paa(List<String> strings) {
		int ret = 0;
		
		if(strings.size() == 1) {
			return 0;
		}
		
		String tmp = removeDuplicates(strings.get(0));
		for(String string : strings) {
			if(!tmp.equals(removeDuplicates(string))) {
				return -1;
			}
		}
		
		int[][] counts = new int[strings.size()][tmp.length()];
		//Arrays.fill(counts, 0);
		
		for(int i=0; i<strings.size(); i++) {
			String string = strings.get(i);
			char c = string.charAt(0);
			int countIt = 0;
			for(int j=0; j<string.length(); j++) {
				if(string.charAt(j) == c) {
					counts[i][countIt]++;
				} else {
					c = string.charAt(j);
					countIt++;
					counts[i][countIt]++;
				}
			}
		}
		
		int[] median = new int[tmp.length()];
		for(int i=0; i<tmp.length(); i++) {
			int[] ints = new int[strings.size()];
			for(int j=0; j<strings.size(); j++) {
				ints[j] = counts[j][i];
			}
			Arrays.sort(ints);
			median[i] = ints[strings.size()/2];
		}
		
		for(int i=0; i<strings.size(); i++) {
			for(int j=0; j<tmp.length(); j++) {
				ret += Math.abs(counts[i][j] - median[j]);
			}
		}
		
		return ret;
	}

	public static String removeDuplicates(String s)
	{
	    StringBuilder sb = new StringBuilder();
	    if (s.length() > 0) {
	        char prev = s.charAt(0);
	        sb.append(prev);
	        for (int i = 1; i < s.length(); ++i) {
	            char cur = s.charAt(i);
	            if (cur != prev) {
	                sb.append(cur);
	                prev = cur;
	            }
	        }
	    }
	    return sb.toString();
	}

	private class Node {
		public int value;
		public List<Node> connections = new ArrayList<Node>();
		
		public Node(int value) {
			this.value = value;
		}
		
	}
	
	public int nodeNoKeep(Node root, Node node) {
		int min = Integer.MIN_VALUE;
		int min1 = Integer.MIN_VALUE;
		int min2 = Integer.MIN_VALUE;
		
		if(node.connections.size() == 1 || node.connections.size() == 2) {
			return 1;
		}
		
		for(Node childNode : node.connections) {
			if(childNode.value != root.value) {
				int tmp = nodeNoKeep(node, childNode);
				if(tmp > min1 && tmp > min2) {
					min1 = min2;
					min2 = tmp;
				} else if(tmp > min1) {
					min1 = tmp;
				}
			}
		}
		
		if(min1 + min2 > min) {
			min = min1 + min2;
		}
		
		return min + 1;
	}
	
	public int pb(List<Node> nodes) {
		int min = Integer.MIN_VALUE;
		
		if(nodes.size() == 1) {
			return 0;
		} else if(nodes.size() == 2) {
			return 1;
		}
		
		for(Node node : nodes) {
			int min1 = Integer.MIN_VALUE;
			int min2 = Integer.MIN_VALUE;
			
			if(node.connections.size() >= 2) {
				for(Node childNode : node.connections) {
					int tmp = nodeNoKeep(node, childNode);
					if(tmp > min1 && tmp > min2) {
						min1 = min2;
						min2 = tmp;
					} else if(tmp > min1) {
						min1 = tmp;
					}
				}
				if(min1 + min2 > min) {
					min = min1 + min2;
				}
				
			}
		}
		
		return nodes.size() - min - 1;
	}
	
	private class Outlet implements Comparable<Outlet>{
		public Long i;

		@Override
		public int compareTo(Outlet g) {
			return count_bits(i) - count_bits(g.i);
		}

		public Outlet(Long i) {
			this.i = i;
		}
	}
	
	public int pa(List<Long> src, List<Long> dst) {
		Collections.sort(src);
		Collections.sort(dst);
		if(src.equals(dst)) {
			return 0;
		}
		
		List<Outlet> xor = new ArrayList<Outlet>();
		
		for(Long s : src) {
			for(Long d : dst) {
				xor.add(new Outlet(s ^ d));
			}
		}
		
		Collections.sort(xor);
		
		for(Outlet x : xor) {
			List<Long> tmp = new ArrayList<Long>();
			for(Long s : src) {
				tmp.add(x.i ^ s);
			}
			Collections.sort(tmp);
			if(tmp.equals(dst)) {
				return count_bits(x.i);
			}
		}
		
		return -1;
	}
	
	int count_bits(long n) {     
		   int c; // c accumulates the total bits set in v
		  for (c = 0; n != 0; c++) 
		    n &= n - 1; // clear the least significant bit set
		  return c;
		}
	
	private class EarthPosition {
		public int row;
		public int column;
		String direction;
		
		public EarthPosition(int row, int column, String direction) {
			this.row = row;
			this.column = column;
			this.direction = direction;
		}
		
		public EarthPosition() {}
	}
	
	public int getFoodCount(int rowMax, int columnMax, Boolean[][] rockPositions, EarthPosition retPos) {
		int ret = 0;
		String[] directions = {"E", "N", "S", "W"};
		
		for(int i=0; i<rowMax; i++) {
			for(int j=0; j<columnMax; j++) {
				if(rockPositions[i][j]) {
					continue;
				}
				
				for(int k=0; k<4; k++) {
					Boolean[][] usedPositions = new Boolean[rockPositions.length][rockPositions[0].length];
					copyTwoDimArray(rockPositions, usedPositions);
					
					int food = 1;
					EarthPosition position = new EarthPosition(i, j, directions[k]);
					usedPositions[i][j] = true;
					int dirIndex, rowIt, columnIt;
					boolean first = true;
					while(true) {
						if(position.direction.equals("E")) {
							dirIndex = 0;
							rowIt = 0;
							columnIt = 1;
						} else if(position.direction.equals("S")) {
							dirIndex = 1;
							rowIt = 1;
							columnIt = 0;
						} else if(position.direction.equals("W")) {
							dirIndex = 2;
							rowIt = 0;
							columnIt = -1;
						} else {
							dirIndex = 3;
							rowIt = -1;
							columnIt = 0;
						}
						
						if(first) {
							first = false;
							if(!isPosLegal(i + rowIt, j + columnIt, rowMax, columnMax, rockPositions)) {
								break;
							}
						}
						
						if(stepNext(position, dirIndex, rowIt, columnIt, rowMax, columnMax, usedPositions)) {
							food++;
						} else {
							if(food > ret) {
								ret = food;
								retPos.row = i;
								retPos.column = j;
								retPos.direction = directions[k];
							}
							break;
						}
					}
				}
			}
		}
		
		return ret;
	}
	
	public boolean stepNext(EarthPosition position, int dirIndex, int rowIt, int columnIt, int rowMax, int columnMax, Boolean[][] usedPositions) {
		String[] directions = {"E", "S", "W", "N"};
		if(!isPosLegal(position.row + rowIt, position.column + columnIt, rowMax, columnMax, usedPositions)) {
			if(isPosLegal(position.row - columnIt, position.column + rowIt, rowMax, columnMax, usedPositions)) {
				position.row -= columnIt;
				position.column += rowIt;
				position.direction = directions[(dirIndex - 1 + directions.length) % directions.length];
				usedPositions[position.row][position.column] = true;
			} else if(isPosLegal(position.row + columnIt, position.column - rowIt, rowMax, columnMax, usedPositions)){
				position.row += columnIt;
				position.column -= rowIt;
				position.direction = directions[(dirIndex + 1) % directions.length];
				usedPositions[position.row][position.column] = true;
			} else {
				return false;
			}
		} else {
			position.row += rowIt;
			position.column += columnIt;
			usedPositions[position.row][position.column] = true;
		}
		return true;
	}
	
	public boolean isPosLegal(int row, int column, int rowMax, int columnMax, Boolean[][] rockPositions) {
		return row < rowMax && row >= 0 && column < columnMax && column >= 0 && (!rockPositions[row][column]);
	}
	
	
	private class GasStation implements Comparable<GasStation>{
		public int position;
		public int gas;
		public boolean cw;
		public boolean ccw;

		@Override
		public int compareTo(GasStation g) {
			return position - g.position;
		}

		public GasStation(int position, int gas) {
			this.position = position;
			this.gas = gas;
			cw = true;
			ccw = true;
		}
	}
	
	public String tankALot(GasStation[] stations, int totalGas) {
		String ret = "";
		boolean[] cw = new boolean[stations.length];
		boolean[] ccw = new boolean[stations.length];
		Arrays.fill(cw, true);
		Arrays.fill(ccw, true);
		
		int lastGas = totalGas - stations[stations.length - 1].position + stations[0].position;

		for(int i=0; i<stations.length; i++) {
			int currentPos = i;
			int gasInTank = 0;
			for(int j=0; j<stations.length; j++) {
				int gasNeeded = 0;
				if(currentPos + 1 == stations.length) {
					gasNeeded = lastGas;
				} else {
					gasNeeded = stations[currentPos + 1].position - stations[currentPos].position;
				}
				gasInTank += stations[currentPos].gas;
				if(gasInTank < gasNeeded) {
					cw[i] = false;
					break;
				}
				gasInTank -= gasNeeded;
				currentPos++;
				currentPos %= stations.length;
			}
		}
		
		for(int i=0; i<stations.length; i++) {
			int currentPos = i;
			int gasInTank = 0;
			for(int j=0; j<stations.length; j++) {
				int gasNeeded = 0;
				if(currentPos - 1 == -1) {
					gasNeeded = lastGas;
				} else {
					gasNeeded = stations[currentPos].position - stations[currentPos - 1].position;
				}
				gasInTank += stations[currentPos].gas;
				if(gasInTank < gasNeeded) {
					ccw[i] = false;
					break;
				}
				gasInTank -= gasNeeded;
				currentPos--;
				currentPos = (currentPos + stations.length) % stations.length;
			}
		}
		
		for(int i=0; i<stations.length; i++) {
			if(cw[i] && ccw[i]) {
				ret += stations[i].position + " CCC ";
			} else if(cw[i]) {
				ret += stations[i].position + " C ";
			} else if(ccw[i]) {
				ret += stations[i].position + " CC ";
			}
		}
		
		return ret.trim();
	}
	
	
	public String[] lcr(int playerNo, String diceRoll) {
		String[] ret = new String[playerNo + 1];
		int[] chips = new int[playerNo + 1];
		Arrays.fill(chips, 3);
		chips[playerNo] = 0;
		int currentPlayer = 0;
		int winner = -1;
		
		for(int i=0; i<playerNo; i++) {
			ret[i] = "Player " + (i + 1) + ":";
		}
		ret[playerNo] = "Center:";
		
		for(int i=0; i<diceRoll.length();) {
			int tmp = i + (chips[currentPlayer] > 3 ? 3 : chips[currentPlayer]);
			if(tmp > diceRoll.length()) {
				break;
			}
			
			for(; i<tmp; i++) {
				if(diceRoll.charAt(i) == 'L') {
					chips[currentPlayer]--;
					chips[(currentPlayer + 1) % playerNo]++;
				} else if(diceRoll.charAt(i) == 'R') {
					chips[currentPlayer]--;
					chips[(currentPlayer - 1 + playerNo) % playerNo]++;
				} else if(diceRoll.charAt(i) == 'C') {
					chips[currentPlayer]--;
					chips[playerNo]++;
				}
			}
			
			boolean gotWinner = true;
			boolean firstNotZero = false;
			int tmpWinner = -1;
			for(int j=0; j<playerNo; j++) {
				if(chips[j] != 0 && !firstNotZero) {
					firstNotZero = true;
					tmpWinner = j;
				} else if(chips[j] != 0) {
					gotWinner = false;
					break;
				}
			}
			if(gotWinner) {
				winner = tmpWinner;
				currentPlayer = -1;
				break;
			}
			
			currentPlayer++;
			currentPlayer %= playerNo;
		}
		
		int nextPlayer = currentPlayer;
		if(winner == -1) {
			for(int i=0; i<playerNo; i++) {
				if(chips[nextPlayer] != 0) {
					break;
				}
				nextPlayer++;
				nextPlayer %= playerNo;
			}
		}
		
		for(int i=0; i<playerNo; i++) {
			ret[i] += chips[i];
			if(winner == i) {
				ret[i] += "(W)";
			} else if(nextPlayer == i) {
				ret[i] += "(*)";
			}
		}
		ret[playerNo] += chips[playerNo];
		
		return ret;
	}
	
	public boolean guessSudoku(Integer[][] input) {
		boolean zeroFound = false;
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				if(input[i][j] == 0) {
					zeroFound = true;
					for(int k=1; k<=9; k++) {
						Integer[][] copy = new Integer[9][9];
						copyTwoDimArray(input, copy);
						copy[i][j] = k;
						if(guessSudoku(copy)) {
							copyTwoDimArray(copy, input);
							return true;
						}
					}
				}
			}
		}
		
		if(!zeroFound) {
			return testSudoku(input);
		}
		
		return false;
	}
	
	public <T> void copyTwoDimArray(T[][] input, T[][] output) {
		for(int i=0; i<input.length; i++) {
			output[i] = Arrays.copyOf(input[i], input[i].length);
		}
	}
	
	public boolean testSudoku(Integer[][] input) {
		for(int i=0; i<9; i++) {
			Set<Integer> nums1 = new HashSet<Integer>();
			Set<Integer> nums2 = new HashSet<Integer>();
			for(int j=0; j<9; j++) {
				nums1.add(input[i][j]);
				nums2.add(input[j][i]);
			}
			if(nums1.size() < 9 || nums2.size() < 9) {
				return false;
			}
		}
		
		for(int i=0; i<3; i+=3) {
			for(int j=0; j<3; j+=3) {
				Set<Integer> nums = new HashSet<Integer>();
				for(int k=i; k<i+3; k++) {
					for(int l=j; l<j+3; l++) {
						nums.add(input[k][l]);
					}
				}
				if(nums.size() < 9) {
					return false;
				}
			}
		}
		
		return true;
	}
	
	public int deceifulWar(List<Double> naomi, List<Double> ken) {
		int ret = 0;
		List<Double> naomiCopy = new ArrayList<Double>(naomi);
		List<Double> kenCopy = new ArrayList<Double>(ken);
		Collections.sort(naomiCopy);
		Collections.sort(kenCopy);
		for(Double k : kenCopy) {
			for(Double n : naomiCopy) {
				if(n > k) {
					naomiCopy.remove(n);
					ret++;
					break;
				}
			}
		}
		return ret;
	}
	
	public int war(List<Double> naomi, List<Double> ken) {
		int ret = 0;
		Collections.sort(naomi);
		Collections.sort(ken);
		for(Double n : naomi) {
			for(Double k : ken) {
				if(k > n) {
					ken.remove(k);
					ret++;
					break;
				}
			}
		}
		return naomi.size() - ret;
	}
	
	public double cookieFarm(double farmValue, double farmYield, double goal, double cookieSpeed) {
		double time = 0;
		while(goal/cookieSpeed > farmValue / cookieSpeed + goal / (cookieSpeed + farmYield)) {
			time += farmValue /cookieSpeed;
			cookieSpeed += farmYield;
			//cookieFarm(farmValue, farmYield, goal, cookieSpeed + farmYield, time + farmValue/cookieSpeed);
		}
		
		return time + goal/cookieSpeed;
	}
	
	public String magician(int[][] first, int firstRow, int[][] second, int secondRow) {
		int selected = -1;
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				if(first[firstRow][i] == second[secondRow][j]) {
					if(selected != -1) {
						return "Bad magician!";
					} else {
						selected = first[firstRow][i];
					}
				}
			}
		}
		if(selected == -1) {
			return "Volunteer cheated!";
		} else {
			return Integer.toString(selected);
		}
	}
	
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
    	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    	if(num.length == 2) {
    		ArrayList<Integer> tmp = new ArrayList<Integer>();
    		tmp.add(num[0]);
    		tmp.add(num[1]);
    		ArrayList<Integer> tmp1 = new ArrayList<Integer>();
    		tmp1.add(num[1]);
    		tmp1.add(num[0]);
    		ret.add(tmp);
    		ret.add(tmp1);
    	} else {
    		ArrayList<ArrayList<Integer>> tmp = permute(Arrays.copyOf(num, num.length-1));
    		for(ArrayList<Integer> list : tmp) {
    			for(int i=0; i<num.length; i++) {
    				ret.add(new ArrayList<Integer>(list));
    			}
    		}

    		for(int i=0; i<tmp.size(); i++) {
    			for(int j=0; j<num.length; j++) {
    				ret.get(j + i*num.length).add(j, num[num.length-1]);
    			}
    		}
    	}
    	return ret;
    }
	
	public class TreeLinkNode {
		int val;
		TreeLinkNode left, right, next;
		TreeLinkNode(int x) { val = x; }
	}
	
    public void populatingNextRightPointersInEachNode(TreeLinkNode root) {
        root.next = null;
        populatingNextRightPointers(root.left);
        populatingNextRightPointers(root.right);
    }
    
    public void populatingNextRightPointers(TreeLinkNode node) {
    	if(node.left == null) {
    		return;
    	}
        node.left.next = node.right;
        if(node.next != null) {
        	node.right.next = node.next.left;
        } else {
        	node.right.next = null;
        }
        populatingNextRightPointers(node.left);
        populatingNextRightPointers(node.right);
    }
	
	private class RobotPos {
		public int x;
		public int y;
		public RobotDir dir;
		
		public RobotPos(int x, int y, RobotDir dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	};
	
	enum RobotDir {
		North,
		South,
		East,
		West
	};
	
	private void robotMaze(String[][] maze, RobotPos last) {
		RobotPos next = new RobotPos(last.x, last.y, last.dir);
		switch(last.dir) {
		case North:
			next.y--;
			break;
		case South:
			next.y++;
			break;
		case East:
			next.x++;
			break;
		case West:
			next.x--;
			break;
		}
	}
	
	private RobotPos nextStep(RobotPos last) {
		RobotPos ret = new RobotPos(last.x, last.y, last.dir);
		switch(last.dir) {
		case North:
			ret.y--;
			break;
		case South:
			ret.y++;
			break;
		case East:
			ret.x++;
			break;
		case West:
			ret.x--;
			break;
		}
		
		return ret;
	}
	
	private void sortBooks(int[] dadOrder) {
		List<Integer> oddBooks = new ArrayList<Integer>();
		List<Integer> evenBooks = new ArrayList<Integer>();
		for(int value : dadOrder) {
			if(value % 2 != 0) {
				oddBooks.add(value);
			} else {
				evenBooks.add(value);
			}
		}
		
		Collections.sort(oddBooks);
		Collections.sort(evenBooks);
		Collections.reverse(evenBooks);
		Iterator<Integer> oddIt = oddBooks.iterator();
		Iterator<Integer> evenIt = evenBooks.iterator();
		
		for(int i=0; i<dadOrder.length; i++) {
			if(dadOrder[i] % 2 != 0) {
				dadOrder[i] = oddIt.next();
			} else {
				dadOrder[i] = evenIt.next();
			}
		}
	}
	
	private void parseLinuxWarningFile() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\warnings\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\warnings\\out.txt"));
		BufferedWriter statisticWriter = new BufferedWriter(new FileWriter("C:\\warnings\\statistic.csv"));
		BufferedReader fileFilter = new BufferedReader(new FileReader("C:\\warnings\\fileFilter.txt"));
		BufferedReader typeFilter = new BufferedReader(new FileReader("C:\\warnings\\typeFilter.txt"));
		
		final String vsMarker = "): warning C";
		final String gccMarker = " [-Werror=";
		
		Set<String> cppFiles = new HashSet<String>();	
		while(true) {
			String line = fileFilter.readLine();
			if(line == null) {
				break;
			}
			if(!line.trim().isEmpty()) {
				cppFiles.add(line.trim().toLowerCase());
			}
		}
		
		Map<String, Integer> warningTypes = new TreeMap<String, Integer>();	
		while(true) {
			String line = typeFilter.readLine();
			if(line == null) {
				break;
			}
			if(!line.trim().isEmpty()) {
				warningTypes.put(line.trim().toLowerCase(), 0);
			}
		}
		
		Set<String> outputLines = new LinkedHashSet<String>();
		while(true) {
			String line = reader.readLine();
			if(line == null) {
				break;
			}

			if(line.indexOf('>') != -1 && line.indexOf('>') < 5) {
				line = line.substring(line.indexOf('>') + 1);
			}
			
			if(!line.startsWith(" ") && (line.contains(vsMarker) || line.contains(gccMarker))) {
				if(doesStringIncluded(cppFiles, line) && doesStringIncluded(warningTypes.keySet(), line)) {
					outputLines.add(line);
				}
			}
		}
		
		Map<String, String> examples = new HashMap<String, String>();	
		for(String line : outputLines) {
			String warningType = "";
			if(line.contains(vsMarker)) {
				int begin = line.indexOf(vsMarker) + 11;
				int end = line.indexOf(':', begin);
				warningType = line.substring(begin, end).toLowerCase();
			} else if(line.contains(gccMarker)) {
				int begin = line.indexOf(gccMarker) + 10;
				int end = line.indexOf(']', begin);
				warningType = line.substring(begin, end).toLowerCase();
			} else {
				continue;
			}
			
			if(warningTypes.containsKey(warningType)) {
				warningTypes.put(warningType, warningTypes.get(warningType) + 1);
			} else {
				warningTypes.put(warningType, 1);
			}
			
			if(!examples.containsKey(warningType)) {
				examples.put(warningType, line);
			}
			
			writer.write(line + "\n");
		}
		
		statisticWriter.write("WarningType,Number,Example\n");
		for(Entry<String, Integer> pair : warningTypes.entrySet()) {
			statisticWriter.write(pair.getKey() + "," + pair.getValue() + ",\"" + examples.get(pair.getKey()) + "\"\n");
		}
		statisticWriter.write("Total," + outputLines.size() + "\n");
		
		reader.close();
		writer.close();
		fileFilter.close();
		typeFilter.close();
		statisticWriter.close();
	}
	
	private boolean doesStringIncluded(Set<String> cppFiles, String line) {
		if(cppFiles.size() != 0) {
			for(String cppFile : cppFiles) {
				if(line.toLowerCase().contains(cppFile)) {
					return true;
				}
			}
		} else {
			return true;
		}
		return false;
	}
	
	private void parseWarningFile2() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt"));
		BufferedReader ref = new BufferedReader(new FileReader("C:\\share\\warnings\\ref2.txt"));
		
		List<String> warnings = new ArrayList<String>();
		
		while(true) {
			String line = ref.readLine();
			if(line == null) {
				break;
			}
			warnings.add(line);
		}
		
		while(true) {
			String line = reader.readLine();
			if(line == null) {
				break;
			}
			
			boolean breakout = false;
			for(String warning : warnings) {
				if(line.contains(warning)) {
					breakout = true;
					break;
				}
			}
			
			if(!breakout) {
				writer.write(line + "\n");
			}
		}
		
		ref.close();
		reader.close();
		writer.close();
	}
	
	private void parseWarningFile() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt"));
		
//		BufferedReader ref = new BufferedReader(new FileReader("C:\\share\\ref.txt"));	
//		List<String> warnings = new ArrayList<String>();	
//		while(true) {
//			String line = ref.readLine();
//			if(line == null) {
//				break;
//			}
//			warnings.add(line.trim());
//		}
//		String[] checkFiles = new String[warnings.size()];
//		warnings.toArray(checkFiles);
		
		String[] checkFiles = {"EuExecUnit", "EuExtMath", "EuFpu", "EuFpuEmBase", "EuGa", "EuJEu", "EuKernelPerf", "EuManager", "EuMessageSend", "EuTc", "EuUtility", "DecodeInst"};

		for(int i=0; i<checkFiles.length; i++) {
			checkFiles[i] = checkFiles[i].toLowerCase();
		}
		
//		boolean doesWrite = false;
		
		while(true) {
			String line = reader.readLine();
			if(line == null) {
				break;
			}
			
//			if(line.contains("error")) {
//				for(String checkFile : checkFiles) {
//					if(line.toLowerCase().contains(checkFile)) {
//						writer.write(line + "\n");
//						break;
//					}
//				}
//			}
		

			if(line.indexOf('>') != -1 && line.indexOf('>') < 5) {
				line = line.substring(line.indexOf('>') + 1);
			}
			
			if(!line.startsWith(" ") && line.contains("warning")) {
				for(String checkFile : checkFiles) {
					if(line.toLowerCase().contains(checkFile)) {
						writer.write(line + "\n");
						break;
					}
				}
			}
			
//			if(!line.startsWith(" ")) {
//				for(String checkFile : checkFiles) {
//					if(line.toLowerCase().contains(checkFile)) {
//						if(!line.contains("in switch of enum") && !line.contains("conversion from") && !line.contains("is not defined as a preprocessor macro")
//								&& !line.contains("unreferenced inline function has been removed") && !line.contains("bytes padding added after data member")
//								&& !line.contains("conditional expression is constant") && !line.contains("signed/unsigned mismatch")) {
//							writer.write(line + "\n");
//							break;
//						}
//					}
//				}
//			}
			
//			if(!line.matches(".*(\\d.).*") && doesWrite) {
//				writer.write(line);
//			} else if(line.matches(".*(\\d.).*")) {
//				doesWrite = false;
//				for(String checkFile : checkFiles) {
//					if(line.toLowerCase().contains(checkFile)) {
//						doesWrite = true;
//						writer.write("\n" + line);
//						break;
//					}
//				}
//			}
		}
		
		reader.close();
		writer.close();
	}
	
//	private void recursiveCopyDir(File src, File dst) throws IOException {
//		Files.copy(src.toPath(), dst.toPath());
//		if(src.isDirectory()) {
//			for(String fileName : src.list()) {
//				recursiveCopyDir(new File(src, fileName), new File(dst, fileName));
//			}
//		}
//	}
//	
//	private BufferedWriter getFpuDumpWritter(int subfix, String exampleTcPath) throws IOException {
//		String tmp = exampleTcPath;
//		if(subfix >= 10) {
//			tmp = exampleTcPath.substring(0, exampleTcPath.length() - 1);
//		}
//		recursiveCopyDir(new File(exampleTcPath), new File(tmp + subfix));
//		return new BufferedWriter(new FileWriter(tmp + subfix + "/fd3d/EuGaEmFpu.txt"));
//	}
//	
//	private void valgrindParse() throws IOException {
//		final int max = 100000;
//		int subfix = 1;
//		String exampleTcPath = "C:/share/eu_op_pln_coverage_00";
//		BufferedReader reader = new BufferedReader(new FileReader("C:/share/pln.txt"));
//		List<String> paders = new ArrayList<String>();
//		List<List<String>> testNums = new ArrayList<List<String>>();
//		for(int i=0; i<5; i++) {
//			testNums.add(new ArrayList<String>());
//		}
//		
//		boolean notFinish = true;
//		while(notFinish) {
//			int lineCount = 0;
//			while(lineCount != max) {
//				String line = reader.readLine();
//				if(line == null) {
//					notFinish = false;
//					break;
//				}
//
//				if(line.charAt(0) == '#') {
//					continue;
//				}
//				lineCount++;
//				String[] tokens = line.split(" ");
//				for(int i=0; i<5; i++) {
//					testNums.get(i).add(tokens[i+2]);
//				}
//			}
//			
//			if(lineCount == 0) {
//				break;
//			}
//			
//			BufferedWriter writer = getFpuDumpWritter(subfix++, exampleTcPath);
//			writeFpuDumpComment(writer, paders);
//			for(int i=0; i<testNums.get(0).size()/4; i++) {
//				for(int j=0; j<5; j++) {
//					writer.write(paders.get(j));
//					writer.write("00000000000000000000000000000000");
//					for(int k=0; k<4; k++) {
//						if(j == 0) {
//							writer.write(testNums.get(4).get(i*4+k));
//						} else {
//							writer.write(testNums.get(j-1).get(i*4+k));	
//						}
//					}
//					writer.write(" ");
//				}
//				writer.write(paders.get(5) + "\n");
//			}
//			writer.write("END");
//			writer.close();
//
//			for(int k=0; k<5; k++) {
//				testNums.get(k).clear();
//			}
//		}
//		
//		reader.close();
//	}

	private void writeFpuDumpComment(BufferedWriter writer, List<String> paders) throws FileNotFoundException, IOException {
		boolean doesWritePad = paders.size() == 0;
		BufferedReader commentReader = new BufferedReader(new FileReader("C:/share/EuGaEmFpu10.txt"));
		while(true) {
			String line = commentReader.readLine();
			if(!line.startsWith("--")) {
				String[] tokens = line.split(" ");
				String acc = "";
				for(String token : tokens) {
					if(token.length() < 60) {
						acc += token + " ";
					}
					else if(doesWritePad) {
						paders.add(acc);
						acc = "";
					}
				}
				if(doesWritePad) {
					paders.add(acc);
				}
				break;
			}
			writer.write(line + "\n");
		}
		commentReader.close();
	}
	
	private void giantCount(String res) {
		int w = 0;
		for(int i=0; i<res.length(); i++) {
			char c = res.charAt(i);
			if(c == 'W') {
				w++;
			}
		}
		System.out.print("Win %:");
		System.out.println((double)w/res.length());
	}
	
	private void giantParsing(String res, int play) {
		Queue<Character> games = new LinkedList<Character>();
		int lose = 0;
		int maxLose = 0;
		String ls = "";
		for(int i=0; i<res.length(); i++) {
			char c = res.charAt(i);
			games.add(c);
			if(c == 'L') {
				lose++;
			}
			
			if(i + 1 > play) {
				if(games.remove() == 'L') {
					lose--;
				}
				if(lose > maxLose) {
					maxLose = lose;
					Iterator<Character> it = games.iterator();
					ls = "";
					while(it.hasNext()) {
						ls += it.next();
					}
				}
			} else if(i + 1 == play) {
				maxLose = lose;
			}
		}
		
		System.out.print("Min Win %: ");
		System.out.println(((double)play - maxLose) / play);
		System.out.println(ls);
		
		/*List<Integer> resList = new ArrayList<Integer>();
		int i=0, sum=0;
		while(true) {
			while(i < res.length() && res.charAt(i) == 'W') {
				i++;
				sum++;
			}
			if(i != 0) {
				resList.add(sum);
				sum = 0;
			}
			if(i == res.length()) {
				break;
			}
			while(i < res.length() && res.charAt(i) == 'L') {
				i++;
				sum--;
			}
			if(i != 0) {
				resList.add(sum);
				sum = 0;
			}
			if(i == res.length()) {
				break;
			}
		}*/
	}

	
	private void parseRegression() throws IOException {
//		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\test.csv"));
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\CHV_regression_stat ww12_2.csv"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.csv"));
		
		String title[] = {"MovInst","Flt2Int", "Int2Flt", "MixFloat", "MixInt", "Compacted","Compressed", "AlignMode", "RndMode", "DenormModeHp", "DenormModeSp",
				"DenormModeDp", "Saturate", "Simd8ShootDown","AccuSrc", "AccuDstImp", "AccuDstExp", "Src0Denorm", "Src1Denorm", "DstDenorm", "SrcModUsed", "CondModUsed",
				"PredicateUsed", "PredCtrl","NumberSources","ImmediateSrc","SrcRepCtrl","DstType", "Src0Type", "Src1Type", "Src2Type", "DstIndexed", "Src0Indexed",
				"Src1Indexed", "DstRegFile", "Src0RegFile", "Src1RegFile", "DstGrfAligned", "Src0GrfAligned", "Src1GrfAligned","Src0Grfs", "Src1Grfs", "Underflow",
				"Overflow", "Inexact", "InvalidOp", "DivByZero","ExecutionSize","FromPrevIpCount","ToNextIpCount","ExecutionCount"};
		
		List<String> outputTitles = new ArrayList<String>(Arrays.asList(title));
		Set<String> additionalTitles = new TreeSet<String>();

		reader.readLine();
		String cline = "";
		while((cline = reader.readLine()) != null) {
			String[] tokens = cline.split(",");
			if(tokens.length < 3) {
				continue;
			}
			for(int i=0; i<title.length; i++) {
				if(tokens.length <= i+3) {
					break;
				}
				try {
					Integer.parseInt(tokens[i+3]);
				} catch(NumberFormatException e) {
					additionalTitles.add(title[i] + "_" + tokens[i+3]);
				}
			}
		}
		reader.close();
		
		for(Iterator<String> it = additionalTitles.iterator(); it.hasNext(); ) {
			outputTitles.add(it.next());
		}
		
//		writer.write("Op,");
//		for(Iterator<String> it = outputTitles.iterator(); it.hasNext(); ) {
//			writer.write(it.next() + ",");
//		}

//		reader = new BufferedReader(new FileReader("C:\\share\\test.csv"));
		reader = new BufferedReader(new FileReader("C:\\share\\CHV_regression_stat ww12_2.csv"));
		Map<String, int[]> opMaps = new HashMap<String, int[]>();
		
		reader.readLine();
		while((cline = reader.readLine()) != null) {
			String[] tokens = cline.split(",");
			if(tokens.length < 3) {
				continue;
			}
			
			if(!opMaps.containsKey(tokens[2])) {
				opMaps.put(tokens[2], new int[outputTitles.size()]);
			}
			
			for(int i=0; i<title.length; i++) {
				if(tokens.length <= i+3) {
					break;
				}
				try {
					opMaps.get(tokens[2])[i] += Integer.parseInt(tokens[i+3]);
				} catch(NumberFormatException e) {
					try {
						String tmp = title[i] + "_" + tokens[i+3];
						for(int j=0; j<outputTitles.size(); j++) {
							if(outputTitles.get(j).equals(tmp)) {
								opMaps.get(tokens[2])[j]++;
								break;
							}
						}
					} catch(NullPointerException e1) {
						e1.printStackTrace();
					}
				}
			}
		}
		
		writer.write("Op,");
		for(String t : outputTitles) {
			writer.write(t + ",");
		}
		writer.write("\n");
		
		for (Iterator<String> iterator = opMaps.keySet().iterator(); iterator.hasNext();) {
		    String key = (String) iterator.next();
		    int[] properties = opMaps.get(key);
		    writer.write(key + ",");
		    for(int property : properties) {
		    	writer.write(property + ",");
		    }
		    writer.write("\n");
		}
		writer.close();
		reader.close();
	}
	
	private void addTwoNewFieldsToDump() throws IOException {
		File example = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\EU_Weekly\\basic\\eu_pln_f_mp_mp_f_p\\fd3d\\EuGaEmFpu.txt");
		BufferedReader exampleReader = new BufferedReader(new FileReader(example));
		List<String> exampleLines = new ArrayList<String>();
		String cline = "";
		while((cline = exampleReader.readLine()) != null) {
			if(cline.startsWith("--")) {
				exampleLines.add(cline);
			}
		}
		exampleReader.close();
		
		File topDir = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\EU_Weekly\\basic");
		File[] secondDirs = topDir.listFiles();
		for(File secondDir : secondDirs) {
			File inputFile = new File(secondDir.getPath() + "\\fd3d\\EuGaEmFpu.txt");
			BufferedReader reader = new BufferedReader(new FileReader(inputFile));
			List<String> inputLines = new ArrayList<String>();
			while((cline = reader.readLine()) != null) {
				if(!cline.startsWith("--") && !cline.contains("END")) {
					inputLines.add(cline.trim());
				}
			}
			reader.close();
			
			BufferedWriter writer = new BufferedWriter(new FileWriter(inputFile));
			for(String exampleLine : exampleLines) {
				writer.write(exampleLine + "\n");
			}
			for(String inputLine :inputLines) {
				writer.write("  " + inputLine.substring(0, 78) + "0 0 " + inputLine.substring(78) + " 00 0 1\n");
			}
			writer.write("END");
			writer.close();
		}
	}
	
	private void refactorEM() throws IOException {
		File topDir = new File("C:\\Users\\mengbozh\\Desktop\\SVN\\em_basic_10");
		//File topDir = new File("C:\\basic");
		File[] secondDirs = topDir.listFiles();
		for(File secondDir : secondDirs) {
			if(!secondDir.getName().endsWith("hf") && !secondDir.getName().endsWith("hf_f")) {
				continue;
			}
			
			
			FilenameFilter nameFilter = new FilenameFilter() {
				public boolean accept(File dir, String fileName) {
					return fileName.endsWith(".asm") && (!fileName.endsWith("su.asm")) && (!fileName.endsWith("vs.asm"));
				}
			};
			File[] inputs = secondDir.listFiles(nameFilter);
			if(inputs.length == 0) {
				continue;
			}
			File input = secondDir.listFiles(nameFilter)[0];
//			boolean isChanen = secondDir.getName().contains("chanen");
			
			BufferedReader reader = new BufferedReader(new FileReader(input));
			List<String> lines = new ArrayList<String>();
			String cline = "";
			while((cline = reader.readLine()) != null) {
				lines.add(cline);
			}
			reader.close();
			
			BufferedWriter writer = new BufferedWriter(new FileWriter(input));			
//			boolean skip = false;
//			boolean skipDone = false;
			for(int i=0; i<lines.size(); i++) {
				String line = lines.get(i);
//				if(line.equals("//############################################################")) {
//					if(!skip && !skipDone) {
//						i += 2;
//						skip = true;
//						continue;
//					} else {
//						skip = false;
//						skipDone = true;
//					}
//				} else if(skip) {
//					continue;
//				}
				
				if(line.matches(".*// *send.*r\\d.*r\\d.*")) {
					line = line.replaceFirst("//.*", "");
				} else if(line.matches(".*// *Gen6.*")) {
					line = line.replaceFirst("//.*", "");
				}
				
				if(line.matches(".*\\.\\d:hf.*")) {
					line = line.replaceFirst(":hf", "<1>:hf");
				} else if(line.matches(".*-.*any\\dh.*")) {
					line = line.replaceFirst("any", "all");
				}
				
//				if(!isChanen) {
//					if(line.matches(".*\\(\\d\\).*")) {
//						line = line.replaceFirst("\\(\\d\\)", "(8)");
//					} else if(line.matches(".*any\\dh.*")) {
//						line = line.replaceFirst("any\\dh", "all8h");
//					}
//				}	
				writer.write(line + "\n");
			}
			writer.close();
		}
	}
	
	private class pogoPath {
		public int x;
		public int y;
		public int pow;
		public String path;
		
		public pogoPath(int x, int y, int pow, String path) {
			this.x = x;
			this.y = y;
			this.pow = pow;
			this.path = path;
		}
	}

	private String pogo(int dstX, int dstY) {
		Queue<pogoPath> queue = new LinkedList<pogoPath>();
		queue.add(new pogoPath(0, 0, 0, ""));
		char[] fourDir = {'N', 'S', 'E', 'W'}; 
		while(true) {
			pogoPath node = queue.remove();
			if(pogoCheck(dstX, dstY, node)) {
				return node.path;
			}
			for(int i=0; i<4; i++) {
				queue.add(new pogoPath(node.x, node.y, node.pow + 1, node.path + fourDir[i]));
			}
		}
	}

	private boolean pogoCheck(int dstX, int dstY, pogoPath node) {
		if(node.path.length() != 0) {
			char dir = node.path.charAt(node.path.length()-1);
			int pow = node.pow;
	
			switch(dir) {
			case 'E':
				node.x += pow;
				break;
			case 'W':
				node.x -= pow;
				break;
			case 'N':
				node.y += pow;
				break;
			case 'S':
				node.y -= pow;
				break;
			}
		}
		if(node.x == dstX && node.y == dstY) {
			return true;
		}
		return false;
	}
	
	private boolean pogoCheck(int dstX, int dstY, String path) {
		int x=0, y=0, pow=1;
		for(int i=0; i<path.length(); i++) {
			switch(path.charAt(i)) {
			case 'E':
				x += pow;
				break;
			case 'W':
				x -= pow;
				break;
			case 'N':
				y += pow;
				break;
			case 'S':
				y -= pow;
				break;
			}
			pow++;
		}
		if(x == dstX && y == dstY) {
			return true;
		}
		return false;
	}

	private int energyUse(int in, int out, int left, int right, int[] values, int e, int r) {
		int maxE = in - out;
		if(left != values.length-1) {
			maxE += r;
		}

		if(left == right) {
			if(maxE > in) {
				maxE = in;
			}
			int v = maxE * values[left];
			return v < 0 ? 0 : v;
		} else if(right < left) {
			return 0;
		}

		int max = 0;
		int maxIndex = 0;
		for(int i=left; i<=right; i++) {
			if(values[i] > max) {
				max = values[i];
				maxIndex = i;
			}
		}

		if((maxIndex-left) * r + in > e) {
			maxE = e;
		} else if(maxE > e) {
			maxE = e;
		}

		return energyUse(in, maxE, left, maxIndex-1, values, e, r) + max * maxE + energyUse(r, out, maxIndex+1, right, values, e, r);
	}

	private boolean is_palindrome(Long orig) {
		long reversed = 0, n = orig;

		while (n > 0)
		{
			reversed = reversed * 10 + n % 10;
			n /= 10;
		}

		return orig == reversed;
	}

	private boolean lawnmover(int position[][], Integer nums[], int N, int M) {
		for(int num : nums) {
			for(int j=0; j<N; j++) {
				for(int k=0; k<M; k++) {
					if(position[j][k] == num) {
						boolean breakout = false;
						for(int i=0; i<N; i++) {
							if(position[i][k] > num) {
								breakout = true;
								break;
							}
						}
						if(!breakout) {
							continue;
						}

						breakout = false;
						for(int i=0; i<M; i++) {
							if(position[j][i] > num) {
								breakout = true;
								break;
							}
						}

						if(breakout) {
							return false;
						}
					}
				}
			}
		}
		return true;
	}

	private boolean checkPosition(char checkChar, char position[][]) {
		for(int i=0; i<4; i++) {
			boolean breakout = false;
			for(int j=0; j<4; j++) {
				if(position[i][j] != checkChar && position[i][j] != 'T') {
					breakout = true;
					break;
				}
			}
			if(!breakout) {
				return true;
			}

			breakout = false;
			for(int j=0; j<4; j++) {
				if(position[j][i] != checkChar && position[j][i] != 'T') {
					breakout = true;
					break;
				}
			}
			if(!breakout) {
				return true;
			}
		}

		boolean breakout = false;
		for(int i=0; i<4; i++) {
			if(position[i][i] != checkChar && position[i][i] != 'T') {
				breakout = true;
				break;
			}
		}
		if(!breakout) {
			return true;
		}

		breakout = false;
		for(int i=0; i<4; i++) {
			if(position[i][3-i] != checkChar && position[i][3-i] != 'T') {
				breakout = true;
				break;
			}
		}
		if(!breakout) {
			return true;
		}

		return false;
	}



	private class CarPos {
		public double pos;
		public double time;

		public CarPos(double pos, double time) {
			this.pos = pos;
			this.time = time;
		}
	}

	private class Interval {
		public double start;
		public double end;
		public double startTime;
		public double endTime;
		public double speed;
		public double length;
		public double time;

		public Interval(double start, double end, double startTime, double endTime) {
			this.start = start;
			this.end = end;
			this.startTime = startTime;
			this.endTime = endTime;
			speed = (end - start) / (endTime - startTime);
			length = this.end - this.start;
			time = this.endTime - this.startTime;
		}
	}

	private double getB(List<CarPos> positions, double acc, double D) {
		List<Interval> intervals = new ArrayList<Interval>();

		Interval in = new Interval(0.0, positions.get(0).pos, 0.0, positions.get(0).time);
		intervals.add(in);

		for(int i=0; i<positions.size()-1; i++) {
			intervals.add(new Interval(positions.get(i).pos, positions.get(i+1).pos, positions.get(i).time, positions.get(i+1).time));
		}

		double speed = 0;
		double pos = 0;
		double t = 0;
		for(Interval interval : intervals) {
			double maxSpeed = speed + acc * interval.time;
			if(maxSpeed <= interval.speed) {
				double down = speed * interval.time + 0.5 * acc * interval.time * interval.time;
				if(down > (D - pos)) {
					double tmp = ((-2) * speed + Math.sqrt( 4 * speed * speed + 8 * acc * (D - pos))) / 2 * acc;
					return t + tmp;
				} else {
					t += interval.time;
					pos = interval.end;
					speed = maxSpeed;
				}
			} else {
				double t1 = (interval.speed - speed) / acc;
				double t1Down = speed * t1 + 0.5 * acc * t1 * t1;
				double t2Down = interval.speed * (interval.time - t1);
				double dPos = D- pos;
				if(dPos < t1Down) {
					double tmp = ((-2) * speed + Math.sqrt( 4 * speed * speed + 8 * acc * (D - pos))) / 2 * acc;
					return t + tmp;
				} else if(dPos < t1Down+t2Down) {
					return t + t1 + (D-pos-t1Down)/interval.speed;
				} else {
					t+= interval.time;
					pos = interval.end;
					speed = interval.speed;
				}

			}
		}

		return -1;
	}

	private class Product {
		public long quantity;
		public int type;
		public int order;

		public Product(long quantity, int type, int order) {
			this.quantity = quantity;
			this.type = type;
			this.order = order;
		}
	}

	private long getB(List<Product> boxes, LinkedList<Product> toys) {
		long ret = Integer.MIN_VALUE;
		LinkedList<Product> boxesBackup = new LinkedList<Product>(boxes);
		LinkedList<Product> toyBackup = new LinkedList<Product>(toys);

		ArrayList<ArrayList<Product>> orders = new ArrayList<ArrayList<Product>>();
		Set<Integer> types = new HashSet<Integer>();

		for(Product box : boxes) {
			for(Product toy : toys) {
				if(box.type == toy.type) {

				}
			}
		}

		for(Product box : boxes) {
			types.add(box.type);
		}

		int index = 0;
		for(int type : types) {
			orders.add(new ArrayList<Product>());
			for(Product toy : toys) {
				if(toy.type == type) {
					orders.get(index).add(toy);
				}
			}
			index++;
		}

		return ret;
	}

	private String getA(List<ClassNode> nodes) {
		for(ClassNode node : nodes) {
			if(node.childrenNum < 2) {
				continue;
			}
			if(travelNode(nodes, node)) {
				return "Yes";
			}

			for(ClassNode node1 : nodes) {
				node1.visited = false;
			}
		}
		return "No";
	}

	private boolean travelNode(final List<ClassNode> nodes, ClassNode node) {
		if(node.visited) {
			return true;
		}
		node.visited = true;
		if(node.childrenNum == 0) {
			return false;
		}
		for(int cnIndex : node.children) {
			if(travelNode(nodes, nodes.get(cnIndex))) {
				return true;
			}
		}
		return false;
	}

	private class ClassNode {
		public List<Integer> children;
		public int childrenNum;
		public boolean visited;

		public ClassNode() {
			children = new ArrayList<Integer>();
			visited = false;
			childrenNum = 0;
		}
	}

	private void getC(List<Long> nums, List<Long> s1, List<Long> s2) {
		long pos = (long)Math.pow(2, nums.size());
		long sum1 = 0;
		long sum2 = 0;
		for(long i=1; i<pos-1; i++) {
			sum1 = 0;
			String b1 = getBinaryNum(i, nums.size());
			for(int j=0; j<b1.length(); j++) {
				if(b1.charAt(j) == '1') {
					sum1 += nums.get(j);
				}
			}

			for(long j=1; j<pos-1; j++) {
				String b2 = getBinaryNum(j, nums.size());
				sum2 = 0;
				for(int k=0; k<b2.length(); k++) {
					if(b2.charAt(k) == '1') {
						if(b1.charAt(k) == '1') {
							break;
						}
						sum2 += nums.get(k);
						if(sum1 == sum2) {
							for(int l=0; l<b1.length(); l++) {
								if(b1.charAt(l) == '1') {
									s1.add(nums.get(l));
								}
							}

							for(int l=0; l<b2.length(); l++) {
								if(b2.charAt(l) == '1') {
									s2.add(nums.get(l));
								}
							}
							return;
						} else if(sum2 > sum1) {
							break;
						}
					}
				}
			}
		}
	}

	private LinkedList<Double> getA(List<Integer> scores) {
		Integer sum = 0;
		for(Integer score : scores) {
			sum += score;
		}

		return getAHelper(scores, sum * 2);
	}

	private LinkedList<Double> getAHelper(List<Integer> scores, int points) {
		LinkedList<Double> ret = new LinkedList<Double>();
		Double avg = new Double(points) / scores.size();

		Integer sum = 0;
		for(Integer score : scores) {
			sum += score;
		}

		for(int i=0; i<scores.size(); i++) {
			if(avg <= scores.get(i)) {
				points -= scores.get(i);
				scores.remove(i);
				ret = getAHelper(scores, points);
				ret.add(i, new Double(0));
				return ret;
			}
		}
		for(Integer score : scores) {
			ret.add((avg - new Double(score)) / new Double(points - sum) * new Double(100));
		}
		return ret;
	}

	private int getSwitchForBooleanTree(BooleanTreeNode node, int value) {
		if(node.And == -1 || !node.change) {
			return node.value == value ? 0 : -1;
		} else {
			int left1 = getSwitchForBooleanTree(node.left, 1);
			int left0 = getSwitchForBooleanTree(node.left, 0);
			int right1 = getSwitchForBooleanTree(node.right, 1);
			int right0 = getSwitchForBooleanTree(node.right, 0);
			int and = -1;
			int or = -1;

			if(value == 1) {
				and = getSwitchForBooleanTreeHelper(left1, right1);
				if(right1 == -1) {
					or = left1;
				} else if(left1 == -1) {
					or = right1;
				} else {
					or = min(right1, left1);
				}
			} else if(value == 0) {
				if(right0 == -1) {
					and = left0;
				} else if(left0 == -1) {
					and = right0;
				} else {
					and = min(right0, left0);
				}
				or = getSwitchForBooleanTreeHelper(left0, right0);
			}

			if(!node.change) {
				return node.And == 1 ? and : or;
			} else {
				if(node.And == 1) {

				}
			}
		}
		throw new RuntimeException("It's not scientific!");
	}

	private int getSwitchForBooleanTreeHelper(int i, int j) {
		if(i == -1 || j == -1) {
			return -1;
		}
		return i + j;
	}

	private class BooleanTreeNode {
		public int value;
		public int And;
		public boolean change;
		public BooleanTreeNode left;
		public BooleanTreeNode right;

		public BooleanTreeNode(int value, int and) {
			this.value = value;
			this.And = and;
			change = false;
			left = null;
			right = null;
		}
	}

	private List<Integer> getPrimeNum(int max) {
		List<Integer> ret = new ArrayList<Integer>();
		boolean[] nums = new boolean[max+1];
		Arrays.fill(nums, true);
		for(int i=2; i<nums.length/2; i++) {
			int tmp = 2 * i;
			while(tmp < nums.length) {
				nums[tmp] = false;
				tmp += i;
			}
		}
		for(int i=2; i<nums.length; i++) {
			if(nums[i]) {
				ret.add(i);
			}
		}
		return ret;
	}

	private String format(String pattern, double value) {
		DecimalFormat myFormatter = new DecimalFormat(pattern);
		return myFormatter.format(value);
	}

	private int[] getMilkShake(int N, List<Customer> customers) {
		int[] ret = new int[N];
		Arrays.fill(ret, 0);
		boolean flag = true;
		while(flag) {
			flag = false;
			for(Customer customer : customers) {
				if(!customer.getMalt && customer.unmaltNum == 0) {
					if(customer.malt == -1) {
						return null;
					}

					int turnMalted = customer.malt;
					ret[turnMalted] = 1;
					customer.getMalt = true;

					for(Customer customer1 : customers) {
						if(customer1.malt == turnMalted) {
							customer1.getMalt = true;
						} else if(customer1.unmalt.contains(turnMalted)) {
							customer1.unmaltNum--;
						}
					}
					flag = true;
					break;
				}
			}
		}
		return ret;
	}

	private class Customer {
		public int malt;
		public List<Integer> unmalt;
		public boolean getMalt;
		public int unmaltNum;

		public Customer(int malt, List<Integer> unmalt) {
			this.malt = malt;
			this.unmalt = new ArrayList<Integer>(unmalt);
			getMalt = false;
			unmaltNum = unmalt.size();
		}

		public Customer(List<Integer> unmalt) {
			this(-1, unmalt);
		}
	}

	private long getMinScalarProduct(long[] xs, long[] ys) {
		Arrays.sort(xs);
		Arrays.sort(ys);
		long min = 0;
		for(int i=0; i<xs.length; i++) {
			min += xs[i] * ys[xs.length - 1 - i];
		}
		return min;
	}

	private int getB(LinkedList<Level> levels) {
		Collections.sort(levels);
		int star = 0;
		int trial = 0;
		boolean flag = false;

		while(!levels.isEmpty()) {
			if(levels.get(0).bi <= star) {
				if(levels.get(0).doneA) {
					star++;
				} else {
					star += 2;
				}
				trial++;
				levels.removeFirst();
			} else {
				for(int i= levels.size()-1; i>=0; i--) {
					if(levels.get(i).ai <= star && !levels.get(i).doneA) {
						star += 1;
						trial++;
						levels.get(i).doneA = true;
						flag = true;
						break;
					}
				}
				if(flag) {
					flag = false;
					continue;
				}
				return -1;
			}
		}

		return trial;
	}

	private class Level implements Comparable<Level>{
		public int ai;
		public int bi;
		public boolean doneA;

		@Override
		public int compareTo(Level o) {
			return bi - o.bi;
		}

		public Level(int ai, int bi) {
			this.ai = ai;
			this.bi = bi;
			doneA = false;
		}
	}

	private Double getA(int A, int B, List<Double> possibs) {
		Double third = new Double(A + B + 1);
		Double forth = new Double(B + 2);
		Double min = third > forth ? forth : third;
		for(int i=0; i<A; i++) {
			Double sum = new Double(1);

			Double pos1 = possibs.get(A - i);
			if(i > 0) {
				pos1 += possibs.get(A);
			}
			int key1 = i + B - A + i + 1;

			Double pos2 = new Double(1) - pos1;
			int key2 = key1 + B + 1;

			sum = pos1 * key1 + pos2 * key2;

			if(sum < min) {
				min = sum;
			}
		}
		return min;
	}

	private List<Double> getPossibility(List<Double> Ais) {
		List<Double> times = new ArrayList<Double>();
		times.add(new Double(1));
		for(int i=0; i<Ais.size(); i++) {
			times.add(times.get(i) * Ais.get(i));
		}

		List<Double> poss = new ArrayList<Double>();
		for(int i=0; i<Ais.size(); i++) {
			poss.add( (1-Ais.get(i)) * times.get(i) );
		}
		poss.add(times.get(Ais.size()));

		return poss;
	}

	private int getSwitchRowNum(int[][] matrix) {
		int ret = 0;
		int[] line = new int[matrix.length];
		Arrays.fill(line, 0);
		for(int i=0; i<matrix.length; i++) {
			for(int j=matrix.length-1; j>=0; j--) {
				if(matrix[i][j] == 1) {
					line[i] = j;
					break;
				}
			}
		}

		boolean flag = true;
		while(flag) {
			flag = false;
			for(int i=0; i<line.length; i++) {
				if(line[i] > i) {
					for(int j=i+1; j<line.length; j++) {
						if(line[j] <= i) {
							for(int k=j; k>i; k--) {
								swap(line, k, k-1);
							}
							ret += j - i;
							flag = true;
							break;
						}
					}
				}
			}
		}

		return ret;
	}

	private void swap(int[] line, int i, int j) {
		int tmp = line[i];
		line[i] = line[j];
		line[j] = tmp;
	}

	private long minBase(String msg) {
		Map<Character, Character> charMap = new HashMap<Character, Character>();
		charMap.put(msg.charAt(0), '1');
		int index = 0;
		String ret = "1";

		for(int i=1; i<msg.length(); i++) {
			char c = msg.charAt(i);
			if(!charMap.containsKey(c)) {
				if(index > 9) {
					charMap.put(c, (char)('a' + index-10));
				} else {
					charMap.put(c, (char)('0' + index));
				}
				if(index == 0) {
					index += 2;
				} else {
					index++;
				}
			}
			ret += charMap.get(c);
		}
		return stringToLong(ret, index < 2 ? 2 : index);
	}

	private double getPossibility(FeatureTree root, HashSet<String> features) {
		//tree ::= (weight [feature tree tree])
		double ret = root.weight;
		if(!root.feature.equals("")) {
			if(features.contains(root.feature)) {
				ret *= getPossibility(root.left, features);
			} else {
				ret *= getPossibility(root.right, features);
			}
		}
		return ret;
	}

	private class FeatureTree {
		public FeatureTree(double weight) {
			this.weight = weight;
			feature = "";
			left = null;
			right = null;
		}

		public FeatureTree(double weight, String feature, FeatureTree left, FeatureTree right) {
			this.weight = weight;
			this.feature = feature;
			this.left = left;
			this.right = right;
		}

		public double weight;
		public String feature;
		public FeatureTree left;
		public FeatureTree right;
	}

	private FeatureTree parseFeatureTree(BufferedReader reader) throws IOException {
		String token = getToken(reader, '[');
		if(token.equals("(")) {
			token = getToken(reader, '[');
		} else {
			token = token.substring(1);
		}

		if(token.endsWith(")")) {
			return new FeatureTree(Double.parseDouble(token.substring(0, token.length()-1)));
		}
		String token1 = getToken(reader, ')');
		if(token1.equals(")")) {
			return new FeatureTree(Double.parseDouble(token.substring(0, token.length())));
		} else {
			FeatureTree ret = new FeatureTree(Double.parseDouble(token), token1, parseFeatureTree(reader), parseFeatureTree(reader));
			getToken(reader, ')');
			return ret;
		}
	}

	private String getToken(BufferedReader reader, char stopChar) throws IOException {
		char c = (char)reader.read();
		for(; c == ' ' || c == '\n'; c = (char)reader.read()) {}
		String ret = "";
		for(; c != ' ' && c != '\n'; c = (char)reader.read()) {
			ret += c;
			if(c == stopChar) {
				break;
			}
		}
		return ret;
	}

	private String getNextNum(String num) {
		for(int i=num.length()-1; i>0; i--) {
			if(num.charAt(i) > num.charAt(i-1)) {
				int j = i;
				for(; j+1 < num.length() && num.charAt(j+1) > num.charAt(i-1); j++) {}
				if(j != num.length()-1) {
					return num.substring(0, i-1) + num.charAt(j) + sortString(num.substring(i-1, j) + num.substring(j+1));
				} else {
					return num.substring(0, i-1) + num.charAt(j) + sortString(num.substring(i-1, num.length()-1));
				}
			}
		}
		if(num.length() == 1) {
			return num + "0";
		} else {
			String ret = sortString(num);
			if(ret.startsWith("0")) {
				for(int i=1; i<ret.length(); i++) {
					if(ret.charAt(i) != '0') {
						if(i+1 <ret.length()) {
							num = ret.charAt(i) + ret.substring(0, i) + ret.substring(i+1);
						} else {
							num = ret.charAt(i) + ret.substring(0, i);
						}
						return num.charAt(0) + "0" + num.substring(1);
					}
				}
			} else {
				return ret.charAt(0) + "0" + ret.substring(1);
			}
		}
		return "";
	}

	private String sortString(String str) {
		char[] tmp = str.toCharArray();
		Arrays.sort(tmp);
		return String.valueOf(tmp);
	}

	private int getRecycleNum(int A, int B) {
		//A <= n < m <= B
		int ret = 0;
		Set<Integer> tmp = new HashSet<Integer>();
		for(int num=A; num<=B; num++) {
			String numStr = Integer.toString(num);
			int length = numStr.length();
			for(int i=0; i<length-1; i++) {
				String numStr2 = numStr.substring(1, numStr.length()) + numStr.charAt(0);
				int num2 = Integer.parseInt(numStr2);
				if(num2 <= B && num2 > num && !tmp.contains(num2)) {
					ret++;
				}
				tmp.add(num2);
				numStr = numStr2;
			}
			tmp.clear();
		}
		return ret;
	}

	private int getNumOfGoogler(int S, int p, List<Integer> points) {
		if(p == 0) {
			return points.size();
		}
		int ret = 0;
		for(int point : points) {
			if(point >= 3 * p - 2) {
				ret++;
			} else if(point >= 3 * p - 4 && S > 0 && p > 1) {
				S--;
				ret++;
			}
		}
		return ret;
	}


	Map<Character, Character> map = new HashMap<Character, Character>();

	private String getTranslation(String gs) {
		String ret = "";
		for(int i=0; i<gs.length(); i++) {
			ret += map.get(gs.charAt(i));
		}
		return ret;
	}

	private void getTranslation() {
		String gs1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		String gs2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		String gs3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

		String str1 = "our language is impossible to understand";
		String str2 = "there are twenty six factorial possibilities";
		String str3 = "so it is okay if you want to just give up";
		map.put('q', 'z');
		map.put('z', 'q');
		getTranslation(gs1, str1);
		getTranslation(gs2, str2);
		getTranslation(gs3, str3);
	}

	private void getTranslation(String gs, String str) {
		for(int i=0; i<gs.length(); i++) {
			map.put(gs.charAt(i), str.charAt(i));
		}
	}

	private int getHappyNum(List<Integer> bases) {
		for(int i=bases.get(0); ; i++) {
			boolean breakOut = false;
			for(int base : bases) {
				if(!isNumHappy(i, base)) {
					breakOut = true;
					break;
				}
			}
			if(!breakOut) {
				return i;
			}
		}
	}

	private boolean isNumHappy(int num, int base) {
		int sum = 0;
		List<String> previous = new ArrayList<String>();
		while(sum != 1) {
			sum = 0;
			String numStr = intToString(num, base);
			if(previous.contains(numStr)) {
				return false;
			}
			previous.add(numStr);
			for(int i=0; i<numStr.length(); i++) {
				sum += Math.pow(numStr.charAt(i) - '0', 2);
			}
			num = sum;
		}
		return true;
	}

	/**
	 * Accept 0~9 a~z
	 * @param str
	 * @param base
	 * @return
	 */
	private long stringToLong(String str, int base) {
		long ret = 0;
		long pow = 1;
		for(int i=str.length()-1; i>=0; i--) {
			if(str.charAt(i) >= 'a') {
				ret += (str.charAt(i) - 'a' + 10) * pow;
			} else {
				ret += (str.charAt(i) - '0') * pow;
			}
			pow *= base;
		}
		return ret;
	}

	private String intToString(int i, int base) {
		return intToString(i, base, 0);
	}

	private String intToString(int i, int base, int length) {
		String ret = "";
		while(i != 0) {
			ret = i % base + ret;
			i /= base;
		}
		if(ret.length() < length) {
			ret = new String(new char[length - ret.length()]).replace("\0", "0") + ret;
		}
		return ret;
	}

	private int getTicketFair(int P, int M[], int price[]) {
		int min = Integer.MAX_VALUE;
		int teamNum = (int)Math.pow(2, P);
		int gameNum = teamNum - 1;
		int possibility = (int)Math.pow(2, gameNum);
		for(int i=0; i<possibility; i++) {
			String buy = getBinaryNum(i, gameNum);
			int sum = 0;
			if(doesTeamWork(M, buy)) {
				for(int k=0; k<gameNum; k++) {
					if(buy.charAt(k) == '1') {
						sum += price[k];
					}
				}
			}
			if(sum != 0 && sum < min) {
				min = sum;
			}
		}
		return min;
	}

	private boolean doesTeamWork(int M[], String buy) {
		for(int i=0; i<M.length; i++) {
			int index = i / 2;
			int indexPlus = (buy.length() + 1) / 2;
			int sum = 0;
			int gameNum = 0;
			while(index < buy.length()) {
				if(buy.charAt(index) == '1') {
					sum++;
				}
				gameNum++;
				index = indexPlus + i / (int)Math.pow(2, gameNum+1);
				indexPlus = indexPlus + indexPlus / 2;
			}
			if(gameNum - M[i] > sum) {
				return false;
			}
		}
		return true;
	}

	private String getBinaryNum(long i, int length) {
		String ret = Long.toBinaryString(i);
		if(ret.length() < length) {
			return new String(new char[length - ret.length()]).replace("\0", "0") + ret;
		}
		return ret;
	}

	private class Chick {
		Chick(int b, int t, int x, int v) {
			T = t;
			B = b;
			X = x;
			V = v;
			arrive = (B - X) / (double)V <= T;
		}

		private int T;
		private int B;
		private int X;
		private int V;
		private boolean arrive;
	}

	private int getSwapNum(List<Chick> chicken, int K) {
		int ret = 0;
		for(int i=chicken.size()-1; i>=0; i--) {
			if(K == 0) {
				break;
			}
			if(!chicken.get(i).arrive) {
				ret += K;
			} else {
				K--;
			}
		}
		if(K != 0) {
			return -1;
		}
		return ret;
	}

	private class Directory {
		Directory(String n) {
			name = n;
			dirs = new ArrayList<Directory>();
		}

		Directory getChild(String name) {
			for(Directory dir : dirs) {
				if(dir.name.equals(name)) {
					return dir;
				}
			}
			return null;
		}

		private String name;
		private List<Directory> dirs;
	}

	private int getNumOfMkdir(Directory root, List<List<String>> newDirs) {
		int ret = 0;
		Directory curr, pre;
		for(List<String> newDir : newDirs) {
			curr = root;
			for(String folder : newDir) {
				pre = curr;
				curr = curr.getChild(folder);
				if(curr == null) {
					ret++;
					pre.dirs.add(new Directory(folder));
					curr = pre.getChild(folder);
				}
			}
		}
		return ret;
	}

	private List<String> getDirNames(String dir) {
		List<String> ret = new ArrayList<String>(Arrays.asList(dir.split("/")));
		ret.remove(0);
		return ret;
	}

	private String rotate(int K, char[][] position) {
		char[][] rotated = new char[position.length][position.length];
		for(int i=0; i<position.length; i++) {
			for(int j=0; j<position.length; j++) {
				rotated[j][position.length-1-i] = position[i][j];
			}
		}
		for(int j=0; j<position.length; j++) {
			int tmp = position.length - 1;
			for(int i=position.length-1; i>=0; i--) {
				if(rotated[i][j] != '.') {
					rotated[tmp][j] = rotated[i][j];
					tmp--;
				}
			}
			for(; tmp>=0; tmp--) {
				rotated[tmp][j] = '.';
			}
		}

		boolean r = checkColor('R', K, rotated);
		boolean b = checkColor('B', K, rotated);

		if(r && b) {
			return "Both";
		} else if(r) {
			return "Red";
		} else if(b) {
			return "Blue";
		} else {
			return "Neither";
		}
	}

	private boolean checkColor(char color, int K, char[][] rotated) {
		int num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				if(rotated[i][j] == color) {
					num++;
					if(num == K) {
						return true;
					}
				} else {
					num = 0;
				}
			}
			num = 0;
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				if(rotated[j][i] == color) {
					num++;
					if(num == K) {
						return true;
					}
				} else {
					num = 0;
				}
			}
			num = 0;
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				for(int k=0; k<K; k++) {
					if(i+k >=rotated.length || j+k >= rotated.length) {
						break;
					}
					if(rotated[i+k][j+k] == color) {
						num++;
						if(num == K) {
							return true;
						}
					} else {
						break;
					}
				}
				num = 0;
			}
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				for(int k=0; k<K; k++) {
					if(i+k >=rotated.length || j-k < 0) {
						break;
					}
					if(rotated[i+k][j-k] == color) {
						num++;
						if(num == K) {
							return true;
						}
					} else {
						break;
					}
				}
				num = 0;
			}
		}

		return false;
	}

	private class WalkWay implements Comparable<WalkWay>{
		WalkWay(int b, int e, int w) {
			B = b;
			E = e;
			W = w;
		}

		private int B;
		private int E;
		private int W;

		@Override
		public int compareTo(WalkWay o) {
			if(W == o.W) {
				return 0;
			}
			return W < o.W ? -1 : 1;
		}
	}

	private Double getMinTimeForWalkWay(int X, int S, int R, Double t, List<WalkWay> walkWays) {
		int walkWayNum = walkWays.size();
		int tmp = 0;
		for(int i=0; i<X; i++) {
			if(tmp >= walkWayNum) {
				walkWays.add(new WalkWay(i, X, 0));
				break;
			}
			if(i < walkWays.get(tmp).B) {
				walkWays.add(new WalkWay(i, walkWays.get(tmp).B, 0));
				i = walkWays.get(tmp).E - 1;
				tmp++;
			} else if(i == walkWays.get(tmp).B) {
				i = walkWays.get(tmp).E - 1;
				tmp++;
			}
		}
		Collections.sort(walkWays);

		Double ret = new Double(0);
		for(WalkWay walkWay : walkWays) {
			if(t > 0) {
				Double ideaT = (new Double(walkWay.E) - walkWay.B) / (walkWay.W + R);
				if(t >= ideaT) {
					t -= ideaT;
					ret += ideaT;
				} else {
					Double pass = t * (walkWay.W + R);
					ret += t + (new Double(walkWay.E) - pass - walkWay.B) / (walkWay.W + S);
					t = new Double(-1);
				}
			} else {
				ret += (new Double(walkWay.E) - walkWay.B) / (walkWay.W + S);
			}
		}

		return ret;
	}

	private String getPerfertHarmony(Long L, Long H, List<Long> frequencise) {
		boolean flag = true;
		for(long i=L; i<=H; i++) {
			flag = true;
			for(Long frequency : frequencise) {
				if(i % frequency != 0 && frequency % i != 0) {
					flag = false;
					break;
				}
			}
			if(flag) {
				return "" + i;
			}
		}
		return "NO";
	}

	private Long getRocketTime(Long L, Long t, Long N, List<Long> distance) {
		Long sum = new Long(0);
		List<Long> singleDis = new ArrayList<Long>();
		for(Long dis : distance) {
			sum += dis;
		}
		Long nRound = N / distance.size();
		Long nRemain = N % distance.size();
		Long time = nRound * sum;
		for(int i=0; i<nRemain; i++) {
			time += distance.get(i);
			singleDis.add(distance.get(i));
		}
		time *= 2;

		if(t >= time || L == 0) {
			return time;
		}

		Long pass = t/2;
		Long passRound = pass / sum;
		Long passRemain = pass % sum;
		Long passRoundRemain = nRound - passRound;

		if(t != 0) {
			for(int i=0; i<distance.size(); i++) {
				if(passRemain > 0) {
					passRemain -= distance.get(i);
				} else {
					singleDis.add(distance.get(i));
				}
			}
			if(passRemain != 0) {
				singleDis.add(-passRemain);
			}
			passRoundRemain--;
		}

		Collections.sort(distance);
		Collections.sort(singleDis);

		Long minus = new Long(0);
		int singleDisIndex = singleDis.size()-1;
		for(int i=distance.size()-1; i>=0; i--) {
			while(singleDisIndex >= 0 && singleDis.get(singleDisIndex) >= distance.get(i)) {
				minus += singleDis.get(singleDisIndex);
				singleDisIndex--;
				L--;
			}
			if(L <= passRoundRemain) {
				minus += L * distance.get(i);
				break;
			} else {
				minus += passRoundRemain * distance.get(i);
				L -= passRoundRemain;
			}
		}

		return time - minus;
	}

	private char[][] tiles;
	private boolean test() {
		for(int i=0; i<tiles.length; i++) {
			for(int j=0; j<tiles[i].length; j++) {
				if(tiles[i][j] == '#') {
					if(i+1 >= tiles.length || j+1 >= tiles[i+1].length || tiles[i][j+1] != '#' || tiles[i+1][j] != '#' || tiles[i+1][j+1] != '#') {
						return false;
					}
					tiles[i][j] = '/';
					tiles[i+1][j] = '\\';
					tiles[i][j+1] = '\\';
					tiles[i+1][j+1] = '/';
				}
			}
		}
		return true;
	}

	private String test1(List<String> words, String seq) {
		int maxScore = -1;
		String maxString = "";

		for(String word : words) {
			int score = -1;
			StringBuilder wildCard = new StringBuilder(new String(new char[word.length()]).replace("\0", "_"));
			List<String> words2 = new ArrayList<String>(words);
			int words2Size = words.size();

			for(int i=0; i<seq.length(); i++) {
				Character seqChar = seq.charAt(i);
				int j=0;

				while(j<words2Size) {
					if(words2.get(j).indexOf(seqChar) != -1) {
						break;
					}
					j++;
				}

				if(j == words2Size) {
					continue;
				}

				if(word.indexOf(seqChar) == -1) {
					score++;
				} else {
					int beginIndex = 0;
					while(true) {
						beginIndex = word.indexOf(seqChar, beginIndex);
						if(beginIndex == -1) {
							break;
						}
						wildCard.setCharAt(beginIndex, seqChar);
						beginIndex++;
					}

					for(j=0; j<words2Size; j++) {
						if(!killerWordWildCard(words2.get(j), wildCard.toString(), seqChar)) {
							words2.remove(words2.get(j));
							words2Size--;
							j--;
						}
					}

					if(words2Size == 1) {
						break;
					}
				}
			}
			if(score > maxScore) {
				maxScore = score;
				maxString = word;
			}
		}
		return maxString;
	}

	private boolean killerWordWildCard(String word, String wildCard, Character notIn) {
		if(!wildCardMatch(word, wildCard)) {
			return false;
		} else if(notIn != null) {
			int begin = -1;
			while(true) {
				if(begin+1 >= word.length()) {
					break;
				}
				begin = word.indexOf(notIn, begin + 1);
				if(begin == -1) {
					break;
				}
				if(wildCard.charAt(begin) != notIn) {
					return false;
				}
			}
			//			wildCard.indexOf(notIn);
		}
		return true;
	}

	private boolean wildCardMatch(String str1, String str2) {
		if(str1.length() != str2.length()) {
			return false;
		}
		for(int i=0; i<str1.length(); i++) {
			if(str2.charAt(i) != '_' && str1.charAt(i) != str2.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	private Integer max(Integer... numbers) {
		int max = numbers[0];

		for(Integer number : numbers) {
			if(number > max) {
				max = number;
			}
		}
		return max;
	}

	private Double max(Double... numbers) {
		Double max = numbers[0];

		for(Double number : numbers) {
			if(number > max) {
				max = number;
			}
		}
		return max;
	}

	private Integer min(Integer... numbers) {
		Integer min = numbers[0];

		for(Integer number : numbers) {
			if(number < min) {
				min = number;
			}
		}
		return min;
	}

	private Double min(Double... numbers) {
		Double min = numbers[0];

		for(Double number : numbers) {
			if(number < min) {
				min = number;
			}
		}
		return min;
	}

	private int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}

	private int gcd(int a, int b) {
		while(a != b) {
			if(a > b) {
				a -= b;
			} else {
				b -= a;
			}
		}
		return a;
	}
}
