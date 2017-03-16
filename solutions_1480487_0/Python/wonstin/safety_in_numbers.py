import string

infile = open('infile','r')
outfile = open('outfile','w')

T = int(string.strip(infile.readline()))

def test(t, rest, a, S):
    t += a*S
    b = 1-a
    print t, rest, '*'
    while min(rest) < t and b > 0:
        b -= (t - rest[0])/S
        rest[0] = t
        rest.sort()
        print t,rest
    if b < 0 or min(rest) < t:
        return -1
    return 1

for k in xrange(T):
    print k
    answer = ''
    s = map(int,string.strip(infile.readline()).split())
    N = s[0]
    s = map(float,s[1:])
    S = sum(s)
    for i in range(N):
        t = s[i]
        rest = s[0:i]
        rest.extend(s[i+1:])
        rest.sort()
        guess = 50.0
        step = 25.0
        for j in range(30):
            guess += step * test(t, rest[:], guess/100, S)
            step = step / 2
        answer += ' '
        answer += str(guess)
#        tS = S
#        j = 1
#        currLevel = rest[0]
#        while tS > 0 and j < N-1:
#            amt = min(j*(rest[j]-rest[j-1]), tS)
#            tS -= amt
#            currLevel += amt / j
#            if amt == j*(rest[j]-rest[j-1]):
#                j += 1
#        if j == N-1:
#            currLevel += tS/j

#        answer += str(max(((t+(j*currLevel))/(j+1)-t)/S*100,0.0))
        
    outfile.write('Case #%d:%s\n' % (k+1,answer))

