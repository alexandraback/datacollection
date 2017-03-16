import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Enclosure {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {

		Scanner scanner = new Scanner(new File("C-small-attempt1.in"));
		int result = 0;
		int caseCounter = 0;
		int i=0;
		int p,q,r, mult;
		caseCounter = scanner.nextInt();		
		BufferedWriter out = new BufferedWriter(new FileWriter("result6.out"));
		
		for(i=0;i<caseCounter;i++){

			p=scanner.nextInt();
			q=scanner.nextInt();
			r=scanner.nextInt();
			mult = p*q;
			
			switch (mult){
			case 9:
				if(p==1 || q==1){
					result = r;
					break;
				}
				if(r<=4)
				result = r;
				else
					result = r-1;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 10:
			case 11:
			case 13:
			case 14:
			case 17:
			case 19:
				result = r;
				break;
			case 12:
				if(p==1 || q==1 || p == 6 || q == 6){
					result = r;
					break;
				}
				if(r<=4)
					result = r;
				if(r>4 && r<8)
					result = r-1;
				if(r>=8)
					result = r-2;
				break;
			case 15:
				if(p==1 || q==1){
					result = r;
					break;
				}
				if(r<=4)
					result = r;
				if(r>4 && r<8)
					result = r-1;
				if(r>=8 && r<11)
					result = r-2;
				if(r>=11)
					result = r-3;
				break;
			case 18:
				if(p==1 || q==1 || p ==9 || q==9){
					result = r;
					break;
				}
				if(r<=4)
					result = r;
				if(r>4 && r<8)
					result = r-1;
				if(r>=8 && r<11)
					result = r-2;
				if(r>=11 && r<14)
					result = r-3;
				if(r>=14)
					result = r-4;
				break;
			case 16:
				if(p==1 || q==1 || p==8 || q== 8){
					result = r;
					break;
				}
				if(r<=4)
					result = r;
				if(r>4 && r<8)
					result = r-1;
				if(r>=8 && r<10)
					result = r-2;
				if(r>=10 && r<12)
					result = r-3;
				if(r>=12)
					result = r-4;
				break;
			case 20:
				if(p==1 || q==1 || p==10 || q==10){
					result = r;
					break;
				}
				if(r<=4)
					result = r;
				if(r>4 && r<8)
					result = r-1;
				if(r>=8 && r<10)
					result = r-2;
				if(r>=10 && r<12)
					result = r-3;
				if(r>=12 && r<14)
					result = r-4;
				if(r>=14 && r<16)
					result = r-5;
				if(r>=16)
					result = r-6;
				break;
			}
			
			
			
			
			

			out.write("Case #" + (i+1) + ": " + result);
			out.newLine();
		}
		
		out.close();

		
		
	}

}
