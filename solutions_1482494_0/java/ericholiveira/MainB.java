import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class MainB {
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("B-small-attempt1.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\Erich\\Desktop\\B-small.out"));
		int qtd = sc.nextInt();
		for(int i=0;i<qtd;i++){
			int niveis = sc.nextInt();
			int[][] estrelas = new int[niveis][2];
			String resposta = "";
			int estrelasGanhas=0;
			int numeroJogos=0;
			boolean[][] modoCompleto = new boolean[niveis][2];
			for(int j=0;j<niveis;j++){
				estrelas[j][0]= sc.nextInt();
				estrelas[j][1]= sc.nextInt();
				modoCompleto[j][0]=false;
				modoCompleto[j][1]=false;
			}
			int menor=0;
			boolean tooBad=false;
			while(menor!=-1 && !tooBad && estrelasGanhas<2*niveis){
				menor= abaixoNivel2(estrelas, modoCompleto, estrelasGanhas);
				if(menor >=0 && estrelas[menor][1]<=estrelasGanhas){
					modoCompleto[menor][1]=true;
					numeroJogos++;
					estrelasGanhas++;
					if(!modoCompleto[menor][0]){
						estrelasGanhas++;
					}
				}else{
					menor = abaixoNivel1(estrelas, modoCompleto, estrelasGanhas);
					if(menor >=0 && estrelas[menor][0]<=estrelasGanhas){
						modoCompleto[menor][0]=true;
						numeroJogos++;
						estrelasGanhas++;
					}else{
						resposta = "Too Bad";
						tooBad = true;
					}
				}
			}
			if(!tooBad){
				resposta = String.valueOf(numeroJogos);
			}
			String saida = "Case #"+(i+1)+": "+resposta+"\n";
			bw.write(saida);
			System.out.println(saida);
		}
		bw.flush();
		bw.close();
	}
	public static int abaixoNivel1(int [][]niveis,boolean[][] modoCompleto,int maximo){
		int maior = -1;
		int menorIndice=-1;
		for(int i=0;i<niveis.length;i++){
			if(!modoCompleto[i][0] && !modoCompleto[i][1]){
				if((maximo>=niveis[i][0])){
					if(menorIndice>-1){
						if(maior<niveis[i][1]){
							maior = niveis[i][1];
							menorIndice=i;
						}
					}else{
						maior = niveis[i][1];
						menorIndice=i;
					}
					
				}
			}
			
		}
		return menorIndice;
	}
	public static int abaixoNivel2(int [][]niveis,boolean[][] modoCompleto,int maximo){
		int menorIndice=-1;
		for(int i=0;i<niveis.length;i++){
			if((maximo>=niveis[i][1]) && !modoCompleto[i][1]){
				menorIndice=i;
			}
		}
		return menorIndice;
	}
}
