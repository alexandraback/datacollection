package org.active.nerd.code.jam;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collection;

public abstract class LineReader<T extends Result> {

	public abstract Collection<Result> parse(BufferedReader reader) throws NumberFormatException, IOException;
	
}
