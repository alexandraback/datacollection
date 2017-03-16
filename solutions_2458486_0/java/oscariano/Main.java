import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {
	private static short[] cofres;
	private static boolean[] comodin;
	private static short[][] llaves_cofre;
	
	public static String resolver(BufferedReader entrada) throws Exception {
		System.out.println("CASO");
		String[] pedazos = entrada.readLine().trim().split(" ");
		System.out.println(pedazos[0] + " " + pedazos[1]);
		int K = Integer.parseInt(pedazos[0]);
		int N = Integer.parseInt(pedazos[1]);
		cofres = new short[N];
		comodin = new boolean[N];
		llaves_cofre = new short[N][];
		for(int i = 0; i < N; i++) {
			cofres[i] = -1;
			comodin[i] = false;
		}
		
		short[] needed = new short[200];
		short[] possessed = new short[200];
		short[] total = new short[200];
		int num_possessed = 0;
		for(int i = 0; i < 200; i++) {
			needed[i] = 0;
			possessed[i] = 0;
			total[i] = 0;
		}
		pedazos = entrada.readLine().trim().split(" ");
		for(int i = 0; i < pedazos.length; i++) {
			int type = Integer.parseInt(pedazos[i]) - 1;
			possessed[type]++;
			total[type]++;
			num_possessed++;
		}
		
		for(int i = 0; i < N; i++) {
			pedazos = entrada.readLine().trim().split(" ");
			int type = Integer.parseInt(pedazos[0]) - 1;
			cofres[i] = (short)type;
			needed[type]++;
			int keys = Integer.parseInt(pedazos[1]);
			llaves_cofre[i] = new short[keys];
			for(int j = 0; j < keys; j++) {
				int n_type = Integer.parseInt(pedazos[2 + j]) - 1;
				if(n_type == type)
					comodin[i] = true;
				llaves_cofre[i][j] = (short)n_type;
				total[n_type]++;
			}
		}
		
		for(int i = 0; i < 200; i++) {
			if(total[i] < needed[i]) {
				return "IMPOSSIBLE";
			}
		}
		
		for(int i = 0; i < N; i++) {
			int type = cofres[i];
			int curr_total = total[type];
			for(int j = 0; j < llaves_cofre[i].length; j++) {
				if(llaves_cofre[i][j] == type)
					curr_total--;
			}
			if(curr_total <= 0)
				return "IMPOSSIBLE";
			
		}
		boolean[] abiertos = new boolean[N];
		for(int i = 0; i < N; i++) {
			abiertos[i] = false;
		}
		String respuesta = resolver(abiertos, needed, possessed, N, num_possessed, "");
		if(respuesta == null)
			return "IMPOSSIBLE";
		return respuesta;
	}
	
	public static String resolver(boolean[] abiertos, short[] needed, short[] possessed, int num_abiertos, int num_possessed, String orden) {
		boolean[] intentado = new boolean[abiertos.length];
		for(int i = 0; i < intentado.length; i++)
			intentado[i] = false;
		
		if(num_possessed <= 0)
			return null;
		
		for(int i = 0; i < abiertos.length; i++) {
			if(abiertos[i])
				continue;
			short key = cofres[i];
			if(possessed[key] == 0)
				continue;
			if(num_abiertos == 1)
				return orden + (i + 1);
			boolean util = llaves_cofre[i].length > 0;
			boolean intentar = comodin[i] || possessed[key] >= needed[key] || llaves_cofre[i].length > 0 || possessed[key] > 1;
			if(!intentar) {
				pruebas:
				for(int j = 0; j < abiertos.length; j++) {
					if(!abiertos[j] && cofres[j] != key) {
						for(int k = 0; k < llaves_cofre[j].length; k++) {
							if(llaves_cofre[j][k] == key) {
								intentar = true;
								break pruebas;
							}
						}
					}
				}
			}
			
			if(intentar) {
				needed[key]--;
				possessed[key]--;
				num_possessed--;
				abiertos[i] = true;
				for(int j = 0; j < llaves_cofre[i].length; j++) {
					possessed[llaves_cofre[i][j]]++;
					num_possessed++;
				}
				intentado[i] = true;
				String resultado = resolver(abiertos, needed, possessed, num_abiertos - 1, num_possessed, orden + (i + 1) + " ");
				if(resultado != null)
					return resultado;
				abiertos[i] = false;
				needed[key]++;
				possessed[key]++;
				num_possessed++;
				for(int j = 0; j < llaves_cofre[i].length; j++) {
					possessed[llaves_cofre[i][j]]--;
					num_possessed--;
				}
			} 
		}
		for(int i = 0; i < abiertos.length; i++) {
			if(abiertos[i])
				continue;
			short key = cofres[i];
			if(possessed[key] == 0)
				continue;
			if(intentado[i])
				continue;
			boolean util = false;
			/*
			for(int j = 0; j < llaves_cofre[i].length; j++) {
				int type = llaves_cofre[i][j];
				if(possessed[type] == 0 && needed[type] > 0) {
					util = true;
					break;
				}
			}*/
			if(llaves_cofre[i].length > 0) util = true;
			if(!util)
				continue;
			
			needed[key]--;
			possessed[key]--;
			num_possessed--;
			abiertos[i] = true;
			for(int j = 0; j < llaves_cofre[i].length; j++) {
				possessed[llaves_cofre[i][j]]++;
				num_possessed++;
			}
			intentado[i] = true;
			String resultado = resolver(abiertos, needed, possessed, num_abiertos - 1, num_possessed, orden + (i + 1) + " ");
			if(resultado != null)
				return resultado;
			abiertos[i] = false;
			needed[key]++;
			possessed[key]++;
			num_possessed++;
			for(int j = 0; j < llaves_cofre[i].length; j++) {
				possessed[llaves_cofre[i][j]]--;
				num_possessed--;
			}
			
		}
		for(int i = 0; i < abiertos.length; i++) {
			if(abiertos[i])
				continue;
			short key = cofres[i];
			if(possessed[key] == 0)
				continue;
			if(intentado[i])
				continue;
			needed[key]--;
			possessed[key]--;
			num_possessed--;
			abiertos[i] = true;
			for(int j = 0; j < llaves_cofre[i].length; j++) {
				possessed[llaves_cofre[i][j]]++;
				num_possessed++;
			}
			intentado[i] = true;
			String resultado = resolver(abiertos, needed, possessed, num_abiertos - 1, num_possessed, orden + (i + 1) + " ");
			if(resultado != null)
				return resultado;
			abiertos[i] = false;
			needed[key]++;
			possessed[key]++;
			num_possessed++;
			for(int j = 0; j < llaves_cofre[i].length; j++) {
				possessed[llaves_cofre[i][j]]--;
				num_possessed--;
			}
			
		}
		return null;
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
            salida.write("Case #" + contador + ": " + resolver(entrada) + "\n");
            contador++;
            casos--;
        }
        entrada.close();
        salida.close();
        System.out.println("Fin");
    }
}
