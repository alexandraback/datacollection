package com.dten.cj.r1b;

import static org.hamcrest.Matchers.equalTo;
import static org.hamcrest.Matchers.is;
import static org.junit.Assert.assertThat;

import java.io.File;
import java.io.IOException;

import org.apache.commons.io.FileUtils;
import org.apache.commons.lang3.StringUtils;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.dten.cj.r1c.A;

public class ATest {

	A	a;

	@Before
	public void setup() {
		a = new A();
	}

	@Test
	public void exampleFile() throws IOException {
		String expected = StringUtils.join(
				new String[] { "Case #1: No", "Case #2: Yes", "Case #3: Yes" }, "\r\n").trim();

		assertThat(a.processFile("r1c/A-example.in"), is(true));
		assertThat(FileUtils.readFileToString(new File("outputs/r1c/A-example.out")),
				is(equalTo(expected)));
	}

	@Test
	public void smallFile() {
		assertThat(a.processFile("r1c/A-small-attempt0.in"), is(true));
	}

	@Ignore
	@Test
	public void largeFile() {
		assertThat(a.processFile("r1c/A-large.in"), is(true));
	}
}
