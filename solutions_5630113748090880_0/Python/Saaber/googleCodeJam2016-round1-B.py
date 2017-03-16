fin = open('inputFile.in', 'r')
fout = open('outputFile.out', 'w')
T = int(fin.readline().strip())

def FUN(nums):
    dic = {}
    for n in nums:
        if n in dic:
            dic[n] += 1
        else:
            dic[n] = 1
    res = []
    for n in dic:
        if dic[n]%2 == 1:
            res.append(n)
    res.sort()
    return ' '.join([str(n) for n in res])

for t in xrange(T):
    line = fin.readline().strip()
    N = int(line)
    nums = []
    for n in xrange(2*N - 1):
        line = fin.readline().strip()
        nums = nums + [int(arg) for arg in line.split() if arg != '' and arg != '\n']
    res = FUN(nums)
    fout.write('Case #'+str(t+1)+': '+res+'\n')


fin.close()
fout.close()
