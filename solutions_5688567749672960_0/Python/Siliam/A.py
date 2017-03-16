def reverse(N):
    if N < 10:
        return N
    else:
        s = ""
        for i in str(N)[::-1]: 
            s += i
        return int(s)

if __name__ == '__main__':
    f = open('A-small-attempt1.in', 'r')
    o = open('A-small-attempt1.out', 'w')

    T = int(f.readline())
    
    MaxN = 10**6 + 1
    R = {}
    
    for i in xrange(1, 21):
       R[i] = i

    for i in xrange(21, MaxN):
        r = reverse(i)
        if(r < i and R[r] < R[i-1] and reverse(r) == i):
            R[i] = R[r] + 1
        else:
            R[i] = R[i-1] + 1
    
    for testCase in xrange(1, T + 1):
        N = int(f.readline())
        o.write('Case #' + str(testCase) + ': ' + str(R[N]) +'\n')
    o.close()