import sys, pickle

def f(i):
    return ''.join(reversed(list(str(i)))) == str(i) and ''.join(reversed(list(str(i*i)))) == str(i*i)

def calculate():
    X = [1, 4, 9]
    a = [11, 22]

    while a:
        n = a.pop(0)
        s = str(n)
        l = len(s)

        if n*n > 1e110: continue

        #print l, n

        X.append(n*n)

        if l % 2 == 0:
            s1, s2 = s[:l/2], s[l/2:]
            for i in range(0, 10):
                s =int(s1+str(i)+s2)
                if f(s):
                    a.append(s)
        else:
            i = l/2
            s = int(''.join([s[:i] , s[i] , s[i] , s[i+1:]]))
            if f(s):
                a.append(s)


    #print len(X)
    return X

def get():
    try:
        X = pickle.load(open('fnsq', 'rb'))
    except:
        X = calculate()
        pickle.dump(X, open('fnsq', 'wb'))

    return X

X = get()


F = open(sys.argv[1])
N = int(F.readline())

for T in range(1, N+1):
    m, n = map(int, F.readline().split())
    a = next(x[0] for x in enumerate(X) if x[1] >= m)
    b = next(x[0] for x in enumerate(X) if x[1] >= n)

    c = 0
    for t in range(a, b+1):
        if X[t] >= m and X[t] <= n:
            c += 1

    print "Case #%d: %d" % (T, c)