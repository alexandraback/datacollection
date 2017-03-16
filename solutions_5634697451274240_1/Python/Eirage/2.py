file = open('B-large.in', 'r')
out = open('result.out','w')
T = int(file.readline())

for k in range (T):

    S = file.readline()
    S = S[0:-1]
    n = len(S)
    s = S[0]
    for i in xrange(n-1):
        if S[i+1] != S[i]:
            s += S[i+1]
    print(s)

    n = len(s)
    if s[-1] == '+':
        n -= 1
    
    out.write('Case #' + str(k+1) + ': ' + str(n) + '\n')
out.close()
