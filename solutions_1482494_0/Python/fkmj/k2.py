
def find_best(l1,cs):
    bj = 0
    bbb = l1[0][1]
    for i in range(len(l1)):
        a,bb,ii = l1[i]
        if (a <= cs) and (bbb < bb):
            bj = i
            bbb = bb
    return bj

def solve(t):
    n = int(raw_input())
    le = []
    l1 = []
    l2 = []

    for i in range(n):
        a,b = [int(x) for x in raw_input().strip().split()]
        if b < a:
            a = b
        le.append((a,b))
        l1.append((a,b,i))
        l2.append((b,i))

    l1 = sorted(l1)
    l2 = sorted(l2)
    #print l1
    #print l2

    played1 = set()
    played2 = set()

    p = 0
    cs = 0
    i = 0
    j = 0
    while i < len(l2):
        ml,l = l2[i]
        if cs >= ml:
            p += 1
            i += 1
            if l in played1:
                cs += 1
            else:
                cs += 2
            played2.add(l)
            #print 2,l,cs,'-',
            continue

        if len(l1)!=0:
            j = find_best(l1,cs)

            ml1, dummy, level1 = l1[j]
            
            if level1 in played2:
                del l1[j]
                continue

            if cs >= ml1:
                p += 1
                cs += 1
                played1.add(level1)
                del l1[j]
                #print 1,level1,cs,'-',
            else:
                print 'Case #%d: Too Bad' % t
                return
                
        else:
            print 'Case #%d: Too Bad' % t
            return

    print 'Case #%d: %d' % (t,p)

def main():
    t = int(raw_input())
    for i in range(t):
        solve(i+1)

if __name__=='__main__':
    main()
