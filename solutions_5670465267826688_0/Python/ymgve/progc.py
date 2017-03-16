import sys, random

import psyco; psyco.full()

def calc(lookup, s):
    n = "1"
    for c in s:
        n = lookup[n+c]
    return n
    
def finalcheck(lookup, invlookup, st, partial, found_i, found_k):
    for test_i in found_i:
        for test_k in found_k:
            if test_i >= test_k:
                continue
                
            #print "qqqqq", test_i, test_k, st[test_i:test_k]
            if invlookup[partial[test_i-1] + partial[test_k-1]] == "j":
                res = calc(lookup, st[:test_i]) + calc(lookup, st[test_i:test_k]) + calc(lookup, st[test_k:])
                if res != "ijk":
                    print "FUUUUUU"
                    exit()
                return True
    return False
            
      
def main():
    basetable = ("1ijk", "i-kJ", "jK-i", "kjI-")
    negs = {}
    for i in xrange(4):
        a = "1ijk"[i]
        b = "-IJK"[i]
        negs[a] = b
        negs[b] = a
        
    lookup = {}
    invlookup = {}
    for i in xrange(4):
        for j in xrange(4):
            a = "1ijk"[i]
            b = "1ijk"[j]
            res = basetable[i][j]
            lookup[a+b] = res
            lookup[negs[a]+b] = negs[res]
            lookup[a+negs[b]] = negs[res]
            lookup[negs[a]+negs[b]] = res
            invlookup[a+res] = b
            invlookup[negs[a]+negs[res]] = b
            invlookup[a+negs[res]] = negs[b]
            invlookup[negs[a]+res] = negs[b]
            
    # for a in "1ijk-IJK":
        # for b in "1ijk-IJK":
            # print lookup[a+b],
        # print
    # exit()
          
    # s = ""
    # for i in xrange(1000):
        # s += random.choice("ijk")
     
    # for i in xrange(1000):
        # m = random.randint(0, 900)
        # n = random.randint(m+1, 901)
        # o = random.randint(n+1, 902)
        
        # a = calc(lookup, s[m:n])
        # b = calc(lookup, s[m:o])
        # c = calc(lookup, s[n:o])
        
        #print a, b, c
        # if invlookup[a+b] != c:
            # print "BAAAAAAAAAD"
            # exit()
        #print invlookup[b+a]
    
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        L, X = f.readline().split()
        L = int(L)
        X = int(X)
        
        st = f.readline().strip() * X
        
        # st = ""
        # for i in xrange(1000):
            # st += random.choice("ijk")
        #print st
        
        found_i = []
        partial = []
        n = "1"
        for i in xrange(len(st)):
            n = lookup[n+st[i]]
            partial.append(n)
            if n == "i":
                found_i.append(i+1)
                
        #print found_i
        # for n in found_i:
            # if calc(lookup, st[:n]) != "i":
                # print "baaaaaaaaaaaad"
                # exit()
            
        found_k = []
        #print len(partial), partial
        for i in xrange(0, len(st)):
            if invlookup[partial[i] + partial[-1]] == "k":
                found_k.append(i+1)
                
        #print found_k
        # for n in found_k:
            # if calc(lookup, st[n:]) != "k":
                # print "baaaaaaaaaaaad2"
                # exit()
        
        res = finalcheck(lookup, invlookup, st, partial, found_i, found_k)
        
        if res:
            st = "YES"
        else:
            st = "NO"
            
        print "Case #%d: %s" % (caseno+1, st)
        
main()