from sys import stdin

TESTSET = [
    ("ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "our language is impossible to understand"),
   ("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "there are twenty six factorial possibilities"),
   ("de kr kd eoya kw aej tysr re ujdr lkgc jv",
    "so it is okay if you want to just give up")]



mapping = dict((x, y) for a, b in TESTSET for x, y in zip(a, b))
mapping['q'] = 'z'
mapping['z'] = 'q'

def translate(st, mapping):
    return ''.join(mapping[x] for x in st)

def main(mapping):
    cases = int(stdin.readline())
    for i in range(1, cases+1):
        st = stdin.readline().strip()
        print "Case #%d: %s" % (i, translate(st, mapping))

if __name__ == "__main__":
    #print mapping
    main(mapping)
