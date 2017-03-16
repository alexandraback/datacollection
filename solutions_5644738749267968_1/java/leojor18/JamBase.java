package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

abstract class JamBase {

	public interface Operable {
		public long resultadoOperacion(long valor);
		public BigInteger resultadoOperacion(BigInteger valor);
	}

	protected ReadWriteFile file = new ReadWriteFile();
	private static BigInteger dosBig = BigInteger.valueOf(2);
	private static BigInteger unoBig = BigInteger.valueOf(1);

	public void setNameFileIn(String archivoIn) throws FileNotFoundException {
		file.setFileReaderName(archivoIn);
	}

	public void setReaderWriter(ReadWriteFile file) {
		this.file = file;
	}

	public void setNameFileOut(String archivoOut) throws IOException {
		file.setFileWriterName(archivoOut);
	}

	public File getOutFile() {
		return file.outFile();
	}

	public String formatRespuesta(int i, String s) {
		return String.format("Case #%d: %s", i, s);
	}
	
	abstract public void execute() throws IOException;
	public static long buscarIgual(long inicio, long fin, long valor, Operable operable) {
		long mitad = (inicio+fin)/2;
		long resultado = operable.resultadoOperacion(mitad);
		if(inicio == fin){
			return valor < resultado? --inicio:inicio;
		}
		if(valor < resultado) {
			return buscarIgual(inicio, mitad - 1, valor, operable);
		}else if(valor > resultado){
			return buscarIgual(mitad+1, fin, valor, operable);
		}
		return mitad;
	}
	public static BigInteger buscarIgual(BigInteger inicio, BigInteger fin, BigInteger valor, Operable operable) {
		BigInteger mitad = inicio.add(fin).divide(dosBig);
		BigInteger resultado = operable.resultadoOperacion(mitad);
		if(inicio.compareTo(fin) == 0){
			return valor.compareTo(resultado) < 0? inicio.add(BigInteger.valueOf(-1)):inicio;
		}
		int comparator = valor.compareTo(resultado);
		if( comparator < 0) {
			return buscarIgual(inicio, mitad, valor, operable);
		}else if(comparator > 0){
			return buscarIgual(mitad.add(unoBig), fin, valor, operable);
		}
		return mitad;
	}

}
