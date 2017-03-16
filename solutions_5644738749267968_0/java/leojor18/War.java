package codejam;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class War extends JamBase {

	private Scanner scanner;
	
	public int juegosJustosGanados(double[] playerUno, double[] playerDos) {
		return playerDos.length -juegosTrucoGanados(playerDos, playerUno);
	}

	public int juegosTrucoGanados(double[] playerUno, double[] playerDos) {
		int juegosGanados =0;
		int indicePlayerUno = playerUno.length-1;
		for (int i = playerDos.length -1; i >= 0; i--) {
			if(playerUno[indicePlayerUno]> playerDos[i]){
				indicePlayerUno--;
				juegosGanados++;
			}
		}
		
		return juegosGanados;
	}

	@Override
	public void execute() throws IOException {
		scanner = file.getScanner();
		int numCasos = scanner.nextInt();
		for (int i = 0; i < numCasos; i++) {
			int numValores = scanner.nextInt();
			double[] naomiValues = leerDatosPlayer(numValores);
			double[] kenValues = leerDatosPlayer(numValores);
			Arrays.sort(naomiValues);
			Arrays.sort(kenValues);
			int juegosTrucoGanados = juegosTrucoGanados(naomiValues, kenValues); 
			int juegosGanados = juegosJustosGanados(naomiValues, kenValues);
			file.append(formatRespuesta(i+1, String.format("%d %d", juegosTrucoGanados, juegosGanados)));
			file.newLine();
		}
		scanner.close();
		file.closeFiles();
	}

	private double[] leerDatosPlayer(int numValores) {
		double[] naomiValues = new double[numValores];
		for (int j = 0; j < numValores; j++) {
			naomiValues[j]=scanner.nextDouble();
		}
		return naomiValues;
	}
	
	public static void main(String[] args){
		JamBase jamBase = new War();
		try {
			jamBase.setNameFileIn("warEjemplo");
			jamBase.setNameFileOut("warSmall.out");
			jamBase.execute();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
