def rings(r,t):
    k = 0
    while t>=0:
        t -= 2*r+1
        r += 2
        k += 1
        print r,t,k
    return k-1

f = open('A-small-attempt0.in')
r = f.readlines()
nums = [map(int,i.split(' ')) for i in r]
w = open('A-small-attempt0.out','w')
for i in range(1,len(nums)):
    w.write('Case #%s: %d\n' % (i, rings(*nums[i])))
f.close()
w.close()
