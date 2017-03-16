package c2013_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class Z3 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\z33.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\C-small-1-attempt0.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\C-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int r = scanner.nextInt();
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int k = scanner.nextInt();
            System.out.println(r+" "+n);
            System.out.println(m+" "+k);
            String s = "Case #" + ti + ": ";
            System.out.println(s);
            out.write(s);
            out.write("\n");
            for (int i=1;i<=r;i++) {
                int [] v = new int[k];
                int f2 = 0;
                int f3 = 0;
                int f4 = 0;
                int f5 = 0;
                int f8 = 0;
                int f16 = 0;
                String res = "";
                for (int j=1;j<=k;j++) {
                    v[j-1] = scanner.nextInt();
                    if (v[j-1]%2==0) {
                        if (f2==0) {
                            f2 = 1;
                        }
                    }
                    if (v[j-1]%3==0) {
                        if (f3==0) {
                            f3 = 1;
                        }
                    }
                    if (v[j-1]%4==0) {
                        if (f4==0) {
                            f4 = 1;
                        }
                    }
                    if (v[j-1]%5==0) {
                        if (f5==0) {
                            f5 = 1;
                        }
                    }
                    if (v[j-1]%8==0) {
                        f8 = 1;
                    }
                    if (v[j-1]%16==0) {
                        f16 = 1;
                    }
                    if (v[j-1]%9==0) {
                        if (f3<2) {
                            f3 = 2;
                        }
                    }
                    if (v[j-1]%25==0) {
                        if (f5<2) {
                            f5 = 2;
                        }
                    }
                    if (v[j-1]%27==0) {
                        f3 = 3;
                        res = "333";
                    }
                    if (v[j-1]%64==0) {
                        f3 = 4;
                        res = "444";
                    }
                    if (v[j-1]%32==0) {
                        f3 = 4;
                        res = "244";
                    }
                    if (v[j-1]%125==0) {
                        f3 = 5;
                        res = "555";
                    }
                }
                if (res.equals("")) {
                    if (f3==2) {
                        if (f5==1) {
                            res = "335";
                        } else {
                            if (f4==1) {
                                res = "334";
                            } else {
                                res = "233";
                            }
                        }
                    } else {
                        if (f5==2) {
                            if (f3==1) {
                                res = "355";
                            } else {
                                if (f4==1) {
                                    res = "455";
                                } else {
                                    res = "255";
                                }
                            }
                        } else {
                            if (f3==1) {
                                if (f5==1) {
                                    if (f4==1) {
                                        res = "345";
                                    } else {
                                        res = "235";
                                    }
                                } else {
                                    if (f16==1) {
                                        res = "344";
                                    } else {
                                        if (f8==1) {
                                            res = "234";
                                        } else {
                                            res = "223";
                                        }
                                    }
                                }
                            } else {
                                if (f5==1) {
                                    if (f16==1) {
                                        res = "445";
                                    } else {
                                        if (f8==1) {
                                            res = "245";
                                        } else {
                                            res = "225";
                                        }
                                    }
                                } else {
                                    if (f16==1){
                                        res = "224";
                                    } else {
                                        res = "222";
                                    }
                                }
                            }
                        }
                    }
                }
                if (res.length()!=n) {
                    res = "222";
                }
                out.write(res);
                out.write("\n");
            }
        }
        out.close();
    }

}
