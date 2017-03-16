import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;


public class MainA {
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("A-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\Erich\\Desktop\\A-small.out"));
		sc.useLocale(Locale.US);
		int qtd = sc.nextInt();
		for(int i=0;i<qtd;i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			double[] probs = new double[a];
			double probAcerto=1;
			for(int j=0;j<a;j++){
				probs[j]=sc.nextDouble();
				probAcerto*=probs[j];
			}
			double caso1 = (b-a+1)* probAcerto+ (1-probAcerto)*(b+1+(b-a+1));
			double caso2 = caso1;
			for(int j=0;j<a;j++){
				double temp = calculaProb2(a,a-j,b,probs);
				if(temp<caso2){
					caso2=temp;
				}
			}
			double caso3 = b+2;
			double resposta = 0.0;
			if(caso3<caso2){
				resposta = caso3;
			}else{
				resposta=caso2;
			}
			
			String saida = "Case #"+(i+1)+": "+resposta+"\n";
			bw.write(saida);
		}
		bw.flush();
		bw.close();
	}
	public static double calculaProb2(int aOriginal,int a, int b, double[] probs){
		double probAcerto=1;
		for(int j=0;j<a-1;j++){
			probAcerto*=probs[j];
		}
		return (b-a+1+2*(aOriginal-a+1))+(b+1)*(1-probAcerto);
	}

}
