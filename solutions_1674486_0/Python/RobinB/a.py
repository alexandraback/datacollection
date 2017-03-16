import time
from multiprocessing import Pool  

def Solve(data):
    N = data[0][0]
    s = data[0][1:]
    X = 0
    for x in s:
        X = X + x
    X2 = X

    res = []
    st = ""
    X2new = X2
    first = True
    tag = {}
    while X2 != X2new or first:
        X2 = X2new
        X2new = X
        first = False
        c = 0
        for x in s:
            c = c + 1
            vol = (2.0*(float(X2) / float(N)) - x)
            if vol < 0 and not c in tag:
                X2new = X2new - vol
                vol = 0
                #tag[c] = 1

    for x in s:
        vol = (2.0*(float(X) / float(N)) - x)
        if vol < 0:
            vol = 0       
            pass
        st = st + "%.6f " % (vol/X2*100 ) 
        #res.append((() *100)/X)

    return st



if __name__ == '__main__':
    start = time.time()

    fin = open('a.in')
    fout = open('a.out','w')
    T = int(fin.readline())
    data = []
    for t in range(T):
        d = []
        d.append(map(int, fin.readline().split()))
        data.append(d)

    pool = Pool()  
    results = map(Solve, data)

    c = 0
    for result in results:
        c = c + 1
        fout.write("Case #%d: %s\n" % (c, result))

    elapsed = (time.time() - start)
    print elapsed