/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.brycealcock.codejam.y2014.qr;

import com.brycealcock.codejam.Case;
import java.io.BufferedReader;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;
import org.junit.Ignore;

/**
 *
 * @author bryce
 */
public class ProblemDTest {

    public ProblemDTest() {
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    @Test
//    @Ignore
    public void testSmall() throws Exception {
        System.out.println("process");
        String fileName = "/Users/bryce/projects/proto/codejam/inputs/2014/QR/D-large";
        ProblemD instance = new ProblemD();
        instance.process(fileName);
    }

}
