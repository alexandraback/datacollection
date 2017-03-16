/**
 * Dancing With the Googlers
 */

package com.google.jam.qualification;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		try {
			FileOutputStream fos = new FileOutputStream("B-large.out");
			System.setOut(new PrintStream(fos, true));
			
			FileInputStream fis=new FileInputStream(new File("B-large.in"));
			InputStreamReader in=new InputStreamReader(fis);
			BufferedReader br=new BufferedReader(in);
			
			String line="";
			int nbTest = Integer.parseInt(br.readLine());
			
			for(int i=1; i<=nbTest; i++) {
				line = br.readLine();
				Scanner sc = new Scanner(line);
				int nbJ = sc.nextInt();
				int nbS = sc.nextInt();
				int minPoint = sc.nextInt();
				
				int res = 0;
				boolean stop = false;
				for(int j=0; j<nbJ && !stop; j++) {
					int total = sc.nextInt();
					int moy = total / 3;
					int reste = total%3;
					
					if(moy >= minPoint) res++;
					else if((moy+1)>= minPoint) {
						if(reste==2 || reste ==1) res++;
						else if(nbS>0 && reste==0 && moy>0) {
							res++;
							nbS--;
						}
						
					}
					else if((moy+2)>= minPoint) {
						if(nbS>0 && reste==2) {
							res++;
							nbS--;
						}
					}
					
				}
				
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
