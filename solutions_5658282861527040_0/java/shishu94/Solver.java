package farm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.ObjectInputStream.GetField;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.StringTokenizer;

public class Solver {
	static class Model {
		int A;
		int B;
		int K;
	}

	static Model[] readInputs(String path) throws IOException {
		InputStream ips = new FileInputStream(path);
		InputStreamReader ipsr = new InputStreamReader(ips);
		BufferedReader br = new BufferedReader(ipsr);
		String ligne;

		ligne = br.readLine();
		int casesCount = Integer.parseInt(ligne);
		Model[] arrayModels = new Model[casesCount];

		for (int c = 0; c < casesCount; c++) {
			arrayModels[c] = new Model();
			ligne = br.readLine();
			StringTokenizer tokenizer = new StringTokenizer(ligne);
			arrayModels[c].A = Integer.parseInt(tokenizer.nextToken());
			arrayModels[c].B = Integer.parseInt(tokenizer.nextToken());
			arrayModels[c].K = Integer.parseInt(tokenizer.nextToken());
		}

		br.close();
		return arrayModels;
	}

	static int resolve(Model model) {
		int count = 0;
		for(int a = 0;a<model.A;a++){
			for(int b = 0;b<model.B;b++){
				int bitwise = a&b;
				if(bitwise < model.K){
					count++;
				}
			}
		}
		return count;
	}

	static void writeOutput(int[] awnsers, String path) throws IOException {
		OutputStream ops = new FileOutputStream(path);
		OutputStreamWriter opsr = new OutputStreamWriter(ops);
		BufferedWriter bw = new BufferedWriter(opsr);

		for (int c = 0; c < awnsers.length; c++) {
//			if (awnsers[c] == -1) {
//				bw.write("Case #" + (c + 1) + ": Fegla Won\n");
//			} else {
				bw.write("Case #" + (c + 1) + ": " + awnsers[c] + "\n");
//			}

		}
		bw.close();
	}

	public static void main(String[] args) throws IOException {
		String inputPath = "inputs/B-small-attempt0.in";
		String outputPath = "outputs/B-small-attempt0.ou";
		Model[] models = readInputs(inputPath);
		int[] awnsers = new int[models.length];
		for (int i = 0; i < models.length; i++) {
			awnsers[i] = resolve(models[i]);
		}
		writeOutput(awnsers, outputPath);

	}
}
