def readFile(file):
    name = file[:file.index('.')]
    ##print(name)
    f = open(file)
    fout = open(name+'.out','w')
    cases = int(f.readline().strip())
    for i in range(cases):
        n = int(f.readline().strip())
        classes = {}
        for j in range(n):
            line = f.readline().split()
            m = line[0]
            mList = [int(x) for x in line[1:]]
            classes[j+1]= mList
        result = execute(i,n,classes)
        print(result)
        fout.write(result)

def execute(index,n,classes):
    #print(index,n,classes)
    result = 'No'

    for i in range(n):
        pMap = {}
        pList = []
        mList = classes[i+1]
        pList.extend(mList)
        found = False
        while len(pList) > 0 :
            head = pList.pop(0)
            if pMap.get(head):
                result = 'Yes'
                found = True
                break
            else:
                pMap[head] = 1
                pList.extend(classes[head])

        if found :
            break
    
    
    return ''.join(['Case #',str(index+1),': ',str(result),'\n'])


if __name__ == "__main__":
    readFile('A-large.in')
