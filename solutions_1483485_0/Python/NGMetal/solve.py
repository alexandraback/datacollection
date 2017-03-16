import sys
from itertools import izip

fout = open("out", "w")
if __name__ == "__main__":
    fp = open(sys.argv[1])
    example = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
    example += "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
    example += "de kr kd eoya kw aej tysr re ujdr lkgc jvqeaz"

    res = "our language is impossible to understand"
    res += "there are twenty six factorial possibilities"
    res += "so it is okay if you want to just give upzoyq"

    dic = {}
    for google, letter in izip(example, res):
        dic[google] = letter

    for case in range(1, int(fp.readline())+1):
        G = fp.readline().strip()
        fout.write("Case #{}: ".format(case) + "".join([dic[g] for g in G]) + "\n")
        
