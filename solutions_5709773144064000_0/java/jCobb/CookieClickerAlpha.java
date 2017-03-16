/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam2014;

import InputOutput.IOHandle;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/**
 *
 * @author kando
 */
public class CookieClickerAlpha {
    
    private double initRate = 2.0;
    
    public CookieClickerAlpha() {
        IOHandle ioh = new IOHandle("input.in","output.out");
        
        int numberOfCases = Integer.parseInt(ioh.getLine());
        
        for(int i=0;i<numberOfCases;i++) {
            ioh.addLine(caseResult(i+1, ioh));
        }
        
        ioh.flush();
    }
    
    private String caseResult(int index, IOHandle ioh) {
        double[] line = ioh.getLineDoubles();
        
        double actPrice = line[0];
        double actRate = initRate;
        double actRateInc = line[1];
        double actTarget = line[2];
        double actTime = actTarget / actRate;
        
        while((actTarget / actRate) > (actPrice/actRate + actTarget/(actRate + actRateInc))) {
            actTime -= (actTarget / actRate) - (actPrice/actRate + actTarget/(actRate + actRateInc));
            actRate += actRateInc;
        }
        
        return "Case #"+index+": "+String.format(Locale.US,"%.7f", actTime);
    }
}
