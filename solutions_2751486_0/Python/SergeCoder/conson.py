#!/usr/bin/python2

def readf(f):
    rline = lambda : f.readline().split(' ')
    name, n = rline()
    return name, int(n)

def has_enough(name, n):
    vow = "aoeui"
    for c in name:
        if c in vow and n != 0:
            return False
        if n == 0:
            break;
        n -= 1
    return n == 0
    
def test(nn):
    name, n = nn
    vow = "aoeui"
    st = 0
    rank = 0
    pos = 0
    for ch in name:
        if not ch in vow:
            if has_enough(name[pos:], n):
                rank += (pos - st + 1) * (len(name) - (pos + n) + 1)
                st = pos + 1
        pos += 1
    return rank
    
if __name__=="__main__":
    f = file("A-small-attempt0.in");
    t = int(f.readline())
    for i in range(t):
        print "Case #%d:" % (i + 1), test(readf(f))

    
