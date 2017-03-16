T=int(input())
for t in range(T):
    S=input()
    l={chr(l):0 for l in range(65, 91)}
    for i in S:
        l[i]+=1
    res = ""
    res += l['Z']*"0"
    res += (l['O']-l['Z']-l['W']-l['U'])*"1"
    res += l['W']*"2"
    res += (l['H']-l['G'])*"3"
    res += l['U']*"4"
    res += (l['V']-l['S']+l['X'])*"5"
    res += l['X']*"6"
    res += (l['S']-l['X'])*"7"
    res += l['G']*"8"
    res += (l['I']-l['G']-l['X']-l['V']+l['S']-l['X'])*"9"
    print("Case #" + str(t+1) +": " +res)
