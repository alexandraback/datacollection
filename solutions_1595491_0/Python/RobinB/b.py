
def Solve(res):
  
    N = res[0]
    S = res[1]
    p = res[2]
    normal = p * 3 - 2
    if normal < 0:
        normal = 0
    surp = p * 3 - 4
    if p == 1:
        surp = 1
    if surp < 0:
        surp = 0
    t = sorted(res[3:], reverse=True)


    count = 0
    for i in t:
        if i >= normal:
            count = count + 1
        elif i >= surp and S > 0:
            count = count + 1
            S = S - 1


    return count
        
        




f = open('b.in')
T = int(f.readline())
for t in range(T):
    res = map(int, f.readline().split())
    #print freq
    result = Solve(res)
    print "Case #%d: %s" % (t+1, result)
