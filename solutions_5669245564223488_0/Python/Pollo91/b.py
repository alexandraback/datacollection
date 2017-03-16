from math import factorial

t = int(raw_input())

M = 1000000007

def quanti(string, rimaste):
    usate = set(string)
    #print "cerco "+string
    possibili = [s for s in rimaste if s.startswith(string[-1])]
    next_rimaste = [s for s in rimaste if s not in possibili]

    #print "possibili"
    #print possibili

    if (len(possibili)==0):
        if (len(rimaste)==0):
            return 1

    if (len(possibili)==1):
        lettere = set(possibili[0])
        lettere.remove(possibili[0][0])
        if usate.intersection(lettere):
            return 0
        else:
            return quanti(string+possibili[0], next_rimaste)

    if len(possibili)>1:
        uniche = [s for s in possibili if len(set(s))==1]
        non_uniche = [s for s in possibili if s not in uniche]
        #print "non_uniche"
        #print non_uniche
        if len(non_uniche) > 1:
            return 0
        if len(non_uniche) == 1:
            lettere = set(non_uniche[0])
            lettere.remove(non_uniche[0][0])
            if usate.intersection(lettere):
                #print "non_usabile"
                return 0
            else:
                q = quanti(string+non_uniche[0], next_rimaste)
                #print "usabile"
                #print q
                return (q * factorial(len(uniche))) % M
        if len(non_uniche) == 0:
            if (len(next_rimaste)==0):
                q = 1
            else:
                q = 0
            for i,s in enumerate(next_rimaste):
                #print "provo con "+s
                lettere = set(s)
                if not usate.intersection(lettere):
                    rim = next_rimaste[:]
                    del rim[i]
                    q += quanti(string+s, rim)
                    #print "con "+string+s+"sono a "+str(q)
            return (q * factorial(len(uniche))) % M

    if (len(possibili)==0):
        q = 0
        for i,s in enumerate(next_rimaste):
            #print "provo con "+s
            lettere = set(s)
            if not usate.intersection(lettere):
                rim = next_rimaste[:]
                del rim[i]
                q += quanti(string+s, rim)
                #print "con "+string+s+"sono a "+str(q)
        return q % M


for k in range(t):
    n = int(raw_input())
    strings = raw_input().split(" ")
    #print strings

    if (n==1):
        viste = set()
        s = strings[0]
        viste.add(s[0])
        ok = True
        for i in range(1,len(s)):
            if (s[i]!=s[i-1]):
                if s[i] in viste:
                    ok = False
                    break
            viste.add(s[i])
        if not ok:
            print "Case #"+str(k+1)+": 0"
            continue

    tot = 0
    for i in range(n):
        rimaste = strings[:]
        del rimaste[i]
        tot += quanti(strings[i],rimaste)
        tot %= M

    print "Case #"+str(k+1)+": "+str(tot)
