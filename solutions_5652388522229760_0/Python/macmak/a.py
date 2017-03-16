T = int(input())

for case in range(T):
    digits = set()
    n = int(input())
    if n < 1:
        print('Case #',case+1,': INSOMNIA',sep='')
        continue
    count = 0
    while(len(digits)<10):
        count += n
        for c in str(count):
            digits.add(c)
    print('Case #',case+1,': ',count,sep='')
