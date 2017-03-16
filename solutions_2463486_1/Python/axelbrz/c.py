import time
import bisect

def sqrt(n):
    i = 1
    d = n
    m = (i+d)/2
    m2 = m**2
    _m = -1
    while True:
        _m = m
        if m2 < n:
            i = m
            m = (i+d)/2
            m2 = m**2
        elif m2 > n:
            d = m
            m = (i+d)/2
            m2 = m**2
        else:
            return m
        if m == _m: return m

def nextp(l):
    itail = len(l) - 2
    while itail >= 0 and l[itail] >= l[itail+1]: itail -= 1
    if itail >= 0:
        j = len(l) - 1
        while l[j] <= l[itail]: j -= 1
        l[j], l[itail] = l[itail], l[j]
        l[itail+1:] = l[-1:itail:-1]
        return True
    return False

# m <= n
def le(m,n):
    #if int(m) <= int(n):
    #    print m
    return int(m) <= int(n)
"""    
def upto(N):
    n = sqrt(N)
    if n <= 3: return n
    ln = len(str(n))
    # sum of square of digs <= 4 / per pseudo-half / 'first part' + (middle dig.) [+ rev(first)]
    # '0' in 'first part' means count of zeros >= 0, '-' in half means no-middle dig.
    # 20(-01)
    # 10(-012) / 1010(-012) / 101010(-01) / 10101010(-01)
    s = 0
    #print ln, n
    for l in xrange(ln/2):
        m = "2"+"0"*l
        if le(m+m[::-1],n):
            s += 1
            if le(m+"0"+m[::-1], n):
                s += 1
                if le(m+"1"+m[::-1], n):
                    s += 1
        #print "--"
        # one 1
        m = "1"+"0"*l
        if le(m+m[::-1],n):
            s += 1
            if le(m+"0"+m[::-1], n):
                s += 1
                if le(m+"1"+m[::-1], n):
                    s += 1
                    if le(m+"2"+m[::-1], n):
                        s += 1
        #print "--"
        # two 1
        if l >= 1:
            ds = ["0"]*(l-1) + ["1"]
            while True:
                m = "1"+"".join(ds)
                if le(m+m[::-1],n):
                    s += 1
                    if le(m+"0"+m[::-1], n):
                        s += 1
                        if le(m+"1"+m[::-1], n):
                            s += 1
                            if le(m+"2"+m[::-1], n):
                                s += 1
                if not nextp(ds): break
        #print "--"
        # three 1
        if l >= 2:
            ds = ["0"]*(l-2) + ["1", "1"]
            while True:
                m = "1"+"".join(ds)
                if le(m+m[::-1],n):
                    s += 1
                    if le(m+"0"+m[::-1], n):
                        s += 1
                        if le(m+"1"+m[::-1], n):
                            s += 1
                if not nextp(ds): break
        #print "--"
        # four 1
        if l >= 3:
            ds = ["0"]*(l-3) + ["1", "1", "1"]
            while True:
                m = "1"+"".join(ds)
                if le(m+m[::-1],n):
                    s += 1
                    if le(m+"0"+m[::-1], n):
                        s += 1
                        if le(m+"1"+m[::-1], n):
                            s += 1
                if not nextp(ds): break
    return s + 3
"""
def allnums():
    alln = [0, 1, 2, 3]
    n = sqrt(10**102)
    ln = len(str(n))
    # sum of square of digs <= 4 / per pseudo-half / 'first part' + (middle dig.) [+ rev(first)]
    # '0' in 'first part' means count of zeros >= 0, '-' in half means no-middle dig.
    # 20(-01)
    # 10(-012) / 1010(-012) / 101010(-01) / 10101010(-01)
    for l in xrange(ln/2):
        m = "2"+"0"*l
        alln += [m+m[::-1]]
        alln += [m+"0"+m[::-1]]
        alln += [m+"1"+m[::-1]]
        
        # one 1
        m = "1"+"0"*l
        alln += [m+m[::-1]]
        alln += [m+"0"+m[::-1]]
        alln += [m+"1"+m[::-1]]
        alln += [m+"2"+m[::-1]]
        
        # two 1
        if l >= 1:
            ds = ["0"]*(l-1) + ["1"]
            while True:
                m = "1"+"".join(ds)
                alln += [m+m[::-1]]
                alln += [m+"0"+m[::-1]]
                alln += [m+"1"+m[::-1]]
                alln += [m+"2"+m[::-1]]
                if not nextp(ds): break
        #print "--"
        # three 1
        if l >= 2:
            ds = ["0"]*(l-2) + ["1", "1"]
            while True:
                m = "1"+"".join(ds)
                alln += [m+m[::-1]]
                alln += [m+"0"+m[::-1]]
                alln += [m+"1"+m[::-1]]
                if not nextp(ds): break
        #print "--"
        # four 1
        if l >= 3:
            ds = ["0"]*(l-3) + ["1", "1", "1"]
            while True:
                m = "1"+"".join(ds)
                alln += [m+m[::-1]]
                alln += [m+"0"+m[::-1]]
                alln += [m+"1"+m[::-1]]
                if not nextp(ds): break
    for i in xrange(len(alln)):
        alln[i] = int(alln[i])
    alln.sort()
    return alln


def bins(l, e):
    i = bisect.bisect_left(l, e)
    #print e, i, len(l), l[-1]
    return i if l[i] == e else i - 1

alln = allnums()
def solve(A, B):
    global alln
    return bins(alln, sqrt(B)) - bins(alln, sqrt(A-1))
    #return upto(B) - upto(A-1)


prob = "c"
f = open(prob+".in","r")
d = f.read()[:-1]
f.close()
f = open(prob+".out","w")
total = int(d.split("\n")[0])
lines = d.split("\n")[1:]
T = 1
i = 1
t_ini = time.time()
for line in lines:
    raw = line.split(" ")
    A, B = int(raw[0]), int(raw[1])
    S = "Case #%d: %s" % (T, solve(A, B))
    print S
    f.write(S + "\n")
    T += 1
    
f.close()
