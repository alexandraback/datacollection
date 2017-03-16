#  --*-coding:utf-8-*--

t = int(input())
(n,j) = map(int, input().split())

print('Case #1:')
for i in range(j):
    digits = ['1']

    for k in range(n//2-1):
        digits.insert(0, '00' if i%2 == 0 else '11')
        i //= 2

    digits.insert(0, '1')
    print(''.join(digits), '3 4 5 6 7 8 9 10 11')




