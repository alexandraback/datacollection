/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dijkstra;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author Sammy Guergachi <sguergachi at gmail.com>
 */
public class Dijkstra {

    public static String multiplication(String q1, char q2) {
        switch (q2) {
            case 'i':
                switch (q1) {
                    case "1":
                        return "i";
                    case "-1":
                        return "-i";
                    case "i":
                        return "-1";
                    case "-i":
                        return "1";
                    case "j":
                        return "-k";
                    case "-j":
                        return "k";
                    case "k":
                        return "j";
                    case "-k":
                        return "-j";
                }
            case 'j':
                switch (q1) {
                    case "1":
                        return "j";
                    case "-1":
                        return "-j";
                    case "i":
                        return "k";
                    case "-i":
                        return "-k";
                    case "j":
                        return "-1";
                    case "-j":
                        return "1";
                    case "k":
                        return "-i";
                    case "-k":
                        return "i";
                }
            case 'k':
                switch (q1) {
                    case "1":
                        return "k";
                    case "-1":
                        return "-k";
                    case "i":
                        return "-j";
                    case "-i":
                        return "j";
                    case "j":
                        return "i";
                    case "-j":
                        return "-i";
                    case "k":
                        return "-1";
                    case "-k":
                        return "1";
                }
        }
        return null;
    }

    public static String multiplication(String q1, String q2) {
        switch (q2) {
            case "1":
                switch (q1) {
                    case "1":
                        return "1";
                    case "-1":
                        return "-1";
                    case "i":
                        return "i";
                    case "-i":
                        return "-i";
                    case "j":
                        return "j";
                    case "-j":
                        return "-j";
                    case "k":
                        return "k";
                    case "-k":
                        return "-k";
                }
            case "-1":
                switch (q1) {
                    case "1":
                        return "-1";
                    case "-1":
                        return "1";
                    case "i":
                        return "-i";
                    case "-i":
                        return "i";
                    case "j":
                        return "-j";
                    case "-j":
                        return "j";
                    case "k":
                        return "-k";
                    case "-k":
                        return "k";
                }
            case "i":
                switch (q1) {
                    case "1":
                        return "i";
                    case "-1":
                        return "-i";
                    case "i":
                        return "-1";
                    case "-i":
                        return "1";
                    case "j":
                        return "-k";
                    case "-j":
                        return "k";
                    case "k":
                        return "j";
                    case "-k":
                        return "-j";
                }
            case "-i":
                switch (q1) {
                    case "1":
                        return "-i";
                    case "-1":
                        return "i";
                    case "i":
                        return "1";
                    case "-i":
                        return "-1";
                    case "j":
                        return "k";
                    case "-j":
                        return "-k";
                    case "k":
                        return "-j";
                    case "-k":
                        return "j";
                }
            case "j":
                switch (q1) {
                    case "1":
                        return "j";
                    case "-1":
                        return "-j";
                    case "i":
                        return "k";
                    case "-i":
                        return "-k";
                    case "j":
                        return "-1";
                    case "-j":
                        return "1";
                    case "k":
                        return "-i";
                    case "-k":
                        return "i";
                }
            case "-j":
                switch (q1) {
                    case "1":
                        return "-j";
                    case "-1":
                        return "j";
                    case "i":
                        return "-k";
                    case "-i":
                        return "k";
                    case "j":
                        return "1";
                    case "-j":
                        return "-1";
                    case "k":
                        return "i";
                    case "-k":
                        return "-i";
                }
            case "k":
                switch (q1) {
                    case "1":
                        return "k";
                    case "-1":
                        return "-k";
                    case "i":
                        return "-j";
                    case "-i":
                        return "j";
                    case "j":
                        return "i";
                    case "-j":
                        return "-i";
                    case "k":
                        return "-1";
                    case "-k":
                        return "1";
            }
            case "-k":
                switch (q1) {
                    case "1":
                        return "-k";
                    case "-1":
                        return "k";
                    case "i":
                        return "j";
                    case "-i":
                        return "-j";
                    case "j":
                        return "-i";
                    case "-j":
                        return "i";
                    case "k":
                        return "1";
                    case "-k":
                        return "-1";
            }
        }
        return null;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        File inputFile = new File("largeInput.txt");
        FileReader reader = null;
        BufferedReader bufferedReader = null;

        File outputFile = new File("largeOutput.txt");

        try {
            reader = new FileReader(inputFile);
            bufferedReader = new BufferedReader(reader);
            String line = bufferedReader.readLine();

            int pos = 1;
            
            while ((line = bufferedReader.readLine()) != null) {
                String[] numbers = line.split(" ");
                Long length = Long.parseLong(numbers[0]);
                Long times = Long.parseLong(numbers[1]);

                line = bufferedReader.readLine();
                ArrayList<String> array = new ArrayList<>(line.length());
                array.add(multiplication("1", line.charAt(0)));
                for (int i = 1; i < line.length(); ++i) {
                    array.add(multiplication(array.get(i - 1), line.charAt(i)));
                }

                String equivalentQ = array.get(array.size() - 1);
                if ("-1".equals(equivalentQ) && times%2 == 1) {
                    boolean foundI = false;
                    boolean foundK = false;
                    for (int i = 0; i < array.size(); ++i) {
                        if ("i".equals(array.get(i))) {
                            foundI = true;
                        }
                        if (foundI && "k".equals(array.get(i))) {
                            foundK = true;
                        }
                    }
                    if (times > 1) {
                        for (int i = 0; i < array.size(); ++i) {
                            if ("-i".equals(array.get(i))) {
                                foundI = true;
                            }
                            if (foundI && "-k".equals(array.get(i))) {
                                foundK = true;
                            }
                        }
                    }
                    if (times > 2) {
                        for (int i = 0; i < array.size(); ++i) {
                            if ("i".equals(array.get(i))) {
                                foundI = true;
                            }
                            if (foundI && "k".equals(array.get(i))) {
                                foundK = true;
                            }
                        }
                    }
                    if (times > 3) {
                        for (int i = 0; i < array.size(); ++i) {
                            if ("-i".equals(array.get(i))) {
                                foundI = true;
                            }
                            if (foundI && "-k".equals(array.get(i))) {
                                foundK = true;
                            }
                        }
                    }
                    if (foundI && foundK) {
                        System.out.println("Case #" + pos + ": YES");
                    } else {
                        System.out.println("Case #" + pos + ": NO");
                    }
                } else if (("i".equals(equivalentQ) || "j".equals(equivalentQ) || "k".equals(equivalentQ) ||
                            "-i".equals(equivalentQ) || "-j".equals(equivalentQ) || "-k".equals(equivalentQ)) && times%4 == 2) {
                    boolean foundI = false;
                    boolean foundK = false;

                    for (int i = 0; i < array.size(); ++i) {
                        if ("i".equals(array.get(i))) {
                            foundI = true;
                        }
                        if (foundI && "k".equals(array.get(i))) {
                            foundK = true;
                        }
                    }
                    for (int i = 0; i < array.size(); ++i) {
                        if ("i".equals(multiplication(equivalentQ, array.get(i)))) {
                            foundI = true;
                        }
                        if (foundI && "k".equals(multiplication(equivalentQ, array.get(i)))) {
                            foundK = true;
                        }
                    }
                    if (times > 2) {
                        for (int i = 0; i < array.size(); ++i) {
                            if ("-i".equals(array.get(i))) {
                                foundI = true;
                            }
                            if (foundI && "-k".equals(array.get(i))) {
                                foundK = true;
                            }
                        }
                        for (int i = 0; i < array.size(); ++i) {
                            if ("-i".equals(multiplication(equivalentQ, array.get(i)))) {
                                foundI = true;
                            }
                            if (foundI && "-k".equals(multiplication(equivalentQ, array.get(i)))) {
                                foundK = true;
                            }
                        }
                    }
                    if (times > 4) {
                        for (int i = 0; i < array.size(); ++i) {
                            if ("i".equals(array.get(i))) {
                                foundI = true;
                            }
                            if (foundI && "k".equals(array.get(i))) {
                                foundK = true;
                            }
                        }
                        for (int i = 0; i < array.size(); ++i) {
                            if ("i".equals(multiplication(equivalentQ, array.get(i)))) {
                                foundI = true;
                            }
                            if (foundI && "k".equals(multiplication(equivalentQ, array.get(i)))) {
                                foundK = true;
                            }
                        }
                    }
                    if (times > 6) {
                        for (int i = 0; i < array.size(); ++i) {
                            if ("-i".equals(array.get(i))) {
                                foundI = true;
                            }
                            if (foundI && "-k".equals(array.get(i))) {
                                foundK = true;
                            }
                        }
                        for (int i = 0; i < array.size(); ++i) {
                            if ("-i".equals(multiplication(equivalentQ, array.get(i)))) {
                                foundI = true;
                            }
                            if (foundI && "-k".equals(multiplication(equivalentQ, array.get(i)))) {
                                foundK = true;
                            }
                        }
                    }
                    if (foundI && foundK) {
                        System.out.println("Case #" + pos + ": YES");
                    } else {
                        System.out.println("Case #" + pos + ": NO");
                    }
                } else {
                    System.out.println("Case #" + pos + ": NO");
                }
                pos++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    
}
