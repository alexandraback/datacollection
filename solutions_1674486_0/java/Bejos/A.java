/**
 * 
 */

package com.google.jam.round1C;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		try {
			FileOutputStream fos = new FileOutputStream("A-small-attempt0.out");
			//FileOutputStream fos = new FileOutputStream("A-large.out");
			System.setOut(new PrintStream(fos, true));
			
			FileInputStream fis=new FileInputStream(new File("A-small-attempt0.in"));
			//FileInputStream fis=new FileInputStream(new File("A-large.in"));
			InputStreamReader in=new InputStreamReader(fis);
			BufferedReader br=new BufferedReader(in);
			
			String line="";
			int nbTest = Integer.parseInt(br.readLine());
			
			String res = "";
			for(int i=1; i<=nbTest; i++) {
				int nbNodes = Integer.parseInt(br.readLine());
				
				GraphDependency gp = new GraphDependency(nbNodes);
				
				for(int j=0; j<nbNodes; j++) {
					line = br.readLine();
					Scanner sc = new Scanner(line);
					int nbEdges = sc.nextInt();
					
					for(int k=0; k<nbEdges; k++) {
						int m = sc.nextInt();
						gp.addEdge(j, m-1);
					}
				}
				
				res = gp.inhetirance() ? "Yes" : "No"; 
						
				System.out.println("Case #" + i + ": " + res);
			}
	
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("File not found");
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
