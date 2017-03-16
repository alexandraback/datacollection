import string
import sys

theMap = {}


def learn(samples):
    for key,value in samples.items():
        for i in range(len(key)):
            c1 = key[i]
            c2 = value[i]
            if c1.isalpha() and theMap.get(c1, None) == None:
                theMap[c1] = c2
                
    theMap['q'] = 'z'
    theMap['z'] = 'q'
    s =  string.lowercase
    table = string.maketrans('', '')
    s1 = string.translate(s, table, "".join(theMap.keys()))
    s2 = string.translate(s, table, "".join(theMap.values()))

def readLine():
    return sys.stdin.readline()

def readLineAsInt():
    return int(readLine())

samples = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi": "our language is impossible to understand",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd": "there are twenty six factorial possibilities",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv": "so it is okay if you want to just give up"
}


learn(samples)
s1 = "".join(theMap.keys())
s2 = "".join(theMap.values())
table = string.maketrans(s1, s2)

n = readLineAsInt()
#print "============"
#print n
for i in range(n):
    #print i
    s = readLine().strip()
    v = string.translate(s, table)
    print "Case #%d: %s" % (i + 1, v)

