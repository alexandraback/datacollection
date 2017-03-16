import java.util.ArrayList;
import java.util.Scanner;
import java.math.BigInteger;

public class coinjam {

	/**
	 * @param args
	 */
	static ArrayList<BigInteger> potencias2 = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> potencias4 = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> potencias6 = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> potencias8 = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> potencias10 = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> potencias3 = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> potencias5 = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> potencias7 = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> potencias9 = new ArrayList<BigInteger>();
	static int nBits;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int numCases = input.nextInt();
		nBits = input.nextInt();
		int cantResultados = input.nextInt();
		
	
			
			ArrayList<BigInteger> vectorsito = new ArrayList<BigInteger>();
			
			for(int i = 0;i<nBits;i++){
				vectorsito.add(new BigInteger("0"));
				potencias2.add(new BigInteger("2").pow(i));
				potencias4.add(new BigInteger("4").pow(i));
				potencias6.add(new BigInteger("6").pow(i));
				potencias8.add(new BigInteger("8").pow(i));
				potencias10.add(new BigInteger("10").pow(i));
				potencias3.add(new BigInteger("3").pow(i));
				potencias5.add(new BigInteger("5").pow(i));
				potencias7.add(new BigInteger("7").pow(i));
				potencias9.add(new BigInteger("9").pow(i));
				
				}
			//mayor
			vectorsito.set(nBits-1,new BigInteger("1"));
			//menor
			vectorsito.set(0,new BigInteger("1"));
			vectorsito.set(14,new BigInteger("1"));
			System.out.println("Case #1:");
		for(int n =0;n<cantResultados;n++){
//			System.out.println(getNum(nBits,vectorsito,potencias10).toString());
//			vectorsito = nextNum(vectorsito);
//			System.out.println(getNum(nBits,vectorsito,potencias10).toString());
//			
			boolean esPrimo=true;
			while(esPrimo){
				esPrimo = false;
				if(getNum(nBits,vectorsito,potencias2).isProbablePrime(1)){
					esPrimo=true;
				}
				if(getNum(nBits,vectorsito,potencias3).isProbablePrime(1)){
					esPrimo=true;
				}
				if(getNum(nBits,vectorsito,potencias4).isProbablePrime(1)){
					esPrimo=true;
				}
				if(getNum(nBits,vectorsito,potencias5).isProbablePrime(1)){
					esPrimo=true;
				}
				if(getNum(nBits,vectorsito,potencias6).isProbablePrime(1)){
					esPrimo=true;
				}
				if(getNum(nBits,vectorsito,potencias7).isProbablePrime(1)){
					esPrimo=true;
				}
				if(getNum(nBits,vectorsito,potencias8).isProbablePrime(1)){
					esPrimo=true;
				}
				if(getNum(nBits,vectorsito,potencias9).isProbablePrime(1)){
					esPrimo=true;
				}
				if(getNum(nBits,vectorsito,potencias10).isProbablePrime(1)){
					
					esPrimo=true;
				}
				if(divisorGigante(getNum(nBits,vectorsito,potencias2))){esPrimo=true;}
				if(divisorGigante(getNum(nBits,vectorsito,potencias3))){esPrimo=true;}
				if(divisorGigante(getNum(nBits,vectorsito,potencias4))){esPrimo=true;}
				if(divisorGigante(getNum(nBits,vectorsito,potencias5))){esPrimo=true;}
				if(divisorGigante(getNum(nBits,vectorsito,potencias6))){esPrimo=true;}
				if(divisorGigante(getNum(nBits,vectorsito,potencias7))){esPrimo=true;}
				if(divisorGigante(getNum(nBits,vectorsito,potencias8))){esPrimo=true;}
				if(divisorGigante(getNum(nBits,vectorsito,potencias9))){esPrimo=true;}
				if(divisorGigante(getNum(nBits,vectorsito,potencias10))){esPrimo=true;}
				
				if(esPrimo){vectorsito = nextNum(vectorsito);}
			}
			imprimir(vectorsito);
			vectorsito = nextNum(vectorsito);
		}
//		for(int n =0;n<numCases;n++){
//			
//			
//			
//			double cont = Math.pow(2,15);
//			
//			System.out.printf("Case #"+(n+1)+":");
//			for(long sdfasfd:resultados){System.out.printf(" "+sdfasfd );}
//			System.out.println("");
			
//			}
	}
	
	public static void imprimir(ArrayList<BigInteger> vectorsito){
		for(int i = (vectorsito.size()-1);i>-1;i--){
			System.out.printf(vectorsito.get(i).toString());
		}
		
		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias2)).toString() );

		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias3)).toString() );

		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias4)).toString() );

		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias5)).toString() );

		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias6)).toString() );

		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias7)).toString() );

		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias8)).toString() );

		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias9)).toString() );

		System.out.printf(" "+getDivisor(getNum(nBits,vectorsito,potencias10)).toString()+"\n" );
		
		
	}
	public static BigInteger getDivisor(BigInteger numero){
		BigInteger aux = new BigInteger("2");
		BigInteger uno = new BigInteger("1");
		BigInteger sero = new BigInteger("0");
		boolean salir = false;
		while(!salir){
//			System.out.println(numero.remainder(aux).toString());
			if(numero.remainder(aux).equals(sero)){
				salir = true;
			}else{
				aux = aux.add(new BigInteger("1"));
			}
		}
		return aux;
	}
	
	public static boolean divisorGigante(BigInteger numero){
		BigInteger aux = new BigInteger("2");
		BigInteger uno = new BigInteger("1");
		BigInteger sero = new BigInteger("0");
		boolean salir = false;
		while(!salir){
//			System.out.println(numero.remainder(aux).toString());
			if(numero.remainder(aux).equals(sero)){
				salir = true;
			}else{
				aux = aux.add(new BigInteger("1"));
				if(aux.compareTo(new BigInteger("100000")) == 1){
					
					salir = true;
				}
			}
		}
		return (aux.compareTo(new BigInteger("100000")) == 1);
	}
	
	public static ArrayList<BigInteger> nextNum(ArrayList<BigInteger> vectorsito){
		int i = 1;
		
		if (vectorsito.get(1).equals(new BigInteger("0"))){
			vectorsito.set(1,new BigInteger("1"));
			
		}else{
			while (vectorsito.get(i).equals(new BigInteger("1"))){
				vectorsito.set(i,new BigInteger("0"));
				i++;
			}
			vectorsito.set(i,new BigInteger("1"));
		}
		return vectorsito;
	}
	public static BigInteger getNum(int nBits,ArrayList<BigInteger> binario,ArrayList<BigInteger> potencias){
		BigInteger resultado = binario.get(0).multiply(potencias.get(0)); 
		for(int i=1;i<nBits;i++){
			resultado = resultado.add(binario.get(i).multiply(potencias.get(i))); 
		}
		return resultado;
	}
}
