package codejam;

import java.awt.Point;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Mine extends JamBase {

	private int filas;
	private int columnas;
	private StringBuilder board;
	private int numMinias;

	private static Map<String, Integer> mapaBoard = new HashMap<String, Integer>();
	private int minasGoal;

	public int getN() {
		return minasGoal;
	}

	private Point puntoAnterior = new Point(-1, -1);

	public void setN(int n) {
		this.minasGoal = n;
	}

	public Mine() {

	}

	public Mine(Mine mine) {
		this.columnas = mine.getColumnas();
		this.filas = mine.getFilas();
		this.board = new StringBuilder(mine.getBoard());
		this.numMinias = mine.getNumMinias();
		this.minasGoal = mine.minasGoal;
	}

	public Mine getBoardNMines() {
		if(minasGoal==0){
			numMinias=minasGoal;
			initBoardWithChar('0');
			return this;
		}
		if(minasGoal== filas*columnas-1){
			numMinias=minasGoal;
			initBoardWithChar('*');
			putOnlyOneClic();
			return this;
		}
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				Mine mine = new Mine();
				mine.initBoard(filas, columnas);
				mine.setN(minasGoal);
				mine.putCeroBoard(i, j);
				Mine mineResp = rellenarRecursivo(mine);
				if (mineResp.getNumMinias() == minasGoal) {
					return mineResp;
				}
			}
		}
		return this;
	}

	private void putOnlyOneClic() {
		board.replace(0, 1, "0");
	}

	private Mine rellenarRecursivo(Mine mine) {
		Point posicionPunto = mine.getPosicionPunto();
		if (getPosInString(posicionPunto) < 0) {
			return mine;
		}
		Mine mineTemp = new Mine(mine);
		mineTemp.putCeroBoard(posicionPunto);
		if (mineTemp.getNumMinias() == minasGoal) {
			return mineTemp;
		}
		if (!mapaBoard.containsKey(mineTemp.getBoard())) {
			mapaBoard.put(mineTemp.getBoard(), 0);
			if (mineTemp.getNumMinias() > minasGoal) {
				return rellenarRecursivo(mineTemp);
			}
		}
		return rellenarRecursivo(mine);
	}

	private void putCeroBoard(Point posicion) {
		putCeroBoard(posicion.x, posicion.y);

	}

	private Point getPosicionPunto() {
		for (int i = puntoAnterior.x + 1; i < filas; i++) {
			for (int j = puntoAnterior.y + 1; j < columnas; j++) {
				int posicionPnto = getPosInString(i, j);
				if (board.charAt(posicionPnto) == '.') {
					Point nuevoPunto = new Point(i, j);
					puntoAnterior = nuevoPunto;
					return nuevoPunto;
				}
			}
		}
		return new Point(-1, -1);
	}

	public void initBoard(int filas, int columnas) {
		numMinias = filas * columnas;
		this.filas = filas;
		this.columnas = columnas;

		initBoardWithChar('*');
	}

	private void initBoardWithChar(char c) {
		StringBuilder sbFila = new StringBuilder();
		String fila = "";
		for (int j = 0; j < columnas; j++) {
			sbFila.append(c);
		}
		fila = sbFila.toString();
		StringBuilder sbBoard = new StringBuilder();
		for (int i = 0; i < filas; i++) {
			sbBoard.append(fila);
		}
		board = sbBoard;
	}

	public void putCeroBoard(int fila, int columna) {
		int posicionChartCero = getPosInString(fila, columna);
		if (board.charAt(posicionChartCero) == '0') {
			return;
		}
		if (board.charAt(posicionChartCero) == '*') {
			numMinias--;
		}
		board.replace(posicionChartCero, posicionChartCero + 1, "0");

		for (int i = Math.max(fila - 1, 0); i < Math.min(fila + 2, filas); i++) {

			for (int j = Math.max(columna - 1, 0); j < Math.min(columna + 2,
					columnas); j++) {
				int posicionChart = getPosInString(i, j);
				if (isChartMina(posicionChart)) {
					--numMinias;
					board.replace(posicionChart, posicionChart + 1, ".");
				}
			}
		}
	}
	
	public String getRespuesta(){
		if(numMinias==minasGoal){
			StringBuilder sb = new StringBuilder();
			ubucarPosicionClic();
			for (int i = 0; i < filas; i++) {
				sb.append(board.subSequence(i*columnas, i*columnas + columnas));
				sb.append("\n");
			}
			return sb.toString();
		}
		return "Impossible";
	}

	private void ubucarPosicionClic() {
		boolean encontroPrimerCero = false;
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				int posicion = getPosInString(i, j);
				char charInPosicion = board.charAt(posicion);
				if(!encontroPrimerCero && charInPosicion=='0'){
					board.replace(posicion, posicion+1, "c");
					encontroPrimerCero = true;
					
				}else
					if(charInPosicion != '*')
						board.replace(posicion, posicion+1, ".");
			}
		}
	}
	

	private boolean isChartMina(int posicionChart) {
		return board.charAt(posicionChart) == '*';
	}

	private int getPosInString(int i, int j) {
		return i * columnas + j;
	}

	private int getPosInString(Point posicion) {
		return posicion.x * filas + posicion.y;
	}

	public int getNumMinias() {
		return numMinias;
	}

	public int getFilas() {
		return filas;
	}

	public int getColumnas() {
		return columnas;
	}

	public String getBoard() {
		return board.toString();
	}

	@Override
	public void execute() throws IOException {
		Scanner scanner = file.getScanner();
		int numCasos = scanner.nextInt();
		for (int i = 0; i < numCasos; i++) {
			int filas = scanner.nextInt();
			int columnas = scanner.nextInt();
			int numeroMinas = scanner.nextInt();
			Mine mine = new Mine();
			mine.setN(numeroMinas);
			mine.initBoard(filas, columnas);
			Mine boardFinal = mine.getBoardNMines();
			file.append(String.format("Case #%d:\n%s", i+1,boardFinal.getRespuesta()));
			file.newLine();
		}
		scanner.close();
		file.closeFiles();
	}
	
	public static void main(String[] args){
		JamBase jamBase = new Mine();
		try {
			jamBase.setNameFileIn("minejemplo");
			jamBase.setNameFileOut("salidaBig");
			jamBase.execute();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
