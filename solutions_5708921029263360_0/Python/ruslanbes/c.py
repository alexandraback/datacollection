from collections import defaultdict
import operator


def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine



def main():


    ############################################1
    T = int( raw_input() )
    for t in xrange(T):  
        J, P, S, K = map(int, raw_input().split())
        outfits = []
        JP = defaultdict(int)
        JS = defaultdict(int)
        PS = defaultdict(int)
        for j in xrange(1, J+1):
            for p in xrange(1, P+1):
                for s in xrange(1, S+1):
                    if JP[(j, p)] >= K or JS[(j, s)] >= K or PS[(p, s)] >= K:
                        continue
                    outfits.append([j, p, s])
                    JP[(j, p)] += 1
                    JS[(j, s)] += 1
                    PS[(p, s)] += 1


        JPmax = max(JP.iteritems(), key=operator.itemgetter(1))
        JSmax = max(JS.iteritems(), key=operator.itemgetter(1))
        PSmax = max(PS.iteritems(), key=operator.itemgetter(1))


        #print "debug1", JPmax, JSmax, PSmax
        #print "debug2", outfits

        if (JPmax[1] <= K):
            y = len(outfits)
            outfits = [' '.join(map(str, x)) for x in outfits]
            outfits = "\n".join(outfits) 
            
            output(t, str(y) + "\n" + outfits)
            continue

        





if __name__ == "__main__":
   main()