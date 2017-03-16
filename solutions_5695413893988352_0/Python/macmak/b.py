T = int(input())

def give_options(s):
    dig = s.count('?')
    for i in range(10**dig):
        istr = str(i).zfill(dig)
        out = ''
        for c in s:
            if c=='?':
                out += istr[0]
                istr = istr[1:]
            else:
                out+=c
        yield out

for case in range(T):
    c,j = input().split()
    diff = 9999
    ca = ''
    ja = ''
    for c1 in give_options(c):
        for j1 in give_options(j):
            d = abs(int(c1) - int(j1))
            if diff > d:
                diff = d
                ca = c1
                ja = j1
    print('Case #',case+1,': ',ca,' ',ja,sep='')
