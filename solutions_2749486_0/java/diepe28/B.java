package b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

public class B {

    public static BufferedReader br = null;
    public static BufferedWriter bw = null;
    public static int T, X, Y;
    public static String camino = "";

    public static void pasos(int x, int y, String cadena, int valor) {
        if (!camino.equals("")) {
            return;
        }
        if (x == X && y == Y) {
            if (camino.length() < cadena.length()) {
                camino = cadena;
            }
            return;
        }

        if (cadena.length() > 50) {
            return;
        }

        //System.out.println(x + " , " + y + "  valor: " + valor + "  camino: " + cadena);
        // si estamos en el X
        if (x == X) {
            // norte
            if (y + valor == Y) {
                pasos(x, y + valor, cadena + "N", valor + 1);
            } else {
                // sur
                if (y - valor == Y) {
                    pasos(x, y - valor, cadena + "S", valor + 1);
                } else {
                    // hacia los dos
                    char ultimo = ' ';
                    if (cadena.length() == 0) {
                        ultimo = 'N';
                    } else {
                        ultimo = cadena.charAt(cadena.length() - 1);
                    }
                    if (ultimo == 'N') {
                        pasos(x, y - valor, cadena + "S", valor + 1);
                    } else {
                        pasos(x, y + valor, cadena + "N", valor + 1);
                    }
                }
            }
        } else {
            // si estamos en el Y
            if (y == Y) {
                // este
                if (x + valor == X) {
                    pasos(x + valor, y, cadena + "E", valor + 1);
                } else {
                    // oeste
                    if (x - valor == X) {
                        pasos(x - valor, y, cadena + "W", valor + 1);
                    } else {
                        // hacia los dos
                        char ultimo = ' ';
                        if (cadena.length() == 0) {
                            ultimo = 'E';
                        } else {
                            ultimo = cadena.charAt(cadena.length() - 1);
                        }
                        if (ultimo == 'E') {
                            pasos(x - valor, y, cadena + "W", valor + 1);
                        } else {
                            pasos(x + valor, y, cadena + "E", valor + 1);
                        }
                    }
                }
            } else {
                // si no estamos en ninguno de los dos
                if (cadena.equals("")) {
                    pasos(x + valor, y, cadena + "E", valor + 1);
                    pasos(x, y + valor, cadena + "N", valor + 1);
                    pasos(x - valor, y, cadena + "W", valor + 1);
                    pasos(x, y - valor, cadena + "S", valor + 1);
                } else {
                    char ultimo = cadena.charAt(cadena.length() - 1);
                    if (ultimo == 'N') {
                        pasos(x - valor, y, cadena + "W", valor + 1);
                        pasos(x + valor, y, cadena + "E", valor + 1);
                        pasos(x, y - valor, cadena + "S", valor + 1);
                    } else {
                        if (ultimo == 'S') {
                            pasos(x + valor, y, cadena + "E", valor + 1);
                            pasos(x - valor, y, cadena + "W", valor + 1);
                            pasos(x, y + valor, cadena + "N", valor + 1);
                        } else {
                            if (ultimo == 'E') {
                                pasos(x, y + valor, cadena + "N", valor + 1);
                                pasos(x, y - valor, cadena + "S", valor + 1);
                                pasos(x - valor, y, cadena + "W", valor + 1);
                            } else {
                                if (ultimo == 'W') {
                                    pasos(x, y - valor, cadena + "S", valor + 1);
                                    pasos(x, y + valor, cadena + "N", valor + 1);
                                    pasos(x + valor, y, cadena + "E", valor + 1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        try {
            br = new BufferedReader(new FileReader("B-small-attempt2.in"));
            bw = new BufferedWriter(new FileWriter(new File("B-Output.txt")));
            T = Integer.parseInt(br.readLine());

            int aux = 1;
            while (aux <= T) {
                String linea = br.readLine();
                StringTokenizer st = new StringTokenizer(linea);
                X = Integer.parseInt(st.nextToken());
                Y = Integer.parseInt(st.nextToken());
                camino = "";

                pasos(0, 0, "", 1);
                String sol = "Case #" + aux + ": " + camino;
                System.out.println(sol);
                bw.write(sol + "\n");
                aux++;
            }

            bw.close();
        } catch (Exception ex) {
            Logger.getLogger(B.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
