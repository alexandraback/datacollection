/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.brycealcock.codejam.y2014.qr;

import com.brycealcock.codejam.Case;
import com.brycealcock.codejam.CodeJamBase;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author bryce
 */
public class ProblemB extends CodeJamBase {

    @Override
    protected Case readAndProcessCase(int caseNumber, BufferedReader br) throws IOException, NumberFormatException {
        Scanner s = new Scanner(br.readLine());
        return new PCase(caseNumber,s.nextDouble(),s.nextDouble(), s.nextDouble());
    }
    
    class PCase extends Case{
        double cost;
        double rateIncrement;
        double win;
        
        PCase (int caseNumber, double c, double f, double x){
            super(caseNumber);
            cost=c;
            rateIncrement=f;
            win=x;
        }
        String result ;
        

        @Override
        protected String caseResult() {
            return result;
        }

        @Override
        protected Case processCase() {
            boolean more = true;
            double lastTime = Double.MAX_VALUE;
            int i =0;
            while(more){
                double ti= 0d;
                for(int j=0;j<i;++j){
                    ti+=cost/(2.0+j*rateIncrement);
                }
                double tr=win/(2+i*rateIncrement);
                if(tr+ti<lastTime){
                    lastTime = tr+ti;
                    ++i;
                }else{
                    more=false;
                }
            }
            result = String.valueOf(lastTime);
            return this;
        }
    }
}
