package deceitfulWar;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DeceitfulWar {

    public static void main(String[] args) throws IOException {

	String mainDir = "/Users/sergio/Downloads";
	Path path = FileSystems.getDefault().getPath(mainDir, "D-large.in");
	Path outputFile = FileSystems.getDefault().getPath(mainDir,
		"output.txt");

	List<String> inputLines = Files.readAllLines(path,
		StandardCharsets.UTF_8);

	List<String> outputLines = new ArrayList<String>();

	long start = System.currentTimeMillis();

	int numCases = Integer.parseInt(inputLines.get(0));
	int rowForCase = 3;
	for (int i = 0; i < numCases; i++) {

	    int firstLine = (i) * rowForCase + 1;
	    int numBlocks = Integer.parseInt(inputLines.get(firstLine));

	    double[] naomiBlocks = new double[numBlocks];
	    double[] kenBlocks = new double[numBlocks];
	    String[] naomiBlocksStr = inputLines.get(firstLine + 1).split(" ");
	    String[] kenBlocksStr = inputLines.get(firstLine + 2).split(" ");

	    for (int j = 0; j < naomiBlocks.length; j++) {
		naomiBlocks[j] = Double.parseDouble(naomiBlocksStr[j]);
		// System.out.println(naomiBlocks[i] + "<-" +
		// naomiBlocksStr[j]);
	    }
	    Arrays.sort(naomiBlocks);

	    for (int j = 0; j < kenBlocks.length; j++) {
		kenBlocks[j] = Double.parseDouble(kenBlocksStr[j]);
		// System.out.println(kenBlocks[j] + "<-" + kenBlocksStr[j]);
	    }
	    Arrays.sort(kenBlocks);

	    int naomiWarPoints = GetNaomiWarPoints(naomiBlocks, kenBlocks);
	    System.out.println("-------");
	    int naomiDeceitfulWarPoints = GetNaomiDeceitfulWarPoints(
		    naomiBlocks, kenBlocks);

	    String caseResult = "Case #" + (i + 1) + ": "
		    + naomiDeceitfulWarPoints + " " + naomiWarPoints;
	    outputLines.add(caseResult);
	    System.out.println(caseResult);

	}
	System.out.println("Completed: " + (System.currentTimeMillis() - start)
		/ 1000d + " s");

	StandardOpenOption option;
	if (!Files.exists(outputFile)) {
	    option = StandardOpenOption.CREATE_NEW;
	} else {
	    option = StandardOpenOption.TRUNCATE_EXISTING;
	}
	Files.write(outputFile, outputLines, option);

    }

    private static int GetNaomiDeceitfulWarPoints(double[] naomiBlocks,
	    double[] kenBlocks) {
	int score = 0;

	Player naomi = new DeceitfulPlayer(naomiBlocks, kenBlocks);
	Player ken = new Player(kenBlocks);

	return GetNaomiScore(naomi, ken);

    }

    private static int GetNaomiWarPoints(double[] naomiBlocks,
	    double[] kenBlocks) {
	printArray(naomiBlocks, "N:");
	printArray(kenBlocks, "K:");

	Player naomi = new Player(naomiBlocks);
	Player ken = new Player(kenBlocks);

	return GetNaomiScore(naomi, ken);
    }

    private static int GetNaomiScore(Player naomi, Player ken) {
	int score = 0;
	while (naomi.hasBlocks()) {
	    double naomisBlock = naomi.playBlock();
	    Double kensBlock = ken.playBlock(naomisBlock);
	    System.out.println("N:" + naomisBlock + ", K:" + kensBlock);

	    if (naomisBlock > kensBlock)
		score++;
	}

	return score;
    }

    private static void printArray(double[] array, String title) {

	System.out.print(title + " ");
	for (double d : array) {
	    System.out.print(d + " ");
	}
	System.out.println();
    }
}

class Player {

    List<Double> blocks;

    public Player(double[] sortedBlocks) {
	this.blocks = new ArrayList<Double>(sortedBlocks.length);
	for (double d : sortedBlocks) {
	    this.blocks.add(d);
	}
	// Collections.sort(this.blocks);
    }

    public boolean hasBlocks() {
	return this.blocks.size() > 0;
    }

    public double playBlock() {
	return GetMinBlock();
    }

    public Double playBlock(double opponentsBlockValue) {

	if (opponentsBlockValue > max()) {
	    return GetMinBlock();
	} else {
	    return GetMinBlockGreaterThan(opponentsBlockValue, true);
	}
    }

    protected double max() {
	return this.blocks.get(blocks.size() - 1);
    }

    protected double GetMinBlock() {
	return GetBlock(0);
    }

    protected Double GetMinBlockGreaterThan(double minValue, boolean remove) {
	for (int i = 0; i < blocks.size(); i++) {
	    if (blocks.get(i) > minValue) {
		if (remove)
		    return GetBlock(i);
		else
		    return blocks.get(i);
	    }
	}
	return null;
    }

    protected double GetBlock(int index) {
	double value = blocks.get(index);
	blocks.remove(index);
	return value;
    }

}

class DeceitfulPlayer extends Player {

    List<Double> opponentsBlocks;

    public DeceitfulPlayer(double[] sortedBlocks, double[] opponentsBlocks) {
	super(sortedBlocks);
	this.opponentsBlocks = new ArrayList<Double>(opponentsBlocks.length);
	for (double d : opponentsBlocks) {
	    this.opponentsBlocks.add(d);
	}

    }

    @Override
    public double playBlock() {
	double toldValue;
	double realValue = GetMinBlock();

	if (opponentsBlocks.get(0) > realValue && opponentsBlocks.size() == 1) {
	    toldValue = realValue;
	    opponentsBlocks.remove(0);// opponent will play the minimum
	} else if (opponentsBlocks.get(0) > realValue
		&& opponentsBlocks.size() > 1) {
	    // opponent's minimum is > mine, let him play his maximum
	    double opponentMaxValue = opponentsBlocks.get(opponentsBlocks
		    .size() - 1);
	    double opponentMax2Value = opponentsBlocks.get(opponentsBlocks
		    .size() - 2);
	    toldValue = (opponentMax2Value + opponentMaxValue) / 2d;
	    opponentsBlocks.remove(opponentsBlocks.size() - 1);// opponent will
							       // play the
							       // maximum
	} else {
	    Double opponentValue = opponentsBlocks
		    .get(opponentsBlocks.size() - 1);
	    toldValue = opponentValue + (1 - opponentValue)
		    / (opponentsBlocks.size()+1);
	    opponentsBlocks.remove(0);// opponent will play the minimum

	}
	return toldValue;
    }

}
