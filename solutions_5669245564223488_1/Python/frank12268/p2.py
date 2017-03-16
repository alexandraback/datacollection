import sys

frac = [1]
mask = 1000000007

def work(a,n):
    assert(len(a)==n)
    answer = 1

    a3 = []
    a2 = []
    n1 = [0 for x in xrange(26)]
    n2_in = [None for x in xrange(26)]
    n2_ou = [None for x in xrange(26)]
    n3 = [0 for x in xrange(26)]
    for x in a:
        l = len(x)
        tx = [ord(x[i])-97 for i in xrange(l) if i==0 or x[i]!=x[i-1]]
        for y in tx:
            n3[y] += 1
        print "%s -> %s" %(x,tx)
        if tx[0]==tx[-1]:
            n1[tx[0]] += 1
            if len(tx)>1:
                return 0
        else:
            if n2_in[tx[0]] is not None:
                return 0
            n2_in[tx[0]] = len(a2)
            if n2_ou[tx[-1]] is not None:
                return 0
            n2_ou[tx[-1]] = len(a2)
            a2.append(tx)
        if len(tx)>2:
            a3.append(tx)
    for x in a3:
        l = len(x)
        for i in xrange(1,l-1):
            if n3[x[i]]>=2:
                return 0

    ind = [0 for x in xrange(26)]
    for x in a2:
        ind[x[-1]] += 1

    used = [False for x in xrange(26)]
    al = []
    cnt = 0
    for i in xrange(26):
        if used[i]:
            continue
        if ind[i]>0:
            continue
        used[i] = True
        ta = frac[n1[i]]
        gone = n1[i]>0
        t0 = i
        while True:
            x = n2_in[t0]
            if x is None:
                break
            t0 = a2[x][-1]
            ind[t0] -= 1
            ta *= frac[n1[t0]]
            ta %= mask
            assert(not used[t0])
            assert(ind[t0]==0)
            used[t0] = True
            gone = True
        answer *= ta
        answer %= mask
        if gone:
            cnt += 1
            print "ta = %d, starting @ %d" %(ta,i)
    if sum(ind)>0:
        return 0
    answer *= frac[cnt]
    answer %= mask
    return answer

def main(ifn='bin.txt',ofn='bout.txt'):
    sys.setrecursionlimit(2000)
    global frac
    for i in xrange(1,104):
        frac.append((frac[-1]*i)%mask)
    with open(ifn) as inf:
        with open(ofn,'w') as ouf:
            noc = int(inf.readline())
            for tnoc in xrange(1,noc+1):
                ouf.write("Case #%d: " %(tnoc))
                print "Case #%d: " %(tnoc)
                n = int(inf.readline())
                a = inf.readline().strip().split(' ')
                answer = work(a,n)
                ouf.write("%d\n" %(answer))
                print "%d" %(answer)

