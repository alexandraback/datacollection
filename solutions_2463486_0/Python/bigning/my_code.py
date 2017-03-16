#! /usr/bin/python
import sys,string

if len(sys.argv)!=2:
    print 'sys.argv!=2'
    sys.exit(1)

my_table = []
for i in range(1,10**7+10):
    a = str(i)
    b = a[::-1]
    if a!=b:
        continue
    d = i**2
    a =str(d)
    b = a[::-1]
    if a==b:
        my_table.append(d)


fin = open(sys.argv[1])
sample_num = string.atoi(fin.readline().strip())

for i in range(sample_num):
    line = fin.readline().strip()
    fields = line.split(' ')
    low = string.atoi(fields[0])
    high = string.atoi(fields[1])

    for k in range(len(my_table)):
        if my_table[k]>=low:
            break

    for j in range(len(my_table)-1,-1,-1):
        if my_table[j]<=high:
            break

    r = j - k + 1
    if r<=0:
        r = 0
        
    print 'Case #%d: %d' %(i+1,r)
