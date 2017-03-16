T = int(input())

def subtr(s,d):
    for c in s:
        d[c] -= 1
        if d[c] == 0:
            del d[c]

for case in range(T):
    ld = {}
    ans = []
    string = input()
    for c in string:
        if c not in ld:
            ld[c] = 0
        ld[c]+=1
    while ld:
        while 'Z' in ld:
            subtr('ZERO',ld)
            ans.append(0)
        while 'W' in ld:
            subtr('TWO',ld)
            ans.append(2)
        while 'G' in ld:
            subtr('EIGHT',ld)
            ans.append(8)
        while 'X' in ld:
            subtr('SIX',ld)
            ans.append(6)
        while 'H' in ld:
            subtr('THREE',ld)
            ans.append(3)
        while 'S' in ld:
            subtr('SEVEN',ld)
            ans.append(7)
        while 'V' in ld:
            subtr('FIVE',ld)
            ans.append(5)
        while 'F' in ld:
            subtr('FOUR',ld)
            ans.append(4)
        while 'I' in ld:
            subtr('NINE',ld)
            ans.append(9)
        while 'O' in ld:
            subtr('ONE',ld)
            ans.append(1)
    ans.sort()
    print('Case #',case+1,': ',*ans,sep='')
