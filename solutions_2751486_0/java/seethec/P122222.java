import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

import javax.swing.text.html.HTMLDocument.Iterator;

public class kkkk1 {
	int notc;
	int sampleNo;
	BufferedReader br;
	public kkkk1() {
		sampleNo=1;
		notc=0;
	}
	public void rf(){
		try {
			br = new BufferedReader(new FileReader("Input.txt"));
			notc = Integer.parseInt(br.readLine());
			do{
				rfs();
				sampleNo++;
			}while(sampleNo<=notc);
		} catch (Exception e) {
			System.out.println("Text - File Exception : " +e);
		}
	}
	
	public void print(String arr[]){
		for(String i:arr)
			System.out.print(i+" , ");
		System.out.println();
	}
	
	public void rfs() throws IOException{
		String sample[]=br.readLine().split(" ");
		char name[] = sample[0].toCharArray();
		Queue<Character> name1 = new LinkedList<Character>();
		for(Character i: name){
			name1.add(i);
		}
		Integer rn = Integer.parseInt(sample[1]);
		ws(cnnn(name1,rn));
	}
	public boolean isVowel(char c){
		if(c=='a'|| c=='e' || c=='i' || c=='o' || c=='u')
			return true;
		return false;
	}
	public Integer cnnn(Queue<Character> name, Integer rn){
		Integer n=0;
		int cont;
		
		wh:while(name.size()>=rn){
			Object n1[]= name.toArray();	
			//System.out.println();
			/*for (Object object : n1) {
				System.out.print((Character)object);
			}
			System.out.println( " " + n1.length);
			*/for(int i=0;i<n1.length;i++){
				cont=0;
				while(i<n1.length && !isVowel((Character)n1[i]) ){
					//System.out.println("n="+n);
					//System.out.print("Y");
					cont++;
					//System.out.print((Character)n1[i] + "" + cont + " ");
					if(cont==rn){
						//System.out.println("\nn = " + n + " add = " + (n1.length-i));
						n+=(n1.length-i);
						name.remove();
						continue wh;
					}
					i++;
				}
				//System.out.println();
			}
			
			name.remove();
			
		}
		return n;
	}
	public void ws(Integer res){
		System.out.println("Case #"+sampleNo+": "+res);
	}
	public static void main(String[] args) {
		kkkk1 p = new kkkk1();
		p.rf();
	}

}
