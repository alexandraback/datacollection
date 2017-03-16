import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {
	private static String resolver(int n, int m, BufferedReader entrada) throws Exception {
		byte[] n_min = new byte[n];
		for(int i = 0; i < n; i++)
			n_min[i] = 0;
		byte[] m_min = new byte[m];
		for(int i = 0; i < m; i++)
			m_min[i] = 0;
		byte[][] lawn = new byte[n][m];
		for(int i = 0; i < n; i++) {
			String[] pedazos = entrada.readLine().trim().split(" ");
			for(int j = 0; j < pedazos.length; j++) {
				byte value = Byte.parseByte(pedazos[j]);
				lawn[i][j] = value;
				if(value > n_min[i])
					n_min[i] = value;
				if(value > m_min[j])
					m_min[j] = value;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(lawn[i][j] < n_min[i] && lawn[i][j] < m_min[j])
					return "NO";
			}
		}
		
		
		
		return "YES";
	}
	
	public static void main(String[] args) throws Exception {
        System.out.println("?");
        BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
        String tipo = lector.readLine().trim();
        BufferedReader entrada = new BufferedReader(new InputStreamReader(new FileInputStream(tipo + ".in")));
        BufferedWriter salida = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(tipo + ".out")));
        int casos = Integer.parseInt(entrada.readLine());
        int contador = 1;
        while(casos > 0) {
        	String[] parametros = entrada.readLine().trim().split(" ");
        	int n = Integer.parseInt(parametros[0]);
        	int m = Integer.parseInt(parametros[1]);
            salida.write("Case #" + contador + ": " + resolver(n, m, entrada) + "\n");
            contador++;
            casos--;
        }
        entrada.close();
        salida.close();
        System.out.println("Fin");
    }
}
