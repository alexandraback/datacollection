mem = set([])
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109]
done = False
A = []

mapk = {}
def dk(k):
    if not k in mapk.keys():
        mapk[k] = len(mapk)
    return mapk[k]

def pk(k):
    pass

def prodk(keys):
    global primes
    p = 1
    for k in keys:
        p *= primes[k]
    return p

def bt(chs, cnt, o, p):
    global done, A, mem
    if done == True: return
    kk = (p, o)
    if kk in mem:
        return
    if len(mem) % 10000 == 0:
        print len(mem)
    mem.add(kk)
    if len(cnt) == len(chs):
        A = cnt[:]
        done = True
        return
    for i in xrange(len(chs)):
        if (o & (1 << i) == 0) and p % primes[chs[i][0]] == 0:
            cnt.append(i)
            bt(chs, cnt, o | (1 << i), p / primes[chs[i][0]] * prodk(chs[i][1]))
            del cnt[-1]
            

def solve(keys, chs):
    global done, A, mem
    mem = set([])
    A = []
    done = False
    bt(chs, [], 0, prodk(keys))
    if A == []:
        return "IMPOSSIBLE"
    return " ".join([str(a+1) for a in A])

prob = "d"
f = open(prob+".in","r")
d = f.read()[:-1]
f.close()
f = open(prob+".out","w")
lines = d.split("\n")
T = 1
i = 1
while i < len(lines):
    line = lines[i]
    raw = line.split(" ")
    raw = [int(e) for e in raw]
    k, n = raw[0], raw[1]
    
    line = lines[i+1]
    raw = line.split(" ")
    keys = [int(e) for e in raw]
    for j in xrange(len(keys)):
        keys[j] = dk(keys[j])
    chs = []
    for j in xrange(n):
        line = lines[j+i+2]
        raw = line.split(" ")
        raw = [int(e) for e in raw]
        chs += [(dk(raw[0]), [dk(b) for b in raw[2:]])]
    S = "Case #%d: %s" % (T, solve(keys, chs))
    print S
    f.write(S + "\n")
    i += n + 2
    T += 1
    
f.close()
