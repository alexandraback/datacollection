package com.google;

import java.io.*;
import java.util.concurrent.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public interface SolutionFactory<V> {
	Callable<V> read(BufferedReader br) throws IOException;
}
