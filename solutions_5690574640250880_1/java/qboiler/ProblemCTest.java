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
public class ProblemCTest {
    
    public ProblemCTest() {
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
    @Ignore
    public void testTestCase() throws Exception {
        System.out.println("process");
        String fileName = "/Users/bryce/projects/proto/codejam/inputs/2014/QR/C-testA";
        ProblemC instance = new ProblemC();
        instance.process(fileName);
    }  
    @Test
    @Ignore
    public void testSmall() throws Exception {
        System.out.println("process");
        String fileName = "/Users/bryce/projects/proto/codejam/inputs/2014/QR/C-small-attempt4";
        ProblemC instance = new ProblemC();
        instance.process(fileName);
    }  
    @Test
    public void testLarge() throws Exception {
        System.out.println("process");
        String fileName = "/Users/bryce/projects/proto/codejam/inputs/2014/QR/C-large";
        ProblemC instance = new ProblemC();
        instance.process(fileName);
    }  
    
}
