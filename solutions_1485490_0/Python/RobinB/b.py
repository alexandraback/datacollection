import time, copy
from multiprocessing import Pool  

def Solve(data):
    M, N = data[0]
    #print M,N
    A = data[1]
    B = data[2]

    toys = 0
    print 

    #print A
    return rek(A, B, 0)

def rek(A, B, toys):
    #print A, B
    if len(A) == 0 or len(B) == 0:
        return toys

    if A[1] == B[1]:
        if A[0] < B[0]:
            #print A[0], toys
            Bnew = B[:]
            Bnew[0] -= A[0]
            toys += A[0] + rek(A[2:], Bnew, toys)
        if A[0] > B[0]:
            Anew = A[:]
            Anew[0] -= B[0]
            toys += B[0] + rek(Anew, B[2:], toys)
        if A[0] == B[0]:
            toys += A[0] + rek(A[2:], B[2:], toys)
        return toys
    else:
        return max(rek(A[2:], B[:], toys),rek(A[:], B[2:], toys))


if __name__ == '__main__':
    start = time.time()

    fin = open('b.in')
    fout = open('b.out','w')
    T = int(fin.readline())
    data = []
    for t in range(T):
        d = []
        d.append(map(int, fin.readline().split()))
        d.append(map(int, fin.readline().split()))
        d.append(map(int, fin.readline().split()))
        data.append(d)

    pool = Pool()  
    results = pool.map(Solve, data)

    c = 0
    for result in results:
        c = c + 1
        fout.write("Case #%d: %s\n" % (c, result))

    elapsed = (time.time() - start)
    print elapsed