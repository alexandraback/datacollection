import math, sys, numpy as np;

l = list(sys.stdin);
T = int(l[0]);
l = l[1:];

def genAllStrings(prefix, keyboard, S):
    if (S == 0): return [prefix];
    collection = [];
    for l in keyboard:
        collection.extend(genAllStrings(prefix + l, keyboard, S - 1));
    return collection;

def countOccurances(string, target):
    tlen = len(target);
    oc = 0;
    for i in range(len(string)):
        if (string[i:i + tlen] == target): oc = oc + 1;
    return oc;

# for s in genAllStrings("", "ABC", 2):
#     print s;

for t in range(T):
    K,L,S = map(int, l[0].strip().split(' '));
    keyboard = l[1].strip();
    target = l[2].strip();
    
    allCounts = np.array(map(lambda x: countOccurances(x, target), genAllStrings("", keyboard, S)));
    expected = np.max(allCounts) - np.mean(allCounts)
    print "Case #%i: %0.9f" % (t + 1, expected);

    l = l[3:];
