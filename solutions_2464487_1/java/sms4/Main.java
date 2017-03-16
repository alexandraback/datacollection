import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) throws IOException {
		
		Scanner in = new Scanner(new File("a.txt"));
		int caso = 1;
		FileWriter out = new FileWriter(new File("b.txt"));
		int q = in.nextInt();
		while(q>0){
			BigInteger r = new BigInteger(in.next());
			BigInteger r1 = new BigInteger("4");
			BigInteger t = new BigInteger(in.next());
			BigInteger soma;
			BigInteger resposta = null;
			BigInteger ini = new BigInteger("1");
			BigInteger fim = new BigInteger("10000000000");
			BigInteger meio;
			while(true){
				meio = ini.add(fim);
				meio = meio.divide(new BigInteger("2"));
				//System.out.println(ini.toString()+ " " + fim.toString() + " meio " + meio.toString() );
				soma = new BigInteger("2").multiply(r);
				soma = soma.add(new BigInteger("1"));
				soma = soma.multiply(new BigInteger("2")).add(r1.multiply(meio)).subtract(r1) ;
				soma = soma.multiply(meio);
				soma = soma.divide(new BigInteger("2"));
				//System.out.println(soma.toString() + " " + t.toString() + " " + soma.compareTo(t));
				if(ini.compareTo(fim) >= 0){
					break;
				}
				if(soma.compareTo(t) > 0){
					fim = meio;
				}else{
					resposta = meio;
					ini = meio.add(new BigInteger("1"));
				}
			}
			out.append("Case #"+ caso + ": ");
			out.append(resposta.toString()+"\n");
			caso++;
			q--;
		}
		
		
		in.close();
		out.close();
	}

}
