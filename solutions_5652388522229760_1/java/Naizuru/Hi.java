import java.util.ArrayList;
import java.util.Scanner;



public class Hi {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int numCases = input.nextInt();
		for(int n =0;n<numCases;n++){
			long numero = input.nextLong();
			long copyNum = numero;
			ArrayList<Boolean> lista = new ArrayList<Boolean>();
			for(int i=0;i<10;i++){lista.add(false);}
			numero = numero % 10;
			numbers(numero,lista);
			Boolean salir = false;
			long i = 1;
			while(!salir && i<1000){
				long reg = copyNum*i;
				numbers(reg,lista);
				salir = true;
				for(Boolean aux:lista){
					if (!aux){
						i++;
						salir = false;
						break;
						}
				}
			}
			if (i >= 1000){System.out.println("Case #"+(n+1)+": INSOMNIA");}else{
			System.out.println("Case #"+(n+1)+": "+(copyNum*i));}
		}
	}
	
	public static void numbers(long num, ArrayList<Boolean> numero){
		
		long loco = num;
		long pos ;
		boolean salir = false;
		while (!salir){
			
			
			pos = loco % 10;
			numero.set((int) pos,true);
			loco = loco / 10;
			if(loco == 0){salir = true;}
			
		}
	}

}
