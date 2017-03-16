package r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.IOException;




public class theLastWord {



		public static void main(String[] args) throws IOException {
			
			String path = "A-small-attempt0.in";
			File f = new File(path);
			PrintWriter out = null;
			
			
			
			try{
				File fi = new File("resultSmall.txt");
				fi.createNewFile();
				out = new PrintWriter(fi);
				Scanner sc = new Scanner(f);
				int num = sc.nextInt();
				sc.nextLine();
				
				for(int k=0; k<num; k++){
					
					StringBuilder sb = new StringBuilder();
					String line = sc.nextLine();
					char[] array = line.toCharArray();
				
					for(int i=0; i<array.length; i++){
						
						
						
						if(sb.length() != 0){

							if(array[i] < sb.charAt(0)){
								
								sb.append(array[i]);
							} else {
							
								sb.insert(0, array[i]);
							}							
						} else {
							
							sb.append(array[i]);
						}
					}
				
					out.printf("Case #%d: ", (k+1));
					out.println(sb.toString());
				}
				sc.close();
			} catch (FileNotFoundException e){
				System.out.println("File not found.");
				System.out.println(e.getMessage());
				
			}finally{
				out.close();
			
			}

		}
	}

