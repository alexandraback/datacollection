import sys

import psyco; psyco.full()

def is_real(cand, n):
    return (cand >> n) & 1 == 1
    
def eval_cand(cand, topics, indexfirst, indexlast):
    fakes = 0
    for j in xrange(len(topics)):
        if not is_real(cand, j):
            word1, word2 = topics[j]
            
            found1 = False
            for k in indexfirst[word1]:
                if is_real(cand, k):
                    found1 = True
                    break
                    
            if not found1:
                return None
                
            found2 = False
            for k in indexlast[word2]:
                if is_real(cand, k):
                    found2 = True
                    break
                    
            if not found2:
                return None
                
            fakes += 1
            
    return fakes
            

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        nlines = int(f.readline().strip())
        
        topics = []
        indexfirst = {}
        indexlast = {}
        for i in xrange(nlines):
            word1, word2 = f.readline().strip().split()
            topics.append((word1, word2))
            
            if word1 not in indexfirst:
                indexfirst[word1] = []
            indexfirst[word1].append(i)
            
            if word2 not in indexlast:
                indexlast[word2] = []
            indexlast[word2].append(i)
            
        maxfake = 0
        
        for cand in xrange(2**len(topics)):
            res = eval_cand(cand, topics, indexfirst, indexlast)
            if res is not None:
                maxfake = max(maxfake, res)
                
        print "Case #%d: %d" % (caseno+1, maxfake)
        
main()