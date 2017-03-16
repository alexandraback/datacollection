#!/usr/bin/python3
n = 16
count = 50
print('Case #1:')
for i in range(1, count+1):
    s = "{0:b}".format(i)
    while len(s) < n//2-2:
        s = '0' + s
    s = '1' + s + '1'
    s = s + s
    print(s, end=' ')
    for j in range(2,11):
        ss = '1' + '0'*(n//2-1) + '1'
        num = int(ss, j)
        bigNum = int(s, j)
        #print(s,' ',ss,' ',num,' ',bigNum)
        assert((num > 1) and (num < bigNum))
        assert(bigNum % num == 0)
        print(num, end=' ')
    print('')