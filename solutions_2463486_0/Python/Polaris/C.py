problem = 'C'
scale = 'small'

infile = problem + '-' + scale + '.in'
outfile = problem + '-' + scale + '.out'

input = open(infile, 'r')
output = open(outfile, 'w')

ncase = int(input.readline().rstrip()) 

fs = []

for i in range(0, 1000):
    for m in range(-1, 10):
        if m == -1:
            mid = ''
        else:
            mid = str(m)
        if i == 0:
            pre = ''
        else:
            pre = str(i)
        post = pre[::-1]
        if pre == '' and mid == '': continue
        whole = int(pre + mid + post)
        sq = str(whole*whole)
        l = len(sq)
        for j in range(0, l//2):
            if sq[j] != sq[l-1-j]:
                break
        else:
            fs.append(sq)

print(fs)

def process(input):
    a, b = input.readline().rstrip().split()
    a = int(a)
    b = int(b)
    ct = 0
    for ele in fs:
        v = int(ele)
        if v >= a and v <= b:
            ct += 1
    return str(ct)

for k in range(1, ncase+1):
    result = process(input)
    print(k, result)
    output.write("Case #%d: %s\n" % (k, result))
