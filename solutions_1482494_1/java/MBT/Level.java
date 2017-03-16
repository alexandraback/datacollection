/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

/**
 *
 * @author Sohail
 */
public class Level {
 public   int ai  ; 
 public   int bi  ;
 public boolean attempted;
 public boolean accomplished ;
 public Level(int ai , int bi)
 {
 this.ai = ai;
 this.bi = bi;
 attempted = false;
 accomplished = false;
 }
}
