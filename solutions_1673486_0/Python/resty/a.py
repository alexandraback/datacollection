f = open("input.txt")
T = int(f.readline())
for i in range(T):
    a, b = map(int, f.readline().strip().split(' ')[0:2])
    p = map(float, f.readline().strip().split(' '))

    best_ans = b + 2 # just jrop

    pp = [p[0]]
    for j in range(1, len(p)):
        pp.append(pp[j-1] * p[j])

    for j in range(1, a + 1):
        ans = (a - j) + (b - j)  + 1 + ( 1 - pp[j-1] ) * (b + 1)
        best_ans = min(best_ans, ans)
    
    print "Case #%d: %.8f" % (i+1, best_ans)
f.close()
    
    
