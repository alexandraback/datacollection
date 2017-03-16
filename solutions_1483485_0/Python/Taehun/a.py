#!/usr/bin/python

import sys

tran = {'a':'y', 'b':'h', 'c':'e', 'd':'s', 'e':'o', 'f':'c', 'g':'v',
        'h':'x', 'i':'d', 'j':'u', 'k':'i', 'l':'g', 'm':'l', 'n':'b',
        'o':'k', 'p':'r', 'q':'z', 'r':'t', 's':'n', 't':'w', 'u':'j', 
        'v':'p', 'w':'f', 'x':'m', 'y':'a', 'z':'q'}

def main(argv):
    if len(argv) != 2:
        print "Usage:", argv[0], "<input file>"
        return

    f = open(argv[1], "r")  
    o = open(argv[1]+".out", "w")  
    cc = int(f.readline())  
    print cc, "cases"  
    for c in range(cc):  
        s = f.readline()[:-1]
        ret = ""
        for i in range(len(s)):
            if not s[i] == ' ':
                ret = ret + tran[s[i]]
            else:
                ret = ret + s[i]

        o.write("Case #%d: %s\n" % (c+1, ret))  
    o.close()  

if __name__ == "__main__":
    main(sys.argv)
