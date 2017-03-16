
from string import maketrans

alphabet1 = "abcdefghijklmnopqrstuvwxyz"
alphabet2 = "yhesocvxduiglbkrztnwjpfmaq"

table = maketrans(alphabet1, alphabet2)

def main():
    with open("input1.txt", "r") as fin:
        with open("output1.txt", "w") as fout:
            T = int(fin.readline())
            for case in xrange(1, T + 1):
                s = fin.readline()
                fout.write("Case #{0}: {1}".format(case, s.translate(table)))

def foo():
    t1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
    t2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

    d = dict(zip(t1, t2))
    print alphabet1
    print "".join(d.get(c, "?") for c in alphabet1)

if __name__ == "__main__":
    main()
