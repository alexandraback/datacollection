import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.LongStream;

public class Fractiles {

	public static void main(String[] args) throws IOException {
		List<String> readAllLines = Files.readAllLines(Paths.get("J:\\dev\\eclipse\\imports\\D-large.in"));
		BufferedWriter writer = Files.newBufferedWriter(Paths.get("J:\\dev\\eclipse\\imports\\outputFractilesLarge.txt"),
				StandardOpenOption.CREATE, StandardOpenOption.WRITE);
		for (int i = 1; i < readAllLines.size(); i++) {
			String string = readAllLines.get(i);
			String[] split = string.split("\\s");
			String count = getFractalsanswer(Long.valueOf(split[0]), Long.valueOf(split[1]), Long.valueOf(split[2]));
			if (i != 1)
				writer.newLine();
			writer.write("Case #" + i + ":" + count);

		}
		writer.flush();
		writer.close();
	}

	private static List<Long> getStudentPositions(long tiles, long level, long students) {
		if (tiles > students && level == 1) {
			return new ArrayList<>();
		}
		if (Math.ceil(tiles / (double) level) > students) {
			return new ArrayList<>();
		}
		if (tiles <= level) {
			long pos = 1;
			for (int l = 2; l <= Math.min(level, tiles); l++) {
				pos = evaluateNextPos(tiles, pos, l);
			}
			return Arrays.asList(Long.valueOf(pos));
		}

		double ceil = Math.ceil(tiles / (double) level);

		List<Long> list = LongStream.range(1, (long) (ceil + 1)).boxed().collect(Collectors.toList());
		for (int i = 0; i < ceil; i++) {
			long pos = 0;
			for (int j = 1; j <= level; j++) {
				int t = (int) (i  * level + j);
				if (t > tiles) {
					t = j;
				}
				pos = evaluateNextPos(tiles, pos, t);
			}
			list.set(i, Long.valueOf(pos));
		}

		return list;

	}

	private static long evaluateNextPos(long tiles, long pos, int t) {
		if(pos == 0) return t;
		return (pos - 1) * tiles + t;
	}

	public static String getFractalsanswer(Long long1, Long long2, Long long3) {
		List<Long> studentPositions = getStudentPositions(long1, long2, long3);
		if (studentPositions.isEmpty()) {
			return " IMPOSSIBLE";
		}
		String ret = "";
		for (Long longe : studentPositions) {
			ret += " " + longe;
		}

		return ret;
	}

}
