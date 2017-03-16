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
public class ProblemBTest {
    
    public ProblemBTest() {
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
        String fileName = "/Users/bryce/projects/proto/codejam/inputs/2014/QR/B-test";
        ProblemB instance = new ProblemB();
        instance.process(fileName);
    }  
    @Test
//    @Ignore
    public void testSmallProcess() throws Exception {
        System.out.println("process");
        String fileName = "/Users/bryce/projects/proto/codejam/inputs/2014/QR/B-large";
        ProblemB instance = new ProblemB();
        instance.process(fileName);
    }
}
