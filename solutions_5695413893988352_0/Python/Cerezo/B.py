from math import sqrt
from scipy.misc import comb #use comb(n,k,True)

def knowsmaller(Big, Small):
    big = [int(b) if b != '?' else 0 for b in Big]
    small = [int(s) if  s != '?' else 9 for s in Small]
    return big, small

def makeint(x):
    summe = 0
    for i in range(len(x)):
        summe += x[i]* 10**(len(x)-i-1)
    return summe

    
def findmin(pairs):
    tosort = [(abs(makeint(x[0])-makeint(x[1])), ''.join(str(i) for i in x[0]), ''.join(str(i) for i in x[1])) for x in pairs]
    tosort.sort()
    return tosort[0][1:]

def Next(C, J):
    c = []
    j = []
    pairs = []
    for i in xrange(len(C)):
        if C[i] != '?' and J[i] == C[i]:
            c.append(int(C[i]))
            j.append(int(C[i]))
        elif C[i] != '?' and J[i] != '?':
            if int(C[i]) > int(J[i]): #know c > j, fill with 0s and 9s
                c.append(int(C[i]))
                j.append(int(J[i]))
                ctail, jtail = knowsmaller(C[i+1:], J[i+1:])
                c.extend(ctail)
                j.extend(jtail)
                pairs.append([c,j])
                break
            else: #know c < j
                c.append(int(C[i]))
                j.append(int(J[i]))
                jtail, ctail = knowsmaller(J[i+1:], C[i+1:])
                c.extend(ctail)
                j.extend(jtail)
                pairs.append([c,j])
                break
        elif  C[i] == '?':
            #compare higher and smaller j, and vice versa
            if J[i] == '?':
                d = 0 #this takes care of 0,0 and 1,0
            else:
                d = int(J[i])

            if d != 9:
                ch = c+[d+1]
                jh = j+[d]
                chtail, jhtail = knowsmaller(C[i+1:], J[i+1:])
                ch.extend(chtail)
                jh.extend(jhtail)
                pairs.append([ch,jh])
            if J[i] == '?':
                d = 1 #take care of 0,1
            if d != 0:
                cl = c+[d-1]
                jl = j+[d]
                jltail, cltail = knowsmaller(J[i+1:], C[i+1:])
                cl.extend(cltail)
                jl.extend(jltail)
                pairs.append([cl,jl])
            if J[i] == '?':
                d = 0
            c.append(d)
            j.append(d)
        elif J[i] == '?':
            #if C[i] == '?':
#                d = 0 #takes care of 0,0 and 1,0
#            else:
#                d = int(C[i])
            d = int(C[i])
            if d!= 9:
                ch = c+[d]
                jh = j+[d+1]
                jhtail, chtail = knowsmaller(J[i+1:], C[i+1:])
                ch.extend(chtail)
                jh.extend(jhtail)
                pairs.append([ch,jh])
            if d != 0:
                cl = c+[d]
                jl = j+[d-1]
                cltail, jltail = knowsmaller(C[i+1:], J[i+1:])
                cl.extend(cltail)
                jl.extend(jltail)
                pairs.append([cl,jl])
            #compare again
            c.append(d)
            j.append(d)
    pairs.append([c,j])
    a, b =  findmin(pairs)
    return ' '.join([a,b])
    
    #now find best pair
            

#input = open(r'sample.in')
input = open(r'B-small-attempt0.in')
#input = open(r'B-large.in')

T = int(input.readline())

sol = []

for i in xrange(T):
    #N = int(input.readline().strip())
    C, J = input.readline().strip().split()
    #print C, J
    sol += [Next(C, J)]
    if not i%10: print i

tofile = True
if tofile:
    with open(r'./outputB.txt', 'w') as output:
        for i in range(len(sol)):
            output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
    print sol
