import pdb
f = open('b.in')
out = open('b.out', 'w+')
t = int(f.readline())
def bitand(x, y):
    pdb.set_trace()
    binx = bin(x)[2:]
    biny = bin(y)[2:]
    if len(binx) > len(biny):
        biny = '0'*(len(binx)-len(biny)) + biny
    if len(biny) > len(binx):
        pass
    binxy = ''
    for i in range(len(binx)):
        binxy += str(int(bool(int(binx[i])) and bool(int(biny[i]))))
    return int(binxy, 2)
for tc in range(t):
    print(tc+1)
    answer = 0
    a, b, k = [int(a) for a in f.readline().split()]
    answer += k*k
    answer += (a-k)*k
    answer += (b-k)*k
    for ca in range(k,a):
        for cb in range(k, b):
            if ca & cb < k:
                answer += 1
    out.write('Case #{0}: {1}\n'.format(tc+1, answer))
    
