#!/usr/bin/python
# -*- coding: utf-8 -*-


def trier(s):
    return ''.join(sorted(s))

def compatible(train,wagon):
    #print "  test de compatibilité «%s» «%s»" % (train,wagon)
    if (train == ''):
        return True
    dernier = train[-1]
    interdites = set(list(train))
    i = 0
    while (i < len(wagon) and wagon[i] == dernier):
        i += 1
    s = set(list(wagon[i:]))
    #print "%s %s" % (s,interdites)
    r = s.isdisjoint(interdites)
    '''
    if r:
        print "    → ok"
    else:
        print "    → nope."
    '''
    return r

def tester(train,wagons):
    if (wagons == []):
        #print "trouvé %s" % train
        return 1
    somme = 0
    for w in wagons:
        #print "tester «%s» «%s»" % (train,w)
        if compatible(train,w):
            nw = list(wagons)
            nw.remove(w)
            nt = train + w
            #print "appel  %s %s" % (nt,nw)
            ajout = tester(nt,nw)
            somme += ajout
            #print "→ cool ! +%d" % ajout
        #else:
            #print "→ nope."
    return somme

def simplifier(s):
    r = ""
    dernierc = ''
    for c in s:
        if (dernierc <> c):
            r += c
            dernierc = c
    return r

def commun(s1,s2):
    return not set(list(s1)).isdisjoint(set(list.s2))

nbcases = int(raw_input())

for case in xrange(1,nbcases+1):
    n = int(raw_input())
    mots = [n for n in raw_input().strip().split(" ")]
    mots = map(simplifier,mots)
    print "Case #%d: %s" % (case,tester("",mots))


