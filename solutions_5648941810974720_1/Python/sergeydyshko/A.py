CurrentPathIn = "input"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

T = int(fr.readline())

for t in range(T):
    s = fr.readline().rstrip("\n")

    d = {}
    for i in range(10):
        d[i]=0

    D = {}
    for i in range(ord('A'),ord('Z')+1):
        D[chr(i)] = 0

    for c in s:
        D[c]+=1

    d[0] = D['Z']
    d[2] = D['W']
    d[4] = D['U']
    d[6] = D['X']
    d[8] = D['G']

    D['Z']-=d[0]
    D['E']-=d[0]
    D['R']-=d[0]
    D['O']-=d[0]

    D['T']-=d[2]
    D['W']-=d[2]
    D['O']-=d[2]

    D['F']-=d[4]
    D['O']-=d[4]
    D['U']-=d[4]
    D['R']-=d[4]

    D['S']-=d[6]
    D['I']-=d[6]
    D['X']-=d[6]

    D['E']-=d[8]
    D['I']-=d[8]
    D['G']-=d[8]
    D['H']-=d[8]
    D['T']-=d[8]

    d[1] = D['O']
    d[3] = D['T']
    d[5] = D['F']
    d[7] = D['S']

    D['O']-=d[1]
    D['N']-=d[1]
    D['E']-=d[1]

    D['T']-=d[3]
    D['H']-=d[3]
    D['R']-=d[3]
    D['E']-=d[3]
    D['E']-=d[3]

    D['F']-=d[5]
    D['I']-=d[5]
    D['V']-=d[5]
    D['E']-=d[5]

    D['S']-=d[7]
    D['E']-=d[7]
    D['V']-=d[7]
    D['E']-=d[7]
    D['N']-=d[7]

    d[9] = D['I']
    
    res = []
    for i in range(10):
        res+=[chr(i+ord('0'))]*d[i]
    res = "".join(res)
    
    fw.write("Case #"+str(t+1)+": "+str(res)+"\n")
fr.close()
fw.close()
