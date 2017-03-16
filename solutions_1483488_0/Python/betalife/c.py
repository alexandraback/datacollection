# from functools import filter;


def check (a, b) :
    global t;
    p, q = str (a), str (b);
    for i in range (t[a]) :
        if q[i:] + q[0:i] == p :
            return True;
    return False;

fin  = open ("c.in" , "r");
fout = open ("c.out", "w");
n = 2255;
t = [len (str (i)) for i in range (n + 2)];
w = [[0] * (n + 2) for i in range (n + 2)];

for i in range (1, n) :
    for j in range (1, n) :
        if t[j] == t[i] and check (i, j) :
            w[i][j] = 1;
# print (w[111]);

for T in range (int (fin.readline ())) :
    A, B = map (int, fin.readline ().split (" "));
    print (T, A, B);
    L = len (str (A));
    ans = 0;
    for i in range (A, B) :
        for j in range (i + 1, B + 1) :
            # if check (i, j) :
            ans += w[i][j];
    print ("Case #%d: %d" % (T + 1, ans), file = fout);
fin.close ();
fout.close ();
