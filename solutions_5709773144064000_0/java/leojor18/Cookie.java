package codejam;

import java.io.IOException;
import java.util.Scanner;

public class Cookie extends JamBase {
	private double plusF;
	private double objetivoX;
	private double costoC;
	private int numeroFarm;

	public Double calcularMinSegundos() {
		numeroFarm = 0;
		double tiempoSinMasGanancia;
		double tiempoConMasGanancia;
		double seg = 0;
		double tiempoGetFarm;
		do {
			double gananciaInicial = getGanancia(numeroFarm);
			double gananciaConNuevaFarm = getGanancia(++numeroFarm);
			tiempoSinMasGanancia = objetivoX / gananciaInicial;
			tiempoGetFarm = costoC / gananciaInicial;
			tiempoConMasGanancia = tiempoGetFarm + objetivoX/ gananciaConNuevaFarm;
			seg += tiempoGetFarm;
		} while (tiempoSinMasGanancia > tiempoConMasGanancia);
		numeroFarm--;
		seg = seg - tiempoGetFarm + objetivoX / getGanancia(numeroFarm);
		return seg;
	}

	private double getGanancia(int i) {

		return (2 + i * plusF);
	}

	public int getNumeroFarm() {
		return numeroFarm;
	}

	public void setPlusF(double plusF) {
		this.plusF = plusF;
	}

	public void setObjetivoX(double objetivoX) {
		this.objetivoX = objetivoX;
	}

	public void setCostoC(double costoC) {
		this.costoC = costoC;
	}

	@Override
	public void execute() throws IOException {
		Scanner scanner = file.getScanner();
		int numCasos = scanner.nextInt();
		for (int i = 0; i < numCasos; i++) {
			Cookie cookie = new Cookie();
			cookie.setCostoC(scanner.nextDouble());
			cookie.setPlusF(scanner.nextDouble());
			cookie.setObjetivoX(scanner.nextDouble());
			file.append(formatRespuesta(i+1, String.format("%.7f", cookie.calcularMinSegundos())));
			file.newLine();
		}
		scanner.close();
		file.closeFiles();
	}
	
	public static void main(String[] args){
		JamBase jamBase = new Cookie();
		try {
			jamBase.setNameFileIn("B-small-attempt0.in");
			jamBase.setNameFileOut("cookieSmall.out");
			jamBase.execute();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
