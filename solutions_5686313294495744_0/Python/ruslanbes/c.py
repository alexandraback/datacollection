from collections import Counter



def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine




def main():


    ############################################1
    T = int( raw_input() )
    for t in xrange(T):  
        N = int(raw_input())
        w1 = []
        w2 = []
        for n in xrange(N):
            words = raw_input().split()
            w1.append(words[0])
            w2.append(words[1])


        c1 = Counter(w1)
        c2 = Counter(w2)
        u1 = [x for x,y in c1.iteritems() if y == 1]
        u2 = [x for x,y in c2.iteritems() if y == 1]
        realT = 0
        for i in xrange(N):
            if w1[i] in u1 or w2[i] in u2:
                realT +=1


        output(t, N - realT)




if __name__ == "__main__":
   main()