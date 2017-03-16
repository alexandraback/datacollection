import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;

import javax.swing.JFileChooser;

public class Pogo {
	public static void main(String[] argv) {
		JFileChooser fc = new JFileChooser();
		fc.setDialogTitle("Select Input File");
		// Show open dialog for selecting input file
		fc.showOpenDialog(null);
		File selFile = fc.getSelectedFile();

		String data = "";
		String inputFileName = selFile.getName();
		try {
			data = FileHandler.readFile(selFile.getAbsolutePath()); // getting
																	// Data
																	// String
																	// from file

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		// Show save dialog
		fc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		fc.setDialogTitle("Select Output Folder");
		fc.showSaveDialog(null);
		selFile = fc.getSelectedFile();
		data = makeAlgorithm(data);
		FileHandler.writeFile(
				selFile.getAbsolutePath() + "\\"
						+ inputFileName.replace(".in", "") + "-Output.txt",
				data);

	}

	static void quicksort(int array[], int begin, int end) {
		int i = begin, j = end;
		int pivot = array[end];
		while (i <= j) {
			while (array[i] < pivot)
				i++;
			while (array[j] > pivot)
				j--;
			if (i <= j) {
				if (i != j) {
					array[i] ^= array[j];
					array[j] ^= array[i];
					array[i] ^= array[j];
				}
				i++;
				j--;
			}
		}
		if (begin < j)
			quicksort(array, begin, j);
		if (i < end)
			quicksort(array, i, end);
	}

	/**
	 * find the availability of every pattern and returns the output string
	 * 
	 * @param input
	 *            String input data
	 */
	public static String makeAlgorithm(String input) {
		try {
			BufferedReader reader = new BufferedReader(new StringReader(input));
			int testCases = Integer.parseInt(reader.readLine());
			StringBuffer outputBuffer = new StringBuffer();
			for (int i = 0; i < testCases; i++) {
				outputBuffer.append("Case #" + (i + 1) + ": ");
				String[] line = reader.readLine().split(" ");
				int x = Integer.parseInt(line[0]);
				int y = Integer.parseInt(line[1]);
				int movedX = 0;
				int movedY= 0;
				int p=1;
				for(int j=0; j<(2*Math.abs(y))-1; j++)
				{	
					if(y>0)
						outputBuffer.append(j%2==0?"N":"S");
					else
						outputBuffer.append(j%2==0?"S":"N");
					if(y>0)
						movedY += j%2==0?p:-p;
					else
						movedY += j%2==0?-p:p;
					p++;
				}
				
				for(int j=0; j<(2*Math.abs(x))-1; j++)
				{	
					if(j==0)
						if(x>0)
						{
							outputBuffer.append("W");
							movedX -= p;
							p++;
						}
						else
						{
							outputBuffer.append("E");
							movedX += p;
							p++;
						}
						
					if(x>0)
						outputBuffer.append(j%2==0?"E":"W");
					else
						outputBuffer.append(j%2==0?"W":"E");
					if(x>0)
						movedX += j%2==0?p:-p;
					else
						movedX += j%2==0?-p:p;
					p++;
				}
				System.out.println(movedX + " " + movedY);
				outputBuffer.append("\n");

			}
			return outputBuffer.toString();
		} catch (Exception e) {
			e.printStackTrace();
			return "";
		}
	}

}

class FileHandler {

	/**
	 * generates a file with given name and data
	 * 
	 * @param fileName
	 *            name of the file that will be generated
	 * @param data
	 *            data that will be in the file
	 */
	public static void writeFile(String fileName, String data) {
		FileOutputStream fop = null;
		File file;

		try {

			file = new File(fileName);
			fop = new FileOutputStream(file);

			// if file doesnt exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}

			// get the content in bytes
			byte[] contentInBytes = data.getBytes();

			fop.write(contentInBytes);
			fop.flush();
			fop.close();

			System.out.println("Done");

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (fop != null) {
					fop.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	/**
	 * reads a file from given path
	 * 
	 * @param filePath
	 *            the name of the file to open. Not sure if it can accept URLs
	 *            or just filenames. Path handling could be better, and buffer
	 *            sizes are hardcoded
	 */
	public static String readFile(String filePath) throws java.io.IOException {
		StringBuffer fileData = new StringBuffer(1000);
		BufferedReader reader = new BufferedReader(new FileReader(filePath));
		char[] buf = new char[1024];
		int numRead = 0;
		while ((numRead = reader.read(buf)) != -1) {
			String readData = String.valueOf(buf, 0, numRead);
			fileData.append(readData);
			buf = new char[1024];
		}
		reader.close();
		return fileData.toString();
	}

	// insert
}
