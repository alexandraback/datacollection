package codeJam2015;

import java.io.IOException;

public class PC extends Cases {

	static char[][] quaternions = new char[256][256];
	
	private static void fillQuaternions() {
		quaternions['e']['e'] = 'e'; quaternions['e']['i'] = 'i'; quaternions['e']['j'] = 'j'; quaternions['e']['k'] = 'k';
		quaternions['i']['e'] = 'i'; quaternions['i']['i'] = 'E'; quaternions['i']['j'] = 'k'; quaternions['i']['k'] = 'J';
		quaternions['j']['e'] = 'j'; quaternions['j']['i'] = 'K'; quaternions['j']['j'] = 'E'; quaternions['j']['k'] = 'i';
		quaternions['k']['e'] = 'k'; quaternions['k']['i'] = 'j'; quaternions['k']['j'] = 'I'; quaternions['k']['k'] = 'E';
	}
	
	private static char multiply(char a, char b) {
		boolean sign = true;
		if(a < 97) {
			a += 32;
			sign ^= true;
		}
		if(b < 97) {
			b += 32;
			sign ^= true;
		}
		char c = quaternions[a][b];
		if(c < 97) {
			c += 32;
			sign ^= true;
		}
		if(!sign)
			c -= 32;
		return c;
	}
	
	public static void operate(Case[] cases) {
		for(Case ca : cases) {
			String[] tmp = ca.input.get(0).split(" ");
			int L = Integer.parseInt(tmp[0]);
			long X = Long.parseLong(tmp[1]);
			char[] ctmp = ca.input.get(1).toCharArray();
			//System.out.println(ca.id + " " + L + " " + X);
			if((L < 3 && X < 2) || (L < 2)) {
				ca.output = "NO";
				continue;
			}
			
			long num = X / 4;
			
			if(X > 100) {
				X = X - 4 * (num - 20);
			}
			
			long len = (long)L * X;
			
			char[] arr = new char[(int)len];
			
				for(int i = 0; i < L; i++)
					for(int j = 0; j < X; j++)
						arr[i + (j * L)] = ctmp[i];
			
			int posI = findI(arr);
			if(posI < 0) {
				ca.output = "NO";
				continue;
			}
			System.out.println(ca.id + " " + posI);
			
			int posK = findK(arr);
			if(posK < 0 || posK <= posI + 1) {
				ca.output = "NO";
				continue;
			}
			System.out.println(ca.id + " " + posK);
			
			char c = arr[posI + 1];
			for(int i = posI + 2; i < posK; i++)
				c = multiply(c, arr[i]);
			if(c == 'j')
				ca.output = "YES";
			else
				ca.output = "NO";
		}
	}
	
	private static int findI(char[] arr) {
		char c = arr[0];
		int i = 1;
		while(c != 'i' && i < arr.length) {
			c = multiply(c, arr[i++]);
		}
		if(c != 'i')
			return -1;
		return i - 1;
	}
	
	private static int findK(char[] arr) {
		char c = arr[arr.length - 1];
		int i = arr.length - 2;
		while(c != 'k' && i > -1) {
			c = multiply(arr[i--], c);
		}
		if(c != 'k')
			return -1;
		return i + 1;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "C-large.in";
		int caseSize = 2;	/////////////////////////////////////// remember to set caseSize here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(args.length > 0)
			inputFile = args[0];
		String outputFile = inputFile.substring(0, inputFile.length() - 3) + ".out";
		Case[] cases = readAllCases(inputFile, caseSize);
		fillQuaternions();
		operate(cases);
		writeOutput(outputFile, cases);
	}
}
