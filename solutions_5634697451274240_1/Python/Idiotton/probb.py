#  --*-coding:utf-8-*--

def f(str):
    c = None
    cnt = 0

    for x in str + '+':
        if (c == None or c != x):
            c = x
            cnt += 1

    return cnt-1


t = int(input())
for i in range(t):
    print('Case #'+str(i+1)+':', f(input().strip()))




