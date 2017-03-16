package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TestClass {

	public static void main (String[] args) throws IOException {
		TestClass testClass = new TestClass();

		//testClass.fixUninitSend(new File("\\\\FM6GW7VPG130\\forSend"));
		
		BufferedReader reader = new BufferedReader(new FileReader("C:\\share\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\share\\out.txt"));

		int caseNum = Integer.parseInt(reader.readLine());
		for(int i=0; i<caseNum; i++) {
			String cakeStr = reader.readLine();
			String[] strs = cakeStr.split(" ");
			
			writer.write("Case #" + (i+1) + ":");
			String[] ret = testClass.scoreBoard(strs[0], strs[1]);
			writer.write(" " + ret[0] + " " + ret[1]);
			writer.write("\n");

			writer.flush();
		}

		reader.close();
		writer.close();
	}
	
	private String[] scoreBoard(String coder, String jammer) {
		List<BigInteger> possCoder = possScore(coder, jammer);
		List<BigInteger> possJammer = possScore(jammer, coder);
		String[] ret = new String[2];
		
		BigInteger minDiff = BigInteger.ZERO;
		BigInteger minJammer = BigInteger.ZERO;
		BigInteger minCoder = BigInteger.ZERO;
		boolean firstTime = true;
		for(BigInteger tmpCoder : possCoder) {
			for(BigInteger tmpJammer : possJammer) {
				BigInteger diff = tmpCoder.subtract(tmpJammer).abs();
				if(firstTime) {
					firstTime = false;
					minDiff = diff;
					minJammer = tmpJammer;
					minCoder = tmpCoder;
					ret[0] = tmpCoder.toString();
					ret[1] = tmpJammer.toString();
				} else if(diff.compareTo(minDiff) == -1) {
					minDiff = diff;
					minJammer = tmpJammer;
					minCoder = tmpCoder;
					ret[0] = tmpCoder.toString();
					ret[1] = tmpJammer.toString();
				} else if(diff.compareTo(minDiff) == 0 && tmpJammer.compareTo(minJammer) == -1) {
					minDiff = diff;
					minJammer = tmpJammer;
					minCoder = tmpCoder;
					ret[0] = tmpCoder.toString();
					ret[1] = tmpJammer.toString();
				} else if(diff.compareTo(minDiff) == 0 && tmpJammer.compareTo(minJammer) == 0 && tmpCoder.compareTo(minCoder) == -1) {
					minDiff = diff;
					minJammer = tmpJammer;
					minCoder = tmpCoder;
					ret[0] = tmpCoder.toString();
					ret[1] = tmpJammer.toString();
				}
			}
		}
		
		for(int i=0; i<2; i++) {
			int l = coder.length() - ret[i].length();
			for(int j=0; j<l; j++) {
				ret[i] = "0" + ret[i];
			}
		}
		return ret;
		
		/*String ret = "";
		int[] compare = new int[coder.length()];
		for(int i=0; i<coder.length(); i++) {
			if(coder.charAt(i) == '?' || jammer.charAt(i) == '?') {
				compare[i] = -1;
			} else if(coder.charAt(i) > jammer.charAt(i)) {
				compare[i] = 1;
			} else {
				compare[i] = 0;
			}
		}
		return ret;*/
	}
	
	private List<BigInteger> possScore(String coder, String jammer) {
		List<String> possCoder = new ArrayList<String>();
		possCoder.add(coder);

		while(true) {
			String tmpCoder = possCoder.get(0);
			if(!tmpCoder.contains("?")) {
				List<BigInteger> ret = new ArrayList<BigInteger>();
				for(String tmp : possCoder) {
					ret.add(new BigInteger(tmp));
				}
				return ret;
			}
			
			try{
			for(int i=0; i<tmpCoder.length(); i++) {
				if(tmpCoder.charAt(i) == '?') {
					if(jammer.charAt(i) == '?') {
						possCoder.add(tmpCoder.substring(0, i) + "0" +tmpCoder.substring(i+1));
						possCoder.add(tmpCoder.substring(0, i) + "1" +tmpCoder.substring(i+1));
						possCoder.add(tmpCoder.substring(0, i) + "9" +tmpCoder.substring(i+1));
					} else {
						possCoder.add(tmpCoder.substring(0, i) + jammer.charAt(i) +tmpCoder.substring(i+1));
						possCoder.add(tmpCoder.substring(0, i) + "0" +tmpCoder.substring(i+1));
						possCoder.add(tmpCoder.substring(0, i) + "1" +tmpCoder.substring(i+1));
						possCoder.add(tmpCoder.substring(0, i) + "9" +tmpCoder.substring(i+1));
						if(jammer.charAt(i) != '0')
						possCoder.add(tmpCoder.substring(0, i) + (char)(jammer.charAt(i)-1) +tmpCoder.substring(i+1));
						if(jammer.charAt(i) != '9')
						possCoder.add(tmpCoder.substring(0, i) + (char)(jammer.charAt(i)+1) +tmpCoder.substring(i+1));
					}
				}
			}
			} catch(StringIndexOutOfBoundsException e) {
				e.printStackTrace();
			}
			possCoder.remove(0);
		}
	}
	
	private int compareString(String a, String b) {
		for(int i=0; i<a.length(); i++) {
			if(a.charAt(i) > b.charAt(i)) {
				return 1;
			} else if(b.charAt(i) > a.charAt(i)) {
				return 0;
			}
		}
		return -1;
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
	
}
