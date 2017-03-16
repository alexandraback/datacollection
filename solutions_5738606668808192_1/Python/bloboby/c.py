def div(m):
    if m%2 == 0:
        return 2
    k = 3
    while k <= 20:
        if m%k == 0:
            return k
        k += 2
    return 0

T = raw_input()
N, J = [int(s) for s in raw_input().split(" ")]
print "Case #1:"

jam = [0] * 40
jam[0] = 1
jam[N-1] = 1
p = 2**(N-2)
for i in xrange(p):
    if J == 0:
        break
    
    # put digits into array
    k = i
    for j in xrange(N-2):
        jam[1+j] = k % 2
        k /= 2
    
    # check all bases
    coin = True
    divs = []
    for b in xrange(2,11):
        m = 0
        for j in xrange(N):
            m += jam[j] * b**j
        d = div(m)
        if d == 0:
            coin = False
            break
        else:
            divs.append(d)
    
    # print output
    if coin:
        ans = ""
        for j in xrange(N-1,-1,-1):
            ans += str(jam[j])
        for j in xrange(9):
            ans += " " + str(divs[j])
        print ans
        J -= 1