fi = "eg"
fi = "small-attempt0"
fi = "large"
fi = "D-"+fi+".in"
fo = fi.replace(".in", ".out")

def best(nb, kb):
    nb.sort()
    kb.sort()
    
    wins = 0
    
    ki = len(nb)-1
    ni = ki
    while ni >= 0:
        assert ki >= 0
        if nb[ni] > kb[ki]:
            wins += 1
            ni -= 1
        else:
            ni -= 1
            ki -= 1
            
    return wins

def warbest(nb, kb):
    nb.sort()
    kb.sort()
    
    wins = 0
    
    ki = len(nb)-1
    ni = ki
    while ki >= 0:
        assert ni >= 0
        if nb[ni] > kb[ki]:
            wins += 1
            ni -= 1
            ki -= 1
        else:
            ki -= 1
            
    return wins


with open(fi) as fi:
    with open(fo, 'w') as fo:
        n = int(fi.readline())
        for i in range(1, n+1):
            cnt = int(fi.readline())
            nblocks = [float(n) for n in fi.readline().split()]
            kblocks   = [float(n) for n in fi.readline().split()]
            assert len(nblocks) == cnt and len(kblocks) == cnt
            nblocks.sort(); kblocks.sort()
            
            wb = warbest(nblocks, kblocks)
            b = best(nblocks, kblocks)
            print("Case #{}: {} {}".format(i, wb, b), file=fo)
            
            print(nblocks)
            print(kblocks)
            print(wb, b, "\n")
