import itertools
def findsubsets(S,m):
    return set(itertools.combinations(S, m))

T = int(raw_input())

for t in range(T):
    arr = [int(i) for i in raw_input().split(' ')]
    N = arr[0]
    arr = arr[1:]
    
    suma = {}
    flag = False
    for i in range(1,len(arr)+1):
        subsets = findsubsets(arr,i)
        for s in subsets:
            d = sum(s)
            if d in suma:
                res = [suma[d],s]
                flag = True
                break
            suma[d] = s
        if flag:
            break
            
    print 'Case #%d:' % (t+1)
    if res:
        print ' '.join(map(str,res[0]))
        print ' '.join(map(str,res[1]))
    else:
        print 'Impossible'
