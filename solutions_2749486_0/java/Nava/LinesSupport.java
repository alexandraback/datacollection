package com.google.code.jam.third;

import java.util.List;

/**
 * @author: nava
 * @date: 04.05.13
 */
public class LinesSupport {

    private List<String> lines;

    public LinesSupport(List<String> lines) {
        this.lines = lines;
    }

    public String getLine() {
        return lines.remove(0);
    }

    public Input getInput() {
        String line = getLine();
        String[] values = line.split(" ");
        return new Input(Long.valueOf(values[0]), Long.valueOf(values[1])) ;

    }

}
