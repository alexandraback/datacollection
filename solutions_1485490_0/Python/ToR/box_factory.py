def readFile(file):
    name = file[:file.index('.')]
    ##print(name)
    f = open(file)
    fout = open(name+'.out','w')
    cases = int(f.readline().strip())
    for case in range(cases):
        n,m = [int(x) for x in f.readline().split()]
        nList = []
        line = f.readline().split()
        for i in range(n):
            a = line[2*i]
            t = line[2*i+1]
            nList.append((t,int(a)))

        mList = []
        line = f.readline().split()
        for j in range(m):
            a = line[2*j]
            t = line[2*j+1]
            mList.append((t,int(a)))
        result = execute(case,nList,mList)
        print(result)
        fout.write(result)

def execute(index,nList,mList):
    print(index,nList,mList)
    t = lcs(nList,mList)
    
    
    return ''.join(['Case #',str(index+1),': ',str(t),'\n'])

def lcs(l1,l2):
    if not( l1 and l2):
        return 0

    t1 = l1[0][0]
    t2 = l2[0][0]
    a1 = l1[0][1]
    a2 = l2[0][1]

    if t1 == t2:
        if a1 == a2 :
            value = a1
            return value + lcs(l1[1:],l2[1:])
        elif a1 > a2 :
            value = a2
            l1[0] = (t1,(a1-a2))
            return value + lcs(l1,l2[1:])
        else:
            value = a1
            l2[0] = (t2,(a2-a1))
            return value + lcs(l1[1:],l2)
    else:
        left = lcs(l1[1:],l2[:])
        right = lcs(l1[:],l2[1:])
        return max(left,right)

if __name__ == "__main__":
    readFile('C-small-attempt0.in')
