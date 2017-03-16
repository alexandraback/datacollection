fin = open ("a.in" , "r");
fout = open ("a.out", "w");

d = {'\n': '\n', ' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z' : 'q', 'q' : 'z'};

# for [u, v] in [['e', 'o'], ['j', 'u'], ['p', 'r'], ['m', 'l'], ['y', 'a'], ['s', 'n'], ['l', 'g'], ['c', 'e'], ['k', 'i'], ['d', 's'], ['x', 'm'], ['v', 'p'], ['n', 

for T in range (int (fin.readline ())) :
    s = fin.readline ();
    ans = '';
    for c in s :
        if c in d :
            ans = ans + d[c];
        else :
            ans = ans + '?';
    print ("Case #%d: %s" % (T + 1, ans), end = '', file = fout);

fin.close ();
fout.close ();

# print (d);
