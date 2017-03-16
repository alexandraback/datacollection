import java.util.ArrayList;
import java.util.Scanner;


public class fractiles {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int numCases = input.nextInt();
		for(int n =0;n<numCases;n++){
			long K = input.nextLong();
			long C = input.nextLong();
			long S = input.nextLong();
			
			//MAKE POLINOMIO DE GRADO C-1
			ArrayList<Long> polinomio = new ArrayList<Long>();
			
			for(long i=0; i<C;i++){
				polinomio.add((long) Math.pow(K,i));
			}
			//Cargo todos los numeros de 0 a "K"
			ArrayList<Long> options = new ArrayList<Long>();
			
			for(long i=0; i<K;i++){
				options.add(i+1);
			}
		
			//los separo en grupos de hasta C
			ArrayList<ArrayList> optionsList = new ArrayList<ArrayList>();
			//optionsList.add(new ArrayList<Long>());
			int aux = -1;
			int cont = (int) C;
			for(long num:options){
				
				if(cont == C){
					optionsList.add(new ArrayList<Long>());
					aux++;
					cont =0;
				}
				optionsList.get(aux).add(num);
				cont++;
			}
		//	for(ArrayList<Long> pop:optionsList){
				//System.out.println("JAJAJA");
			//for(long cuchi:pop){System.out.println(cuchi + " ASDFASDF");}}
			//LISTA DE RESULTADOS
			ArrayList<Long> resultados = new ArrayList<Long>();
			for(ArrayList<Long> printt:optionsList){
				long resultaditos = evaluarPol(polinomio, printt);
				resultados.add(resultaditos);
				
				
				
			}
			resultados.sort(null);
			//for(long sdfasfd:resultados){System.out.println(sdfasfd + "");}
			
			if(resultados.size()> S){

				System.out.println("Case #"+(n+1)+": IMPOSSIBLE");
			}else{
				System.out.printf("Case #"+(n+1)+":");
				for(long sdfasfd:resultados){System.out.printf(" "+sdfasfd );}
				System.out.println("");
			}
			
			
			
			
			
			}
	}
	
	public static long evaluarPol(ArrayList<Long> polinomio , ArrayList<Long> options){
		long res = 0;
		res = res + polinomio.get(0)*options.get(0);
	
		for(long temp=1;temp<options.size();temp++){
			res = res + polinomio.get((int) temp)*(options.get((int) temp)-1); 
		}
		return res;
	}

}
