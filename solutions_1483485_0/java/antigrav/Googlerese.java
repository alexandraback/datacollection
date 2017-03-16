package codejam2.googlerese;

import java.util.Scanner;

import codejam2.CodejamCase;
import codejam2.CodejamRunner;

public class Googlerese extends CodejamRunner implements CodejamCase {
	private String cypher;
	private String plain;

	private static char translate[] = {
		'y', // a
		'h', // b
		'e', // c
		's', // d
		'o', // e
		'c', // f
		'v', // g
		'x', // h
		'd', // i
		'u', // j
		'i', // k
		'g', // l
		'l', // m
		'b', // n
		'k', // o
		'r', // p
		'z', // q
		't', // r
		'n', // s
		'w', // t
		'j', // u
		'p', // v
		'f', // w
		'm', // x
		'a', // y
		'q'  // z
	};
	
	public Googlerese(Scanner s) {
		cypher = s.nextLine();
	}

	public Googlerese() {}

	@Override
	public void compute() {
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < cypher.length(); i++) {
			char ch = cypher.charAt(i);
			sb.append(ch==' ' ? ' ' : translate[ch-'a']);
		}
		plain = sb.toString();
	}

	@Override
	public String getOutput() {
		return plain;
	}

	@Override
	public CodejamCase parseCase(Scanner s) {
		return new Googlerese(s);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Googlerese().run(args);
	}

}
