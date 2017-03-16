'''
Created on May 5, 2012

@author: Indra
'''
import sys, os

filename = "C-small-attempt0"

path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename + ".in"))
reader = open(path, "rb")
path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename + ".out"))
writer = open(path, "w")
svotes = []
X = 0
T = int(reader.readline().rstrip())

caseno = 1
while caseno <= T:
    line = reader.readline().rstrip()
    t = [int(x) for x in line.split(' ')]
    N = t[0]
    S = t[1:]
    l = len(S)
    memo = {}
    ret = None
    for i in xrange(1<<l):
        sum = 0
        for j in xrange(l):
            if i&(1<<j):
                sum+=S[j]
        if memo.has_key(sum):
            ret = (i,memo[sum])
            break
        else:
            memo[sum]=i
    
    if not ret:
        pret = "Impossible"
    else:
        first = []
        second = []
        for j in xrange(l):
            if ret[0]&(1<<j):
                first.append(S[j])
            if ret[1]&(1<<j):
                second.append(S[j])
        pret = "\n"+ ' '.join(str(x) for x in first) + "\n" +  ' '.join(str(x) for x in second)
    print pret
    writer.write("Case #%s: %s\n" % (str(caseno), pret))
    caseno += 1

writer.close()
