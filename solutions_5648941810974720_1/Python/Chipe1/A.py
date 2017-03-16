d={}
tc=int(input())
for echsdfadf in range(tc):
    L=[]
    for c in 'QWERTYUIOPASDFGHJKLZXCVBNM':
        d[c]=0
    s=input()
    for c in s:
        d[c]+=1

    #eight
    i=d['G']
    for x in range(i):
        L.append(8)
    for c in "EIGHT":
        d[c]-=i
    #six
    i=d['X']
    for x in range(i):
        L.append(6)
    for c in "SIX":
        d[c]-=i
    #two
    i=d['W']
    for x in range(i):
        L.append(2)
    for c in "TWO":
        d[c]-=i
    #three
    i=d['T']
    for x in range(i):
        L.append(3)
    for c in "THREE":
        d[c]-=i
    #four
    i=d['U']
    for x in range(i):
        L.append(4)
    for c in "FOUR":
        d[c]-=i
    #five
    i=d['F']
    for x in range(i):
        L.append(5)
    for c in "FIVE":
        d[c]-=i
    #seven
    i=d['V']
    for x in range(i):
        L.append(7)
    for c in "SEVEN":
        d[c]-=i
    #nine
    i=d['I']
    for x in range(i):
        L.append(9)
    for c in "NINE":
        d[c]-=i
    #one
    i=d['N']
    for x in range(i):
        L.append(1)
    for c in "ONE":
        d[c]-=i
    #zero
    i=d['Z']
    for x in range(i):
        L.append(0)
    for c in "ZERO":
        d[c]-=i
    L.sort()
    ans=''.join(map(str,L))
    print("Case #{}: {}".format(echsdfadf+1,ans))
    
