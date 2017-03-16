/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test;

import java.io.IOException;
import java.io.LineNumberReader;

public class Case {

    private int _e;
    private int _r;
    private int _n;
    private int [] _v;
    
    public static Case readCase(LineNumberReader lnr) throws IOException {
        String line = lnr.readLine();
        String[] parts = line.split(" ");
        int e = Integer.parseInt(parts[0]);
        int r = Integer.parseInt(parts[1]);
        int n = Integer.parseInt(parts[2]);
        int [] v = new int[n];
        line = lnr.readLine();
        parts = line.split(" ");
        for(int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(parts[i]);
        }
        return new Case(e, r, v);
    }

    private Case(int e, int r, int [] v) {
        _e = e;
        _r = r;
        _n = v.length;
        _v = v;
    }
    
    public String solve() {
        int m = 0;
        if(_r >= _e) {
            for(int i = 0; i < _v.length; i++) {
                m += _e * _v[i];
            }
        } else if(_r == 0) {
            int max = 0;
            for(int i = 0; i < _v.length; i++) {
                if(_v[i] > max) {
                    max = _v[i];
                }
            }
            m = max * _e;
        } else {
            m = compute(0, _e);
        }
        
        return Integer.toString(m);
    }
    
    public int compute(int i, int e) {
        int min = Math.max(0, e - _e + _r);
        int g = 0;
        for(int ei = min; ei <= e; ei++) {
            int gc = 0;
            int gi = ei * _v[i];
            if(i < _n - 1) {
                gc = compute(i + 1, e - ei + _r);
            }
            g = Math.max(g, gc + gi);
        }
        return g;
    }
}
