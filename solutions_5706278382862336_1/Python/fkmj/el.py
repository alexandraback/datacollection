
def powerof2(q):
    r = 1
    t = 0
    while r < q:
        r *= 2
        t += 1
        if t == 40:
            break
    if r==q:
        return True
    else:
        return False

def gcd(a,b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def solve(i):
    st = raw_input()
    p,q = [int(x) for x in st.split('/')]

    ggg = gcd(p,q)
    p /= ggg
    q /= ggg

    if not powerof2(q):
        print 'Case #%d: impossible' % (i+1)
        return

    c = 2
    g = 1
    while True:
        if q <= p*c:
            print 'Case #%d: %d' % (i+1,g)
            return
        c *= 2
        g += 1
        if g==40:
            print 'Case #%d: impossible' % (i+1)
            return

def main():
    t = int(raw_input())
    for i in range(t):
        solve(i)
        

main()
