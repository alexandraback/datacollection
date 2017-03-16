import sys

voy=set(['a', 'e', 'i', 'o', 'u'])



def calculate(w, n):
    count = 0
    cc=0
    groups= []
    beg = False
    last = 0
    
    try:
        for i in xrange(len(w)):
            consec = True
            for ii in xrange(n):
                if w[i+ii] in voy:
                    consec=False
                    break
            if consec:
                
                before = (i-last )
                after = len(w) - (i+n)
                count += (before+1)*(after+1)
                last = i+1
    except IndexError:
         pass
    
#     for i,c in enumerate(list(w)):
#         if c not in voy:
#             if not beg:
#                 beg=True
#                 start = i
#             cc+=1
#         else:
#             if cc>=n:
#                 count +=1
#                 groups.append(cc)
#             cc=0
#     if cc>=n:
#         groups.append(cc)
#         count +=1
    return count



if __name__=="__main__":
    T = int(sys.stdin.readline())
    
    for t in xrange(T):
        l = sys.stdin.readline().split()
        w = l[0]
        n = int(l[1])
        print "Case #%i:"%(t+1), calculate(w, n)

