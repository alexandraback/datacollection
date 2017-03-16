/**
 * 
 */
package hu.herba.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;

/**
 * Base functionality, helper functions for CodeJam problem solver utilities.
 * 
 * @author csorbazoli
 */
public abstract class AbstractCodeJamBase {
    private static final String EXT_OUT = ".out";
    protected static final int STREAM_TYPE = 0;
    protected static final int FILE_TYPE = 1;
    protected static final int READER_TYPE = 2;
    private static final String DEFAULT_INPUT = "test_input";
    private static final String DEFAULT_OUTPUT = "test_output";

    private final File inputFolder;
    private final File outputFolder;

    public AbstractCodeJamBase(String[] args, int type) {
	String inputFolderName = AbstractCodeJamBase.DEFAULT_INPUT;
	String outputFolderName = AbstractCodeJamBase.DEFAULT_OUTPUT;
	if (args.length > 0) {
	    inputFolderName = args[0];
	}
	this.inputFolder = new File(inputFolderName);
	if (!this.inputFolder.exists()) {
	    this.showUsage("Input folder '" + this.inputFolder.getAbsolutePath() + "' not exists!");
	}
	if (args.length > 1) {
	    outputFolderName = args[1];
	}
	this.outputFolder = new File(outputFolderName);
	if (this.outputFolder.exists() && !this.outputFolder.canWrite()) {
	    this.showUsage("Output folder '" + this.outputFolder.getAbsolutePath() + "' not writeable!");
	} else if (!this.outputFolder.exists() && !this.outputFolder.mkdirs()) {
	    this.showUsage("Could not create output folder '" + this.outputFolder.getAbsolutePath() + "'!");
	}
	File[] inputFiles = this.inputFolder.listFiles();
	for (File inputFile : inputFiles) {
	    this.processInputFile(inputFile, type);
	}
    }

    /**
     * @return the inputFolder
     */
    public File getInputFolder() {
	return this.inputFolder;
    }

    /**
     * @return the outputFolder
     */
    public File getOutputFolder() {
	return this.outputFolder;
    }

    /**
     * @param input
     *            input reader
     * @param output
     *            output writer
     * @throws IOException
     *             in case input or output fails
     * @throws IllegalArgumentException
     *             in case the given input is invalid
     */
    @SuppressWarnings("unused")
    protected void process(BufferedReader reader, PrintWriter pw) throws IOException, IllegalArgumentException {
	System.out.println("NEED TO IMPLEMENT (reader/writer)!!!");
	System.exit(-2);
    }

    /**
     * @param input
     *            input file
     * @param output
     *            output file (will be overwritten)
     * @throws IOException
     *             in case input or output fails
     * @throws IllegalArgumentException
     *             in case the given input is invalid
     */
    protected void process(File input, File output) throws IOException, IllegalArgumentException {
	System.out.println("NEED TO IMPLEMENT (file/file)!!!");
	System.exit(-2);
    }

    /**
     * @param input
     *            input stream
     * @param output
     *            output stream
     * @throws IOException
     *             in case input or output fails
     * @throws IllegalArgumentException
     *             in case the given input is invalid
     */
    protected void process(InputStream input, OutputStream output) throws IOException, IllegalArgumentException {
	System.out.println("NEED TO IMPLEMENT (stream/stream)!!!");
	System.exit(-2);
    }

    /**
     * @param type
     * @param input
     * @param output
     */
    private void processInputFile(File input, int type) {
	long starttime = System.currentTimeMillis();
	System.out.println("Processing '" + input.getAbsolutePath() + "'...");
	File output = new File(this.outputFolder, input.getName() + AbstractCodeJamBase.EXT_OUT);
	if (type == AbstractCodeJamBase.STREAM_TYPE) {
	    InputStream is = null;
	    OutputStream os = null;
	    try {
		is = new FileInputStream(input);
		os = new FileOutputStream(output);
		this.process(is, os);
	    } catch (FileNotFoundException e) {
		this.showUsage("FileNotFound: " + e.getLocalizedMessage());
	    } catch (IllegalArgumentException excIA) {
		this.showUsage(excIA.getLocalizedMessage());
	    } catch (Exception exc) {
		System.out.println("Program failed: " + exc.getLocalizedMessage());
		exc.printStackTrace(System.out);
	    } finally {
		if (is != null) {
		    try {
			is.close();
		    } catch (IOException e) {
			System.out.println("Failed to close input: " + e.getLocalizedMessage());
		    }
		}
		if (os != null) {
		    try {
			os.close();
		    } catch (IOException e) {
			System.out.println("Failed to close output: " + e.getLocalizedMessage());
		    }
		}
	    }
	} else if (type == AbstractCodeJamBase.READER_TYPE) {
	    BufferedReader reader = null;
	    PrintWriter pw = null;
	    try {
		reader = new BufferedReader(new FileReader(input));
		pw = new PrintWriter(output);
		this.process(reader, pw);
	    } catch (FileNotFoundException e) {
		this.showUsage("FileNotFound: " + e.getLocalizedMessage());
	    } catch (IllegalArgumentException excIA) {
		this.showUsage(excIA.getLocalizedMessage());
	    } catch (Exception exc) {
		System.out.println("Program failed: " + exc.getLocalizedMessage());
		exc.printStackTrace(System.out);
	    } finally {
		if (reader != null) {
		    try {
			reader.close();
		    } catch (IOException e) {
			System.out.println("Failed to close input: " + e.getLocalizedMessage());
		    }
		}
		if (pw != null) {
		    pw.close();
		}
	    }
	} else if (type == AbstractCodeJamBase.FILE_TYPE) {
	    try {
		this.process(input, output);
	    } catch (IllegalArgumentException excIA) {
		this.showUsage(excIA.getLocalizedMessage());
	    } catch (Exception exc) {
		System.out.println("Program failed: " + exc.getLocalizedMessage());
		exc.printStackTrace(System.out);
	    }
	} else {
	    this.showUsage("Unknown type given: " + type + " (accepted values: 0,1)");
	}
	System.out.println("  READY (" + (System.currentTimeMillis() - starttime) + " ms)");
    }

    /**
     * Read a single number from input
     * 
     * @param reader
     * @param purpose
     *            What is the purpose of given data
     * @return
     * @throws IOException
     * @throws IllegalArgumentException
     */
    protected int readInt(BufferedReader reader, String purpose) throws IOException, IllegalArgumentException {
	int ret = 0;
	String line = reader.readLine();
	if (line == null) {
	    throw new IllegalArgumentException("Invalid input: line is empty, it should be an integer (" + purpose + ")!");
	}
	try {
	    ret = Integer.parseInt(line);
	} catch (NumberFormatException excNF) {
	    throw new IllegalArgumentException("Invalid input: the first line '" + line + "' should be an integer (" + purpose + ")!");
	}
	return ret;
    }

    /**
     * Read array of integers
     * 
     * @param reader
     * @param purpose
     * @return
     */
    protected int[] readIntArray(BufferedReader reader, String purpose) throws IOException {
	int[] ret = null;
	String line = reader.readLine();
	if (line == null) {
	    throw new IllegalArgumentException("Invalid input: line is empty, it should be an integer list (" + purpose + ")!");
	}
	String[] strArr = line.split("\\s");
	int len = strArr.length;
	ret = new int[len];
	for (int i = 0; i < len; i++) {
	    try {
		ret[i] = Integer.parseInt(strArr[i]);
	    } catch (NumberFormatException excNF) {
		throw new IllegalArgumentException("Invalid input: line '" + line + "' should be an integer list (" + purpose + ")!");
	    }
	}
	return ret;
    }

    /**
     * Read array of strings
     * 
     * @param reader
     * @param purpose
     * @return
     */
    protected String[] readStringArray(BufferedReader reader, String purpose) throws IOException {
	String[] ret = null;
	String line = reader.readLine();
	if (line == null) {
	    throw new IllegalArgumentException("Invalid input: line is empty, it should be a string list (" + purpose + ")!");
	}
	ret = line.split("\\s");
	return ret == null ? new String[0] : ret;
    }

    /**
     * Basic usage pattern. Can be overwritten by current implementation
     * 
     * @param message
     *            Short message, describing the problem with given program
     *            arguments
     */
    protected void showUsage(String message) {
	if (message != null) {
	    System.out.println(message);
	}
	System.out.println("Usage:");
	System.out.println("\t" + this.getClass().getName() + " program");
	System.out.println("\tArguments:");
	System.out.println("\t\t<input folder>:\tpath of input folder (default: " + AbstractCodeJamBase.DEFAULT_INPUT + ").");
	System.out.println("\t\t               \tAll files will be processed in the folder");
	System.out.println("\t\t<output folder>:\tpath of output folder (default: " + AbstractCodeJamBase.DEFAULT_OUTPUT + ")");
	System.out.println("\t\t               \tOutput file name will be the same as input");
	System.out.println("\t\t               \tinput with extension '.out'");
	System.exit(-1);
    }
}
