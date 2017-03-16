import math

def ispall(k):
    m = str(k)
    l = len(m)
    i = 0
    ans = True
    while( i <= l//2):
        if m[i] == m[l-1-i]:
            ans = True
        else:
            return False
        i += 1
    return True

l = []
for i in range(0, 10000000 + 1):
    if ispall(i):
        l = l + [i]

ls = []
for i in l:
    if ispall(i*i):
        ls = ls + [i]
    
infile = open('/home/suguman/Desktop/C-large-1.in', 'r')
outfile = open('/home/suguman/Desktop/output3.txt', 'w')

x = int(infile.readline())
i = 0
while (i < x):
    l1 = infile.readline().strip().split()
    a, b = int(l1[0]), int(l1[1])
    a1 = math.ceil(math.sqrt(a))
    b1 = math.floor(math.sqrt(b))
    count = 0
    for n in ls:
        if a1<=n<=b1:
            count+=1
        
    outfile.write('Case #'+str(i+1)+': ' + str(count)+'\n')
    i += 1
